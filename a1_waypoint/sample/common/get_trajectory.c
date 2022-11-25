void get_trajectory(double ttime,double ts,double tend,
                    double *xref,double *yref,
                    double *xdotref,double *ydotref,
                    double *thetaref,double *thetadotref,
                    double a,double x_center,double y_center)
{
  double tau = 2*pi*(ttime-ts)/tend;
  double  den = 1+sin(tau)*sin(tau);
  double den2 = den*den;
  double b = 2*pi/tend;
  *xref = x_center + a*cos(tau)/den;
  *yref = y_center + a*cos(tau)*sin(tau)/den;
  *xdotref = (a*b*sin(tau)*(sin(tau)*sin(tau) - 3))/den2;
  *ydotref = -(a*b*(3*sin(tau)*sin(tau) - 1))/den2;

  double xdot = *xdotref;
  double ydot = *ydotref;
  double epsilon = 1e-6;
  double xddot = a*(b*b)*cos(tau)*1.0/pow(pow(cos(tau),2.0)-2.0,3.0)*(pow(cos(tau),2.0)*1.0E+1+pow(cos(tau),4.0)-8.0);
  double yddot = a*(b*b)*cos(tau)*sin(tau)*1.0/pow(pow(sin(tau),2.0)+1.0,3.0)*(pow(cos(tau),2.0)*3.0+2.0)*-2.0;

  double theta = atan2(ydot,xdot);
  double sec_theta = 1/cos(theta);
  double num3 = xdot*yddot - ydot*xddot;
  double den3 = (xdot*xdot+epsilon);
  double thetadot;

  //constant reference
    if (flag_constant)
      thetadot = 0;
    else
      thetadot = (1/(sec_theta*sec_theta))*(num3/den3);

    //changing reference
   *thetadotref = thetadot;
   theta_ref0 += t_stance*thetadot;
   *thetaref = theta_ref0;
  
}
