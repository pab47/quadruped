/*  Copyright © 2018, Roboti LLC

    This file is licensed under the MuJoCo Resource License (the "License").
    You may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        https://www.roboti.us/resourcelicense.txt
*/

//#include <iostream>
#include <stdbool.h>

#include "mujoco.h"
#include "glfw3.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//for save_data
FILE *fid2;
char path2[] = "../sample/data.csv";

FILE *fidmat,*fidC;
char pathmat[] = "../sample/data.m";
char pathC[] = "../sample/data.txt";
int flag_openmat;
int flag_C;

#define nact 12
#define nbase 16
#define nendeff 12

double init_pos_y = 0;
double init_pos_x = 0;

double time_gravity_off = 1; //time gravity should be off from start of sim


double t_control = 0;

#define fsm_controller_init 0
#define fsm_controller_run 1
#define fsm_controller_end 2

int fsm_controller=fsm_controller_init;

int motiontime = 0;

double bodyWorldPos[3]={0};

#include "../lib/comm.h"
#include "../lib/comm2.h"



#include "common/params.h"
#include "common/my_controller.c"
#include "get_state.c"
#include "set_torque.c"
#include "save_data.c"

double time_end = t_curve + 10.0; //end time for simulation


LowCmd cmd = {0}; //low level command
LowState state = {0}; //low level state
//RobotState robotstate = {0}; //high level state info. derived from state
RobotState modelstate = {0}; //high level state info. for model


//This file is not to be touched by the user
int q_id[nact]={0}, v_id[nact]={0}, act_id[nact]={0};
int base_stateid[nbase]={0},endeff_stateid[nendeff]={0},shoulder_stateid[nendeff]={0},elbow_stateid[nendeff]={0};
int endeff_velid[nendeff]={0},shoulder_velid[nendeff]={0};
int com_id[3]={0};
int footForce_id[4]={0};
// FILE *fid;

const int data_frequency = 10; //once every 2*data_frequency seconds (should be a multiple of 2)

// MuJoCo data structures
mjModel* m = NULL;                  // MuJoCo model
mjData* d = NULL;                   // MuJoCo data
mjvCamera cam;                      // abstract camera
mjvOption opt;                      // visualization options
mjvScene scn;                       // abstract scene
mjrContext con;                     // custom GPU context
mjvFigure fig;

// mouse interaction
bool button_left = false;
bool button_middle = false;
bool button_right =  false;
double lastx = 0;
double lasty = 0;


// keyboard callback
void keyboard(GLFWwindow* window, int key, int scancode, int act, int mods)
{
    // backspace: reset simulation
    if( act==GLFW_PRESS && key==GLFW_KEY_BACKSPACE )
    {
        mj_resetData(m, d);
        mj_forward(m, d);
    }
}


// mouse button callback
void mouse_button(GLFWwindow* window, int button, int act, int mods)
{
    // update button state
    button_left =   (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS);
    button_middle = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE)==GLFW_PRESS);
    button_right =  (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT)==GLFW_PRESS);

    // update mouse position
    glfwGetCursorPos(window, &lastx, &lasty);
}


// mouse move callback
void mouse_move(GLFWwindow* window, double xpos, double ypos)
{
    // no buttons down: nothing to do
    if( !button_left && !button_middle && !button_right )
        return;

    // compute mouse displacement, save
    double dx = xpos - lastx;
    double dy = ypos - lasty;
    lastx = xpos;
    lasty = ypos;

    // get current window size
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    // get shift key state
    bool mod_shift = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS ||
                      glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS);

    // determine action based on mouse button
    mjtMouse action;
    if( button_right )
        action = mod_shift ? mjMOUSE_MOVE_H : mjMOUSE_MOVE_V;
    else if( button_left )
        action = mod_shift ? mjMOUSE_ROTATE_H : mjMOUSE_ROTATE_V;
    else
        action = mjMOUSE_ZOOM;

    // move camera
    mjv_moveCamera(m, action, dx/height, dy/height, &scn, &cam);
}


// scroll callback
void scroll(GLFWwindow* window, double xoffset, double yoffset)
{
    // emulate vertical mouse motion = 5% of window height
    mjv_moveCamera(m, mjMOUSE_ZOOM, 0, -0.05*yoffset, &scn, &cam);
}

