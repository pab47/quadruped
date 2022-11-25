void inverse_kinematics_3D_analytic(double X[3],double Xdot[3],
                                    double q[3], double qdot[3],  int leg_no)
{
  int i,j,k;

  double l = leg_length;

  double l_x = X[0];
  double l_y = X[1];
  double l_z = X[2];

  double r = sqrt(l_x*l_x+l_y*l_y+l_z*l_z);

  double sign = -1;
  if (leg_no == leg_FL || leg_no == leg_RL)
    sign = 1;
  double q0 = sign*asin(l_y/r);

  //angles in a triangle
  double q2_star = acos( (2*l*l-r*r)/ (2*l*l) ); //cosine rule
  double q1_star = 0.5*(pi-q2_star); //sum of all angles in a triangle is pi

  double q1 = asin(l_x/r)+q1_star;
  double q2 = -pi+q2_star;

  q[0] = q0;
  q[1] = q1;
  q[2] = q2;


  double J[3][3]={0};
  get_Jac(leg_no,q,J);
  double Jinv[3][3]={0};
  ram_inverse(&J[0][0],3,3,&Jinv[0][0]);
  ram_multMatVec(&Jinv[0][0],3,3,&Xdot[0],3,&qdot[0]);

  //fudging the sign
  for (i=0;i<3;i++)
    qdot[i]=-qdot[i];


}
