

void init_save_data()
{
   fprintf(fid2,"t,");
   // fprintf(fid2,"x, y, z, q0, qx, qy, qz, vx, vy, vz, wx, wy, wz,");
   fprintf(fid2,"q0,qx,qy,qz,wx,wy,wz,");
   fprintf(fid2,"q_FR_hip,q_FR_thigh,q_FR_calf,q_FL_hip,q_FL_thigh,q_FL_calf,q_RR_hip,q_RR_thigh,q_RR_calR,q_RL_hip,q_RL_thigh,q_RL_calR,");
   fprintf(fid2,"v_FR_hip,v_FR_thigh,v_FR_calf,v_FL_hip,v_FL_thigh,v_FL_calf,v_RR_hip,v_RR_thigh,v_RR_calR,v_RL_hip,v_RL_thigh,v_RL_calR,");
   fprintf(fid2,"tau_FR_hip,tau_FR_thigh,tau_FR_calf,tau_FL_hip,tau_FL_thigh,tau_FL_calf,tau_RR_hip,tau_RR_thigh,tau_RR_calR,tau_RL_hip,tau_RL_thigh,tau_RL_calR,");
   fprintf(fid2,"qref_FR_hip,qref_FR_thigh,qref_FR_calf,qref_FL_hip,qref_FL_thigh,qref_FL_calf,qref_RR_hip,qref_RR_thigh,qref_RR_calR,qref_RL_hip,qref_RL_thigh,qref_RL_calR,");
   fprintf(fid2,"uref_FR_hip,uref_FR_thigh,uref_FR_calf,uref_FL_hip,uref_FL_thigh,uref_FL_calf,uref_RR_hip,uref_RR_thigh,uref_RR_calR,uref_RL_hip,uref_RL_thigh,uref_RL_calR,");
   fprintf(fid2,"Kp_FR_hip,Kp_FR_thigh,Kp_FR_calf,Kp_FL_hip,Kp_FL_thigh,Kp_FL_calf,Kp_RR_hip,Kp_RR_thigh,Kp_RR_calR,Kp_RL_hip,Kp_RL_thigh,Kp_RL_calR,");
   fprintf(fid2,"Kd_FR_hip,Kd_FR_thigh,Kd_FR_calf,Kd_FL_hip,Kd_FL_thigh,Kd_FL_calf,Kd_RR_hip,Kd_RR_thigh,Kd_RR_calR,Kd_RL_hip,Kd_RL_thigh,Kd_RL_calR,");
   // fprintf(fid2,"pos_FR_foot2shoulder_x,pos_FR_foot2shoulder_y,pos_FR_foot2shoulder_z,");
   // fprintf(fid2,"pos_FL_foot2shoulder_x,pos_FL_foot2shoulder_y,pos_FL_foot2shoulder_z,");
   // fprintf(fid2,"pos_RR_foot2shoulder_x,pos_RR_foot2shoulder_y,pos_RR_foot2shoulder_z,");
   // fprintf(fid2,"pos_RL_foot2shoulder_x,pos_RL_foot2shoulder_y,pos_RL_foot2shoulder_z,");
   // fprintf(fid2,"pos_FR_foot2shoulder_vx,pos_FR_foot2shoulder_vy,pos_FR_foot2shoulder_vz,");
   // fprintf(fid2,"pos_FL_foot2shoulder_vx,pos_FL_foot2shoulder_vy,pos_FL_foot2shoulder_vz,");
   // fprintf(fid2,"pos_RR_foot2shoulder_vx,pos_RR_foot2shoulder_vy,pos_RR_foot2shoulder_vz,");
   // fprintf(fid2,"pos_RL_foot2shoulder_vx,pos_RL_foot2shoulder_vy,pos_RL_foot2shoulder_vz,");
   // fprintf(fid2,"com_x,com_y,com_z,");
  fprintf(fid2,"eulerX,eulerY,eulerZ,");
  fprintf(fid2,"forceFR,forceFL,forceRR,forceRL,");

  // fprintf(fid2,"WorldPosX,WorldPosY,WorldPosZ,");
  // fprintf(fid2,"WorldVelX,WorldVelY,WorldVelZ");

  //fprintf(fid2,"error_x,error_y");
  fprintf(fid2,"\n");

}