// initialize the different ids
void get_ID()
{
  const char* joint_name;
  const char* actuator_name;
  int i, jointid;

  joint_name = "FR_hip_joint";
  actuator_name = "FR_hip";
  jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
  int FR_hip_joint_qpos_adr = m->jnt_qposadr[jointid];
  int FR_hip_joint_qvel_adr = m->jnt_dofadr[jointid];
  int FR_hip_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
  //printf("%d %d %d %d \n",jointid,FR_hip_joint_qpos_adr,FR_hip_joint_qvel_adr,FR_hip_joint_actuatorID);

  joint_name = "FR_thigh_joint";
  actuator_name = "FR_thigh";
  jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
  int FR_thigh_joint_qpos_adr = m->jnt_qposadr[jointid];
  int FR_thigh_joint_qvel_adr = m->jnt_dofadr[jointid];
  int FR_thigh_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
  //printf("%d %d %d %d \n",jointid, FR_thigh_joint_qpos_adr,FR_thigh_joint_qvel_adr,FR_thigh_joint_actuatorID);


  joint_name = "FR_calf_joint";
  actuator_name = "FR_calf";
  jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
  int FR_calf_joint_qpos_adr = m->jnt_qposadr[jointid];
  int FR_calf_joint_qvel_adr = m->jnt_dofadr[jointid];
  int FR_calf_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
  //printf("%d %d %d %d \n",jointid,FR_calf_joint_qpos_adr,FR_calf_joint_qvel_adr,FR_calf_joint_actuatorID);

  joint_name = "FL_hip_joint";
  actuator_name = "FL_hip";
  jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
  int FL_hip_joint_qpos_adr = m->jnt_qposadr[jointid];
  int FL_hip_joint_qvel_adr = m->jnt_dofadr[jointid];
  int FL_hip_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
  //printf("%d %d %d %d \n",jointid,FL_hip_joint_qpos_adr,FL_hip_joint_qvel_adr,FL_hip_joint_actuatorID);

  joint_name = "FL_thigh_joint";
  actuator_name = "FL_thigh";
  jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
  int FL_thigh_joint_qpos_adr = m->jnt_qposadr[jointid];
  int FL_thigh_joint_qvel_adr = m->jnt_dofadr[jointid];
  int FL_thigh_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
  //printf("%d %d %d %d \n",jointid, FL_thigh_joint_qpos_adr,FL_thigh_joint_qvel_adr,FL_thigh_joint_actuatorID);

  joint_name = "FL_calf_joint";
  actuator_name = "FL_calf";
  jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
  int FL_calf_joint_qpos_adr = m->jnt_qposadr[jointid];
  int FL_calf_joint_qvel_adr = m->jnt_dofadr[jointid];
  int FL_calf_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
  //printf("%d %d %d %d \n",jointid,FL_calf_joint_qpos_adr,FL_calf_joint_qvel_adr,FL_calf_joint_actuatorID);

  joint_name = "RR_hip_joint";
  actuator_name = "RR_hip";
  jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
  int RR_hip_joint_qpos_adr = m->jnt_qposadr[jointid];
  int RR_hip_joint_qvel_adr = m->jnt_dofadr[jointid];
  int RR_hip_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
  //printf("%d %d %d %d \n",jointid,RR_hip_joint_qpos_adr,RR_hip_joint_qvel_adr,RR_hip_joint_actuatorID);

  joint_name = "RR_thigh_joint";
  actuator_name = "RR_thigh";
  jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
  int RR_thigh_joint_qpos_adr = m->jnt_qposadr[jointid];
  int RR_thigh_joint_qvel_adr = m->jnt_dofadr[jointid];
  int RR_thigh_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
  //printf("%d %d %d %d \n",jointid, RR_thigh_joint_qpos_adr,RR_thigh_joint_qvel_adr,RR_thigh_joint_actuatorID);

  joint_name = "RR_calf_joint";
  actuator_name = "RR_calf";
  jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
  int RR_calf_joint_qpos_adr = m->jnt_qposadr[jointid];
  int RR_calf_joint_qvel_adr = m->jnt_dofadr[jointid];
  int RR_calf_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
  //printf("%d %d %d %d \n",jointid,RR_calf_joint_qpos_adr,RR_calf_joint_qvel_adr,RR_calf_joint_actuatorID);


  joint_name = "RL_hip_joint";
actuator_name = "RL_hip";
jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
int RL_hip_joint_qpos_adr = m->jnt_qposadr[jointid];
int RL_hip_joint_qvel_adr = m->jnt_dofadr[jointid];
int RL_hip_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
//printf("%d %d %d %d \n",jointid,RL_hip_joint_qpos_adr,RL_hip_joint_qvel_adr,RL_hip_joint_actuatorID);

joint_name = "RL_thigh_joint";
actuator_name = "RL_thigh";
jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
int RL_thigh_joint_qpos_adr = m->jnt_qposadr[jointid];
int RL_thigh_joint_qvel_adr = m->jnt_dofadr[jointid];
int RL_thigh_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
//printf("%d %d %d %d \n",jointid, RL_thigh_joint_qpos_adr,RL_thigh_joint_qvel_adr,RL_thigh_joint_actuatorID);

joint_name = "RL_calf_joint";
actuator_name = "RL_calf";
jointid = mj_name2id(m, mjOBJ_JOINT, joint_name);
int RL_calf_joint_qpos_adr = m->jnt_qposadr[jointid];
int RL_calf_joint_qvel_adr = m->jnt_dofadr[jointid];
int RL_calf_joint_actuatorID = mj_name2id(m, mjOBJ_ACTUATOR, actuator_name);
//printf("%d %d %d %d \n",jointid,RL_calf_joint_qpos_adr,RL_calf_joint_qvel_adr,RL_calf_joint_actuatorID);

//Base
  const char* base_pos_name = "Body_Pos";
  int base_sensorID = mj_name2id(m, mjOBJ_SENSOR, base_pos_name);
  int base_sensor_adr = m->sensor_adr[base_sensorID];

  const char* base_quat_name = "Body_Quat";
  int base_quat_sensorID = mj_name2id(m, mjOBJ_SENSOR, base_quat_name);
  int base_quat_sensor_adr = m->sensor_adr[base_quat_sensorID];

  int base_linvel_sensorID = mj_name2id(m, mjOBJ_SENSOR, "Body_LinVel");
  int base_linvel_sensor_adr = m->sensor_adr[base_linvel_sensorID];
  int base_angvel_sensorID = mj_name2id(m, mjOBJ_SENSOR, "Body_Gyro");
  int base_angvel_sensor_adr = m->sensor_adr[base_angvel_sensorID];

  int base_linacc_sensorID = mj_name2id(m, mjOBJ_SENSOR, "Body_Acc");
  int base_linacc_sensor_adr = m->sensor_adr[base_linacc_sensorID];

  const char* pos_FR_foot = "FR_foot_pos";
  int pos_FR_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_FR_foot);
  int pos_FR_adr = m->sensor_adr[pos_FR_sensorID];

  const char* pos_FL_foot = "FL_foot_pos";
  int pos_FL_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_FL_foot);
  int pos_FL_adr = m->sensor_adr[pos_FL_sensorID];

  const char* pos_RR_foot = "RR_foot_pos";
  int pos_RR_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_RR_foot);
  int pos_RR_adr = m->sensor_adr[pos_RR_sensorID];

  const char* pos_RL_foot = "RL_foot_pos";
  int pos_RL_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_RL_foot);
  int pos_RL_adr = m->sensor_adr[pos_RL_sensorID];

  const char* pos_FR_shoulder = "FR_shoulder_pos";
  int pos_FR_shoulder_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_FR_shoulder);
  int pos_FR_shoulder_adr = m->sensor_adr[pos_FR_shoulder_sensorID];

  const char* pos_FL_shoulder = "FL_shoulder_pos";
  int pos_FL_shoulder_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_FL_shoulder);
  int pos_FL_shoulder_adr = m->sensor_adr[pos_FL_shoulder_sensorID];

  const char* pos_RR_shoulder = "RR_shoulder_pos";
  int pos_RR_shoulder_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_RR_shoulder);
  int pos_RR_shoulder_adr = m->sensor_adr[pos_RR_shoulder_sensorID];

  const char* pos_RL_shoulder = "RL_shoulder_pos";
  int pos_RL_shoulder_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_RL_shoulder);
  int pos_RL_shoulder_adr = m->sensor_adr[pos_RL_shoulder_sensorID];

  const char* pos_FR_elbow = "FR_elbow_pos";
  int pos_FR_elbow_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_FR_elbow);
  int pos_FR_elbow_adr = m->sensor_adr[pos_FR_elbow_sensorID];

  const char* pos_FL_elbow = "FL_elbow_pos";
  int pos_FL_elbow_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_FL_elbow);
  int pos_FL_elbow_adr = m->sensor_adr[pos_FL_elbow_sensorID];

  const char* pos_RR_elbow = "RR_elbow_pos";
  int pos_RR_elbow_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_RR_elbow);
  int pos_RR_elbow_adr = m->sensor_adr[pos_RR_elbow_sensorID];

  const char* pos_RL_elbow = "RL_elbow_pos";
  int pos_RL_elbow_sensorID = mj_name2id(m, mjOBJ_SENSOR, pos_RL_elbow);
  int pos_RL_elbow_adr = m->sensor_adr[pos_RL_elbow_sensorID];

  //COM sensor
  const char* robot_com = "robot_com";
  int com_sensorID = mj_name2id(m, mjOBJ_SENSOR, robot_com);
  int com_sensor_adr = m->sensor_adr[com_sensorID];

  //velocity
  const char* vel_FR_foot = "FR_foot_vel";
  int vel_FR_sensorID = mj_name2id(m, mjOBJ_SENSOR, vel_FR_foot);
  int vel_FR_adr = m->sensor_adr[vel_FR_sensorID];

  const char* vel_FL_foot = "FL_foot_vel";
  int vel_FL_sensorID = mj_name2id(m, mjOBJ_SENSOR, vel_FL_foot);
  int vel_FL_adr = m->sensor_adr[vel_FL_sensorID];

  const char* vel_RR_foot = "RR_foot_vel";
  int vel_RR_sensorID = mj_name2id(m, mjOBJ_SENSOR, vel_RR_foot);
  int vel_RR_adr = m->sensor_adr[vel_RR_sensorID];

  const char* vel_RL_foot = "RL_foot_vel";
  int vel_RL_sensorID = mj_name2id(m, mjOBJ_SENSOR, vel_RL_foot);
  int vel_RL_adr = m->sensor_adr[vel_RL_sensorID];

  const char* vel_FR_shoulder = "FR_shoulder_vel";
  int vel_FR_shoulder_sensorID = mj_name2id(m, mjOBJ_SENSOR, vel_FR_shoulder);
  int vel_FR_shoulder_adr = m->sensor_adr[vel_FR_shoulder_sensorID];

  const char* vel_FL_shoulder = "FL_shoulder_vel";
  int vel_FL_shoulder_sensorID = mj_name2id(m, mjOBJ_SENSOR, vel_FL_shoulder);
  int vel_FL_shoulder_adr = m->sensor_adr[vel_FL_shoulder_sensorID];

  const char* vel_RR_shoulder = "RR_shoulder_vel";
  int vel_RR_shoulder_sensorID = mj_name2id(m, mjOBJ_SENSOR, vel_RR_shoulder);
  int vel_RR_shoulder_adr = m->sensor_adr[vel_RR_shoulder_sensorID];

  const char* vel_RL_shoulder = "RL_shoulder_vel";
  int vel_RL_shoulder_sensorID = mj_name2id(m, mjOBJ_SENSOR, vel_RL_shoulder);
  int vel_RL_shoulder_adr = m->sensor_adr[vel_RL_shoulder_sensorID];

  //contact sensors
  //const char* force_FR_foot = "FR_footForce";
  int force_FR_foot_sensorID = mj_name2id(m, mjOBJ_SENSOR, "FR_footForce");
  int force_FR_foot_adr = m->sensor_adr[force_FR_foot_sensorID];

  int force_FL_foot_sensorID = mj_name2id(m, mjOBJ_SENSOR, "FL_footForce");
  int force_FL_foot_adr = m->sensor_adr[force_FL_foot_sensorID];

  int force_RR_foot_sensorID = mj_name2id(m, mjOBJ_SENSOR, "RR_footForce");
  int force_RR_foot_adr = m->sensor_adr[force_RR_foot_sensorID];

  int force_RL_foot_sensorID = mj_name2id(m, mjOBJ_SENSOR, "RL_footForce");
  int force_RL_foot_adr = m->sensor_adr[force_RL_foot_sensorID];




   int temp_IDq[] = {FR_hip_joint_qpos_adr,FR_thigh_joint_qpos_adr,FR_calf_joint_qpos_adr,
                     FL_hip_joint_qpos_adr,FL_thigh_joint_qpos_adr,FL_calf_joint_qpos_adr,
                     RR_hip_joint_qpos_adr,RR_thigh_joint_qpos_adr,RR_calf_joint_qpos_adr,
                     RL_hip_joint_qpos_adr,RL_thigh_joint_qpos_adr,RL_calf_joint_qpos_adr};

   int temp_IDv[] = {FR_hip_joint_qvel_adr,FR_thigh_joint_qvel_adr,FR_calf_joint_qvel_adr,
                     FL_hip_joint_qvel_adr,FL_thigh_joint_qvel_adr,FL_calf_joint_qvel_adr,
                     RR_hip_joint_qvel_adr,RR_thigh_joint_qvel_adr,RR_calf_joint_qvel_adr,
                     RL_hip_joint_qvel_adr,RL_thigh_joint_qvel_adr,RL_calf_joint_qvel_adr};

   int temp_IDT[] = {FR_hip_joint_actuatorID,FR_thigh_joint_actuatorID,FR_calf_joint_actuatorID,
                     FL_hip_joint_actuatorID,FL_thigh_joint_actuatorID,FL_calf_joint_actuatorID,
                     RR_hip_joint_actuatorID,RR_thigh_joint_actuatorID,RR_calf_joint_actuatorID,
                     RL_hip_joint_actuatorID,RL_thigh_joint_actuatorID,RL_calf_joint_actuatorID};

   int temp_baseID[] = {base_sensor_adr, base_sensor_adr+1, base_sensor_adr+2,
                        base_quat_sensor_adr, base_quat_sensor_adr+1, base_quat_sensor_adr+2, base_quat_sensor_adr+3,  //w component should be last
                        base_angvel_sensor_adr, base_angvel_sensor_adr+1, base_angvel_sensor_adr+2,
                       base_linacc_sensor_adr, base_linacc_sensor_adr+1, base_linacc_sensor_adr+2,
                       base_linvel_sensor_adr, base_linvel_sensor_adr+1, base_linvel_sensor_adr+2};

   int temp_endeffectorID[] = {pos_FR_adr,pos_FR_adr+1,pos_FR_adr+2,
                               pos_FL_adr,pos_FL_adr+1,pos_FL_adr+2,
                               pos_RR_adr,pos_RR_adr+1,pos_RR_adr+2,
                               pos_RL_adr,pos_RL_adr+1,pos_RL_adr+2};

   int temp_shoulderID[] = {pos_FR_shoulder_adr,pos_FR_shoulder_adr+1,pos_FR_shoulder_adr+2,
                             pos_FL_shoulder_adr,pos_FL_shoulder_adr+1,pos_FL_shoulder_adr+2,
                             pos_RR_shoulder_adr,pos_RR_shoulder_adr+1,pos_RR_shoulder_adr+2,
                             pos_RL_shoulder_adr,pos_RL_shoulder_adr+1,pos_RL_shoulder_adr+2};

 int temp_elbowID[] = {pos_FR_elbow_adr,pos_FR_elbow_adr+1,pos_FR_elbow_adr+2,
                           pos_FL_elbow_adr,pos_FL_elbow_adr+1,pos_FL_elbow_adr+2,
                           pos_RR_elbow_adr,pos_RR_elbow_adr+1,pos_RR_elbow_adr+2,
                           pos_RL_elbow_adr,pos_RL_elbow_adr+1,pos_RL_elbow_adr+2};

