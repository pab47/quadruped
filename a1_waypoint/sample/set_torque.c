void set_torque(int motiontime, LowCmd *cmd, double tau[nact],
              double Kp[nact],double Kd[nact],double qref[nact], double uref[nact])
{
    int i;
    float command;
    float angle;
    float ttime;

    ttime = motiontime*dtime;
    for (i=0;i<nact;i++)
    {
          command = tau[i];
          if (command<trq_min)
            {command = trq_min;}
          else if (command>trq_max)
            {command = trq_max;}

          angle = qref[i];
          if (angle < joint_min[i])
     	      {
              angle = joint_min[i];
              //printf("t=%f; jnt = %d, at min limit \n",ttime,i);
            }

     	    if (angle>joint_max[i])
     	     {
             angle = joint_max[i];
             //printf("t=%f; jnt = %d, at max limit  \n",ttime,i);
           }


         cmd->motorCmd[i].tau = command;
         cmd->motorCmd[i].Kp = Kp[i];
         cmd->motorCmd[i].Kd = Kd[i];
         cmd->motorCmd[i].q = angle;
         cmd->motorCmd[i].dq = uref[i];
    }
}
