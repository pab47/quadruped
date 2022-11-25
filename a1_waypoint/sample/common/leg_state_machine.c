double C1_swing[4][3][N_traj] = {0};
double C2_swing[4][3][N_traj] = {0};

double C1_stance[4][3][N_traj] = {0};
double C2_stance[4][3][N_traj] = {0};

double C_init2stand[4][3][N_traj] = {0};

double Kp = 50;
double Kd = 10;

double t_fsm[4] = {0};

double prev_w0;
double prev_l0;
double prev_h0;
double prev_yaw_w0;


int leg_state_machine(int leg_no,int fsm_,int motiontime,
                      double quat_act[4],double omega_act[3],
                      double qr_act[3],double ur_act[3],
                     double qr_ref[3],double ur_ref[3],
                     double tau_r[3], double kp_r[3], double kd_r[3],
                     uint16_t footForce, double force[3])

{
int i,j;
int ii,jj;
double coefs[3][N_traj] = {0};
double ttime;

ttime = motiontime*dtime;


//all transitions
if (fsm_ == fsm_init && ttime >= t_fsm[leg_no] + t_init[leg_no])
{
  fsm_ = fsm_init2stand;
  t_fsm[leg_no] = ttime;

  double t0, tf;
  double s0[3]={0},sf[3]={0};
  double v0[3]={0},vf[3]={0};
  double a0[3]={0},af[3]={0};
  t0 = 0;
  tf = 0 + t_init2stand[leg_no];
  double pos_sdfast_foot2shoulder[3]={0}; double vel_sdfast_foot2shoulder[3]={0};
  get_kinematics2(leg_no,qr_act,pos_sdfast_foot2shoulder,vel_sdfast_foot2shoulder);
  s0[0] = pos_sdfast_foot2shoulder[0];
  s0[1] = pos_sdfast_foot2shoulder[1];
  s0[2] = pos_sdfast_foot2shoulder[2];

  double init_length0 = init_l0;
  double init_height0 = init_h0;
  double init_width0 = init_w0;

  sf[0] = init_length0;
  sf[1] = init_width0;
  sf[2] = init_height0;

  init_poly_trajectory(t0,tf,s0,sf,v0,vf,a0,af,coefs);
  for (i=0;i<3;i++)
      for (j=0;j<N_traj;j++)
          C_init2stand[leg_no][i][j]=coefs[i][j];

}

if (fsm_ == fsm_init2stand && ttime >= t_fsm[leg_no] + t_init2stand[leg_no] )
{
  fsm_ = fsm_stand;
  t_fsm[leg_no] = ttime;
}

if (fsm_ == fsm_stand && ttime >= t_fsm[leg_no] + t_stand[leg_no] )
{
  fsm_ = fsm_stance;
  t_fsm[leg_no] = ttime;

  double t0, tm, tf;
  double s0[3]={0},sf[3]={0},sm[3]={0};
  double v0[3]={0},vf[3]={0},vm[3]={0};
  double a0[3]={0},af[3]={0},am[3]={0};
  t0 = 0;
  tm = 0 + 0.5*t_move[leg_no];
  tf = 0 + t_move[leg_no];

  double init_length0 = init_l0;
  double init_height0 = init_h0;
  double init_width0 = init_w0;

  double mid_stance_length = 0;
  double mid_stance_height = h0;
  double mid_stance_width = 0;

  vx = set_limit(vx,vx_max);
  vy = set_limit(vy,vy_max);

  l0 = 0.5*vx*t_stance;
  w0 = 0.5*vy*t_stance;

  double final_stance_length = l0; //l0*lmax;
  double final_stance_height = h0;
  double final_stance_width = w0; //w0*wmax;

  s0[0] = init_length0;
  s0[1] = init_width0;
  s0[2] = init_height0;

  sm[0] = mid_stance_length;
  sm[1] = mid_stance_width;
  sm[2] = mid_stance_height;

  sf[0] = final_stance_length;
  sf[1] = final_stance_width;
  sf[2] = final_stance_height;

  init_poly_trajectory(t0,tm,s0,sm,v0,vf,a0,af,coefs);
  for (i=0;i<3;i++)
      for (j=0;j<N_traj;j++)
          C1_stance[leg_no][i][j]=coefs[i][j];

  init_poly_trajectory(tm,tf,sm,sf,v0,vf,a0,af,coefs);
  for (i=0;i<3;i++)
    for (j=0;j<N_traj;j++)
          C2_stance[leg_no][i][j]=coefs[i][j];

  prev_l0 = l0;
  prev_h0 = h0;
  prev_w0 = w0;
  prev_yaw_w0 = yaw_w0;

}

if (fsm_ == fsm_stance && ttime >= t_fsm[leg_no] + t_move[leg_no])
{

  fsm_ = fsm_swing;
  t_fsm[leg_no] = ttime;

  if (leg_no == 0 || leg_no == 1)
  {
    step_no +=1;
    //printf("%f %f %f %f %f \n",ttime,quat_act[0],quat_act[1],quat_act[2],quat_act[3]);
  }


  vx = set_limit(vx,vx_max);
  vy = set_limit(vy,vy_max);
  omega = set_limit(omega,omega_max);

  l0 = 0.5*vx*t_stance;
  w0 = 0.5*vy*t_stance;
  yaw_w0 =  -omega*t_stance*body_length;

  double t0, tm, tf;
  double s0[3]={0},sf[3]={0},sm[3]={0};
  double v0[3]={0},vf[3]={0},vm[3]={0};
  double a0[3]={0},af[3]={0},am[3]={0};
  t0 = 0;
  tm = 0 + 0.5*t_move[leg_no];
  tf = 0 + t_move[leg_no];

  double init_swing_length = prev_l0; //*lmax;
  double init_swing_height = prev_h0;
  double init_swing_width = prev_w0;//*wmax;

  double mid_swing_length = 0;
  double mid_swing_height = prev_h0-hcl;
  double mid_swing_width = 0;

  double final_swing_length = -l0; //*lmax;
  double final_swing_height = h0;
  double final_swing_width = -w0; //*wmax;

  s0[0] = init_swing_length;
  s0[1] = init_swing_width;
  s0[2] = init_swing_height;

  sm[0] = mid_swing_length;
  sm[1] = mid_swing_width;
  sm[2] = mid_swing_height;

  sf[0] = final_swing_length;
  sf[1] = final_swing_width;
  sf[2] = final_swing_height;

  // if (omega < -0.01 || omega > 0.01)
  //{
    if (leg_no == 0 || leg_no == 1)
    {
    // s0[1] = init_w0;
    // sf[1] = init_w0;
    }
    else
    {
      //omega = set_limit(omega,omega_max);
      //yaw_w0 =  -omega*t_stance*body_length;
      init_swing_width +=  prev_yaw_w0;
      final_swing_width += -yaw_w0;
      s0[1] = init_swing_width;
      sf[1] = final_swing_width;
    }
  //}

  prev_l0 = l0;
  prev_h0 = h0;
  prev_w0 = w0;
  prev_yaw_w0 = yaw_w0;

  init_poly_trajectory(t0,tm,s0,sm,v0,vf,a0,af,coefs);
  for (i=0;i<3;i++)
      for (j=0;j<N_traj;j++)
          C1_swing[leg_no][i][j]=coefs[i][j];

  init_poly_trajectory(tm,tf,sm,sf,v0,vf,a0,af,coefs);
  for (i=0;i<3;i++)
    for (j=0;j<N_traj;j++)
          C2_swing[leg_no][i][j]=coefs[i][j];


}
if (fsm_ == fsm_swing && ttime >= t_fsm[leg_no] + t_move[leg_no])
{
  fsm_ = fsm_stance;
  t_fsm[leg_no] = ttime;

  vx = set_limit(vx,vx_max);
  vy = set_limit(vy,vy_max);
  omega = set_limit(omega,omega_max);

  l0 = 0.5*vx*t_stance;
  w0 = 0.5*vy*t_stance;
  yaw_w0 = -omega*t_stance*body_length;

  double t0, tm, tf;
  double s0[3]={0},sf[3]={0},sm[3]={0};
  double v0[3]={0},vf[3]={0},vm[3]={0};
  double a0[3]={0},af[3]={0},am[3]={0};
  t0 = 0;
  tm = 0 + 0.5*t_move[leg_no];
  tf = 0 + t_move[leg_no];


  double init_stance_length = -prev_l0;//*lmax;
  double init_stance_height = prev_h0;
  double init_stance_width = -prev_w0;//*wmax;

  double mid_stance_length = 0;
  double mid_stance_height = prev_h0;
  double mid_stance_width = 0;

  double final_stance_length = l0;//*lmax;
  double final_stance_height = h0;
  double final_stance_width = w0; //*wmax;
  //printf("%f %f \n",init_stance_width,final_stance_width);

  double vx_mid = (final_stance_length - init_stance_length)/t_stance;
  double vy_mid = (final_stance_width - init_stance_width)/t_stance;
  vm[0] = vx_mid;
  vm[1] = vy_mid;


  s0[0] = init_stance_length;
  s0[1] = init_stance_width;
  s0[2] = init_stance_height;

  sm[0] = mid_stance_length;
  sm[1] = mid_stance_width;
  sm[2] = mid_stance_height;

  sf[0] = final_stance_length;
  sf[1] = final_stance_width;
  sf[2] = final_stance_height;

  // if (omega < -0.01 || omega > 0.01)
  // {
    if (leg_no == 0 || leg_no == 1)
    {
      // s0[1] = init_w0;
      // sf[1] = init_w0;
    }
    else
    {
      // omega = set_limit(omega,omega_max);
      // yaw_w0 = -omega*t_stance*body_length;
      init_stance_width += -prev_yaw_w0;
      final_stance_width += yaw_w0;
      s0[1] = init_stance_width;
      sf[1] = final_stance_width;
    }
  // }

  prev_l0 = l0;
  prev_h0 = h0;
  prev_w0 = w0;
  prev_yaw_w0 = yaw_w0;


  init_poly_trajectory(t0,tm,s0,sm,v0,vf,a0,af,coefs);
  for (i=0;i<3;i++)
      for (j=0;j<N_traj;j++)
          C1_stance[leg_no][i][j]=coefs[i][j];

  init_poly_trajectory(tm,tf,sm,sf,v0,vf,a0,af,coefs);
  for (i=0;i<3;i++)
    for (j=0;j<N_traj;j++)
          C2_stance[leg_no][i][j]=coefs[i][j];

}


//all actions
if (fsm_ == fsm_init)
{
  //set torques
    for (i=0;i<3;i++)
    {
      tau_r[i] = 0;
      kp_r[i] = 0;
      kd_r[i] = 0;
    }
}

if (fsm_ == fsm_init2stand)
{
  //set joint angles
  double tt=ttime-t_fsm[leg_no];
  double X[3]={0},Xdot[3]={0},Xddot[3]={0};
  if (ttime > t_fsm[leg_no] && ttime <= t_fsm[leg_no]+t_init2stand[leg_no])
  {
    for (ii=0;ii<3;ii++)
        for (jj=0;jj<N_traj;jj++)
          coefs[ii][jj] = C_init2stand[leg_no][ii][jj];
    generate_poly_trajectory(tt,coefs,X,Xdot,Xddot);
  }
  else
  {
    tt = t_init2stand[leg_no];
    for (ii=0;ii<3;ii++)
        for (jj=0;jj<N_traj;jj++)
          coefs[ii][jj] = C_init2stand[leg_no][ii][jj];
    generate_poly_trajectory(tt,coefs,X,Xdot,Xddot);
  }
  inverse_kinematics_3D_analytic(X,Xdot,qr_ref,ur_ref,leg_no);

  //set torques
  get_trq_swing(leg_no,qr_ref,tau_r);
  for (i=0;i<3;i++)
    {kp_r[i]= Kp; kd_r[i]= Kd;}

}

if (fsm_ == fsm_stand)
{
    //set angles
    double X[3]={0},Xdot[3]={0},Xddot[3]={0};
    double tt = t_init2stand[leg_no];
    for (ii=0;ii<3;ii++)
        for (jj=0;jj<N_traj;jj++)
          coefs[ii][jj] = C_init2stand[leg_no][ii][jj];
    generate_poly_trajectory(tt,coefs,X,Xdot,Xddot);
    inverse_kinematics_3D_analytic(X,Xdot,qr_ref,ur_ref,leg_no);

      //set torque
     get_trq_swing(leg_no,qr_ref,tau_r);
     for (i=0;i<3;i++)
     { kp_r[i]=Kp; kd_r[i]=Kd;}

}
if (fsm_ == fsm_stance)
{
    //set angles
  double tt=ttime-t_fsm[leg_no];
  double X[3]={0},Xdot[3]={0},Xddot[3]={0};
  if (ttime > t_fsm[leg_no] && ttime <= t_fsm[leg_no]+0.5*t_move[leg_no])
  {
    for (ii=0;ii<3;ii++)
        for (jj=0;jj<N_traj;jj++)
          coefs[ii][jj] = C1_stance[leg_no][ii][jj];
    generate_poly_trajectory(tt,coefs,X,Xdot,Xddot);
  }
  else if (ttime > t_fsm[leg_no]+0.5*t_move[leg_no] && ttime <= t_fsm[leg_no]+t_move[leg_no])
  {
    for (ii=0;ii<3;ii++)
        for (jj=0;jj<N_traj;jj++)
          coefs[ii][jj] = C2_stance[leg_no][ii][jj];
    generate_poly_trajectory(tt,coefs,X,Xdot,Xddot);
  }
  else
  {
    tt = t_move[leg_no];
    for (ii=0;ii<3;ii++)
        for (jj=0;jj<N_traj;jj++)
          coefs[ii][jj] = C2_stance[leg_no][ii][jj];
    generate_poly_trajectory(tt,coefs,X,Xdot,Xddot);
  }
  inverse_kinematics_3D_analytic(X,Xdot,qr_ref,ur_ref,leg_no);

  //set torque
  //get_trq_stance(leg_no,qr_ref,tau_r);
  get_trq_stance(leg_no,quat_act,omega_act,qr_ref,tau_r,force);
  for (i=0;i<3;i++)
     { kp_r[i]=Kp; kd_r[i]=Kd;}

}
if (fsm_ == fsm_swing)
{
  //use coefs to generate Xref and Xdotref
  //use polynomials to get qref, qdot_ref
  double tt=ttime-t_fsm[leg_no];
  double X[3]={0},Xdot[3]={0},Xddot[3]={0};
  if (ttime > t_fsm[leg_no] && ttime <= t_fsm[leg_no]+0.5*t_move[leg_no])
  {
    for (ii=0;ii<3;ii++)
        for (jj=0;jj<N_traj;jj++)
          coefs[ii][jj] = C1_swing[leg_no][ii][jj];
    generate_poly_trajectory(tt,coefs,X,Xdot,Xddot);
  }
  else if (ttime > t_fsm[leg_no]+0.5*t_move[leg_no] && ttime <= t_fsm[leg_no]+t_move[leg_no])
  {
    for (ii=0;ii<3;ii++)
        for (jj=0;jj<N_traj;jj++)
          coefs[ii][jj] = C2_swing[leg_no][ii][jj];
    generate_poly_trajectory(tt,coefs,X,Xdot,Xddot);
  }
  else
  {
    tt = t_move[leg_no];
    for (ii=0;ii<3;ii++)
        for (jj=0;jj<N_traj;jj++)
          coefs[ii][jj] = C2_swing[leg_no][ii][jj];
    generate_poly_trajectory(tt,coefs,X,Xdot,Xddot);
  }
  inverse_kinematics_3D_analytic(X,Xdot,qr_ref,ur_ref,leg_no);

  //set torque
  if (ttime > t_fsm[leg_no] + 0.005)
  {
    get_trq_swing(leg_no,qr_ref,tau_r);
  }
  else
  {
    //get_trq_stance(leg_no,qr_ref,tau_r);
    get_trq_stance(leg_no,quat_act,omega_act,qr_ref,tau_r,force);
  }


  for (i=0;i<3;i++)
     { kp_r[i]=Kp; kd_r[i]=Kd;}

  }
  return fsm_;
}
