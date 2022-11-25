/*
Generated 06-Jan-2022 13:13:21 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/
#include <math.h>

/* These routines are passed to sdroot. */

void sdposfunc(double vars[18],
    double param[1],
    double resid[1])
{
    int i;
    double pos[19],vel[18];

    for (i = 0; i < 18; i++) {
        vel[i] = 0.;
    }
    sdang2st(vars,pos);
    sdstate(param[0],pos,vel);
    sdperr(resid);
}

void sdvelfunc(double vars[18],
    double param[20],
    double resid[1])
{

    sdstate(param[19],param,vars);
    sdverr(resid);
}

void sdstatfunc(double vars[18],
    double param[19],
    double resid[18])
{
    double pos[19],qdotdum[19];

    sdang2st(vars,pos);
    sdstate(param[18],pos,param);
    sduforce(param[18],pos,param);
    sdperr(resid);
    sdderiv(qdotdum,&resid[0]);
}

void sdstdyfunc(double vars[36],
    double param[1],
    double resid[18])
{
    double pos[19],qdotdum[19];

    sdang2st(vars,pos);
    sdstate(param[0],pos,&vars[18]);
    sduforce(param[0],pos,&vars[18]);
    sdperr(resid);
    sdverr(&resid[0]);
    sdderiv(qdotdum,&resid[0]);
}

/* This routine is passed to the integrator. */

void sdmotfunc(double time,
    double state[37],
    double dstate[37],
    double param[1],
    int *status)
{

    sdstate(time,state,&state[19]);
    sduforce(time,state,&state[19]);
    sdderiv(dstate,&dstate[19]);
    *status = 0;
}

/* This routine performs assembly analysis. */

void sdassemble(double time,
    double state[37],
    int lock[18],
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double perrs[1],param[1];
    int i;

    sdgentime(&i);
    if (i != 131321) {
        sdseterr(50,42);
    }
    param[0] = time;
    sdst2ang(state,state);
    *err = 0;
    *fcnt = 0;
    sdposfunc(state,param,perrs);
    *fcnt = *fcnt+1;
    sdang2st(state,state);
}

/* This routine performs initial velocity analysis. */

void sdinitvel(double time,
    double state[37],
    int lock[18],
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double verrs[1],param[20];
    int i;

    sdgentime(&i);
    if (i != 131321) {
        sdseterr(51,42);
    }
    for (i = 0; i < 19; i++) {
        param[i] = state[i];
    }
    param[19] = time;
    *err = 0;
    *fcnt = 0;
    sdvelfunc(&state[19],param,verrs);
    *fcnt = *fcnt+1;
}

/* This routine performs static analysis. */

void sdstatic(double time,
    double state[37],
    int lock[18],
    double ctol,
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double resid[18],param[19],jw[324],dw[2592],rw[288];
    int iw[144],rooterr,i;

    sdgentime(&i);
    if (i != 131321) {
        sdseterr(52,42);
    }
    for (i = 0; i < 18; i++) {
        param[i] = state[19+i];
    }
    param[18] = time;
    sdst2ang(state,state);
    sdroot(sdstatfunc,state,param,18,18,18,lock,
      ctol,tol,maxevals,jw,dw,rw,iw,resid,fcnt,&rooterr);
    sdstatfunc(state,param,resid);
    *fcnt = *fcnt+1;
    sdang2st(state,state);
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs steady motion analysis. */

void sdsteady(double time,
    double state[37],
    int lock[36],
    double ctol,
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double resid[18],param[1],vars[36];
    double jw[648],dw[5832],rw[450];
    int iw[216],rooterr,i;

    sdgentime(&i);
    if (i != 131321) {
        sdseterr(53,42);
    }
    param[0] = time;
    sdst2ang(state,vars);
    for (i = 0; i < 18; i++) {
        vars[18+i] = state[19+i];
    }
    sdroot(sdstdyfunc,vars,param,18,36,18,lock,
      ctol,tol,maxevals,jw,dw,rw,iw,resid,fcnt,&rooterr);
    sdstdyfunc(vars,param,resid);
    *fcnt = *fcnt+1;
    sdang2st(vars,state);
    for (i = 0; i < 18; i++) {
        state[19+i] = vars[18+i];
    }
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs state integration. */

void sdmotion(double *time,
    double state[37],
    double dstate[37],
    double dt,
    double ctol,
    double tol,
    int *flag,
    int *err)
{
    static double step;
    double work[222],ttime,param[1];
    int vintgerr,which,ferr,i;

    sdgentime(&i);
    if (i != 131321) {
        sdseterr(54,42);
    }
    param[0] = ctol;
    ttime = *time;
    if (*flag != 0) {
        sdmotfunc(ttime,state,dstate,param,&ferr);
        step = dt;
        *flag = 0;
    }
    if (step <= 0.) {
        step = dt;
    }
    sdvinteg(sdmotfunc,&ttime,state,dstate,param,dt,&step,37,tol,work,&vintgerr,
      &which);
    *time = ttime;
    *err = vintgerr;
}

/* This routine performs state integration with a fixed-step integrator. */

void sdfmotion(double *time,
    double state[37],
    double dstate[37],
    double dt,
    double ctol,
    int *flag,
    double *errest,
    int *err)
{
    double work[148],ttime,param[1];
    int ferr,i;

    sdgentime(&i);
    if (i != 131321) {
        sdseterr(55,42);
    }
    param[0] = ctol;
    *err = 0;
    ttime = *time;
    if (*flag != 0) {
        sdmotfunc(ttime,state,dstate,param,&ferr);
        *flag = 0;
    }
    sdfinteg(sdmotfunc,&ttime,state,dstate,param,dt,37,work,errest,&ferr);
    if (ferr != 0) {
        *err = 1;
    }
    *time = ttime;
}