int temp_endeffectorID2[] = {vel_FR_adr,vel_FR_adr+1,vel_FR_adr+2,
                           vel_FL_adr,vel_FL_adr+1,vel_FL_adr+2,
                           vel_RR_adr,vel_RR_adr+1,vel_RR_adr+2,
                           vel_RL_adr,vel_RL_adr+1,vel_RL_adr+2};

int temp_shoulderID2[] = {vel_FR_shoulder_adr,vel_FR_shoulder_adr+1,vel_FR_shoulder_adr+2,
                         vel_FL_shoulder_adr,vel_FL_shoulder_adr+1,vel_FL_shoulder_adr+2,
                         vel_RR_shoulder_adr,vel_RR_shoulder_adr+1,vel_RR_shoulder_adr+2,
                         vel_RL_shoulder_adr,vel_RL_shoulder_adr+1,vel_RL_shoulder_adr+2};


int temp_comID[] = {com_sensor_adr,com_sensor_adr+1,com_sensor_adr+2};

int temp_footForceID[] = {force_FR_foot_adr,force_FL_foot_adr,force_RR_foot_adr,force_RL_foot_adr};

 for (i=0;i<nact;i++)
   {
     q_id[i] = temp_IDq[i];
     v_id[i] = temp_IDv[i];
     act_id[i] = temp_IDT[i];
  }

   for (i=0;i<nbase;i++)
   {
     base_stateid[i] = temp_baseID[i];
   }

   for (i=0;i<nendeff;i++)
   {
     endeff_stateid[i] = temp_endeffectorID[i];
     shoulder_stateid[i] = temp_shoulderID[i];
     elbow_stateid[i] = temp_elbowID[i];

     endeff_velid[i] = temp_endeffectorID2[i];
     shoulder_velid[i] = temp_shoulderID2[i];
   }

   for (i=0;i<3;i++)
    com_id[i] = temp_comID[i];

   for (i=0;i<4;i++)
    footForce_id[i]= temp_footForceID[i];

  printf("\n\n ************ All joint IDs set ***** \n\n");

}

