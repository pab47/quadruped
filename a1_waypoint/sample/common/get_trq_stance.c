void get_trq_stance(int leg_no,double quat[4],double omega[3], double qr_ref[3],double tau_r[3],double F[3])
{
  int i;

  // double F[3]={0};
  // F[0] = 0.01*mass*g;
  // F[1] = 0*mass*g;
  // F[2] = 0.5*mass*g;
  
  //printf("%d %f %f %f \n",leg_no,F[0],F[1],F[2]);
  
  //F[0] = 0.05*mass*g; //0.05
  //F[1] = 0*mass*g;
  //F[2] = 0.5*mass*g;


  double dc[3][3];
  double eulerX, eulerY, eulerZ;
  double omegaX, omegaY, omegaZ;
  double quat_sdfast[4] = {quat[1],quat[2],quat[3],quat[0]};
  sdquat2dc(quat_sdfast[0],quat_sdfast[1],quat_sdfast[2],quat_sdfast[3],dc); sdprinterr(stderr);
  sddc2ang(dc,&eulerX,&eulerY,&eulerZ); sdprinterr(stderr);
  omegaX = omega[0]; omegaY = omega[1]; omegaZ = omega[2];


  double J[3][3]={0};
  double JT[3][3]={0};
  get_Jac(leg_no, qr_ref,J);
  ram_transpose(&J[0][0], 3, 3,  &JT[0][0]);
  ram_multMatVec(&JT[0][0],3,3,&F[0],3,&tau_r[0]);
  for (i=0;i<3;i++)
  {
    tau_r[i] = -tau_r[i];
  }
  // tau_r[1] = tau_r[1] - 100*eulerY - 20*omegaY;
  // if (leg_no == 0 || leg_no == 2)
  // {
  //   tau_r[0] = tau_r[0] - 100*eulerX - 20*omegaX;
  // }
  // else
  // {
  //   tau_r[0] = tau_r[0] + 100*eulerX + 20*omegaX;
  // }
}
