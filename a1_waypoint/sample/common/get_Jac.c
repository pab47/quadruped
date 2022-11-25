void get_Jac(int leg_no, double q[3],double J[3][3])

{

  int i,ii;
  double quat[4]={0}; quat[0]=1;
  double omega[3] = {0}; double u[nact]={0}; double qref[nact]={0};
  for (i=0;i<3;i++)
    qref[index_leg_act[leg_no][i]] = q[i];
  set_model_state(quat,omega,qref,u);

  double lin[3]={0},rot[3]={0};
  double foot_local[3] = {-0.0047 ,        0 ,  -0.0680};
  int index_body[4]={FR_calf,FL_calf,RR_calf,RL_calf};
  int index_coord_hip[4] = {q_FR_hip,q_FL_hip,q_RR_hip,q_RL_hip};
  int index_coord_thigh[4] = {q_FR_thigh,q_FL_thigh,q_RR_thigh,q_RL_thigh};
  int index_coord_calf[4] =  {q_FR_calf,q_FL_calf,q_RR_calf,q_RL_calf};
  int index_frame[4] = {trunk,trunk,trunk,trunk};

// sdrel2cart(coord,body,pt,lin,rot)
// int coord,body;
// double pt[3],lin[3],rot[3];
//sdtrans(frombody, vec, tobody, ovec);

  ii = leg_no;
  sdrel2cart(index_coord_hip[ii],index_body[ii],foot_local,lin,rot); sdprinterr(stderr);
  sdtrans(index_body[ii],lin,index_frame[ii],lin); sdprinterr(stderr);
  J[0][0]=lin[0];
  J[1][0]=lin[1];
  J[2][0]=lin[2];
  sdrel2cart(index_coord_thigh[ii],index_body[ii],foot_local,lin,rot); sdprinterr(stderr);
  sdtrans(index_body[ii],lin,index_frame[ii],lin); sdprinterr(stderr);
  J[0][1]=lin[0];
  J[1][1]=lin[1];
  J[2][1]=lin[2];
  sdrel2cart(index_coord_calf[ii],index_body[ii],foot_local,lin,rot); sdprinterr(stderr);
  sdtrans(index_body[ii],lin,index_frame[ii],lin); sdprinterr(stderr);
  J[0][2]=lin[0];
  J[1][2]=lin[1];
  J[2][2]=lin[2];
}