void udp_GetRecv(LowState *state, RobotState *modelstate)
{
  int i,j,k;

  // robotstate->time = d->time;

  for (i=0;i<nact;i++)
  {
    state->motorState[i].q = d->qpos[q_id[i]];
    state->motorState[i].dq = d->qvel[v_id[i]];
  }

    i = 0;
    //double bodyWorldPos[3]={0};
    bodyWorldPos[0] = d->sensordata[base_stateid[i]]; i+=1;
    bodyWorldPos[1] = d->sensordata[base_stateid[i]]; i+=1;
    bodyWorldPos[2] = d->sensordata[base_stateid[i]]; i+=1;


    state->imu.quaternion[0] = d->sensordata[base_stateid[i]]; i+=1;
    state->imu.quaternion[1] = d->sensordata[base_stateid[i]]; i+=1;
    state->imu.quaternion[2] = d->sensordata[base_stateid[i]]; i+=1;
    state->imu.quaternion[3] = d->sensordata[base_stateid[i]]; i+=1;

    state->imu.gyroscope[0] = d->sensordata[base_stateid[i]]; i+=1;
    state->imu.gyroscope[1] = d->sensordata[base_stateid[i]]; i+=1;
    state->imu.gyroscope[2] = d->sensordata[base_stateid[i]]; i+=1;

    state->imu.accelerometer[0] = d->sensordata[base_stateid[i]]; i+=1;
    state->imu.accelerometer[1] = d->sensordata[base_stateid[i]]; i+=1;
    state->imu.accelerometer[2] = d->sensordata[base_stateid[i]]; i+=1;


    double dc[3][3]={0};
    double euler1, euler2, euler3;
    sdquat2dc(state->imu.quaternion[1],  state->imu.quaternion[2],
              state->imu.quaternion[3], state->imu.quaternion[0],dc); sdprinterr(stderr);
    sddc2ang(dc,&euler1,&euler2,&euler3); sdprinterr(stderr);

    //this needs to be check later
    state->imu.rpy[0]=euler1;
    state->imu.rpy[1]=euler2;
    state->imu.rpy[2]=euler3;

    for (i=0;i<4;i++)
      state->footForce[i] = (int) d->sensordata[footForce_id[i]];

}

