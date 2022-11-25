void generate_poly_trajectory(double t, double c_traj[nact_leg][N_traj],double X[nact_leg],double Xdot[nact_leg], double Xddot[nact_leg])
{
  int i;
  double c0, c1, c2, c3, c4, c5;
  for (i=0;i<nact_leg;i++)
  {
    c0 = c_traj[i][0];
    c1 = c_traj[i][1];
    c2 = c_traj[i][2];
    c3 = c_traj[i][3];
    c4 = c_traj[i][4];
    c5 = c_traj[i][5];
    X[i] = c0+c1*t+c2*(t*t)+c3*(t*t*t)+c4*(t*t*t*t)+c5*(t*t*t*t*t);
    Xdot[i] = c1+c2*t*2.0+c3*(t*t)*3.0+c4*(t*t*t)*4.0+c5*(t*t*t*t)*5.0;
    Xddot[i] = c2*2.0+c3*t*6.0+c4*(t*t)*1.2E+1+c5*(t*t*t)*2.0E+1;
  }
}

void init_poly_trajectory(double t0,double tf,double S0[],double Sf[],double V0[],double Vf[],double A0[],double Af[], double coefs[nact][N_traj])
{
  int i,j,k;
  double s0, sf, v0, vf, a0, af;
  double A[N_traj][N_traj]={0},b[N_traj]={0},y[N_traj]={0}; //important to initialize these

  gsl_matrix * gsl_A = gsl_matrix_alloc(N_traj,N_traj);
  gsl_matrix * gsl_invA = gsl_matrix_alloc(N_traj,N_traj);
  gsl_vector * gsl_b = gsl_vector_alloc(N_traj);
  gsl_vector * gsl_y = gsl_vector_alloc(N_traj);

  //A and b copy pasted from derive_trajectory
  for (k=0;k<nact_leg;k++)
  {
  s0 = S0[k];
  sf = Sf[k];
  v0 = V0[k];
  vf = Vf[k];
  a0 = A0[k];
  af = Af[k];

  A[0][0] = 1.0;
  A[0][1] = t0;
  A[0][2] = t0*t0;
  A[0][3] = t0*t0*t0;
  A[0][4] = t0*t0*t0*t0;
  A[0][5] = t0*t0*t0*t0*t0;
  A[1][0] = 1.0;
  A[1][1] = tf;
  A[1][2] = tf*tf;
  A[1][3] = tf*tf*tf;
  A[1][4] = tf*tf*tf*tf;
  A[1][5] = tf*tf*tf*tf*tf;
  A[2][1] = 1.0;
  A[2][2] = t0*2.0;
  A[2][3] = (t0*t0)*3.0;
  A[2][4] = (t0*t0*t0)*4.0;
  A[2][5] = (t0*t0*t0*t0)*5.0;
  A[3][1] = 1.0;
  A[3][2] = tf*2.0;
  A[3][3] = (tf*tf)*3.0;
  A[3][4] = (tf*tf*tf)*4.0;
  A[3][5] = (tf*tf*tf*tf)*5.0;
  A[4][2] = 2.0;
  A[4][3] = t0*6.0;
  A[4][4] = (t0*t0)*1.2E+1;
  A[4][5] = (t0*t0*t0)*2.0E+1;
  A[5][2] = 2.0;
  A[5][3] = tf*6.0;
  A[5][4] = (tf*tf)*1.2E+1;
  A[5][5] = (tf*tf*tf)*2.0E+1;


  b[0] = s0;
  b[1] = sf;
  b[2] = v0;
  b[3] = vf;
  b[4] = a0;
  b[5] = af;


  for (i = 0; i < N_traj; i++)
    for (j = 0; j < N_traj; j++)
    {
      gsl_matrix_set (gsl_A, i, j, A[i][j]);
    }

    for (i = 0; i < N_traj; i++)
        gsl_vector_set (gsl_b, i, b[i]);


    gsl_permutation *p = gsl_permutation_alloc(N_traj);
    int s;
      // Compute the LU decomposition of this matrix
      gsl_linalg_LU_decomp(gsl_A, p, &s);
      // Compute the  inverse of the LU decomposition
      gsl_linalg_LU_invert(gsl_A, p, gsl_invA);

  //multiply matrix to gsl_vector
  //y = alpha*A*x + beta y (level 2 in https://www.gnu.org/software/gsl/doc/html/blas.html)
  //gsl_blas_dgemv(CBLAS_TRANSPOSE_t TransA, double alpha, constgsl_matrix *A, constgsl_vector *x, double beta, gsl_vector *y)
  //Here alpha = 1, beta = 0, A = A, b = x,
  gsl_blas_dgemv(CblasNoTrans,1.0,gsl_invA,gsl_b,0.0,gsl_y);

  for (i = 0; i < N_traj; i++)
      y[i] = gsl_vector_get (gsl_y, i);


  for (i=0;i<N_traj;i++)
    {
    coefs[k][i] = y[i];
    //printf("%f ",y[i]);
    }
    //printf("\n");
  }
}
