double l0, w0, yaw_w0;

double vx = 0.05;
double vy = 0;
double omega = 0;

double vx_max = 1;
double vy_max = 0.3;
double omega_max = 1; //(2*w_max/body_length)*(1/t_stance)

double h0 = 0.3; //should be same as init_h0
double hmax = 0.3;
double hcl = 0.1;

//init parameters
#define init_h0 0.3 //should be same as h0
#define init_w0 0
#define init_l0 0

#define t_free 1
#define t_trans 2
#define t_stance .2
double t_init[4] = {t_free,t_free,t_free,t_free}; //laying down
double t_init2stand[4] = {t_trans,t_trans,t_trans,t_trans}; //transition from laying down to standing up
double t_stand[4] = {0,0+t_stance,0+t_stance,0}; //stand up for so much time
double t_move[4] = {t_stance,t_stance,t_stance,t_stance}; //move now


#define fsm_init 0
#define fsm_init2stand 1
#define fsm_stand 2
#define fsm_swing 3
#define fsm_stance 4