void udp_SetSend(const LowState *state, LowCmd *cmd)
{
  int i;
  double command;
  double q[nact]={0}, u[nact]={0};

  for (i=0;i<nact;i++)
  {
  q[i]=state->motorState[i].q;
  u[i]=state->motorState[i].dq;
  }

  for (i=0;i<nact;i++)
  {
     command = cmd->motorCmd[i].tau +
               cmd->motorCmd[i].Kp*(cmd->motorCmd[i].q - q[i]) +
               cmd->motorCmd[i].Kd*(cmd->motorCmd[i].dq - u[i]);
  if (command<trq_min)
    {command = trq_min;}
  else if (command>trq_max)
    {command = trq_max;}

   d->ctrl[act_id[i]] = command;
  }

}

//control loop callback
void RobotControl(const mjModel* m, mjData* d)
{
  double tau[nact]={0};
  double q_act[nact] = {0};
  double u_act[nact] = {0};
  double q_ref[nact] = {0};
  double u_ref[nact] = {0};
  double Kp[nact]={0};
  double Kd[nact]={0};
  double quat_act[4] = {0};
  double omega_act[3] = {0};
  uint16_t footForce[4]={0};
  double tauEst[nact];
  double bodyWorldPos[3] = {0};
  double tracking_error[2] = {0};

  //increase time
  motiontime++;

  //get state from simu;ation
  udp_GetRecv(&state,&modelstate);

  //get state
  get_state(motiontime, &state,&modelstate,quat_act,omega_act,q_act,u_act,footForce,bodyWorldPos);

  //actions for controller
  if (fsm_controller == fsm_controller_init)
  {
      init_controller(motiontime,quat_act,omega_act,q_act,u_act);
      fid2 = fopen(path2,"w");
      init_save_data();
  }
  if (fsm_controller == fsm_controller_run)
  {
      my_controller(motiontime,quat_act,omega_act,q_act,u_act,tau,Kp,Kd,q_ref,u_ref,
                    tauEst,footForce);

      if ( motiontime%data_frequency==0)
      {
      save_data(motiontime,&state,&cmd,&modelstate);
      }
  }
  if (fsm_controller == fsm_controller_end)
  {
      my_controller(motiontime,quat_act,omega_act,q_act,u_act,tau,Kp,Kd,q_ref,u_ref,
                    tauEst,footForce);
  }

  //transitions for controller
  if (fsm_controller == fsm_controller_init )
  {
      fsm_controller = fsm_controller_run;
  }
  if (fsm_controller == fsm_controller_run && motiontime*dtime > time_end)
  {
      fsm_controller = fsm_controller_end;
      fclose(fid2);
      printf("Controller ends \n");
      exit(0);
  }


  //set torque
  set_torque(motiontime,&cmd,tau,Kp,Kd,q_ref,u_ref);


  //send cmd to simulation
  udp_SetSend(&state,&cmd);


  if ( motiontime%data_frequency==0)
  {
    save_data(motiontime,&state,&cmd,&modelstate);
  }


 }

