void get_stance_forces(double quat[4],double omega[3],double q[nact],double u[nact],double F[4][3])
{
int i, j;


  //Need to convert quat to dc and back to quat using sd else gives normalization error
  double dc[3][3];
  double quat0, quat1, quat2, quat3;
  sdquat2dc(quat[1],quat[2],quat[3],quat[0],dc); sdprinterr(stderr);
  sddc2quat(dc,&quat1,&quat2,&quat3,&quat0); sdprinterr(stderr);
  quat[0] = quat0;
  quat[1] = quat1;
  quat[2] = quat2;
  quat[3] = quat3;

  set_model_state(quat,omega,q,u);

  double FR_foot_local[3] = {-0.0047 ,        0 ,  -0.0680};
  double pos_FR_foot_sdfast[3]={0};
  sdpos(FR_calf,FR_foot_local,pos_FR_foot_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_FR_foot_sdfast,0,pos_FR_foot_sdfast); sdprinterr(stderr);

  double FL_foot_local[3] = {-0.0047 ,        0 ,  -0.0680};
  double pos_FL_foot_sdfast[3]={0};
  sdpos(FL_calf,FL_foot_local,pos_FL_foot_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_FL_foot_sdfast,0,pos_FL_foot_sdfast); sdprinterr(stderr);

  double RR_foot_local[3] = {-0.0047 ,        0 ,  -0.0680};
  double pos_RR_foot_sdfast[3]={0};
  sdpos(RR_calf,RR_foot_local,pos_RR_foot_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_RR_foot_sdfast,0,pos_RR_foot_sdfast); sdprinterr(stderr);

  double RL_foot_local[3] = {-0.0047 ,        0 ,  -0.0680};
  double pos_RL_foot_sdfast[3]={0};
  sdpos(RL_calf,RL_foot_local,pos_RL_foot_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_RL_foot_sdfast,0,pos_RL_foot_sdfast); sdprinterr(stderr);

  double com_local[3] = {0,0,0};
  double pos_com_trunk[3];
  sdpos(trunk,com_local,pos_com_trunk); sdprinterr(stderr);
  sdtrans(-1,pos_com_trunk,0,pos_com_trunk); sdprinterr(stderr);

  double pos_FR_com2foot[3]={0};
  double pos_FL_com2foot[3]={0};
  double pos_RR_com2foot[3]={0};
  double pos_RL_com2foot[3]={0};

  for (i=0;i<3;i++)
  {
    pos_FR_com2foot[i] = pos_FR_foot_sdfast[i] - pos_com_trunk[i];
    pos_FL_com2foot[i] = pos_FL_foot_sdfast[i] - pos_com_trunk[i];
    pos_RR_com2foot[i] = pos_RR_foot_sdfast[i] - pos_com_trunk[i];
    pos_RL_com2foot[i] = pos_RL_foot_sdfast[i] - pos_com_trunk[i];
  }

  double pos_FR_mat[3][3];  double pos_FL_mat[3][3];
  double pos_RR_mat[3][3];  double pos_RL_mat[3][3];
  ram_multVec2SkewMat(&pos_FR_com2foot[0],3, &pos_FR_mat[0][0]);
  ram_multVec2SkewMat(&pos_FL_com2foot[0],3, &pos_FL_mat[0][0]);
  ram_multVec2SkewMat(&pos_RR_com2foot[0],3, &pos_RR_mat[0][0]);
  ram_multVec2SkewMat(&pos_RL_com2foot[0],3, &pos_RL_mat[0][0]);

  double A03[6][6] = {0};
  double A12[6][6] = {0};
  double A03inv[6][6] = {0};
  double A12inv[6][6] = {0};
  double x03[6] = {0};
  double x12[6] = {0};
  double b[6] = {0};
  b[2] = mass*g;


  double I[3][3]={0};
  ram_identity(&I[0][0],3);
  for (i=0;i<3;i++)
  {
    for (j=0;j<3;j++)
    {
      A03[i][j] = I[i][j];
      A03[i][j+3] = I[i][j];
      A03[i+3][j] = pos_FR_mat[i][j];
      A03[i+3][j+3] = pos_RL_mat[i][j];

      A12[i][j] = I[i][j];
      A12[i][j+3] = I[i][j];
      A12[i+3][j] = pos_FL_mat[i][j];
      A12[i+3][j+3] = pos_RR_mat[i][j];

    }
  }
  //ram_display(&A12[0][0],6,6,"A12");
  ram_pinverse(&A12[0][0],6,6, &A12inv[0][0]);
  ram_pinverse(&A03[0][0],6,6, &A03inv[0][0]);

  ram_multMatVec(&A12inv[0][0], 6,6, &b[0], 6,&x12[0]); //Multiply matrix to vector
  ram_multMatVec(&A03inv[0][0], 6,6, &b[0], 6,&x03[0]);
  //ram_display(&x03[0],6,1,"force");
  for (i=0;i<3;i++)
  {
    F[0][i] = x03[i];
    F[3][i] = x03[i+3];
    F[1][i] = x12[i];
    F[2][i] = x12[i+3];
  }


}
