void get_trq_swing(int leg_no,double qr_ref[3],double tau_r[3])
{
int i;
double quat0[4]={0}; quat0[0]=1; double omega0[3]={0};
double u0[nact] = {0}; double q_ref[nact]={0};
double tau_static[NU]={0};
for (i=0;i<3;i++)
  q_ref[index_leg_act[leg_no][i]]= qr_ref[i];
set_model_state(quat0,omega0,q_ref,u0);
sdequivht(tau_static); sdprinterr(stderr);
for (i=0;i<3;i++)
  tau_r[i] = -tau_static[6+index_leg_act[leg_no][i]];
 }
