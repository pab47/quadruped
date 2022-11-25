
#define dtime 0.001 // 0.001~0.01
#define width_calibration 0.085
#define body_length 0.24 //0.36

#define nact 12
#define nact_leg 3

#define mass  12.46 //4.72+4*(0.696+1.013+0.226);
#define g  9.81
#define leg_length 0.2

#define pi M_PI

#define N_traj 6

double trq_max = 33.5;
double trq_min = -33.5;

// definition of each leg and joint
const int leg_FR = 0;       // leg index
const int leg_FL = 1;
const int leg_RR = 2;
const int leg_RL = 3;


const int act_FR_0 = 0;      // motor index
const int act_FR_1 = 1;
const int act_FR_2 = 2;

const int act_FL_0 = 3;
const int act_FL_1 = 4;
const int act_FL_2 = 5;

const int act_RR_0 = 6;
const int act_RR_1 = 7;
const int act_RR_2 = 8;

const int act_RL_0 = 9;
const int act_RL_1 = 10;
const int act_RL_2 = 11;

int index_leg_act[4][3] = {
                      {act_FR_0,act_FR_1,act_FR_2},
                      {act_FL_0,act_FL_1,act_FL_2},
                      {act_RR_0,act_RR_1,act_RR_2},
                      {act_RL_0,act_RL_1,act_RL_2}
                      };

//joint limits
double joint_min[] = {
 -0.802851,
-1.0472,
-2.69653,
-0.802851,
-1.0472,
-2.69653,
-0.802851,
-1.0472,
-2.69653,
-0.802851,
-1.0472,
-2.69653};


double joint_max[] = {
  0.802851,
  4.18879,
  -0.916298,
  0.802851,
  4.18879,
  -0.916298,
  0.802851,
  4.18879,
  -0.916298,
  0.802851,
  4.18879,
  -0.916298,
  0.802851,
  4.18879,
  -0.916298};

double joint_mean[]={
  0,1.57,-1.8,
  0,1.57,-1.8,
  0,1.57,-1.8,
  0,1.57,-1.8
  };

double joint_min3[] = {  -0.802851, -1.0472, -2.69653};
double joint_max3[] = {   0.802851,  4.18879,  -0.916298};

double joint_mean3[]={0,1.57,-1.8};

//sdfast parameters

#define NQ 19
#define NU 18
#define NACT 12
#define NSTATE (NQ+NU)

#define ground	(-1)
#define trunk 0
#define FR_hip 1
#define FR_thigh 2
#define FR_calf 3
#define FL_hip 4
#define FL_thigh 5
#define FL_calf 6
#define RR_hip 7
#define RR_thigh 8
#define RR_calf 9
#define RL_hip 10
#define RL_thigh 11
#define RL_calf 12

#define q_trunk_x 0
#define q_trunk_y 1
#define q_trunk_z 2
#define q_trunk_qx 3
#define q_trunk_qy 4
#define q_trunk_qz 5
#define q_FR_hip 6
#define q_FR_thigh 7
#define q_FR_calf 8
#define q_FL_hip 9
#define q_FL_thigh 10
#define q_FL_calf 11
#define q_RR_hip 12
#define q_RR_thigh 13
#define q_RR_calf 14
#define q_RL_hip 15
#define q_RL_thigh 16
#define q_RL_calf 17
#define q_trunk_q0 18

#define u_trunk_x 19
#define u_trunk_y 20
#define u_trunk_z 21
#define u_trunk_qx 22
#define u_trunk_qy 23
#define u_trunk_qz 24
#define u_FR_hip 25
#define u_FR_thigh 26
#define u_FR_calf 27
#define u_FL_hip 28
#define u_FL_thigh 29
#define u_FL_calf 30
#define u_RR_hip 31
#define u_RR_thigh 32
#define u_RR_calf 33
#define u_RL_hip 34
#define u_RL_thigh 35
#define u_RL_calf 36