void save_data(int motiontime, const LowState *state,const LowCmd *cmd,const RobotState *modelstate)
{
      int i;

      //time
      fprintf(fid2,"%f, ",(double) motiontime*dtime);

      //base_x
      // fprintf(fid2,"%f, ",robotstate->bodyWorldPos.x);
      // fprintf(fid2,"%f, ",robotstate->bodyWorldPos.y);
      // fprintf(fid2,"%f, ",robotstate->bodyWorldPos.z);

      //quaternions
      for (i=0;i<4;i++)
        fprintf(fid2,"%f, ",state->imu.quaternion[i]);

      //base_linvelocity
      // fprintf(fid2,"%f, ",robotstate->bodyWorldVel.x );
      // fprintf(fid2,"%f, ",robotstate->bodyWorldVel.y);
      // fprintf(fid2,"%f, ",robotstate->bodyWorldVel.z);

      //base_angvelocity
      for (i=0;i<3;i++)
        fprintf(fid2,"%f, ",state->imu.gyroscope[i]);

      //q's
      for (i=0;i<nact;i++)
        fprintf(fid2,"%f, ",state->motorState[i].q);

      //u's
      for (i=0;i<nact;i++)
        fprintf(fid2,"%f, ",state->motorState[i].dq);

      //tau's
      for (i=0;i<nact;i++)
        fprintf(fid2,"%f, ",cmd->motorCmd[i].tau);

      for (i=0;i<nact;i++)
        fprintf(fid2,"%f, ",cmd->motorCmd[i].q);

      for (i=0;i<nact;i++)
        fprintf(fid2,"%f, ",cmd->motorCmd[i].dq);

      for (i=0;i<nact;i++)
        fprintf(fid2,"%f, ",cmd->motorCmd[i].Kp);

      for (i=0;i<nact;i++)
        fprintf(fid2,"%f, ",cmd->motorCmd[i].Kd);


        //positions
      // for (i=0;i<4;i++)
      // {
      //   fprintf(fid2,"%f, %f, %f, ",robotstate->footPosition2Body[i].x,
      //                               robotstate->footPosition2Body[i].y,
      //                               robotstate->footPosition2Body[i].z);
      // }

      //speeds
      // for (i=0;i<4;i++)
      // {
      //   fprintf(fid2,"%f, %f, %f, ",robotstate->footSpeed2Body[i].x,
      //                               robotstate->footSpeed2Body[i].y,
      //                               robotstate->footSpeed2Body[i].z);
      // }

      //com
      // fprintf(fid2,"%f, ",robotstate->com.x);
      // fprintf(fid2,"%f, ",robotstate->com.y);
      // fprintf(fid2,"%f, ",robotstate->com.z);

      for (i=0;i<3;i++)
        fprintf(fid2,"%f, ",state->imu.rpy[i]);

      for (i=0;i<4;i++)
        fprintf(fid2,"%d, ",state->footForce[i]);
      // fprintf(fid2,"%f, ",robotstate->com.y);
      // fprintf(fid2,"%f, ",robotstate->com.z);

      // fprintf(fid2,"%f, ",modelstate->bodyWorldPos.x);
      // fprintf(fid2,"%f, ",modelstate->bodyWorldPos.y);
      // fprintf(fid2,"%f, ",modelstate->bodyWorldPos.z);
      // fprintf(fid2,"%f, ",modelstate->bodyWorldVel.x);
      // fprintf(fid2,"%f, ",modelstate->bodyWorldVel.y);
      // fprintf(fid2,"%f  ",modelstate->bodyWorldVel.z);

      // fprintf(fid2,"%f, ",modelstate->tracking_error_x);
      // fprintf(fid2,"%f  ",modelstate->tracking_error_y);
      fprintf(fid2,"\n");

}
