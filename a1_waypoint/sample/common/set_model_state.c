void set_model_state(double quat[4],double omega[3],double q[nact],double u[nact])
{
    int i;
    double t_sdfast, q_sdfast[NQ]={0}, u_sdfast[NU]={0}; //state_sdfast[NSTATE]={0};

    t_sdfast = 0; //not needed

    for (i=0;i<3;i++)
      q_sdfast[i] = 0; //not available

    for (i=0;i<3;i++)
       q_sdfast[i+3] = quat[i+1];
    q_sdfast[q_trunk_q0] = quat[0];

    for (i=0;i<3;i++)
      u_sdfast[i] = 0; //not available

    for (i=0;i<3;i++)
      u_sdfast[i+3] = omega[i];

    for (i=0;i<nact;i++)
      q_sdfast[i+q_FR_hip] = q[i]; //state->motorState[i].q ;

    for (i=0;i<nact;i++)
      u_sdfast[i+q_FR_hip] = u[i] ; //state->motorState[i].dq ;

    sdstate(t_sdfast,q_sdfast,u_sdfast); sdprinterr(stderr);

}
