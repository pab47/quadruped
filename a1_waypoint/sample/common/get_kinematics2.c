void get_kinematics2(int leg_no,double q[3], double pos_sdfast_foot2shoulder[3],double vel_sdfast_foot2shoulder[3] )
{

  int i,ii;
  double quat0[4]={0}; quat0[0]=1;
  double omega0[3] = {0}; double u0[nact]={0}; double qref[nact]={0};
  for (i=0;i<3;i++)
    qref[index_leg_act[leg_no][i]] = q[i];
  set_model_state(quat0,omega0,qref,u0);

//************************************************************************

  if (leg_no == 0)
  {
  double FR_shoulder_local[3] = {0.1703,   -0.0492,   -0.0005};
  double pos_FR_shoulder_sdfast[3]={0};
  double vel_FR_shoulder_sdfast[3]={0};
  sdpos(trunk,FR_shoulder_local,pos_FR_shoulder_sdfast);  sdprinterr(stderr);
  sdvel(trunk,FR_shoulder_local,vel_FR_shoulder_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_FR_shoulder_sdfast,0,pos_FR_shoulder_sdfast); sdprinterr(stderr);
  sdtrans(-1,vel_FR_shoulder_sdfast,0,vel_FR_shoulder_sdfast); sdprinterr(stderr);

  // double FR_elbow_local[3] = {-0.0047 ,        0 ,   0.1320};
  // double pos_FR_elbow_sdfast[3]={0};
  // double vel_FR_elbow_sdfast[3]={0};
  // sdpos(FR_calf,FR_elbow_local,pos_FR_elbow_sdfast);  sdprinterr(stderr);
  // sdtrans(-1,pos_FR_elbow_sdfast,0,pos_FR_elbow_sdfast); sdprinterr(stderr);

  double FR_foot_local[3] = {-0.0047 ,        0 ,  -0.0680};
  double pos_FR_foot_sdfast[3]={0};
  double vel_FR_foot_sdfast[3]={0};
  sdpos(FR_calf,FR_foot_local,pos_FR_foot_sdfast);  sdprinterr(stderr);
  sdvel(FR_calf,FR_foot_local,vel_FR_foot_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_FR_foot_sdfast,0,pos_FR_foot_sdfast); sdprinterr(stderr);
  sdtrans(-1,vel_FR_foot_sdfast,0,vel_FR_foot_sdfast); sdprinterr(stderr);
    for (i=0;i<3;i++)
    {
      pos_sdfast_foot2shoulder[i] = -pos_FR_foot_sdfast[i] + pos_FR_shoulder_sdfast[i];
      vel_sdfast_foot2shoulder[i] = -vel_FR_foot_sdfast[i] + vel_FR_shoulder_sdfast[i];
      if (i==1)
       pos_sdfast_foot2shoulder[i] += -width_calibration;
    }
   }

//************************************************************************

if (leg_no == 1)
  {
  double FL_shoulder_local[3] = {0.1703,   0.0448,   -0.0005};
  double pos_FL_shoulder_sdfast[3]={0};
  double vel_FL_shoulder_sdfast[3]={0};
  sdpos(trunk,FL_shoulder_local,pos_FL_shoulder_sdfast);  sdprinterr(stderr);
  sdvel(trunk,FL_shoulder_local,vel_FL_shoulder_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_FL_shoulder_sdfast,0,pos_FL_shoulder_sdfast); sdprinterr(stderr);
  sdtrans(-1,vel_FL_shoulder_sdfast,0,vel_FL_shoulder_sdfast); sdprinterr(stderr);

  // double FL_elbow_local[3] = {-0.0047 ,        0 ,   0.1320};
  // double pos_FL_elbow_sdfast[3]={0};
  // double vel_FL_elbow_sdfast[3]={0};
  // sdpos(FL_calf,FL_elbow_local,pos_FL_elbow_sdfast);  sdprinterr(stderr);
  // sdtrans(-1,pos_FL_elbow_sdfast,0,pos_FL_elbow_sdfast); sdprinterr(stderr);

  double FL_foot_local[3] = {-0.0047 ,        0 ,  -0.0680};
  double pos_FL_foot_sdfast[3]={0};
  double vel_FL_foot_sdfast[3]={0};
  sdpos(FL_calf,FL_foot_local,pos_FL_foot_sdfast);  sdprinterr(stderr);
  sdvel(FL_calf,FL_foot_local,vel_FL_foot_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_FL_foot_sdfast,0,pos_FL_foot_sdfast); sdprinterr(stderr);
  sdtrans(-1,vel_FL_foot_sdfast,0,vel_FL_foot_sdfast); sdprinterr(stderr);

  for (i=0;i<3;i++)
  {
    pos_sdfast_foot2shoulder[i] = -pos_FL_foot_sdfast[i] + pos_FL_shoulder_sdfast[i];
    vel_sdfast_foot2shoulder[i] = -vel_FL_foot_sdfast[i] + vel_FL_shoulder_sdfast[i];
    if (i==1)
     pos_sdfast_foot2shoulder[i] += width_calibration;
  }
}
//************************************************************************

if (leg_no == 2)
{
  double RR_shoulder_local[3] = {-0.1957,   -0.0492,   -0.0005};
  double pos_RR_shoulder_sdfast[3]={0};
  double vel_RR_shoulder_sdfast[3]={0};
  sdpos(trunk,RR_shoulder_local,pos_RR_shoulder_sdfast);  sdprinterr(stderr);
  sdvel(trunk,RR_shoulder_local,vel_RR_shoulder_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_RR_shoulder_sdfast,0,pos_RR_shoulder_sdfast); sdprinterr(stderr);
  sdtrans(-1,vel_RR_shoulder_sdfast,0,vel_RR_shoulder_sdfast); sdprinterr(stderr);

  // double RR_elbow_local[3] = {-0.0047 ,        0 ,   0.1320};
  // double pos_RR_elbow_sdfast[3]={0};
  // double vel_RR_elbow_sdfast[3]={0};
  // sdpos(RR_calf,RR_elbow_local,pos_RR_elbow_sdfast);  sdprinterr(stderr);
  // sdtrans(-1,pos_RR_elbow_sdfast,0,pos_RR_elbow_sdfast); sdprinterr(stderr);

  double RR_foot_local[3] = {-0.0047 ,        0 ,  -0.0680};
  double pos_RR_foot_sdfast[3]={0};
  double vel_RR_foot_sdfast[3]={0};
  sdpos(RR_calf,RR_foot_local,pos_RR_foot_sdfast);  sdprinterr(stderr);
  sdvel(RR_calf,RR_foot_local,vel_RR_foot_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_RR_foot_sdfast,0,pos_RR_foot_sdfast); sdprinterr(stderr);
  sdtrans(-1,vel_RR_foot_sdfast,0,vel_RR_foot_sdfast); sdprinterr(stderr);
  for (i=0;i<3;i++)
  {
    pos_sdfast_foot2shoulder[i] = -pos_RR_foot_sdfast[i] + pos_RR_shoulder_sdfast[i];
    vel_sdfast_foot2shoulder[i] = -vel_RR_foot_sdfast[i] + vel_RR_shoulder_sdfast[i];
    if (i==1)
     pos_sdfast_foot2shoulder[i] += -width_calibration;
  }

}
//************************************************************************

if (leg_no == 3)
{
  double RL_shoulder_local[3] = {  -0.1957 ,   0.0448 ,  -0.0005};
  double pos_RL_shoulder_sdfast[3]={0};
  double vel_RL_shoulder_sdfast[3]={0};
  sdpos(trunk,RL_shoulder_local,pos_RL_shoulder_sdfast);  sdprinterr(stderr);
  sdvel(trunk,RL_shoulder_local,vel_RL_shoulder_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_RL_shoulder_sdfast,0,pos_RL_shoulder_sdfast); sdprinterr(stderr);
  sdtrans(-1,vel_RL_shoulder_sdfast,0,vel_RL_shoulder_sdfast); sdprinterr(stderr);

  // double RL_elbow_local[3] = {-0.0047 ,        0 ,   0.1320};
  // double pos_RL_elbow_sdfast[3]={0};
  // double vel_RL_elbow_sdfast[3]={0};
  // sdpos(RL_calf,RL_elbow_local,pos_RL_elbow_sdfast);  sdprinterr(stderr);
  // sdtrans(-1,pos_RL_elbow_sdfast,0,pos_RL_elbow_sdfast); sdprinterr(stderr);

  double RL_foot_local[3] = {-0.0047 ,        0 ,  -0.0680};
  double pos_RL_foot_sdfast[3]={0};
  double vel_RL_foot_sdfast[3]={0};
  sdpos(RL_calf,RL_foot_local,pos_RL_foot_sdfast);  sdprinterr(stderr);
  sdvel(RL_calf,RL_foot_local,vel_RL_foot_sdfast);  sdprinterr(stderr);
  sdtrans(-1,pos_RL_foot_sdfast,0,pos_RL_foot_sdfast); sdprinterr(stderr);
  sdtrans(-1,vel_RL_foot_sdfast,0,vel_RL_foot_sdfast); sdprinterr(stderr);

  for (i=0;i<3;i++)
  {
    pos_sdfast_foot2shoulder[i] = -pos_RL_foot_sdfast[i] + pos_RL_shoulder_sdfast[i];
    vel_sdfast_foot2shoulder[i] = -vel_RL_foot_sdfast[i] + vel_RL_shoulder_sdfast[i];
    if (i==1)
     pos_sdfast_foot2shoulder[i] += width_calibration;
  }
}

}
