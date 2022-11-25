void get_state(int motiontime, const LowState *state, const RobotState *modelstate, double quat[4], double omega[3],
             double q_act[nact],double u_act[nact],uint16_t footForce[4],double bodyWorldPos[3])
{
    int i;

    for (i=0;i<4;i++)
      quat[i]= state->imu.quaternion[i];

    for (i=0;i<3;i++)
      omega[i]= state->imu.gyroscope[i];

    for (i=0;i<nact;i++)
    {
      q_act[i] = state->motorState[i].q ;
      u_act[i] = state->motorState[i].dq ;
    }

    for (i=0;i<4;i++)
    {
      footForce[i] = state->footForce[i];
    }

    // bodyWorldPos[0] = modelstate->bodyWorldPos.x;
    // bodyWorldPos[1] = modelstate->bodyWorldPos.y;
    // bodyWorldPos[2] = modelstate->bodyWorldPos.z;
    //printf("  %f %f %f %f\n",state->imu.rpy[0],state->imu.rpy[1],omega[0],omega[1]);

}