// main function
int main(int argc, const char** argv)
{

    // check command-line arguments
    if( argc!=2 )
    {
        printf(" USAGE:  basic modelfile\n");
        return 0;
    }

    // activate software
    // mj_activate("../../../mjkey.txt");
    mj_activate("mjkey.txt");

    // load and compile model
    char error[1000] = "Could not load binary model";
    if( strlen(argv[1])>4 && !strcmp(argv[1]+strlen(argv[1])-4, ".mjb") )
        m = mj_loadModel(argv[1], 0);
    else
        m = mj_loadXML(argv[1], 0, error, 1000);
    if( !m )
        mju_error_s("Load model error: %s", error);

    // make data
    d = mj_makeData(m);


    // init GLFW
    if( !glfwInit() )
        mju_error("Could not initialize GLFW");

    // create window, make OpenGL context current, request v-sync
    //GLFWwindow* window = glfwCreateWindow(1200, 900, "Demo", NULL, NULL);//1200,900
     GLFWwindow* window = glfwCreateWindow(900, 600, "A1 demo", NULL, NULL);//1200,900
    //GLFWwindow* window = glfwCreateWindow(450, 300, "A1 demo", NULL, NULL);//1200,900
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // initialize visualization data structures
    mjv_defaultCamera(&cam);
    mjv_defaultOption(&opt);
    mjv_defaultScene(&scn);
    mjr_defaultContext(&con);

    // create scene and context
    mjv_makeScene(m, &scn, 2000);
    mjr_makeContext(m, &con, mjFONTSCALE_150);

    // install GLFW mouse and keyboard callbacks
    glfwSetKeyCallback(window, keyboard);
    glfwSetCursorPosCallback(window, mouse_move);
    glfwSetMouseButtonCallback(window, mouse_button);
    glfwSetScrollCallback(window, scroll);

    //get IDs of joints considered
    get_ID();



    //set camera distance
    double arr_view[] = {-89.431857, -69.955732, 4.770732, -2.000000, 0.000000, 0.000000}; //-2.844089

    cam.azimuth = arr_view[0];
    cam.elevation = arr_view[1];
    cam.distance = arr_view[2];
    cam.lookat[0] = arr_view[3];
    cam.lookat[1] = arr_view[4];
    cam.lookat[2] = arr_view[5];

    //initialization stuff
    //m->opt.gravity[2] = 0; //turn gravity off


    //https://www.andre-gaschler.com/rotationconverter/

    //rotate by 90 degrees about z-axis
    d->qpos[0] = init_pos_x; //y-coordinate
    d->qpos[1] = init_pos_y-0.2; //y-coordinate

    // d->qpos[3] = 1;
    // d->qpos[4] = 0;
    // d->qpos[5] = 0;
    // d->qpos[6] = 0;
    //leminscate
    d->qpos[3] = 0.7071068;
    d->qpos[4] = 0;
    d->qpos[5] = 0;
    d->qpos[6] = 0.7071068;




    while( !glfwWindowShouldClose(window) )
    {
        // advance interactive simulation for 1/60 sec
        //  Assuming MuJoCo can simulate faster than real-time, which it usually can,
        //  this loop will finish on time for the next frame to be rendered at 60 fps.
        //  Otherwise add a cpu timer and exit this loop when it is time to render.
        //printf("%f \n",d->time);
        // if (d->time<time_gravity_off)
        //   m->opt.gravity[2] = -0.5;
        // else
        //   m->opt.gravity[2] = -9.81;

        mjtNum simstart = d->time;
        double delay_normal = 1.0/60.0;
        double delay_short = 0.1;
        while( d->time - simstart < delay_normal )
        {
          if (d->time - t_control > dtime-1e-5)
          {
            RobotControl(m,d);
            t_control = d->time;
          }

            mj_step(m, d);

        }


        // get framebuffer viewport
        mjrRect viewport = {0, 0, 0, 0};
        glfwGetFramebufferSize(window, &viewport.width, &viewport.height);

        //cam.lookat[0] = -5; //d->xpos[3*1+0];
        //cam.lookat[1] = 0; //d->xpos[3*1+1];
        //cam.lookat[2] = d->xpos[3*1+2];
        // update scene and render
        //
        mjv_updateScene(m, d, &opt, NULL, &cam, mjCAT_ALL, &scn);
        mjr_render(viewport, &scn, &con);
        // mjr_figure(viewport, &fig, &con);


        // swap OpenGL buffers (blocking call due to v-sync)
        glfwSwapBuffers(window);

        // process pending GUI events, call GLFW callbacks
        glfwPollEvents();

        // move the animation to get updated values.
        //printf("{%f, %f, %f, %f, %f, %f};\n",cam.azimuth,cam.elevation, cam.distance,cam.lookat[0],cam.lookat[1],cam.lookat[2]);

    }

    //free visualization storage
    mjv_freeScene(&scn);
    mjr_freeContext(&con);

    // free MuJoCo model and data, deactivate
    mj_deleteData(d);
    mj_deleteModel(m);
    mj_deactivate();

    //sd_end();

    // terminate GLFW (crashes with Linux NVidia drivers)
    #if defined(__APPLE__) || defined(_WIN32)
        glfwTerminate();
    #endif

    return 1;
}
