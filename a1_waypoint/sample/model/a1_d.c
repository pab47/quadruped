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


ROADMAP (a1.sd)

Bodies        Inb
No  Name      body Joint type  Coords q
--- --------- ---- ----------- ----------------
 -1 $ground                                    
  0 trunk      -1  Sixdof        0   1   2 
                   ...           3   4   5  18 
  1 FR_hip      0  Pin           6             
  2 FR_thigh    1  Pin           7             
  3 FR_calf     2  Pin           8             
  4 FL_hip      0  Pin           9             
  5 FL_thigh    4  Pin          10             
  6 FL_calf     5  Pin          11             
  7 RR_hip      0  Pin          12             
  8 RR_thigh    7  Pin          13             
  9 RR_calf     8  Pin          14             
 10 RL_hip      0  Pin          15             
 11 RL_thigh   10  Pin          16             
 12 RL_calf    11  Pin          17             

*/
#include <math.h>
#include <stdio.h>

typedef struct {
    int ground_,nbod_,ndof_,ncons_,nloop_,nldof_,nloopc_,nball_,nlball_,npres_,
      nuser_;
    int jtype_[13],inb_[13],outb_[13],njntdof_[13],njntc_[13],njntp_[13],firstq_
      [13],ballq_[13],firstm_[13],firstp_[13];
    int trans_[18];
} sdgtopo_t;
#define ground (sdgtopo.ground_)
#define nbod (sdgtopo.nbod_)
#define ndof (sdgtopo.ndof_)
#define ncons (sdgtopo.ncons_)
#define nloop (sdgtopo.nloop_)
#define nldof (sdgtopo.nldof_)
#define nloopc (sdgtopo.nloopc_)
#define nball (sdgtopo.nball_)
#define nlball (sdgtopo.nlball_)
#define npres (sdgtopo.npres_)
#define nuser (sdgtopo.nuser_)
#define jtype (sdgtopo.jtype_)
#define inb (sdgtopo.inb_)
#define outb (sdgtopo.outb_)
#define njntdof (sdgtopo.njntdof_)
#define njntc (sdgtopo.njntc_)
#define njntp (sdgtopo.njntp_)
#define firstq (sdgtopo.firstq_)
#define ballq (sdgtopo.ballq_)
#define firstm (sdgtopo.firstm_)
#define firstp (sdgtopo.firstp_)
#define trans (sdgtopo.trans_)

typedef struct {
    double grav_[3],mk_[13],ik_[13][3][3],pin_[18][3];
    double rk_[13][3],ri_[13][3],pres_[18],stabvel_,stabpos_;
    int mfrcflg_,roustate_,vpkflg_,inerflg_,mmflg_,mmlduflg_,wwflg_,ltauflg_,
      fs0flg_,ii_,mmap_[18];
    int gravq_[3],mkq_[13],ikq_[13][3][3],pinq_[18][3],rkq_[13][3],riq_[13][3],
      presq_[18],stabvelq_,stabposq_;
    double mtot_,psmkg_,rhead_[13][3],rcom_[13][3],mkrcomt_[13][3][3],psikg_[3][
      3],psrcomg_[3],psrkg_[3],psrig_[3],psmk_[18],psik_[18][3][3],psrcom_[18][3
      ],psrk_[18][3],psri_[18][3];
} sdginput_t;
#define grav (sdginput.grav_)
#define mk (sdginput.mk_)
#define ik (sdginput.ik_)
#define pin (sdginput.pin_)
#define rk (sdginput.rk_)
#define ri (sdginput.ri_)
#define pres (sdginput.pres_)
#define stabvel (sdginput.stabvel_)
#define stabpos (sdginput.stabpos_)
#define rhead (sdginput.rhead_)
#define rcom (sdginput.rcom_)
#define psrcomg (sdginput.psrcomg_)
#define psrcom (sdginput.psrcom_)
#define mkrcomt (sdginput.mkrcomt_)
#define psmk (sdginput.psmk_)
#define psik (sdginput.psik_)
#define psrk (sdginput.psrk_)
#define psri (sdginput.psri_)
#define psmkg (sdginput.psmkg_)
#define psikg (sdginput.psikg_)
#define psrkg (sdginput.psrkg_)
#define psrig (sdginput.psrig_)
#define mtot (sdginput.mtot_)
#define mfrcflg (sdginput.mfrcflg_)
#define roustate (sdginput.roustate_)
#define vpkflg (sdginput.vpkflg_)
#define inerflg (sdginput.inerflg_)
#define mmflg (sdginput.mmflg_)
#define mmlduflg (sdginput.mmlduflg_)
#define wwflg (sdginput.wwflg_)
#define ltauflg (sdginput.ltauflg_)
#define fs0flg (sdginput.fs0flg_)
#define ii (sdginput.ii_)
#define mmap (sdginput.mmap_)
#define gravq (sdginput.gravq_)
#define mkq (sdginput.mkq_)
#define ikq (sdginput.ikq_)
#define pinq (sdginput.pinq_)
#define rkq (sdginput.rkq_)
#define riq (sdginput.riq_)
#define presq (sdginput.presq_)
#define stabvelq (sdginput.stabvelq_)
#define stabposq (sdginput.stabposq_)

typedef struct {
    double curtim_,q_[19],qn_[19],u_[18],cnk_[18][3][3],cnb_[13][3][3];
    double rnk_[18][3],vnk_[18][3],wk_[18][3],rnb_[13][3],vnb_[13][3],wb_[13][3]
      ,wbrcom_[13][3],com_[3],rnkg_[3];
    double Cik_[18][3][3],rikt_[18][3][3],Iko_[18][3][3],mkrk_[18][3][3],Cib_[13
      ][3][3];
    double Wkk_[18][3],Vkk_[18][3],dik_[18][3],rpp_[18][3],rpk_[18][3],rik_[18][
      3],rik2_[18][3];
    double rpri_[18][3],Wik_[18][3],Vik_[18][3],Wirk_[18][3],rkWkk_[18][3],
      Wkrpk_[18][3],VikWkr_[18][3];
    double perr_[1],verr_[1],aerr_[1],mult_[1],ufk_[13][3],utk_[13][3],mfk_[13][
      3],mtk_[13][3];
    double utau_[18],mtau_[18],uacc_[18],uvel_[18],upos_[19];
    double s6_,c6_,s7_,c7_,s8_,c8_,s9_,c9_,s10_,c10_,s11_,c11_,s12_,c12_,s13_,
      c13_,s14_,c14_,s15_,c15_,s16_,c16_,s17_,c17_;
} sdgstate_t;
#define curtim (sdgstate.curtim_)
#define q (sdgstate.q_)
#define qn (sdgstate.qn_)
#define u (sdgstate.u_)
#define cnk (sdgstate.cnk_)
#define cnb (sdgstate.cnb_)
#define rnkg (sdgstate.rnkg_)
#define rnk (sdgstate.rnk_)
#define rnb (sdgstate.rnb_)
#define vnk (sdgstate.vnk_)
#define vnb (sdgstate.vnb_)
#define wk (sdgstate.wk_)
#define wb (sdgstate.wb_)
#define com (sdgstate.com_)
#define Cik (sdgstate.Cik_)
#define Cib (sdgstate.Cib_)
#define rikt (sdgstate.rikt_)
#define Iko (sdgstate.Iko_)
#define mkrk (sdgstate.mkrk_)
#define Wkk (sdgstate.Wkk_)
#define Vkk (sdgstate.Vkk_)
#define dik (sdgstate.dik_)
#define rpp (sdgstate.rpp_)
#define rpk (sdgstate.rpk_)
#define rik (sdgstate.rik_)
#define rik2 (sdgstate.rik2_)
#define rpri (sdgstate.rpri_)
#define Wik (sdgstate.Wik_)
#define Vik (sdgstate.Vik_)
#define Wirk (sdgstate.Wirk_)
#define rkWkk (sdgstate.rkWkk_)
#define Wkrpk (sdgstate.Wkrpk_)
#define VikWkr (sdgstate.VikWkr_)
#define wbrcom (sdgstate.wbrcom_)
#define perr (sdgstate.perr_)
#define verr (sdgstate.verr_)
#define aerr (sdgstate.aerr_)
#define mult (sdgstate.mult_)
#define ufk (sdgstate.ufk_)
#define utk (sdgstate.utk_)
#define utau (sdgstate.utau_)
#define mfk (sdgstate.mfk_)
#define mtk (sdgstate.mtk_)
#define mtau (sdgstate.mtau_)
#define uacc (sdgstate.uacc_)
#define uvel (sdgstate.uvel_)
#define upos (sdgstate.upos_)
#define s6 (sdgstate.s6_)
#define c6 (sdgstate.c6_)
#define s7 (sdgstate.s7_)
#define c7 (sdgstate.c7_)
#define s8 (sdgstate.s8_)
#define c8 (sdgstate.c8_)
#define s9 (sdgstate.s9_)
#define c9 (sdgstate.c9_)
#define s10 (sdgstate.s10_)
#define c10 (sdgstate.c10_)
#define s11 (sdgstate.s11_)
#define c11 (sdgstate.c11_)
#define s12 (sdgstate.s12_)
#define c12 (sdgstate.c12_)
#define s13 (sdgstate.s13_)
#define c13 (sdgstate.c13_)
#define s14 (sdgstate.s14_)
#define c14 (sdgstate.c14_)
#define s15 (sdgstate.s15_)
#define c15 (sdgstate.c15_)
#define s16 (sdgstate.s16_)
#define c16 (sdgstate.c16_)
#define s17 (sdgstate.s17_)
#define c17 (sdgstate.c17_)

typedef struct {
    double fs0_[18],qdot_[19],Otk_[18][3],Atk_[18][3],AiOiWi_[18][3],Fstar_[18][
      3];
    double Tstar_[18][3],Fstark_[18][3],Tstark_[18][3],IkWk_[18][3],WkIkWk_[18][
      3],gk_[18][3],IkbWk_[13][3],WkIkbWk_[13][3];
    double w0w0_[13],w1w1_[13],w2w2_[13],w0w1_[13],w0w2_[13],w1w2_[13];
    double w00w11_[13],w00w22_[13],w11w22_[13],ww_[1][1],qraux_[1];
    double mm_[18][18],mlo_[18][18],mdi_[18],IkWpk_[18][18][3],works_[18],
      workss_[18][18];
    double Wpk_[18][18][3],Vpk_[18][18][3],VWri_[18][18][3];
    int wmap_[1],multmap_[1],jpvt_[1],wsiz_,wrank_;
} sdglhs_t;
#define qdot (sdglhs.qdot_)
#define Otk (sdglhs.Otk_)
#define Atk (sdglhs.Atk_)
#define AiOiWi (sdglhs.AiOiWi_)
#define Fstar (sdglhs.Fstar_)
#define Tstar (sdglhs.Tstar_)
#define fs0 (sdglhs.fs0_)
#define Fstark (sdglhs.Fstark_)
#define Tstark (sdglhs.Tstark_)
#define IkWk (sdglhs.IkWk_)
#define IkbWk (sdglhs.IkbWk_)
#define WkIkWk (sdglhs.WkIkWk_)
#define WkIkbWk (sdglhs.WkIkbWk_)
#define gk (sdglhs.gk_)
#define w0w0 (sdglhs.w0w0_)
#define w1w1 (sdglhs.w1w1_)
#define w2w2 (sdglhs.w2w2_)
#define w0w1 (sdglhs.w0w1_)
#define w0w2 (sdglhs.w0w2_)
#define w1w2 (sdglhs.w1w2_)
#define w00w11 (sdglhs.w00w11_)
#define w00w22 (sdglhs.w00w22_)
#define w11w22 (sdglhs.w11w22_)
#define ww (sdglhs.ww_)
#define qraux (sdglhs.qraux_)
#define mm (sdglhs.mm_)
#define mlo (sdglhs.mlo_)
#define mdi (sdglhs.mdi_)
#define IkWpk (sdglhs.IkWpk_)
#define works (sdglhs.works_)
#define workss (sdglhs.workss_)
#define Wpk (sdglhs.Wpk_)
#define Vpk (sdglhs.Vpk_)
#define VWri (sdglhs.VWri_)
#define wmap (sdglhs.wmap_)
#define multmap (sdglhs.multmap_)
#define jpvt (sdglhs.jpvt_)
#define wsiz (sdglhs.wsiz_)
#define wrank (sdglhs.wrank_)

typedef struct {
    double fs_[18],udot_[18],tauc_[18],dyad_[13][3][3],fc_[18][3],tc_[18][3];
    double ank_[18][3],onk_[18][3],Onkb_[18][3],AOnkri_[18][3],Ankb_[18][3],
      AnkAtk_[18][3],anb_[13][3],onb_[13][3],dyrcom_[13][3];
    double ffk_[18][3],ttk_[18][3],fccikt_[18][3],ffkb_[13][3],ttkb_[13][3];
} sdgrhs_t;
#define fs (sdgrhs.fs_)
#define udot (sdgrhs.udot_)
#define ank (sdgrhs.ank_)
#define anb (sdgrhs.anb_)
#define onk (sdgrhs.onk_)
#define onb (sdgrhs.onb_)
#define Onkb (sdgrhs.Onkb_)
#define AOnkri (sdgrhs.AOnkri_)
#define Ankb (sdgrhs.Ankb_)
#define AnkAtk (sdgrhs.AnkAtk_)
#define dyrcom (sdgrhs.dyrcom_)
#define ffk (sdgrhs.ffk_)
#define ttk (sdgrhs.ttk_)
#define fccikt (sdgrhs.fccikt_)
#define ffkb (sdgrhs.ffkb_)
#define ttkb (sdgrhs.ttkb_)
#define dyad (sdgrhs.dyad_)
#define fc (sdgrhs.fc_)
#define tc (sdgrhs.tc_)
#define tauc (sdgrhs.tauc_)

typedef struct {
    double temp_[3000],tmat1_[3][3],tmat2_[3][3],tvec1_[3],tvec2_[3],tvec3_[3],
      tvec4_[3],tvec5_[3];
    double tsc1_,tsc2_,tsc3_;
} sdgtemp_t;
#define temp (sdgtemp.temp_)
#define tmat1 (sdgtemp.tmat1_)
#define tmat2 (sdgtemp.tmat2_)
#define tvec1 (sdgtemp.tvec1_)
#define tvec2 (sdgtemp.tvec2_)
#define tvec3 (sdgtemp.tvec3_)
#define tvec4 (sdgtemp.tvec4_)
#define tvec5 (sdgtemp.tvec5_)
#define tsc1 (sdgtemp.tsc1_)
#define tsc2 (sdgtemp.tsc2_)
#define tsc3 (sdgtemp.tsc3_)

sdgtopo_t sdgtopo = {
/*  Topological information
*/
    /* ground */ 1,
    /* nbod */ 13,
    /* ndof */ 18,
    /* ncons */ 0,
    /* nloop */ 0,
    /* nldof */ 0,
    /* nloopc */ 0,
    /* nball */ 1,
    /* nlball */ 0,
    /* npres */ 0,
    /* nuser */ 0,
    /* jtype[0] */ 6,
    /* jtype[1] */ 1,
    /* jtype[2] */ 1,
    /* jtype[3] */ 1,
    /* jtype[4] */ 1,
    /* jtype[5] */ 1,
    /* jtype[6] */ 1,
    /* jtype[7] */ 1,
    /* jtype[8] */ 1,
    /* jtype[9] */ 1,
    /* jtype[10] */ 1,
    /* jtype[11] */ 1,
    /* jtype[12] */ 1,
    /* inb[0] */ -1,
    /* inb[1] */ 0,
    /* inb[2] */ 1,
    /* inb[3] */ 2,
    /* inb[4] */ 0,
    /* inb[5] */ 4,
    /* inb[6] */ 5,
    /* inb[7] */ 0,
    /* inb[8] */ 7,
    /* inb[9] */ 8,
    /* inb[10] */ 0,
    /* inb[11] */ 10,
    /* inb[12] */ 11,
    /* outb[0] */ 0,
    /* outb[1] */ 1,
    /* outb[2] */ 2,
    /* outb[3] */ 3,
    /* outb[4] */ 4,
    /* outb[5] */ 5,
    /* outb[6] */ 6,
    /* outb[7] */ 7,
    /* outb[8] */ 8,
    /* outb[9] */ 9,
    /* outb[10] */ 10,
    /* outb[11] */ 11,
    /* outb[12] */ 12,
    /* njntdof[0] */ 6,
    /* njntdof[1] */ 1,
    /* njntdof[2] */ 1,
    /* njntdof[3] */ 1,
    /* njntdof[4] */ 1,
    /* njntdof[5] */ 1,
    /* njntdof[6] */ 1,
    /* njntdof[7] */ 1,
    /* njntdof[8] */ 1,
    /* njntdof[9] */ 1,
    /* njntdof[10] */ 1,
    /* njntdof[11] */ 1,
    /* njntdof[12] */ 1,
    /* njntc[0] */ 0,
    /* njntc[1] */ 0,
    /* njntc[2] */ 0,
    /* njntc[3] */ 0,
    /* njntc[4] */ 0,
    /* njntc[5] */ 0,
    /* njntc[6] */ 0,
    /* njntc[7] */ 0,
    /* njntc[8] */ 0,
    /* njntc[9] */ 0,
    /* njntc[10] */ 0,
    /* njntc[11] */ 0,
    /* njntc[12] */ 0,
    /* njntp[0] */ 0,
    /* njntp[1] */ 0,
    /* njntp[2] */ 0,
    /* njntp[3] */ 0,
    /* njntp[4] */ 0,
    /* njntp[5] */ 0,
    /* njntp[6] */ 0,
    /* njntp[7] */ 0,
    /* njntp[8] */ 0,
    /* njntp[9] */ 0,
    /* njntp[10] */ 0,
    /* njntp[11] */ 0,
    /* njntp[12] */ 0,
    /* firstq[0] */ 0,
    /* firstq[1] */ 6,
    /* firstq[2] */ 7,
    /* firstq[3] */ 8,
    /* firstq[4] */ 9,
    /* firstq[5] */ 10,
    /* firstq[6] */ 11,
    /* firstq[7] */ 12,
    /* firstq[8] */ 13,
    /* firstq[9] */ 14,
    /* firstq[10] */ 15,
    /* firstq[11] */ 16,
    /* firstq[12] */ 17,
    /* ballq[0] */ 18,
    /* ballq[1] */ -104,
    /* ballq[2] */ -104,
    /* ballq[3] */ -104,
    /* ballq[4] */ -104,
    /* ballq[5] */ -104,
    /* ballq[6] */ -104,
    /* ballq[7] */ -104,
    /* ballq[8] */ -104,
    /* ballq[9] */ -104,
    /* ballq[10] */ -104,
    /* ballq[11] */ -104,
    /* ballq[12] */ -104,
    /* firstm[0] */ -1,
    /* firstm[1] */ -1,
    /* firstm[2] */ -1,
    /* firstm[3] */ -1,
    /* firstm[4] */ -1,
    /* firstm[5] */ -1,
    /* firstm[6] */ -1,
    /* firstm[7] */ -1,
    /* firstm[8] */ -1,
    /* firstm[9] */ -1,
    /* firstm[10] */ -1,
    /* firstm[11] */ -1,
    /* firstm[12] */ -1,
    /* firstp[0] */ -1,
    /* firstp[1] */ -1,
    /* firstp[2] */ -1,
    /* firstp[3] */ -1,
    /* firstp[4] */ -1,
    /* firstp[5] */ -1,
    /* firstp[6] */ -1,
    /* firstp[7] */ -1,
    /* firstp[8] */ -1,
    /* firstp[9] */ -1,
    /* firstp[10] */ -1,
    /* firstp[11] */ -1,
    /* firstp[12] */ -1,
    /* trans[0] */ 1,
    /* trans[1] */ 1,
    /* trans[2] */ 1,
    /* trans[3] */ 0,
    /* trans[4] */ 0,
    /* trans[5] */ 0,
    /* trans[6] */ 0,
    /* trans[7] */ 0,
    /* trans[8] */ 0,
    /* trans[9] */ 0,
    /* trans[10] */ 0,
    /* trans[11] */ 0,
    /* trans[12] */ 0,
    /* trans[13] */ 0,
    /* trans[14] */ 0,
    /* trans[15] */ 0,
    /* trans[16] */ 0,
    /* trans[17] */ 0,
};
sdginput_t sdginput = {
/* Model parameters from the input file */

/* gravity */
    /* grav[0] */ 0.,
    /* grav[1] */ 0.,
    /* grav[2] */ -9.81,

/* mass */
    /* mk[0] */ 4.714,
    /* mk[1] */ .696,
    /* mk[2] */ 1.013,
    /* mk[3] */ .226,
    /* mk[4] */ .696,
    /* mk[5] */ 1.013,
    /* mk[6] */ .226,
    /* mk[7] */ .696,
    /* mk[8] */ 1.013,
    /* mk[9] */ .226,
    /* mk[10] */ .696,
    /* mk[11] */ 1.013,
    /* mk[12] */ .226,

/* inertia */
    /* ik[0][0][0] */ .01694,
    /* ik[0][0][1] */ 8.3874e-5,
    /* ik[0][0][2] */ .00059778,
    /* ik[0][1][0] */ 8.3874e-5,
    /* ik[0][1][1] */ .05658,
    /* ik[0][1][2] */ 2.5133e-5,
    /* ik[0][2][0] */ .00059778,
    /* ik[0][2][1] */ 2.5133e-5,
    /* ik[0][2][2] */ .064814,
    /* ik[1][0][0] */ .00046925,
    /* ik[1][0][1] */ 9.4092e-6,
    /* ik[1][0][2] */ -3.4207e-7,
    /* ik[1][1][0] */ 9.4092e-6,
    /* ik[1][1][1] */ .00080749,
    /* ik[1][1][2] */ 4.6605e-7,
    /* ik[1][2][0] */ -3.4207e-7,
    /* ik[1][2][1] */ 4.6605e-7,
    /* ik[1][2][2] */ .00055293,
    /* ik[2][0][0] */ .0055291,
    /* ik[2][0][1] */ -4.825e-6,
    /* ik[2][0][2] */ .00034387,
    /* ik[2][1][0] */ -4.825e-6,
    /* ik[2][1][1] */ .0051393,
    /* ik[2][1][2] */ -2.2447e-5,
    /* ik[2][2][0] */ .00034387,
    /* ik[2][2][1] */ -2.2447e-5,
    /* ik[2][2][2] */ .0013678,
    /* ik[3][0][0] */ .0033856,
    /* ik[3][0][1] */ 0.,
    /* ik[3][0][2] */ -.00016743,
    /* ik[3][1][0] */ 0.,
    /* ik[3][1][1] */ .0034034,
    /* ik[3][1][2] */ 0.,
    /* ik[3][2][0] */ -.00016743,
    /* ik[3][2][1] */ 0.,
    /* ik[3][2][2] */ 4.3851e-5,
    /* ik[4][0][0] */ .00046925,
    /* ik[4][0][1] */ -9.4092e-6,
    /* ik[4][0][2] */ -3.4207e-7,
    /* ik[4][1][0] */ -9.4092e-6,
    /* ik[4][1][1] */ .00080749,
    /* ik[4][1][2] */ -4.6605e-7,
    /* ik[4][2][0] */ -3.4207e-7,
    /* ik[4][2][1] */ -4.6605e-7,
    /* ik[4][2][2] */ .00055293,
    /* ik[5][0][0] */ .0055291,
    /* ik[5][0][1] */ 4.825e-6,
    /* ik[5][0][2] */ .00034387,
    /* ik[5][1][0] */ 4.825e-6,
    /* ik[5][1][1] */ .0051393,
    /* ik[5][1][2] */ 2.2447e-5,
    /* ik[5][2][0] */ .00034387,
    /* ik[5][2][1] */ 2.2447e-5,
    /* ik[5][2][2] */ .0013678,
    /* ik[6][0][0] */ .0033856,
    /* ik[6][0][1] */ 0.,
    /* ik[6][0][2] */ -.00016743,
    /* ik[6][1][0] */ 0.,
    /* ik[6][1][1] */ .0034034,
    /* ik[6][1][2] */ 0.,
    /* ik[6][2][0] */ -.00016743,
    /* ik[6][2][1] */ 0.,
    /* ik[6][2][2] */ 4.3851e-5,
    /* ik[7][0][0] */ .00046925,
    /* ik[7][0][1] */ -9.4092e-6,
    /* ik[7][0][2] */ 3.4207e-7,
    /* ik[7][1][0] */ -9.4092e-6,
    /* ik[7][1][1] */ .00080749,
    /* ik[7][1][2] */ 4.6605e-7,
    /* ik[7][2][0] */ 3.4207e-7,
    /* ik[7][2][1] */ 4.6605e-7,
    /* ik[7][2][2] */ .00055293,
    /* ik[8][0][0] */ .0055291,
    /* ik[8][0][1] */ -4.825e-6,
    /* ik[8][0][2] */ .00034387,
    /* ik[8][1][0] */ -4.825e-6,
    /* ik[8][1][1] */ .0051393,
    /* ik[8][1][2] */ -2.2447e-5,
    /* ik[8][2][0] */ .00034387,
    /* ik[8][2][1] */ -2.2447e-5,
    /* ik[8][2][2] */ .0013678,
    /* ik[9][0][0] */ .0033856,
    /* ik[9][0][1] */ 0.,
    /* ik[9][0][2] */ -.00016743,
    /* ik[9][1][0] */ 0.,
    /* ik[9][1][1] */ .0034034,
    /* ik[9][1][2] */ 0.,
    /* ik[9][2][0] */ -.00016743,
    /* ik[9][2][1] */ 0.,
    /* ik[9][2][2] */ 4.3851e-5,
    /* ik[10][0][0] */ .00046925,
    /* ik[10][0][1] */ 9.4092e-6,
    /* ik[10][0][2] */ 3.4207e-7,
    /* ik[10][1][0] */ 9.4092e-6,
    /* ik[10][1][1] */ .00080749,
    /* ik[10][1][2] */ -4.6605e-7,
    /* ik[10][2][0] */ 3.4207e-7,
    /* ik[10][2][1] */ -4.6605e-7,
    /* ik[10][2][2] */ .00055293,
    /* ik[11][0][0] */ .0055291,
    /* ik[11][0][1] */ 4.825e-6,
    /* ik[11][0][2] */ .00034387,
    /* ik[11][1][0] */ 4.825e-6,
    /* ik[11][1][1] */ .0051393,
    /* ik[11][1][2] */ 2.2447e-5,
    /* ik[11][2][0] */ .00034387,
    /* ik[11][2][1] */ 2.2447e-5,
    /* ik[11][2][2] */ .0013678,
    /* ik[12][0][0] */ .0033856,
    /* ik[12][0][1] */ 0.,
    /* ik[12][0][2] */ -.00016743,
    /* ik[12][1][0] */ 0.,
    /* ik[12][1][1] */ .0034034,
    /* ik[12][1][2] */ 0.,
    /* ik[12][2][0] */ -.00016743,
    /* ik[12][2][1] */ 0.,
    /* ik[12][2][2] */ 4.3851e-5,

/* tree hinge axis vectors */
    /* pin[0][0] */ 1.,
    /* pin[0][1] */ 0.,
    /* pin[0][2] */ 0.,
    /* pin[1][0] */ 0.,
    /* pin[1][1] */ 1.,
    /* pin[1][2] */ 0.,
    /* pin[2][0] */ 0.,
    /* pin[2][1] */ 0.,
    /* pin[2][2] */ 1.,
    /* pin[3][0] */ 0.,
    /* pin[3][1] */ 0.,
    /* pin[3][2] */ 0.,
    /* pin[4][0] */ 0.,
    /* pin[4][1] */ 0.,
    /* pin[4][2] */ 0.,
    /* pin[5][0] */ 0.,
    /* pin[5][1] */ 0.,
    /* pin[5][2] */ 0.,
    /* pin[6][0] */ 1.,
    /* pin[6][1] */ 0.,
    /* pin[6][2] */ 0.,
    /* pin[7][0] */ 0.,
    /* pin[7][1] */ 1.,
    /* pin[7][2] */ 0.,
    /* pin[8][0] */ 0.,
    /* pin[8][1] */ 1.,
    /* pin[8][2] */ 0.,
    /* pin[9][0] */ 1.,
    /* pin[9][1] */ 0.,
    /* pin[9][2] */ 0.,
    /* pin[10][0] */ 0.,
    /* pin[10][1] */ 1.,
    /* pin[10][2] */ 0.,
    /* pin[11][0] */ 0.,
    /* pin[11][1] */ 1.,
    /* pin[11][2] */ 0.,
    /* pin[12][0] */ 1.,
    /* pin[12][1] */ 0.,
    /* pin[12][2] */ 0.,
    /* pin[13][0] */ 0.,
    /* pin[13][1] */ 1.,
    /* pin[13][2] */ 0.,
    /* pin[14][0] */ 0.,
    /* pin[14][1] */ 1.,
    /* pin[14][2] */ 0.,
    /* pin[15][0] */ 1.,
    /* pin[15][1] */ 0.,
    /* pin[15][2] */ 0.,
    /* pin[16][0] */ 0.,
    /* pin[16][1] */ 1.,
    /* pin[16][2] */ 0.,
    /* pin[17][0] */ 0.,
    /* pin[17][1] */ 1.,
    /* pin[17][2] */ 0.,

/* tree bodytojoint vectors */
    /* rk[0][0] */ -.012728,
    /* rk[0][1] */ -.0021855,
    /* rk[0][2] */ -.00051489,
    /* rk[1][0] */ .003311,
    /* rk[1][1] */ .000635,
    /* rk[1][2] */ -3.1e-5,
    /* rk[2][0] */ .003237,
    /* rk[2][1] */ -.022327,
    /* rk[2][2] */ .027326,
    /* rk[3][0] */ -.0047266,
    /* rk[3][1] */ 0.,
    /* rk[3][2] */ .13198,
    /* rk[4][0] */ .003311,
    /* rk[4][1] */ -.000635,
    /* rk[4][2] */ -3.1e-5,
    /* rk[5][0] */ .003237,
    /* rk[5][1] */ .022327,
    /* rk[5][2] */ .027326,
    /* rk[6][0] */ -.0047266,
    /* rk[6][1] */ 0.,
    /* rk[6][2] */ .13198,
    /* rk[7][0] */ -.003311,
    /* rk[7][1] */ .000635,
    /* rk[7][2] */ -3.1e-5,
    /* rk[8][0] */ .003237,
    /* rk[8][1] */ -.022327,
    /* rk[8][2] */ .027326,
    /* rk[9][0] */ -.0047266,
    /* rk[9][1] */ 0.,
    /* rk[9][2] */ .13198,
    /* rk[10][0] */ -.003311,
    /* rk[10][1] */ -.000635,
    /* rk[10][2] */ -3.1e-5,
    /* rk[11][0] */ .003237,
    /* rk[11][1] */ .022327,
    /* rk[11][2] */ .027326,
    /* rk[12][0] */ -.0047266,
    /* rk[12][1] */ 0.,
    /* rk[12][2] */ .13198,

/* tree inbtojoint vectors */
    /* ri[0][0] */ 0.,
    /* ri[0][1] */ 0.,
    /* ri[0][2] */ 0.,
    /* ri[1][0] */ .17027,
    /* ri[1][1] */ -.049186,
    /* ri[1][2] */ -.00051489,
    /* ri[2][0] */ .003311,
    /* ri[2][1] */ -.084415,
    /* ri[2][2] */ -3.1e-5,
    /* ri[3][0] */ .003237,
    /* ri[3][1] */ -.022327,
    /* ri[3][2] */ -.17267,
    /* ri[4][0] */ .17027,
    /* ri[4][1] */ .044814,
    /* ri[4][2] */ -.00051489,
    /* ri[5][0] */ .003311,
    /* ri[5][1] */ .084415,
    /* ri[5][2] */ -3.1e-5,
    /* ri[6][0] */ .003237,
    /* ri[6][1] */ .022327,
    /* ri[6][2] */ -.17267,
    /* ri[7][0] */ -.19573,
    /* ri[7][1] */ -.049186,
    /* ri[7][2] */ -.00051489,
    /* ri[8][0] */ -.003311,
    /* ri[8][1] */ -.084415,
    /* ri[8][2] */ -3.1e-5,
    /* ri[9][0] */ .003237,
    /* ri[9][1] */ -.022327,
    /* ri[9][2] */ -.17267,
    /* ri[10][0] */ -.19573,
    /* ri[10][1] */ .044814,
    /* ri[10][2] */ -.00051489,
    /* ri[11][0] */ -.003311,
    /* ri[11][1] */ .084415,
    /* ri[11][2] */ -3.1e-5,
    /* ri[12][0] */ .003237,
    /* ri[12][1] */ .022327,
    /* ri[12][2] */ -.17267,

/* tree prescribed motion */
    /* pres[0] */ 0.,
    /* pres[1] */ 0.,
    /* pres[2] */ 0.,
    /* pres[3] */ 0.,
    /* pres[4] */ 0.,
    /* pres[5] */ 0.,
    /* pres[6] */ 0.,
    /* pres[7] */ 0.,
    /* pres[8] */ 0.,
    /* pres[9] */ 0.,
    /* pres[10] */ 0.,
    /* pres[11] */ 0.,
    /* pres[12] */ 0.,
    /* pres[13] */ 0.,
    /* pres[14] */ 0.,
    /* pres[15] */ 0.,
    /* pres[16] */ 0.,
    /* pres[17] */ 0.,

/* stabilization parameters */
    /* stabvel */ 0.,
    /* stabpos */ 0.,

/* miscellaneous */
    /* mfrcflg */ 0,
    /* roustate */ 0,
    /* vpkflg */ 0,
    /* inerflg */ 0,
    /* mmflg */ 0,
    /* mmlduflg */ 0,
    /* wwflg */ 0,
    /* ltauflg */ 0,
    /* fs0flg */ 0,
    /* ii */ 0,
    /* mmap[0] */ 0,
    /* mmap[1] */ 1,
    /* mmap[2] */ 2,
    /* mmap[3] */ 3,
    /* mmap[4] */ 4,
    /* mmap[5] */ 5,
    /* mmap[6] */ 6,
    /* mmap[7] */ 7,
    /* mmap[8] */ 8,
    /* mmap[9] */ 9,
    /* mmap[10] */ 10,
    /* mmap[11] */ 11,
    /* mmap[12] */ 12,
    /* mmap[13] */ 13,
    /* mmap[14] */ 14,
    /* mmap[15] */ 15,
    /* mmap[16] */ 16,
    /* mmap[17] */ 17,

/* Which parameters were "?" (1) or "<nominal>?" (3) */
    /* gravq[0] */ 3,
    /* gravq[1] */ 3,
    /* gravq[2] */ 3,
    /* mkq[0] */ 3,
    /* mkq[1] */ 3,
    /* mkq[2] */ 3,
    /* mkq[3] */ 3,
    /* mkq[4] */ 3,
    /* mkq[5] */ 3,
    /* mkq[6] */ 3,
    /* mkq[7] */ 3,
    /* mkq[8] */ 3,
    /* mkq[9] */ 3,
    /* mkq[10] */ 3,
    /* mkq[11] */ 3,
    /* mkq[12] */ 3,
    /* ikq[0][0][0] */ 3,
    /* ikq[0][0][1] */ 3,
    /* ikq[0][0][2] */ 3,
    /* ikq[0][1][0] */ 3,
    /* ikq[0][1][1] */ 3,
    /* ikq[0][1][2] */ 3,
    /* ikq[0][2][0] */ 3,
    /* ikq[0][2][1] */ 3,
    /* ikq[0][2][2] */ 3,
    /* ikq[1][0][0] */ 3,
    /* ikq[1][0][1] */ 3,
    /* ikq[1][0][2] */ 3,
    /* ikq[1][1][0] */ 3,
    /* ikq[1][1][1] */ 3,
    /* ikq[1][1][2] */ 3,
    /* ikq[1][2][0] */ 3,
    /* ikq[1][2][1] */ 3,
    /* ikq[1][2][2] */ 3,
    /* ikq[2][0][0] */ 3,
    /* ikq[2][0][1] */ 3,
    /* ikq[2][0][2] */ 3,
    /* ikq[2][1][0] */ 3,
    /* ikq[2][1][1] */ 3,
    /* ikq[2][1][2] */ 3,
    /* ikq[2][2][0] */ 3,
    /* ikq[2][2][1] */ 3,
    /* ikq[2][2][2] */ 3,
    /* ikq[3][0][0] */ 3,
    /* ikq[3][0][1] */ 3,
    /* ikq[3][0][2] */ 3,
    /* ikq[3][1][0] */ 3,
    /* ikq[3][1][1] */ 3,
    /* ikq[3][1][2] */ 3,
    /* ikq[3][2][0] */ 3,
    /* ikq[3][2][1] */ 3,
    /* ikq[3][2][2] */ 3,
    /* ikq[4][0][0] */ 3,
    /* ikq[4][0][1] */ 3,
    /* ikq[4][0][2] */ 3,
    /* ikq[4][1][0] */ 3,
    /* ikq[4][1][1] */ 3,
    /* ikq[4][1][2] */ 3,
    /* ikq[4][2][0] */ 3,
    /* ikq[4][2][1] */ 3,
    /* ikq[4][2][2] */ 3,
    /* ikq[5][0][0] */ 3,
    /* ikq[5][0][1] */ 3,
    /* ikq[5][0][2] */ 3,
    /* ikq[5][1][0] */ 3,
    /* ikq[5][1][1] */ 3,
    /* ikq[5][1][2] */ 3,
    /* ikq[5][2][0] */ 3,
    /* ikq[5][2][1] */ 3,
    /* ikq[5][2][2] */ 3,
    /* ikq[6][0][0] */ 3,
    /* ikq[6][0][1] */ 3,
    /* ikq[6][0][2] */ 3,
    /* ikq[6][1][0] */ 3,
    /* ikq[6][1][1] */ 3,
    /* ikq[6][1][2] */ 3,
    /* ikq[6][2][0] */ 3,
    /* ikq[6][2][1] */ 3,
    /* ikq[6][2][2] */ 3,
    /* ikq[7][0][0] */ 3,
    /* ikq[7][0][1] */ 3,
    /* ikq[7][0][2] */ 3,
    /* ikq[7][1][0] */ 3,
    /* ikq[7][1][1] */ 3,
    /* ikq[7][1][2] */ 3,
    /* ikq[7][2][0] */ 3,
    /* ikq[7][2][1] */ 3,
    /* ikq[7][2][2] */ 3,
    /* ikq[8][0][0] */ 3,
    /* ikq[8][0][1] */ 3,
    /* ikq[8][0][2] */ 3,
    /* ikq[8][1][0] */ 3,
    /* ikq[8][1][1] */ 3,
    /* ikq[8][1][2] */ 3,
    /* ikq[8][2][0] */ 3,
    /* ikq[8][2][1] */ 3,
    /* ikq[8][2][2] */ 3,
    /* ikq[9][0][0] */ 3,
    /* ikq[9][0][1] */ 3,
    /* ikq[9][0][2] */ 3,
    /* ikq[9][1][0] */ 3,
    /* ikq[9][1][1] */ 3,
    /* ikq[9][1][2] */ 3,
    /* ikq[9][2][0] */ 3,
    /* ikq[9][2][1] */ 3,
    /* ikq[9][2][2] */ 3,
    /* ikq[10][0][0] */ 3,
    /* ikq[10][0][1] */ 3,
    /* ikq[10][0][2] */ 3,
    /* ikq[10][1][0] */ 3,
    /* ikq[10][1][1] */ 3,
    /* ikq[10][1][2] */ 3,
    /* ikq[10][2][0] */ 3,
    /* ikq[10][2][1] */ 3,
    /* ikq[10][2][2] */ 3,
    /* ikq[11][0][0] */ 3,
    /* ikq[11][0][1] */ 3,
    /* ikq[11][0][2] */ 3,
    /* ikq[11][1][0] */ 3,
    /* ikq[11][1][1] */ 3,
    /* ikq[11][1][2] */ 3,
    /* ikq[11][2][0] */ 3,
    /* ikq[11][2][1] */ 3,
    /* ikq[11][2][2] */ 3,
    /* ikq[12][0][0] */ 3,
    /* ikq[12][0][1] */ 3,
    /* ikq[12][0][2] */ 3,
    /* ikq[12][1][0] */ 3,
    /* ikq[12][1][1] */ 3,
    /* ikq[12][1][2] */ 3,
    /* ikq[12][2][0] */ 3,
    /* ikq[12][2][1] */ 3,
    /* ikq[12][2][2] */ 3,
    /* pinq[0][0] */ 3,
    /* pinq[0][1] */ 3,
    /* pinq[0][2] */ 3,
    /* pinq[1][0] */ 3,
    /* pinq[1][1] */ 3,
    /* pinq[1][2] */ 3,
    /* pinq[2][0] */ 3,
    /* pinq[2][1] */ 3,
    /* pinq[2][2] */ 3,
    /* pinq[3][0] */ 0,
    /* pinq[3][1] */ 0,
    /* pinq[3][2] */ 0,
    /* pinq[4][0] */ 0,
    /* pinq[4][1] */ 0,
    /* pinq[4][2] */ 0,
    /* pinq[5][0] */ 0,
    /* pinq[5][1] */ 0,
    /* pinq[5][2] */ 0,
    /* pinq[6][0] */ 3,
    /* pinq[6][1] */ 3,
    /* pinq[6][2] */ 3,
    /* pinq[7][0] */ 3,
    /* pinq[7][1] */ 3,
    /* pinq[7][2] */ 3,
    /* pinq[8][0] */ 3,
    /* pinq[8][1] */ 3,
    /* pinq[8][2] */ 3,
    /* pinq[9][0] */ 3,
    /* pinq[9][1] */ 3,
    /* pinq[9][2] */ 3,
    /* pinq[10][0] */ 3,
    /* pinq[10][1] */ 3,
    /* pinq[10][2] */ 3,
    /* pinq[11][0] */ 3,
    /* pinq[11][1] */ 3,
    /* pinq[11][2] */ 3,
    /* pinq[12][0] */ 3,
    /* pinq[12][1] */ 3,
    /* pinq[12][2] */ 3,
    /* pinq[13][0] */ 3,
    /* pinq[13][1] */ 3,
    /* pinq[13][2] */ 3,
    /* pinq[14][0] */ 3,
    /* pinq[14][1] */ 3,
    /* pinq[14][2] */ 3,
    /* pinq[15][0] */ 3,
    /* pinq[15][1] */ 3,
    /* pinq[15][2] */ 3,
    /* pinq[16][0] */ 3,
    /* pinq[16][1] */ 3,
    /* pinq[16][2] */ 3,
    /* pinq[17][0] */ 3,
    /* pinq[17][1] */ 3,
    /* pinq[17][2] */ 3,
    /* rkq[0][0] */ 3,
    /* rkq[0][1] */ 3,
    /* rkq[0][2] */ 3,
    /* rkq[1][0] */ 3,
    /* rkq[1][1] */ 3,
    /* rkq[1][2] */ 3,
    /* rkq[2][0] */ 3,
    /* rkq[2][1] */ 3,
    /* rkq[2][2] */ 3,
    /* rkq[3][0] */ 3,
    /* rkq[3][1] */ 3,
    /* rkq[3][2] */ 3,
    /* rkq[4][0] */ 3,
    /* rkq[4][1] */ 3,
    /* rkq[4][2] */ 3,
    /* rkq[5][0] */ 3,
    /* rkq[5][1] */ 3,
    /* rkq[5][2] */ 3,
    /* rkq[6][0] */ 3,
    /* rkq[6][1] */ 3,
    /* rkq[6][2] */ 3,
    /* rkq[7][0] */ 3,
    /* rkq[7][1] */ 3,
    /* rkq[7][2] */ 3,
    /* rkq[8][0] */ 3,
    /* rkq[8][1] */ 3,
    /* rkq[8][2] */ 3,
    /* rkq[9][0] */ 3,
    /* rkq[9][1] */ 3,
    /* rkq[9][2] */ 3,
    /* rkq[10][0] */ 3,
    /* rkq[10][1] */ 3,
    /* rkq[10][2] */ 3,
    /* rkq[11][0] */ 3,
    /* rkq[11][1] */ 3,
    /* rkq[11][2] */ 3,
    /* rkq[12][0] */ 3,
    /* rkq[12][1] */ 3,
    /* rkq[12][2] */ 3,
    /* riq[0][0] */ 3,
    /* riq[0][1] */ 3,
    /* riq[0][2] */ 3,
    /* riq[1][0] */ 3,
    /* riq[1][1] */ 3,
    /* riq[1][2] */ 3,
    /* riq[2][0] */ 3,
    /* riq[2][1] */ 3,
    /* riq[2][2] */ 3,
    /* riq[3][0] */ 3,
    /* riq[3][1] */ 3,
    /* riq[3][2] */ 3,
    /* riq[4][0] */ 3,
    /* riq[4][1] */ 3,
    /* riq[4][2] */ 3,
    /* riq[5][0] */ 3,
    /* riq[5][1] */ 3,
    /* riq[5][2] */ 3,
    /* riq[6][0] */ 3,
    /* riq[6][1] */ 3,
    /* riq[6][2] */ 3,
    /* riq[7][0] */ 3,
    /* riq[7][1] */ 3,
    /* riq[7][2] */ 3,
    /* riq[8][0] */ 3,
    /* riq[8][1] */ 3,
    /* riq[8][2] */ 3,
    /* riq[9][0] */ 3,
    /* riq[9][1] */ 3,
    /* riq[9][2] */ 3,
    /* riq[10][0] */ 3,
    /* riq[10][1] */ 3,
    /* riq[10][2] */ 3,
    /* riq[11][0] */ 3,
    /* riq[11][1] */ 3,
    /* riq[11][2] */ 3,
    /* riq[12][0] */ 3,
    /* riq[12][1] */ 3,
    /* riq[12][2] */ 3,
    /* presq[0] */ 0,
    /* presq[1] */ 0,
    /* presq[2] */ 0,
    /* presq[3] */ 0,
    /* presq[4] */ 0,
    /* presq[5] */ 0,
    /* presq[6] */ 0,
    /* presq[7] */ 0,
    /* presq[8] */ 0,
    /* presq[9] */ 0,
    /* presq[10] */ 0,
    /* presq[11] */ 0,
    /* presq[12] */ 0,
    /* presq[13] */ 0,
    /* presq[14] */ 0,
    /* presq[15] */ 0,
    /* presq[16] */ 0,
    /* presq[17] */ 0,
    /* stabvelq */ 3,
    /* stabposq */ 3,

/* End of values from input file */

};
sdgstate_t sdgstate;
sdglhs_t sdglhs;
sdgrhs_t sdgrhs;
sdgtemp_t sdgtemp;


void sdinit(void)
{
/*
Initialization routine


 This routine must be called before the first call to sdstate(), after
 supplying values for any `?' parameters in the input.
*/
    double sumsq,norminv;
    int i,j,k;


/* Check that all `?' parameters have been assigned values */

    for (k = 0; k < 3; k++) {
        if (gravq[k] == 1) {
            sdseterr(7,25);
        }
    }
    for (k = 0; k < 13; k++) {
        if (mkq[k] == 1) {
            sdseterr(7,26);
        }
        for (i = 0; i < 3; i++) {
            if (rkq[k][i] == 1) {
                sdseterr(7,29);
            }
            if (riq[k][i] == 1) {
                sdseterr(7,30);
            }
            for (j = 0; j < 3; j++) {
                if (ikq[k][i][j] == 1) {
                    sdseterr(7,27);
                }
            }
        }
    }
    for (k = 0; k < 18; k++) {
        for (i = 0; i < 3; i++) {
            if (pinq[k][i] == 1) {
                sdseterr(7,28);
            }
        }
    }

/* Normalize pin vectors if necessary */

    sumsq = ((pin[0][2]*pin[0][2])+((pin[0][0]*pin[0][0])+(pin[0][1]*pin[0][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[0][0] = (norminv*pin[0][0]);
    pin[0][1] = (norminv*pin[0][1]);
    pin[0][2] = (norminv*pin[0][2]);
    sumsq = ((pin[1][2]*pin[1][2])+((pin[1][0]*pin[1][0])+(pin[1][1]*pin[1][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[1][0] = (norminv*pin[1][0]);
    pin[1][1] = (norminv*pin[1][1]);
    pin[1][2] = (norminv*pin[1][2]);
    sumsq = ((pin[2][2]*pin[2][2])+((pin[2][0]*pin[2][0])+(pin[2][1]*pin[2][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[2][0] = (norminv*pin[2][0]);
    pin[2][1] = (norminv*pin[2][1]);
    pin[2][2] = (norminv*pin[2][2]);
    sumsq = ((pin[6][2]*pin[6][2])+((pin[6][0]*pin[6][0])+(pin[6][1]*pin[6][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[6][0] = (norminv*pin[6][0]);
    pin[6][1] = (norminv*pin[6][1]);
    pin[6][2] = (norminv*pin[6][2]);
    sumsq = ((pin[7][2]*pin[7][2])+((pin[7][0]*pin[7][0])+(pin[7][1]*pin[7][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[7][0] = (norminv*pin[7][0]);
    pin[7][1] = (norminv*pin[7][1]);
    pin[7][2] = (norminv*pin[7][2]);
    sumsq = ((pin[8][2]*pin[8][2])+((pin[8][0]*pin[8][0])+(pin[8][1]*pin[8][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[8][0] = (norminv*pin[8][0]);
    pin[8][1] = (norminv*pin[8][1]);
    pin[8][2] = (norminv*pin[8][2]);
    sumsq = ((pin[9][2]*pin[9][2])+((pin[9][0]*pin[9][0])+(pin[9][1]*pin[9][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[9][0] = (norminv*pin[9][0]);
    pin[9][1] = (norminv*pin[9][1]);
    pin[9][2] = (norminv*pin[9][2]);
    sumsq = ((pin[10][2]*pin[10][2])+((pin[10][0]*pin[10][0])+(pin[10][1]*
      pin[10][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[10][0] = (norminv*pin[10][0]);
    pin[10][1] = (norminv*pin[10][1]);
    pin[10][2] = (norminv*pin[10][2]);
    sumsq = ((pin[11][2]*pin[11][2])+((pin[11][0]*pin[11][0])+(pin[11][1]*
      pin[11][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[11][0] = (norminv*pin[11][0]);
    pin[11][1] = (norminv*pin[11][1]);
    pin[11][2] = (norminv*pin[11][2]);
    sumsq = ((pin[12][2]*pin[12][2])+((pin[12][0]*pin[12][0])+(pin[12][1]*
      pin[12][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[12][0] = (norminv*pin[12][0]);
    pin[12][1] = (norminv*pin[12][1]);
    pin[12][2] = (norminv*pin[12][2]);
    sumsq = ((pin[13][2]*pin[13][2])+((pin[13][0]*pin[13][0])+(pin[13][1]*
      pin[13][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[13][0] = (norminv*pin[13][0]);
    pin[13][1] = (norminv*pin[13][1]);
    pin[13][2] = (norminv*pin[13][2]);
    sumsq = ((pin[14][2]*pin[14][2])+((pin[14][0]*pin[14][0])+(pin[14][1]*
      pin[14][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[14][0] = (norminv*pin[14][0]);
    pin[14][1] = (norminv*pin[14][1]);
    pin[14][2] = (norminv*pin[14][2]);
    sumsq = ((pin[15][2]*pin[15][2])+((pin[15][0]*pin[15][0])+(pin[15][1]*
      pin[15][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[15][0] = (norminv*pin[15][0]);
    pin[15][1] = (norminv*pin[15][1]);
    pin[15][2] = (norminv*pin[15][2]);
    sumsq = ((pin[16][2]*pin[16][2])+((pin[16][0]*pin[16][0])+(pin[16][1]*
      pin[16][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[16][0] = (norminv*pin[16][0]);
    pin[16][1] = (norminv*pin[16][1]);
    pin[16][2] = (norminv*pin[16][2]);
    sumsq = ((pin[17][2]*pin[17][2])+((pin[17][0]*pin[17][0])+(pin[17][1]*
      pin[17][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        sdseterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[17][0] = (norminv*pin[17][0]);
    pin[17][1] = (norminv*pin[17][1]);
    pin[17][2] = (norminv*pin[17][2]);

/* Zero out Vpk and Wpk */

    for (i = 0; i < 18; i++) {
        for (j = i; j <= 17; j++) {
            for (k = 0; k < 3; k++) {
                Vpk[i][j][k] = 0.;
                Wpk[i][j][k] = 0.;
            }
        }
    }

/* Compute pseudobody-related constants */

    rcom[0][0] = 0.;
    rcom[0][1] = 0.;
    rcom[0][2] = 0.;
    rcom[1][0] = 0.;
    rcom[1][1] = 0.;
    rcom[1][2] = 0.;
    rcom[2][0] = 0.;
    rcom[2][1] = 0.;
    rcom[2][2] = 0.;
    rcom[3][0] = 0.;
    rcom[3][1] = 0.;
    rcom[3][2] = 0.;
    rcom[4][0] = 0.;
    rcom[4][1] = 0.;
    rcom[4][2] = 0.;
    rcom[5][0] = 0.;
    rcom[5][1] = 0.;
    rcom[5][2] = 0.;
    rcom[6][0] = 0.;
    rcom[6][1] = 0.;
    rcom[6][2] = 0.;
    rcom[7][0] = 0.;
    rcom[7][1] = 0.;
    rcom[7][2] = 0.;
    rcom[8][0] = 0.;
    rcom[8][1] = 0.;
    rcom[8][2] = 0.;
    rcom[9][0] = 0.;
    rcom[9][1] = 0.;
    rcom[9][2] = 0.;
    rcom[10][0] = 0.;
    rcom[10][1] = 0.;
    rcom[10][2] = 0.;
    rcom[11][0] = 0.;
    rcom[11][1] = 0.;
    rcom[11][2] = 0.;
    rcom[12][0] = 0.;
    rcom[12][1] = 0.;
    rcom[12][2] = 0.;
    rkWkk[6][0] = ((pin[6][2]*rk[1][1])-(pin[6][1]*rk[1][2]));
    rkWkk[6][1] = ((pin[6][0]*rk[1][2])-(pin[6][2]*rk[1][0]));
    rkWkk[6][2] = ((pin[6][1]*rk[1][0])-(pin[6][0]*rk[1][1]));
    rkWkk[7][0] = ((pin[7][2]*rk[2][1])-(pin[7][1]*rk[2][2]));
    rkWkk[7][1] = ((pin[7][0]*rk[2][2])-(pin[7][2]*rk[2][0]));
    rkWkk[7][2] = ((pin[7][1]*rk[2][0])-(pin[7][0]*rk[2][1]));
    rkWkk[8][0] = ((pin[8][2]*rk[3][1])-(pin[8][1]*rk[3][2]));
    rkWkk[8][1] = ((pin[8][0]*rk[3][2])-(pin[8][2]*rk[3][0]));
    rkWkk[8][2] = ((pin[8][1]*rk[3][0])-(pin[8][0]*rk[3][1]));
    rkWkk[9][0] = ((pin[9][2]*rk[4][1])-(pin[9][1]*rk[4][2]));
    rkWkk[9][1] = ((pin[9][0]*rk[4][2])-(pin[9][2]*rk[4][0]));
    rkWkk[9][2] = ((pin[9][1]*rk[4][0])-(pin[9][0]*rk[4][1]));
    rkWkk[10][0] = ((pin[10][2]*rk[5][1])-(pin[10][1]*rk[5][2]));
    rkWkk[10][1] = ((pin[10][0]*rk[5][2])-(pin[10][2]*rk[5][0]));
    rkWkk[10][2] = ((pin[10][1]*rk[5][0])-(pin[10][0]*rk[5][1]));
    rkWkk[11][0] = ((pin[11][2]*rk[6][1])-(pin[11][1]*rk[6][2]));
    rkWkk[11][1] = ((pin[11][0]*rk[6][2])-(pin[11][2]*rk[6][0]));
    rkWkk[11][2] = ((pin[11][1]*rk[6][0])-(pin[11][0]*rk[6][1]));
    rkWkk[12][0] = ((pin[12][2]*rk[7][1])-(pin[12][1]*rk[7][2]));
    rkWkk[12][1] = ((pin[12][0]*rk[7][2])-(pin[12][2]*rk[7][0]));
    rkWkk[12][2] = ((pin[12][1]*rk[7][0])-(pin[12][0]*rk[7][1]));
    rkWkk[13][0] = ((pin[13][2]*rk[8][1])-(pin[13][1]*rk[8][2]));
    rkWkk[13][1] = ((pin[13][0]*rk[8][2])-(pin[13][2]*rk[8][0]));
    rkWkk[13][2] = ((pin[13][1]*rk[8][0])-(pin[13][0]*rk[8][1]));
    rkWkk[14][0] = ((pin[14][2]*rk[9][1])-(pin[14][1]*rk[9][2]));
    rkWkk[14][1] = ((pin[14][0]*rk[9][2])-(pin[14][2]*rk[9][0]));
    rkWkk[14][2] = ((pin[14][1]*rk[9][0])-(pin[14][0]*rk[9][1]));
    rkWkk[15][0] = ((pin[15][2]*rk[10][1])-(pin[15][1]*rk[10][2]));
    rkWkk[15][1] = ((pin[15][0]*rk[10][2])-(pin[15][2]*rk[10][0]));
    rkWkk[15][2] = ((pin[15][1]*rk[10][0])-(pin[15][0]*rk[10][1]));
    rkWkk[16][0] = ((pin[16][2]*rk[11][1])-(pin[16][1]*rk[11][2]));
    rkWkk[16][1] = ((pin[16][0]*rk[11][2])-(pin[16][2]*rk[11][0]));
    rkWkk[16][2] = ((pin[16][1]*rk[11][0])-(pin[16][0]*rk[11][1]));
    rkWkk[17][0] = ((pin[17][2]*rk[12][1])-(pin[17][1]*rk[12][2]));
    rkWkk[17][1] = ((pin[17][0]*rk[12][2])-(pin[17][2]*rk[12][0]));
    rkWkk[17][2] = ((pin[17][1]*rk[12][0])-(pin[17][0]*rk[12][1]));
    dik[6][0] = (ri[1][0]-rk[0][0]);
    dik[6][1] = (ri[1][1]-rk[0][1]);
    dik[6][2] = (ri[1][2]-rk[0][2]);
    dik[7][0] = (ri[2][0]-rk[1][0]);
    dik[7][1] = (ri[2][1]-rk[1][1]);
    dik[7][2] = (ri[2][2]-rk[1][2]);
    dik[8][0] = (ri[3][0]-rk[2][0]);
    dik[8][1] = (ri[3][1]-rk[2][1]);
    dik[8][2] = (ri[3][2]-rk[2][2]);
    dik[9][0] = (ri[4][0]-rk[0][0]);
    dik[9][1] = (ri[4][1]-rk[0][1]);
    dik[9][2] = (ri[4][2]-rk[0][2]);
    dik[10][0] = (ri[5][0]-rk[4][0]);
    dik[10][1] = (ri[5][1]-rk[4][1]);
    dik[10][2] = (ri[5][2]-rk[4][2]);
    dik[11][0] = (ri[6][0]-rk[5][0]);
    dik[11][1] = (ri[6][1]-rk[5][1]);
    dik[11][2] = (ri[6][2]-rk[5][2]);
    dik[12][0] = (ri[7][0]-rk[0][0]);
    dik[12][1] = (ri[7][1]-rk[0][1]);
    dik[12][2] = (ri[7][2]-rk[0][2]);
    dik[13][0] = (ri[8][0]-rk[7][0]);
    dik[13][1] = (ri[8][1]-rk[7][1]);
    dik[13][2] = (ri[8][2]-rk[7][2]);
    dik[14][0] = (ri[9][0]-rk[8][0]);
    dik[14][1] = (ri[9][1]-rk[8][1]);
    dik[14][2] = (ri[9][2]-rk[8][2]);
    dik[15][0] = (ri[10][0]-rk[0][0]);
    dik[15][1] = (ri[10][1]-rk[0][1]);
    dik[15][2] = (ri[10][2]-rk[0][2]);
    dik[16][0] = (ri[11][0]-rk[10][0]);
    dik[16][1] = (ri[11][1]-rk[10][1]);
    dik[16][2] = (ri[11][2]-rk[10][2]);
    dik[17][0] = (ri[12][0]-rk[11][0]);
    dik[17][1] = (ri[12][1]-rk[11][1]);
    dik[17][2] = (ri[12][2]-rk[11][2]);

/* Compute mass properties-related constants */

    mtot = (mk[12]+(mk[11]+(mk[10]+(mk[9]+(mk[8]+(mk[7]+(mk[6]+(mk[5]+(mk[4]+(
      mk[3]+(mk[2]+(mk[0]+mk[1]))))))))))));
    mkrk[5][0][1] = -(mk[0]*rk[0][2]);
    mkrk[5][0][2] = (mk[0]*rk[0][1]);
    mkrk[5][1][0] = (mk[0]*rk[0][2]);
    mkrk[5][1][2] = -(mk[0]*rk[0][0]);
    mkrk[5][2][0] = -(mk[0]*rk[0][1]);
    mkrk[5][2][1] = (mk[0]*rk[0][0]);
    mkrk[6][0][1] = -(mk[1]*rk[1][2]);
    mkrk[6][0][2] = (mk[1]*rk[1][1]);
    mkrk[6][1][0] = (mk[1]*rk[1][2]);
    mkrk[6][1][2] = -(mk[1]*rk[1][0]);
    mkrk[6][2][0] = -(mk[1]*rk[1][1]);
    mkrk[6][2][1] = (mk[1]*rk[1][0]);
    mkrk[7][0][1] = -(mk[2]*rk[2][2]);
    mkrk[7][0][2] = (mk[2]*rk[2][1]);
    mkrk[7][1][0] = (mk[2]*rk[2][2]);
    mkrk[7][1][2] = -(mk[2]*rk[2][0]);
    mkrk[7][2][0] = -(mk[2]*rk[2][1]);
    mkrk[7][2][1] = (mk[2]*rk[2][0]);
    mkrk[8][0][1] = -(mk[3]*rk[3][2]);
    mkrk[8][0][2] = (mk[3]*rk[3][1]);
    mkrk[8][1][0] = (mk[3]*rk[3][2]);
    mkrk[8][1][2] = -(mk[3]*rk[3][0]);
    mkrk[8][2][0] = -(mk[3]*rk[3][1]);
    mkrk[8][2][1] = (mk[3]*rk[3][0]);
    mkrk[9][0][1] = -(mk[4]*rk[4][2]);
    mkrk[9][0][2] = (mk[4]*rk[4][1]);
    mkrk[9][1][0] = (mk[4]*rk[4][2]);
    mkrk[9][1][2] = -(mk[4]*rk[4][0]);
    mkrk[9][2][0] = -(mk[4]*rk[4][1]);
    mkrk[9][2][1] = (mk[4]*rk[4][0]);
    mkrk[10][0][1] = -(mk[5]*rk[5][2]);
    mkrk[10][0][2] = (mk[5]*rk[5][1]);
    mkrk[10][1][0] = (mk[5]*rk[5][2]);
    mkrk[10][1][2] = -(mk[5]*rk[5][0]);
    mkrk[10][2][0] = -(mk[5]*rk[5][1]);
    mkrk[10][2][1] = (mk[5]*rk[5][0]);
    mkrk[11][0][1] = -(mk[6]*rk[6][2]);
    mkrk[11][0][2] = (mk[6]*rk[6][1]);
    mkrk[11][1][0] = (mk[6]*rk[6][2]);
    mkrk[11][1][2] = -(mk[6]*rk[6][0]);
    mkrk[11][2][0] = -(mk[6]*rk[6][1]);
    mkrk[11][2][1] = (mk[6]*rk[6][0]);
    mkrk[12][0][1] = -(mk[7]*rk[7][2]);
    mkrk[12][0][2] = (mk[7]*rk[7][1]);
    mkrk[12][1][0] = (mk[7]*rk[7][2]);
    mkrk[12][1][2] = -(mk[7]*rk[7][0]);
    mkrk[12][2][0] = -(mk[7]*rk[7][1]);
    mkrk[12][2][1] = (mk[7]*rk[7][0]);
    mkrk[13][0][1] = -(mk[8]*rk[8][2]);
    mkrk[13][0][2] = (mk[8]*rk[8][1]);
    mkrk[13][1][0] = (mk[8]*rk[8][2]);
    mkrk[13][1][2] = -(mk[8]*rk[8][0]);
    mkrk[13][2][0] = -(mk[8]*rk[8][1]);
    mkrk[13][2][1] = (mk[8]*rk[8][0]);
    mkrk[14][0][1] = -(mk[9]*rk[9][2]);
    mkrk[14][0][2] = (mk[9]*rk[9][1]);
    mkrk[14][1][0] = (mk[9]*rk[9][2]);
    mkrk[14][1][2] = -(mk[9]*rk[9][0]);
    mkrk[14][2][0] = -(mk[9]*rk[9][1]);
    mkrk[14][2][1] = (mk[9]*rk[9][0]);
    mkrk[15][0][1] = -(mk[10]*rk[10][2]);
    mkrk[15][0][2] = (mk[10]*rk[10][1]);
    mkrk[15][1][0] = (mk[10]*rk[10][2]);
    mkrk[15][1][2] = -(mk[10]*rk[10][0]);
    mkrk[15][2][0] = -(mk[10]*rk[10][1]);
    mkrk[15][2][1] = (mk[10]*rk[10][0]);
    mkrk[16][0][1] = -(mk[11]*rk[11][2]);
    mkrk[16][0][2] = (mk[11]*rk[11][1]);
    mkrk[16][1][0] = (mk[11]*rk[11][2]);
    mkrk[16][1][2] = -(mk[11]*rk[11][0]);
    mkrk[16][2][0] = -(mk[11]*rk[11][1]);
    mkrk[16][2][1] = (mk[11]*rk[11][0]);
    mkrk[17][0][1] = -(mk[12]*rk[12][2]);
    mkrk[17][0][2] = (mk[12]*rk[12][1]);
    mkrk[17][1][0] = (mk[12]*rk[12][2]);
    mkrk[17][1][2] = -(mk[12]*rk[12][0]);
    mkrk[17][2][0] = -(mk[12]*rk[12][1]);
    mkrk[17][2][1] = (mk[12]*rk[12][0]);
    Iko[5][0][0] = (ik[0][0][0]-((mkrk[5][0][1]*rk[0][2])-(mkrk[5][0][2]*
      rk[0][1])));
    Iko[5][0][1] = (ik[0][0][1]-(mkrk[5][0][2]*rk[0][0]));
    Iko[5][0][2] = (ik[0][0][2]+(mkrk[5][0][1]*rk[0][0]));
    Iko[5][1][0] = (ik[0][1][0]+(mkrk[5][1][2]*rk[0][1]));
    Iko[5][1][1] = (ik[0][1][1]-((mkrk[5][1][2]*rk[0][0])-(mkrk[5][1][0]*
      rk[0][2])));
    Iko[5][1][2] = (ik[0][1][2]-(mkrk[5][1][0]*rk[0][1]));
    Iko[5][2][0] = (ik[0][2][0]-(mkrk[5][2][1]*rk[0][2]));
    Iko[5][2][1] = (ik[0][2][1]+(mkrk[5][2][0]*rk[0][2]));
    Iko[5][2][2] = (ik[0][2][2]-((mkrk[5][2][0]*rk[0][1])-(mkrk[5][2][1]*
      rk[0][0])));
    Iko[6][0][0] = (ik[1][0][0]-((mkrk[6][0][1]*rk[1][2])-(mkrk[6][0][2]*
      rk[1][1])));
    Iko[6][0][1] = (ik[1][0][1]-(mkrk[6][0][2]*rk[1][0]));
    Iko[6][0][2] = (ik[1][0][2]+(mkrk[6][0][1]*rk[1][0]));
    Iko[6][1][0] = (ik[1][1][0]+(mkrk[6][1][2]*rk[1][1]));
    Iko[6][1][1] = (ik[1][1][1]-((mkrk[6][1][2]*rk[1][0])-(mkrk[6][1][0]*
      rk[1][2])));
    Iko[6][1][2] = (ik[1][1][2]-(mkrk[6][1][0]*rk[1][1]));
    Iko[6][2][0] = (ik[1][2][0]-(mkrk[6][2][1]*rk[1][2]));
    Iko[6][2][1] = (ik[1][2][1]+(mkrk[6][2][0]*rk[1][2]));
    Iko[6][2][2] = (ik[1][2][2]-((mkrk[6][2][0]*rk[1][1])-(mkrk[6][2][1]*
      rk[1][0])));
    Iko[7][0][0] = (ik[2][0][0]-((mkrk[7][0][1]*rk[2][2])-(mkrk[7][0][2]*
      rk[2][1])));
    Iko[7][0][1] = (ik[2][0][1]-(mkrk[7][0][2]*rk[2][0]));
    Iko[7][0][2] = (ik[2][0][2]+(mkrk[7][0][1]*rk[2][0]));
    Iko[7][1][0] = (ik[2][1][0]+(mkrk[7][1][2]*rk[2][1]));
    Iko[7][1][1] = (ik[2][1][1]-((mkrk[7][1][2]*rk[2][0])-(mkrk[7][1][0]*
      rk[2][2])));
    Iko[7][1][2] = (ik[2][1][2]-(mkrk[7][1][0]*rk[2][1]));
    Iko[7][2][0] = (ik[2][2][0]-(mkrk[7][2][1]*rk[2][2]));
    Iko[7][2][1] = (ik[2][2][1]+(mkrk[7][2][0]*rk[2][2]));
    Iko[7][2][2] = (ik[2][2][2]-((mkrk[7][2][0]*rk[2][1])-(mkrk[7][2][1]*
      rk[2][0])));
    Iko[8][0][0] = (ik[3][0][0]-((mkrk[8][0][1]*rk[3][2])-(mkrk[8][0][2]*
      rk[3][1])));
    Iko[8][0][1] = (ik[3][0][1]-(mkrk[8][0][2]*rk[3][0]));
    Iko[8][0][2] = (ik[3][0][2]+(mkrk[8][0][1]*rk[3][0]));
    Iko[8][1][0] = (ik[3][1][0]+(mkrk[8][1][2]*rk[3][1]));
    Iko[8][1][1] = (ik[3][1][1]-((mkrk[8][1][2]*rk[3][0])-(mkrk[8][1][0]*
      rk[3][2])));
    Iko[8][1][2] = (ik[3][1][2]-(mkrk[8][1][0]*rk[3][1]));
    Iko[8][2][0] = (ik[3][2][0]-(mkrk[8][2][1]*rk[3][2]));
    Iko[8][2][1] = (ik[3][2][1]+(mkrk[8][2][0]*rk[3][2]));
    Iko[8][2][2] = (ik[3][2][2]-((mkrk[8][2][0]*rk[3][1])-(mkrk[8][2][1]*
      rk[3][0])));
    Iko[9][0][0] = (ik[4][0][0]-((mkrk[9][0][1]*rk[4][2])-(mkrk[9][0][2]*
      rk[4][1])));
    Iko[9][0][1] = (ik[4][0][1]-(mkrk[9][0][2]*rk[4][0]));
    Iko[9][0][2] = (ik[4][0][2]+(mkrk[9][0][1]*rk[4][0]));
    Iko[9][1][0] = (ik[4][1][0]+(mkrk[9][1][2]*rk[4][1]));
    Iko[9][1][1] = (ik[4][1][1]-((mkrk[9][1][2]*rk[4][0])-(mkrk[9][1][0]*
      rk[4][2])));
    Iko[9][1][2] = (ik[4][1][2]-(mkrk[9][1][0]*rk[4][1]));
    Iko[9][2][0] = (ik[4][2][0]-(mkrk[9][2][1]*rk[4][2]));
    Iko[9][2][1] = (ik[4][2][1]+(mkrk[9][2][0]*rk[4][2]));
    Iko[9][2][2] = (ik[4][2][2]-((mkrk[9][2][0]*rk[4][1])-(mkrk[9][2][1]*
      rk[4][0])));
    Iko[10][0][0] = (ik[5][0][0]-((mkrk[10][0][1]*rk[5][2])-(mkrk[10][0][2]*
      rk[5][1])));
    Iko[10][0][1] = (ik[5][0][1]-(mkrk[10][0][2]*rk[5][0]));
    Iko[10][0][2] = (ik[5][0][2]+(mkrk[10][0][1]*rk[5][0]));
    Iko[10][1][0] = (ik[5][1][0]+(mkrk[10][1][2]*rk[5][1]));
    Iko[10][1][1] = (ik[5][1][1]-((mkrk[10][1][2]*rk[5][0])-(mkrk[10][1][0]*
      rk[5][2])));
    Iko[10][1][2] = (ik[5][1][2]-(mkrk[10][1][0]*rk[5][1]));
    Iko[10][2][0] = (ik[5][2][0]-(mkrk[10][2][1]*rk[5][2]));
    Iko[10][2][1] = (ik[5][2][1]+(mkrk[10][2][0]*rk[5][2]));
    Iko[10][2][2] = (ik[5][2][2]-((mkrk[10][2][0]*rk[5][1])-(mkrk[10][2][1]*
      rk[5][0])));
    Iko[11][0][0] = (ik[6][0][0]-((mkrk[11][0][1]*rk[6][2])-(mkrk[11][0][2]*
      rk[6][1])));
    Iko[11][0][1] = (ik[6][0][1]-(mkrk[11][0][2]*rk[6][0]));
    Iko[11][0][2] = (ik[6][0][2]+(mkrk[11][0][1]*rk[6][0]));
    Iko[11][1][0] = (ik[6][1][0]+(mkrk[11][1][2]*rk[6][1]));
    Iko[11][1][1] = (ik[6][1][1]-((mkrk[11][1][2]*rk[6][0])-(mkrk[11][1][0]*
      rk[6][2])));
    Iko[11][1][2] = (ik[6][1][2]-(mkrk[11][1][0]*rk[6][1]));
    Iko[11][2][0] = (ik[6][2][0]-(mkrk[11][2][1]*rk[6][2]));
    Iko[11][2][1] = (ik[6][2][1]+(mkrk[11][2][0]*rk[6][2]));
    Iko[11][2][2] = (ik[6][2][2]-((mkrk[11][2][0]*rk[6][1])-(mkrk[11][2][1]*
      rk[6][0])));
    Iko[12][0][0] = (ik[7][0][0]-((mkrk[12][0][1]*rk[7][2])-(mkrk[12][0][2]*
      rk[7][1])));
    Iko[12][0][1] = (ik[7][0][1]-(mkrk[12][0][2]*rk[7][0]));
    Iko[12][0][2] = (ik[7][0][2]+(mkrk[12][0][1]*rk[7][0]));
    Iko[12][1][0] = (ik[7][1][0]+(mkrk[12][1][2]*rk[7][1]));
    Iko[12][1][1] = (ik[7][1][1]-((mkrk[12][1][2]*rk[7][0])-(mkrk[12][1][0]*
      rk[7][2])));
    Iko[12][1][2] = (ik[7][1][2]-(mkrk[12][1][0]*rk[7][1]));
    Iko[12][2][0] = (ik[7][2][0]-(mkrk[12][2][1]*rk[7][2]));
    Iko[12][2][1] = (ik[7][2][1]+(mkrk[12][2][0]*rk[7][2]));
    Iko[12][2][2] = (ik[7][2][2]-((mkrk[12][2][0]*rk[7][1])-(mkrk[12][2][1]*
      rk[7][0])));
    Iko[13][0][0] = (ik[8][0][0]-((mkrk[13][0][1]*rk[8][2])-(mkrk[13][0][2]*
      rk[8][1])));
    Iko[13][0][1] = (ik[8][0][1]-(mkrk[13][0][2]*rk[8][0]));
    Iko[13][0][2] = (ik[8][0][2]+(mkrk[13][0][1]*rk[8][0]));
    Iko[13][1][0] = (ik[8][1][0]+(mkrk[13][1][2]*rk[8][1]));
    Iko[13][1][1] = (ik[8][1][1]-((mkrk[13][1][2]*rk[8][0])-(mkrk[13][1][0]*
      rk[8][2])));
    Iko[13][1][2] = (ik[8][1][2]-(mkrk[13][1][0]*rk[8][1]));
    Iko[13][2][0] = (ik[8][2][0]-(mkrk[13][2][1]*rk[8][2]));
    Iko[13][2][1] = (ik[8][2][1]+(mkrk[13][2][0]*rk[8][2]));
    Iko[13][2][2] = (ik[8][2][2]-((mkrk[13][2][0]*rk[8][1])-(mkrk[13][2][1]*
      rk[8][0])));
    Iko[14][0][0] = (ik[9][0][0]-((mkrk[14][0][1]*rk[9][2])-(mkrk[14][0][2]*
      rk[9][1])));
    Iko[14][0][1] = (ik[9][0][1]-(mkrk[14][0][2]*rk[9][0]));
    Iko[14][0][2] = (ik[9][0][2]+(mkrk[14][0][1]*rk[9][0]));
    Iko[14][1][0] = (ik[9][1][0]+(mkrk[14][1][2]*rk[9][1]));
    Iko[14][1][1] = (ik[9][1][1]-((mkrk[14][1][2]*rk[9][0])-(mkrk[14][1][0]*
      rk[9][2])));
    Iko[14][1][2] = (ik[9][1][2]-(mkrk[14][1][0]*rk[9][1]));
    Iko[14][2][0] = (ik[9][2][0]-(mkrk[14][2][1]*rk[9][2]));
    Iko[14][2][1] = (ik[9][2][1]+(mkrk[14][2][0]*rk[9][2]));
    Iko[14][2][2] = (ik[9][2][2]-((mkrk[14][2][0]*rk[9][1])-(mkrk[14][2][1]*
      rk[9][0])));
    Iko[15][0][0] = (ik[10][0][0]-((mkrk[15][0][1]*rk[10][2])-(mkrk[15][0][2]*
      rk[10][1])));
    Iko[15][0][1] = (ik[10][0][1]-(mkrk[15][0][2]*rk[10][0]));
    Iko[15][0][2] = (ik[10][0][2]+(mkrk[15][0][1]*rk[10][0]));
    Iko[15][1][0] = (ik[10][1][0]+(mkrk[15][1][2]*rk[10][1]));
    Iko[15][1][1] = (ik[10][1][1]-((mkrk[15][1][2]*rk[10][0])-(mkrk[15][1][0]*
      rk[10][2])));
    Iko[15][1][2] = (ik[10][1][2]-(mkrk[15][1][0]*rk[10][1]));
    Iko[15][2][0] = (ik[10][2][0]-(mkrk[15][2][1]*rk[10][2]));
    Iko[15][2][1] = (ik[10][2][1]+(mkrk[15][2][0]*rk[10][2]));
    Iko[15][2][2] = (ik[10][2][2]-((mkrk[15][2][0]*rk[10][1])-(mkrk[15][2][1]*
      rk[10][0])));
    Iko[16][0][0] = (ik[11][0][0]-((mkrk[16][0][1]*rk[11][2])-(mkrk[16][0][2]*
      rk[11][1])));
    Iko[16][0][1] = (ik[11][0][1]-(mkrk[16][0][2]*rk[11][0]));
    Iko[16][0][2] = (ik[11][0][2]+(mkrk[16][0][1]*rk[11][0]));
    Iko[16][1][0] = (ik[11][1][0]+(mkrk[16][1][2]*rk[11][1]));
    Iko[16][1][1] = (ik[11][1][1]-((mkrk[16][1][2]*rk[11][0])-(mkrk[16][1][0]*
      rk[11][2])));
    Iko[16][1][2] = (ik[11][1][2]-(mkrk[16][1][0]*rk[11][1]));
    Iko[16][2][0] = (ik[11][2][0]-(mkrk[16][2][1]*rk[11][2]));
    Iko[16][2][1] = (ik[11][2][1]+(mkrk[16][2][0]*rk[11][2]));
    Iko[16][2][2] = (ik[11][2][2]-((mkrk[16][2][0]*rk[11][1])-(mkrk[16][2][1]*
      rk[11][0])));
    Iko[17][0][0] = (ik[12][0][0]-((mkrk[17][0][1]*rk[12][2])-(mkrk[17][0][2]*
      rk[12][1])));
    Iko[17][0][1] = (ik[12][0][1]-(mkrk[17][0][2]*rk[12][0]));
    Iko[17][0][2] = (ik[12][0][2]+(mkrk[17][0][1]*rk[12][0]));
    Iko[17][1][0] = (ik[12][1][0]+(mkrk[17][1][2]*rk[12][1]));
    Iko[17][1][1] = (ik[12][1][1]-((mkrk[17][1][2]*rk[12][0])-(mkrk[17][1][0]*
      rk[12][2])));
    Iko[17][1][2] = (ik[12][1][2]-(mkrk[17][1][0]*rk[12][1]));
    Iko[17][2][0] = (ik[12][2][0]-(mkrk[17][2][1]*rk[12][2]));
    Iko[17][2][1] = (ik[12][2][1]+(mkrk[17][2][0]*rk[12][2]));
    Iko[17][2][2] = (ik[12][2][2]-((mkrk[17][2][0]*rk[12][1])-(mkrk[17][2][1]*
      rk[12][0])));
    sdserialno(&i);
    if (i != 30123) {
        sdseterr(7,41);
    }
    roustate = 1;
}

/* Convert state to form using 1-2-3 Euler angles for ball joints. */

void sdst2ang(double st[19],
    double stang[18])
{
    int i;
    double dc[3][3];

    for (i = 0; i < 18; i++) {
        stang[i] = st[i];
    }
    sdquat2dc(st[3],st[4],st[5],st[18],dc);
    sddc2ang(dc,&stang[3],&stang[4],&stang[5]);
}

/* Convert 1-2-3 form of state back to Euler parameters for ball joints. */

void sdang2st(double stang[18],
    double st[19])
{
    int i;
    double dc[3][3];

    for (i = 0; i < 18; i++) {
        st[i] = stang[i];
    }
    sdang2dc(stang[3],stang[4],stang[5],dc);
    sddc2quat(dc,&st[3],&st[4],&st[5],&st[18]);
}

/* Normalize Euler parameters in state. */

void sdnrmsterr(double st[19],
    double normst[19],
    int routine)
{
    int i;
    double norm;

    for (i = 0; i < 19; i++) {
        normst[i] = st[i];
    }
    norm = sqrt(st[3]*st[3]+st[4]*st[4]+st[5]*st[5]+st[18]*st[18]);
    if (routine != 0) {
        if ((norm < .9) || (norm > 1.1)) {
            sdseterr(routine,14);
        }
    }
    if (norm == 0.) {
        normst[18] = 1.;
        norm = 1.;
    }
    norm = 1./norm;
    normst[3] = normst[3]*norm;
    normst[4] = normst[4]*norm;
    normst[5] = normst[5]*norm;
    normst[18] = normst[18]*norm;
}

void sdnormst(double st[19],
    double normst[19])
{

    sdnrmsterr(st,normst,0);
}

void sdstate(double timein,
    double qin[19],
    double uin[18])
{
/*
Compute kinematic information and store it in sdgstate.

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
    int i,j,qchg,uchg;
    double ee,stab;

    if ((roustate != 1) && (roustate != 2) && (roustate != 3)) {
        sdseterr(8,22);
        return;
    }
    if (roustate == 1) {
        for (i = 0; i < 18; i++) {
            if (presq[i] == 1) {
                sdseterr(8,31);
            }
        }
    }
/*
See if time or any qs have changed since last call
*/
    if ((roustate != 1) && (timein == curtim)) {
        qchg = 0;
        for (i = 0; i < 19; i++) {
            if (qin[i] != q[i]) {
                qchg = 1;
                break;
            }
        }
    } else {
        qchg = 1;
    }
/*
If time and qs are unchanged, check us
*/
    if (qchg == 0) {
        uchg = 0;
        for (i = 0; i < 18; i++) {
            if (uin[i] != u[i]) {
                uchg = 1;
                break;
            }
        }
    } else {
        uchg = 1;
    }
    curtim = timein;
    roustate = 2;
    if (qchg == 0) {
        goto skipqs;
    }
/*
Position-related variables need to be computed
*/
    vpkflg = 0;
    mmflg = 0;
    mmlduflg = 0;
    wwflg = 0;
    for (i = 0; i < 19; i++) {
        q[i] = qin[i];
    }
/*
Normalize Euler parameters in state
*/
    sdnrmsterr(q,qn,8);
/*
Compute sines and cosines of q
*/
    s6 = sin(q[6]);
    c6 = cos(q[6]);
    s7 = sin(q[7]);
    c7 = cos(q[7]);
    s8 = sin(q[8]);
    c8 = cos(q[8]);
    s9 = sin(q[9]);
    c9 = cos(q[9]);
    s10 = sin(q[10]);
    c10 = cos(q[10]);
    s11 = sin(q[11]);
    c11 = cos(q[11]);
    s12 = sin(q[12]);
    c12 = cos(q[12]);
    s13 = sin(q[13]);
    c13 = cos(q[13]);
    s14 = sin(q[14]);
    c14 = cos(q[14]);
    s15 = sin(q[15]);
    c15 = cos(q[15]);
    s16 = sin(q[16]);
    c16 = cos(q[16]);
    s17 = sin(q[17]);
    c17 = cos(q[17]);
/*
Compute across-axis direction cosines Cik
*/
    Cik[3][0][0] = (1.-(2.*((qn[4]*qn[4])+(qn[5]*qn[5]))));
    Cik[3][0][1] = (2.*((qn[3]*qn[4])-(qn[5]*qn[18])));
    Cik[3][0][2] = (2.*((qn[3]*qn[5])+(qn[4]*qn[18])));
    Cik[3][1][0] = (2.*((qn[3]*qn[4])+(qn[5]*qn[18])));
    Cik[3][1][1] = (1.-(2.*((qn[3]*qn[3])+(qn[5]*qn[5]))));
    Cik[3][1][2] = (2.*((qn[4]*qn[5])-(qn[3]*qn[18])));
    Cik[3][2][0] = (2.*((qn[3]*qn[5])-(qn[4]*qn[18])));
    Cik[3][2][1] = (2.*((qn[3]*qn[18])+(qn[4]*qn[5])));
    Cik[3][2][2] = (1.-(2.*((qn[3]*qn[3])+(qn[4]*qn[4]))));
    Cik[6][0][0] = ((pin[6][0]*pin[6][0])+(c6*(1.-(pin[6][0]*pin[6][0]))));
    Cik[6][0][1] = (((pin[6][0]*pin[6][1])-(pin[6][2]*s6))-(c6*(pin[6][0]*
      pin[6][1])));
    Cik[6][0][2] = (((pin[6][0]*pin[6][2])+(pin[6][1]*s6))-(c6*(pin[6][0]*
      pin[6][2])));
    Cik[6][1][0] = (((pin[6][0]*pin[6][1])+(pin[6][2]*s6))-(c6*(pin[6][0]*
      pin[6][1])));
    Cik[6][1][1] = ((pin[6][1]*pin[6][1])+(c6*(1.-(pin[6][1]*pin[6][1]))));
    Cik[6][1][2] = (((pin[6][1]*pin[6][2])-(pin[6][0]*s6))-(c6*(pin[6][1]*
      pin[6][2])));
    Cik[6][2][0] = (((pin[6][0]*pin[6][2])-(pin[6][1]*s6))-(c6*(pin[6][0]*
      pin[6][2])));
    Cik[6][2][1] = (((pin[6][0]*s6)+(pin[6][1]*pin[6][2]))-(c6*(pin[6][1]*
      pin[6][2])));
    Cik[6][2][2] = ((pin[6][2]*pin[6][2])+(c6*(1.-(pin[6][2]*pin[6][2]))));
    Cik[7][0][0] = ((pin[7][0]*pin[7][0])+(c7*(1.-(pin[7][0]*pin[7][0]))));
    Cik[7][0][1] = (((pin[7][0]*pin[7][1])-(pin[7][2]*s7))-(c7*(pin[7][0]*
      pin[7][1])));
    Cik[7][0][2] = (((pin[7][0]*pin[7][2])+(pin[7][1]*s7))-(c7*(pin[7][0]*
      pin[7][2])));
    Cik[7][1][0] = (((pin[7][0]*pin[7][1])+(pin[7][2]*s7))-(c7*(pin[7][0]*
      pin[7][1])));
    Cik[7][1][1] = ((pin[7][1]*pin[7][1])+(c7*(1.-(pin[7][1]*pin[7][1]))));
    Cik[7][1][2] = (((pin[7][1]*pin[7][2])-(pin[7][0]*s7))-(c7*(pin[7][1]*
      pin[7][2])));
    Cik[7][2][0] = (((pin[7][0]*pin[7][2])-(pin[7][1]*s7))-(c7*(pin[7][0]*
      pin[7][2])));
    Cik[7][2][1] = (((pin[7][0]*s7)+(pin[7][1]*pin[7][2]))-(c7*(pin[7][1]*
      pin[7][2])));
    Cik[7][2][2] = ((pin[7][2]*pin[7][2])+(c7*(1.-(pin[7][2]*pin[7][2]))));
    Cik[8][0][0] = ((pin[8][0]*pin[8][0])+(c8*(1.-(pin[8][0]*pin[8][0]))));
    Cik[8][0][1] = (((pin[8][0]*pin[8][1])-(pin[8][2]*s8))-(c8*(pin[8][0]*
      pin[8][1])));
    Cik[8][0][2] = (((pin[8][0]*pin[8][2])+(pin[8][1]*s8))-(c8*(pin[8][0]*
      pin[8][2])));
    Cik[8][1][0] = (((pin[8][0]*pin[8][1])+(pin[8][2]*s8))-(c8*(pin[8][0]*
      pin[8][1])));
    Cik[8][1][1] = ((pin[8][1]*pin[8][1])+(c8*(1.-(pin[8][1]*pin[8][1]))));
    Cik[8][1][2] = (((pin[8][1]*pin[8][2])-(pin[8][0]*s8))-(c8*(pin[8][1]*
      pin[8][2])));
    Cik[8][2][0] = (((pin[8][0]*pin[8][2])-(pin[8][1]*s8))-(c8*(pin[8][0]*
      pin[8][2])));
    Cik[8][2][1] = (((pin[8][0]*s8)+(pin[8][1]*pin[8][2]))-(c8*(pin[8][1]*
      pin[8][2])));
    Cik[8][2][2] = ((pin[8][2]*pin[8][2])+(c8*(1.-(pin[8][2]*pin[8][2]))));
    Cik[9][0][0] = ((pin[9][0]*pin[9][0])+(c9*(1.-(pin[9][0]*pin[9][0]))));
    Cik[9][0][1] = (((pin[9][0]*pin[9][1])-(pin[9][2]*s9))-(c9*(pin[9][0]*
      pin[9][1])));
    Cik[9][0][2] = (((pin[9][0]*pin[9][2])+(pin[9][1]*s9))-(c9*(pin[9][0]*
      pin[9][2])));
    Cik[9][1][0] = (((pin[9][0]*pin[9][1])+(pin[9][2]*s9))-(c9*(pin[9][0]*
      pin[9][1])));
    Cik[9][1][1] = ((pin[9][1]*pin[9][1])+(c9*(1.-(pin[9][1]*pin[9][1]))));
    Cik[9][1][2] = (((pin[9][1]*pin[9][2])-(pin[9][0]*s9))-(c9*(pin[9][1]*
      pin[9][2])));
    Cik[9][2][0] = (((pin[9][0]*pin[9][2])-(pin[9][1]*s9))-(c9*(pin[9][0]*
      pin[9][2])));
    Cik[9][2][1] = (((pin[9][0]*s9)+(pin[9][1]*pin[9][2]))-(c9*(pin[9][1]*
      pin[9][2])));
    Cik[9][2][2] = ((pin[9][2]*pin[9][2])+(c9*(1.-(pin[9][2]*pin[9][2]))));
    Cik[10][0][0] = ((pin[10][0]*pin[10][0])+(c10*(1.-(pin[10][0]*pin[10][0]))))
      ;
    Cik[10][0][1] = (((pin[10][0]*pin[10][1])-(pin[10][2]*s10))-(c10*(pin[10][0]
      *pin[10][1])));
    Cik[10][0][2] = (((pin[10][0]*pin[10][2])+(pin[10][1]*s10))-(c10*(pin[10][0]
      *pin[10][2])));
    Cik[10][1][0] = (((pin[10][0]*pin[10][1])+(pin[10][2]*s10))-(c10*(pin[10][0]
      *pin[10][1])));
    Cik[10][1][1] = ((pin[10][1]*pin[10][1])+(c10*(1.-(pin[10][1]*pin[10][1]))))
      ;
    Cik[10][1][2] = (((pin[10][1]*pin[10][2])-(pin[10][0]*s10))-(c10*(pin[10][1]
      *pin[10][2])));
    Cik[10][2][0] = (((pin[10][0]*pin[10][2])-(pin[10][1]*s10))-(c10*(pin[10][0]
      *pin[10][2])));
    Cik[10][2][1] = (((pin[10][0]*s10)+(pin[10][1]*pin[10][2]))-(c10*(pin[10][1]
      *pin[10][2])));
    Cik[10][2][2] = ((pin[10][2]*pin[10][2])+(c10*(1.-(pin[10][2]*pin[10][2]))))
      ;
    Cik[11][0][0] = ((pin[11][0]*pin[11][0])+(c11*(1.-(pin[11][0]*pin[11][0]))))
      ;
    Cik[11][0][1] = (((pin[11][0]*pin[11][1])-(pin[11][2]*s11))-(c11*(pin[11][0]
      *pin[11][1])));
    Cik[11][0][2] = (((pin[11][0]*pin[11][2])+(pin[11][1]*s11))-(c11*(pin[11][0]
      *pin[11][2])));
    Cik[11][1][0] = (((pin[11][0]*pin[11][1])+(pin[11][2]*s11))-(c11*(pin[11][0]
      *pin[11][1])));
    Cik[11][1][1] = ((pin[11][1]*pin[11][1])+(c11*(1.-(pin[11][1]*pin[11][1]))))
      ;
    Cik[11][1][2] = (((pin[11][1]*pin[11][2])-(pin[11][0]*s11))-(c11*(pin[11][1]
      *pin[11][2])));
    Cik[11][2][0] = (((pin[11][0]*pin[11][2])-(pin[11][1]*s11))-(c11*(pin[11][0]
      *pin[11][2])));
    Cik[11][2][1] = (((pin[11][0]*s11)+(pin[11][1]*pin[11][2]))-(c11*(pin[11][1]
      *pin[11][2])));
    Cik[11][2][2] = ((pin[11][2]*pin[11][2])+(c11*(1.-(pin[11][2]*pin[11][2]))))
      ;
    Cik[12][0][0] = ((pin[12][0]*pin[12][0])+(c12*(1.-(pin[12][0]*pin[12][0]))))
      ;
    Cik[12][0][1] = (((pin[12][0]*pin[12][1])-(pin[12][2]*s12))-(c12*(pin[12][0]
      *pin[12][1])));
    Cik[12][0][2] = (((pin[12][0]*pin[12][2])+(pin[12][1]*s12))-(c12*(pin[12][0]
      *pin[12][2])));
    Cik[12][1][0] = (((pin[12][0]*pin[12][1])+(pin[12][2]*s12))-(c12*(pin[12][0]
      *pin[12][1])));
    Cik[12][1][1] = ((pin[12][1]*pin[12][1])+(c12*(1.-(pin[12][1]*pin[12][1]))))
      ;
    Cik[12][1][2] = (((pin[12][1]*pin[12][2])-(pin[12][0]*s12))-(c12*(pin[12][1]
      *pin[12][2])));
    Cik[12][2][0] = (((pin[12][0]*pin[12][2])-(pin[12][1]*s12))-(c12*(pin[12][0]
      *pin[12][2])));
    Cik[12][2][1] = (((pin[12][0]*s12)+(pin[12][1]*pin[12][2]))-(c12*(pin[12][1]
      *pin[12][2])));
    Cik[12][2][2] = ((pin[12][2]*pin[12][2])+(c12*(1.-(pin[12][2]*pin[12][2]))))
      ;
    Cik[13][0][0] = ((pin[13][0]*pin[13][0])+(c13*(1.-(pin[13][0]*pin[13][0]))))
      ;
    Cik[13][0][1] = (((pin[13][0]*pin[13][1])-(pin[13][2]*s13))-(c13*(pin[13][0]
      *pin[13][1])));
    Cik[13][0][2] = (((pin[13][0]*pin[13][2])+(pin[13][1]*s13))-(c13*(pin[13][0]
      *pin[13][2])));
    Cik[13][1][0] = (((pin[13][0]*pin[13][1])+(pin[13][2]*s13))-(c13*(pin[13][0]
      *pin[13][1])));
    Cik[13][1][1] = ((pin[13][1]*pin[13][1])+(c13*(1.-(pin[13][1]*pin[13][1]))))
      ;
    Cik[13][1][2] = (((pin[13][1]*pin[13][2])-(pin[13][0]*s13))-(c13*(pin[13][1]
      *pin[13][2])));
    Cik[13][2][0] = (((pin[13][0]*pin[13][2])-(pin[13][1]*s13))-(c13*(pin[13][0]
      *pin[13][2])));
    Cik[13][2][1] = (((pin[13][0]*s13)+(pin[13][1]*pin[13][2]))-(c13*(pin[13][1]
      *pin[13][2])));
    Cik[13][2][2] = ((pin[13][2]*pin[13][2])+(c13*(1.-(pin[13][2]*pin[13][2]))))
      ;
    Cik[14][0][0] = ((pin[14][0]*pin[14][0])+(c14*(1.-(pin[14][0]*pin[14][0]))))
      ;
    Cik[14][0][1] = (((pin[14][0]*pin[14][1])-(pin[14][2]*s14))-(c14*(pin[14][0]
      *pin[14][1])));
    Cik[14][0][2] = (((pin[14][0]*pin[14][2])+(pin[14][1]*s14))-(c14*(pin[14][0]
      *pin[14][2])));
    Cik[14][1][0] = (((pin[14][0]*pin[14][1])+(pin[14][2]*s14))-(c14*(pin[14][0]
      *pin[14][1])));
    Cik[14][1][1] = ((pin[14][1]*pin[14][1])+(c14*(1.-(pin[14][1]*pin[14][1]))))
      ;
    Cik[14][1][2] = (((pin[14][1]*pin[14][2])-(pin[14][0]*s14))-(c14*(pin[14][1]
      *pin[14][2])));
    Cik[14][2][0] = (((pin[14][0]*pin[14][2])-(pin[14][1]*s14))-(c14*(pin[14][0]
      *pin[14][2])));
    Cik[14][2][1] = (((pin[14][0]*s14)+(pin[14][1]*pin[14][2]))-(c14*(pin[14][1]
      *pin[14][2])));
    Cik[14][2][2] = ((pin[14][2]*pin[14][2])+(c14*(1.-(pin[14][2]*pin[14][2]))))
      ;
    Cik[15][0][0] = ((pin[15][0]*pin[15][0])+(c15*(1.-(pin[15][0]*pin[15][0]))))
      ;
    Cik[15][0][1] = (((pin[15][0]*pin[15][1])-(pin[15][2]*s15))-(c15*(pin[15][0]
      *pin[15][1])));
    Cik[15][0][2] = (((pin[15][0]*pin[15][2])+(pin[15][1]*s15))-(c15*(pin[15][0]
      *pin[15][2])));
    Cik[15][1][0] = (((pin[15][0]*pin[15][1])+(pin[15][2]*s15))-(c15*(pin[15][0]
      *pin[15][1])));
    Cik[15][1][1] = ((pin[15][1]*pin[15][1])+(c15*(1.-(pin[15][1]*pin[15][1]))))
      ;
    Cik[15][1][2] = (((pin[15][1]*pin[15][2])-(pin[15][0]*s15))-(c15*(pin[15][1]
      *pin[15][2])));
    Cik[15][2][0] = (((pin[15][0]*pin[15][2])-(pin[15][1]*s15))-(c15*(pin[15][0]
      *pin[15][2])));
    Cik[15][2][1] = (((pin[15][0]*s15)+(pin[15][1]*pin[15][2]))-(c15*(pin[15][1]
      *pin[15][2])));
    Cik[15][2][2] = ((pin[15][2]*pin[15][2])+(c15*(1.-(pin[15][2]*pin[15][2]))))
      ;
    Cik[16][0][0] = ((pin[16][0]*pin[16][0])+(c16*(1.-(pin[16][0]*pin[16][0]))))
      ;
    Cik[16][0][1] = (((pin[16][0]*pin[16][1])-(pin[16][2]*s16))-(c16*(pin[16][0]
      *pin[16][1])));
    Cik[16][0][2] = (((pin[16][0]*pin[16][2])+(pin[16][1]*s16))-(c16*(pin[16][0]
      *pin[16][2])));
    Cik[16][1][0] = (((pin[16][0]*pin[16][1])+(pin[16][2]*s16))-(c16*(pin[16][0]
      *pin[16][1])));
    Cik[16][1][1] = ((pin[16][1]*pin[16][1])+(c16*(1.-(pin[16][1]*pin[16][1]))))
      ;
    Cik[16][1][2] = (((pin[16][1]*pin[16][2])-(pin[16][0]*s16))-(c16*(pin[16][1]
      *pin[16][2])));
    Cik[16][2][0] = (((pin[16][0]*pin[16][2])-(pin[16][1]*s16))-(c16*(pin[16][0]
      *pin[16][2])));
    Cik[16][2][1] = (((pin[16][0]*s16)+(pin[16][1]*pin[16][2]))-(c16*(pin[16][1]
      *pin[16][2])));
    Cik[16][2][2] = ((pin[16][2]*pin[16][2])+(c16*(1.-(pin[16][2]*pin[16][2]))))
      ;
    Cik[17][0][0] = ((pin[17][0]*pin[17][0])+(c17*(1.-(pin[17][0]*pin[17][0]))))
      ;
    Cik[17][0][1] = (((pin[17][0]*pin[17][1])-(pin[17][2]*s17))-(c17*(pin[17][0]
      *pin[17][1])));
    Cik[17][0][2] = (((pin[17][0]*pin[17][2])+(pin[17][1]*s17))-(c17*(pin[17][0]
      *pin[17][2])));
    Cik[17][1][0] = (((pin[17][0]*pin[17][1])+(pin[17][2]*s17))-(c17*(pin[17][0]
      *pin[17][1])));
    Cik[17][1][1] = ((pin[17][1]*pin[17][1])+(c17*(1.-(pin[17][1]*pin[17][1]))))
      ;
    Cik[17][1][2] = (((pin[17][1]*pin[17][2])-(pin[17][0]*s17))-(c17*(pin[17][1]
      *pin[17][2])));
    Cik[17][2][0] = (((pin[17][0]*pin[17][2])-(pin[17][1]*s17))-(c17*(pin[17][0]
      *pin[17][2])));
    Cik[17][2][1] = (((pin[17][0]*s17)+(pin[17][1]*pin[17][2]))-(c17*(pin[17][1]
      *pin[17][2])));
    Cik[17][2][2] = ((pin[17][2]*pin[17][2])+(c17*(1.-(pin[17][2]*pin[17][2]))))
      ;
/*
Compute across-joint direction cosines Cib
*/
/*
Compute gravity
*/
    gk[3][0] = ((Cik[3][2][0]*grav[2])+((Cik[3][0][0]*grav[0])+(Cik[3][1][0]*
      grav[1])));
    gk[3][1] = ((Cik[3][2][1]*grav[2])+((Cik[3][0][1]*grav[0])+(Cik[3][1][1]*
      grav[1])));
    gk[3][2] = ((Cik[3][2][2]*grav[2])+((Cik[3][0][2]*grav[0])+(Cik[3][1][2]*
      grav[1])));
    gk[6][0] = ((Cik[6][2][0]*gk[3][2])+((Cik[6][0][0]*gk[3][0])+(Cik[6][1][0]*
      gk[3][1])));
    gk[6][1] = ((Cik[6][2][1]*gk[3][2])+((Cik[6][0][1]*gk[3][0])+(Cik[6][1][1]*
      gk[3][1])));
    gk[6][2] = ((Cik[6][2][2]*gk[3][2])+((Cik[6][0][2]*gk[3][0])+(Cik[6][1][2]*
      gk[3][1])));
    gk[7][0] = ((Cik[7][2][0]*gk[6][2])+((Cik[7][0][0]*gk[6][0])+(Cik[7][1][0]*
      gk[6][1])));
    gk[7][1] = ((Cik[7][2][1]*gk[6][2])+((Cik[7][0][1]*gk[6][0])+(Cik[7][1][1]*
      gk[6][1])));
    gk[7][2] = ((Cik[7][2][2]*gk[6][2])+((Cik[7][0][2]*gk[6][0])+(Cik[7][1][2]*
      gk[6][1])));
    gk[8][0] = ((Cik[8][2][0]*gk[7][2])+((Cik[8][0][0]*gk[7][0])+(Cik[8][1][0]*
      gk[7][1])));
    gk[8][1] = ((Cik[8][2][1]*gk[7][2])+((Cik[8][0][1]*gk[7][0])+(Cik[8][1][1]*
      gk[7][1])));
    gk[8][2] = ((Cik[8][2][2]*gk[7][2])+((Cik[8][0][2]*gk[7][0])+(Cik[8][1][2]*
      gk[7][1])));
    gk[9][0] = ((Cik[9][2][0]*gk[3][2])+((Cik[9][0][0]*gk[3][0])+(Cik[9][1][0]*
      gk[3][1])));
    gk[9][1] = ((Cik[9][2][1]*gk[3][2])+((Cik[9][0][1]*gk[3][0])+(Cik[9][1][1]*
      gk[3][1])));
    gk[9][2] = ((Cik[9][2][2]*gk[3][2])+((Cik[9][0][2]*gk[3][0])+(Cik[9][1][2]*
      gk[3][1])));
    gk[10][0] = ((Cik[10][2][0]*gk[9][2])+((Cik[10][0][0]*gk[9][0])+(
      Cik[10][1][0]*gk[9][1])));
    gk[10][1] = ((Cik[10][2][1]*gk[9][2])+((Cik[10][0][1]*gk[9][0])+(
      Cik[10][1][1]*gk[9][1])));
    gk[10][2] = ((Cik[10][2][2]*gk[9][2])+((Cik[10][0][2]*gk[9][0])+(
      Cik[10][1][2]*gk[9][1])));
    gk[11][0] = ((Cik[11][2][0]*gk[10][2])+((Cik[11][0][0]*gk[10][0])+(
      Cik[11][1][0]*gk[10][1])));
    gk[11][1] = ((Cik[11][2][1]*gk[10][2])+((Cik[11][0][1]*gk[10][0])+(
      Cik[11][1][1]*gk[10][1])));
    gk[11][2] = ((Cik[11][2][2]*gk[10][2])+((Cik[11][0][2]*gk[10][0])+(
      Cik[11][1][2]*gk[10][1])));
    gk[12][0] = ((Cik[12][2][0]*gk[3][2])+((Cik[12][0][0]*gk[3][0])+(
      Cik[12][1][0]*gk[3][1])));
    gk[12][1] = ((Cik[12][2][1]*gk[3][2])+((Cik[12][0][1]*gk[3][0])+(
      Cik[12][1][1]*gk[3][1])));
    gk[12][2] = ((Cik[12][2][2]*gk[3][2])+((Cik[12][0][2]*gk[3][0])+(
      Cik[12][1][2]*gk[3][1])));
    gk[13][0] = ((Cik[13][2][0]*gk[12][2])+((Cik[13][0][0]*gk[12][0])+(
      Cik[13][1][0]*gk[12][1])));
    gk[13][1] = ((Cik[13][2][1]*gk[12][2])+((Cik[13][0][1]*gk[12][0])+(
      Cik[13][1][1]*gk[12][1])));
    gk[13][2] = ((Cik[13][2][2]*gk[12][2])+((Cik[13][0][2]*gk[12][0])+(
      Cik[13][1][2]*gk[12][1])));
    gk[14][0] = ((Cik[14][2][0]*gk[13][2])+((Cik[14][0][0]*gk[13][0])+(
      Cik[14][1][0]*gk[13][1])));
    gk[14][1] = ((Cik[14][2][1]*gk[13][2])+((Cik[14][0][1]*gk[13][0])+(
      Cik[14][1][1]*gk[13][1])));
    gk[14][2] = ((Cik[14][2][2]*gk[13][2])+((Cik[14][0][2]*gk[13][0])+(
      Cik[14][1][2]*gk[13][1])));
    gk[15][0] = ((Cik[15][2][0]*gk[3][2])+((Cik[15][0][0]*gk[3][0])+(
      Cik[15][1][0]*gk[3][1])));
    gk[15][1] = ((Cik[15][2][1]*gk[3][2])+((Cik[15][0][1]*gk[3][0])+(
      Cik[15][1][1]*gk[3][1])));
    gk[15][2] = ((Cik[15][2][2]*gk[3][2])+((Cik[15][0][2]*gk[3][0])+(
      Cik[15][1][2]*gk[3][1])));
    gk[16][0] = ((Cik[16][2][0]*gk[15][2])+((Cik[16][0][0]*gk[15][0])+(
      Cik[16][1][0]*gk[15][1])));
    gk[16][1] = ((Cik[16][2][1]*gk[15][2])+((Cik[16][0][1]*gk[15][0])+(
      Cik[16][1][1]*gk[15][1])));
    gk[16][2] = ((Cik[16][2][2]*gk[15][2])+((Cik[16][0][2]*gk[15][0])+(
      Cik[16][1][2]*gk[15][1])));
    gk[17][0] = ((Cik[17][2][0]*gk[16][2])+((Cik[17][0][0]*gk[16][0])+(
      Cik[17][1][0]*gk[16][1])));
    gk[17][1] = ((Cik[17][2][1]*gk[16][2])+((Cik[17][0][1]*gk[16][0])+(
      Cik[17][1][1]*gk[16][1])));
    gk[17][2] = ((Cik[17][2][2]*gk[16][2])+((Cik[17][0][2]*gk[16][0])+(
      Cik[17][1][2]*gk[16][1])));
/*
Compute cnk & cnb (direction cosines in N)
*/
    cnk[6][0][0] = ((Cik[3][0][2]*Cik[6][2][0])+((Cik[3][0][0]*Cik[6][0][0])+(
      Cik[3][0][1]*Cik[6][1][0])));
    cnk[6][0][1] = ((Cik[3][0][2]*Cik[6][2][1])+((Cik[3][0][0]*Cik[6][0][1])+(
      Cik[3][0][1]*Cik[6][1][1])));
    cnk[6][0][2] = ((Cik[3][0][2]*Cik[6][2][2])+((Cik[3][0][0]*Cik[6][0][2])+(
      Cik[3][0][1]*Cik[6][1][2])));
    cnk[6][1][0] = ((Cik[3][1][2]*Cik[6][2][0])+((Cik[3][1][0]*Cik[6][0][0])+(
      Cik[3][1][1]*Cik[6][1][0])));
    cnk[6][1][1] = ((Cik[3][1][2]*Cik[6][2][1])+((Cik[3][1][0]*Cik[6][0][1])+(
      Cik[3][1][1]*Cik[6][1][1])));
    cnk[6][1][2] = ((Cik[3][1][2]*Cik[6][2][2])+((Cik[3][1][0]*Cik[6][0][2])+(
      Cik[3][1][1]*Cik[6][1][2])));
    cnk[6][2][0] = ((Cik[3][2][2]*Cik[6][2][0])+((Cik[3][2][0]*Cik[6][0][0])+(
      Cik[3][2][1]*Cik[6][1][0])));
    cnk[6][2][1] = ((Cik[3][2][2]*Cik[6][2][1])+((Cik[3][2][0]*Cik[6][0][1])+(
      Cik[3][2][1]*Cik[6][1][1])));
    cnk[6][2][2] = ((Cik[3][2][2]*Cik[6][2][2])+((Cik[3][2][0]*Cik[6][0][2])+(
      Cik[3][2][1]*Cik[6][1][2])));
    cnk[7][0][0] = ((Cik[7][2][0]*cnk[6][0][2])+((Cik[7][0][0]*cnk[6][0][0])+(
      Cik[7][1][0]*cnk[6][0][1])));
    cnk[7][0][1] = ((Cik[7][2][1]*cnk[6][0][2])+((Cik[7][0][1]*cnk[6][0][0])+(
      Cik[7][1][1]*cnk[6][0][1])));
    cnk[7][0][2] = ((Cik[7][2][2]*cnk[6][0][2])+((Cik[7][0][2]*cnk[6][0][0])+(
      Cik[7][1][2]*cnk[6][0][1])));
    cnk[7][1][0] = ((Cik[7][2][0]*cnk[6][1][2])+((Cik[7][0][0]*cnk[6][1][0])+(
      Cik[7][1][0]*cnk[6][1][1])));
    cnk[7][1][1] = ((Cik[7][2][1]*cnk[6][1][2])+((Cik[7][0][1]*cnk[6][1][0])+(
      Cik[7][1][1]*cnk[6][1][1])));
    cnk[7][1][2] = ((Cik[7][2][2]*cnk[6][1][2])+((Cik[7][0][2]*cnk[6][1][0])+(
      Cik[7][1][2]*cnk[6][1][1])));
    cnk[7][2][0] = ((Cik[7][2][0]*cnk[6][2][2])+((Cik[7][0][0]*cnk[6][2][0])+(
      Cik[7][1][0]*cnk[6][2][1])));
    cnk[7][2][1] = ((Cik[7][2][1]*cnk[6][2][2])+((Cik[7][0][1]*cnk[6][2][0])+(
      Cik[7][1][1]*cnk[6][2][1])));
    cnk[7][2][2] = ((Cik[7][2][2]*cnk[6][2][2])+((Cik[7][0][2]*cnk[6][2][0])+(
      Cik[7][1][2]*cnk[6][2][1])));
    cnk[8][0][0] = ((Cik[8][2][0]*cnk[7][0][2])+((Cik[8][0][0]*cnk[7][0][0])+(
      Cik[8][1][0]*cnk[7][0][1])));
    cnk[8][0][1] = ((Cik[8][2][1]*cnk[7][0][2])+((Cik[8][0][1]*cnk[7][0][0])+(
      Cik[8][1][1]*cnk[7][0][1])));
    cnk[8][0][2] = ((Cik[8][2][2]*cnk[7][0][2])+((Cik[8][0][2]*cnk[7][0][0])+(
      Cik[8][1][2]*cnk[7][0][1])));
    cnk[8][1][0] = ((Cik[8][2][0]*cnk[7][1][2])+((Cik[8][0][0]*cnk[7][1][0])+(
      Cik[8][1][0]*cnk[7][1][1])));
    cnk[8][1][1] = ((Cik[8][2][1]*cnk[7][1][2])+((Cik[8][0][1]*cnk[7][1][0])+(
      Cik[8][1][1]*cnk[7][1][1])));
    cnk[8][1][2] = ((Cik[8][2][2]*cnk[7][1][2])+((Cik[8][0][2]*cnk[7][1][0])+(
      Cik[8][1][2]*cnk[7][1][1])));
    cnk[8][2][0] = ((Cik[8][2][0]*cnk[7][2][2])+((Cik[8][0][0]*cnk[7][2][0])+(
      Cik[8][1][0]*cnk[7][2][1])));
    cnk[8][2][1] = ((Cik[8][2][1]*cnk[7][2][2])+((Cik[8][0][1]*cnk[7][2][0])+(
      Cik[8][1][1]*cnk[7][2][1])));
    cnk[8][2][2] = ((Cik[8][2][2]*cnk[7][2][2])+((Cik[8][0][2]*cnk[7][2][0])+(
      Cik[8][1][2]*cnk[7][2][1])));
    cnk[9][0][0] = ((Cik[3][0][2]*Cik[9][2][0])+((Cik[3][0][0]*Cik[9][0][0])+(
      Cik[3][0][1]*Cik[9][1][0])));
    cnk[9][0][1] = ((Cik[3][0][2]*Cik[9][2][1])+((Cik[3][0][0]*Cik[9][0][1])+(
      Cik[3][0][1]*Cik[9][1][1])));
    cnk[9][0][2] = ((Cik[3][0][2]*Cik[9][2][2])+((Cik[3][0][0]*Cik[9][0][2])+(
      Cik[3][0][1]*Cik[9][1][2])));
    cnk[9][1][0] = ((Cik[3][1][2]*Cik[9][2][0])+((Cik[3][1][0]*Cik[9][0][0])+(
      Cik[3][1][1]*Cik[9][1][0])));
    cnk[9][1][1] = ((Cik[3][1][2]*Cik[9][2][1])+((Cik[3][1][0]*Cik[9][0][1])+(
      Cik[3][1][1]*Cik[9][1][1])));
    cnk[9][1][2] = ((Cik[3][1][2]*Cik[9][2][2])+((Cik[3][1][0]*Cik[9][0][2])+(
      Cik[3][1][1]*Cik[9][1][2])));
    cnk[9][2][0] = ((Cik[3][2][2]*Cik[9][2][0])+((Cik[3][2][0]*Cik[9][0][0])+(
      Cik[3][2][1]*Cik[9][1][0])));
    cnk[9][2][1] = ((Cik[3][2][2]*Cik[9][2][1])+((Cik[3][2][0]*Cik[9][0][1])+(
      Cik[3][2][1]*Cik[9][1][1])));
    cnk[9][2][2] = ((Cik[3][2][2]*Cik[9][2][2])+((Cik[3][2][0]*Cik[9][0][2])+(
      Cik[3][2][1]*Cik[9][1][2])));
    cnk[10][0][0] = ((Cik[10][2][0]*cnk[9][0][2])+((Cik[10][0][0]*cnk[9][0][0])+
      (Cik[10][1][0]*cnk[9][0][1])));
    cnk[10][0][1] = ((Cik[10][2][1]*cnk[9][0][2])+((Cik[10][0][1]*cnk[9][0][0])+
      (Cik[10][1][1]*cnk[9][0][1])));
    cnk[10][0][2] = ((Cik[10][2][2]*cnk[9][0][2])+((Cik[10][0][2]*cnk[9][0][0])+
      (Cik[10][1][2]*cnk[9][0][1])));
    cnk[10][1][0] = ((Cik[10][2][0]*cnk[9][1][2])+((Cik[10][0][0]*cnk[9][1][0])+
      (Cik[10][1][0]*cnk[9][1][1])));
    cnk[10][1][1] = ((Cik[10][2][1]*cnk[9][1][2])+((Cik[10][0][1]*cnk[9][1][0])+
      (Cik[10][1][1]*cnk[9][1][1])));
    cnk[10][1][2] = ((Cik[10][2][2]*cnk[9][1][2])+((Cik[10][0][2]*cnk[9][1][0])+
      (Cik[10][1][2]*cnk[9][1][1])));
    cnk[10][2][0] = ((Cik[10][2][0]*cnk[9][2][2])+((Cik[10][0][0]*cnk[9][2][0])+
      (Cik[10][1][0]*cnk[9][2][1])));
    cnk[10][2][1] = ((Cik[10][2][1]*cnk[9][2][2])+((Cik[10][0][1]*cnk[9][2][0])+
      (Cik[10][1][1]*cnk[9][2][1])));
    cnk[10][2][2] = ((Cik[10][2][2]*cnk[9][2][2])+((Cik[10][0][2]*cnk[9][2][0])+
      (Cik[10][1][2]*cnk[9][2][1])));
    cnk[11][0][0] = ((Cik[11][2][0]*cnk[10][0][2])+((Cik[11][0][0]*cnk[10][0][0]
      )+(Cik[11][1][0]*cnk[10][0][1])));
    cnk[11][0][1] = ((Cik[11][2][1]*cnk[10][0][2])+((Cik[11][0][1]*cnk[10][0][0]
      )+(Cik[11][1][1]*cnk[10][0][1])));
    cnk[11][0][2] = ((Cik[11][2][2]*cnk[10][0][2])+((Cik[11][0][2]*cnk[10][0][0]
      )+(Cik[11][1][2]*cnk[10][0][1])));
    cnk[11][1][0] = ((Cik[11][2][0]*cnk[10][1][2])+((Cik[11][0][0]*cnk[10][1][0]
      )+(Cik[11][1][0]*cnk[10][1][1])));
    cnk[11][1][1] = ((Cik[11][2][1]*cnk[10][1][2])+((Cik[11][0][1]*cnk[10][1][0]
      )+(Cik[11][1][1]*cnk[10][1][1])));
    cnk[11][1][2] = ((Cik[11][2][2]*cnk[10][1][2])+((Cik[11][0][2]*cnk[10][1][0]
      )+(Cik[11][1][2]*cnk[10][1][1])));
    cnk[11][2][0] = ((Cik[11][2][0]*cnk[10][2][2])+((Cik[11][0][0]*cnk[10][2][0]
      )+(Cik[11][1][0]*cnk[10][2][1])));
    cnk[11][2][1] = ((Cik[11][2][1]*cnk[10][2][2])+((Cik[11][0][1]*cnk[10][2][0]
      )+(Cik[11][1][1]*cnk[10][2][1])));
    cnk[11][2][2] = ((Cik[11][2][2]*cnk[10][2][2])+((Cik[11][0][2]*cnk[10][2][0]
      )+(Cik[11][1][2]*cnk[10][2][1])));
    cnk[12][0][0] = ((Cik[3][0][2]*Cik[12][2][0])+((Cik[3][0][0]*Cik[12][0][0])+
      (Cik[3][0][1]*Cik[12][1][0])));
    cnk[12][0][1] = ((Cik[3][0][2]*Cik[12][2][1])+((Cik[3][0][0]*Cik[12][0][1])+
      (Cik[3][0][1]*Cik[12][1][1])));
    cnk[12][0][2] = ((Cik[3][0][2]*Cik[12][2][2])+((Cik[3][0][0]*Cik[12][0][2])+
      (Cik[3][0][1]*Cik[12][1][2])));
    cnk[12][1][0] = ((Cik[3][1][2]*Cik[12][2][0])+((Cik[3][1][0]*Cik[12][0][0])+
      (Cik[3][1][1]*Cik[12][1][0])));
    cnk[12][1][1] = ((Cik[3][1][2]*Cik[12][2][1])+((Cik[3][1][0]*Cik[12][0][1])+
      (Cik[3][1][1]*Cik[12][1][1])));
    cnk[12][1][2] = ((Cik[3][1][2]*Cik[12][2][2])+((Cik[3][1][0]*Cik[12][0][2])+
      (Cik[3][1][1]*Cik[12][1][2])));
    cnk[12][2][0] = ((Cik[3][2][2]*Cik[12][2][0])+((Cik[3][2][0]*Cik[12][0][0])+
      (Cik[3][2][1]*Cik[12][1][0])));
    cnk[12][2][1] = ((Cik[3][2][2]*Cik[12][2][1])+((Cik[3][2][0]*Cik[12][0][1])+
      (Cik[3][2][1]*Cik[12][1][1])));
    cnk[12][2][2] = ((Cik[3][2][2]*Cik[12][2][2])+((Cik[3][2][0]*Cik[12][0][2])+
      (Cik[3][2][1]*Cik[12][1][2])));
    cnk[13][0][0] = ((Cik[13][2][0]*cnk[12][0][2])+((Cik[13][0][0]*cnk[12][0][0]
      )+(Cik[13][1][0]*cnk[12][0][1])));
    cnk[13][0][1] = ((Cik[13][2][1]*cnk[12][0][2])+((Cik[13][0][1]*cnk[12][0][0]
      )+(Cik[13][1][1]*cnk[12][0][1])));
    cnk[13][0][2] = ((Cik[13][2][2]*cnk[12][0][2])+((Cik[13][0][2]*cnk[12][0][0]
      )+(Cik[13][1][2]*cnk[12][0][1])));
    cnk[13][1][0] = ((Cik[13][2][0]*cnk[12][1][2])+((Cik[13][0][0]*cnk[12][1][0]
      )+(Cik[13][1][0]*cnk[12][1][1])));
    cnk[13][1][1] = ((Cik[13][2][1]*cnk[12][1][2])+((Cik[13][0][1]*cnk[12][1][0]
      )+(Cik[13][1][1]*cnk[12][1][1])));
    cnk[13][1][2] = ((Cik[13][2][2]*cnk[12][1][2])+((Cik[13][0][2]*cnk[12][1][0]
      )+(Cik[13][1][2]*cnk[12][1][1])));
    cnk[13][2][0] = ((Cik[13][2][0]*cnk[12][2][2])+((Cik[13][0][0]*cnk[12][2][0]
      )+(Cik[13][1][0]*cnk[12][2][1])));
    cnk[13][2][1] = ((Cik[13][2][1]*cnk[12][2][2])+((Cik[13][0][1]*cnk[12][2][0]
      )+(Cik[13][1][1]*cnk[12][2][1])));
    cnk[13][2][2] = ((Cik[13][2][2]*cnk[12][2][2])+((Cik[13][0][2]*cnk[12][2][0]
      )+(Cik[13][1][2]*cnk[12][2][1])));
    cnk[14][0][0] = ((Cik[14][2][0]*cnk[13][0][2])+((Cik[14][0][0]*cnk[13][0][0]
      )+(Cik[14][1][0]*cnk[13][0][1])));
    cnk[14][0][1] = ((Cik[14][2][1]*cnk[13][0][2])+((Cik[14][0][1]*cnk[13][0][0]
      )+(Cik[14][1][1]*cnk[13][0][1])));
    cnk[14][0][2] = ((Cik[14][2][2]*cnk[13][0][2])+((Cik[14][0][2]*cnk[13][0][0]
      )+(Cik[14][1][2]*cnk[13][0][1])));
    cnk[14][1][0] = ((Cik[14][2][0]*cnk[13][1][2])+((Cik[14][0][0]*cnk[13][1][0]
      )+(Cik[14][1][0]*cnk[13][1][1])));
    cnk[14][1][1] = ((Cik[14][2][1]*cnk[13][1][2])+((Cik[14][0][1]*cnk[13][1][0]
      )+(Cik[14][1][1]*cnk[13][1][1])));
    cnk[14][1][2] = ((Cik[14][2][2]*cnk[13][1][2])+((Cik[14][0][2]*cnk[13][1][0]
      )+(Cik[14][1][2]*cnk[13][1][1])));
    cnk[14][2][0] = ((Cik[14][2][0]*cnk[13][2][2])+((Cik[14][0][0]*cnk[13][2][0]
      )+(Cik[14][1][0]*cnk[13][2][1])));
    cnk[14][2][1] = ((Cik[14][2][1]*cnk[13][2][2])+((Cik[14][0][1]*cnk[13][2][0]
      )+(Cik[14][1][1]*cnk[13][2][1])));
    cnk[14][2][2] = ((Cik[14][2][2]*cnk[13][2][2])+((Cik[14][0][2]*cnk[13][2][0]
      )+(Cik[14][1][2]*cnk[13][2][1])));
    cnk[15][0][0] = ((Cik[3][0][2]*Cik[15][2][0])+((Cik[3][0][0]*Cik[15][0][0])+
      (Cik[3][0][1]*Cik[15][1][0])));
    cnk[15][0][1] = ((Cik[3][0][2]*Cik[15][2][1])+((Cik[3][0][0]*Cik[15][0][1])+
      (Cik[3][0][1]*Cik[15][1][1])));
    cnk[15][0][2] = ((Cik[3][0][2]*Cik[15][2][2])+((Cik[3][0][0]*Cik[15][0][2])+
      (Cik[3][0][1]*Cik[15][1][2])));
    cnk[15][1][0] = ((Cik[3][1][2]*Cik[15][2][0])+((Cik[3][1][0]*Cik[15][0][0])+
      (Cik[3][1][1]*Cik[15][1][0])));
    cnk[15][1][1] = ((Cik[3][1][2]*Cik[15][2][1])+((Cik[3][1][0]*Cik[15][0][1])+
      (Cik[3][1][1]*Cik[15][1][1])));
    cnk[15][1][2] = ((Cik[3][1][2]*Cik[15][2][2])+((Cik[3][1][0]*Cik[15][0][2])+
      (Cik[3][1][1]*Cik[15][1][2])));
    cnk[15][2][0] = ((Cik[3][2][2]*Cik[15][2][0])+((Cik[3][2][0]*Cik[15][0][0])+
      (Cik[3][2][1]*Cik[15][1][0])));
    cnk[15][2][1] = ((Cik[3][2][2]*Cik[15][2][1])+((Cik[3][2][0]*Cik[15][0][1])+
      (Cik[3][2][1]*Cik[15][1][1])));
    cnk[15][2][2] = ((Cik[3][2][2]*Cik[15][2][2])+((Cik[3][2][0]*Cik[15][0][2])+
      (Cik[3][2][1]*Cik[15][1][2])));
    cnk[16][0][0] = ((Cik[16][2][0]*cnk[15][0][2])+((Cik[16][0][0]*cnk[15][0][0]
      )+(Cik[16][1][0]*cnk[15][0][1])));
    cnk[16][0][1] = ((Cik[16][2][1]*cnk[15][0][2])+((Cik[16][0][1]*cnk[15][0][0]
      )+(Cik[16][1][1]*cnk[15][0][1])));
    cnk[16][0][2] = ((Cik[16][2][2]*cnk[15][0][2])+((Cik[16][0][2]*cnk[15][0][0]
      )+(Cik[16][1][2]*cnk[15][0][1])));
    cnk[16][1][0] = ((Cik[16][2][0]*cnk[15][1][2])+((Cik[16][0][0]*cnk[15][1][0]
      )+(Cik[16][1][0]*cnk[15][1][1])));
    cnk[16][1][1] = ((Cik[16][2][1]*cnk[15][1][2])+((Cik[16][0][1]*cnk[15][1][0]
      )+(Cik[16][1][1]*cnk[15][1][1])));
    cnk[16][1][2] = ((Cik[16][2][2]*cnk[15][1][2])+((Cik[16][0][2]*cnk[15][1][0]
      )+(Cik[16][1][2]*cnk[15][1][1])));
    cnk[16][2][0] = ((Cik[16][2][0]*cnk[15][2][2])+((Cik[16][0][0]*cnk[15][2][0]
      )+(Cik[16][1][0]*cnk[15][2][1])));
    cnk[16][2][1] = ((Cik[16][2][1]*cnk[15][2][2])+((Cik[16][0][1]*cnk[15][2][0]
      )+(Cik[16][1][1]*cnk[15][2][1])));
    cnk[16][2][2] = ((Cik[16][2][2]*cnk[15][2][2])+((Cik[16][0][2]*cnk[15][2][0]
      )+(Cik[16][1][2]*cnk[15][2][1])));
    cnk[17][0][0] = ((Cik[17][2][0]*cnk[16][0][2])+((Cik[17][0][0]*cnk[16][0][0]
      )+(Cik[17][1][0]*cnk[16][0][1])));
    cnk[17][0][1] = ((Cik[17][2][1]*cnk[16][0][2])+((Cik[17][0][1]*cnk[16][0][0]
      )+(Cik[17][1][1]*cnk[16][0][1])));
    cnk[17][0][2] = ((Cik[17][2][2]*cnk[16][0][2])+((Cik[17][0][2]*cnk[16][0][0]
      )+(Cik[17][1][2]*cnk[16][0][1])));
    cnk[17][1][0] = ((Cik[17][2][0]*cnk[16][1][2])+((Cik[17][0][0]*cnk[16][1][0]
      )+(Cik[17][1][0]*cnk[16][1][1])));
    cnk[17][1][1] = ((Cik[17][2][1]*cnk[16][1][2])+((Cik[17][0][1]*cnk[16][1][0]
      )+(Cik[17][1][1]*cnk[16][1][1])));
    cnk[17][1][2] = ((Cik[17][2][2]*cnk[16][1][2])+((Cik[17][0][2]*cnk[16][1][0]
      )+(Cik[17][1][2]*cnk[16][1][1])));
    cnk[17][2][0] = ((Cik[17][2][0]*cnk[16][2][2])+((Cik[17][0][0]*cnk[16][2][0]
      )+(Cik[17][1][0]*cnk[16][2][1])));
    cnk[17][2][1] = ((Cik[17][2][1]*cnk[16][2][2])+((Cik[17][0][1]*cnk[16][2][0]
      )+(Cik[17][1][1]*cnk[16][2][1])));
    cnk[17][2][2] = ((Cik[17][2][2]*cnk[16][2][2])+((Cik[17][0][2]*cnk[16][2][0]
      )+(Cik[17][1][2]*cnk[16][2][1])));
    cnb[0][0][0] = Cik[3][0][0];
    cnb[0][0][1] = Cik[3][0][1];
    cnb[0][0][2] = Cik[3][0][2];
    cnb[0][1][0] = Cik[3][1][0];
    cnb[0][1][1] = Cik[3][1][1];
    cnb[0][1][2] = Cik[3][1][2];
    cnb[0][2][0] = Cik[3][2][0];
    cnb[0][2][1] = Cik[3][2][1];
    cnb[0][2][2] = Cik[3][2][2];
    cnb[1][0][0] = cnk[6][0][0];
    cnb[1][0][1] = cnk[6][0][1];
    cnb[1][0][2] = cnk[6][0][2];
    cnb[1][1][0] = cnk[6][1][0];
    cnb[1][1][1] = cnk[6][1][1];
    cnb[1][1][2] = cnk[6][1][2];
    cnb[1][2][0] = cnk[6][2][0];
    cnb[1][2][1] = cnk[6][2][1];
    cnb[1][2][2] = cnk[6][2][2];
    cnb[2][0][0] = cnk[7][0][0];
    cnb[2][0][1] = cnk[7][0][1];
    cnb[2][0][2] = cnk[7][0][2];
    cnb[2][1][0] = cnk[7][1][0];
    cnb[2][1][1] = cnk[7][1][1];
    cnb[2][1][2] = cnk[7][1][2];
    cnb[2][2][0] = cnk[7][2][0];
    cnb[2][2][1] = cnk[7][2][1];
    cnb[2][2][2] = cnk[7][2][2];
    cnb[3][0][0] = cnk[8][0][0];
    cnb[3][0][1] = cnk[8][0][1];
    cnb[3][0][2] = cnk[8][0][2];
    cnb[3][1][0] = cnk[8][1][0];
    cnb[3][1][1] = cnk[8][1][1];
    cnb[3][1][2] = cnk[8][1][2];
    cnb[3][2][0] = cnk[8][2][0];
    cnb[3][2][1] = cnk[8][2][1];
    cnb[3][2][2] = cnk[8][2][2];
    cnb[4][0][0] = cnk[9][0][0];
    cnb[4][0][1] = cnk[9][0][1];
    cnb[4][0][2] = cnk[9][0][2];
    cnb[4][1][0] = cnk[9][1][0];
    cnb[4][1][1] = cnk[9][1][1];
    cnb[4][1][2] = cnk[9][1][2];
    cnb[4][2][0] = cnk[9][2][0];
    cnb[4][2][1] = cnk[9][2][1];
    cnb[4][2][2] = cnk[9][2][2];
    cnb[5][0][0] = cnk[10][0][0];
    cnb[5][0][1] = cnk[10][0][1];
    cnb[5][0][2] = cnk[10][0][2];
    cnb[5][1][0] = cnk[10][1][0];
    cnb[5][1][1] = cnk[10][1][1];
    cnb[5][1][2] = cnk[10][1][2];
    cnb[5][2][0] = cnk[10][2][0];
    cnb[5][2][1] = cnk[10][2][1];
    cnb[5][2][2] = cnk[10][2][2];
    cnb[6][0][0] = cnk[11][0][0];
    cnb[6][0][1] = cnk[11][0][1];
    cnb[6][0][2] = cnk[11][0][2];
    cnb[6][1][0] = cnk[11][1][0];
    cnb[6][1][1] = cnk[11][1][1];
    cnb[6][1][2] = cnk[11][1][2];
    cnb[6][2][0] = cnk[11][2][0];
    cnb[6][2][1] = cnk[11][2][1];
    cnb[6][2][2] = cnk[11][2][2];
    cnb[7][0][0] = cnk[12][0][0];
    cnb[7][0][1] = cnk[12][0][1];
    cnb[7][0][2] = cnk[12][0][2];
    cnb[7][1][0] = cnk[12][1][0];
    cnb[7][1][1] = cnk[12][1][1];
    cnb[7][1][2] = cnk[12][1][2];
    cnb[7][2][0] = cnk[12][2][0];
    cnb[7][2][1] = cnk[12][2][1];
    cnb[7][2][2] = cnk[12][2][2];
    cnb[8][0][0] = cnk[13][0][0];
    cnb[8][0][1] = cnk[13][0][1];
    cnb[8][0][2] = cnk[13][0][2];
    cnb[8][1][0] = cnk[13][1][0];
    cnb[8][1][1] = cnk[13][1][1];
    cnb[8][1][2] = cnk[13][1][2];
    cnb[8][2][0] = cnk[13][2][0];
    cnb[8][2][1] = cnk[13][2][1];
    cnb[8][2][2] = cnk[13][2][2];
    cnb[9][0][0] = cnk[14][0][0];
    cnb[9][0][1] = cnk[14][0][1];
    cnb[9][0][2] = cnk[14][0][2];
    cnb[9][1][0] = cnk[14][1][0];
    cnb[9][1][1] = cnk[14][1][1];
    cnb[9][1][2] = cnk[14][1][2];
    cnb[9][2][0] = cnk[14][2][0];
    cnb[9][2][1] = cnk[14][2][1];
    cnb[9][2][2] = cnk[14][2][2];
    cnb[10][0][0] = cnk[15][0][0];
    cnb[10][0][1] = cnk[15][0][1];
    cnb[10][0][2] = cnk[15][0][2];
    cnb[10][1][0] = cnk[15][1][0];
    cnb[10][1][1] = cnk[15][1][1];
    cnb[10][1][2] = cnk[15][1][2];
    cnb[10][2][0] = cnk[15][2][0];
    cnb[10][2][1] = cnk[15][2][1];
    cnb[10][2][2] = cnk[15][2][2];
    cnb[11][0][0] = cnk[16][0][0];
    cnb[11][0][1] = cnk[16][0][1];
    cnb[11][0][2] = cnk[16][0][2];
    cnb[11][1][0] = cnk[16][1][0];
    cnb[11][1][1] = cnk[16][1][1];
    cnb[11][1][2] = cnk[16][1][2];
    cnb[11][2][0] = cnk[16][2][0];
    cnb[11][2][1] = cnk[16][2][1];
    cnb[11][2][2] = cnk[16][2][2];
    cnb[12][0][0] = cnk[17][0][0];
    cnb[12][0][1] = cnk[17][0][1];
    cnb[12][0][2] = cnk[17][0][2];
    cnb[12][1][0] = cnk[17][1][0];
    cnb[12][1][1] = cnk[17][1][1];
    cnb[12][1][2] = cnk[17][1][2];
    cnb[12][2][0] = cnk[17][2][0];
    cnb[12][2][1] = cnk[17][2][1];
    cnb[12][2][2] = cnk[17][2][2];
/*
Compute q-related auxiliary variables
*/
    rpp[0][0] = (pin[0][0]*q[0]);
    rpp[0][1] = (pin[0][1]*q[0]);
    rpp[0][2] = (pin[0][2]*q[0]);
    rpp[1][0] = (pin[1][0]*q[1]);
    rpp[1][1] = (pin[1][1]*q[1]);
    rpp[1][2] = (pin[1][2]*q[1]);
    rpp[2][0] = (pin[2][0]*q[2]);
    rpp[2][1] = (pin[2][1]*q[2]);
    rpp[2][2] = (pin[2][2]*q[2]);
    rpri[0][0] = (ri[0][0]+rpp[0][0]);
    rpri[0][1] = (ri[0][1]+rpp[0][1]);
    rpri[0][2] = (ri[0][2]+rpp[0][2]);
    rik[0][0] = (ri[0][0]+rpp[0][0]);
    rik[0][1] = (ri[0][1]+rpp[0][1]);
    rik[0][2] = (ri[0][2]+rpp[0][2]);
    rik[6][0] = (((Cik[6][2][0]*ri[1][2])+((Cik[6][0][0]*ri[1][0])+(Cik[6][1][0]
      *ri[1][1])))-rk[1][0]);
    rik[6][1] = (((Cik[6][2][1]*ri[1][2])+((Cik[6][0][1]*ri[1][0])+(Cik[6][1][1]
      *ri[1][1])))-rk[1][1]);
    rik[6][2] = (((Cik[6][2][2]*ri[1][2])+((Cik[6][0][2]*ri[1][0])+(Cik[6][1][2]
      *ri[1][1])))-rk[1][2]);
    rik[7][0] = (((Cik[7][2][0]*ri[2][2])+((Cik[7][0][0]*ri[2][0])+(Cik[7][1][0]
      *ri[2][1])))-rk[2][0]);
    rik[7][1] = (((Cik[7][2][1]*ri[2][2])+((Cik[7][0][1]*ri[2][0])+(Cik[7][1][1]
      *ri[2][1])))-rk[2][1]);
    rik[7][2] = (((Cik[7][2][2]*ri[2][2])+((Cik[7][0][2]*ri[2][0])+(Cik[7][1][2]
      *ri[2][1])))-rk[2][2]);
    rik[8][0] = (((Cik[8][2][0]*ri[3][2])+((Cik[8][0][0]*ri[3][0])+(Cik[8][1][0]
      *ri[3][1])))-rk[3][0]);
    rik[8][1] = (((Cik[8][2][1]*ri[3][2])+((Cik[8][0][1]*ri[3][0])+(Cik[8][1][1]
      *ri[3][1])))-rk[3][1]);
    rik[8][2] = (((Cik[8][2][2]*ri[3][2])+((Cik[8][0][2]*ri[3][0])+(Cik[8][1][2]
      *ri[3][1])))-rk[3][2]);
    rik[9][0] = (((Cik[9][2][0]*ri[4][2])+((Cik[9][0][0]*ri[4][0])+(Cik[9][1][0]
      *ri[4][1])))-rk[4][0]);
    rik[9][1] = (((Cik[9][2][1]*ri[4][2])+((Cik[9][0][1]*ri[4][0])+(Cik[9][1][1]
      *ri[4][1])))-rk[4][1]);
    rik[9][2] = (((Cik[9][2][2]*ri[4][2])+((Cik[9][0][2]*ri[4][0])+(Cik[9][1][2]
      *ri[4][1])))-rk[4][2]);
    rik[10][0] = (((Cik[10][2][0]*ri[5][2])+((Cik[10][0][0]*ri[5][0])+(
      Cik[10][1][0]*ri[5][1])))-rk[5][0]);
    rik[10][1] = (((Cik[10][2][1]*ri[5][2])+((Cik[10][0][1]*ri[5][0])+(
      Cik[10][1][1]*ri[5][1])))-rk[5][1]);
    rik[10][2] = (((Cik[10][2][2]*ri[5][2])+((Cik[10][0][2]*ri[5][0])+(
      Cik[10][1][2]*ri[5][1])))-rk[5][2]);
    rik[11][0] = (((Cik[11][2][0]*ri[6][2])+((Cik[11][0][0]*ri[6][0])+(
      Cik[11][1][0]*ri[6][1])))-rk[6][0]);
    rik[11][1] = (((Cik[11][2][1]*ri[6][2])+((Cik[11][0][1]*ri[6][0])+(
      Cik[11][1][1]*ri[6][1])))-rk[6][1]);
    rik[11][2] = (((Cik[11][2][2]*ri[6][2])+((Cik[11][0][2]*ri[6][0])+(
      Cik[11][1][2]*ri[6][1])))-rk[6][2]);
    rik[12][0] = (((Cik[12][2][0]*ri[7][2])+((Cik[12][0][0]*ri[7][0])+(
      Cik[12][1][0]*ri[7][1])))-rk[7][0]);
    rik[12][1] = (((Cik[12][2][1]*ri[7][2])+((Cik[12][0][1]*ri[7][0])+(
      Cik[12][1][1]*ri[7][1])))-rk[7][1]);
    rik[12][2] = (((Cik[12][2][2]*ri[7][2])+((Cik[12][0][2]*ri[7][0])+(
      Cik[12][1][2]*ri[7][1])))-rk[7][2]);
    rik[13][0] = (((Cik[13][2][0]*ri[8][2])+((Cik[13][0][0]*ri[8][0])+(
      Cik[13][1][0]*ri[8][1])))-rk[8][0]);
    rik[13][1] = (((Cik[13][2][1]*ri[8][2])+((Cik[13][0][1]*ri[8][0])+(
      Cik[13][1][1]*ri[8][1])))-rk[8][1]);
    rik[13][2] = (((Cik[13][2][2]*ri[8][2])+((Cik[13][0][2]*ri[8][0])+(
      Cik[13][1][2]*ri[8][1])))-rk[8][2]);
    rik[14][0] = (((Cik[14][2][0]*ri[9][2])+((Cik[14][0][0]*ri[9][0])+(
      Cik[14][1][0]*ri[9][1])))-rk[9][0]);
    rik[14][1] = (((Cik[14][2][1]*ri[9][2])+((Cik[14][0][1]*ri[9][0])+(
      Cik[14][1][1]*ri[9][1])))-rk[9][1]);
    rik[14][2] = (((Cik[14][2][2]*ri[9][2])+((Cik[14][0][2]*ri[9][0])+(
      Cik[14][1][2]*ri[9][1])))-rk[9][2]);
    rik[15][0] = (((Cik[15][2][0]*ri[10][2])+((Cik[15][0][0]*ri[10][0])+(
      Cik[15][1][0]*ri[10][1])))-rk[10][0]);
    rik[15][1] = (((Cik[15][2][1]*ri[10][2])+((Cik[15][0][1]*ri[10][0])+(
      Cik[15][1][1]*ri[10][1])))-rk[10][1]);
    rik[15][2] = (((Cik[15][2][2]*ri[10][2])+((Cik[15][0][2]*ri[10][0])+(
      Cik[15][1][2]*ri[10][1])))-rk[10][2]);
    rik[16][0] = (((Cik[16][2][0]*ri[11][2])+((Cik[16][0][0]*ri[11][0])+(
      Cik[16][1][0]*ri[11][1])))-rk[11][0]);
    rik[16][1] = (((Cik[16][2][1]*ri[11][2])+((Cik[16][0][1]*ri[11][0])+(
      Cik[16][1][1]*ri[11][1])))-rk[11][1]);
    rik[16][2] = (((Cik[16][2][2]*ri[11][2])+((Cik[16][0][2]*ri[11][0])+(
      Cik[16][1][2]*ri[11][1])))-rk[11][2]);
    rik[17][0] = (((Cik[17][2][0]*ri[12][2])+((Cik[17][0][0]*ri[12][0])+(
      Cik[17][1][0]*ri[12][1])))-rk[12][0]);
    rik[17][1] = (((Cik[17][2][1]*ri[12][2])+((Cik[17][0][1]*ri[12][0])+(
      Cik[17][1][1]*ri[12][1])))-rk[12][1]);
    rik[17][2] = (((Cik[17][2][2]*ri[12][2])+((Cik[17][0][2]*ri[12][0])+(
      Cik[17][1][2]*ri[12][1])))-rk[12][2]);
/*
Compute rnk & rnb (mass center locations in N)
*/
    rnk[0][0] = (ri[0][0]+rpp[0][0]);
    rnk[0][1] = (ri[0][1]+rpp[0][1]);
    rnk[0][2] = (ri[0][2]+rpp[0][2]);
    rnk[1][0] = (rnk[0][0]+rpp[1][0]);
    rnk[1][1] = (rnk[0][1]+rpp[1][1]);
    rnk[1][2] = (rnk[0][2]+rpp[1][2]);
    rnk[2][0] = (rnk[1][0]+rpp[2][0]);
    rnk[2][1] = (rnk[1][1]+rpp[2][1]);
    rnk[2][2] = (rnk[1][2]+rpp[2][2]);
    rnk[5][0] = (rnk[2][0]-((Cik[3][0][2]*rk[0][2])+((Cik[3][0][0]*rk[0][0])+(
      Cik[3][0][1]*rk[0][1]))));
    rnk[5][1] = (rnk[2][1]-((Cik[3][1][2]*rk[0][2])+((Cik[3][1][0]*rk[0][0])+(
      Cik[3][1][1]*rk[0][1]))));
    rnk[5][2] = (rnk[2][2]-((Cik[3][2][2]*rk[0][2])+((Cik[3][2][0]*rk[0][0])+(
      Cik[3][2][1]*rk[0][1]))));
    rnk[6][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[1][2])+((Cik[3][0][0]*ri[1][0])+(
      Cik[3][0][1]*ri[1][1]))))-((cnk[6][0][2]*rk[1][2])+((cnk[6][0][0]*rk[1][0]
      )+(cnk[6][0][1]*rk[1][1]))));
    rnk[6][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[1][2])+((Cik[3][1][0]*ri[1][0])+(
      Cik[3][1][1]*ri[1][1]))))-((cnk[6][1][2]*rk[1][2])+((cnk[6][1][0]*rk[1][0]
      )+(cnk[6][1][1]*rk[1][1]))));
    rnk[6][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[1][2])+((Cik[3][2][0]*ri[1][0])+(
      Cik[3][2][1]*ri[1][1]))))-((cnk[6][2][2]*rk[1][2])+((cnk[6][2][0]*rk[1][0]
      )+(cnk[6][2][1]*rk[1][1]))));
    rnk[7][0] = ((rnk[6][0]+((cnk[6][0][2]*ri[2][2])+((cnk[6][0][0]*ri[2][0])+(
      cnk[6][0][1]*ri[2][1]))))-((cnk[7][0][2]*rk[2][2])+((cnk[7][0][0]*rk[2][0]
      )+(cnk[7][0][1]*rk[2][1]))));
    rnk[7][1] = ((rnk[6][1]+((cnk[6][1][2]*ri[2][2])+((cnk[6][1][0]*ri[2][0])+(
      cnk[6][1][1]*ri[2][1]))))-((cnk[7][1][2]*rk[2][2])+((cnk[7][1][0]*rk[2][0]
      )+(cnk[7][1][1]*rk[2][1]))));
    rnk[7][2] = ((rnk[6][2]+((cnk[6][2][2]*ri[2][2])+((cnk[6][2][0]*ri[2][0])+(
      cnk[6][2][1]*ri[2][1]))))-((cnk[7][2][2]*rk[2][2])+((cnk[7][2][0]*rk[2][0]
      )+(cnk[7][2][1]*rk[2][1]))));
    rnk[8][0] = ((rnk[7][0]+((cnk[7][0][2]*ri[3][2])+((cnk[7][0][0]*ri[3][0])+(
      cnk[7][0][1]*ri[3][1]))))-((cnk[8][0][2]*rk[3][2])+((cnk[8][0][0]*rk[3][0]
      )+(cnk[8][0][1]*rk[3][1]))));
    rnk[8][1] = ((rnk[7][1]+((cnk[7][1][2]*ri[3][2])+((cnk[7][1][0]*ri[3][0])+(
      cnk[7][1][1]*ri[3][1]))))-((cnk[8][1][2]*rk[3][2])+((cnk[8][1][0]*rk[3][0]
      )+(cnk[8][1][1]*rk[3][1]))));
    rnk[8][2] = ((rnk[7][2]+((cnk[7][2][2]*ri[3][2])+((cnk[7][2][0]*ri[3][0])+(
      cnk[7][2][1]*ri[3][1]))))-((cnk[8][2][2]*rk[3][2])+((cnk[8][2][0]*rk[3][0]
      )+(cnk[8][2][1]*rk[3][1]))));
    rnk[9][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[4][2])+((Cik[3][0][0]*ri[4][0])+(
      Cik[3][0][1]*ri[4][1]))))-((cnk[9][0][2]*rk[4][2])+((cnk[9][0][0]*rk[4][0]
      )+(cnk[9][0][1]*rk[4][1]))));
    rnk[9][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[4][2])+((Cik[3][1][0]*ri[4][0])+(
      Cik[3][1][1]*ri[4][1]))))-((cnk[9][1][2]*rk[4][2])+((cnk[9][1][0]*rk[4][0]
      )+(cnk[9][1][1]*rk[4][1]))));
    rnk[9][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[4][2])+((Cik[3][2][0]*ri[4][0])+(
      Cik[3][2][1]*ri[4][1]))))-((cnk[9][2][2]*rk[4][2])+((cnk[9][2][0]*rk[4][0]
      )+(cnk[9][2][1]*rk[4][1]))));
    rnk[10][0] = ((rnk[9][0]+((cnk[9][0][2]*ri[5][2])+((cnk[9][0][0]*ri[5][0])+(
      cnk[9][0][1]*ri[5][1]))))-((cnk[10][0][2]*rk[5][2])+((cnk[10][0][0]*
      rk[5][0])+(cnk[10][0][1]*rk[5][1]))));
    rnk[10][1] = ((rnk[9][1]+((cnk[9][1][2]*ri[5][2])+((cnk[9][1][0]*ri[5][0])+(
      cnk[9][1][1]*ri[5][1]))))-((cnk[10][1][2]*rk[5][2])+((cnk[10][1][0]*
      rk[5][0])+(cnk[10][1][1]*rk[5][1]))));
    rnk[10][2] = ((rnk[9][2]+((cnk[9][2][2]*ri[5][2])+((cnk[9][2][0]*ri[5][0])+(
      cnk[9][2][1]*ri[5][1]))))-((cnk[10][2][2]*rk[5][2])+((cnk[10][2][0]*
      rk[5][0])+(cnk[10][2][1]*rk[5][1]))));
    rnk[11][0] = ((rnk[10][0]+((cnk[10][0][2]*ri[6][2])+((cnk[10][0][0]*ri[6][0]
      )+(cnk[10][0][1]*ri[6][1]))))-((cnk[11][0][2]*rk[6][2])+((cnk[11][0][0]*
      rk[6][0])+(cnk[11][0][1]*rk[6][1]))));
    rnk[11][1] = ((rnk[10][1]+((cnk[10][1][2]*ri[6][2])+((cnk[10][1][0]*ri[6][0]
      )+(cnk[10][1][1]*ri[6][1]))))-((cnk[11][1][2]*rk[6][2])+((cnk[11][1][0]*
      rk[6][0])+(cnk[11][1][1]*rk[6][1]))));
    rnk[11][2] = ((rnk[10][2]+((cnk[10][2][2]*ri[6][2])+((cnk[10][2][0]*ri[6][0]
      )+(cnk[10][2][1]*ri[6][1]))))-((cnk[11][2][2]*rk[6][2])+((cnk[11][2][0]*
      rk[6][0])+(cnk[11][2][1]*rk[6][1]))));
    rnk[12][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[7][2])+((Cik[3][0][0]*ri[7][0])+(
      Cik[3][0][1]*ri[7][1]))))-((cnk[12][0][2]*rk[7][2])+((cnk[12][0][0]*
      rk[7][0])+(cnk[12][0][1]*rk[7][1]))));
    rnk[12][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[7][2])+((Cik[3][1][0]*ri[7][0])+(
      Cik[3][1][1]*ri[7][1]))))-((cnk[12][1][2]*rk[7][2])+((cnk[12][1][0]*
      rk[7][0])+(cnk[12][1][1]*rk[7][1]))));
    rnk[12][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[7][2])+((Cik[3][2][0]*ri[7][0])+(
      Cik[3][2][1]*ri[7][1]))))-((cnk[12][2][2]*rk[7][2])+((cnk[12][2][0]*
      rk[7][0])+(cnk[12][2][1]*rk[7][1]))));
    rnk[13][0] = ((rnk[12][0]+((cnk[12][0][2]*ri[8][2])+((cnk[12][0][0]*ri[8][0]
      )+(cnk[12][0][1]*ri[8][1]))))-((cnk[13][0][2]*rk[8][2])+((cnk[13][0][0]*
      rk[8][0])+(cnk[13][0][1]*rk[8][1]))));
    rnk[13][1] = ((rnk[12][1]+((cnk[12][1][2]*ri[8][2])+((cnk[12][1][0]*ri[8][0]
      )+(cnk[12][1][1]*ri[8][1]))))-((cnk[13][1][2]*rk[8][2])+((cnk[13][1][0]*
      rk[8][0])+(cnk[13][1][1]*rk[8][1]))));
    rnk[13][2] = ((rnk[12][2]+((cnk[12][2][2]*ri[8][2])+((cnk[12][2][0]*ri[8][0]
      )+(cnk[12][2][1]*ri[8][1]))))-((cnk[13][2][2]*rk[8][2])+((cnk[13][2][0]*
      rk[8][0])+(cnk[13][2][1]*rk[8][1]))));
    rnk[14][0] = ((rnk[13][0]+((cnk[13][0][2]*ri[9][2])+((cnk[13][0][0]*ri[9][0]
      )+(cnk[13][0][1]*ri[9][1]))))-((cnk[14][0][2]*rk[9][2])+((cnk[14][0][0]*
      rk[9][0])+(cnk[14][0][1]*rk[9][1]))));
    rnk[14][1] = ((rnk[13][1]+((cnk[13][1][2]*ri[9][2])+((cnk[13][1][0]*ri[9][0]
      )+(cnk[13][1][1]*ri[9][1]))))-((cnk[14][1][2]*rk[9][2])+((cnk[14][1][0]*
      rk[9][0])+(cnk[14][1][1]*rk[9][1]))));
    rnk[14][2] = ((rnk[13][2]+((cnk[13][2][2]*ri[9][2])+((cnk[13][2][0]*ri[9][0]
      )+(cnk[13][2][1]*ri[9][1]))))-((cnk[14][2][2]*rk[9][2])+((cnk[14][2][0]*
      rk[9][0])+(cnk[14][2][1]*rk[9][1]))));
    rnk[15][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[10][2])+((Cik[3][0][0]*ri[10][0])
      +(Cik[3][0][1]*ri[10][1]))))-((cnk[15][0][2]*rk[10][2])+((cnk[15][0][0]*
      rk[10][0])+(cnk[15][0][1]*rk[10][1]))));
    rnk[15][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[10][2])+((Cik[3][1][0]*ri[10][0])
      +(Cik[3][1][1]*ri[10][1]))))-((cnk[15][1][2]*rk[10][2])+((cnk[15][1][0]*
      rk[10][0])+(cnk[15][1][1]*rk[10][1]))));
    rnk[15][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[10][2])+((Cik[3][2][0]*ri[10][0])
      +(Cik[3][2][1]*ri[10][1]))))-((cnk[15][2][2]*rk[10][2])+((cnk[15][2][0]*
      rk[10][0])+(cnk[15][2][1]*rk[10][1]))));
    rnk[16][0] = ((rnk[15][0]+((cnk[15][0][2]*ri[11][2])+((cnk[15][0][0]*
      ri[11][0])+(cnk[15][0][1]*ri[11][1]))))-((cnk[16][0][2]*rk[11][2])+((
      cnk[16][0][0]*rk[11][0])+(cnk[16][0][1]*rk[11][1]))));
    rnk[16][1] = ((rnk[15][1]+((cnk[15][1][2]*ri[11][2])+((cnk[15][1][0]*
      ri[11][0])+(cnk[15][1][1]*ri[11][1]))))-((cnk[16][1][2]*rk[11][2])+((
      cnk[16][1][0]*rk[11][0])+(cnk[16][1][1]*rk[11][1]))));
    rnk[16][2] = ((rnk[15][2]+((cnk[15][2][2]*ri[11][2])+((cnk[15][2][0]*
      ri[11][0])+(cnk[15][2][1]*ri[11][1]))))-((cnk[16][2][2]*rk[11][2])+((
      cnk[16][2][0]*rk[11][0])+(cnk[16][2][1]*rk[11][1]))));
    rnk[17][0] = ((rnk[16][0]+((cnk[16][0][2]*ri[12][2])+((cnk[16][0][0]*
      ri[12][0])+(cnk[16][0][1]*ri[12][1]))))-((cnk[17][0][2]*rk[12][2])+((
      cnk[17][0][0]*rk[12][0])+(cnk[17][0][1]*rk[12][1]))));
    rnk[17][1] = ((rnk[16][1]+((cnk[16][1][2]*ri[12][2])+((cnk[16][1][0]*
      ri[12][0])+(cnk[16][1][1]*ri[12][1]))))-((cnk[17][1][2]*rk[12][2])+((
      cnk[17][1][0]*rk[12][0])+(cnk[17][1][1]*rk[12][1]))));
    rnk[17][2] = ((rnk[16][2]+((cnk[16][2][2]*ri[12][2])+((cnk[16][2][0]*
      ri[12][0])+(cnk[16][2][1]*ri[12][1]))))-((cnk[17][2][2]*rk[12][2])+((
      cnk[17][2][0]*rk[12][0])+(cnk[17][2][1]*rk[12][1]))));
    rnb[0][0] = rnk[5][0];
    rnb[0][1] = rnk[5][1];
    rnb[0][2] = rnk[5][2];
    rnb[1][0] = rnk[6][0];
    rnb[1][1] = rnk[6][1];
    rnb[1][2] = rnk[6][2];
    rnb[2][0] = rnk[7][0];
    rnb[2][1] = rnk[7][1];
    rnb[2][2] = rnk[7][2];
    rnb[3][0] = rnk[8][0];
    rnb[3][1] = rnk[8][1];
    rnb[3][2] = rnk[8][2];
    rnb[4][0] = rnk[9][0];
    rnb[4][1] = rnk[9][1];
    rnb[4][2] = rnk[9][2];
    rnb[5][0] = rnk[10][0];
    rnb[5][1] = rnk[10][1];
    rnb[5][2] = rnk[10][2];
    rnb[6][0] = rnk[11][0];
    rnb[6][1] = rnk[11][1];
    rnb[6][2] = rnk[11][2];
    rnb[7][0] = rnk[12][0];
    rnb[7][1] = rnk[12][1];
    rnb[7][2] = rnk[12][2];
    rnb[8][0] = rnk[13][0];
    rnb[8][1] = rnk[13][1];
    rnb[8][2] = rnk[13][2];
    rnb[9][0] = rnk[14][0];
    rnb[9][1] = rnk[14][1];
    rnb[9][2] = rnk[14][2];
    rnb[10][0] = rnk[15][0];
    rnb[10][1] = rnk[15][1];
    rnb[10][2] = rnk[15][2];
    rnb[11][0] = rnk[16][0];
    rnb[11][1] = rnk[16][1];
    rnb[11][2] = rnk[16][2];
    rnb[12][0] = rnk[17][0];
    rnb[12][1] = rnk[17][1];
    rnb[12][2] = rnk[17][2];
/*
Compute com (system mass center location in N)
*/
    com[0] = ((1./mtot)*((mk[12]*rnk[17][0])+((mk[11]*rnk[16][0])+((mk[10]*
      rnk[15][0])+((mk[9]*rnk[14][0])+((mk[8]*rnk[13][0])+((mk[7]*rnk[12][0])+((
      mk[6]*rnk[11][0])+((mk[5]*rnk[10][0])+((mk[4]*rnk[9][0])+((mk[3]*rnk[8][0]
      )+((mk[2]*rnk[7][0])+((mk[0]*rnk[5][0])+(mk[1]*rnk[6][0]))))))))))))));
    com[1] = ((1./mtot)*((mk[12]*rnk[17][1])+((mk[11]*rnk[16][1])+((mk[10]*
      rnk[15][1])+((mk[9]*rnk[14][1])+((mk[8]*rnk[13][1])+((mk[7]*rnk[12][1])+((
      mk[6]*rnk[11][1])+((mk[5]*rnk[10][1])+((mk[4]*rnk[9][1])+((mk[3]*rnk[8][1]
      )+((mk[2]*rnk[7][1])+((mk[0]*rnk[5][1])+(mk[1]*rnk[6][1]))))))))))))));
    com[2] = ((1./mtot)*((mk[12]*rnk[17][2])+((mk[11]*rnk[16][2])+((mk[10]*
      rnk[15][2])+((mk[9]*rnk[14][2])+((mk[8]*rnk[13][2])+((mk[7]*rnk[12][2])+((
      mk[6]*rnk[11][2])+((mk[5]*rnk[10][2])+((mk[4]*rnk[9][2])+((mk[3]*rnk[8][2]
      )+((mk[2]*rnk[7][2])+((mk[0]*rnk[5][2])+(mk[1]*rnk[6][2]))))))))))))));
    skipqs: ;
    if (uchg == 0) {
        goto skipus;
    }
/*
Velocity-related variables need to be computed
*/
    inerflg = 0;
    for (i = 0; i < 18; i++) {
        u[i] = uin[i];
    }
/*
Compute u-related auxiliary variables
*/
    Wik[6][0] = (pin[6][0]*u[6]);
    Wik[6][1] = (pin[6][1]*u[6]);
    Wik[6][2] = (pin[6][2]*u[6]);
    Wik[7][0] = (pin[7][0]*u[7]);
    Wik[7][1] = (pin[7][1]*u[7]);
    Wik[7][2] = (pin[7][2]*u[7]);
    Wik[8][0] = (pin[8][0]*u[8]);
    Wik[8][1] = (pin[8][1]*u[8]);
    Wik[8][2] = (pin[8][2]*u[8]);
    Wik[9][0] = (pin[9][0]*u[9]);
    Wik[9][1] = (pin[9][1]*u[9]);
    Wik[9][2] = (pin[9][2]*u[9]);
    Wik[10][0] = (pin[10][0]*u[10]);
    Wik[10][1] = (pin[10][1]*u[10]);
    Wik[10][2] = (pin[10][2]*u[10]);
    Wik[11][0] = (pin[11][0]*u[11]);
    Wik[11][1] = (pin[11][1]*u[11]);
    Wik[11][2] = (pin[11][2]*u[11]);
    Wik[12][0] = (pin[12][0]*u[12]);
    Wik[12][1] = (pin[12][1]*u[12]);
    Wik[12][2] = (pin[12][2]*u[12]);
    Wik[13][0] = (pin[13][0]*u[13]);
    Wik[13][1] = (pin[13][1]*u[13]);
    Wik[13][2] = (pin[13][2]*u[13]);
    Wik[14][0] = (pin[14][0]*u[14]);
    Wik[14][1] = (pin[14][1]*u[14]);
    Wik[14][2] = (pin[14][2]*u[14]);
    Wik[15][0] = (pin[15][0]*u[15]);
    Wik[15][1] = (pin[15][1]*u[15]);
    Wik[15][2] = (pin[15][2]*u[15]);
    Wik[16][0] = (pin[16][0]*u[16]);
    Wik[16][1] = (pin[16][1]*u[16]);
    Wik[16][2] = (pin[16][2]*u[16]);
    Wik[17][0] = (pin[17][0]*u[17]);
    Wik[17][1] = (pin[17][1]*u[17]);
    Wik[17][2] = (pin[17][2]*u[17]);
    Vik[0][0] = (pin[0][0]*u[0]);
    Vik[0][1] = (pin[0][1]*u[0]);
    Vik[0][2] = (pin[0][2]*u[0]);
    Vik[1][0] = (pin[1][0]*u[1]);
    Vik[1][1] = (pin[1][1]*u[1]);
    Vik[1][2] = (pin[1][2]*u[1]);
    Vik[2][0] = (pin[2][0]*u[2]);
    Vik[2][1] = (pin[2][1]*u[2]);
    Vik[2][2] = (pin[2][2]*u[2]);
/*
Compute wk & wb (angular velocities)
*/
    wk[6][0] = (Wik[6][0]+((Cik[6][2][0]*u[5])+((Cik[6][0][0]*u[3])+(
      Cik[6][1][0]*u[4]))));
    wk[6][1] = (Wik[6][1]+((Cik[6][2][1]*u[5])+((Cik[6][0][1]*u[3])+(
      Cik[6][1][1]*u[4]))));
    wk[6][2] = (Wik[6][2]+((Cik[6][2][2]*u[5])+((Cik[6][0][2]*u[3])+(
      Cik[6][1][2]*u[4]))));
    wk[7][0] = (Wik[7][0]+((Cik[7][2][0]*wk[6][2])+((Cik[7][0][0]*wk[6][0])+(
      Cik[7][1][0]*wk[6][1]))));
    wk[7][1] = (Wik[7][1]+((Cik[7][2][1]*wk[6][2])+((Cik[7][0][1]*wk[6][0])+(
      Cik[7][1][1]*wk[6][1]))));
    wk[7][2] = (Wik[7][2]+((Cik[7][2][2]*wk[6][2])+((Cik[7][0][2]*wk[6][0])+(
      Cik[7][1][2]*wk[6][1]))));
    wk[8][0] = (Wik[8][0]+((Cik[8][2][0]*wk[7][2])+((Cik[8][0][0]*wk[7][0])+(
      Cik[8][1][0]*wk[7][1]))));
    wk[8][1] = (Wik[8][1]+((Cik[8][2][1]*wk[7][2])+((Cik[8][0][1]*wk[7][0])+(
      Cik[8][1][1]*wk[7][1]))));
    wk[8][2] = (Wik[8][2]+((Cik[8][2][2]*wk[7][2])+((Cik[8][0][2]*wk[7][0])+(
      Cik[8][1][2]*wk[7][1]))));
    wk[9][0] = (Wik[9][0]+((Cik[9][2][0]*u[5])+((Cik[9][0][0]*u[3])+(
      Cik[9][1][0]*u[4]))));
    wk[9][1] = (Wik[9][1]+((Cik[9][2][1]*u[5])+((Cik[9][0][1]*u[3])+(
      Cik[9][1][1]*u[4]))));
    wk[9][2] = (Wik[9][2]+((Cik[9][2][2]*u[5])+((Cik[9][0][2]*u[3])+(
      Cik[9][1][2]*u[4]))));
    wk[10][0] = (Wik[10][0]+((Cik[10][2][0]*wk[9][2])+((Cik[10][0][0]*wk[9][0])+
      (Cik[10][1][0]*wk[9][1]))));
    wk[10][1] = (Wik[10][1]+((Cik[10][2][1]*wk[9][2])+((Cik[10][0][1]*wk[9][0])+
      (Cik[10][1][1]*wk[9][1]))));
    wk[10][2] = (Wik[10][2]+((Cik[10][2][2]*wk[9][2])+((Cik[10][0][2]*wk[9][0])+
      (Cik[10][1][2]*wk[9][1]))));
    wk[11][0] = (Wik[11][0]+((Cik[11][2][0]*wk[10][2])+((Cik[11][0][0]*wk[10][0]
      )+(Cik[11][1][0]*wk[10][1]))));
    wk[11][1] = (Wik[11][1]+((Cik[11][2][1]*wk[10][2])+((Cik[11][0][1]*wk[10][0]
      )+(Cik[11][1][1]*wk[10][1]))));
    wk[11][2] = (Wik[11][2]+((Cik[11][2][2]*wk[10][2])+((Cik[11][0][2]*wk[10][0]
      )+(Cik[11][1][2]*wk[10][1]))));
    wk[12][0] = (Wik[12][0]+((Cik[12][2][0]*u[5])+((Cik[12][0][0]*u[3])+(
      Cik[12][1][0]*u[4]))));
    wk[12][1] = (Wik[12][1]+((Cik[12][2][1]*u[5])+((Cik[12][0][1]*u[3])+(
      Cik[12][1][1]*u[4]))));
    wk[12][2] = (Wik[12][2]+((Cik[12][2][2]*u[5])+((Cik[12][0][2]*u[3])+(
      Cik[12][1][2]*u[4]))));
    wk[13][0] = (Wik[13][0]+((Cik[13][2][0]*wk[12][2])+((Cik[13][0][0]*wk[12][0]
      )+(Cik[13][1][0]*wk[12][1]))));
    wk[13][1] = (Wik[13][1]+((Cik[13][2][1]*wk[12][2])+((Cik[13][0][1]*wk[12][0]
      )+(Cik[13][1][1]*wk[12][1]))));
    wk[13][2] = (Wik[13][2]+((Cik[13][2][2]*wk[12][2])+((Cik[13][0][2]*wk[12][0]
      )+(Cik[13][1][2]*wk[12][1]))));
    wk[14][0] = (Wik[14][0]+((Cik[14][2][0]*wk[13][2])+((Cik[14][0][0]*wk[13][0]
      )+(Cik[14][1][0]*wk[13][1]))));
    wk[14][1] = (Wik[14][1]+((Cik[14][2][1]*wk[13][2])+((Cik[14][0][1]*wk[13][0]
      )+(Cik[14][1][1]*wk[13][1]))));
    wk[14][2] = (Wik[14][2]+((Cik[14][2][2]*wk[13][2])+((Cik[14][0][2]*wk[13][0]
      )+(Cik[14][1][2]*wk[13][1]))));
    wk[15][0] = (Wik[15][0]+((Cik[15][2][0]*u[5])+((Cik[15][0][0]*u[3])+(
      Cik[15][1][0]*u[4]))));
    wk[15][1] = (Wik[15][1]+((Cik[15][2][1]*u[5])+((Cik[15][0][1]*u[3])+(
      Cik[15][1][1]*u[4]))));
    wk[15][2] = (Wik[15][2]+((Cik[15][2][2]*u[5])+((Cik[15][0][2]*u[3])+(
      Cik[15][1][2]*u[4]))));
    wk[16][0] = (Wik[16][0]+((Cik[16][2][0]*wk[15][2])+((Cik[16][0][0]*wk[15][0]
      )+(Cik[16][1][0]*wk[15][1]))));
    wk[16][1] = (Wik[16][1]+((Cik[16][2][1]*wk[15][2])+((Cik[16][0][1]*wk[15][0]
      )+(Cik[16][1][1]*wk[15][1]))));
    wk[16][2] = (Wik[16][2]+((Cik[16][2][2]*wk[15][2])+((Cik[16][0][2]*wk[15][0]
      )+(Cik[16][1][2]*wk[15][1]))));
    wk[17][0] = (Wik[17][0]+((Cik[17][2][0]*wk[16][2])+((Cik[17][0][0]*wk[16][0]
      )+(Cik[17][1][0]*wk[16][1]))));
    wk[17][1] = (Wik[17][1]+((Cik[17][2][1]*wk[16][2])+((Cik[17][0][1]*wk[16][0]
      )+(Cik[17][1][1]*wk[16][1]))));
    wk[17][2] = (Wik[17][2]+((Cik[17][2][2]*wk[16][2])+((Cik[17][0][2]*wk[16][0]
      )+(Cik[17][1][2]*wk[16][1]))));
    wb[0][0] = u[3];
    wb[0][1] = u[4];
    wb[0][2] = u[5];
    wb[1][0] = wk[6][0];
    wb[1][1] = wk[6][1];
    wb[1][2] = wk[6][2];
    wb[2][0] = wk[7][0];
    wb[2][1] = wk[7][1];
    wb[2][2] = wk[7][2];
    wb[3][0] = wk[8][0];
    wb[3][1] = wk[8][1];
    wb[3][2] = wk[8][2];
    wb[4][0] = wk[9][0];
    wb[4][1] = wk[9][1];
    wb[4][2] = wk[9][2];
    wb[5][0] = wk[10][0];
    wb[5][1] = wk[10][1];
    wb[5][2] = wk[10][2];
    wb[6][0] = wk[11][0];
    wb[6][1] = wk[11][1];
    wb[6][2] = wk[11][2];
    wb[7][0] = wk[12][0];
    wb[7][1] = wk[12][1];
    wb[7][2] = wk[12][2];
    wb[8][0] = wk[13][0];
    wb[8][1] = wk[13][1];
    wb[8][2] = wk[13][2];
    wb[9][0] = wk[14][0];
    wb[9][1] = wk[14][1];
    wb[9][2] = wk[14][2];
    wb[10][0] = wk[15][0];
    wb[10][1] = wk[15][1];
    wb[10][2] = wk[15][2];
    wb[11][0] = wk[16][0];
    wb[11][1] = wk[16][1];
    wb[11][2] = wk[16][2];
    wb[12][0] = wk[17][0];
    wb[12][1] = wk[17][1];
    wb[12][2] = wk[17][2];
/*
Compute auxiliary variables involving wk
*/
    Wirk[6][0] = ((ri[1][2]*u[4])-(ri[1][1]*u[5]));
    Wirk[6][1] = ((ri[1][0]*u[5])-(ri[1][2]*u[3]));
    Wirk[6][2] = ((ri[1][1]*u[3])-(ri[1][0]*u[4]));
    Wirk[7][0] = ((ri[2][2]*wk[6][1])-(ri[2][1]*wk[6][2]));
    Wirk[7][1] = ((ri[2][0]*wk[6][2])-(ri[2][2]*wk[6][0]));
    Wirk[7][2] = ((ri[2][1]*wk[6][0])-(ri[2][0]*wk[6][1]));
    Wirk[8][0] = ((ri[3][2]*wk[7][1])-(ri[3][1]*wk[7][2]));
    Wirk[8][1] = ((ri[3][0]*wk[7][2])-(ri[3][2]*wk[7][0]));
    Wirk[8][2] = ((ri[3][1]*wk[7][0])-(ri[3][0]*wk[7][1]));
    Wirk[9][0] = ((ri[4][2]*u[4])-(ri[4][1]*u[5]));
    Wirk[9][1] = ((ri[4][0]*u[5])-(ri[4][2]*u[3]));
    Wirk[9][2] = ((ri[4][1]*u[3])-(ri[4][0]*u[4]));
    Wirk[10][0] = ((ri[5][2]*wk[9][1])-(ri[5][1]*wk[9][2]));
    Wirk[10][1] = ((ri[5][0]*wk[9][2])-(ri[5][2]*wk[9][0]));
    Wirk[10][2] = ((ri[5][1]*wk[9][0])-(ri[5][0]*wk[9][1]));
    Wirk[11][0] = ((ri[6][2]*wk[10][1])-(ri[6][1]*wk[10][2]));
    Wirk[11][1] = ((ri[6][0]*wk[10][2])-(ri[6][2]*wk[10][0]));
    Wirk[11][2] = ((ri[6][1]*wk[10][0])-(ri[6][0]*wk[10][1]));
    Wirk[12][0] = ((ri[7][2]*u[4])-(ri[7][1]*u[5]));
    Wirk[12][1] = ((ri[7][0]*u[5])-(ri[7][2]*u[3]));
    Wirk[12][2] = ((ri[7][1]*u[3])-(ri[7][0]*u[4]));
    Wirk[13][0] = ((ri[8][2]*wk[12][1])-(ri[8][1]*wk[12][2]));
    Wirk[13][1] = ((ri[8][0]*wk[12][2])-(ri[8][2]*wk[12][0]));
    Wirk[13][2] = ((ri[8][1]*wk[12][0])-(ri[8][0]*wk[12][1]));
    Wirk[14][0] = ((ri[9][2]*wk[13][1])-(ri[9][1]*wk[13][2]));
    Wirk[14][1] = ((ri[9][0]*wk[13][2])-(ri[9][2]*wk[13][0]));
    Wirk[14][2] = ((ri[9][1]*wk[13][0])-(ri[9][0]*wk[13][1]));
    Wirk[15][0] = ((ri[10][2]*u[4])-(ri[10][1]*u[5]));
    Wirk[15][1] = ((ri[10][0]*u[5])-(ri[10][2]*u[3]));
    Wirk[15][2] = ((ri[10][1]*u[3])-(ri[10][0]*u[4]));
    Wirk[16][0] = ((ri[11][2]*wk[15][1])-(ri[11][1]*wk[15][2]));
    Wirk[16][1] = ((ri[11][0]*wk[15][2])-(ri[11][2]*wk[15][0]));
    Wirk[16][2] = ((ri[11][1]*wk[15][0])-(ri[11][0]*wk[15][1]));
    Wirk[17][0] = ((ri[12][2]*wk[16][1])-(ri[12][1]*wk[16][2]));
    Wirk[17][1] = ((ri[12][0]*wk[16][2])-(ri[12][2]*wk[16][0]));
    Wirk[17][2] = ((ri[12][1]*wk[16][0])-(ri[12][0]*wk[16][1]));
    Wkrpk[5][0] = ((rk[0][1]*u[5])-(rk[0][2]*u[4]));
    Wkrpk[5][1] = ((rk[0][2]*u[3])-(rk[0][0]*u[5]));
    Wkrpk[5][2] = ((rk[0][0]*u[4])-(rk[0][1]*u[3]));
    Wkrpk[6][0] = ((rk[1][1]*wk[6][2])-(rk[1][2]*wk[6][1]));
    Wkrpk[6][1] = ((rk[1][2]*wk[6][0])-(rk[1][0]*wk[6][2]));
    Wkrpk[6][2] = ((rk[1][0]*wk[6][1])-(rk[1][1]*wk[6][0]));
    Wkrpk[7][0] = ((rk[2][1]*wk[7][2])-(rk[2][2]*wk[7][1]));
    Wkrpk[7][1] = ((rk[2][2]*wk[7][0])-(rk[2][0]*wk[7][2]));
    Wkrpk[7][2] = ((rk[2][0]*wk[7][1])-(rk[2][1]*wk[7][0]));
    Wkrpk[8][0] = ((rk[3][1]*wk[8][2])-(rk[3][2]*wk[8][1]));
    Wkrpk[8][1] = ((rk[3][2]*wk[8][0])-(rk[3][0]*wk[8][2]));
    Wkrpk[8][2] = ((rk[3][0]*wk[8][1])-(rk[3][1]*wk[8][0]));
    Wkrpk[9][0] = ((rk[4][1]*wk[9][2])-(rk[4][2]*wk[9][1]));
    Wkrpk[9][1] = ((rk[4][2]*wk[9][0])-(rk[4][0]*wk[9][2]));
    Wkrpk[9][2] = ((rk[4][0]*wk[9][1])-(rk[4][1]*wk[9][0]));
    Wkrpk[10][0] = ((rk[5][1]*wk[10][2])-(rk[5][2]*wk[10][1]));
    Wkrpk[10][1] = ((rk[5][2]*wk[10][0])-(rk[5][0]*wk[10][2]));
    Wkrpk[10][2] = ((rk[5][0]*wk[10][1])-(rk[5][1]*wk[10][0]));
    Wkrpk[11][0] = ((rk[6][1]*wk[11][2])-(rk[6][2]*wk[11][1]));
    Wkrpk[11][1] = ((rk[6][2]*wk[11][0])-(rk[6][0]*wk[11][2]));
    Wkrpk[11][2] = ((rk[6][0]*wk[11][1])-(rk[6][1]*wk[11][0]));
    Wkrpk[12][0] = ((rk[7][1]*wk[12][2])-(rk[7][2]*wk[12][1]));
    Wkrpk[12][1] = ((rk[7][2]*wk[12][0])-(rk[7][0]*wk[12][2]));
    Wkrpk[12][2] = ((rk[7][0]*wk[12][1])-(rk[7][1]*wk[12][0]));
    Wkrpk[13][0] = ((rk[8][1]*wk[13][2])-(rk[8][2]*wk[13][1]));
    Wkrpk[13][1] = ((rk[8][2]*wk[13][0])-(rk[8][0]*wk[13][2]));
    Wkrpk[13][2] = ((rk[8][0]*wk[13][1])-(rk[8][1]*wk[13][0]));
    Wkrpk[14][0] = ((rk[9][1]*wk[14][2])-(rk[9][2]*wk[14][1]));
    Wkrpk[14][1] = ((rk[9][2]*wk[14][0])-(rk[9][0]*wk[14][2]));
    Wkrpk[14][2] = ((rk[9][0]*wk[14][1])-(rk[9][1]*wk[14][0]));
    Wkrpk[15][0] = ((rk[10][1]*wk[15][2])-(rk[10][2]*wk[15][1]));
    Wkrpk[15][1] = ((rk[10][2]*wk[15][0])-(rk[10][0]*wk[15][2]));
    Wkrpk[15][2] = ((rk[10][0]*wk[15][1])-(rk[10][1]*wk[15][0]));
    Wkrpk[16][0] = ((rk[11][1]*wk[16][2])-(rk[11][2]*wk[16][1]));
    Wkrpk[16][1] = ((rk[11][2]*wk[16][0])-(rk[11][0]*wk[16][2]));
    Wkrpk[16][2] = ((rk[11][0]*wk[16][1])-(rk[11][1]*wk[16][0]));
    Wkrpk[17][0] = ((rk[12][1]*wk[17][2])-(rk[12][2]*wk[17][1]));
    Wkrpk[17][1] = ((rk[12][2]*wk[17][0])-(rk[12][0]*wk[17][2]));
    Wkrpk[17][2] = ((rk[12][0]*wk[17][1])-(rk[12][1]*wk[17][0]));
    IkWk[5][0] = ((ik[0][0][2]*u[5])+((ik[0][0][0]*u[3])+(ik[0][0][1]*u[4])));
    IkWk[5][1] = ((ik[0][1][2]*u[5])+((ik[0][1][0]*u[3])+(ik[0][1][1]*u[4])));
    IkWk[5][2] = ((ik[0][2][2]*u[5])+((ik[0][2][0]*u[3])+(ik[0][2][1]*u[4])));
    WkIkWk[5][0] = ((IkWk[5][2]*u[4])-(IkWk[5][1]*u[5]));
    WkIkWk[5][1] = ((IkWk[5][0]*u[5])-(IkWk[5][2]*u[3]));
    WkIkWk[5][2] = ((IkWk[5][1]*u[3])-(IkWk[5][0]*u[4]));
    IkWk[6][0] = ((ik[1][0][2]*wk[6][2])+((ik[1][0][0]*wk[6][0])+(ik[1][0][1]*
      wk[6][1])));
    IkWk[6][1] = ((ik[1][1][2]*wk[6][2])+((ik[1][1][0]*wk[6][0])+(ik[1][1][1]*
      wk[6][1])));
    IkWk[6][2] = ((ik[1][2][2]*wk[6][2])+((ik[1][2][0]*wk[6][0])+(ik[1][2][1]*
      wk[6][1])));
    WkIkWk[6][0] = ((IkWk[6][2]*wk[6][1])-(IkWk[6][1]*wk[6][2]));
    WkIkWk[6][1] = ((IkWk[6][0]*wk[6][2])-(IkWk[6][2]*wk[6][0]));
    WkIkWk[6][2] = ((IkWk[6][1]*wk[6][0])-(IkWk[6][0]*wk[6][1]));
    IkWk[7][0] = ((ik[2][0][2]*wk[7][2])+((ik[2][0][0]*wk[7][0])+(ik[2][0][1]*
      wk[7][1])));
    IkWk[7][1] = ((ik[2][1][2]*wk[7][2])+((ik[2][1][0]*wk[7][0])+(ik[2][1][1]*
      wk[7][1])));
    IkWk[7][2] = ((ik[2][2][2]*wk[7][2])+((ik[2][2][0]*wk[7][0])+(ik[2][2][1]*
      wk[7][1])));
    WkIkWk[7][0] = ((IkWk[7][2]*wk[7][1])-(IkWk[7][1]*wk[7][2]));
    WkIkWk[7][1] = ((IkWk[7][0]*wk[7][2])-(IkWk[7][2]*wk[7][0]));
    WkIkWk[7][2] = ((IkWk[7][1]*wk[7][0])-(IkWk[7][0]*wk[7][1]));
    IkWk[8][0] = ((ik[3][0][2]*wk[8][2])+((ik[3][0][0]*wk[8][0])+(ik[3][0][1]*
      wk[8][1])));
    IkWk[8][1] = ((ik[3][1][2]*wk[8][2])+((ik[3][1][0]*wk[8][0])+(ik[3][1][1]*
      wk[8][1])));
    IkWk[8][2] = ((ik[3][2][2]*wk[8][2])+((ik[3][2][0]*wk[8][0])+(ik[3][2][1]*
      wk[8][1])));
    WkIkWk[8][0] = ((IkWk[8][2]*wk[8][1])-(IkWk[8][1]*wk[8][2]));
    WkIkWk[8][1] = ((IkWk[8][0]*wk[8][2])-(IkWk[8][2]*wk[8][0]));
    WkIkWk[8][2] = ((IkWk[8][1]*wk[8][0])-(IkWk[8][0]*wk[8][1]));
    IkWk[9][0] = ((ik[4][0][2]*wk[9][2])+((ik[4][0][0]*wk[9][0])+(ik[4][0][1]*
      wk[9][1])));
    IkWk[9][1] = ((ik[4][1][2]*wk[9][2])+((ik[4][1][0]*wk[9][0])+(ik[4][1][1]*
      wk[9][1])));
    IkWk[9][2] = ((ik[4][2][2]*wk[9][2])+((ik[4][2][0]*wk[9][0])+(ik[4][2][1]*
      wk[9][1])));
    WkIkWk[9][0] = ((IkWk[9][2]*wk[9][1])-(IkWk[9][1]*wk[9][2]));
    WkIkWk[9][1] = ((IkWk[9][0]*wk[9][2])-(IkWk[9][2]*wk[9][0]));
    WkIkWk[9][2] = ((IkWk[9][1]*wk[9][0])-(IkWk[9][0]*wk[9][1]));
    IkWk[10][0] = ((ik[5][0][2]*wk[10][2])+((ik[5][0][0]*wk[10][0])+(ik[5][0][1]
      *wk[10][1])));
    IkWk[10][1] = ((ik[5][1][2]*wk[10][2])+((ik[5][1][0]*wk[10][0])+(ik[5][1][1]
      *wk[10][1])));
    IkWk[10][2] = ((ik[5][2][2]*wk[10][2])+((ik[5][2][0]*wk[10][0])+(ik[5][2][1]
      *wk[10][1])));
    WkIkWk[10][0] = ((IkWk[10][2]*wk[10][1])-(IkWk[10][1]*wk[10][2]));
    WkIkWk[10][1] = ((IkWk[10][0]*wk[10][2])-(IkWk[10][2]*wk[10][0]));
    WkIkWk[10][2] = ((IkWk[10][1]*wk[10][0])-(IkWk[10][0]*wk[10][1]));
    IkWk[11][0] = ((ik[6][0][2]*wk[11][2])+((ik[6][0][0]*wk[11][0])+(ik[6][0][1]
      *wk[11][1])));
    IkWk[11][1] = ((ik[6][1][2]*wk[11][2])+((ik[6][1][0]*wk[11][0])+(ik[6][1][1]
      *wk[11][1])));
    IkWk[11][2] = ((ik[6][2][2]*wk[11][2])+((ik[6][2][0]*wk[11][0])+(ik[6][2][1]
      *wk[11][1])));
    WkIkWk[11][0] = ((IkWk[11][2]*wk[11][1])-(IkWk[11][1]*wk[11][2]));
    WkIkWk[11][1] = ((IkWk[11][0]*wk[11][2])-(IkWk[11][2]*wk[11][0]));
    WkIkWk[11][2] = ((IkWk[11][1]*wk[11][0])-(IkWk[11][0]*wk[11][1]));
    IkWk[12][0] = ((ik[7][0][2]*wk[12][2])+((ik[7][0][0]*wk[12][0])+(ik[7][0][1]
      *wk[12][1])));
    IkWk[12][1] = ((ik[7][1][2]*wk[12][2])+((ik[7][1][0]*wk[12][0])+(ik[7][1][1]
      *wk[12][1])));
    IkWk[12][2] = ((ik[7][2][2]*wk[12][2])+((ik[7][2][0]*wk[12][0])+(ik[7][2][1]
      *wk[12][1])));
    WkIkWk[12][0] = ((IkWk[12][2]*wk[12][1])-(IkWk[12][1]*wk[12][2]));
    WkIkWk[12][1] = ((IkWk[12][0]*wk[12][2])-(IkWk[12][2]*wk[12][0]));
    WkIkWk[12][2] = ((IkWk[12][1]*wk[12][0])-(IkWk[12][0]*wk[12][1]));
    IkWk[13][0] = ((ik[8][0][2]*wk[13][2])+((ik[8][0][0]*wk[13][0])+(ik[8][0][1]
      *wk[13][1])));
    IkWk[13][1] = ((ik[8][1][2]*wk[13][2])+((ik[8][1][0]*wk[13][0])+(ik[8][1][1]
      *wk[13][1])));
    IkWk[13][2] = ((ik[8][2][2]*wk[13][2])+((ik[8][2][0]*wk[13][0])+(ik[8][2][1]
      *wk[13][1])));
    WkIkWk[13][0] = ((IkWk[13][2]*wk[13][1])-(IkWk[13][1]*wk[13][2]));
    WkIkWk[13][1] = ((IkWk[13][0]*wk[13][2])-(IkWk[13][2]*wk[13][0]));
    WkIkWk[13][2] = ((IkWk[13][1]*wk[13][0])-(IkWk[13][0]*wk[13][1]));
    IkWk[14][0] = ((ik[9][0][2]*wk[14][2])+((ik[9][0][0]*wk[14][0])+(ik[9][0][1]
      *wk[14][1])));
    IkWk[14][1] = ((ik[9][1][2]*wk[14][2])+((ik[9][1][0]*wk[14][0])+(ik[9][1][1]
      *wk[14][1])));
    IkWk[14][2] = ((ik[9][2][2]*wk[14][2])+((ik[9][2][0]*wk[14][0])+(ik[9][2][1]
      *wk[14][1])));
    WkIkWk[14][0] = ((IkWk[14][2]*wk[14][1])-(IkWk[14][1]*wk[14][2]));
    WkIkWk[14][1] = ((IkWk[14][0]*wk[14][2])-(IkWk[14][2]*wk[14][0]));
    WkIkWk[14][2] = ((IkWk[14][1]*wk[14][0])-(IkWk[14][0]*wk[14][1]));
    IkWk[15][0] = ((ik[10][0][2]*wk[15][2])+((ik[10][0][0]*wk[15][0])+(
      ik[10][0][1]*wk[15][1])));
    IkWk[15][1] = ((ik[10][1][2]*wk[15][2])+((ik[10][1][0]*wk[15][0])+(
      ik[10][1][1]*wk[15][1])));
    IkWk[15][2] = ((ik[10][2][2]*wk[15][2])+((ik[10][2][0]*wk[15][0])+(
      ik[10][2][1]*wk[15][1])));
    WkIkWk[15][0] = ((IkWk[15][2]*wk[15][1])-(IkWk[15][1]*wk[15][2]));
    WkIkWk[15][1] = ((IkWk[15][0]*wk[15][2])-(IkWk[15][2]*wk[15][0]));
    WkIkWk[15][2] = ((IkWk[15][1]*wk[15][0])-(IkWk[15][0]*wk[15][1]));
    IkWk[16][0] = ((ik[11][0][2]*wk[16][2])+((ik[11][0][0]*wk[16][0])+(
      ik[11][0][1]*wk[16][1])));
    IkWk[16][1] = ((ik[11][1][2]*wk[16][2])+((ik[11][1][0]*wk[16][0])+(
      ik[11][1][1]*wk[16][1])));
    IkWk[16][2] = ((ik[11][2][2]*wk[16][2])+((ik[11][2][0]*wk[16][0])+(
      ik[11][2][1]*wk[16][1])));
    WkIkWk[16][0] = ((IkWk[16][2]*wk[16][1])-(IkWk[16][1]*wk[16][2]));
    WkIkWk[16][1] = ((IkWk[16][0]*wk[16][2])-(IkWk[16][2]*wk[16][0]));
    WkIkWk[16][2] = ((IkWk[16][1]*wk[16][0])-(IkWk[16][0]*wk[16][1]));
    IkWk[17][0] = ((ik[12][0][2]*wk[17][2])+((ik[12][0][0]*wk[17][0])+(
      ik[12][0][1]*wk[17][1])));
    IkWk[17][1] = ((ik[12][1][2]*wk[17][2])+((ik[12][1][0]*wk[17][0])+(
      ik[12][1][1]*wk[17][1])));
    IkWk[17][2] = ((ik[12][2][2]*wk[17][2])+((ik[12][2][0]*wk[17][0])+(
      ik[12][2][1]*wk[17][1])));
    WkIkWk[17][0] = ((IkWk[17][2]*wk[17][1])-(IkWk[17][1]*wk[17][2]));
    WkIkWk[17][1] = ((IkWk[17][0]*wk[17][2])-(IkWk[17][2]*wk[17][0]));
    WkIkWk[17][2] = ((IkWk[17][1]*wk[17][0])-(IkWk[17][0]*wk[17][1]));
/*
Compute temporaries for use in SDRHS
*/
    w0w0[0] = (u[3]*u[3]);
    w0w0[1] = (wk[6][0]*wk[6][0]);
    w0w0[2] = (wk[7][0]*wk[7][0]);
    w0w0[3] = (wk[8][0]*wk[8][0]);
    w0w0[4] = (wk[9][0]*wk[9][0]);
    w0w0[5] = (wk[10][0]*wk[10][0]);
    w0w0[6] = (wk[11][0]*wk[11][0]);
    w0w0[7] = (wk[12][0]*wk[12][0]);
    w0w0[8] = (wk[13][0]*wk[13][0]);
    w0w0[9] = (wk[14][0]*wk[14][0]);
    w0w0[10] = (wk[15][0]*wk[15][0]);
    w0w0[11] = (wk[16][0]*wk[16][0]);
    w0w0[12] = (wk[17][0]*wk[17][0]);
    w1w1[0] = (u[4]*u[4]);
    w1w1[1] = (wk[6][1]*wk[6][1]);
    w1w1[2] = (wk[7][1]*wk[7][1]);
    w1w1[3] = (wk[8][1]*wk[8][1]);
    w1w1[4] = (wk[9][1]*wk[9][1]);
    w1w1[5] = (wk[10][1]*wk[10][1]);
    w1w1[6] = (wk[11][1]*wk[11][1]);
    w1w1[7] = (wk[12][1]*wk[12][1]);
    w1w1[8] = (wk[13][1]*wk[13][1]);
    w1w1[9] = (wk[14][1]*wk[14][1]);
    w1w1[10] = (wk[15][1]*wk[15][1]);
    w1w1[11] = (wk[16][1]*wk[16][1]);
    w1w1[12] = (wk[17][1]*wk[17][1]);
    w2w2[0] = (u[5]*u[5]);
    w2w2[1] = (wk[6][2]*wk[6][2]);
    w2w2[2] = (wk[7][2]*wk[7][2]);
    w2w2[3] = (wk[8][2]*wk[8][2]);
    w2w2[4] = (wk[9][2]*wk[9][2]);
    w2w2[5] = (wk[10][2]*wk[10][2]);
    w2w2[6] = (wk[11][2]*wk[11][2]);
    w2w2[7] = (wk[12][2]*wk[12][2]);
    w2w2[8] = (wk[13][2]*wk[13][2]);
    w2w2[9] = (wk[14][2]*wk[14][2]);
    w2w2[10] = (wk[15][2]*wk[15][2]);
    w2w2[11] = (wk[16][2]*wk[16][2]);
    w2w2[12] = (wk[17][2]*wk[17][2]);
    w0w1[0] = (u[3]*u[4]);
    w0w1[1] = (wk[6][0]*wk[6][1]);
    w0w1[2] = (wk[7][0]*wk[7][1]);
    w0w1[3] = (wk[8][0]*wk[8][1]);
    w0w1[4] = (wk[9][0]*wk[9][1]);
    w0w1[5] = (wk[10][0]*wk[10][1]);
    w0w1[6] = (wk[11][0]*wk[11][1]);
    w0w1[7] = (wk[12][0]*wk[12][1]);
    w0w1[8] = (wk[13][0]*wk[13][1]);
    w0w1[9] = (wk[14][0]*wk[14][1]);
    w0w1[10] = (wk[15][0]*wk[15][1]);
    w0w1[11] = (wk[16][0]*wk[16][1]);
    w0w1[12] = (wk[17][0]*wk[17][1]);
    w0w2[0] = (u[3]*u[5]);
    w0w2[1] = (wk[6][0]*wk[6][2]);
    w0w2[2] = (wk[7][0]*wk[7][2]);
    w0w2[3] = (wk[8][0]*wk[8][2]);
    w0w2[4] = (wk[9][0]*wk[9][2]);
    w0w2[5] = (wk[10][0]*wk[10][2]);
    w0w2[6] = (wk[11][0]*wk[11][2]);
    w0w2[7] = (wk[12][0]*wk[12][2]);
    w0w2[8] = (wk[13][0]*wk[13][2]);
    w0w2[9] = (wk[14][0]*wk[14][2]);
    w0w2[10] = (wk[15][0]*wk[15][2]);
    w0w2[11] = (wk[16][0]*wk[16][2]);
    w0w2[12] = (wk[17][0]*wk[17][2]);
    w1w2[0] = (u[4]*u[5]);
    w1w2[1] = (wk[6][1]*wk[6][2]);
    w1w2[2] = (wk[7][1]*wk[7][2]);
    w1w2[3] = (wk[8][1]*wk[8][2]);
    w1w2[4] = (wk[9][1]*wk[9][2]);
    w1w2[5] = (wk[10][1]*wk[10][2]);
    w1w2[6] = (wk[11][1]*wk[11][2]);
    w1w2[7] = (wk[12][1]*wk[12][2]);
    w1w2[8] = (wk[13][1]*wk[13][2]);
    w1w2[9] = (wk[14][1]*wk[14][2]);
    w1w2[10] = (wk[15][1]*wk[15][2]);
    w1w2[11] = (wk[16][1]*wk[16][2]);
    w1w2[12] = (wk[17][1]*wk[17][2]);
    w00w11[0] = -(w0w0[0]+w1w1[0]);
    w00w11[1] = -(w0w0[1]+w1w1[1]);
    w00w11[2] = -(w0w0[2]+w1w1[2]);
    w00w11[3] = -(w0w0[3]+w1w1[3]);
    w00w11[4] = -(w0w0[4]+w1w1[4]);
    w00w11[5] = -(w0w0[5]+w1w1[5]);
    w00w11[6] = -(w0w0[6]+w1w1[6]);
    w00w11[7] = -(w0w0[7]+w1w1[7]);
    w00w11[8] = -(w0w0[8]+w1w1[8]);
    w00w11[9] = -(w0w0[9]+w1w1[9]);
    w00w11[10] = -(w0w0[10]+w1w1[10]);
    w00w11[11] = -(w0w0[11]+w1w1[11]);
    w00w11[12] = -(w0w0[12]+w1w1[12]);
    w00w22[0] = -(w0w0[0]+w2w2[0]);
    w00w22[1] = -(w0w0[1]+w2w2[1]);
    w00w22[2] = -(w0w0[2]+w2w2[2]);
    w00w22[3] = -(w0w0[3]+w2w2[3]);
    w00w22[4] = -(w0w0[4]+w2w2[4]);
    w00w22[5] = -(w0w0[5]+w2w2[5]);
    w00w22[6] = -(w0w0[6]+w2w2[6]);
    w00w22[7] = -(w0w0[7]+w2w2[7]);
    w00w22[8] = -(w0w0[8]+w2w2[8]);
    w00w22[9] = -(w0w0[9]+w2w2[9]);
    w00w22[10] = -(w0w0[10]+w2w2[10]);
    w00w22[11] = -(w0w0[11]+w2w2[11]);
    w00w22[12] = -(w0w0[12]+w2w2[12]);
    w11w22[0] = -(w1w1[0]+w2w2[0]);
    w11w22[1] = -(w1w1[1]+w2w2[1]);
    w11w22[2] = -(w1w1[2]+w2w2[2]);
    w11w22[3] = -(w1w1[3]+w2w2[3]);
    w11w22[4] = -(w1w1[4]+w2w2[4]);
    w11w22[5] = -(w1w1[5]+w2w2[5]);
    w11w22[6] = -(w1w1[6]+w2w2[6]);
    w11w22[7] = -(w1w1[7]+w2w2[7]);
    w11w22[8] = -(w1w1[8]+w2w2[8]);
    w11w22[9] = -(w1w1[9]+w2w2[9]);
    w11w22[10] = -(w1w1[10]+w2w2[10]);
    w11w22[11] = -(w1w1[11]+w2w2[11]);
    w11w22[12] = -(w1w1[12]+w2w2[12]);
/*
Compute vnk & vnb (mass center linear velocities in N)
*/
    vnk[1][0] = (Vik[0][0]+Vik[1][0]);
    vnk[1][1] = (Vik[0][1]+Vik[1][1]);
    vnk[1][2] = (Vik[0][2]+Vik[1][2]);
    vnk[2][0] = (Vik[2][0]+vnk[1][0]);
    vnk[2][1] = (Vik[2][1]+vnk[1][1]);
    vnk[2][2] = (Vik[2][2]+vnk[1][2]);
    vnk[5][0] = (vnk[2][0]+((Cik[3][0][2]*Wkrpk[5][2])+((Cik[3][0][0]*
      Wkrpk[5][0])+(Cik[3][0][1]*Wkrpk[5][1]))));
    vnk[5][1] = (vnk[2][1]+((Cik[3][1][2]*Wkrpk[5][2])+((Cik[3][1][0]*
      Wkrpk[5][0])+(Cik[3][1][1]*Wkrpk[5][1]))));
    vnk[5][2] = (vnk[2][2]+((Cik[3][2][2]*Wkrpk[5][2])+((Cik[3][2][0]*
      Wkrpk[5][0])+(Cik[3][2][1]*Wkrpk[5][1]))));
    vnk[6][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[6][2])+((Cik[3][0][0]*Wirk[6][0]
      )+(Cik[3][0][1]*Wirk[6][1]))))+((cnk[6][0][2]*Wkrpk[6][2])+((cnk[6][0][0]*
      Wkrpk[6][0])+(cnk[6][0][1]*Wkrpk[6][1]))));
    vnk[6][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[6][2])+((Cik[3][1][0]*Wirk[6][0]
      )+(Cik[3][1][1]*Wirk[6][1]))))+((cnk[6][1][2]*Wkrpk[6][2])+((cnk[6][1][0]*
      Wkrpk[6][0])+(cnk[6][1][1]*Wkrpk[6][1]))));
    vnk[6][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[6][2])+((Cik[3][2][0]*Wirk[6][0]
      )+(Cik[3][2][1]*Wirk[6][1]))))+((cnk[6][2][2]*Wkrpk[6][2])+((cnk[6][2][0]*
      Wkrpk[6][0])+(cnk[6][2][1]*Wkrpk[6][1]))));
    vnk[7][0] = ((vnk[6][0]+((cnk[6][0][2]*Wirk[7][2])+((cnk[6][0][0]*Wirk[7][0]
      )+(cnk[6][0][1]*Wirk[7][1]))))+((cnk[7][0][2]*Wkrpk[7][2])+((cnk[7][0][0]*
      Wkrpk[7][0])+(cnk[7][0][1]*Wkrpk[7][1]))));
    vnk[7][1] = ((vnk[6][1]+((cnk[6][1][2]*Wirk[7][2])+((cnk[6][1][0]*Wirk[7][0]
      )+(cnk[6][1][1]*Wirk[7][1]))))+((cnk[7][1][2]*Wkrpk[7][2])+((cnk[7][1][0]*
      Wkrpk[7][0])+(cnk[7][1][1]*Wkrpk[7][1]))));
    vnk[7][2] = ((vnk[6][2]+((cnk[6][2][2]*Wirk[7][2])+((cnk[6][2][0]*Wirk[7][0]
      )+(cnk[6][2][1]*Wirk[7][1]))))+((cnk[7][2][2]*Wkrpk[7][2])+((cnk[7][2][0]*
      Wkrpk[7][0])+(cnk[7][2][1]*Wkrpk[7][1]))));
    vnk[8][0] = ((vnk[7][0]+((cnk[7][0][2]*Wirk[8][2])+((cnk[7][0][0]*Wirk[8][0]
      )+(cnk[7][0][1]*Wirk[8][1]))))+((cnk[8][0][2]*Wkrpk[8][2])+((cnk[8][0][0]*
      Wkrpk[8][0])+(cnk[8][0][1]*Wkrpk[8][1]))));
    vnk[8][1] = ((vnk[7][1]+((cnk[7][1][2]*Wirk[8][2])+((cnk[7][1][0]*Wirk[8][0]
      )+(cnk[7][1][1]*Wirk[8][1]))))+((cnk[8][1][2]*Wkrpk[8][2])+((cnk[8][1][0]*
      Wkrpk[8][0])+(cnk[8][1][1]*Wkrpk[8][1]))));
    vnk[8][2] = ((vnk[7][2]+((cnk[7][2][2]*Wirk[8][2])+((cnk[7][2][0]*Wirk[8][0]
      )+(cnk[7][2][1]*Wirk[8][1]))))+((cnk[8][2][2]*Wkrpk[8][2])+((cnk[8][2][0]*
      Wkrpk[8][0])+(cnk[8][2][1]*Wkrpk[8][1]))));
    vnk[9][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[9][2])+((Cik[3][0][0]*Wirk[9][0]
      )+(Cik[3][0][1]*Wirk[9][1]))))+((cnk[9][0][2]*Wkrpk[9][2])+((cnk[9][0][0]*
      Wkrpk[9][0])+(cnk[9][0][1]*Wkrpk[9][1]))));
    vnk[9][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[9][2])+((Cik[3][1][0]*Wirk[9][0]
      )+(Cik[3][1][1]*Wirk[9][1]))))+((cnk[9][1][2]*Wkrpk[9][2])+((cnk[9][1][0]*
      Wkrpk[9][0])+(cnk[9][1][1]*Wkrpk[9][1]))));
    vnk[9][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[9][2])+((Cik[3][2][0]*Wirk[9][0]
      )+(Cik[3][2][1]*Wirk[9][1]))))+((cnk[9][2][2]*Wkrpk[9][2])+((cnk[9][2][0]*
      Wkrpk[9][0])+(cnk[9][2][1]*Wkrpk[9][1]))));
    vnk[10][0] = ((vnk[9][0]+((cnk[9][0][2]*Wirk[10][2])+((cnk[9][0][0]*
      Wirk[10][0])+(cnk[9][0][1]*Wirk[10][1]))))+((cnk[10][0][2]*Wkrpk[10][2])+(
      (cnk[10][0][0]*Wkrpk[10][0])+(cnk[10][0][1]*Wkrpk[10][1]))));
    vnk[10][1] = ((vnk[9][1]+((cnk[9][1][2]*Wirk[10][2])+((cnk[9][1][0]*
      Wirk[10][0])+(cnk[9][1][1]*Wirk[10][1]))))+((cnk[10][1][2]*Wkrpk[10][2])+(
      (cnk[10][1][0]*Wkrpk[10][0])+(cnk[10][1][1]*Wkrpk[10][1]))));
    vnk[10][2] = ((vnk[9][2]+((cnk[9][2][2]*Wirk[10][2])+((cnk[9][2][0]*
      Wirk[10][0])+(cnk[9][2][1]*Wirk[10][1]))))+((cnk[10][2][2]*Wkrpk[10][2])+(
      (cnk[10][2][0]*Wkrpk[10][0])+(cnk[10][2][1]*Wkrpk[10][1]))));
    vnk[11][0] = ((vnk[10][0]+((cnk[10][0][2]*Wirk[11][2])+((cnk[10][0][0]*
      Wirk[11][0])+(cnk[10][0][1]*Wirk[11][1]))))+((cnk[11][0][2]*Wkrpk[11][2])+
      ((cnk[11][0][0]*Wkrpk[11][0])+(cnk[11][0][1]*Wkrpk[11][1]))));
    vnk[11][1] = ((vnk[10][1]+((cnk[10][1][2]*Wirk[11][2])+((cnk[10][1][0]*
      Wirk[11][0])+(cnk[10][1][1]*Wirk[11][1]))))+((cnk[11][1][2]*Wkrpk[11][2])+
      ((cnk[11][1][0]*Wkrpk[11][0])+(cnk[11][1][1]*Wkrpk[11][1]))));
    vnk[11][2] = ((vnk[10][2]+((cnk[10][2][2]*Wirk[11][2])+((cnk[10][2][0]*
      Wirk[11][0])+(cnk[10][2][1]*Wirk[11][1]))))+((cnk[11][2][2]*Wkrpk[11][2])+
      ((cnk[11][2][0]*Wkrpk[11][0])+(cnk[11][2][1]*Wkrpk[11][1]))));
    vnk[12][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[12][2])+((Cik[3][0][0]*
      Wirk[12][0])+(Cik[3][0][1]*Wirk[12][1]))))+((cnk[12][0][2]*Wkrpk[12][2])+(
      (cnk[12][0][0]*Wkrpk[12][0])+(cnk[12][0][1]*Wkrpk[12][1]))));
    vnk[12][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[12][2])+((Cik[3][1][0]*
      Wirk[12][0])+(Cik[3][1][1]*Wirk[12][1]))))+((cnk[12][1][2]*Wkrpk[12][2])+(
      (cnk[12][1][0]*Wkrpk[12][0])+(cnk[12][1][1]*Wkrpk[12][1]))));
    vnk[12][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[12][2])+((Cik[3][2][0]*
      Wirk[12][0])+(Cik[3][2][1]*Wirk[12][1]))))+((cnk[12][2][2]*Wkrpk[12][2])+(
      (cnk[12][2][0]*Wkrpk[12][0])+(cnk[12][2][1]*Wkrpk[12][1]))));
    vnk[13][0] = ((vnk[12][0]+((cnk[12][0][2]*Wirk[13][2])+((cnk[12][0][0]*
      Wirk[13][0])+(cnk[12][0][1]*Wirk[13][1]))))+((cnk[13][0][2]*Wkrpk[13][2])+
      ((cnk[13][0][0]*Wkrpk[13][0])+(cnk[13][0][1]*Wkrpk[13][1]))));
    vnk[13][1] = ((vnk[12][1]+((cnk[12][1][2]*Wirk[13][2])+((cnk[12][1][0]*
      Wirk[13][0])+(cnk[12][1][1]*Wirk[13][1]))))+((cnk[13][1][2]*Wkrpk[13][2])+
      ((cnk[13][1][0]*Wkrpk[13][0])+(cnk[13][1][1]*Wkrpk[13][1]))));
    vnk[13][2] = ((vnk[12][2]+((cnk[12][2][2]*Wirk[13][2])+((cnk[12][2][0]*
      Wirk[13][0])+(cnk[12][2][1]*Wirk[13][1]))))+((cnk[13][2][2]*Wkrpk[13][2])+
      ((cnk[13][2][0]*Wkrpk[13][0])+(cnk[13][2][1]*Wkrpk[13][1]))));
    vnk[14][0] = ((vnk[13][0]+((cnk[13][0][2]*Wirk[14][2])+((cnk[13][0][0]*
      Wirk[14][0])+(cnk[13][0][1]*Wirk[14][1]))))+((cnk[14][0][2]*Wkrpk[14][2])+
      ((cnk[14][0][0]*Wkrpk[14][0])+(cnk[14][0][1]*Wkrpk[14][1]))));
    vnk[14][1] = ((vnk[13][1]+((cnk[13][1][2]*Wirk[14][2])+((cnk[13][1][0]*
      Wirk[14][0])+(cnk[13][1][1]*Wirk[14][1]))))+((cnk[14][1][2]*Wkrpk[14][2])+
      ((cnk[14][1][0]*Wkrpk[14][0])+(cnk[14][1][1]*Wkrpk[14][1]))));
    vnk[14][2] = ((vnk[13][2]+((cnk[13][2][2]*Wirk[14][2])+((cnk[13][2][0]*
      Wirk[14][0])+(cnk[13][2][1]*Wirk[14][1]))))+((cnk[14][2][2]*Wkrpk[14][2])+
      ((cnk[14][2][0]*Wkrpk[14][0])+(cnk[14][2][1]*Wkrpk[14][1]))));
    vnk[15][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[15][2])+((Cik[3][0][0]*
      Wirk[15][0])+(Cik[3][0][1]*Wirk[15][1]))))+((cnk[15][0][2]*Wkrpk[15][2])+(
      (cnk[15][0][0]*Wkrpk[15][0])+(cnk[15][0][1]*Wkrpk[15][1]))));
    vnk[15][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[15][2])+((Cik[3][1][0]*
      Wirk[15][0])+(Cik[3][1][1]*Wirk[15][1]))))+((cnk[15][1][2]*Wkrpk[15][2])+(
      (cnk[15][1][0]*Wkrpk[15][0])+(cnk[15][1][1]*Wkrpk[15][1]))));
    vnk[15][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[15][2])+((Cik[3][2][0]*
      Wirk[15][0])+(Cik[3][2][1]*Wirk[15][1]))))+((cnk[15][2][2]*Wkrpk[15][2])+(
      (cnk[15][2][0]*Wkrpk[15][0])+(cnk[15][2][1]*Wkrpk[15][1]))));
    vnk[16][0] = ((vnk[15][0]+((cnk[15][0][2]*Wirk[16][2])+((cnk[15][0][0]*
      Wirk[16][0])+(cnk[15][0][1]*Wirk[16][1]))))+((cnk[16][0][2]*Wkrpk[16][2])+
      ((cnk[16][0][0]*Wkrpk[16][0])+(cnk[16][0][1]*Wkrpk[16][1]))));
    vnk[16][1] = ((vnk[15][1]+((cnk[15][1][2]*Wirk[16][2])+((cnk[15][1][0]*
      Wirk[16][0])+(cnk[15][1][1]*Wirk[16][1]))))+((cnk[16][1][2]*Wkrpk[16][2])+
      ((cnk[16][1][0]*Wkrpk[16][0])+(cnk[16][1][1]*Wkrpk[16][1]))));
    vnk[16][2] = ((vnk[15][2]+((cnk[15][2][2]*Wirk[16][2])+((cnk[15][2][0]*
      Wirk[16][0])+(cnk[15][2][1]*Wirk[16][1]))))+((cnk[16][2][2]*Wkrpk[16][2])+
      ((cnk[16][2][0]*Wkrpk[16][0])+(cnk[16][2][1]*Wkrpk[16][1]))));
    vnk[17][0] = ((vnk[16][0]+((cnk[16][0][2]*Wirk[17][2])+((cnk[16][0][0]*
      Wirk[17][0])+(cnk[16][0][1]*Wirk[17][1]))))+((cnk[17][0][2]*Wkrpk[17][2])+
      ((cnk[17][0][0]*Wkrpk[17][0])+(cnk[17][0][1]*Wkrpk[17][1]))));
    vnk[17][1] = ((vnk[16][1]+((cnk[16][1][2]*Wirk[17][2])+((cnk[16][1][0]*
      Wirk[17][0])+(cnk[16][1][1]*Wirk[17][1]))))+((cnk[17][1][2]*Wkrpk[17][2])+
      ((cnk[17][1][0]*Wkrpk[17][0])+(cnk[17][1][1]*Wkrpk[17][1]))));
    vnk[17][2] = ((vnk[16][2]+((cnk[16][2][2]*Wirk[17][2])+((cnk[16][2][0]*
      Wirk[17][0])+(cnk[16][2][1]*Wirk[17][1]))))+((cnk[17][2][2]*Wkrpk[17][2])+
      ((cnk[17][2][0]*Wkrpk[17][0])+(cnk[17][2][1]*Wkrpk[17][1]))));
    vnb[0][0] = vnk[5][0];
    vnb[0][1] = vnk[5][1];
    vnb[0][2] = vnk[5][2];
    vnb[1][0] = vnk[6][0];
    vnb[1][1] = vnk[6][1];
    vnb[1][2] = vnk[6][2];
    vnb[2][0] = vnk[7][0];
    vnb[2][1] = vnk[7][1];
    vnb[2][2] = vnk[7][2];
    vnb[3][0] = vnk[8][0];
    vnb[3][1] = vnk[8][1];
    vnb[3][2] = vnk[8][2];
    vnb[4][0] = vnk[9][0];
    vnb[4][1] = vnk[9][1];
    vnb[4][2] = vnk[9][2];
    vnb[5][0] = vnk[10][0];
    vnb[5][1] = vnk[10][1];
    vnb[5][2] = vnk[10][2];
    vnb[6][0] = vnk[11][0];
    vnb[6][1] = vnk[11][1];
    vnb[6][2] = vnk[11][2];
    vnb[7][0] = vnk[12][0];
    vnb[7][1] = vnk[12][1];
    vnb[7][2] = vnk[12][2];
    vnb[8][0] = vnk[13][0];
    vnb[8][1] = vnk[13][1];
    vnb[8][2] = vnk[13][2];
    vnb[9][0] = vnk[14][0];
    vnb[9][1] = vnk[14][1];
    vnb[9][2] = vnk[14][2];
    vnb[10][0] = vnk[15][0];
    vnb[10][1] = vnk[15][1];
    vnb[10][2] = vnk[15][2];
    vnb[11][0] = vnk[16][0];
    vnb[11][1] = vnk[16][1];
    vnb[11][2] = vnk[16][2];
    vnb[12][0] = vnk[17][0];
    vnb[12][1] = vnk[17][1];
    vnb[12][2] = vnk[17][2];
/*
Compute qdot (kinematical equations)
*/
    qdot[0] = u[0];
    qdot[1] = u[1];
    qdot[2] = u[2];
    qdot[3] = (.5*((q[18]*u[3])+((q[4]*u[5])-(q[5]*u[4]))));
    qdot[4] = (.5*((q[5]*u[3])+((q[18]*u[4])-(q[3]*u[5]))));
    qdot[5] = (.5*(((q[3]*u[4])+(q[18]*u[5]))-(q[4]*u[3])));
    qdot[18] = -(.5*((q[3]*u[3])+((q[4]*u[4])+(q[5]*u[5]))));
    if (stabvel  !=  0.) {
        ee = ((q[18]*q[18])+((q[5]*q[5])+((q[3]*q[3])+(q[4]*q[4]))));
        stab = ((stabvel*(1.-ee))/ee);
        qdot[3] = (qdot[3]+(q[3]*stab));
        qdot[4] = (qdot[4]+(q[4]*stab));
        qdot[5] = (qdot[5]+(q[5]*stab));
        qdot[18] = (qdot[18]+(q[18]*stab));
    }
    qdot[6] = u[6];
    qdot[7] = u[7];
    qdot[8] = u[8];
    qdot[9] = u[9];
    qdot[10] = u[10];
    qdot[11] = u[11];
    qdot[12] = u[12];
    qdot[13] = u[13];
    qdot[14] = u[14];
    qdot[15] = u[15];
    qdot[16] = u[16];
    qdot[17] = u[17];
    skipus: ;
/*
Initialize applied forces and torques to zero
*/
    for (i = 0; i < 13; i++) {
        for (j = 0; j < 3; j++) {
            ufk[i][j] = 0.;
            utk[i][j] = 0.;
        }
    }
    for (i = 0; i < 18; i++) {
        utau[i] = 0.;
    }
    ltauflg = 0;
    fs0flg = 0;
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1532 adds/subtracts/negates
                   2074 multiplies
                      4 divides
                   1154 assignments
*/
}

void sdqdot(double oqdot[19])
{
/*
Return position coordinate derivatives for tree joints.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(63,23);
        return;
    }
    for (i = 0; i <= 18; i++) {
        oqdot[i] = qdot[i];
    }
}

void sdu2qdot(double uin[18],
    double oqdot[19])
{
/*
Convert velocities to qdots.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(64,23);
        return;
    }
    for (i = 0; i <= 17; i++) {
        oqdot[i] = uin[i];
    }
    oqdot[3] = (.5*((q[18]*uin[3])+((q[4]*uin[5])-(q[5]*uin[4]))));
    oqdot[4] = (.5*((q[5]*uin[3])+((q[18]*uin[4])-(q[3]*uin[5]))));
    oqdot[5] = (.5*(((q[3]*uin[4])+(q[18]*uin[5]))-(q[4]*uin[3])));
    oqdot[18] = -(.5*((q[3]*uin[3])+((q[4]*uin[4])+(q[5]*uin[5]))));
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    9 adds/subtracts/negates
                     16 multiplies
                      0 divides
                     22 assignments
*/
}

void sdpsstate(double lqin[1])
{

    if (roustate != 2) {
        sdseterr(9,23);
        return;
    }
}

void sddovpk(void)
{

    if (vpkflg == 0) {
/*
Compute Wpk (partial angular velocities)
*/
        Wpk[3][3][0] = 1.;
        Wpk[3][4][0] = 1.;
        Wpk[3][5][0] = 1.;
        Wpk[3][6][0] = Cik[6][0][0];
        Wpk[3][6][1] = Cik[6][0][1];
        Wpk[3][6][2] = Cik[6][0][2];
        Wpk[3][7][0] = ((Cik[6][0][2]*Cik[7][2][0])+((Cik[6][0][0]*Cik[7][0][0])
          +(Cik[6][0][1]*Cik[7][1][0])));
        Wpk[3][7][1] = ((Cik[6][0][2]*Cik[7][2][1])+((Cik[6][0][0]*Cik[7][0][1])
          +(Cik[6][0][1]*Cik[7][1][1])));
        Wpk[3][7][2] = ((Cik[6][0][2]*Cik[7][2][2])+((Cik[6][0][0]*Cik[7][0][2])
          +(Cik[6][0][1]*Cik[7][1][2])));
        Wpk[3][8][0] = ((Cik[8][2][0]*Wpk[3][7][2])+((Cik[8][0][0]*Wpk[3][7][0])
          +(Cik[8][1][0]*Wpk[3][7][1])));
        Wpk[3][8][1] = ((Cik[8][2][1]*Wpk[3][7][2])+((Cik[8][0][1]*Wpk[3][7][0])
          +(Cik[8][1][1]*Wpk[3][7][1])));
        Wpk[3][8][2] = ((Cik[8][2][2]*Wpk[3][7][2])+((Cik[8][0][2]*Wpk[3][7][0])
          +(Cik[8][1][2]*Wpk[3][7][1])));
        Wpk[3][9][0] = Cik[9][0][0];
        Wpk[3][9][1] = Cik[9][0][1];
        Wpk[3][9][2] = Cik[9][0][2];
        Wpk[3][10][0] = ((Cik[9][0][2]*Cik[10][2][0])+((Cik[9][0][0]*
          Cik[10][0][0])+(Cik[9][0][1]*Cik[10][1][0])));
        Wpk[3][10][1] = ((Cik[9][0][2]*Cik[10][2][1])+((Cik[9][0][0]*
          Cik[10][0][1])+(Cik[9][0][1]*Cik[10][1][1])));
        Wpk[3][10][2] = ((Cik[9][0][2]*Cik[10][2][2])+((Cik[9][0][0]*
          Cik[10][0][2])+(Cik[9][0][1]*Cik[10][1][2])));
        Wpk[3][11][0] = ((Cik[11][2][0]*Wpk[3][10][2])+((Cik[11][0][0]*
          Wpk[3][10][0])+(Cik[11][1][0]*Wpk[3][10][1])));
        Wpk[3][11][1] = ((Cik[11][2][1]*Wpk[3][10][2])+((Cik[11][0][1]*
          Wpk[3][10][0])+(Cik[11][1][1]*Wpk[3][10][1])));
        Wpk[3][11][2] = ((Cik[11][2][2]*Wpk[3][10][2])+((Cik[11][0][2]*
          Wpk[3][10][0])+(Cik[11][1][2]*Wpk[3][10][1])));
        Wpk[3][12][0] = Cik[12][0][0];
        Wpk[3][12][1] = Cik[12][0][1];
        Wpk[3][12][2] = Cik[12][0][2];
        Wpk[3][13][0] = ((Cik[12][0][2]*Cik[13][2][0])+((Cik[12][0][0]*
          Cik[13][0][0])+(Cik[12][0][1]*Cik[13][1][0])));
        Wpk[3][13][1] = ((Cik[12][0][2]*Cik[13][2][1])+((Cik[12][0][0]*
          Cik[13][0][1])+(Cik[12][0][1]*Cik[13][1][1])));
        Wpk[3][13][2] = ((Cik[12][0][2]*Cik[13][2][2])+((Cik[12][0][0]*
          Cik[13][0][2])+(Cik[12][0][1]*Cik[13][1][2])));
        Wpk[3][14][0] = ((Cik[14][2][0]*Wpk[3][13][2])+((Cik[14][0][0]*
          Wpk[3][13][0])+(Cik[14][1][0]*Wpk[3][13][1])));
        Wpk[3][14][1] = ((Cik[14][2][1]*Wpk[3][13][2])+((Cik[14][0][1]*
          Wpk[3][13][0])+(Cik[14][1][1]*Wpk[3][13][1])));
        Wpk[3][14][2] = ((Cik[14][2][2]*Wpk[3][13][2])+((Cik[14][0][2]*
          Wpk[3][13][0])+(Cik[14][1][2]*Wpk[3][13][1])));
        Wpk[3][15][0] = Cik[15][0][0];
        Wpk[3][15][1] = Cik[15][0][1];
        Wpk[3][15][2] = Cik[15][0][2];
        Wpk[3][16][0] = ((Cik[15][0][2]*Cik[16][2][0])+((Cik[15][0][0]*
          Cik[16][0][0])+(Cik[15][0][1]*Cik[16][1][0])));
        Wpk[3][16][1] = ((Cik[15][0][2]*Cik[16][2][1])+((Cik[15][0][0]*
          Cik[16][0][1])+(Cik[15][0][1]*Cik[16][1][1])));
        Wpk[3][16][2] = ((Cik[15][0][2]*Cik[16][2][2])+((Cik[15][0][0]*
          Cik[16][0][2])+(Cik[15][0][1]*Cik[16][1][2])));
        Wpk[3][17][0] = ((Cik[17][2][0]*Wpk[3][16][2])+((Cik[17][0][0]*
          Wpk[3][16][0])+(Cik[17][1][0]*Wpk[3][16][1])));
        Wpk[3][17][1] = ((Cik[17][2][1]*Wpk[3][16][2])+((Cik[17][0][1]*
          Wpk[3][16][0])+(Cik[17][1][1]*Wpk[3][16][1])));
        Wpk[3][17][2] = ((Cik[17][2][2]*Wpk[3][16][2])+((Cik[17][0][2]*
          Wpk[3][16][0])+(Cik[17][1][2]*Wpk[3][16][1])));
        Wpk[4][4][1] = 1.;
        Wpk[4][5][1] = 1.;
        Wpk[4][6][0] = Cik[6][1][0];
        Wpk[4][6][1] = Cik[6][1][1];
        Wpk[4][6][2] = Cik[6][1][2];
        Wpk[4][7][0] = ((Cik[6][1][2]*Cik[7][2][0])+((Cik[6][1][0]*Cik[7][0][0])
          +(Cik[6][1][1]*Cik[7][1][0])));
        Wpk[4][7][1] = ((Cik[6][1][2]*Cik[7][2][1])+((Cik[6][1][0]*Cik[7][0][1])
          +(Cik[6][1][1]*Cik[7][1][1])));
        Wpk[4][7][2] = ((Cik[6][1][2]*Cik[7][2][2])+((Cik[6][1][0]*Cik[7][0][2])
          +(Cik[6][1][1]*Cik[7][1][2])));
        Wpk[4][8][0] = ((Cik[8][2][0]*Wpk[4][7][2])+((Cik[8][0][0]*Wpk[4][7][0])
          +(Cik[8][1][0]*Wpk[4][7][1])));
        Wpk[4][8][1] = ((Cik[8][2][1]*Wpk[4][7][2])+((Cik[8][0][1]*Wpk[4][7][0])
          +(Cik[8][1][1]*Wpk[4][7][1])));
        Wpk[4][8][2] = ((Cik[8][2][2]*Wpk[4][7][2])+((Cik[8][0][2]*Wpk[4][7][0])
          +(Cik[8][1][2]*Wpk[4][7][1])));
        Wpk[4][9][0] = Cik[9][1][0];
        Wpk[4][9][1] = Cik[9][1][1];
        Wpk[4][9][2] = Cik[9][1][2];
        Wpk[4][10][0] = ((Cik[9][1][2]*Cik[10][2][0])+((Cik[9][1][0]*
          Cik[10][0][0])+(Cik[9][1][1]*Cik[10][1][0])));
        Wpk[4][10][1] = ((Cik[9][1][2]*Cik[10][2][1])+((Cik[9][1][0]*
          Cik[10][0][1])+(Cik[9][1][1]*Cik[10][1][1])));
        Wpk[4][10][2] = ((Cik[9][1][2]*Cik[10][2][2])+((Cik[9][1][0]*
          Cik[10][0][2])+(Cik[9][1][1]*Cik[10][1][2])));
        Wpk[4][11][0] = ((Cik[11][2][0]*Wpk[4][10][2])+((Cik[11][0][0]*
          Wpk[4][10][0])+(Cik[11][1][0]*Wpk[4][10][1])));
        Wpk[4][11][1] = ((Cik[11][2][1]*Wpk[4][10][2])+((Cik[11][0][1]*
          Wpk[4][10][0])+(Cik[11][1][1]*Wpk[4][10][1])));
        Wpk[4][11][2] = ((Cik[11][2][2]*Wpk[4][10][2])+((Cik[11][0][2]*
          Wpk[4][10][0])+(Cik[11][1][2]*Wpk[4][10][1])));
        Wpk[4][12][0] = Cik[12][1][0];
        Wpk[4][12][1] = Cik[12][1][1];
        Wpk[4][12][2] = Cik[12][1][2];
        Wpk[4][13][0] = ((Cik[12][1][2]*Cik[13][2][0])+((Cik[12][1][0]*
          Cik[13][0][0])+(Cik[12][1][1]*Cik[13][1][0])));
        Wpk[4][13][1] = ((Cik[12][1][2]*Cik[13][2][1])+((Cik[12][1][0]*
          Cik[13][0][1])+(Cik[12][1][1]*Cik[13][1][1])));
        Wpk[4][13][2] = ((Cik[12][1][2]*Cik[13][2][2])+((Cik[12][1][0]*
          Cik[13][0][2])+(Cik[12][1][1]*Cik[13][1][2])));
        Wpk[4][14][0] = ((Cik[14][2][0]*Wpk[4][13][2])+((Cik[14][0][0]*
          Wpk[4][13][0])+(Cik[14][1][0]*Wpk[4][13][1])));
        Wpk[4][14][1] = ((Cik[14][2][1]*Wpk[4][13][2])+((Cik[14][0][1]*
          Wpk[4][13][0])+(Cik[14][1][1]*Wpk[4][13][1])));
        Wpk[4][14][2] = ((Cik[14][2][2]*Wpk[4][13][2])+((Cik[14][0][2]*
          Wpk[4][13][0])+(Cik[14][1][2]*Wpk[4][13][1])));
        Wpk[4][15][0] = Cik[15][1][0];
        Wpk[4][15][1] = Cik[15][1][1];
        Wpk[4][15][2] = Cik[15][1][2];
        Wpk[4][16][0] = ((Cik[15][1][2]*Cik[16][2][0])+((Cik[15][1][0]*
          Cik[16][0][0])+(Cik[15][1][1]*Cik[16][1][0])));
        Wpk[4][16][1] = ((Cik[15][1][2]*Cik[16][2][1])+((Cik[15][1][0]*
          Cik[16][0][1])+(Cik[15][1][1]*Cik[16][1][1])));
        Wpk[4][16][2] = ((Cik[15][1][2]*Cik[16][2][2])+((Cik[15][1][0]*
          Cik[16][0][2])+(Cik[15][1][1]*Cik[16][1][2])));
        Wpk[4][17][0] = ((Cik[17][2][0]*Wpk[4][16][2])+((Cik[17][0][0]*
          Wpk[4][16][0])+(Cik[17][1][0]*Wpk[4][16][1])));
        Wpk[4][17][1] = ((Cik[17][2][1]*Wpk[4][16][2])+((Cik[17][0][1]*
          Wpk[4][16][0])+(Cik[17][1][1]*Wpk[4][16][1])));
        Wpk[4][17][2] = ((Cik[17][2][2]*Wpk[4][16][2])+((Cik[17][0][2]*
          Wpk[4][16][0])+(Cik[17][1][2]*Wpk[4][16][1])));
        Wpk[5][5][2] = 1.;
        Wpk[5][6][0] = Cik[6][2][0];
        Wpk[5][6][1] = Cik[6][2][1];
        Wpk[5][6][2] = Cik[6][2][2];
        Wpk[5][7][0] = ((Cik[6][2][2]*Cik[7][2][0])+((Cik[6][2][0]*Cik[7][0][0])
          +(Cik[6][2][1]*Cik[7][1][0])));
        Wpk[5][7][1] = ((Cik[6][2][2]*Cik[7][2][1])+((Cik[6][2][0]*Cik[7][0][1])
          +(Cik[6][2][1]*Cik[7][1][1])));
        Wpk[5][7][2] = ((Cik[6][2][2]*Cik[7][2][2])+((Cik[6][2][0]*Cik[7][0][2])
          +(Cik[6][2][1]*Cik[7][1][2])));
        Wpk[5][8][0] = ((Cik[8][2][0]*Wpk[5][7][2])+((Cik[8][0][0]*Wpk[5][7][0])
          +(Cik[8][1][0]*Wpk[5][7][1])));
        Wpk[5][8][1] = ((Cik[8][2][1]*Wpk[5][7][2])+((Cik[8][0][1]*Wpk[5][7][0])
          +(Cik[8][1][1]*Wpk[5][7][1])));
        Wpk[5][8][2] = ((Cik[8][2][2]*Wpk[5][7][2])+((Cik[8][0][2]*Wpk[5][7][0])
          +(Cik[8][1][2]*Wpk[5][7][1])));
        Wpk[5][9][0] = Cik[9][2][0];
        Wpk[5][9][1] = Cik[9][2][1];
        Wpk[5][9][2] = Cik[9][2][2];
        Wpk[5][10][0] = ((Cik[9][2][2]*Cik[10][2][0])+((Cik[9][2][0]*
          Cik[10][0][0])+(Cik[9][2][1]*Cik[10][1][0])));
        Wpk[5][10][1] = ((Cik[9][2][2]*Cik[10][2][1])+((Cik[9][2][0]*
          Cik[10][0][1])+(Cik[9][2][1]*Cik[10][1][1])));
        Wpk[5][10][2] = ((Cik[9][2][2]*Cik[10][2][2])+((Cik[9][2][0]*
          Cik[10][0][2])+(Cik[9][2][1]*Cik[10][1][2])));
        Wpk[5][11][0] = ((Cik[11][2][0]*Wpk[5][10][2])+((Cik[11][0][0]*
          Wpk[5][10][0])+(Cik[11][1][0]*Wpk[5][10][1])));
        Wpk[5][11][1] = ((Cik[11][2][1]*Wpk[5][10][2])+((Cik[11][0][1]*
          Wpk[5][10][0])+(Cik[11][1][1]*Wpk[5][10][1])));
        Wpk[5][11][2] = ((Cik[11][2][2]*Wpk[5][10][2])+((Cik[11][0][2]*
          Wpk[5][10][0])+(Cik[11][1][2]*Wpk[5][10][1])));
        Wpk[5][12][0] = Cik[12][2][0];
        Wpk[5][12][1] = Cik[12][2][1];
        Wpk[5][12][2] = Cik[12][2][2];
        Wpk[5][13][0] = ((Cik[12][2][2]*Cik[13][2][0])+((Cik[12][2][0]*
          Cik[13][0][0])+(Cik[12][2][1]*Cik[13][1][0])));
        Wpk[5][13][1] = ((Cik[12][2][2]*Cik[13][2][1])+((Cik[12][2][0]*
          Cik[13][0][1])+(Cik[12][2][1]*Cik[13][1][1])));
        Wpk[5][13][2] = ((Cik[12][2][2]*Cik[13][2][2])+((Cik[12][2][0]*
          Cik[13][0][2])+(Cik[12][2][1]*Cik[13][1][2])));
        Wpk[5][14][0] = ((Cik[14][2][0]*Wpk[5][13][2])+((Cik[14][0][0]*
          Wpk[5][13][0])+(Cik[14][1][0]*Wpk[5][13][1])));
        Wpk[5][14][1] = ((Cik[14][2][1]*Wpk[5][13][2])+((Cik[14][0][1]*
          Wpk[5][13][0])+(Cik[14][1][1]*Wpk[5][13][1])));
        Wpk[5][14][2] = ((Cik[14][2][2]*Wpk[5][13][2])+((Cik[14][0][2]*
          Wpk[5][13][0])+(Cik[14][1][2]*Wpk[5][13][1])));
        Wpk[5][15][0] = Cik[15][2][0];
        Wpk[5][15][1] = Cik[15][2][1];
        Wpk[5][15][2] = Cik[15][2][2];
        Wpk[5][16][0] = ((Cik[15][2][2]*Cik[16][2][0])+((Cik[15][2][0]*
          Cik[16][0][0])+(Cik[15][2][1]*Cik[16][1][0])));
        Wpk[5][16][1] = ((Cik[15][2][2]*Cik[16][2][1])+((Cik[15][2][0]*
          Cik[16][0][1])+(Cik[15][2][1]*Cik[16][1][1])));
        Wpk[5][16][2] = ((Cik[15][2][2]*Cik[16][2][2])+((Cik[15][2][0]*
          Cik[16][0][2])+(Cik[15][2][1]*Cik[16][1][2])));
        Wpk[5][17][0] = ((Cik[17][2][0]*Wpk[5][16][2])+((Cik[17][0][0]*
          Wpk[5][16][0])+(Cik[17][1][0]*Wpk[5][16][1])));
        Wpk[5][17][1] = ((Cik[17][2][1]*Wpk[5][16][2])+((Cik[17][0][1]*
          Wpk[5][16][0])+(Cik[17][1][1]*Wpk[5][16][1])));
        Wpk[5][17][2] = ((Cik[17][2][2]*Wpk[5][16][2])+((Cik[17][0][2]*
          Wpk[5][16][0])+(Cik[17][1][2]*Wpk[5][16][1])));
        Wpk[6][6][0] = pin[6][0];
        Wpk[6][6][1] = pin[6][1];
        Wpk[6][6][2] = pin[6][2];
        Wpk[6][7][0] = ((Cik[7][2][0]*pin[6][2])+((Cik[7][0][0]*pin[6][0])+(
          Cik[7][1][0]*pin[6][1])));
        Wpk[6][7][1] = ((Cik[7][2][1]*pin[6][2])+((Cik[7][0][1]*pin[6][0])+(
          Cik[7][1][1]*pin[6][1])));
        Wpk[6][7][2] = ((Cik[7][2][2]*pin[6][2])+((Cik[7][0][2]*pin[6][0])+(
          Cik[7][1][2]*pin[6][1])));
        Wpk[6][8][0] = ((Cik[8][2][0]*Wpk[6][7][2])+((Cik[8][0][0]*Wpk[6][7][0])
          +(Cik[8][1][0]*Wpk[6][7][1])));
        Wpk[6][8][1] = ((Cik[8][2][1]*Wpk[6][7][2])+((Cik[8][0][1]*Wpk[6][7][0])
          +(Cik[8][1][1]*Wpk[6][7][1])));
        Wpk[6][8][2] = ((Cik[8][2][2]*Wpk[6][7][2])+((Cik[8][0][2]*Wpk[6][7][0])
          +(Cik[8][1][2]*Wpk[6][7][1])));
        Wpk[7][7][0] = pin[7][0];
        Wpk[7][7][1] = pin[7][1];
        Wpk[7][7][2] = pin[7][2];
        Wpk[7][8][0] = ((Cik[8][2][0]*pin[7][2])+((Cik[8][0][0]*pin[7][0])+(
          Cik[8][1][0]*pin[7][1])));
        Wpk[7][8][1] = ((Cik[8][2][1]*pin[7][2])+((Cik[8][0][1]*pin[7][0])+(
          Cik[8][1][1]*pin[7][1])));
        Wpk[7][8][2] = ((Cik[8][2][2]*pin[7][2])+((Cik[8][0][2]*pin[7][0])+(
          Cik[8][1][2]*pin[7][1])));
        Wpk[8][8][0] = pin[8][0];
        Wpk[8][8][1] = pin[8][1];
        Wpk[8][8][2] = pin[8][2];
        Wpk[9][9][0] = pin[9][0];
        Wpk[9][9][1] = pin[9][1];
        Wpk[9][9][2] = pin[9][2];
        Wpk[9][10][0] = ((Cik[10][2][0]*pin[9][2])+((Cik[10][0][0]*pin[9][0])+(
          Cik[10][1][0]*pin[9][1])));
        Wpk[9][10][1] = ((Cik[10][2][1]*pin[9][2])+((Cik[10][0][1]*pin[9][0])+(
          Cik[10][1][1]*pin[9][1])));
        Wpk[9][10][2] = ((Cik[10][2][2]*pin[9][2])+((Cik[10][0][2]*pin[9][0])+(
          Cik[10][1][2]*pin[9][1])));
        Wpk[9][11][0] = ((Cik[11][2][0]*Wpk[9][10][2])+((Cik[11][0][0]*
          Wpk[9][10][0])+(Cik[11][1][0]*Wpk[9][10][1])));
        Wpk[9][11][1] = ((Cik[11][2][1]*Wpk[9][10][2])+((Cik[11][0][1]*
          Wpk[9][10][0])+(Cik[11][1][1]*Wpk[9][10][1])));
        Wpk[9][11][2] = ((Cik[11][2][2]*Wpk[9][10][2])+((Cik[11][0][2]*
          Wpk[9][10][0])+(Cik[11][1][2]*Wpk[9][10][1])));
        Wpk[10][10][0] = pin[10][0];
        Wpk[10][10][1] = pin[10][1];
        Wpk[10][10][2] = pin[10][2];
        Wpk[10][11][0] = ((Cik[11][2][0]*pin[10][2])+((Cik[11][0][0]*pin[10][0])
          +(Cik[11][1][0]*pin[10][1])));
        Wpk[10][11][1] = ((Cik[11][2][1]*pin[10][2])+((Cik[11][0][1]*pin[10][0])
          +(Cik[11][1][1]*pin[10][1])));
        Wpk[10][11][2] = ((Cik[11][2][2]*pin[10][2])+((Cik[11][0][2]*pin[10][0])
          +(Cik[11][1][2]*pin[10][1])));
        Wpk[11][11][0] = pin[11][0];
        Wpk[11][11][1] = pin[11][1];
        Wpk[11][11][2] = pin[11][2];
        Wpk[12][12][0] = pin[12][0];
        Wpk[12][12][1] = pin[12][1];
        Wpk[12][12][2] = pin[12][2];
        Wpk[12][13][0] = ((Cik[13][2][0]*pin[12][2])+((Cik[13][0][0]*pin[12][0])
          +(Cik[13][1][0]*pin[12][1])));
        Wpk[12][13][1] = ((Cik[13][2][1]*pin[12][2])+((Cik[13][0][1]*pin[12][0])
          +(Cik[13][1][1]*pin[12][1])));
        Wpk[12][13][2] = ((Cik[13][2][2]*pin[12][2])+((Cik[13][0][2]*pin[12][0])
          +(Cik[13][1][2]*pin[12][1])));
        Wpk[12][14][0] = ((Cik[14][2][0]*Wpk[12][13][2])+((Cik[14][0][0]*
          Wpk[12][13][0])+(Cik[14][1][0]*Wpk[12][13][1])));
        Wpk[12][14][1] = ((Cik[14][2][1]*Wpk[12][13][2])+((Cik[14][0][1]*
          Wpk[12][13][0])+(Cik[14][1][1]*Wpk[12][13][1])));
        Wpk[12][14][2] = ((Cik[14][2][2]*Wpk[12][13][2])+((Cik[14][0][2]*
          Wpk[12][13][0])+(Cik[14][1][2]*Wpk[12][13][1])));
        Wpk[13][13][0] = pin[13][0];
        Wpk[13][13][1] = pin[13][1];
        Wpk[13][13][2] = pin[13][2];
        Wpk[13][14][0] = ((Cik[14][2][0]*pin[13][2])+((Cik[14][0][0]*pin[13][0])
          +(Cik[14][1][0]*pin[13][1])));
        Wpk[13][14][1] = ((Cik[14][2][1]*pin[13][2])+((Cik[14][0][1]*pin[13][0])
          +(Cik[14][1][1]*pin[13][1])));
        Wpk[13][14][2] = ((Cik[14][2][2]*pin[13][2])+((Cik[14][0][2]*pin[13][0])
          +(Cik[14][1][2]*pin[13][1])));
        Wpk[14][14][0] = pin[14][0];
        Wpk[14][14][1] = pin[14][1];
        Wpk[14][14][2] = pin[14][2];
        Wpk[15][15][0] = pin[15][0];
        Wpk[15][15][1] = pin[15][1];
        Wpk[15][15][2] = pin[15][2];
        Wpk[15][16][0] = ((Cik[16][2][0]*pin[15][2])+((Cik[16][0][0]*pin[15][0])
          +(Cik[16][1][0]*pin[15][1])));
        Wpk[15][16][1] = ((Cik[16][2][1]*pin[15][2])+((Cik[16][0][1]*pin[15][0])
          +(Cik[16][1][1]*pin[15][1])));
        Wpk[15][16][2] = ((Cik[16][2][2]*pin[15][2])+((Cik[16][0][2]*pin[15][0])
          +(Cik[16][1][2]*pin[15][1])));
        Wpk[15][17][0] = ((Cik[17][2][0]*Wpk[15][16][2])+((Cik[17][0][0]*
          Wpk[15][16][0])+(Cik[17][1][0]*Wpk[15][16][1])));
        Wpk[15][17][1] = ((Cik[17][2][1]*Wpk[15][16][2])+((Cik[17][0][1]*
          Wpk[15][16][0])+(Cik[17][1][1]*Wpk[15][16][1])));
        Wpk[15][17][2] = ((Cik[17][2][2]*Wpk[15][16][2])+((Cik[17][0][2]*
          Wpk[15][16][0])+(Cik[17][1][2]*Wpk[15][16][1])));
        Wpk[16][16][0] = pin[16][0];
        Wpk[16][16][1] = pin[16][1];
        Wpk[16][16][2] = pin[16][2];
        Wpk[16][17][0] = ((Cik[17][2][0]*pin[16][2])+((Cik[17][0][0]*pin[16][0])
          +(Cik[17][1][0]*pin[16][1])));
        Wpk[16][17][1] = ((Cik[17][2][1]*pin[16][2])+((Cik[17][0][1]*pin[16][0])
          +(Cik[17][1][1]*pin[16][1])));
        Wpk[16][17][2] = ((Cik[17][2][2]*pin[16][2])+((Cik[17][0][2]*pin[16][0])
          +(Cik[17][1][2]*pin[16][1])));
        Wpk[17][17][0] = pin[17][0];
        Wpk[17][17][1] = pin[17][1];
        Wpk[17][17][2] = pin[17][2];
/*
Compute Vpk (partial velocities)
*/
        Vpk[0][0][0] = pin[0][0];
        Vpk[0][0][1] = pin[0][1];
        Vpk[0][0][2] = pin[0][2];
        Vpk[0][1][0] = pin[0][0];
        Vpk[0][1][1] = pin[0][1];
        Vpk[0][1][2] = pin[0][2];
        Vpk[0][2][0] = pin[0][0];
        Vpk[0][2][1] = pin[0][1];
        Vpk[0][2][2] = pin[0][2];
        Vpk[0][3][0] = ((Cik[3][2][0]*pin[0][2])+((Cik[3][0][0]*pin[0][0])+(
          Cik[3][1][0]*pin[0][1])));
        Vpk[0][3][1] = ((Cik[3][2][1]*pin[0][2])+((Cik[3][0][1]*pin[0][0])+(
          Cik[3][1][1]*pin[0][1])));
        Vpk[0][3][2] = ((Cik[3][2][2]*pin[0][2])+((Cik[3][0][2]*pin[0][0])+(
          Cik[3][1][2]*pin[0][1])));
        Vpk[0][4][0] = Vpk[0][3][0];
        Vpk[0][4][1] = Vpk[0][3][1];
        Vpk[0][4][2] = Vpk[0][3][2];
        Vpk[0][5][0] = Vpk[0][3][0];
        Vpk[0][5][1] = Vpk[0][3][1];
        Vpk[0][5][2] = Vpk[0][3][2];
        Vpk[0][6][0] = ((Cik[6][2][0]*Vpk[0][3][2])+((Cik[6][0][0]*Vpk[0][3][0])
          +(Cik[6][1][0]*Vpk[0][3][1])));
        Vpk[0][6][1] = ((Cik[6][2][1]*Vpk[0][3][2])+((Cik[6][0][1]*Vpk[0][3][0])
          +(Cik[6][1][1]*Vpk[0][3][1])));
        Vpk[0][6][2] = ((Cik[6][2][2]*Vpk[0][3][2])+((Cik[6][0][2]*Vpk[0][3][0])
          +(Cik[6][1][2]*Vpk[0][3][1])));
        Vpk[0][7][0] = ((Cik[7][2][0]*Vpk[0][6][2])+((Cik[7][0][0]*Vpk[0][6][0])
          +(Cik[7][1][0]*Vpk[0][6][1])));
        Vpk[0][7][1] = ((Cik[7][2][1]*Vpk[0][6][2])+((Cik[7][0][1]*Vpk[0][6][0])
          +(Cik[7][1][1]*Vpk[0][6][1])));
        Vpk[0][7][2] = ((Cik[7][2][2]*Vpk[0][6][2])+((Cik[7][0][2]*Vpk[0][6][0])
          +(Cik[7][1][2]*Vpk[0][6][1])));
        Vpk[0][8][0] = ((Cik[8][2][0]*Vpk[0][7][2])+((Cik[8][0][0]*Vpk[0][7][0])
          +(Cik[8][1][0]*Vpk[0][7][1])));
        Vpk[0][8][1] = ((Cik[8][2][1]*Vpk[0][7][2])+((Cik[8][0][1]*Vpk[0][7][0])
          +(Cik[8][1][1]*Vpk[0][7][1])));
        Vpk[0][8][2] = ((Cik[8][2][2]*Vpk[0][7][2])+((Cik[8][0][2]*Vpk[0][7][0])
          +(Cik[8][1][2]*Vpk[0][7][1])));
        Vpk[0][9][0] = ((Cik[9][2][0]*Vpk[0][3][2])+((Cik[9][0][0]*Vpk[0][3][0])
          +(Cik[9][1][0]*Vpk[0][3][1])));
        Vpk[0][9][1] = ((Cik[9][2][1]*Vpk[0][3][2])+((Cik[9][0][1]*Vpk[0][3][0])
          +(Cik[9][1][1]*Vpk[0][3][1])));
        Vpk[0][9][2] = ((Cik[9][2][2]*Vpk[0][3][2])+((Cik[9][0][2]*Vpk[0][3][0])
          +(Cik[9][1][2]*Vpk[0][3][1])));
        Vpk[0][10][0] = ((Cik[10][2][0]*Vpk[0][9][2])+((Cik[10][0][0]*
          Vpk[0][9][0])+(Cik[10][1][0]*Vpk[0][9][1])));
        Vpk[0][10][1] = ((Cik[10][2][1]*Vpk[0][9][2])+((Cik[10][0][1]*
          Vpk[0][9][0])+(Cik[10][1][1]*Vpk[0][9][1])));
        Vpk[0][10][2] = ((Cik[10][2][2]*Vpk[0][9][2])+((Cik[10][0][2]*
          Vpk[0][9][0])+(Cik[10][1][2]*Vpk[0][9][1])));
        Vpk[0][11][0] = ((Cik[11][2][0]*Vpk[0][10][2])+((Cik[11][0][0]*
          Vpk[0][10][0])+(Cik[11][1][0]*Vpk[0][10][1])));
        Vpk[0][11][1] = ((Cik[11][2][1]*Vpk[0][10][2])+((Cik[11][0][1]*
          Vpk[0][10][0])+(Cik[11][1][1]*Vpk[0][10][1])));
        Vpk[0][11][2] = ((Cik[11][2][2]*Vpk[0][10][2])+((Cik[11][0][2]*
          Vpk[0][10][0])+(Cik[11][1][2]*Vpk[0][10][1])));
        Vpk[0][12][0] = ((Cik[12][2][0]*Vpk[0][3][2])+((Cik[12][0][0]*
          Vpk[0][3][0])+(Cik[12][1][0]*Vpk[0][3][1])));
        Vpk[0][12][1] = ((Cik[12][2][1]*Vpk[0][3][2])+((Cik[12][0][1]*
          Vpk[0][3][0])+(Cik[12][1][1]*Vpk[0][3][1])));
        Vpk[0][12][2] = ((Cik[12][2][2]*Vpk[0][3][2])+((Cik[12][0][2]*
          Vpk[0][3][0])+(Cik[12][1][2]*Vpk[0][3][1])));
        Vpk[0][13][0] = ((Cik[13][2][0]*Vpk[0][12][2])+((Cik[13][0][0]*
          Vpk[0][12][0])+(Cik[13][1][0]*Vpk[0][12][1])));
        Vpk[0][13][1] = ((Cik[13][2][1]*Vpk[0][12][2])+((Cik[13][0][1]*
          Vpk[0][12][0])+(Cik[13][1][1]*Vpk[0][12][1])));
        Vpk[0][13][2] = ((Cik[13][2][2]*Vpk[0][12][2])+((Cik[13][0][2]*
          Vpk[0][12][0])+(Cik[13][1][2]*Vpk[0][12][1])));
        Vpk[0][14][0] = ((Cik[14][2][0]*Vpk[0][13][2])+((Cik[14][0][0]*
          Vpk[0][13][0])+(Cik[14][1][0]*Vpk[0][13][1])));
        Vpk[0][14][1] = ((Cik[14][2][1]*Vpk[0][13][2])+((Cik[14][0][1]*
          Vpk[0][13][0])+(Cik[14][1][1]*Vpk[0][13][1])));
        Vpk[0][14][2] = ((Cik[14][2][2]*Vpk[0][13][2])+((Cik[14][0][2]*
          Vpk[0][13][0])+(Cik[14][1][2]*Vpk[0][13][1])));
        Vpk[0][15][0] = ((Cik[15][2][0]*Vpk[0][3][2])+((Cik[15][0][0]*
          Vpk[0][3][0])+(Cik[15][1][0]*Vpk[0][3][1])));
        Vpk[0][15][1] = ((Cik[15][2][1]*Vpk[0][3][2])+((Cik[15][0][1]*
          Vpk[0][3][0])+(Cik[15][1][1]*Vpk[0][3][1])));
        Vpk[0][15][2] = ((Cik[15][2][2]*Vpk[0][3][2])+((Cik[15][0][2]*
          Vpk[0][3][0])+(Cik[15][1][2]*Vpk[0][3][1])));
        Vpk[0][16][0] = ((Cik[16][2][0]*Vpk[0][15][2])+((Cik[16][0][0]*
          Vpk[0][15][0])+(Cik[16][1][0]*Vpk[0][15][1])));
        Vpk[0][16][1] = ((Cik[16][2][1]*Vpk[0][15][2])+((Cik[16][0][1]*
          Vpk[0][15][0])+(Cik[16][1][1]*Vpk[0][15][1])));
        Vpk[0][16][2] = ((Cik[16][2][2]*Vpk[0][15][2])+((Cik[16][0][2]*
          Vpk[0][15][0])+(Cik[16][1][2]*Vpk[0][15][1])));
        Vpk[0][17][0] = ((Cik[17][2][0]*Vpk[0][16][2])+((Cik[17][0][0]*
          Vpk[0][16][0])+(Cik[17][1][0]*Vpk[0][16][1])));
        Vpk[0][17][1] = ((Cik[17][2][1]*Vpk[0][16][2])+((Cik[17][0][1]*
          Vpk[0][16][0])+(Cik[17][1][1]*Vpk[0][16][1])));
        Vpk[0][17][2] = ((Cik[17][2][2]*Vpk[0][16][2])+((Cik[17][0][2]*
          Vpk[0][16][0])+(Cik[17][1][2]*Vpk[0][16][1])));
        Vpk[1][1][0] = pin[1][0];
        Vpk[1][1][1] = pin[1][1];
        Vpk[1][1][2] = pin[1][2];
        Vpk[1][2][0] = pin[1][0];
        Vpk[1][2][1] = pin[1][1];
        Vpk[1][2][2] = pin[1][2];
        Vpk[1][3][0] = ((Cik[3][2][0]*pin[1][2])+((Cik[3][0][0]*pin[1][0])+(
          Cik[3][1][0]*pin[1][1])));
        Vpk[1][3][1] = ((Cik[3][2][1]*pin[1][2])+((Cik[3][0][1]*pin[1][0])+(
          Cik[3][1][1]*pin[1][1])));
        Vpk[1][3][2] = ((Cik[3][2][2]*pin[1][2])+((Cik[3][0][2]*pin[1][0])+(
          Cik[3][1][2]*pin[1][1])));
        Vpk[1][4][0] = Vpk[1][3][0];
        Vpk[1][4][1] = Vpk[1][3][1];
        Vpk[1][4][2] = Vpk[1][3][2];
        Vpk[1][5][0] = Vpk[1][3][0];
        Vpk[1][5][1] = Vpk[1][3][1];
        Vpk[1][5][2] = Vpk[1][3][2];
        Vpk[1][6][0] = ((Cik[6][2][0]*Vpk[1][3][2])+((Cik[6][0][0]*Vpk[1][3][0])
          +(Cik[6][1][0]*Vpk[1][3][1])));
        Vpk[1][6][1] = ((Cik[6][2][1]*Vpk[1][3][2])+((Cik[6][0][1]*Vpk[1][3][0])
          +(Cik[6][1][1]*Vpk[1][3][1])));
        Vpk[1][6][2] = ((Cik[6][2][2]*Vpk[1][3][2])+((Cik[6][0][2]*Vpk[1][3][0])
          +(Cik[6][1][2]*Vpk[1][3][1])));
        Vpk[1][7][0] = ((Cik[7][2][0]*Vpk[1][6][2])+((Cik[7][0][0]*Vpk[1][6][0])
          +(Cik[7][1][0]*Vpk[1][6][1])));
        Vpk[1][7][1] = ((Cik[7][2][1]*Vpk[1][6][2])+((Cik[7][0][1]*Vpk[1][6][0])
          +(Cik[7][1][1]*Vpk[1][6][1])));
        Vpk[1][7][2] = ((Cik[7][2][2]*Vpk[1][6][2])+((Cik[7][0][2]*Vpk[1][6][0])
          +(Cik[7][1][2]*Vpk[1][6][1])));
        Vpk[1][8][0] = ((Cik[8][2][0]*Vpk[1][7][2])+((Cik[8][0][0]*Vpk[1][7][0])
          +(Cik[8][1][0]*Vpk[1][7][1])));
        Vpk[1][8][1] = ((Cik[8][2][1]*Vpk[1][7][2])+((Cik[8][0][1]*Vpk[1][7][0])
          +(Cik[8][1][1]*Vpk[1][7][1])));
        Vpk[1][8][2] = ((Cik[8][2][2]*Vpk[1][7][2])+((Cik[8][0][2]*Vpk[1][7][0])
          +(Cik[8][1][2]*Vpk[1][7][1])));
        Vpk[1][9][0] = ((Cik[9][2][0]*Vpk[1][3][2])+((Cik[9][0][0]*Vpk[1][3][0])
          +(Cik[9][1][0]*Vpk[1][3][1])));
        Vpk[1][9][1] = ((Cik[9][2][1]*Vpk[1][3][2])+((Cik[9][0][1]*Vpk[1][3][0])
          +(Cik[9][1][1]*Vpk[1][3][1])));
        Vpk[1][9][2] = ((Cik[9][2][2]*Vpk[1][3][2])+((Cik[9][0][2]*Vpk[1][3][0])
          +(Cik[9][1][2]*Vpk[1][3][1])));
        Vpk[1][10][0] = ((Cik[10][2][0]*Vpk[1][9][2])+((Cik[10][0][0]*
          Vpk[1][9][0])+(Cik[10][1][0]*Vpk[1][9][1])));
        Vpk[1][10][1] = ((Cik[10][2][1]*Vpk[1][9][2])+((Cik[10][0][1]*
          Vpk[1][9][0])+(Cik[10][1][1]*Vpk[1][9][1])));
        Vpk[1][10][2] = ((Cik[10][2][2]*Vpk[1][9][2])+((Cik[10][0][2]*
          Vpk[1][9][0])+(Cik[10][1][2]*Vpk[1][9][1])));
        Vpk[1][11][0] = ((Cik[11][2][0]*Vpk[1][10][2])+((Cik[11][0][0]*
          Vpk[1][10][0])+(Cik[11][1][0]*Vpk[1][10][1])));
        Vpk[1][11][1] = ((Cik[11][2][1]*Vpk[1][10][2])+((Cik[11][0][1]*
          Vpk[1][10][0])+(Cik[11][1][1]*Vpk[1][10][1])));
        Vpk[1][11][2] = ((Cik[11][2][2]*Vpk[1][10][2])+((Cik[11][0][2]*
          Vpk[1][10][0])+(Cik[11][1][2]*Vpk[1][10][1])));
        Vpk[1][12][0] = ((Cik[12][2][0]*Vpk[1][3][2])+((Cik[12][0][0]*
          Vpk[1][3][0])+(Cik[12][1][0]*Vpk[1][3][1])));
        Vpk[1][12][1] = ((Cik[12][2][1]*Vpk[1][3][2])+((Cik[12][0][1]*
          Vpk[1][3][0])+(Cik[12][1][1]*Vpk[1][3][1])));
        Vpk[1][12][2] = ((Cik[12][2][2]*Vpk[1][3][2])+((Cik[12][0][2]*
          Vpk[1][3][0])+(Cik[12][1][2]*Vpk[1][3][1])));
        Vpk[1][13][0] = ((Cik[13][2][0]*Vpk[1][12][2])+((Cik[13][0][0]*
          Vpk[1][12][0])+(Cik[13][1][0]*Vpk[1][12][1])));
        Vpk[1][13][1] = ((Cik[13][2][1]*Vpk[1][12][2])+((Cik[13][0][1]*
          Vpk[1][12][0])+(Cik[13][1][1]*Vpk[1][12][1])));
        Vpk[1][13][2] = ((Cik[13][2][2]*Vpk[1][12][2])+((Cik[13][0][2]*
          Vpk[1][12][0])+(Cik[13][1][2]*Vpk[1][12][1])));
        Vpk[1][14][0] = ((Cik[14][2][0]*Vpk[1][13][2])+((Cik[14][0][0]*
          Vpk[1][13][0])+(Cik[14][1][0]*Vpk[1][13][1])));
        Vpk[1][14][1] = ((Cik[14][2][1]*Vpk[1][13][2])+((Cik[14][0][1]*
          Vpk[1][13][0])+(Cik[14][1][1]*Vpk[1][13][1])));
        Vpk[1][14][2] = ((Cik[14][2][2]*Vpk[1][13][2])+((Cik[14][0][2]*
          Vpk[1][13][0])+(Cik[14][1][2]*Vpk[1][13][1])));
        Vpk[1][15][0] = ((Cik[15][2][0]*Vpk[1][3][2])+((Cik[15][0][0]*
          Vpk[1][3][0])+(Cik[15][1][0]*Vpk[1][3][1])));
        Vpk[1][15][1] = ((Cik[15][2][1]*Vpk[1][3][2])+((Cik[15][0][1]*
          Vpk[1][3][0])+(Cik[15][1][1]*Vpk[1][3][1])));
        Vpk[1][15][2] = ((Cik[15][2][2]*Vpk[1][3][2])+((Cik[15][0][2]*
          Vpk[1][3][0])+(Cik[15][1][2]*Vpk[1][3][1])));
        Vpk[1][16][0] = ((Cik[16][2][0]*Vpk[1][15][2])+((Cik[16][0][0]*
          Vpk[1][15][0])+(Cik[16][1][0]*Vpk[1][15][1])));
        Vpk[1][16][1] = ((Cik[16][2][1]*Vpk[1][15][2])+((Cik[16][0][1]*
          Vpk[1][15][0])+(Cik[16][1][1]*Vpk[1][15][1])));
        Vpk[1][16][2] = ((Cik[16][2][2]*Vpk[1][15][2])+((Cik[16][0][2]*
          Vpk[1][15][0])+(Cik[16][1][2]*Vpk[1][15][1])));
        Vpk[1][17][0] = ((Cik[17][2][0]*Vpk[1][16][2])+((Cik[17][0][0]*
          Vpk[1][16][0])+(Cik[17][1][0]*Vpk[1][16][1])));
        Vpk[1][17][1] = ((Cik[17][2][1]*Vpk[1][16][2])+((Cik[17][0][1]*
          Vpk[1][16][0])+(Cik[17][1][1]*Vpk[1][16][1])));
        Vpk[1][17][2] = ((Cik[17][2][2]*Vpk[1][16][2])+((Cik[17][0][2]*
          Vpk[1][16][0])+(Cik[17][1][2]*Vpk[1][16][1])));
        Vpk[2][2][0] = pin[2][0];
        Vpk[2][2][1] = pin[2][1];
        Vpk[2][2][2] = pin[2][2];
        Vpk[2][3][0] = ((Cik[3][2][0]*pin[2][2])+((Cik[3][0][0]*pin[2][0])+(
          Cik[3][1][0]*pin[2][1])));
        Vpk[2][3][1] = ((Cik[3][2][1]*pin[2][2])+((Cik[3][0][1]*pin[2][0])+(
          Cik[3][1][1]*pin[2][1])));
        Vpk[2][3][2] = ((Cik[3][2][2]*pin[2][2])+((Cik[3][0][2]*pin[2][0])+(
          Cik[3][1][2]*pin[2][1])));
        Vpk[2][4][0] = Vpk[2][3][0];
        Vpk[2][4][1] = Vpk[2][3][1];
        Vpk[2][4][2] = Vpk[2][3][2];
        Vpk[2][5][0] = Vpk[2][3][0];
        Vpk[2][5][1] = Vpk[2][3][1];
        Vpk[2][5][2] = Vpk[2][3][2];
        Vpk[2][6][0] = ((Cik[6][2][0]*Vpk[2][3][2])+((Cik[6][0][0]*Vpk[2][3][0])
          +(Cik[6][1][0]*Vpk[2][3][1])));
        Vpk[2][6][1] = ((Cik[6][2][1]*Vpk[2][3][2])+((Cik[6][0][1]*Vpk[2][3][0])
          +(Cik[6][1][1]*Vpk[2][3][1])));
        Vpk[2][6][2] = ((Cik[6][2][2]*Vpk[2][3][2])+((Cik[6][0][2]*Vpk[2][3][0])
          +(Cik[6][1][2]*Vpk[2][3][1])));
        Vpk[2][7][0] = ((Cik[7][2][0]*Vpk[2][6][2])+((Cik[7][0][0]*Vpk[2][6][0])
          +(Cik[7][1][0]*Vpk[2][6][1])));
        Vpk[2][7][1] = ((Cik[7][2][1]*Vpk[2][6][2])+((Cik[7][0][1]*Vpk[2][6][0])
          +(Cik[7][1][1]*Vpk[2][6][1])));
        Vpk[2][7][2] = ((Cik[7][2][2]*Vpk[2][6][2])+((Cik[7][0][2]*Vpk[2][6][0])
          +(Cik[7][1][2]*Vpk[2][6][1])));
        Vpk[2][8][0] = ((Cik[8][2][0]*Vpk[2][7][2])+((Cik[8][0][0]*Vpk[2][7][0])
          +(Cik[8][1][0]*Vpk[2][7][1])));
        Vpk[2][8][1] = ((Cik[8][2][1]*Vpk[2][7][2])+((Cik[8][0][1]*Vpk[2][7][0])
          +(Cik[8][1][1]*Vpk[2][7][1])));
        Vpk[2][8][2] = ((Cik[8][2][2]*Vpk[2][7][2])+((Cik[8][0][2]*Vpk[2][7][0])
          +(Cik[8][1][2]*Vpk[2][7][1])));
        Vpk[2][9][0] = ((Cik[9][2][0]*Vpk[2][3][2])+((Cik[9][0][0]*Vpk[2][3][0])
          +(Cik[9][1][0]*Vpk[2][3][1])));
        Vpk[2][9][1] = ((Cik[9][2][1]*Vpk[2][3][2])+((Cik[9][0][1]*Vpk[2][3][0])
          +(Cik[9][1][1]*Vpk[2][3][1])));
        Vpk[2][9][2] = ((Cik[9][2][2]*Vpk[2][3][2])+((Cik[9][0][2]*Vpk[2][3][0])
          +(Cik[9][1][2]*Vpk[2][3][1])));
        Vpk[2][10][0] = ((Cik[10][2][0]*Vpk[2][9][2])+((Cik[10][0][0]*
          Vpk[2][9][0])+(Cik[10][1][0]*Vpk[2][9][1])));
        Vpk[2][10][1] = ((Cik[10][2][1]*Vpk[2][9][2])+((Cik[10][0][1]*
          Vpk[2][9][0])+(Cik[10][1][1]*Vpk[2][9][1])));
        Vpk[2][10][2] = ((Cik[10][2][2]*Vpk[2][9][2])+((Cik[10][0][2]*
          Vpk[2][9][0])+(Cik[10][1][2]*Vpk[2][9][1])));
        Vpk[2][11][0] = ((Cik[11][2][0]*Vpk[2][10][2])+((Cik[11][0][0]*
          Vpk[2][10][0])+(Cik[11][1][0]*Vpk[2][10][1])));
        Vpk[2][11][1] = ((Cik[11][2][1]*Vpk[2][10][2])+((Cik[11][0][1]*
          Vpk[2][10][0])+(Cik[11][1][1]*Vpk[2][10][1])));
        Vpk[2][11][2] = ((Cik[11][2][2]*Vpk[2][10][2])+((Cik[11][0][2]*
          Vpk[2][10][0])+(Cik[11][1][2]*Vpk[2][10][1])));
        Vpk[2][12][0] = ((Cik[12][2][0]*Vpk[2][3][2])+((Cik[12][0][0]*
          Vpk[2][3][0])+(Cik[12][1][0]*Vpk[2][3][1])));
        Vpk[2][12][1] = ((Cik[12][2][1]*Vpk[2][3][2])+((Cik[12][0][1]*
          Vpk[2][3][0])+(Cik[12][1][1]*Vpk[2][3][1])));
        Vpk[2][12][2] = ((Cik[12][2][2]*Vpk[2][3][2])+((Cik[12][0][2]*
          Vpk[2][3][0])+(Cik[12][1][2]*Vpk[2][3][1])));
        Vpk[2][13][0] = ((Cik[13][2][0]*Vpk[2][12][2])+((Cik[13][0][0]*
          Vpk[2][12][0])+(Cik[13][1][0]*Vpk[2][12][1])));
        Vpk[2][13][1] = ((Cik[13][2][1]*Vpk[2][12][2])+((Cik[13][0][1]*
          Vpk[2][12][0])+(Cik[13][1][1]*Vpk[2][12][1])));
        Vpk[2][13][2] = ((Cik[13][2][2]*Vpk[2][12][2])+((Cik[13][0][2]*
          Vpk[2][12][0])+(Cik[13][1][2]*Vpk[2][12][1])));
        Vpk[2][14][0] = ((Cik[14][2][0]*Vpk[2][13][2])+((Cik[14][0][0]*
          Vpk[2][13][0])+(Cik[14][1][0]*Vpk[2][13][1])));
        Vpk[2][14][1] = ((Cik[14][2][1]*Vpk[2][13][2])+((Cik[14][0][1]*
          Vpk[2][13][0])+(Cik[14][1][1]*Vpk[2][13][1])));
        Vpk[2][14][2] = ((Cik[14][2][2]*Vpk[2][13][2])+((Cik[14][0][2]*
          Vpk[2][13][0])+(Cik[14][1][2]*Vpk[2][13][1])));
        Vpk[2][15][0] = ((Cik[15][2][0]*Vpk[2][3][2])+((Cik[15][0][0]*
          Vpk[2][3][0])+(Cik[15][1][0]*Vpk[2][3][1])));
        Vpk[2][15][1] = ((Cik[15][2][1]*Vpk[2][3][2])+((Cik[15][0][1]*
          Vpk[2][3][0])+(Cik[15][1][1]*Vpk[2][3][1])));
        Vpk[2][15][2] = ((Cik[15][2][2]*Vpk[2][3][2])+((Cik[15][0][2]*
          Vpk[2][3][0])+(Cik[15][1][2]*Vpk[2][3][1])));
        Vpk[2][16][0] = ((Cik[16][2][0]*Vpk[2][15][2])+((Cik[16][0][0]*
          Vpk[2][15][0])+(Cik[16][1][0]*Vpk[2][15][1])));
        Vpk[2][16][1] = ((Cik[16][2][1]*Vpk[2][15][2])+((Cik[16][0][1]*
          Vpk[2][15][0])+(Cik[16][1][1]*Vpk[2][15][1])));
        Vpk[2][16][2] = ((Cik[16][2][2]*Vpk[2][15][2])+((Cik[16][0][2]*
          Vpk[2][15][0])+(Cik[16][1][2]*Vpk[2][15][1])));
        Vpk[2][17][0] = ((Cik[17][2][0]*Vpk[2][16][2])+((Cik[17][0][0]*
          Vpk[2][16][0])+(Cik[17][1][0]*Vpk[2][16][1])));
        Vpk[2][17][1] = ((Cik[17][2][1]*Vpk[2][16][2])+((Cik[17][0][1]*
          Vpk[2][16][0])+(Cik[17][1][1]*Vpk[2][16][1])));
        Vpk[2][17][2] = ((Cik[17][2][2]*Vpk[2][16][2])+((Cik[17][0][2]*
          Vpk[2][16][0])+(Cik[17][1][2]*Vpk[2][16][1])));
        Vpk[3][5][1] = rk[0][2];
        Vpk[3][5][2] = -rk[0][1];
        VWri[3][6][1] = (rk[0][2]-ri[1][2]);
        VWri[3][6][2] = (ri[1][1]-rk[0][1]);
        Vpk[3][6][0] = (((Cik[6][0][2]*rk[1][1])-(Cik[6][0][1]*rk[1][2]))+((
          Cik[6][1][0]*VWri[3][6][1])+(Cik[6][2][0]*VWri[3][6][2])));
        Vpk[3][6][1] = (((Cik[6][0][0]*rk[1][2])-(Cik[6][0][2]*rk[1][0]))+((
          Cik[6][1][1]*VWri[3][6][1])+(Cik[6][2][1]*VWri[3][6][2])));
        Vpk[3][6][2] = (((Cik[6][0][1]*rk[1][0])-(Cik[6][0][0]*rk[1][1]))+((
          Cik[6][1][2]*VWri[3][6][1])+(Cik[6][2][2]*VWri[3][6][2])));
        VWri[3][7][0] = (Vpk[3][6][0]+((Cik[6][0][1]*ri[2][2])-(Cik[6][0][2]*
          ri[2][1])));
        VWri[3][7][1] = (Vpk[3][6][1]+((Cik[6][0][2]*ri[2][0])-(Cik[6][0][0]*
          ri[2][2])));
        VWri[3][7][2] = (Vpk[3][6][2]+((Cik[6][0][0]*ri[2][1])-(Cik[6][0][1]*
          ri[2][0])));
        Vpk[3][7][0] = (((Cik[7][2][0]*VWri[3][7][2])+((Cik[7][0][0]*
          VWri[3][7][0])+(Cik[7][1][0]*VWri[3][7][1])))+((rk[2][1]*Wpk[3][7][2])
          -(rk[2][2]*Wpk[3][7][1])));
        Vpk[3][7][1] = (((Cik[7][2][1]*VWri[3][7][2])+((Cik[7][0][1]*
          VWri[3][7][0])+(Cik[7][1][1]*VWri[3][7][1])))+((rk[2][2]*Wpk[3][7][0])
          -(rk[2][0]*Wpk[3][7][2])));
        Vpk[3][7][2] = (((Cik[7][2][2]*VWri[3][7][2])+((Cik[7][0][2]*
          VWri[3][7][0])+(Cik[7][1][2]*VWri[3][7][1])))+((rk[2][0]*Wpk[3][7][1])
          -(rk[2][1]*Wpk[3][7][0])));
        VWri[3][8][0] = (Vpk[3][7][0]+((ri[3][2]*Wpk[3][7][1])-(ri[3][1]*
          Wpk[3][7][2])));
        VWri[3][8][1] = (Vpk[3][7][1]+((ri[3][0]*Wpk[3][7][2])-(ri[3][2]*
          Wpk[3][7][0])));
        VWri[3][8][2] = (Vpk[3][7][2]+((ri[3][1]*Wpk[3][7][0])-(ri[3][0]*
          Wpk[3][7][1])));
        Vpk[3][8][0] = (((Cik[8][2][0]*VWri[3][8][2])+((Cik[8][0][0]*
          VWri[3][8][0])+(Cik[8][1][0]*VWri[3][8][1])))+((rk[3][1]*Wpk[3][8][2])
          -(rk[3][2]*Wpk[3][8][1])));
        Vpk[3][8][1] = (((Cik[8][2][1]*VWri[3][8][2])+((Cik[8][0][1]*
          VWri[3][8][0])+(Cik[8][1][1]*VWri[3][8][1])))+((rk[3][2]*Wpk[3][8][0])
          -(rk[3][0]*Wpk[3][8][2])));
        Vpk[3][8][2] = (((Cik[8][2][2]*VWri[3][8][2])+((Cik[8][0][2]*
          VWri[3][8][0])+(Cik[8][1][2]*VWri[3][8][1])))+((rk[3][0]*Wpk[3][8][1])
          -(rk[3][1]*Wpk[3][8][0])));
        VWri[3][9][1] = (rk[0][2]-ri[4][2]);
        VWri[3][9][2] = (ri[4][1]-rk[0][1]);
        Vpk[3][9][0] = (((Cik[9][0][2]*rk[4][1])-(Cik[9][0][1]*rk[4][2]))+((
          Cik[9][1][0]*VWri[3][9][1])+(Cik[9][2][0]*VWri[3][9][2])));
        Vpk[3][9][1] = (((Cik[9][0][0]*rk[4][2])-(Cik[9][0][2]*rk[4][0]))+((
          Cik[9][1][1]*VWri[3][9][1])+(Cik[9][2][1]*VWri[3][9][2])));
        Vpk[3][9][2] = (((Cik[9][0][1]*rk[4][0])-(Cik[9][0][0]*rk[4][1]))+((
          Cik[9][1][2]*VWri[3][9][1])+(Cik[9][2][2]*VWri[3][9][2])));
        VWri[3][10][0] = (Vpk[3][9][0]+((Cik[9][0][1]*ri[5][2])-(Cik[9][0][2]*
          ri[5][1])));
        VWri[3][10][1] = (Vpk[3][9][1]+((Cik[9][0][2]*ri[5][0])-(Cik[9][0][0]*
          ri[5][2])));
        VWri[3][10][2] = (Vpk[3][9][2]+((Cik[9][0][0]*ri[5][1])-(Cik[9][0][1]*
          ri[5][0])));
        Vpk[3][10][0] = (((Cik[10][2][0]*VWri[3][10][2])+((Cik[10][0][0]*
          VWri[3][10][0])+(Cik[10][1][0]*VWri[3][10][1])))+((rk[5][1]*
          Wpk[3][10][2])-(rk[5][2]*Wpk[3][10][1])));
        Vpk[3][10][1] = (((Cik[10][2][1]*VWri[3][10][2])+((Cik[10][0][1]*
          VWri[3][10][0])+(Cik[10][1][1]*VWri[3][10][1])))+((rk[5][2]*
          Wpk[3][10][0])-(rk[5][0]*Wpk[3][10][2])));
        Vpk[3][10][2] = (((Cik[10][2][2]*VWri[3][10][2])+((Cik[10][0][2]*
          VWri[3][10][0])+(Cik[10][1][2]*VWri[3][10][1])))+((rk[5][0]*
          Wpk[3][10][1])-(rk[5][1]*Wpk[3][10][0])));
        VWri[3][11][0] = (Vpk[3][10][0]+((ri[6][2]*Wpk[3][10][1])-(ri[6][1]*
          Wpk[3][10][2])));
        VWri[3][11][1] = (Vpk[3][10][1]+((ri[6][0]*Wpk[3][10][2])-(ri[6][2]*
          Wpk[3][10][0])));
        VWri[3][11][2] = (Vpk[3][10][2]+((ri[6][1]*Wpk[3][10][0])-(ri[6][0]*
          Wpk[3][10][1])));
        Vpk[3][11][0] = (((Cik[11][2][0]*VWri[3][11][2])+((Cik[11][0][0]*
          VWri[3][11][0])+(Cik[11][1][0]*VWri[3][11][1])))+((rk[6][1]*
          Wpk[3][11][2])-(rk[6][2]*Wpk[3][11][1])));
        Vpk[3][11][1] = (((Cik[11][2][1]*VWri[3][11][2])+((Cik[11][0][1]*
          VWri[3][11][0])+(Cik[11][1][1]*VWri[3][11][1])))+((rk[6][2]*
          Wpk[3][11][0])-(rk[6][0]*Wpk[3][11][2])));
        Vpk[3][11][2] = (((Cik[11][2][2]*VWri[3][11][2])+((Cik[11][0][2]*
          VWri[3][11][0])+(Cik[11][1][2]*VWri[3][11][1])))+((rk[6][0]*
          Wpk[3][11][1])-(rk[6][1]*Wpk[3][11][0])));
        VWri[3][12][1] = (rk[0][2]-ri[7][2]);
        VWri[3][12][2] = (ri[7][1]-rk[0][1]);
        Vpk[3][12][0] = (((Cik[12][0][2]*rk[7][1])-(Cik[12][0][1]*rk[7][2]))+((
          Cik[12][1][0]*VWri[3][12][1])+(Cik[12][2][0]*VWri[3][12][2])));
        Vpk[3][12][1] = (((Cik[12][0][0]*rk[7][2])-(Cik[12][0][2]*rk[7][0]))+((
          Cik[12][1][1]*VWri[3][12][1])+(Cik[12][2][1]*VWri[3][12][2])));
        Vpk[3][12][2] = (((Cik[12][0][1]*rk[7][0])-(Cik[12][0][0]*rk[7][1]))+((
          Cik[12][1][2]*VWri[3][12][1])+(Cik[12][2][2]*VWri[3][12][2])));
        VWri[3][13][0] = (Vpk[3][12][0]+((Cik[12][0][1]*ri[8][2])-(Cik[12][0][2]
          *ri[8][1])));
        VWri[3][13][1] = (Vpk[3][12][1]+((Cik[12][0][2]*ri[8][0])-(Cik[12][0][0]
          *ri[8][2])));
        VWri[3][13][2] = (Vpk[3][12][2]+((Cik[12][0][0]*ri[8][1])-(Cik[12][0][1]
          *ri[8][0])));
        Vpk[3][13][0] = (((Cik[13][2][0]*VWri[3][13][2])+((Cik[13][0][0]*
          VWri[3][13][0])+(Cik[13][1][0]*VWri[3][13][1])))+((rk[8][1]*
          Wpk[3][13][2])-(rk[8][2]*Wpk[3][13][1])));
        Vpk[3][13][1] = (((Cik[13][2][1]*VWri[3][13][2])+((Cik[13][0][1]*
          VWri[3][13][0])+(Cik[13][1][1]*VWri[3][13][1])))+((rk[8][2]*
          Wpk[3][13][0])-(rk[8][0]*Wpk[3][13][2])));
        Vpk[3][13][2] = (((Cik[13][2][2]*VWri[3][13][2])+((Cik[13][0][2]*
          VWri[3][13][0])+(Cik[13][1][2]*VWri[3][13][1])))+((rk[8][0]*
          Wpk[3][13][1])-(rk[8][1]*Wpk[3][13][0])));
        VWri[3][14][0] = (Vpk[3][13][0]+((ri[9][2]*Wpk[3][13][1])-(ri[9][1]*
          Wpk[3][13][2])));
        VWri[3][14][1] = (Vpk[3][13][1]+((ri[9][0]*Wpk[3][13][2])-(ri[9][2]*
          Wpk[3][13][0])));
        VWri[3][14][2] = (Vpk[3][13][2]+((ri[9][1]*Wpk[3][13][0])-(ri[9][0]*
          Wpk[3][13][1])));
        Vpk[3][14][0] = (((Cik[14][2][0]*VWri[3][14][2])+((Cik[14][0][0]*
          VWri[3][14][0])+(Cik[14][1][0]*VWri[3][14][1])))+((rk[9][1]*
          Wpk[3][14][2])-(rk[9][2]*Wpk[3][14][1])));
        Vpk[3][14][1] = (((Cik[14][2][1]*VWri[3][14][2])+((Cik[14][0][1]*
          VWri[3][14][0])+(Cik[14][1][1]*VWri[3][14][1])))+((rk[9][2]*
          Wpk[3][14][0])-(rk[9][0]*Wpk[3][14][2])));
        Vpk[3][14][2] = (((Cik[14][2][2]*VWri[3][14][2])+((Cik[14][0][2]*
          VWri[3][14][0])+(Cik[14][1][2]*VWri[3][14][1])))+((rk[9][0]*
          Wpk[3][14][1])-(rk[9][1]*Wpk[3][14][0])));
        VWri[3][15][1] = (rk[0][2]-ri[10][2]);
        VWri[3][15][2] = (ri[10][1]-rk[0][1]);
        Vpk[3][15][0] = (((Cik[15][0][2]*rk[10][1])-(Cik[15][0][1]*rk[10][2]))+(
          (Cik[15][1][0]*VWri[3][15][1])+(Cik[15][2][0]*VWri[3][15][2])));
        Vpk[3][15][1] = (((Cik[15][0][0]*rk[10][2])-(Cik[15][0][2]*rk[10][0]))+(
          (Cik[15][1][1]*VWri[3][15][1])+(Cik[15][2][1]*VWri[3][15][2])));
        Vpk[3][15][2] = (((Cik[15][0][1]*rk[10][0])-(Cik[15][0][0]*rk[10][1]))+(
          (Cik[15][1][2]*VWri[3][15][1])+(Cik[15][2][2]*VWri[3][15][2])));
        VWri[3][16][0] = (Vpk[3][15][0]+((Cik[15][0][1]*ri[11][2])-(
          Cik[15][0][2]*ri[11][1])));
        VWri[3][16][1] = (Vpk[3][15][1]+((Cik[15][0][2]*ri[11][0])-(
          Cik[15][0][0]*ri[11][2])));
        VWri[3][16][2] = (Vpk[3][15][2]+((Cik[15][0][0]*ri[11][1])-(
          Cik[15][0][1]*ri[11][0])));
        Vpk[3][16][0] = (((Cik[16][2][0]*VWri[3][16][2])+((Cik[16][0][0]*
          VWri[3][16][0])+(Cik[16][1][0]*VWri[3][16][1])))+((rk[11][1]*
          Wpk[3][16][2])-(rk[11][2]*Wpk[3][16][1])));
        Vpk[3][16][1] = (((Cik[16][2][1]*VWri[3][16][2])+((Cik[16][0][1]*
          VWri[3][16][0])+(Cik[16][1][1]*VWri[3][16][1])))+((rk[11][2]*
          Wpk[3][16][0])-(rk[11][0]*Wpk[3][16][2])));
        Vpk[3][16][2] = (((Cik[16][2][2]*VWri[3][16][2])+((Cik[16][0][2]*
          VWri[3][16][0])+(Cik[16][1][2]*VWri[3][16][1])))+((rk[11][0]*
          Wpk[3][16][1])-(rk[11][1]*Wpk[3][16][0])));
        VWri[3][17][0] = (Vpk[3][16][0]+((ri[12][2]*Wpk[3][16][1])-(ri[12][1]*
          Wpk[3][16][2])));
        VWri[3][17][1] = (Vpk[3][16][1]+((ri[12][0]*Wpk[3][16][2])-(ri[12][2]*
          Wpk[3][16][0])));
        VWri[3][17][2] = (Vpk[3][16][2]+((ri[12][1]*Wpk[3][16][0])-(ri[12][0]*
          Wpk[3][16][1])));
        Vpk[3][17][0] = (((Cik[17][2][0]*VWri[3][17][2])+((Cik[17][0][0]*
          VWri[3][17][0])+(Cik[17][1][0]*VWri[3][17][1])))+((rk[12][1]*
          Wpk[3][17][2])-(rk[12][2]*Wpk[3][17][1])));
        Vpk[3][17][1] = (((Cik[17][2][1]*VWri[3][17][2])+((Cik[17][0][1]*
          VWri[3][17][0])+(Cik[17][1][1]*VWri[3][17][1])))+((rk[12][2]*
          Wpk[3][17][0])-(rk[12][0]*Wpk[3][17][2])));
        Vpk[3][17][2] = (((Cik[17][2][2]*VWri[3][17][2])+((Cik[17][0][2]*
          VWri[3][17][0])+(Cik[17][1][2]*VWri[3][17][1])))+((rk[12][0]*
          Wpk[3][17][1])-(rk[12][1]*Wpk[3][17][0])));
        Vpk[4][5][0] = -rk[0][2];
        Vpk[4][5][2] = rk[0][0];
        VWri[4][6][0] = (ri[1][2]-rk[0][2]);
        VWri[4][6][2] = (rk[0][0]-ri[1][0]);
        Vpk[4][6][0] = (((Cik[6][0][0]*VWri[4][6][0])+(Cik[6][2][0]*
          VWri[4][6][2]))+((Cik[6][1][2]*rk[1][1])-(Cik[6][1][1]*rk[1][2])));
        Vpk[4][6][1] = (((Cik[6][0][1]*VWri[4][6][0])+(Cik[6][2][1]*
          VWri[4][6][2]))+((Cik[6][1][0]*rk[1][2])-(Cik[6][1][2]*rk[1][0])));
        Vpk[4][6][2] = (((Cik[6][0][2]*VWri[4][6][0])+(Cik[6][2][2]*
          VWri[4][6][2]))+((Cik[6][1][1]*rk[1][0])-(Cik[6][1][0]*rk[1][1])));
        VWri[4][7][0] = (Vpk[4][6][0]+((Cik[6][1][1]*ri[2][2])-(Cik[6][1][2]*
          ri[2][1])));
        VWri[4][7][1] = (Vpk[4][6][1]+((Cik[6][1][2]*ri[2][0])-(Cik[6][1][0]*
          ri[2][2])));
        VWri[4][7][2] = (Vpk[4][6][2]+((Cik[6][1][0]*ri[2][1])-(Cik[6][1][1]*
          ri[2][0])));
        Vpk[4][7][0] = (((Cik[7][2][0]*VWri[4][7][2])+((Cik[7][0][0]*
          VWri[4][7][0])+(Cik[7][1][0]*VWri[4][7][1])))+((rk[2][1]*Wpk[4][7][2])
          -(rk[2][2]*Wpk[4][7][1])));
        Vpk[4][7][1] = (((Cik[7][2][1]*VWri[4][7][2])+((Cik[7][0][1]*
          VWri[4][7][0])+(Cik[7][1][1]*VWri[4][7][1])))+((rk[2][2]*Wpk[4][7][0])
          -(rk[2][0]*Wpk[4][7][2])));
        Vpk[4][7][2] = (((Cik[7][2][2]*VWri[4][7][2])+((Cik[7][0][2]*
          VWri[4][7][0])+(Cik[7][1][2]*VWri[4][7][1])))+((rk[2][0]*Wpk[4][7][1])
          -(rk[2][1]*Wpk[4][7][0])));
        VWri[4][8][0] = (Vpk[4][7][0]+((ri[3][2]*Wpk[4][7][1])-(ri[3][1]*
          Wpk[4][7][2])));
        VWri[4][8][1] = (Vpk[4][7][1]+((ri[3][0]*Wpk[4][7][2])-(ri[3][2]*
          Wpk[4][7][0])));
        VWri[4][8][2] = (Vpk[4][7][2]+((ri[3][1]*Wpk[4][7][0])-(ri[3][0]*
          Wpk[4][7][1])));
        Vpk[4][8][0] = (((Cik[8][2][0]*VWri[4][8][2])+((Cik[8][0][0]*
          VWri[4][8][0])+(Cik[8][1][0]*VWri[4][8][1])))+((rk[3][1]*Wpk[4][8][2])
          -(rk[3][2]*Wpk[4][8][1])));
        Vpk[4][8][1] = (((Cik[8][2][1]*VWri[4][8][2])+((Cik[8][0][1]*
          VWri[4][8][0])+(Cik[8][1][1]*VWri[4][8][1])))+((rk[3][2]*Wpk[4][8][0])
          -(rk[3][0]*Wpk[4][8][2])));
        Vpk[4][8][2] = (((Cik[8][2][2]*VWri[4][8][2])+((Cik[8][0][2]*
          VWri[4][8][0])+(Cik[8][1][2]*VWri[4][8][1])))+((rk[3][0]*Wpk[4][8][1])
          -(rk[3][1]*Wpk[4][8][0])));
        VWri[4][9][0] = (ri[4][2]-rk[0][2]);
        VWri[4][9][2] = (rk[0][0]-ri[4][0]);
        Vpk[4][9][0] = (((Cik[9][0][0]*VWri[4][9][0])+(Cik[9][2][0]*
          VWri[4][9][2]))+((Cik[9][1][2]*rk[4][1])-(Cik[9][1][1]*rk[4][2])));
        Vpk[4][9][1] = (((Cik[9][0][1]*VWri[4][9][0])+(Cik[9][2][1]*
          VWri[4][9][2]))+((Cik[9][1][0]*rk[4][2])-(Cik[9][1][2]*rk[4][0])));
        Vpk[4][9][2] = (((Cik[9][0][2]*VWri[4][9][0])+(Cik[9][2][2]*
          VWri[4][9][2]))+((Cik[9][1][1]*rk[4][0])-(Cik[9][1][0]*rk[4][1])));
        VWri[4][10][0] = (Vpk[4][9][0]+((Cik[9][1][1]*ri[5][2])-(Cik[9][1][2]*
          ri[5][1])));
        VWri[4][10][1] = (Vpk[4][9][1]+((Cik[9][1][2]*ri[5][0])-(Cik[9][1][0]*
          ri[5][2])));
        VWri[4][10][2] = (Vpk[4][9][2]+((Cik[9][1][0]*ri[5][1])-(Cik[9][1][1]*
          ri[5][0])));
        Vpk[4][10][0] = (((Cik[10][2][0]*VWri[4][10][2])+((Cik[10][0][0]*
          VWri[4][10][0])+(Cik[10][1][0]*VWri[4][10][1])))+((rk[5][1]*
          Wpk[4][10][2])-(rk[5][2]*Wpk[4][10][1])));
        Vpk[4][10][1] = (((Cik[10][2][1]*VWri[4][10][2])+((Cik[10][0][1]*
          VWri[4][10][0])+(Cik[10][1][1]*VWri[4][10][1])))+((rk[5][2]*
          Wpk[4][10][0])-(rk[5][0]*Wpk[4][10][2])));
        Vpk[4][10][2] = (((Cik[10][2][2]*VWri[4][10][2])+((Cik[10][0][2]*
          VWri[4][10][0])+(Cik[10][1][2]*VWri[4][10][1])))+((rk[5][0]*
          Wpk[4][10][1])-(rk[5][1]*Wpk[4][10][0])));
        VWri[4][11][0] = (Vpk[4][10][0]+((ri[6][2]*Wpk[4][10][1])-(ri[6][1]*
          Wpk[4][10][2])));
        VWri[4][11][1] = (Vpk[4][10][1]+((ri[6][0]*Wpk[4][10][2])-(ri[6][2]*
          Wpk[4][10][0])));
        VWri[4][11][2] = (Vpk[4][10][2]+((ri[6][1]*Wpk[4][10][0])-(ri[6][0]*
          Wpk[4][10][1])));
        Vpk[4][11][0] = (((Cik[11][2][0]*VWri[4][11][2])+((Cik[11][0][0]*
          VWri[4][11][0])+(Cik[11][1][0]*VWri[4][11][1])))+((rk[6][1]*
          Wpk[4][11][2])-(rk[6][2]*Wpk[4][11][1])));
        Vpk[4][11][1] = (((Cik[11][2][1]*VWri[4][11][2])+((Cik[11][0][1]*
          VWri[4][11][0])+(Cik[11][1][1]*VWri[4][11][1])))+((rk[6][2]*
          Wpk[4][11][0])-(rk[6][0]*Wpk[4][11][2])));
        Vpk[4][11][2] = (((Cik[11][2][2]*VWri[4][11][2])+((Cik[11][0][2]*
          VWri[4][11][0])+(Cik[11][1][2]*VWri[4][11][1])))+((rk[6][0]*
          Wpk[4][11][1])-(rk[6][1]*Wpk[4][11][0])));
        VWri[4][12][0] = (ri[7][2]-rk[0][2]);
        VWri[4][12][2] = (rk[0][0]-ri[7][0]);
        Vpk[4][12][0] = (((Cik[12][0][0]*VWri[4][12][0])+(Cik[12][2][0]*
          VWri[4][12][2]))+((Cik[12][1][2]*rk[7][1])-(Cik[12][1][1]*rk[7][2])));
        Vpk[4][12][1] = (((Cik[12][0][1]*VWri[4][12][0])+(Cik[12][2][1]*
          VWri[4][12][2]))+((Cik[12][1][0]*rk[7][2])-(Cik[12][1][2]*rk[7][0])));
        Vpk[4][12][2] = (((Cik[12][0][2]*VWri[4][12][0])+(Cik[12][2][2]*
          VWri[4][12][2]))+((Cik[12][1][1]*rk[7][0])-(Cik[12][1][0]*rk[7][1])));
        VWri[4][13][0] = (Vpk[4][12][0]+((Cik[12][1][1]*ri[8][2])-(Cik[12][1][2]
          *ri[8][1])));
        VWri[4][13][1] = (Vpk[4][12][1]+((Cik[12][1][2]*ri[8][0])-(Cik[12][1][0]
          *ri[8][2])));
        VWri[4][13][2] = (Vpk[4][12][2]+((Cik[12][1][0]*ri[8][1])-(Cik[12][1][1]
          *ri[8][0])));
        Vpk[4][13][0] = (((Cik[13][2][0]*VWri[4][13][2])+((Cik[13][0][0]*
          VWri[4][13][0])+(Cik[13][1][0]*VWri[4][13][1])))+((rk[8][1]*
          Wpk[4][13][2])-(rk[8][2]*Wpk[4][13][1])));
        Vpk[4][13][1] = (((Cik[13][2][1]*VWri[4][13][2])+((Cik[13][0][1]*
          VWri[4][13][0])+(Cik[13][1][1]*VWri[4][13][1])))+((rk[8][2]*
          Wpk[4][13][0])-(rk[8][0]*Wpk[4][13][2])));
        Vpk[4][13][2] = (((Cik[13][2][2]*VWri[4][13][2])+((Cik[13][0][2]*
          VWri[4][13][0])+(Cik[13][1][2]*VWri[4][13][1])))+((rk[8][0]*
          Wpk[4][13][1])-(rk[8][1]*Wpk[4][13][0])));
        VWri[4][14][0] = (Vpk[4][13][0]+((ri[9][2]*Wpk[4][13][1])-(ri[9][1]*
          Wpk[4][13][2])));
        VWri[4][14][1] = (Vpk[4][13][1]+((ri[9][0]*Wpk[4][13][2])-(ri[9][2]*
          Wpk[4][13][0])));
        VWri[4][14][2] = (Vpk[4][13][2]+((ri[9][1]*Wpk[4][13][0])-(ri[9][0]*
          Wpk[4][13][1])));
        Vpk[4][14][0] = (((Cik[14][2][0]*VWri[4][14][2])+((Cik[14][0][0]*
          VWri[4][14][0])+(Cik[14][1][0]*VWri[4][14][1])))+((rk[9][1]*
          Wpk[4][14][2])-(rk[9][2]*Wpk[4][14][1])));
        Vpk[4][14][1] = (((Cik[14][2][1]*VWri[4][14][2])+((Cik[14][0][1]*
          VWri[4][14][0])+(Cik[14][1][1]*VWri[4][14][1])))+((rk[9][2]*
          Wpk[4][14][0])-(rk[9][0]*Wpk[4][14][2])));
        Vpk[4][14][2] = (((Cik[14][2][2]*VWri[4][14][2])+((Cik[14][0][2]*
          VWri[4][14][0])+(Cik[14][1][2]*VWri[4][14][1])))+((rk[9][0]*
          Wpk[4][14][1])-(rk[9][1]*Wpk[4][14][0])));
        VWri[4][15][0] = (ri[10][2]-rk[0][2]);
        VWri[4][15][2] = (rk[0][0]-ri[10][0]);
        Vpk[4][15][0] = (((Cik[15][0][0]*VWri[4][15][0])+(Cik[15][2][0]*
          VWri[4][15][2]))+((Cik[15][1][2]*rk[10][1])-(Cik[15][1][1]*rk[10][2]))
          );
        Vpk[4][15][1] = (((Cik[15][0][1]*VWri[4][15][0])+(Cik[15][2][1]*
          VWri[4][15][2]))+((Cik[15][1][0]*rk[10][2])-(Cik[15][1][2]*rk[10][0]))
          );
        Vpk[4][15][2] = (((Cik[15][0][2]*VWri[4][15][0])+(Cik[15][2][2]*
          VWri[4][15][2]))+((Cik[15][1][1]*rk[10][0])-(Cik[15][1][0]*rk[10][1]))
          );
        VWri[4][16][0] = (Vpk[4][15][0]+((Cik[15][1][1]*ri[11][2])-(
          Cik[15][1][2]*ri[11][1])));
        VWri[4][16][1] = (Vpk[4][15][1]+((Cik[15][1][2]*ri[11][0])-(
          Cik[15][1][0]*ri[11][2])));
        VWri[4][16][2] = (Vpk[4][15][2]+((Cik[15][1][0]*ri[11][1])-(
          Cik[15][1][1]*ri[11][0])));
        Vpk[4][16][0] = (((Cik[16][2][0]*VWri[4][16][2])+((Cik[16][0][0]*
          VWri[4][16][0])+(Cik[16][1][0]*VWri[4][16][1])))+((rk[11][1]*
          Wpk[4][16][2])-(rk[11][2]*Wpk[4][16][1])));
        Vpk[4][16][1] = (((Cik[16][2][1]*VWri[4][16][2])+((Cik[16][0][1]*
          VWri[4][16][0])+(Cik[16][1][1]*VWri[4][16][1])))+((rk[11][2]*
          Wpk[4][16][0])-(rk[11][0]*Wpk[4][16][2])));
        Vpk[4][16][2] = (((Cik[16][2][2]*VWri[4][16][2])+((Cik[16][0][2]*
          VWri[4][16][0])+(Cik[16][1][2]*VWri[4][16][1])))+((rk[11][0]*
          Wpk[4][16][1])-(rk[11][1]*Wpk[4][16][0])));
        VWri[4][17][0] = (Vpk[4][16][0]+((ri[12][2]*Wpk[4][16][1])-(ri[12][1]*
          Wpk[4][16][2])));
        VWri[4][17][1] = (Vpk[4][16][1]+((ri[12][0]*Wpk[4][16][2])-(ri[12][2]*
          Wpk[4][16][0])));
        VWri[4][17][2] = (Vpk[4][16][2]+((ri[12][1]*Wpk[4][16][0])-(ri[12][0]*
          Wpk[4][16][1])));
        Vpk[4][17][0] = (((Cik[17][2][0]*VWri[4][17][2])+((Cik[17][0][0]*
          VWri[4][17][0])+(Cik[17][1][0]*VWri[4][17][1])))+((rk[12][1]*
          Wpk[4][17][2])-(rk[12][2]*Wpk[4][17][1])));
        Vpk[4][17][1] = (((Cik[17][2][1]*VWri[4][17][2])+((Cik[17][0][1]*
          VWri[4][17][0])+(Cik[17][1][1]*VWri[4][17][1])))+((rk[12][2]*
          Wpk[4][17][0])-(rk[12][0]*Wpk[4][17][2])));
        Vpk[4][17][2] = (((Cik[17][2][2]*VWri[4][17][2])+((Cik[17][0][2]*
          VWri[4][17][0])+(Cik[17][1][2]*VWri[4][17][1])))+((rk[12][0]*
          Wpk[4][17][1])-(rk[12][1]*Wpk[4][17][0])));
        Vpk[5][5][0] = rk[0][1];
        Vpk[5][5][1] = -rk[0][0];
        VWri[5][6][0] = (rk[0][1]-ri[1][1]);
        VWri[5][6][1] = (ri[1][0]-rk[0][0]);
        Vpk[5][6][0] = (((Cik[6][0][0]*VWri[5][6][0])+(Cik[6][1][0]*
          VWri[5][6][1]))+((Cik[6][2][2]*rk[1][1])-(Cik[6][2][1]*rk[1][2])));
        Vpk[5][6][1] = (((Cik[6][0][1]*VWri[5][6][0])+(Cik[6][1][1]*
          VWri[5][6][1]))+((Cik[6][2][0]*rk[1][2])-(Cik[6][2][2]*rk[1][0])));
        Vpk[5][6][2] = (((Cik[6][0][2]*VWri[5][6][0])+(Cik[6][1][2]*
          VWri[5][6][1]))+((Cik[6][2][1]*rk[1][0])-(Cik[6][2][0]*rk[1][1])));
        VWri[5][7][0] = (Vpk[5][6][0]+((Cik[6][2][1]*ri[2][2])-(Cik[6][2][2]*
          ri[2][1])));
        VWri[5][7][1] = (Vpk[5][6][1]+((Cik[6][2][2]*ri[2][0])-(Cik[6][2][0]*
          ri[2][2])));
        VWri[5][7][2] = (Vpk[5][6][2]+((Cik[6][2][0]*ri[2][1])-(Cik[6][2][1]*
          ri[2][0])));
        Vpk[5][7][0] = (((Cik[7][2][0]*VWri[5][7][2])+((Cik[7][0][0]*
          VWri[5][7][0])+(Cik[7][1][0]*VWri[5][7][1])))+((rk[2][1]*Wpk[5][7][2])
          -(rk[2][2]*Wpk[5][7][1])));
        Vpk[5][7][1] = (((Cik[7][2][1]*VWri[5][7][2])+((Cik[7][0][1]*
          VWri[5][7][0])+(Cik[7][1][1]*VWri[5][7][1])))+((rk[2][2]*Wpk[5][7][0])
          -(rk[2][0]*Wpk[5][7][2])));
        Vpk[5][7][2] = (((Cik[7][2][2]*VWri[5][7][2])+((Cik[7][0][2]*
          VWri[5][7][0])+(Cik[7][1][2]*VWri[5][7][1])))+((rk[2][0]*Wpk[5][7][1])
          -(rk[2][1]*Wpk[5][7][0])));
        VWri[5][8][0] = (Vpk[5][7][0]+((ri[3][2]*Wpk[5][7][1])-(ri[3][1]*
          Wpk[5][7][2])));
        VWri[5][8][1] = (Vpk[5][7][1]+((ri[3][0]*Wpk[5][7][2])-(ri[3][2]*
          Wpk[5][7][0])));
        VWri[5][8][2] = (Vpk[5][7][2]+((ri[3][1]*Wpk[5][7][0])-(ri[3][0]*
          Wpk[5][7][1])));
        Vpk[5][8][0] = (((Cik[8][2][0]*VWri[5][8][2])+((Cik[8][0][0]*
          VWri[5][8][0])+(Cik[8][1][0]*VWri[5][8][1])))+((rk[3][1]*Wpk[5][8][2])
          -(rk[3][2]*Wpk[5][8][1])));
        Vpk[5][8][1] = (((Cik[8][2][1]*VWri[5][8][2])+((Cik[8][0][1]*
          VWri[5][8][0])+(Cik[8][1][1]*VWri[5][8][1])))+((rk[3][2]*Wpk[5][8][0])
          -(rk[3][0]*Wpk[5][8][2])));
        Vpk[5][8][2] = (((Cik[8][2][2]*VWri[5][8][2])+((Cik[8][0][2]*
          VWri[5][8][0])+(Cik[8][1][2]*VWri[5][8][1])))+((rk[3][0]*Wpk[5][8][1])
          -(rk[3][1]*Wpk[5][8][0])));
        VWri[5][9][0] = (rk[0][1]-ri[4][1]);
        VWri[5][9][1] = (ri[4][0]-rk[0][0]);
        Vpk[5][9][0] = (((Cik[9][0][0]*VWri[5][9][0])+(Cik[9][1][0]*
          VWri[5][9][1]))+((Cik[9][2][2]*rk[4][1])-(Cik[9][2][1]*rk[4][2])));
        Vpk[5][9][1] = (((Cik[9][0][1]*VWri[5][9][0])+(Cik[9][1][1]*
          VWri[5][9][1]))+((Cik[9][2][0]*rk[4][2])-(Cik[9][2][2]*rk[4][0])));
        Vpk[5][9][2] = (((Cik[9][0][2]*VWri[5][9][0])+(Cik[9][1][2]*
          VWri[5][9][1]))+((Cik[9][2][1]*rk[4][0])-(Cik[9][2][0]*rk[4][1])));
        VWri[5][10][0] = (Vpk[5][9][0]+((Cik[9][2][1]*ri[5][2])-(Cik[9][2][2]*
          ri[5][1])));
        VWri[5][10][1] = (Vpk[5][9][1]+((Cik[9][2][2]*ri[5][0])-(Cik[9][2][0]*
          ri[5][2])));
        VWri[5][10][2] = (Vpk[5][9][2]+((Cik[9][2][0]*ri[5][1])-(Cik[9][2][1]*
          ri[5][0])));
        Vpk[5][10][0] = (((Cik[10][2][0]*VWri[5][10][2])+((Cik[10][0][0]*
          VWri[5][10][0])+(Cik[10][1][0]*VWri[5][10][1])))+((rk[5][1]*
          Wpk[5][10][2])-(rk[5][2]*Wpk[5][10][1])));
        Vpk[5][10][1] = (((Cik[10][2][1]*VWri[5][10][2])+((Cik[10][0][1]*
          VWri[5][10][0])+(Cik[10][1][1]*VWri[5][10][1])))+((rk[5][2]*
          Wpk[5][10][0])-(rk[5][0]*Wpk[5][10][2])));
        Vpk[5][10][2] = (((Cik[10][2][2]*VWri[5][10][2])+((Cik[10][0][2]*
          VWri[5][10][0])+(Cik[10][1][2]*VWri[5][10][1])))+((rk[5][0]*
          Wpk[5][10][1])-(rk[5][1]*Wpk[5][10][0])));
        VWri[5][11][0] = (Vpk[5][10][0]+((ri[6][2]*Wpk[5][10][1])-(ri[6][1]*
          Wpk[5][10][2])));
        VWri[5][11][1] = (Vpk[5][10][1]+((ri[6][0]*Wpk[5][10][2])-(ri[6][2]*
          Wpk[5][10][0])));
        VWri[5][11][2] = (Vpk[5][10][2]+((ri[6][1]*Wpk[5][10][0])-(ri[6][0]*
          Wpk[5][10][1])));
        Vpk[5][11][0] = (((Cik[11][2][0]*VWri[5][11][2])+((Cik[11][0][0]*
          VWri[5][11][0])+(Cik[11][1][0]*VWri[5][11][1])))+((rk[6][1]*
          Wpk[5][11][2])-(rk[6][2]*Wpk[5][11][1])));
        Vpk[5][11][1] = (((Cik[11][2][1]*VWri[5][11][2])+((Cik[11][0][1]*
          VWri[5][11][0])+(Cik[11][1][1]*VWri[5][11][1])))+((rk[6][2]*
          Wpk[5][11][0])-(rk[6][0]*Wpk[5][11][2])));
        Vpk[5][11][2] = (((Cik[11][2][2]*VWri[5][11][2])+((Cik[11][0][2]*
          VWri[5][11][0])+(Cik[11][1][2]*VWri[5][11][1])))+((rk[6][0]*
          Wpk[5][11][1])-(rk[6][1]*Wpk[5][11][0])));
        VWri[5][12][0] = (rk[0][1]-ri[7][1]);
        VWri[5][12][1] = (ri[7][0]-rk[0][0]);
        Vpk[5][12][0] = (((Cik[12][0][0]*VWri[5][12][0])+(Cik[12][1][0]*
          VWri[5][12][1]))+((Cik[12][2][2]*rk[7][1])-(Cik[12][2][1]*rk[7][2])));
        Vpk[5][12][1] = (((Cik[12][0][1]*VWri[5][12][0])+(Cik[12][1][1]*
          VWri[5][12][1]))+((Cik[12][2][0]*rk[7][2])-(Cik[12][2][2]*rk[7][0])));
        Vpk[5][12][2] = (((Cik[12][0][2]*VWri[5][12][0])+(Cik[12][1][2]*
          VWri[5][12][1]))+((Cik[12][2][1]*rk[7][0])-(Cik[12][2][0]*rk[7][1])));
        VWri[5][13][0] = (Vpk[5][12][0]+((Cik[12][2][1]*ri[8][2])-(Cik[12][2][2]
          *ri[8][1])));
        VWri[5][13][1] = (Vpk[5][12][1]+((Cik[12][2][2]*ri[8][0])-(Cik[12][2][0]
          *ri[8][2])));
        VWri[5][13][2] = (Vpk[5][12][2]+((Cik[12][2][0]*ri[8][1])-(Cik[12][2][1]
          *ri[8][0])));
        Vpk[5][13][0] = (((Cik[13][2][0]*VWri[5][13][2])+((Cik[13][0][0]*
          VWri[5][13][0])+(Cik[13][1][0]*VWri[5][13][1])))+((rk[8][1]*
          Wpk[5][13][2])-(rk[8][2]*Wpk[5][13][1])));
        Vpk[5][13][1] = (((Cik[13][2][1]*VWri[5][13][2])+((Cik[13][0][1]*
          VWri[5][13][0])+(Cik[13][1][1]*VWri[5][13][1])))+((rk[8][2]*
          Wpk[5][13][0])-(rk[8][0]*Wpk[5][13][2])));
        Vpk[5][13][2] = (((Cik[13][2][2]*VWri[5][13][2])+((Cik[13][0][2]*
          VWri[5][13][0])+(Cik[13][1][2]*VWri[5][13][1])))+((rk[8][0]*
          Wpk[5][13][1])-(rk[8][1]*Wpk[5][13][0])));
        VWri[5][14][0] = (Vpk[5][13][0]+((ri[9][2]*Wpk[5][13][1])-(ri[9][1]*
          Wpk[5][13][2])));
        VWri[5][14][1] = (Vpk[5][13][1]+((ri[9][0]*Wpk[5][13][2])-(ri[9][2]*
          Wpk[5][13][0])));
        VWri[5][14][2] = (Vpk[5][13][2]+((ri[9][1]*Wpk[5][13][0])-(ri[9][0]*
          Wpk[5][13][1])));
        Vpk[5][14][0] = (((Cik[14][2][0]*VWri[5][14][2])+((Cik[14][0][0]*
          VWri[5][14][0])+(Cik[14][1][0]*VWri[5][14][1])))+((rk[9][1]*
          Wpk[5][14][2])-(rk[9][2]*Wpk[5][14][1])));
        Vpk[5][14][1] = (((Cik[14][2][1]*VWri[5][14][2])+((Cik[14][0][1]*
          VWri[5][14][0])+(Cik[14][1][1]*VWri[5][14][1])))+((rk[9][2]*
          Wpk[5][14][0])-(rk[9][0]*Wpk[5][14][2])));
        Vpk[5][14][2] = (((Cik[14][2][2]*VWri[5][14][2])+((Cik[14][0][2]*
          VWri[5][14][0])+(Cik[14][1][2]*VWri[5][14][1])))+((rk[9][0]*
          Wpk[5][14][1])-(rk[9][1]*Wpk[5][14][0])));
        VWri[5][15][0] = (rk[0][1]-ri[10][1]);
        VWri[5][15][1] = (ri[10][0]-rk[0][0]);
        Vpk[5][15][0] = (((Cik[15][0][0]*VWri[5][15][0])+(Cik[15][1][0]*
          VWri[5][15][1]))+((Cik[15][2][2]*rk[10][1])-(Cik[15][2][1]*rk[10][2]))
          );
        Vpk[5][15][1] = (((Cik[15][0][1]*VWri[5][15][0])+(Cik[15][1][1]*
          VWri[5][15][1]))+((Cik[15][2][0]*rk[10][2])-(Cik[15][2][2]*rk[10][0]))
          );
        Vpk[5][15][2] = (((Cik[15][0][2]*VWri[5][15][0])+(Cik[15][1][2]*
          VWri[5][15][1]))+((Cik[15][2][1]*rk[10][0])-(Cik[15][2][0]*rk[10][1]))
          );
        VWri[5][16][0] = (Vpk[5][15][0]+((Cik[15][2][1]*ri[11][2])-(
          Cik[15][2][2]*ri[11][1])));
        VWri[5][16][1] = (Vpk[5][15][1]+((Cik[15][2][2]*ri[11][0])-(
          Cik[15][2][0]*ri[11][2])));
        VWri[5][16][2] = (Vpk[5][15][2]+((Cik[15][2][0]*ri[11][1])-(
          Cik[15][2][1]*ri[11][0])));
        Vpk[5][16][0] = (((Cik[16][2][0]*VWri[5][16][2])+((Cik[16][0][0]*
          VWri[5][16][0])+(Cik[16][1][0]*VWri[5][16][1])))+((rk[11][1]*
          Wpk[5][16][2])-(rk[11][2]*Wpk[5][16][1])));
        Vpk[5][16][1] = (((Cik[16][2][1]*VWri[5][16][2])+((Cik[16][0][1]*
          VWri[5][16][0])+(Cik[16][1][1]*VWri[5][16][1])))+((rk[11][2]*
          Wpk[5][16][0])-(rk[11][0]*Wpk[5][16][2])));
        Vpk[5][16][2] = (((Cik[16][2][2]*VWri[5][16][2])+((Cik[16][0][2]*
          VWri[5][16][0])+(Cik[16][1][2]*VWri[5][16][1])))+((rk[11][0]*
          Wpk[5][16][1])-(rk[11][1]*Wpk[5][16][0])));
        VWri[5][17][0] = (Vpk[5][16][0]+((ri[12][2]*Wpk[5][16][1])-(ri[12][1]*
          Wpk[5][16][2])));
        VWri[5][17][1] = (Vpk[5][16][1]+((ri[12][0]*Wpk[5][16][2])-(ri[12][2]*
          Wpk[5][16][0])));
        VWri[5][17][2] = (Vpk[5][16][2]+((ri[12][1]*Wpk[5][16][0])-(ri[12][0]*
          Wpk[5][16][1])));
        Vpk[5][17][0] = (((Cik[17][2][0]*VWri[5][17][2])+((Cik[17][0][0]*
          VWri[5][17][0])+(Cik[17][1][0]*VWri[5][17][1])))+((rk[12][1]*
          Wpk[5][17][2])-(rk[12][2]*Wpk[5][17][1])));
        Vpk[5][17][1] = (((Cik[17][2][1]*VWri[5][17][2])+((Cik[17][0][1]*
          VWri[5][17][0])+(Cik[17][1][1]*VWri[5][17][1])))+((rk[12][2]*
          Wpk[5][17][0])-(rk[12][0]*Wpk[5][17][2])));
        Vpk[5][17][2] = (((Cik[17][2][2]*VWri[5][17][2])+((Cik[17][0][2]*
          VWri[5][17][0])+(Cik[17][1][2]*VWri[5][17][1])))+((rk[12][0]*
          Wpk[5][17][1])-(rk[12][1]*Wpk[5][17][0])));
        Vpk[6][6][0] = ((pin[6][2]*rk[1][1])-(pin[6][1]*rk[1][2]));
        Vpk[6][6][1] = ((pin[6][0]*rk[1][2])-(pin[6][2]*rk[1][0]));
        Vpk[6][6][2] = ((pin[6][1]*rk[1][0])-(pin[6][0]*rk[1][1]));
        VWri[6][7][0] = (Vpk[6][6][0]+((pin[6][1]*ri[2][2])-(pin[6][2]*ri[2][1])
          ));
        VWri[6][7][1] = (Vpk[6][6][1]+((pin[6][2]*ri[2][0])-(pin[6][0]*ri[2][2])
          ));
        VWri[6][7][2] = (Vpk[6][6][2]+((pin[6][0]*ri[2][1])-(pin[6][1]*ri[2][0])
          ));
        Vpk[6][7][0] = (((Cik[7][2][0]*VWri[6][7][2])+((Cik[7][0][0]*
          VWri[6][7][0])+(Cik[7][1][0]*VWri[6][7][1])))+((rk[2][1]*Wpk[6][7][2])
          -(rk[2][2]*Wpk[6][7][1])));
        Vpk[6][7][1] = (((Cik[7][2][1]*VWri[6][7][2])+((Cik[7][0][1]*
          VWri[6][7][0])+(Cik[7][1][1]*VWri[6][7][1])))+((rk[2][2]*Wpk[6][7][0])
          -(rk[2][0]*Wpk[6][7][2])));
        Vpk[6][7][2] = (((Cik[7][2][2]*VWri[6][7][2])+((Cik[7][0][2]*
          VWri[6][7][0])+(Cik[7][1][2]*VWri[6][7][1])))+((rk[2][0]*Wpk[6][7][1])
          -(rk[2][1]*Wpk[6][7][0])));
        VWri[6][8][0] = (Vpk[6][7][0]+((ri[3][2]*Wpk[6][7][1])-(ri[3][1]*
          Wpk[6][7][2])));
        VWri[6][8][1] = (Vpk[6][7][1]+((ri[3][0]*Wpk[6][7][2])-(ri[3][2]*
          Wpk[6][7][0])));
        VWri[6][8][2] = (Vpk[6][7][2]+((ri[3][1]*Wpk[6][7][0])-(ri[3][0]*
          Wpk[6][7][1])));
        Vpk[6][8][0] = (((Cik[8][2][0]*VWri[6][8][2])+((Cik[8][0][0]*
          VWri[6][8][0])+(Cik[8][1][0]*VWri[6][8][1])))+((rk[3][1]*Wpk[6][8][2])
          -(rk[3][2]*Wpk[6][8][1])));
        Vpk[6][8][1] = (((Cik[8][2][1]*VWri[6][8][2])+((Cik[8][0][1]*
          VWri[6][8][0])+(Cik[8][1][1]*VWri[6][8][1])))+((rk[3][2]*Wpk[6][8][0])
          -(rk[3][0]*Wpk[6][8][2])));
        Vpk[6][8][2] = (((Cik[8][2][2]*VWri[6][8][2])+((Cik[8][0][2]*
          VWri[6][8][0])+(Cik[8][1][2]*VWri[6][8][1])))+((rk[3][0]*Wpk[6][8][1])
          -(rk[3][1]*Wpk[6][8][0])));
        Vpk[7][7][0] = ((pin[7][2]*rk[2][1])-(pin[7][1]*rk[2][2]));
        Vpk[7][7][1] = ((pin[7][0]*rk[2][2])-(pin[7][2]*rk[2][0]));
        Vpk[7][7][2] = ((pin[7][1]*rk[2][0])-(pin[7][0]*rk[2][1]));
        VWri[7][8][0] = (Vpk[7][7][0]+((pin[7][1]*ri[3][2])-(pin[7][2]*ri[3][1])
          ));
        VWri[7][8][1] = (Vpk[7][7][1]+((pin[7][2]*ri[3][0])-(pin[7][0]*ri[3][2])
          ));
        VWri[7][8][2] = (Vpk[7][7][2]+((pin[7][0]*ri[3][1])-(pin[7][1]*ri[3][0])
          ));
        Vpk[7][8][0] = (((Cik[8][2][0]*VWri[7][8][2])+((Cik[8][0][0]*
          VWri[7][8][0])+(Cik[8][1][0]*VWri[7][8][1])))+((rk[3][1]*Wpk[7][8][2])
          -(rk[3][2]*Wpk[7][8][1])));
        Vpk[7][8][1] = (((Cik[8][2][1]*VWri[7][8][2])+((Cik[8][0][1]*
          VWri[7][8][0])+(Cik[8][1][1]*VWri[7][8][1])))+((rk[3][2]*Wpk[7][8][0])
          -(rk[3][0]*Wpk[7][8][2])));
        Vpk[7][8][2] = (((Cik[8][2][2]*VWri[7][8][2])+((Cik[8][0][2]*
          VWri[7][8][0])+(Cik[8][1][2]*VWri[7][8][1])))+((rk[3][0]*Wpk[7][8][1])
          -(rk[3][1]*Wpk[7][8][0])));
        Vpk[8][8][0] = ((pin[8][2]*rk[3][1])-(pin[8][1]*rk[3][2]));
        Vpk[8][8][1] = ((pin[8][0]*rk[3][2])-(pin[8][2]*rk[3][0]));
        Vpk[8][8][2] = ((pin[8][1]*rk[3][0])-(pin[8][0]*rk[3][1]));
        Vpk[9][9][0] = ((pin[9][2]*rk[4][1])-(pin[9][1]*rk[4][2]));
        Vpk[9][9][1] = ((pin[9][0]*rk[4][2])-(pin[9][2]*rk[4][0]));
        Vpk[9][9][2] = ((pin[9][1]*rk[4][0])-(pin[9][0]*rk[4][1]));
        VWri[9][10][0] = (Vpk[9][9][0]+((pin[9][1]*ri[5][2])-(pin[9][2]*ri[5][1]
          )));
        VWri[9][10][1] = (Vpk[9][9][1]+((pin[9][2]*ri[5][0])-(pin[9][0]*ri[5][2]
          )));
        VWri[9][10][2] = (Vpk[9][9][2]+((pin[9][0]*ri[5][1])-(pin[9][1]*ri[5][0]
          )));
        Vpk[9][10][0] = (((Cik[10][2][0]*VWri[9][10][2])+((Cik[10][0][0]*
          VWri[9][10][0])+(Cik[10][1][0]*VWri[9][10][1])))+((rk[5][1]*
          Wpk[9][10][2])-(rk[5][2]*Wpk[9][10][1])));
        Vpk[9][10][1] = (((Cik[10][2][1]*VWri[9][10][2])+((Cik[10][0][1]*
          VWri[9][10][0])+(Cik[10][1][1]*VWri[9][10][1])))+((rk[5][2]*
          Wpk[9][10][0])-(rk[5][0]*Wpk[9][10][2])));
        Vpk[9][10][2] = (((Cik[10][2][2]*VWri[9][10][2])+((Cik[10][0][2]*
          VWri[9][10][0])+(Cik[10][1][2]*VWri[9][10][1])))+((rk[5][0]*
          Wpk[9][10][1])-(rk[5][1]*Wpk[9][10][0])));
        VWri[9][11][0] = (Vpk[9][10][0]+((ri[6][2]*Wpk[9][10][1])-(ri[6][1]*
          Wpk[9][10][2])));
        VWri[9][11][1] = (Vpk[9][10][1]+((ri[6][0]*Wpk[9][10][2])-(ri[6][2]*
          Wpk[9][10][0])));
        VWri[9][11][2] = (Vpk[9][10][2]+((ri[6][1]*Wpk[9][10][0])-(ri[6][0]*
          Wpk[9][10][1])));
        Vpk[9][11][0] = (((Cik[11][2][0]*VWri[9][11][2])+((Cik[11][0][0]*
          VWri[9][11][0])+(Cik[11][1][0]*VWri[9][11][1])))+((rk[6][1]*
          Wpk[9][11][2])-(rk[6][2]*Wpk[9][11][1])));
        Vpk[9][11][1] = (((Cik[11][2][1]*VWri[9][11][2])+((Cik[11][0][1]*
          VWri[9][11][0])+(Cik[11][1][1]*VWri[9][11][1])))+((rk[6][2]*
          Wpk[9][11][0])-(rk[6][0]*Wpk[9][11][2])));
        Vpk[9][11][2] = (((Cik[11][2][2]*VWri[9][11][2])+((Cik[11][0][2]*
          VWri[9][11][0])+(Cik[11][1][2]*VWri[9][11][1])))+((rk[6][0]*
          Wpk[9][11][1])-(rk[6][1]*Wpk[9][11][0])));
        Vpk[10][10][0] = ((pin[10][2]*rk[5][1])-(pin[10][1]*rk[5][2]));
        Vpk[10][10][1] = ((pin[10][0]*rk[5][2])-(pin[10][2]*rk[5][0]));
        Vpk[10][10][2] = ((pin[10][1]*rk[5][0])-(pin[10][0]*rk[5][1]));
        VWri[10][11][0] = (Vpk[10][10][0]+((pin[10][1]*ri[6][2])-(pin[10][2]*
          ri[6][1])));
        VWri[10][11][1] = (Vpk[10][10][1]+((pin[10][2]*ri[6][0])-(pin[10][0]*
          ri[6][2])));
        VWri[10][11][2] = (Vpk[10][10][2]+((pin[10][0]*ri[6][1])-(pin[10][1]*
          ri[6][0])));
        Vpk[10][11][0] = (((Cik[11][2][0]*VWri[10][11][2])+((Cik[11][0][0]*
          VWri[10][11][0])+(Cik[11][1][0]*VWri[10][11][1])))+((rk[6][1]*
          Wpk[10][11][2])-(rk[6][2]*Wpk[10][11][1])));
        Vpk[10][11][1] = (((Cik[11][2][1]*VWri[10][11][2])+((Cik[11][0][1]*
          VWri[10][11][0])+(Cik[11][1][1]*VWri[10][11][1])))+((rk[6][2]*
          Wpk[10][11][0])-(rk[6][0]*Wpk[10][11][2])));
        Vpk[10][11][2] = (((Cik[11][2][2]*VWri[10][11][2])+((Cik[11][0][2]*
          VWri[10][11][0])+(Cik[11][1][2]*VWri[10][11][1])))+((rk[6][0]*
          Wpk[10][11][1])-(rk[6][1]*Wpk[10][11][0])));
        Vpk[11][11][0] = ((pin[11][2]*rk[6][1])-(pin[11][1]*rk[6][2]));
        Vpk[11][11][1] = ((pin[11][0]*rk[6][2])-(pin[11][2]*rk[6][0]));
        Vpk[11][11][2] = ((pin[11][1]*rk[6][0])-(pin[11][0]*rk[6][1]));
        Vpk[12][12][0] = ((pin[12][2]*rk[7][1])-(pin[12][1]*rk[7][2]));
        Vpk[12][12][1] = ((pin[12][0]*rk[7][2])-(pin[12][2]*rk[7][0]));
        Vpk[12][12][2] = ((pin[12][1]*rk[7][0])-(pin[12][0]*rk[7][1]));
        VWri[12][13][0] = (Vpk[12][12][0]+((pin[12][1]*ri[8][2])-(pin[12][2]*
          ri[8][1])));
        VWri[12][13][1] = (Vpk[12][12][1]+((pin[12][2]*ri[8][0])-(pin[12][0]*
          ri[8][2])));
        VWri[12][13][2] = (Vpk[12][12][2]+((pin[12][0]*ri[8][1])-(pin[12][1]*
          ri[8][0])));
        Vpk[12][13][0] = (((Cik[13][2][0]*VWri[12][13][2])+((Cik[13][0][0]*
          VWri[12][13][0])+(Cik[13][1][0]*VWri[12][13][1])))+((rk[8][1]*
          Wpk[12][13][2])-(rk[8][2]*Wpk[12][13][1])));
        Vpk[12][13][1] = (((Cik[13][2][1]*VWri[12][13][2])+((Cik[13][0][1]*
          VWri[12][13][0])+(Cik[13][1][1]*VWri[12][13][1])))+((rk[8][2]*
          Wpk[12][13][0])-(rk[8][0]*Wpk[12][13][2])));
        Vpk[12][13][2] = (((Cik[13][2][2]*VWri[12][13][2])+((Cik[13][0][2]*
          VWri[12][13][0])+(Cik[13][1][2]*VWri[12][13][1])))+((rk[8][0]*
          Wpk[12][13][1])-(rk[8][1]*Wpk[12][13][0])));
        VWri[12][14][0] = (Vpk[12][13][0]+((ri[9][2]*Wpk[12][13][1])-(ri[9][1]*
          Wpk[12][13][2])));
        VWri[12][14][1] = (Vpk[12][13][1]+((ri[9][0]*Wpk[12][13][2])-(ri[9][2]*
          Wpk[12][13][0])));
        VWri[12][14][2] = (Vpk[12][13][2]+((ri[9][1]*Wpk[12][13][0])-(ri[9][0]*
          Wpk[12][13][1])));
        Vpk[12][14][0] = (((Cik[14][2][0]*VWri[12][14][2])+((Cik[14][0][0]*
          VWri[12][14][0])+(Cik[14][1][0]*VWri[12][14][1])))+((rk[9][1]*
          Wpk[12][14][2])-(rk[9][2]*Wpk[12][14][1])));
        Vpk[12][14][1] = (((Cik[14][2][1]*VWri[12][14][2])+((Cik[14][0][1]*
          VWri[12][14][0])+(Cik[14][1][1]*VWri[12][14][1])))+((rk[9][2]*
          Wpk[12][14][0])-(rk[9][0]*Wpk[12][14][2])));
        Vpk[12][14][2] = (((Cik[14][2][2]*VWri[12][14][2])+((Cik[14][0][2]*
          VWri[12][14][0])+(Cik[14][1][2]*VWri[12][14][1])))+((rk[9][0]*
          Wpk[12][14][1])-(rk[9][1]*Wpk[12][14][0])));
        Vpk[13][13][0] = ((pin[13][2]*rk[8][1])-(pin[13][1]*rk[8][2]));
        Vpk[13][13][1] = ((pin[13][0]*rk[8][2])-(pin[13][2]*rk[8][0]));
        Vpk[13][13][2] = ((pin[13][1]*rk[8][0])-(pin[13][0]*rk[8][1]));
        VWri[13][14][0] = (Vpk[13][13][0]+((pin[13][1]*ri[9][2])-(pin[13][2]*
          ri[9][1])));
        VWri[13][14][1] = (Vpk[13][13][1]+((pin[13][2]*ri[9][0])-(pin[13][0]*
          ri[9][2])));
        VWri[13][14][2] = (Vpk[13][13][2]+((pin[13][0]*ri[9][1])-(pin[13][1]*
          ri[9][0])));
        Vpk[13][14][0] = (((Cik[14][2][0]*VWri[13][14][2])+((Cik[14][0][0]*
          VWri[13][14][0])+(Cik[14][1][0]*VWri[13][14][1])))+((rk[9][1]*
          Wpk[13][14][2])-(rk[9][2]*Wpk[13][14][1])));
        Vpk[13][14][1] = (((Cik[14][2][1]*VWri[13][14][2])+((Cik[14][0][1]*
          VWri[13][14][0])+(Cik[14][1][1]*VWri[13][14][1])))+((rk[9][2]*
          Wpk[13][14][0])-(rk[9][0]*Wpk[13][14][2])));
        Vpk[13][14][2] = (((Cik[14][2][2]*VWri[13][14][2])+((Cik[14][0][2]*
          VWri[13][14][0])+(Cik[14][1][2]*VWri[13][14][1])))+((rk[9][0]*
          Wpk[13][14][1])-(rk[9][1]*Wpk[13][14][0])));
        Vpk[14][14][0] = ((pin[14][2]*rk[9][1])-(pin[14][1]*rk[9][2]));
        Vpk[14][14][1] = ((pin[14][0]*rk[9][2])-(pin[14][2]*rk[9][0]));
        Vpk[14][14][2] = ((pin[14][1]*rk[9][0])-(pin[14][0]*rk[9][1]));
        Vpk[15][15][0] = ((pin[15][2]*rk[10][1])-(pin[15][1]*rk[10][2]));
        Vpk[15][15][1] = ((pin[15][0]*rk[10][2])-(pin[15][2]*rk[10][0]));
        Vpk[15][15][2] = ((pin[15][1]*rk[10][0])-(pin[15][0]*rk[10][1]));
        VWri[15][16][0] = (Vpk[15][15][0]+((pin[15][1]*ri[11][2])-(pin[15][2]*
          ri[11][1])));
        VWri[15][16][1] = (Vpk[15][15][1]+((pin[15][2]*ri[11][0])-(pin[15][0]*
          ri[11][2])));
        VWri[15][16][2] = (Vpk[15][15][2]+((pin[15][0]*ri[11][1])-(pin[15][1]*
          ri[11][0])));
        Vpk[15][16][0] = (((Cik[16][2][0]*VWri[15][16][2])+((Cik[16][0][0]*
          VWri[15][16][0])+(Cik[16][1][0]*VWri[15][16][1])))+((rk[11][1]*
          Wpk[15][16][2])-(rk[11][2]*Wpk[15][16][1])));
        Vpk[15][16][1] = (((Cik[16][2][1]*VWri[15][16][2])+((Cik[16][0][1]*
          VWri[15][16][0])+(Cik[16][1][1]*VWri[15][16][1])))+((rk[11][2]*
          Wpk[15][16][0])-(rk[11][0]*Wpk[15][16][2])));
        Vpk[15][16][2] = (((Cik[16][2][2]*VWri[15][16][2])+((Cik[16][0][2]*
          VWri[15][16][0])+(Cik[16][1][2]*VWri[15][16][1])))+((rk[11][0]*
          Wpk[15][16][1])-(rk[11][1]*Wpk[15][16][0])));
        VWri[15][17][0] = (Vpk[15][16][0]+((ri[12][2]*Wpk[15][16][1])-(ri[12][1]
          *Wpk[15][16][2])));
        VWri[15][17][1] = (Vpk[15][16][1]+((ri[12][0]*Wpk[15][16][2])-(ri[12][2]
          *Wpk[15][16][0])));
        VWri[15][17][2] = (Vpk[15][16][2]+((ri[12][1]*Wpk[15][16][0])-(ri[12][0]
          *Wpk[15][16][1])));
        Vpk[15][17][0] = (((Cik[17][2][0]*VWri[15][17][2])+((Cik[17][0][0]*
          VWri[15][17][0])+(Cik[17][1][0]*VWri[15][17][1])))+((rk[12][1]*
          Wpk[15][17][2])-(rk[12][2]*Wpk[15][17][1])));
        Vpk[15][17][1] = (((Cik[17][2][1]*VWri[15][17][2])+((Cik[17][0][1]*
          VWri[15][17][0])+(Cik[17][1][1]*VWri[15][17][1])))+((rk[12][2]*
          Wpk[15][17][0])-(rk[12][0]*Wpk[15][17][2])));
        Vpk[15][17][2] = (((Cik[17][2][2]*VWri[15][17][2])+((Cik[17][0][2]*
          VWri[15][17][0])+(Cik[17][1][2]*VWri[15][17][1])))+((rk[12][0]*
          Wpk[15][17][1])-(rk[12][1]*Wpk[15][17][0])));
        Vpk[16][16][0] = ((pin[16][2]*rk[11][1])-(pin[16][1]*rk[11][2]));
        Vpk[16][16][1] = ((pin[16][0]*rk[11][2])-(pin[16][2]*rk[11][0]));
        Vpk[16][16][2] = ((pin[16][1]*rk[11][0])-(pin[16][0]*rk[11][1]));
        VWri[16][17][0] = (Vpk[16][16][0]+((pin[16][1]*ri[12][2])-(pin[16][2]*
          ri[12][1])));
        VWri[16][17][1] = (Vpk[16][16][1]+((pin[16][2]*ri[12][0])-(pin[16][0]*
          ri[12][2])));
        VWri[16][17][2] = (Vpk[16][16][2]+((pin[16][0]*ri[12][1])-(pin[16][1]*
          ri[12][0])));
        Vpk[16][17][0] = (((Cik[17][2][0]*VWri[16][17][2])+((Cik[17][0][0]*
          VWri[16][17][0])+(Cik[17][1][0]*VWri[16][17][1])))+((rk[12][1]*
          Wpk[16][17][2])-(rk[12][2]*Wpk[16][17][1])));
        Vpk[16][17][1] = (((Cik[17][2][1]*VWri[16][17][2])+((Cik[17][0][1]*
          VWri[16][17][0])+(Cik[17][1][1]*VWri[16][17][1])))+((rk[12][2]*
          Wpk[16][17][0])-(rk[12][0]*Wpk[16][17][2])));
        Vpk[16][17][2] = (((Cik[17][2][2]*VWri[16][17][2])+((Cik[17][0][2]*
          VWri[16][17][0])+(Cik[17][1][2]*VWri[16][17][1])))+((rk[12][0]*
          Wpk[16][17][1])-(rk[12][1]*Wpk[16][17][0])));
        Vpk[17][17][0] = ((pin[17][2]*rk[12][1])-(pin[17][1]*rk[12][2]));
        Vpk[17][17][1] = ((pin[17][0]*rk[12][2])-(pin[17][2]*rk[12][0]));
        Vpk[17][17][2] = ((pin[17][1]*rk[12][0])-(pin[17][0]*rk[12][1]));
        vpkflg = 1;
    }
/*
 Used 0.02 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1269 adds/subtracts/negates
                   1647 multiplies
                      0 divides
                    657 assignments
*/
}

void sddoltau(void)
{

/*
Compute effect of loop hinge torques
*/
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                      0 assignments
*/
}

void sddoiner(void)
{

/*
Compute inertial accelerations and related temps
*/
    if (inerflg == 0) {
/*
Compute Otk (inertial angular acceleration)
*/
        Otk[6][0] = ((Wik[6][2]*wk[6][1])-(Wik[6][1]*wk[6][2]));
        Otk[6][1] = ((Wik[6][0]*wk[6][2])-(Wik[6][2]*wk[6][0]));
        Otk[6][2] = ((Wik[6][1]*wk[6][0])-(Wik[6][0]*wk[6][1]));
        Otk[7][0] = (((Cik[7][2][0]*Otk[6][2])+((Cik[7][0][0]*Otk[6][0])+(
          Cik[7][1][0]*Otk[6][1])))+((Wik[7][2]*wk[7][1])-(Wik[7][1]*wk[7][2])))
          ;
        Otk[7][1] = (((Cik[7][2][1]*Otk[6][2])+((Cik[7][0][1]*Otk[6][0])+(
          Cik[7][1][1]*Otk[6][1])))+((Wik[7][0]*wk[7][2])-(Wik[7][2]*wk[7][0])))
          ;
        Otk[7][2] = (((Cik[7][2][2]*Otk[6][2])+((Cik[7][0][2]*Otk[6][0])+(
          Cik[7][1][2]*Otk[6][1])))+((Wik[7][1]*wk[7][0])-(Wik[7][0]*wk[7][1])))
          ;
        Otk[8][0] = (((Cik[8][2][0]*Otk[7][2])+((Cik[8][0][0]*Otk[7][0])+(
          Cik[8][1][0]*Otk[7][1])))+((Wik[8][2]*wk[8][1])-(Wik[8][1]*wk[8][2])))
          ;
        Otk[8][1] = (((Cik[8][2][1]*Otk[7][2])+((Cik[8][0][1]*Otk[7][0])+(
          Cik[8][1][1]*Otk[7][1])))+((Wik[8][0]*wk[8][2])-(Wik[8][2]*wk[8][0])))
          ;
        Otk[8][2] = (((Cik[8][2][2]*Otk[7][2])+((Cik[8][0][2]*Otk[7][0])+(
          Cik[8][1][2]*Otk[7][1])))+((Wik[8][1]*wk[8][0])-(Wik[8][0]*wk[8][1])))
          ;
        Otk[9][0] = ((Wik[9][2]*wk[9][1])-(Wik[9][1]*wk[9][2]));
        Otk[9][1] = ((Wik[9][0]*wk[9][2])-(Wik[9][2]*wk[9][0]));
        Otk[9][2] = ((Wik[9][1]*wk[9][0])-(Wik[9][0]*wk[9][1]));
        Otk[10][0] = (((Cik[10][2][0]*Otk[9][2])+((Cik[10][0][0]*Otk[9][0])+(
          Cik[10][1][0]*Otk[9][1])))+((Wik[10][2]*wk[10][1])-(Wik[10][1]*
          wk[10][2])));
        Otk[10][1] = (((Cik[10][2][1]*Otk[9][2])+((Cik[10][0][1]*Otk[9][0])+(
          Cik[10][1][1]*Otk[9][1])))+((Wik[10][0]*wk[10][2])-(Wik[10][2]*
          wk[10][0])));
        Otk[10][2] = (((Cik[10][2][2]*Otk[9][2])+((Cik[10][0][2]*Otk[9][0])+(
          Cik[10][1][2]*Otk[9][1])))+((Wik[10][1]*wk[10][0])-(Wik[10][0]*
          wk[10][1])));
        Otk[11][0] = (((Cik[11][2][0]*Otk[10][2])+((Cik[11][0][0]*Otk[10][0])+(
          Cik[11][1][0]*Otk[10][1])))+((Wik[11][2]*wk[11][1])-(Wik[11][1]*
          wk[11][2])));
        Otk[11][1] = (((Cik[11][2][1]*Otk[10][2])+((Cik[11][0][1]*Otk[10][0])+(
          Cik[11][1][1]*Otk[10][1])))+((Wik[11][0]*wk[11][2])-(Wik[11][2]*
          wk[11][0])));
        Otk[11][2] = (((Cik[11][2][2]*Otk[10][2])+((Cik[11][0][2]*Otk[10][0])+(
          Cik[11][1][2]*Otk[10][1])))+((Wik[11][1]*wk[11][0])-(Wik[11][0]*
          wk[11][1])));
        Otk[12][0] = ((Wik[12][2]*wk[12][1])-(Wik[12][1]*wk[12][2]));
        Otk[12][1] = ((Wik[12][0]*wk[12][2])-(Wik[12][2]*wk[12][0]));
        Otk[12][2] = ((Wik[12][1]*wk[12][0])-(Wik[12][0]*wk[12][1]));
        Otk[13][0] = (((Cik[13][2][0]*Otk[12][2])+((Cik[13][0][0]*Otk[12][0])+(
          Cik[13][1][0]*Otk[12][1])))+((Wik[13][2]*wk[13][1])-(Wik[13][1]*
          wk[13][2])));
        Otk[13][1] = (((Cik[13][2][1]*Otk[12][2])+((Cik[13][0][1]*Otk[12][0])+(
          Cik[13][1][1]*Otk[12][1])))+((Wik[13][0]*wk[13][2])-(Wik[13][2]*
          wk[13][0])));
        Otk[13][2] = (((Cik[13][2][2]*Otk[12][2])+((Cik[13][0][2]*Otk[12][0])+(
          Cik[13][1][2]*Otk[12][1])))+((Wik[13][1]*wk[13][0])-(Wik[13][0]*
          wk[13][1])));
        Otk[14][0] = (((Cik[14][2][0]*Otk[13][2])+((Cik[14][0][0]*Otk[13][0])+(
          Cik[14][1][0]*Otk[13][1])))+((Wik[14][2]*wk[14][1])-(Wik[14][1]*
          wk[14][2])));
        Otk[14][1] = (((Cik[14][2][1]*Otk[13][2])+((Cik[14][0][1]*Otk[13][0])+(
          Cik[14][1][1]*Otk[13][1])))+((Wik[14][0]*wk[14][2])-(Wik[14][2]*
          wk[14][0])));
        Otk[14][2] = (((Cik[14][2][2]*Otk[13][2])+((Cik[14][0][2]*Otk[13][0])+(
          Cik[14][1][2]*Otk[13][1])))+((Wik[14][1]*wk[14][0])-(Wik[14][0]*
          wk[14][1])));
        Otk[15][0] = ((Wik[15][2]*wk[15][1])-(Wik[15][1]*wk[15][2]));
        Otk[15][1] = ((Wik[15][0]*wk[15][2])-(Wik[15][2]*wk[15][0]));
        Otk[15][2] = ((Wik[15][1]*wk[15][0])-(Wik[15][0]*wk[15][1]));
        Otk[16][0] = (((Cik[16][2][0]*Otk[15][2])+((Cik[16][0][0]*Otk[15][0])+(
          Cik[16][1][0]*Otk[15][1])))+((Wik[16][2]*wk[16][1])-(Wik[16][1]*
          wk[16][2])));
        Otk[16][1] = (((Cik[16][2][1]*Otk[15][2])+((Cik[16][0][1]*Otk[15][0])+(
          Cik[16][1][1]*Otk[15][1])))+((Wik[16][0]*wk[16][2])-(Wik[16][2]*
          wk[16][0])));
        Otk[16][2] = (((Cik[16][2][2]*Otk[15][2])+((Cik[16][0][2]*Otk[15][0])+(
          Cik[16][1][2]*Otk[15][1])))+((Wik[16][1]*wk[16][0])-(Wik[16][0]*
          wk[16][1])));
        Otk[17][0] = (((Cik[17][2][0]*Otk[16][2])+((Cik[17][0][0]*Otk[16][0])+(
          Cik[17][1][0]*Otk[16][1])))+((Wik[17][2]*wk[17][1])-(Wik[17][1]*
          wk[17][2])));
        Otk[17][1] = (((Cik[17][2][1]*Otk[16][2])+((Cik[17][0][1]*Otk[16][0])+(
          Cik[17][1][1]*Otk[16][1])))+((Wik[17][0]*wk[17][2])-(Wik[17][2]*
          wk[17][0])));
        Otk[17][2] = (((Cik[17][2][2]*Otk[16][2])+((Cik[17][0][2]*Otk[16][0])+(
          Cik[17][1][2]*Otk[16][1])))+((Wik[17][1]*wk[17][0])-(Wik[17][0]*
          wk[17][1])));
/*
Compute Atk (inertial linear acceleration)
*/
        Atk[5][0] = ((u[4]*Wkrpk[5][2])-(u[5]*Wkrpk[5][1]));
        Atk[5][1] = ((u[5]*Wkrpk[5][0])-(u[3]*Wkrpk[5][2]));
        Atk[5][2] = ((u[3]*Wkrpk[5][1])-(u[4]*Wkrpk[5][0]));
        AiOiWi[6][0] = (Atk[5][0]+((u[4]*Wirk[6][2])-(u[5]*Wirk[6][1])));
        AiOiWi[6][1] = (Atk[5][1]+((u[5]*Wirk[6][0])-(u[3]*Wirk[6][2])));
        AiOiWi[6][2] = (Atk[5][2]+((u[3]*Wirk[6][1])-(u[4]*Wirk[6][0])));
        Atk[6][0] = (((AiOiWi[6][2]*Cik[6][2][0])+((AiOiWi[6][0]*Cik[6][0][0])+(
          AiOiWi[6][1]*Cik[6][1][0])))+(((Otk[6][2]*rk[1][1])-(Otk[6][1]*
          rk[1][2]))+((wk[6][1]*Wkrpk[6][2])-(wk[6][2]*Wkrpk[6][1]))));
        Atk[6][1] = (((AiOiWi[6][2]*Cik[6][2][1])+((AiOiWi[6][0]*Cik[6][0][1])+(
          AiOiWi[6][1]*Cik[6][1][1])))+(((Otk[6][0]*rk[1][2])-(Otk[6][2]*
          rk[1][0]))+((wk[6][2]*Wkrpk[6][0])-(wk[6][0]*Wkrpk[6][2]))));
        Atk[6][2] = (((AiOiWi[6][2]*Cik[6][2][2])+((AiOiWi[6][0]*Cik[6][0][2])+(
          AiOiWi[6][1]*Cik[6][1][2])))+(((Otk[6][1]*rk[1][0])-(Otk[6][0]*
          rk[1][1]))+((wk[6][0]*Wkrpk[6][1])-(wk[6][1]*Wkrpk[6][0]))));
        AiOiWi[7][0] = (Atk[6][0]+(((Otk[6][1]*ri[2][2])-(Otk[6][2]*ri[2][1]))+(
          (Wirk[7][2]*wk[6][1])-(Wirk[7][1]*wk[6][2]))));
        AiOiWi[7][1] = (Atk[6][1]+(((Otk[6][2]*ri[2][0])-(Otk[6][0]*ri[2][2]))+(
          (Wirk[7][0]*wk[6][2])-(Wirk[7][2]*wk[6][0]))));
        AiOiWi[7][2] = (Atk[6][2]+(((Otk[6][0]*ri[2][1])-(Otk[6][1]*ri[2][0]))+(
          (Wirk[7][1]*wk[6][0])-(Wirk[7][0]*wk[6][1]))));
        Atk[7][0] = (((AiOiWi[7][2]*Cik[7][2][0])+((AiOiWi[7][0]*Cik[7][0][0])+(
          AiOiWi[7][1]*Cik[7][1][0])))+(((Otk[7][2]*rk[2][1])-(Otk[7][1]*
          rk[2][2]))+((wk[7][1]*Wkrpk[7][2])-(wk[7][2]*Wkrpk[7][1]))));
        Atk[7][1] = (((AiOiWi[7][2]*Cik[7][2][1])+((AiOiWi[7][0]*Cik[7][0][1])+(
          AiOiWi[7][1]*Cik[7][1][1])))+(((Otk[7][0]*rk[2][2])-(Otk[7][2]*
          rk[2][0]))+((wk[7][2]*Wkrpk[7][0])-(wk[7][0]*Wkrpk[7][2]))));
        Atk[7][2] = (((AiOiWi[7][2]*Cik[7][2][2])+((AiOiWi[7][0]*Cik[7][0][2])+(
          AiOiWi[7][1]*Cik[7][1][2])))+(((Otk[7][1]*rk[2][0])-(Otk[7][0]*
          rk[2][1]))+((wk[7][0]*Wkrpk[7][1])-(wk[7][1]*Wkrpk[7][0]))));
        AiOiWi[8][0] = (Atk[7][0]+(((Otk[7][1]*ri[3][2])-(Otk[7][2]*ri[3][1]))+(
          (Wirk[8][2]*wk[7][1])-(Wirk[8][1]*wk[7][2]))));
        AiOiWi[8][1] = (Atk[7][1]+(((Otk[7][2]*ri[3][0])-(Otk[7][0]*ri[3][2]))+(
          (Wirk[8][0]*wk[7][2])-(Wirk[8][2]*wk[7][0]))));
        AiOiWi[8][2] = (Atk[7][2]+(((Otk[7][0]*ri[3][1])-(Otk[7][1]*ri[3][0]))+(
          (Wirk[8][1]*wk[7][0])-(Wirk[8][0]*wk[7][1]))));
        Atk[8][0] = (((AiOiWi[8][2]*Cik[8][2][0])+((AiOiWi[8][0]*Cik[8][0][0])+(
          AiOiWi[8][1]*Cik[8][1][0])))+(((Otk[8][2]*rk[3][1])-(Otk[8][1]*
          rk[3][2]))+((wk[8][1]*Wkrpk[8][2])-(wk[8][2]*Wkrpk[8][1]))));
        Atk[8][1] = (((AiOiWi[8][2]*Cik[8][2][1])+((AiOiWi[8][0]*Cik[8][0][1])+(
          AiOiWi[8][1]*Cik[8][1][1])))+(((Otk[8][0]*rk[3][2])-(Otk[8][2]*
          rk[3][0]))+((wk[8][2]*Wkrpk[8][0])-(wk[8][0]*Wkrpk[8][2]))));
        Atk[8][2] = (((AiOiWi[8][2]*Cik[8][2][2])+((AiOiWi[8][0]*Cik[8][0][2])+(
          AiOiWi[8][1]*Cik[8][1][2])))+(((Otk[8][1]*rk[3][0])-(Otk[8][0]*
          rk[3][1]))+((wk[8][0]*Wkrpk[8][1])-(wk[8][1]*Wkrpk[8][0]))));
        AiOiWi[9][0] = (Atk[5][0]+((u[4]*Wirk[9][2])-(u[5]*Wirk[9][1])));
        AiOiWi[9][1] = (Atk[5][1]+((u[5]*Wirk[9][0])-(u[3]*Wirk[9][2])));
        AiOiWi[9][2] = (Atk[5][2]+((u[3]*Wirk[9][1])-(u[4]*Wirk[9][0])));
        Atk[9][0] = (((AiOiWi[9][2]*Cik[9][2][0])+((AiOiWi[9][0]*Cik[9][0][0])+(
          AiOiWi[9][1]*Cik[9][1][0])))+(((Otk[9][2]*rk[4][1])-(Otk[9][1]*
          rk[4][2]))+((wk[9][1]*Wkrpk[9][2])-(wk[9][2]*Wkrpk[9][1]))));
        Atk[9][1] = (((AiOiWi[9][2]*Cik[9][2][1])+((AiOiWi[9][0]*Cik[9][0][1])+(
          AiOiWi[9][1]*Cik[9][1][1])))+(((Otk[9][0]*rk[4][2])-(Otk[9][2]*
          rk[4][0]))+((wk[9][2]*Wkrpk[9][0])-(wk[9][0]*Wkrpk[9][2]))));
        Atk[9][2] = (((AiOiWi[9][2]*Cik[9][2][2])+((AiOiWi[9][0]*Cik[9][0][2])+(
          AiOiWi[9][1]*Cik[9][1][2])))+(((Otk[9][1]*rk[4][0])-(Otk[9][0]*
          rk[4][1]))+((wk[9][0]*Wkrpk[9][1])-(wk[9][1]*Wkrpk[9][0]))));
        AiOiWi[10][0] = (Atk[9][0]+(((Otk[9][1]*ri[5][2])-(Otk[9][2]*ri[5][1]))+
          ((Wirk[10][2]*wk[9][1])-(Wirk[10][1]*wk[9][2]))));
        AiOiWi[10][1] = (Atk[9][1]+(((Otk[9][2]*ri[5][0])-(Otk[9][0]*ri[5][2]))+
          ((Wirk[10][0]*wk[9][2])-(Wirk[10][2]*wk[9][0]))));
        AiOiWi[10][2] = (Atk[9][2]+(((Otk[9][0]*ri[5][1])-(Otk[9][1]*ri[5][0]))+
          ((Wirk[10][1]*wk[9][0])-(Wirk[10][0]*wk[9][1]))));
        Atk[10][0] = (((AiOiWi[10][2]*Cik[10][2][0])+((AiOiWi[10][0]*
          Cik[10][0][0])+(AiOiWi[10][1]*Cik[10][1][0])))+(((Otk[10][2]*rk[5][1])
          -(Otk[10][1]*rk[5][2]))+((wk[10][1]*Wkrpk[10][2])-(wk[10][2]*
          Wkrpk[10][1]))));
        Atk[10][1] = (((AiOiWi[10][2]*Cik[10][2][1])+((AiOiWi[10][0]*
          Cik[10][0][1])+(AiOiWi[10][1]*Cik[10][1][1])))+(((Otk[10][0]*rk[5][2])
          -(Otk[10][2]*rk[5][0]))+((wk[10][2]*Wkrpk[10][0])-(wk[10][0]*
          Wkrpk[10][2]))));
        Atk[10][2] = (((AiOiWi[10][2]*Cik[10][2][2])+((AiOiWi[10][0]*
          Cik[10][0][2])+(AiOiWi[10][1]*Cik[10][1][2])))+(((Otk[10][1]*rk[5][0])
          -(Otk[10][0]*rk[5][1]))+((wk[10][0]*Wkrpk[10][1])-(wk[10][1]*
          Wkrpk[10][0]))));
        AiOiWi[11][0] = (Atk[10][0]+(((Otk[10][1]*ri[6][2])-(Otk[10][2]*ri[6][1]
          ))+((Wirk[11][2]*wk[10][1])-(Wirk[11][1]*wk[10][2]))));
        AiOiWi[11][1] = (Atk[10][1]+(((Otk[10][2]*ri[6][0])-(Otk[10][0]*ri[6][2]
          ))+((Wirk[11][0]*wk[10][2])-(Wirk[11][2]*wk[10][0]))));
        AiOiWi[11][2] = (Atk[10][2]+(((Otk[10][0]*ri[6][1])-(Otk[10][1]*ri[6][0]
          ))+((Wirk[11][1]*wk[10][0])-(Wirk[11][0]*wk[10][1]))));
        Atk[11][0] = (((AiOiWi[11][2]*Cik[11][2][0])+((AiOiWi[11][0]*
          Cik[11][0][0])+(AiOiWi[11][1]*Cik[11][1][0])))+(((Otk[11][2]*rk[6][1])
          -(Otk[11][1]*rk[6][2]))+((wk[11][1]*Wkrpk[11][2])-(wk[11][2]*
          Wkrpk[11][1]))));
        Atk[11][1] = (((AiOiWi[11][2]*Cik[11][2][1])+((AiOiWi[11][0]*
          Cik[11][0][1])+(AiOiWi[11][1]*Cik[11][1][1])))+(((Otk[11][0]*rk[6][2])
          -(Otk[11][2]*rk[6][0]))+((wk[11][2]*Wkrpk[11][0])-(wk[11][0]*
          Wkrpk[11][2]))));
        Atk[11][2] = (((AiOiWi[11][2]*Cik[11][2][2])+((AiOiWi[11][0]*
          Cik[11][0][2])+(AiOiWi[11][1]*Cik[11][1][2])))+(((Otk[11][1]*rk[6][0])
          -(Otk[11][0]*rk[6][1]))+((wk[11][0]*Wkrpk[11][1])-(wk[11][1]*
          Wkrpk[11][0]))));
        AiOiWi[12][0] = (Atk[5][0]+((u[4]*Wirk[12][2])-(u[5]*Wirk[12][1])));
        AiOiWi[12][1] = (Atk[5][1]+((u[5]*Wirk[12][0])-(u[3]*Wirk[12][2])));
        AiOiWi[12][2] = (Atk[5][2]+((u[3]*Wirk[12][1])-(u[4]*Wirk[12][0])));
        Atk[12][0] = (((AiOiWi[12][2]*Cik[12][2][0])+((AiOiWi[12][0]*
          Cik[12][0][0])+(AiOiWi[12][1]*Cik[12][1][0])))+(((Otk[12][2]*rk[7][1])
          -(Otk[12][1]*rk[7][2]))+((wk[12][1]*Wkrpk[12][2])-(wk[12][2]*
          Wkrpk[12][1]))));
        Atk[12][1] = (((AiOiWi[12][2]*Cik[12][2][1])+((AiOiWi[12][0]*
          Cik[12][0][1])+(AiOiWi[12][1]*Cik[12][1][1])))+(((Otk[12][0]*rk[7][2])
          -(Otk[12][2]*rk[7][0]))+((wk[12][2]*Wkrpk[12][0])-(wk[12][0]*
          Wkrpk[12][2]))));
        Atk[12][2] = (((AiOiWi[12][2]*Cik[12][2][2])+((AiOiWi[12][0]*
          Cik[12][0][2])+(AiOiWi[12][1]*Cik[12][1][2])))+(((Otk[12][1]*rk[7][0])
          -(Otk[12][0]*rk[7][1]))+((wk[12][0]*Wkrpk[12][1])-(wk[12][1]*
          Wkrpk[12][0]))));
        AiOiWi[13][0] = (Atk[12][0]+(((Otk[12][1]*ri[8][2])-(Otk[12][2]*ri[8][1]
          ))+((Wirk[13][2]*wk[12][1])-(Wirk[13][1]*wk[12][2]))));
        AiOiWi[13][1] = (Atk[12][1]+(((Otk[12][2]*ri[8][0])-(Otk[12][0]*ri[8][2]
          ))+((Wirk[13][0]*wk[12][2])-(Wirk[13][2]*wk[12][0]))));
        AiOiWi[13][2] = (Atk[12][2]+(((Otk[12][0]*ri[8][1])-(Otk[12][1]*ri[8][0]
          ))+((Wirk[13][1]*wk[12][0])-(Wirk[13][0]*wk[12][1]))));
        Atk[13][0] = (((AiOiWi[13][2]*Cik[13][2][0])+((AiOiWi[13][0]*
          Cik[13][0][0])+(AiOiWi[13][1]*Cik[13][1][0])))+(((Otk[13][2]*rk[8][1])
          -(Otk[13][1]*rk[8][2]))+((wk[13][1]*Wkrpk[13][2])-(wk[13][2]*
          Wkrpk[13][1]))));
        Atk[13][1] = (((AiOiWi[13][2]*Cik[13][2][1])+((AiOiWi[13][0]*
          Cik[13][0][1])+(AiOiWi[13][1]*Cik[13][1][1])))+(((Otk[13][0]*rk[8][2])
          -(Otk[13][2]*rk[8][0]))+((wk[13][2]*Wkrpk[13][0])-(wk[13][0]*
          Wkrpk[13][2]))));
        Atk[13][2] = (((AiOiWi[13][2]*Cik[13][2][2])+((AiOiWi[13][0]*
          Cik[13][0][2])+(AiOiWi[13][1]*Cik[13][1][2])))+(((Otk[13][1]*rk[8][0])
          -(Otk[13][0]*rk[8][1]))+((wk[13][0]*Wkrpk[13][1])-(wk[13][1]*
          Wkrpk[13][0]))));
        AiOiWi[14][0] = (Atk[13][0]+(((Otk[13][1]*ri[9][2])-(Otk[13][2]*ri[9][1]
          ))+((Wirk[14][2]*wk[13][1])-(Wirk[14][1]*wk[13][2]))));
        AiOiWi[14][1] = (Atk[13][1]+(((Otk[13][2]*ri[9][0])-(Otk[13][0]*ri[9][2]
          ))+((Wirk[14][0]*wk[13][2])-(Wirk[14][2]*wk[13][0]))));
        AiOiWi[14][2] = (Atk[13][2]+(((Otk[13][0]*ri[9][1])-(Otk[13][1]*ri[9][0]
          ))+((Wirk[14][1]*wk[13][0])-(Wirk[14][0]*wk[13][1]))));
        Atk[14][0] = (((AiOiWi[14][2]*Cik[14][2][0])+((AiOiWi[14][0]*
          Cik[14][0][0])+(AiOiWi[14][1]*Cik[14][1][0])))+(((Otk[14][2]*rk[9][1])
          -(Otk[14][1]*rk[9][2]))+((wk[14][1]*Wkrpk[14][2])-(wk[14][2]*
          Wkrpk[14][1]))));
        Atk[14][1] = (((AiOiWi[14][2]*Cik[14][2][1])+((AiOiWi[14][0]*
          Cik[14][0][1])+(AiOiWi[14][1]*Cik[14][1][1])))+(((Otk[14][0]*rk[9][2])
          -(Otk[14][2]*rk[9][0]))+((wk[14][2]*Wkrpk[14][0])-(wk[14][0]*
          Wkrpk[14][2]))));
        Atk[14][2] = (((AiOiWi[14][2]*Cik[14][2][2])+((AiOiWi[14][0]*
          Cik[14][0][2])+(AiOiWi[14][1]*Cik[14][1][2])))+(((Otk[14][1]*rk[9][0])
          -(Otk[14][0]*rk[9][1]))+((wk[14][0]*Wkrpk[14][1])-(wk[14][1]*
          Wkrpk[14][0]))));
        AiOiWi[15][0] = (Atk[5][0]+((u[4]*Wirk[15][2])-(u[5]*Wirk[15][1])));
        AiOiWi[15][1] = (Atk[5][1]+((u[5]*Wirk[15][0])-(u[3]*Wirk[15][2])));
        AiOiWi[15][2] = (Atk[5][2]+((u[3]*Wirk[15][1])-(u[4]*Wirk[15][0])));
        Atk[15][0] = (((AiOiWi[15][2]*Cik[15][2][0])+((AiOiWi[15][0]*
          Cik[15][0][0])+(AiOiWi[15][1]*Cik[15][1][0])))+(((Otk[15][2]*rk[10][1]
          )-(Otk[15][1]*rk[10][2]))+((wk[15][1]*Wkrpk[15][2])-(wk[15][2]*
          Wkrpk[15][1]))));
        Atk[15][1] = (((AiOiWi[15][2]*Cik[15][2][1])+((AiOiWi[15][0]*
          Cik[15][0][1])+(AiOiWi[15][1]*Cik[15][1][1])))+(((Otk[15][0]*rk[10][2]
          )-(Otk[15][2]*rk[10][0]))+((wk[15][2]*Wkrpk[15][0])-(wk[15][0]*
          Wkrpk[15][2]))));
        Atk[15][2] = (((AiOiWi[15][2]*Cik[15][2][2])+((AiOiWi[15][0]*
          Cik[15][0][2])+(AiOiWi[15][1]*Cik[15][1][2])))+(((Otk[15][1]*rk[10][0]
          )-(Otk[15][0]*rk[10][1]))+((wk[15][0]*Wkrpk[15][1])-(wk[15][1]*
          Wkrpk[15][0]))));
        AiOiWi[16][0] = (Atk[15][0]+(((Otk[15][1]*ri[11][2])-(Otk[15][2]*
          ri[11][1]))+((Wirk[16][2]*wk[15][1])-(Wirk[16][1]*wk[15][2]))));
        AiOiWi[16][1] = (Atk[15][1]+(((Otk[15][2]*ri[11][0])-(Otk[15][0]*
          ri[11][2]))+((Wirk[16][0]*wk[15][2])-(Wirk[16][2]*wk[15][0]))));
        AiOiWi[16][2] = (Atk[15][2]+(((Otk[15][0]*ri[11][1])-(Otk[15][1]*
          ri[11][0]))+((Wirk[16][1]*wk[15][0])-(Wirk[16][0]*wk[15][1]))));
        Atk[16][0] = (((AiOiWi[16][2]*Cik[16][2][0])+((AiOiWi[16][0]*
          Cik[16][0][0])+(AiOiWi[16][1]*Cik[16][1][0])))+(((Otk[16][2]*rk[11][1]
          )-(Otk[16][1]*rk[11][2]))+((wk[16][1]*Wkrpk[16][2])-(wk[16][2]*
          Wkrpk[16][1]))));
        Atk[16][1] = (((AiOiWi[16][2]*Cik[16][2][1])+((AiOiWi[16][0]*
          Cik[16][0][1])+(AiOiWi[16][1]*Cik[16][1][1])))+(((Otk[16][0]*rk[11][2]
          )-(Otk[16][2]*rk[11][0]))+((wk[16][2]*Wkrpk[16][0])-(wk[16][0]*
          Wkrpk[16][2]))));
        Atk[16][2] = (((AiOiWi[16][2]*Cik[16][2][2])+((AiOiWi[16][0]*
          Cik[16][0][2])+(AiOiWi[16][1]*Cik[16][1][2])))+(((Otk[16][1]*rk[11][0]
          )-(Otk[16][0]*rk[11][1]))+((wk[16][0]*Wkrpk[16][1])-(wk[16][1]*
          Wkrpk[16][0]))));
        AiOiWi[17][0] = (Atk[16][0]+(((Otk[16][1]*ri[12][2])-(Otk[16][2]*
          ri[12][1]))+((Wirk[17][2]*wk[16][1])-(Wirk[17][1]*wk[16][2]))));
        AiOiWi[17][1] = (Atk[16][1]+(((Otk[16][2]*ri[12][0])-(Otk[16][0]*
          ri[12][2]))+((Wirk[17][0]*wk[16][2])-(Wirk[17][2]*wk[16][0]))));
        AiOiWi[17][2] = (Atk[16][2]+(((Otk[16][0]*ri[12][1])-(Otk[16][1]*
          ri[12][0]))+((Wirk[17][1]*wk[16][0])-(Wirk[17][0]*wk[16][1]))));
        Atk[17][0] = (((AiOiWi[17][2]*Cik[17][2][0])+((AiOiWi[17][0]*
          Cik[17][0][0])+(AiOiWi[17][1]*Cik[17][1][0])))+(((Otk[17][2]*rk[12][1]
          )-(Otk[17][1]*rk[12][2]))+((wk[17][1]*Wkrpk[17][2])-(wk[17][2]*
          Wkrpk[17][1]))));
        Atk[17][1] = (((AiOiWi[17][2]*Cik[17][2][1])+((AiOiWi[17][0]*
          Cik[17][0][1])+(AiOiWi[17][1]*Cik[17][1][1])))+(((Otk[17][0]*rk[12][2]
          )-(Otk[17][2]*rk[12][0]))+((wk[17][2]*Wkrpk[17][0])-(wk[17][0]*
          Wkrpk[17][2]))));
        Atk[17][2] = (((AiOiWi[17][2]*Cik[17][2][2])+((AiOiWi[17][0]*
          Cik[17][0][2])+(AiOiWi[17][1]*Cik[17][1][2])))+(((Otk[17][1]*rk[12][0]
          )-(Otk[17][0]*rk[12][1]))+((wk[17][0]*Wkrpk[17][1])-(wk[17][1]*
          Wkrpk[17][0]))));
        inerflg = 1;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  447 adds/subtracts/negates
                    522 multiplies
                      0 divides
                    111 assignments
*/
}

void sddofs0(void)
{

/*
Compute effect of all applied loads
*/
    if (fs0flg == 0) {
        sddoltau();
        sddoiner();
/*
Compute Fstar (forces)
*/
        Fstar[5][0] = ((mk[0]*(Atk[5][0]-gk[3][0]))-ufk[0][0]);
        Fstar[5][1] = ((mk[0]*(Atk[5][1]-gk[3][1]))-ufk[0][1]);
        Fstar[5][2] = ((mk[0]*(Atk[5][2]-gk[3][2]))-ufk[0][2]);
        Fstar[6][0] = ((mk[1]*(Atk[6][0]-gk[6][0]))-ufk[1][0]);
        Fstar[6][1] = ((mk[1]*(Atk[6][1]-gk[6][1]))-ufk[1][1]);
        Fstar[6][2] = ((mk[1]*(Atk[6][2]-gk[6][2]))-ufk[1][2]);
        Fstar[7][0] = ((mk[2]*(Atk[7][0]-gk[7][0]))-ufk[2][0]);
        Fstar[7][1] = ((mk[2]*(Atk[7][1]-gk[7][1]))-ufk[2][1]);
        Fstar[7][2] = ((mk[2]*(Atk[7][2]-gk[7][2]))-ufk[2][2]);
        Fstar[8][0] = ((mk[3]*(Atk[8][0]-gk[8][0]))-ufk[3][0]);
        Fstar[8][1] = ((mk[3]*(Atk[8][1]-gk[8][1]))-ufk[3][1]);
        Fstar[8][2] = ((mk[3]*(Atk[8][2]-gk[8][2]))-ufk[3][2]);
        Fstar[9][0] = ((mk[4]*(Atk[9][0]-gk[9][0]))-ufk[4][0]);
        Fstar[9][1] = ((mk[4]*(Atk[9][1]-gk[9][1]))-ufk[4][1]);
        Fstar[9][2] = ((mk[4]*(Atk[9][2]-gk[9][2]))-ufk[4][2]);
        Fstar[10][0] = ((mk[5]*(Atk[10][0]-gk[10][0]))-ufk[5][0]);
        Fstar[10][1] = ((mk[5]*(Atk[10][1]-gk[10][1]))-ufk[5][1]);
        Fstar[10][2] = ((mk[5]*(Atk[10][2]-gk[10][2]))-ufk[5][2]);
        Fstar[11][0] = ((mk[6]*(Atk[11][0]-gk[11][0]))-ufk[6][0]);
        Fstar[11][1] = ((mk[6]*(Atk[11][1]-gk[11][1]))-ufk[6][1]);
        Fstar[11][2] = ((mk[6]*(Atk[11][2]-gk[11][2]))-ufk[6][2]);
        Fstar[12][0] = ((mk[7]*(Atk[12][0]-gk[12][0]))-ufk[7][0]);
        Fstar[12][1] = ((mk[7]*(Atk[12][1]-gk[12][1]))-ufk[7][1]);
        Fstar[12][2] = ((mk[7]*(Atk[12][2]-gk[12][2]))-ufk[7][2]);
        Fstar[13][0] = ((mk[8]*(Atk[13][0]-gk[13][0]))-ufk[8][0]);
        Fstar[13][1] = ((mk[8]*(Atk[13][1]-gk[13][1]))-ufk[8][1]);
        Fstar[13][2] = ((mk[8]*(Atk[13][2]-gk[13][2]))-ufk[8][2]);
        Fstar[14][0] = ((mk[9]*(Atk[14][0]-gk[14][0]))-ufk[9][0]);
        Fstar[14][1] = ((mk[9]*(Atk[14][1]-gk[14][1]))-ufk[9][1]);
        Fstar[14][2] = ((mk[9]*(Atk[14][2]-gk[14][2]))-ufk[9][2]);
        Fstar[15][0] = ((mk[10]*(Atk[15][0]-gk[15][0]))-ufk[10][0]);
        Fstar[15][1] = ((mk[10]*(Atk[15][1]-gk[15][1]))-ufk[10][1]);
        Fstar[15][2] = ((mk[10]*(Atk[15][2]-gk[15][2]))-ufk[10][2]);
        Fstar[16][0] = ((mk[11]*(Atk[16][0]-gk[16][0]))-ufk[11][0]);
        Fstar[16][1] = ((mk[11]*(Atk[16][1]-gk[16][1]))-ufk[11][1]);
        Fstar[16][2] = ((mk[11]*(Atk[16][2]-gk[16][2]))-ufk[11][2]);
        Fstar[17][0] = ((mk[12]*(Atk[17][0]-gk[17][0]))-ufk[12][0]);
        Fstar[17][1] = ((mk[12]*(Atk[17][1]-gk[17][1]))-ufk[12][1]);
        Fstar[17][2] = ((mk[12]*(Atk[17][2]-gk[17][2]))-ufk[12][2]);
/*
Compute Tstar (torques)
*/
        Tstar[5][0] = (WkIkWk[5][0]-utk[0][0]);
        Tstar[5][1] = (WkIkWk[5][1]-utk[0][1]);
        Tstar[5][2] = (WkIkWk[5][2]-utk[0][2]);
        Tstar[6][0] = ((WkIkWk[6][0]+((ik[1][0][2]*Otk[6][2])+((ik[1][0][0]*
          Otk[6][0])+(ik[1][0][1]*Otk[6][1]))))-utk[1][0]);
        Tstar[6][1] = ((WkIkWk[6][1]+((ik[1][1][2]*Otk[6][2])+((ik[1][1][0]*
          Otk[6][0])+(ik[1][1][1]*Otk[6][1]))))-utk[1][1]);
        Tstar[6][2] = ((WkIkWk[6][2]+((ik[1][2][2]*Otk[6][2])+((ik[1][2][0]*
          Otk[6][0])+(ik[1][2][1]*Otk[6][1]))))-utk[1][2]);
        Tstar[7][0] = ((WkIkWk[7][0]+((ik[2][0][2]*Otk[7][2])+((ik[2][0][0]*
          Otk[7][0])+(ik[2][0][1]*Otk[7][1]))))-utk[2][0]);
        Tstar[7][1] = ((WkIkWk[7][1]+((ik[2][1][2]*Otk[7][2])+((ik[2][1][0]*
          Otk[7][0])+(ik[2][1][1]*Otk[7][1]))))-utk[2][1]);
        Tstar[7][2] = ((WkIkWk[7][2]+((ik[2][2][2]*Otk[7][2])+((ik[2][2][0]*
          Otk[7][0])+(ik[2][2][1]*Otk[7][1]))))-utk[2][2]);
        Tstar[8][0] = ((WkIkWk[8][0]+((ik[3][0][2]*Otk[8][2])+((ik[3][0][0]*
          Otk[8][0])+(ik[3][0][1]*Otk[8][1]))))-utk[3][0]);
        Tstar[8][1] = ((WkIkWk[8][1]+((ik[3][1][2]*Otk[8][2])+((ik[3][1][0]*
          Otk[8][0])+(ik[3][1][1]*Otk[8][1]))))-utk[3][1]);
        Tstar[8][2] = ((WkIkWk[8][2]+((ik[3][2][2]*Otk[8][2])+((ik[3][2][0]*
          Otk[8][0])+(ik[3][2][1]*Otk[8][1]))))-utk[3][2]);
        Tstar[9][0] = ((WkIkWk[9][0]+((ik[4][0][2]*Otk[9][2])+((ik[4][0][0]*
          Otk[9][0])+(ik[4][0][1]*Otk[9][1]))))-utk[4][0]);
        Tstar[9][1] = ((WkIkWk[9][1]+((ik[4][1][2]*Otk[9][2])+((ik[4][1][0]*
          Otk[9][0])+(ik[4][1][1]*Otk[9][1]))))-utk[4][1]);
        Tstar[9][2] = ((WkIkWk[9][2]+((ik[4][2][2]*Otk[9][2])+((ik[4][2][0]*
          Otk[9][0])+(ik[4][2][1]*Otk[9][1]))))-utk[4][2]);
        Tstar[10][0] = ((WkIkWk[10][0]+((ik[5][0][2]*Otk[10][2])+((ik[5][0][0]*
          Otk[10][0])+(ik[5][0][1]*Otk[10][1]))))-utk[5][0]);
        Tstar[10][1] = ((WkIkWk[10][1]+((ik[5][1][2]*Otk[10][2])+((ik[5][1][0]*
          Otk[10][0])+(ik[5][1][1]*Otk[10][1]))))-utk[5][1]);
        Tstar[10][2] = ((WkIkWk[10][2]+((ik[5][2][2]*Otk[10][2])+((ik[5][2][0]*
          Otk[10][0])+(ik[5][2][1]*Otk[10][1]))))-utk[5][2]);
        Tstar[11][0] = ((WkIkWk[11][0]+((ik[6][0][2]*Otk[11][2])+((ik[6][0][0]*
          Otk[11][0])+(ik[6][0][1]*Otk[11][1]))))-utk[6][0]);
        Tstar[11][1] = ((WkIkWk[11][1]+((ik[6][1][2]*Otk[11][2])+((ik[6][1][0]*
          Otk[11][0])+(ik[6][1][1]*Otk[11][1]))))-utk[6][1]);
        Tstar[11][2] = ((WkIkWk[11][2]+((ik[6][2][2]*Otk[11][2])+((ik[6][2][0]*
          Otk[11][0])+(ik[6][2][1]*Otk[11][1]))))-utk[6][2]);
        Tstar[12][0] = ((WkIkWk[12][0]+((ik[7][0][2]*Otk[12][2])+((ik[7][0][0]*
          Otk[12][0])+(ik[7][0][1]*Otk[12][1]))))-utk[7][0]);
        Tstar[12][1] = ((WkIkWk[12][1]+((ik[7][1][2]*Otk[12][2])+((ik[7][1][0]*
          Otk[12][0])+(ik[7][1][1]*Otk[12][1]))))-utk[7][1]);
        Tstar[12][2] = ((WkIkWk[12][2]+((ik[7][2][2]*Otk[12][2])+((ik[7][2][0]*
          Otk[12][0])+(ik[7][2][1]*Otk[12][1]))))-utk[7][2]);
        Tstar[13][0] = ((WkIkWk[13][0]+((ik[8][0][2]*Otk[13][2])+((ik[8][0][0]*
          Otk[13][0])+(ik[8][0][1]*Otk[13][1]))))-utk[8][0]);
        Tstar[13][1] = ((WkIkWk[13][1]+((ik[8][1][2]*Otk[13][2])+((ik[8][1][0]*
          Otk[13][0])+(ik[8][1][1]*Otk[13][1]))))-utk[8][1]);
        Tstar[13][2] = ((WkIkWk[13][2]+((ik[8][2][2]*Otk[13][2])+((ik[8][2][0]*
          Otk[13][0])+(ik[8][2][1]*Otk[13][1]))))-utk[8][2]);
        Tstar[14][0] = ((WkIkWk[14][0]+((ik[9][0][2]*Otk[14][2])+((ik[9][0][0]*
          Otk[14][0])+(ik[9][0][1]*Otk[14][1]))))-utk[9][0]);
        Tstar[14][1] = ((WkIkWk[14][1]+((ik[9][1][2]*Otk[14][2])+((ik[9][1][0]*
          Otk[14][0])+(ik[9][1][1]*Otk[14][1]))))-utk[9][1]);
        Tstar[14][2] = ((WkIkWk[14][2]+((ik[9][2][2]*Otk[14][2])+((ik[9][2][0]*
          Otk[14][0])+(ik[9][2][1]*Otk[14][1]))))-utk[9][2]);
        Tstar[15][0] = ((WkIkWk[15][0]+((ik[10][0][2]*Otk[15][2])+((ik[10][0][0]
          *Otk[15][0])+(ik[10][0][1]*Otk[15][1]))))-utk[10][0]);
        Tstar[15][1] = ((WkIkWk[15][1]+((ik[10][1][2]*Otk[15][2])+((ik[10][1][0]
          *Otk[15][0])+(ik[10][1][1]*Otk[15][1]))))-utk[10][1]);
        Tstar[15][2] = ((WkIkWk[15][2]+((ik[10][2][2]*Otk[15][2])+((ik[10][2][0]
          *Otk[15][0])+(ik[10][2][1]*Otk[15][1]))))-utk[10][2]);
        Tstar[16][0] = ((WkIkWk[16][0]+((ik[11][0][2]*Otk[16][2])+((ik[11][0][0]
          *Otk[16][0])+(ik[11][0][1]*Otk[16][1]))))-utk[11][0]);
        Tstar[16][1] = ((WkIkWk[16][1]+((ik[11][1][2]*Otk[16][2])+((ik[11][1][0]
          *Otk[16][0])+(ik[11][1][1]*Otk[16][1]))))-utk[11][1]);
        Tstar[16][2] = ((WkIkWk[16][2]+((ik[11][2][2]*Otk[16][2])+((ik[11][2][0]
          *Otk[16][0])+(ik[11][2][1]*Otk[16][1]))))-utk[11][2]);
        Tstar[17][0] = ((WkIkWk[17][0]+((ik[12][0][2]*Otk[17][2])+((ik[12][0][0]
          *Otk[17][0])+(ik[12][0][1]*Otk[17][1]))))-utk[12][0]);
        Tstar[17][1] = ((WkIkWk[17][1]+((ik[12][1][2]*Otk[17][2])+((ik[12][1][0]
          *Otk[17][0])+(ik[12][1][1]*Otk[17][1]))))-utk[12][1]);
        Tstar[17][2] = ((WkIkWk[17][2]+((ik[12][2][2]*Otk[17][2])+((ik[12][2][0]
          *Otk[17][0])+(ik[12][2][1]*Otk[17][1]))))-utk[12][2]);
/*
Compute fs0 (RHS ignoring constraints)
*/
        sddovpk();
        temp[0] = (((Fstar[8][2]*Vpk[0][8][2])+((Fstar[8][0]*Vpk[0][8][0])+(
          Fstar[8][1]*Vpk[0][8][1])))+(((Fstar[7][2]*Vpk[0][7][2])+((Fstar[7][0]
          *Vpk[0][7][0])+(Fstar[7][1]*Vpk[0][7][1])))+(((Fstar[5][2]*
          Vpk[0][3][2])+((Fstar[5][0]*Vpk[0][3][0])+(Fstar[5][1]*Vpk[0][3][1])))
          +((Fstar[6][2]*Vpk[0][6][2])+((Fstar[6][0]*Vpk[0][6][0])+(Fstar[6][1]*
          Vpk[0][6][1]))))));
        temp[1] = (((Fstar[12][2]*Vpk[0][12][2])+((Fstar[12][0]*Vpk[0][12][0])+(
          Fstar[12][1]*Vpk[0][12][1])))+(((Fstar[11][2]*Vpk[0][11][2])+((
          Fstar[11][0]*Vpk[0][11][0])+(Fstar[11][1]*Vpk[0][11][1])))+(((
          Fstar[10][2]*Vpk[0][10][2])+((Fstar[10][0]*Vpk[0][10][0])+(
          Fstar[10][1]*Vpk[0][10][1])))+(((Fstar[9][2]*Vpk[0][9][2])+((
          Fstar[9][0]*Vpk[0][9][0])+(Fstar[9][1]*Vpk[0][9][1])))+temp[0]))));
        temp[2] = (((Fstar[16][2]*Vpk[0][16][2])+((Fstar[16][0]*Vpk[0][16][0])+(
          Fstar[16][1]*Vpk[0][16][1])))+(((Fstar[15][2]*Vpk[0][15][2])+((
          Fstar[15][0]*Vpk[0][15][0])+(Fstar[15][1]*Vpk[0][15][1])))+(((
          Fstar[14][2]*Vpk[0][14][2])+((Fstar[14][0]*Vpk[0][14][0])+(
          Fstar[14][1]*Vpk[0][14][1])))+(((Fstar[13][2]*Vpk[0][13][2])+((
          Fstar[13][0]*Vpk[0][13][0])+(Fstar[13][1]*Vpk[0][13][1])))+temp[1]))))
          ;
        fs0[0] = (utau[0]-(((Fstar[17][2]*Vpk[0][17][2])+((Fstar[17][0]*
          Vpk[0][17][0])+(Fstar[17][1]*Vpk[0][17][1])))+temp[2]));
        temp[0] = (((Fstar[8][2]*Vpk[1][8][2])+((Fstar[8][0]*Vpk[1][8][0])+(
          Fstar[8][1]*Vpk[1][8][1])))+(((Fstar[7][2]*Vpk[1][7][2])+((Fstar[7][0]
          *Vpk[1][7][0])+(Fstar[7][1]*Vpk[1][7][1])))+(((Fstar[5][2]*
          Vpk[1][3][2])+((Fstar[5][0]*Vpk[1][3][0])+(Fstar[5][1]*Vpk[1][3][1])))
          +((Fstar[6][2]*Vpk[1][6][2])+((Fstar[6][0]*Vpk[1][6][0])+(Fstar[6][1]*
          Vpk[1][6][1]))))));
        temp[1] = (((Fstar[12][2]*Vpk[1][12][2])+((Fstar[12][0]*Vpk[1][12][0])+(
          Fstar[12][1]*Vpk[1][12][1])))+(((Fstar[11][2]*Vpk[1][11][2])+((
          Fstar[11][0]*Vpk[1][11][0])+(Fstar[11][1]*Vpk[1][11][1])))+(((
          Fstar[10][2]*Vpk[1][10][2])+((Fstar[10][0]*Vpk[1][10][0])+(
          Fstar[10][1]*Vpk[1][10][1])))+(((Fstar[9][2]*Vpk[1][9][2])+((
          Fstar[9][0]*Vpk[1][9][0])+(Fstar[9][1]*Vpk[1][9][1])))+temp[0]))));
        temp[2] = (((Fstar[16][2]*Vpk[1][16][2])+((Fstar[16][0]*Vpk[1][16][0])+(
          Fstar[16][1]*Vpk[1][16][1])))+(((Fstar[15][2]*Vpk[1][15][2])+((
          Fstar[15][0]*Vpk[1][15][0])+(Fstar[15][1]*Vpk[1][15][1])))+(((
          Fstar[14][2]*Vpk[1][14][2])+((Fstar[14][0]*Vpk[1][14][0])+(
          Fstar[14][1]*Vpk[1][14][1])))+(((Fstar[13][2]*Vpk[1][13][2])+((
          Fstar[13][0]*Vpk[1][13][0])+(Fstar[13][1]*Vpk[1][13][1])))+temp[1]))))
          ;
        fs0[1] = (utau[1]-(((Fstar[17][2]*Vpk[1][17][2])+((Fstar[17][0]*
          Vpk[1][17][0])+(Fstar[17][1]*Vpk[1][17][1])))+temp[2]));
        temp[0] = (((Fstar[8][2]*Vpk[2][8][2])+((Fstar[8][0]*Vpk[2][8][0])+(
          Fstar[8][1]*Vpk[2][8][1])))+(((Fstar[7][2]*Vpk[2][7][2])+((Fstar[7][0]
          *Vpk[2][7][0])+(Fstar[7][1]*Vpk[2][7][1])))+(((Fstar[5][2]*
          Vpk[2][3][2])+((Fstar[5][0]*Vpk[2][3][0])+(Fstar[5][1]*Vpk[2][3][1])))
          +((Fstar[6][2]*Vpk[2][6][2])+((Fstar[6][0]*Vpk[2][6][0])+(Fstar[6][1]*
          Vpk[2][6][1]))))));
        temp[1] = (((Fstar[12][2]*Vpk[2][12][2])+((Fstar[12][0]*Vpk[2][12][0])+(
          Fstar[12][1]*Vpk[2][12][1])))+(((Fstar[11][2]*Vpk[2][11][2])+((
          Fstar[11][0]*Vpk[2][11][0])+(Fstar[11][1]*Vpk[2][11][1])))+(((
          Fstar[10][2]*Vpk[2][10][2])+((Fstar[10][0]*Vpk[2][10][0])+(
          Fstar[10][1]*Vpk[2][10][1])))+(((Fstar[9][2]*Vpk[2][9][2])+((
          Fstar[9][0]*Vpk[2][9][0])+(Fstar[9][1]*Vpk[2][9][1])))+temp[0]))));
        temp[2] = (((Fstar[16][2]*Vpk[2][16][2])+((Fstar[16][0]*Vpk[2][16][0])+(
          Fstar[16][1]*Vpk[2][16][1])))+(((Fstar[15][2]*Vpk[2][15][2])+((
          Fstar[15][0]*Vpk[2][15][0])+(Fstar[15][1]*Vpk[2][15][1])))+(((
          Fstar[14][2]*Vpk[2][14][2])+((Fstar[14][0]*Vpk[2][14][0])+(
          Fstar[14][1]*Vpk[2][14][1])))+(((Fstar[13][2]*Vpk[2][13][2])+((
          Fstar[13][0]*Vpk[2][13][0])+(Fstar[13][1]*Vpk[2][13][1])))+temp[1]))))
          ;
        fs0[2] = (utau[2]-(((Fstar[17][2]*Vpk[2][17][2])+((Fstar[17][0]*
          Vpk[2][17][0])+(Fstar[17][1]*Vpk[2][17][1])))+temp[2]));
        temp[0] = (((Tstar[5][0]+((Fstar[5][1]*rk[0][2])-(Fstar[5][2]*rk[0][1]))
          )+(((Cik[6][0][2]*Tstar[6][2])+((Cik[6][0][0]*Tstar[6][0])+(
          Cik[6][0][1]*Tstar[6][1])))+((Fstar[6][2]*Vpk[3][6][2])+((Fstar[6][0]*
          Vpk[3][6][0])+(Fstar[6][1]*Vpk[3][6][1])))))+(((Fstar[7][2]*
          Vpk[3][7][2])+((Fstar[7][0]*Vpk[3][7][0])+(Fstar[7][1]*Vpk[3][7][1])))
          +((Tstar[7][2]*Wpk[3][7][2])+((Tstar[7][0]*Wpk[3][7][0])+(Tstar[7][1]*
          Wpk[3][7][1])))));
        temp[1] = ((((Cik[9][0][2]*Tstar[9][2])+((Cik[9][0][0]*Tstar[9][0])+(
          Cik[9][0][1]*Tstar[9][1])))+((Fstar[9][2]*Vpk[3][9][2])+((Fstar[9][0]*
          Vpk[3][9][0])+(Fstar[9][1]*Vpk[3][9][1]))))+((((Fstar[8][2]*
          Vpk[3][8][2])+((Fstar[8][0]*Vpk[3][8][0])+(Fstar[8][1]*Vpk[3][8][1])))
          +((Tstar[8][2]*Wpk[3][8][2])+((Tstar[8][0]*Wpk[3][8][0])+(Tstar[8][1]*
          Wpk[3][8][1]))))+temp[0]));
        temp[2] = ((((Fstar[11][2]*Vpk[3][11][2])+((Fstar[11][0]*Vpk[3][11][0])+
          (Fstar[11][1]*Vpk[3][11][1])))+((Tstar[11][2]*Wpk[3][11][2])+((
          Tstar[11][0]*Wpk[3][11][0])+(Tstar[11][1]*Wpk[3][11][1]))))+((((
          Fstar[10][2]*Vpk[3][10][2])+((Fstar[10][0]*Vpk[3][10][0])+(
          Fstar[10][1]*Vpk[3][10][1])))+((Tstar[10][2]*Wpk[3][10][2])+((
          Tstar[10][0]*Wpk[3][10][0])+(Tstar[10][1]*Wpk[3][10][1]))))+temp[1]));
        temp[3] = ((((Fstar[13][2]*Vpk[3][13][2])+((Fstar[13][0]*Vpk[3][13][0])+
          (Fstar[13][1]*Vpk[3][13][1])))+((Tstar[13][2]*Wpk[3][13][2])+((
          Tstar[13][0]*Wpk[3][13][0])+(Tstar[13][1]*Wpk[3][13][1]))))+((((
          Cik[12][0][2]*Tstar[12][2])+((Cik[12][0][0]*Tstar[12][0])+(
          Cik[12][0][1]*Tstar[12][1])))+((Fstar[12][2]*Vpk[3][12][2])+((
          Fstar[12][0]*Vpk[3][12][0])+(Fstar[12][1]*Vpk[3][12][1]))))+temp[2]));
        temp[4] = ((((Cik[15][0][2]*Tstar[15][2])+((Cik[15][0][0]*Tstar[15][0])+
          (Cik[15][0][1]*Tstar[15][1])))+((Fstar[15][2]*Vpk[3][15][2])+((
          Fstar[15][0]*Vpk[3][15][0])+(Fstar[15][1]*Vpk[3][15][1]))))+((((
          Fstar[14][2]*Vpk[3][14][2])+((Fstar[14][0]*Vpk[3][14][0])+(
          Fstar[14][1]*Vpk[3][14][1])))+((Tstar[14][2]*Wpk[3][14][2])+((
          Tstar[14][0]*Wpk[3][14][0])+(Tstar[14][1]*Wpk[3][14][1]))))+temp[3]));
        fs0[3] = (utau[3]-((((Fstar[17][2]*Vpk[3][17][2])+((Fstar[17][0]*
          Vpk[3][17][0])+(Fstar[17][1]*Vpk[3][17][1])))+((Tstar[17][2]*
          Wpk[3][17][2])+((Tstar[17][0]*Wpk[3][17][0])+(Tstar[17][1]*
          Wpk[3][17][1]))))+((((Fstar[16][2]*Vpk[3][16][2])+((Fstar[16][0]*
          Vpk[3][16][0])+(Fstar[16][1]*Vpk[3][16][1])))+((Tstar[16][2]*
          Wpk[3][16][2])+((Tstar[16][0]*Wpk[3][16][0])+(Tstar[16][1]*
          Wpk[3][16][1]))))+temp[4])));
        temp[0] = (((Tstar[5][1]+((Fstar[5][2]*rk[0][0])-(Fstar[5][0]*rk[0][2]))
          )+(((Cik[6][1][2]*Tstar[6][2])+((Cik[6][1][0]*Tstar[6][0])+(
          Cik[6][1][1]*Tstar[6][1])))+((Fstar[6][2]*Vpk[4][6][2])+((Fstar[6][0]*
          Vpk[4][6][0])+(Fstar[6][1]*Vpk[4][6][1])))))+(((Fstar[7][2]*
          Vpk[4][7][2])+((Fstar[7][0]*Vpk[4][7][0])+(Fstar[7][1]*Vpk[4][7][1])))
          +((Tstar[7][2]*Wpk[4][7][2])+((Tstar[7][0]*Wpk[4][7][0])+(Tstar[7][1]*
          Wpk[4][7][1])))));
        temp[1] = ((((Cik[9][1][2]*Tstar[9][2])+((Cik[9][1][0]*Tstar[9][0])+(
          Cik[9][1][1]*Tstar[9][1])))+((Fstar[9][2]*Vpk[4][9][2])+((Fstar[9][0]*
          Vpk[4][9][0])+(Fstar[9][1]*Vpk[4][9][1]))))+((((Fstar[8][2]*
          Vpk[4][8][2])+((Fstar[8][0]*Vpk[4][8][0])+(Fstar[8][1]*Vpk[4][8][1])))
          +((Tstar[8][2]*Wpk[4][8][2])+((Tstar[8][0]*Wpk[4][8][0])+(Tstar[8][1]*
          Wpk[4][8][1]))))+temp[0]));
        temp[2] = ((((Fstar[11][2]*Vpk[4][11][2])+((Fstar[11][0]*Vpk[4][11][0])+
          (Fstar[11][1]*Vpk[4][11][1])))+((Tstar[11][2]*Wpk[4][11][2])+((
          Tstar[11][0]*Wpk[4][11][0])+(Tstar[11][1]*Wpk[4][11][1]))))+((((
          Fstar[10][2]*Vpk[4][10][2])+((Fstar[10][0]*Vpk[4][10][0])+(
          Fstar[10][1]*Vpk[4][10][1])))+((Tstar[10][2]*Wpk[4][10][2])+((
          Tstar[10][0]*Wpk[4][10][0])+(Tstar[10][1]*Wpk[4][10][1]))))+temp[1]));
        temp[3] = ((((Fstar[13][2]*Vpk[4][13][2])+((Fstar[13][0]*Vpk[4][13][0])+
          (Fstar[13][1]*Vpk[4][13][1])))+((Tstar[13][2]*Wpk[4][13][2])+((
          Tstar[13][0]*Wpk[4][13][0])+(Tstar[13][1]*Wpk[4][13][1]))))+((((
          Cik[12][1][2]*Tstar[12][2])+((Cik[12][1][0]*Tstar[12][0])+(
          Cik[12][1][1]*Tstar[12][1])))+((Fstar[12][2]*Vpk[4][12][2])+((
          Fstar[12][0]*Vpk[4][12][0])+(Fstar[12][1]*Vpk[4][12][1]))))+temp[2]));
        temp[4] = ((((Cik[15][1][2]*Tstar[15][2])+((Cik[15][1][0]*Tstar[15][0])+
          (Cik[15][1][1]*Tstar[15][1])))+((Fstar[15][2]*Vpk[4][15][2])+((
          Fstar[15][0]*Vpk[4][15][0])+(Fstar[15][1]*Vpk[4][15][1]))))+((((
          Fstar[14][2]*Vpk[4][14][2])+((Fstar[14][0]*Vpk[4][14][0])+(
          Fstar[14][1]*Vpk[4][14][1])))+((Tstar[14][2]*Wpk[4][14][2])+((
          Tstar[14][0]*Wpk[4][14][0])+(Tstar[14][1]*Wpk[4][14][1]))))+temp[3]));
        fs0[4] = (utau[4]-((((Fstar[17][2]*Vpk[4][17][2])+((Fstar[17][0]*
          Vpk[4][17][0])+(Fstar[17][1]*Vpk[4][17][1])))+((Tstar[17][2]*
          Wpk[4][17][2])+((Tstar[17][0]*Wpk[4][17][0])+(Tstar[17][1]*
          Wpk[4][17][1]))))+((((Fstar[16][2]*Vpk[4][16][2])+((Fstar[16][0]*
          Vpk[4][16][0])+(Fstar[16][1]*Vpk[4][16][1])))+((Tstar[16][2]*
          Wpk[4][16][2])+((Tstar[16][0]*Wpk[4][16][0])+(Tstar[16][1]*
          Wpk[4][16][1]))))+temp[4])));
        temp[0] = (((Tstar[5][2]+((Fstar[5][0]*rk[0][1])-(Fstar[5][1]*rk[0][0]))
          )+(((Cik[6][2][2]*Tstar[6][2])+((Cik[6][2][0]*Tstar[6][0])+(
          Cik[6][2][1]*Tstar[6][1])))+((Fstar[6][2]*Vpk[5][6][2])+((Fstar[6][0]*
          Vpk[5][6][0])+(Fstar[6][1]*Vpk[5][6][1])))))+(((Fstar[7][2]*
          Vpk[5][7][2])+((Fstar[7][0]*Vpk[5][7][0])+(Fstar[7][1]*Vpk[5][7][1])))
          +((Tstar[7][2]*Wpk[5][7][2])+((Tstar[7][0]*Wpk[5][7][0])+(Tstar[7][1]*
          Wpk[5][7][1])))));
        temp[1] = ((((Cik[9][2][2]*Tstar[9][2])+((Cik[9][2][0]*Tstar[9][0])+(
          Cik[9][2][1]*Tstar[9][1])))+((Fstar[9][2]*Vpk[5][9][2])+((Fstar[9][0]*
          Vpk[5][9][0])+(Fstar[9][1]*Vpk[5][9][1]))))+((((Fstar[8][2]*
          Vpk[5][8][2])+((Fstar[8][0]*Vpk[5][8][0])+(Fstar[8][1]*Vpk[5][8][1])))
          +((Tstar[8][2]*Wpk[5][8][2])+((Tstar[8][0]*Wpk[5][8][0])+(Tstar[8][1]*
          Wpk[5][8][1]))))+temp[0]));
        temp[2] = ((((Fstar[11][2]*Vpk[5][11][2])+((Fstar[11][0]*Vpk[5][11][0])+
          (Fstar[11][1]*Vpk[5][11][1])))+((Tstar[11][2]*Wpk[5][11][2])+((
          Tstar[11][0]*Wpk[5][11][0])+(Tstar[11][1]*Wpk[5][11][1]))))+((((
          Fstar[10][2]*Vpk[5][10][2])+((Fstar[10][0]*Vpk[5][10][0])+(
          Fstar[10][1]*Vpk[5][10][1])))+((Tstar[10][2]*Wpk[5][10][2])+((
          Tstar[10][0]*Wpk[5][10][0])+(Tstar[10][1]*Wpk[5][10][1]))))+temp[1]));
        temp[3] = ((((Fstar[13][2]*Vpk[5][13][2])+((Fstar[13][0]*Vpk[5][13][0])+
          (Fstar[13][1]*Vpk[5][13][1])))+((Tstar[13][2]*Wpk[5][13][2])+((
          Tstar[13][0]*Wpk[5][13][0])+(Tstar[13][1]*Wpk[5][13][1]))))+((((
          Cik[12][2][2]*Tstar[12][2])+((Cik[12][2][0]*Tstar[12][0])+(
          Cik[12][2][1]*Tstar[12][1])))+((Fstar[12][2]*Vpk[5][12][2])+((
          Fstar[12][0]*Vpk[5][12][0])+(Fstar[12][1]*Vpk[5][12][1]))))+temp[2]));
        temp[4] = ((((Cik[15][2][2]*Tstar[15][2])+((Cik[15][2][0]*Tstar[15][0])+
          (Cik[15][2][1]*Tstar[15][1])))+((Fstar[15][2]*Vpk[5][15][2])+((
          Fstar[15][0]*Vpk[5][15][0])+(Fstar[15][1]*Vpk[5][15][1]))))+((((
          Fstar[14][2]*Vpk[5][14][2])+((Fstar[14][0]*Vpk[5][14][0])+(
          Fstar[14][1]*Vpk[5][14][1])))+((Tstar[14][2]*Wpk[5][14][2])+((
          Tstar[14][0]*Wpk[5][14][0])+(Tstar[14][1]*Wpk[5][14][1]))))+temp[3]));
        fs0[5] = (utau[5]-((((Fstar[17][2]*Vpk[5][17][2])+((Fstar[17][0]*
          Vpk[5][17][0])+(Fstar[17][1]*Vpk[5][17][1])))+((Tstar[17][2]*
          Wpk[5][17][2])+((Tstar[17][0]*Wpk[5][17][0])+(Tstar[17][1]*
          Wpk[5][17][1]))))+((((Fstar[16][2]*Vpk[5][16][2])+((Fstar[16][0]*
          Vpk[5][16][0])+(Fstar[16][1]*Vpk[5][16][1])))+((Tstar[16][2]*
          Wpk[5][16][2])+((Tstar[16][0]*Wpk[5][16][0])+(Tstar[16][1]*
          Wpk[5][16][1]))))+temp[4])));
        temp[0] = ((((Fstar[6][2]*Vpk[6][6][2])+((Fstar[6][0]*Vpk[6][6][0])+(
          Fstar[6][1]*Vpk[6][6][1])))+((pin[6][2]*Tstar[6][2])+((pin[6][0]*
          Tstar[6][0])+(pin[6][1]*Tstar[6][1]))))+(((Fstar[7][2]*Vpk[6][7][2])+(
          (Fstar[7][0]*Vpk[6][7][0])+(Fstar[7][1]*Vpk[6][7][1])))+((Tstar[7][2]*
          Wpk[6][7][2])+((Tstar[7][0]*Wpk[6][7][0])+(Tstar[7][1]*Wpk[6][7][1])))
          ));
        fs0[6] = (utau[6]-((((Fstar[8][2]*Vpk[6][8][2])+((Fstar[8][0]*
          Vpk[6][8][0])+(Fstar[8][1]*Vpk[6][8][1])))+((Tstar[8][2]*Wpk[6][8][2])
          +((Tstar[8][0]*Wpk[6][8][0])+(Tstar[8][1]*Wpk[6][8][1]))))+temp[0]));
        fs0[7] = (utau[7]-((((Fstar[7][2]*Vpk[7][7][2])+((Fstar[7][0]*
          Vpk[7][7][0])+(Fstar[7][1]*Vpk[7][7][1])))+((pin[7][2]*Tstar[7][2])+((
          pin[7][0]*Tstar[7][0])+(pin[7][1]*Tstar[7][1]))))+(((Fstar[8][2]*
          Vpk[7][8][2])+((Fstar[8][0]*Vpk[7][8][0])+(Fstar[8][1]*Vpk[7][8][1])))
          +((Tstar[8][2]*Wpk[7][8][2])+((Tstar[8][0]*Wpk[7][8][0])+(Tstar[8][1]*
          Wpk[7][8][1]))))));
        fs0[8] = (utau[8]-(((Fstar[8][2]*Vpk[8][8][2])+((Fstar[8][0]*
          Vpk[8][8][0])+(Fstar[8][1]*Vpk[8][8][1])))+((pin[8][2]*Tstar[8][2])+((
          pin[8][0]*Tstar[8][0])+(pin[8][1]*Tstar[8][1])))));
        temp[0] = ((((Fstar[9][2]*Vpk[9][9][2])+((Fstar[9][0]*Vpk[9][9][0])+(
          Fstar[9][1]*Vpk[9][9][1])))+((pin[9][2]*Tstar[9][2])+((pin[9][0]*
          Tstar[9][0])+(pin[9][1]*Tstar[9][1]))))+(((Fstar[10][2]*Vpk[9][10][2])
          +((Fstar[10][0]*Vpk[9][10][0])+(Fstar[10][1]*Vpk[9][10][1])))+((
          Tstar[10][2]*Wpk[9][10][2])+((Tstar[10][0]*Wpk[9][10][0])+(
          Tstar[10][1]*Wpk[9][10][1])))));
        fs0[9] = (utau[9]-((((Fstar[11][2]*Vpk[9][11][2])+((Fstar[11][0]*
          Vpk[9][11][0])+(Fstar[11][1]*Vpk[9][11][1])))+((Tstar[11][2]*
          Wpk[9][11][2])+((Tstar[11][0]*Wpk[9][11][0])+(Tstar[11][1]*
          Wpk[9][11][1]))))+temp[0]));
        fs0[10] = (utau[10]-((((Fstar[10][2]*Vpk[10][10][2])+((Fstar[10][0]*
          Vpk[10][10][0])+(Fstar[10][1]*Vpk[10][10][1])))+((pin[10][2]*
          Tstar[10][2])+((pin[10][0]*Tstar[10][0])+(pin[10][1]*Tstar[10][1]))))+
          (((Fstar[11][2]*Vpk[10][11][2])+((Fstar[11][0]*Vpk[10][11][0])+(
          Fstar[11][1]*Vpk[10][11][1])))+((Tstar[11][2]*Wpk[10][11][2])+((
          Tstar[11][0]*Wpk[10][11][0])+(Tstar[11][1]*Wpk[10][11][1]))))));
        fs0[11] = (utau[11]-(((Fstar[11][2]*Vpk[11][11][2])+((Fstar[11][0]*
          Vpk[11][11][0])+(Fstar[11][1]*Vpk[11][11][1])))+((pin[11][2]*
          Tstar[11][2])+((pin[11][0]*Tstar[11][0])+(pin[11][1]*Tstar[11][1])))))
          ;
        temp[0] = ((((Fstar[12][2]*Vpk[12][12][2])+((Fstar[12][0]*Vpk[12][12][0]
          )+(Fstar[12][1]*Vpk[12][12][1])))+((pin[12][2]*Tstar[12][2])+((
          pin[12][0]*Tstar[12][0])+(pin[12][1]*Tstar[12][1]))))+(((Fstar[13][2]*
          Vpk[12][13][2])+((Fstar[13][0]*Vpk[12][13][0])+(Fstar[13][1]*
          Vpk[12][13][1])))+((Tstar[13][2]*Wpk[12][13][2])+((Tstar[13][0]*
          Wpk[12][13][0])+(Tstar[13][1]*Wpk[12][13][1])))));
        fs0[12] = (utau[12]-((((Fstar[14][2]*Vpk[12][14][2])+((Fstar[14][0]*
          Vpk[12][14][0])+(Fstar[14][1]*Vpk[12][14][1])))+((Tstar[14][2]*
          Wpk[12][14][2])+((Tstar[14][0]*Wpk[12][14][0])+(Tstar[14][1]*
          Wpk[12][14][1]))))+temp[0]));
        fs0[13] = (utau[13]-((((Fstar[13][2]*Vpk[13][13][2])+((Fstar[13][0]*
          Vpk[13][13][0])+(Fstar[13][1]*Vpk[13][13][1])))+((pin[13][2]*
          Tstar[13][2])+((pin[13][0]*Tstar[13][0])+(pin[13][1]*Tstar[13][1]))))+
          (((Fstar[14][2]*Vpk[13][14][2])+((Fstar[14][0]*Vpk[13][14][0])+(
          Fstar[14][1]*Vpk[13][14][1])))+((Tstar[14][2]*Wpk[13][14][2])+((
          Tstar[14][0]*Wpk[13][14][0])+(Tstar[14][1]*Wpk[13][14][1]))))));
        fs0[14] = (utau[14]-(((Fstar[14][2]*Vpk[14][14][2])+((Fstar[14][0]*
          Vpk[14][14][0])+(Fstar[14][1]*Vpk[14][14][1])))+((pin[14][2]*
          Tstar[14][2])+((pin[14][0]*Tstar[14][0])+(pin[14][1]*Tstar[14][1])))))
          ;
        temp[0] = ((((Fstar[15][2]*Vpk[15][15][2])+((Fstar[15][0]*Vpk[15][15][0]
          )+(Fstar[15][1]*Vpk[15][15][1])))+((pin[15][2]*Tstar[15][2])+((
          pin[15][0]*Tstar[15][0])+(pin[15][1]*Tstar[15][1]))))+(((Fstar[16][2]*
          Vpk[15][16][2])+((Fstar[16][0]*Vpk[15][16][0])+(Fstar[16][1]*
          Vpk[15][16][1])))+((Tstar[16][2]*Wpk[15][16][2])+((Tstar[16][0]*
          Wpk[15][16][0])+(Tstar[16][1]*Wpk[15][16][1])))));
        fs0[15] = (utau[15]-((((Fstar[17][2]*Vpk[15][17][2])+((Fstar[17][0]*
          Vpk[15][17][0])+(Fstar[17][1]*Vpk[15][17][1])))+((Tstar[17][2]*
          Wpk[15][17][2])+((Tstar[17][0]*Wpk[15][17][0])+(Tstar[17][1]*
          Wpk[15][17][1]))))+temp[0]));
        fs0[16] = (utau[16]-((((Fstar[16][2]*Vpk[16][16][2])+((Fstar[16][0]*
          Vpk[16][16][0])+(Fstar[16][1]*Vpk[16][16][1])))+((pin[16][2]*
          Tstar[16][2])+((pin[16][0]*Tstar[16][0])+(pin[16][1]*Tstar[16][1]))))+
          (((Fstar[17][2]*Vpk[16][17][2])+((Fstar[17][0]*Vpk[16][17][0])+(
          Fstar[17][1]*Vpk[16][17][1])))+((Tstar[17][2]*Wpk[16][17][2])+((
          Tstar[17][0]*Wpk[16][17][0])+(Tstar[17][1]*Wpk[16][17][1]))))));
        fs0[17] = (utau[17]-(((Fstar[17][2]*Vpk[17][17][2])+((Fstar[17][0]*
          Vpk[17][17][0])+(Fstar[17][1]*Vpk[17][17][1])))+((pin[17][2]*
          Tstar[17][2])+((pin[17][0]*Tstar[17][0])+(pin[17][1]*Tstar[17][1])))))
          ;
        fs0flg = 1;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  711 adds/subtracts/negates
                    630 multiplies
                      0 divides
                    124 assignments
*/
}

void sddomm(int routine)
{
    int dumroutine,errnum;
    int i;

    if (mmflg == 0) {
/*
Compute mass matrix (MM)
*/
        sddovpk();
        IkWpk[3][6][0] = ((Cik[6][0][2]*ik[1][0][2])+((Cik[6][0][0]*ik[1][0][0])
          +(Cik[6][0][1]*ik[1][0][1])));
        IkWpk[3][6][1] = ((Cik[6][0][2]*ik[1][1][2])+((Cik[6][0][0]*ik[1][1][0])
          +(Cik[6][0][1]*ik[1][1][1])));
        IkWpk[3][6][2] = ((Cik[6][0][2]*ik[1][2][2])+((Cik[6][0][0]*ik[1][2][0])
          +(Cik[6][0][1]*ik[1][2][1])));
        IkWpk[3][7][0] = ((ik[2][0][2]*Wpk[3][7][2])+((ik[2][0][0]*Wpk[3][7][0])
          +(ik[2][0][1]*Wpk[3][7][1])));
        IkWpk[3][7][1] = ((ik[2][1][2]*Wpk[3][7][2])+((ik[2][1][0]*Wpk[3][7][0])
          +(ik[2][1][1]*Wpk[3][7][1])));
        IkWpk[3][7][2] = ((ik[2][2][2]*Wpk[3][7][2])+((ik[2][2][0]*Wpk[3][7][0])
          +(ik[2][2][1]*Wpk[3][7][1])));
        IkWpk[3][8][0] = ((ik[3][0][2]*Wpk[3][8][2])+((ik[3][0][0]*Wpk[3][8][0])
          +(ik[3][0][1]*Wpk[3][8][1])));
        IkWpk[3][8][1] = ((ik[3][1][2]*Wpk[3][8][2])+((ik[3][1][0]*Wpk[3][8][0])
          +(ik[3][1][1]*Wpk[3][8][1])));
        IkWpk[3][8][2] = ((ik[3][2][2]*Wpk[3][8][2])+((ik[3][2][0]*Wpk[3][8][0])
          +(ik[3][2][1]*Wpk[3][8][1])));
        IkWpk[3][9][0] = ((Cik[9][0][2]*ik[4][0][2])+((Cik[9][0][0]*ik[4][0][0])
          +(Cik[9][0][1]*ik[4][0][1])));
        IkWpk[3][9][1] = ((Cik[9][0][2]*ik[4][1][2])+((Cik[9][0][0]*ik[4][1][0])
          +(Cik[9][0][1]*ik[4][1][1])));
        IkWpk[3][9][2] = ((Cik[9][0][2]*ik[4][2][2])+((Cik[9][0][0]*ik[4][2][0])
          +(Cik[9][0][1]*ik[4][2][1])));
        IkWpk[3][10][0] = ((ik[5][0][2]*Wpk[3][10][2])+((ik[5][0][0]*
          Wpk[3][10][0])+(ik[5][0][1]*Wpk[3][10][1])));
        IkWpk[3][10][1] = ((ik[5][1][2]*Wpk[3][10][2])+((ik[5][1][0]*
          Wpk[3][10][0])+(ik[5][1][1]*Wpk[3][10][1])));
        IkWpk[3][10][2] = ((ik[5][2][2]*Wpk[3][10][2])+((ik[5][2][0]*
          Wpk[3][10][0])+(ik[5][2][1]*Wpk[3][10][1])));
        IkWpk[3][11][0] = ((ik[6][0][2]*Wpk[3][11][2])+((ik[6][0][0]*
          Wpk[3][11][0])+(ik[6][0][1]*Wpk[3][11][1])));
        IkWpk[3][11][1] = ((ik[6][1][2]*Wpk[3][11][2])+((ik[6][1][0]*
          Wpk[3][11][0])+(ik[6][1][1]*Wpk[3][11][1])));
        IkWpk[3][11][2] = ((ik[6][2][2]*Wpk[3][11][2])+((ik[6][2][0]*
          Wpk[3][11][0])+(ik[6][2][1]*Wpk[3][11][1])));
        IkWpk[3][12][0] = ((Cik[12][0][2]*ik[7][0][2])+((Cik[12][0][0]*
          ik[7][0][0])+(Cik[12][0][1]*ik[7][0][1])));
        IkWpk[3][12][1] = ((Cik[12][0][2]*ik[7][1][2])+((Cik[12][0][0]*
          ik[7][1][0])+(Cik[12][0][1]*ik[7][1][1])));
        IkWpk[3][12][2] = ((Cik[12][0][2]*ik[7][2][2])+((Cik[12][0][0]*
          ik[7][2][0])+(Cik[12][0][1]*ik[7][2][1])));
        IkWpk[3][13][0] = ((ik[8][0][2]*Wpk[3][13][2])+((ik[8][0][0]*
          Wpk[3][13][0])+(ik[8][0][1]*Wpk[3][13][1])));
        IkWpk[3][13][1] = ((ik[8][1][2]*Wpk[3][13][2])+((ik[8][1][0]*
          Wpk[3][13][0])+(ik[8][1][1]*Wpk[3][13][1])));
        IkWpk[3][13][2] = ((ik[8][2][2]*Wpk[3][13][2])+((ik[8][2][0]*
          Wpk[3][13][0])+(ik[8][2][1]*Wpk[3][13][1])));
        IkWpk[3][14][0] = ((ik[9][0][2]*Wpk[3][14][2])+((ik[9][0][0]*
          Wpk[3][14][0])+(ik[9][0][1]*Wpk[3][14][1])));
        IkWpk[3][14][1] = ((ik[9][1][2]*Wpk[3][14][2])+((ik[9][1][0]*
          Wpk[3][14][0])+(ik[9][1][1]*Wpk[3][14][1])));
        IkWpk[3][14][2] = ((ik[9][2][2]*Wpk[3][14][2])+((ik[9][2][0]*
          Wpk[3][14][0])+(ik[9][2][1]*Wpk[3][14][1])));
        IkWpk[3][15][0] = ((Cik[15][0][2]*ik[10][0][2])+((Cik[15][0][0]*
          ik[10][0][0])+(Cik[15][0][1]*ik[10][0][1])));
        IkWpk[3][15][1] = ((Cik[15][0][2]*ik[10][1][2])+((Cik[15][0][0]*
          ik[10][1][0])+(Cik[15][0][1]*ik[10][1][1])));
        IkWpk[3][15][2] = ((Cik[15][0][2]*ik[10][2][2])+((Cik[15][0][0]*
          ik[10][2][0])+(Cik[15][0][1]*ik[10][2][1])));
        IkWpk[3][16][0] = ((ik[11][0][2]*Wpk[3][16][2])+((ik[11][0][0]*
          Wpk[3][16][0])+(ik[11][0][1]*Wpk[3][16][1])));
        IkWpk[3][16][1] = ((ik[11][1][2]*Wpk[3][16][2])+((ik[11][1][0]*
          Wpk[3][16][0])+(ik[11][1][1]*Wpk[3][16][1])));
        IkWpk[3][16][2] = ((ik[11][2][2]*Wpk[3][16][2])+((ik[11][2][0]*
          Wpk[3][16][0])+(ik[11][2][1]*Wpk[3][16][1])));
        IkWpk[3][17][0] = ((ik[12][0][2]*Wpk[3][17][2])+((ik[12][0][0]*
          Wpk[3][17][0])+(ik[12][0][1]*Wpk[3][17][1])));
        IkWpk[3][17][1] = ((ik[12][1][2]*Wpk[3][17][2])+((ik[12][1][0]*
          Wpk[3][17][0])+(ik[12][1][1]*Wpk[3][17][1])));
        IkWpk[3][17][2] = ((ik[12][2][2]*Wpk[3][17][2])+((ik[12][2][0]*
          Wpk[3][17][0])+(ik[12][2][1]*Wpk[3][17][1])));
        IkWpk[4][6][0] = ((Cik[6][1][2]*ik[1][0][2])+((Cik[6][1][0]*ik[1][0][0])
          +(Cik[6][1][1]*ik[1][0][1])));
        IkWpk[4][6][1] = ((Cik[6][1][2]*ik[1][1][2])+((Cik[6][1][0]*ik[1][1][0])
          +(Cik[6][1][1]*ik[1][1][1])));
        IkWpk[4][6][2] = ((Cik[6][1][2]*ik[1][2][2])+((Cik[6][1][0]*ik[1][2][0])
          +(Cik[6][1][1]*ik[1][2][1])));
        IkWpk[4][7][0] = ((ik[2][0][2]*Wpk[4][7][2])+((ik[2][0][0]*Wpk[4][7][0])
          +(ik[2][0][1]*Wpk[4][7][1])));
        IkWpk[4][7][1] = ((ik[2][1][2]*Wpk[4][7][2])+((ik[2][1][0]*Wpk[4][7][0])
          +(ik[2][1][1]*Wpk[4][7][1])));
        IkWpk[4][7][2] = ((ik[2][2][2]*Wpk[4][7][2])+((ik[2][2][0]*Wpk[4][7][0])
          +(ik[2][2][1]*Wpk[4][7][1])));
        IkWpk[4][8][0] = ((ik[3][0][2]*Wpk[4][8][2])+((ik[3][0][0]*Wpk[4][8][0])
          +(ik[3][0][1]*Wpk[4][8][1])));
        IkWpk[4][8][1] = ((ik[3][1][2]*Wpk[4][8][2])+((ik[3][1][0]*Wpk[4][8][0])
          +(ik[3][1][1]*Wpk[4][8][1])));
        IkWpk[4][8][2] = ((ik[3][2][2]*Wpk[4][8][2])+((ik[3][2][0]*Wpk[4][8][0])
          +(ik[3][2][1]*Wpk[4][8][1])));
        IkWpk[4][9][0] = ((Cik[9][1][2]*ik[4][0][2])+((Cik[9][1][0]*ik[4][0][0])
          +(Cik[9][1][1]*ik[4][0][1])));
        IkWpk[4][9][1] = ((Cik[9][1][2]*ik[4][1][2])+((Cik[9][1][0]*ik[4][1][0])
          +(Cik[9][1][1]*ik[4][1][1])));
        IkWpk[4][9][2] = ((Cik[9][1][2]*ik[4][2][2])+((Cik[9][1][0]*ik[4][2][0])
          +(Cik[9][1][1]*ik[4][2][1])));
        IkWpk[4][10][0] = ((ik[5][0][2]*Wpk[4][10][2])+((ik[5][0][0]*
          Wpk[4][10][0])+(ik[5][0][1]*Wpk[4][10][1])));
        IkWpk[4][10][1] = ((ik[5][1][2]*Wpk[4][10][2])+((ik[5][1][0]*
          Wpk[4][10][0])+(ik[5][1][1]*Wpk[4][10][1])));
        IkWpk[4][10][2] = ((ik[5][2][2]*Wpk[4][10][2])+((ik[5][2][0]*
          Wpk[4][10][0])+(ik[5][2][1]*Wpk[4][10][1])));
        IkWpk[4][11][0] = ((ik[6][0][2]*Wpk[4][11][2])+((ik[6][0][0]*
          Wpk[4][11][0])+(ik[6][0][1]*Wpk[4][11][1])));
        IkWpk[4][11][1] = ((ik[6][1][2]*Wpk[4][11][2])+((ik[6][1][0]*
          Wpk[4][11][0])+(ik[6][1][1]*Wpk[4][11][1])));
        IkWpk[4][11][2] = ((ik[6][2][2]*Wpk[4][11][2])+((ik[6][2][0]*
          Wpk[4][11][0])+(ik[6][2][1]*Wpk[4][11][1])));
        IkWpk[4][12][0] = ((Cik[12][1][2]*ik[7][0][2])+((Cik[12][1][0]*
          ik[7][0][0])+(Cik[12][1][1]*ik[7][0][1])));
        IkWpk[4][12][1] = ((Cik[12][1][2]*ik[7][1][2])+((Cik[12][1][0]*
          ik[7][1][0])+(Cik[12][1][1]*ik[7][1][1])));
        IkWpk[4][12][2] = ((Cik[12][1][2]*ik[7][2][2])+((Cik[12][1][0]*
          ik[7][2][0])+(Cik[12][1][1]*ik[7][2][1])));
        IkWpk[4][13][0] = ((ik[8][0][2]*Wpk[4][13][2])+((ik[8][0][0]*
          Wpk[4][13][0])+(ik[8][0][1]*Wpk[4][13][1])));
        IkWpk[4][13][1] = ((ik[8][1][2]*Wpk[4][13][2])+((ik[8][1][0]*
          Wpk[4][13][0])+(ik[8][1][1]*Wpk[4][13][1])));
        IkWpk[4][13][2] = ((ik[8][2][2]*Wpk[4][13][2])+((ik[8][2][0]*
          Wpk[4][13][0])+(ik[8][2][1]*Wpk[4][13][1])));
        IkWpk[4][14][0] = ((ik[9][0][2]*Wpk[4][14][2])+((ik[9][0][0]*
          Wpk[4][14][0])+(ik[9][0][1]*Wpk[4][14][1])));
        IkWpk[4][14][1] = ((ik[9][1][2]*Wpk[4][14][2])+((ik[9][1][0]*
          Wpk[4][14][0])+(ik[9][1][1]*Wpk[4][14][1])));
        IkWpk[4][14][2] = ((ik[9][2][2]*Wpk[4][14][2])+((ik[9][2][0]*
          Wpk[4][14][0])+(ik[9][2][1]*Wpk[4][14][1])));
        IkWpk[4][15][0] = ((Cik[15][1][2]*ik[10][0][2])+((Cik[15][1][0]*
          ik[10][0][0])+(Cik[15][1][1]*ik[10][0][1])));
        IkWpk[4][15][1] = ((Cik[15][1][2]*ik[10][1][2])+((Cik[15][1][0]*
          ik[10][1][0])+(Cik[15][1][1]*ik[10][1][1])));
        IkWpk[4][15][2] = ((Cik[15][1][2]*ik[10][2][2])+((Cik[15][1][0]*
          ik[10][2][0])+(Cik[15][1][1]*ik[10][2][1])));
        IkWpk[4][16][0] = ((ik[11][0][2]*Wpk[4][16][2])+((ik[11][0][0]*
          Wpk[4][16][0])+(ik[11][0][1]*Wpk[4][16][1])));
        IkWpk[4][16][1] = ((ik[11][1][2]*Wpk[4][16][2])+((ik[11][1][0]*
          Wpk[4][16][0])+(ik[11][1][1]*Wpk[4][16][1])));
        IkWpk[4][16][2] = ((ik[11][2][2]*Wpk[4][16][2])+((ik[11][2][0]*
          Wpk[4][16][0])+(ik[11][2][1]*Wpk[4][16][1])));
        IkWpk[4][17][0] = ((ik[12][0][2]*Wpk[4][17][2])+((ik[12][0][0]*
          Wpk[4][17][0])+(ik[12][0][1]*Wpk[4][17][1])));
        IkWpk[4][17][1] = ((ik[12][1][2]*Wpk[4][17][2])+((ik[12][1][0]*
          Wpk[4][17][0])+(ik[12][1][1]*Wpk[4][17][1])));
        IkWpk[4][17][2] = ((ik[12][2][2]*Wpk[4][17][2])+((ik[12][2][0]*
          Wpk[4][17][0])+(ik[12][2][1]*Wpk[4][17][1])));
        IkWpk[5][6][0] = ((Cik[6][2][2]*ik[1][0][2])+((Cik[6][2][0]*ik[1][0][0])
          +(Cik[6][2][1]*ik[1][0][1])));
        IkWpk[5][6][1] = ((Cik[6][2][2]*ik[1][1][2])+((Cik[6][2][0]*ik[1][1][0])
          +(Cik[6][2][1]*ik[1][1][1])));
        IkWpk[5][6][2] = ((Cik[6][2][2]*ik[1][2][2])+((Cik[6][2][0]*ik[1][2][0])
          +(Cik[6][2][1]*ik[1][2][1])));
        IkWpk[5][7][0] = ((ik[2][0][2]*Wpk[5][7][2])+((ik[2][0][0]*Wpk[5][7][0])
          +(ik[2][0][1]*Wpk[5][7][1])));
        IkWpk[5][7][1] = ((ik[2][1][2]*Wpk[5][7][2])+((ik[2][1][0]*Wpk[5][7][0])
          +(ik[2][1][1]*Wpk[5][7][1])));
        IkWpk[5][7][2] = ((ik[2][2][2]*Wpk[5][7][2])+((ik[2][2][0]*Wpk[5][7][0])
          +(ik[2][2][1]*Wpk[5][7][1])));
        IkWpk[5][8][0] = ((ik[3][0][2]*Wpk[5][8][2])+((ik[3][0][0]*Wpk[5][8][0])
          +(ik[3][0][1]*Wpk[5][8][1])));
        IkWpk[5][8][1] = ((ik[3][1][2]*Wpk[5][8][2])+((ik[3][1][0]*Wpk[5][8][0])
          +(ik[3][1][1]*Wpk[5][8][1])));
        IkWpk[5][8][2] = ((ik[3][2][2]*Wpk[5][8][2])+((ik[3][2][0]*Wpk[5][8][0])
          +(ik[3][2][1]*Wpk[5][8][1])));
        IkWpk[5][9][0] = ((Cik[9][2][2]*ik[4][0][2])+((Cik[9][2][0]*ik[4][0][0])
          +(Cik[9][2][1]*ik[4][0][1])));
        IkWpk[5][9][1] = ((Cik[9][2][2]*ik[4][1][2])+((Cik[9][2][0]*ik[4][1][0])
          +(Cik[9][2][1]*ik[4][1][1])));
        IkWpk[5][9][2] = ((Cik[9][2][2]*ik[4][2][2])+((Cik[9][2][0]*ik[4][2][0])
          +(Cik[9][2][1]*ik[4][2][1])));
        IkWpk[5][10][0] = ((ik[5][0][2]*Wpk[5][10][2])+((ik[5][0][0]*
          Wpk[5][10][0])+(ik[5][0][1]*Wpk[5][10][1])));
        IkWpk[5][10][1] = ((ik[5][1][2]*Wpk[5][10][2])+((ik[5][1][0]*
          Wpk[5][10][0])+(ik[5][1][1]*Wpk[5][10][1])));
        IkWpk[5][10][2] = ((ik[5][2][2]*Wpk[5][10][2])+((ik[5][2][0]*
          Wpk[5][10][0])+(ik[5][2][1]*Wpk[5][10][1])));
        IkWpk[5][11][0] = ((ik[6][0][2]*Wpk[5][11][2])+((ik[6][0][0]*
          Wpk[5][11][0])+(ik[6][0][1]*Wpk[5][11][1])));
        IkWpk[5][11][1] = ((ik[6][1][2]*Wpk[5][11][2])+((ik[6][1][0]*
          Wpk[5][11][0])+(ik[6][1][1]*Wpk[5][11][1])));
        IkWpk[5][11][2] = ((ik[6][2][2]*Wpk[5][11][2])+((ik[6][2][0]*
          Wpk[5][11][0])+(ik[6][2][1]*Wpk[5][11][1])));
        IkWpk[5][12][0] = ((Cik[12][2][2]*ik[7][0][2])+((Cik[12][2][0]*
          ik[7][0][0])+(Cik[12][2][1]*ik[7][0][1])));
        IkWpk[5][12][1] = ((Cik[12][2][2]*ik[7][1][2])+((Cik[12][2][0]*
          ik[7][1][0])+(Cik[12][2][1]*ik[7][1][1])));
        IkWpk[5][12][2] = ((Cik[12][2][2]*ik[7][2][2])+((Cik[12][2][0]*
          ik[7][2][0])+(Cik[12][2][1]*ik[7][2][1])));
        IkWpk[5][13][0] = ((ik[8][0][2]*Wpk[5][13][2])+((ik[8][0][0]*
          Wpk[5][13][0])+(ik[8][0][1]*Wpk[5][13][1])));
        IkWpk[5][13][1] = ((ik[8][1][2]*Wpk[5][13][2])+((ik[8][1][0]*
          Wpk[5][13][0])+(ik[8][1][1]*Wpk[5][13][1])));
        IkWpk[5][13][2] = ((ik[8][2][2]*Wpk[5][13][2])+((ik[8][2][0]*
          Wpk[5][13][0])+(ik[8][2][1]*Wpk[5][13][1])));
        IkWpk[5][14][0] = ((ik[9][0][2]*Wpk[5][14][2])+((ik[9][0][0]*
          Wpk[5][14][0])+(ik[9][0][1]*Wpk[5][14][1])));
        IkWpk[5][14][1] = ((ik[9][1][2]*Wpk[5][14][2])+((ik[9][1][0]*
          Wpk[5][14][0])+(ik[9][1][1]*Wpk[5][14][1])));
        IkWpk[5][14][2] = ((ik[9][2][2]*Wpk[5][14][2])+((ik[9][2][0]*
          Wpk[5][14][0])+(ik[9][2][1]*Wpk[5][14][1])));
        IkWpk[5][15][0] = ((Cik[15][2][2]*ik[10][0][2])+((Cik[15][2][0]*
          ik[10][0][0])+(Cik[15][2][1]*ik[10][0][1])));
        IkWpk[5][15][1] = ((Cik[15][2][2]*ik[10][1][2])+((Cik[15][2][0]*
          ik[10][1][0])+(Cik[15][2][1]*ik[10][1][1])));
        IkWpk[5][15][2] = ((Cik[15][2][2]*ik[10][2][2])+((Cik[15][2][0]*
          ik[10][2][0])+(Cik[15][2][1]*ik[10][2][1])));
        IkWpk[5][16][0] = ((ik[11][0][2]*Wpk[5][16][2])+((ik[11][0][0]*
          Wpk[5][16][0])+(ik[11][0][1]*Wpk[5][16][1])));
        IkWpk[5][16][1] = ((ik[11][1][2]*Wpk[5][16][2])+((ik[11][1][0]*
          Wpk[5][16][0])+(ik[11][1][1]*Wpk[5][16][1])));
        IkWpk[5][16][2] = ((ik[11][2][2]*Wpk[5][16][2])+((ik[11][2][0]*
          Wpk[5][16][0])+(ik[11][2][1]*Wpk[5][16][1])));
        IkWpk[5][17][0] = ((ik[12][0][2]*Wpk[5][17][2])+((ik[12][0][0]*
          Wpk[5][17][0])+(ik[12][0][1]*Wpk[5][17][1])));
        IkWpk[5][17][1] = ((ik[12][1][2]*Wpk[5][17][2])+((ik[12][1][0]*
          Wpk[5][17][0])+(ik[12][1][1]*Wpk[5][17][1])));
        IkWpk[5][17][2] = ((ik[12][2][2]*Wpk[5][17][2])+((ik[12][2][0]*
          Wpk[5][17][0])+(ik[12][2][1]*Wpk[5][17][1])));
        IkWpk[6][6][0] = ((ik[1][0][2]*pin[6][2])+((ik[1][0][0]*pin[6][0])+(
          ik[1][0][1]*pin[6][1])));
        IkWpk[6][6][1] = ((ik[1][1][2]*pin[6][2])+((ik[1][1][0]*pin[6][0])+(
          ik[1][1][1]*pin[6][1])));
        IkWpk[6][6][2] = ((ik[1][2][2]*pin[6][2])+((ik[1][2][0]*pin[6][0])+(
          ik[1][2][1]*pin[6][1])));
        IkWpk[6][7][0] = ((ik[2][0][2]*Wpk[6][7][2])+((ik[2][0][0]*Wpk[6][7][0])
          +(ik[2][0][1]*Wpk[6][7][1])));
        IkWpk[6][7][1] = ((ik[2][1][2]*Wpk[6][7][2])+((ik[2][1][0]*Wpk[6][7][0])
          +(ik[2][1][1]*Wpk[6][7][1])));
        IkWpk[6][7][2] = ((ik[2][2][2]*Wpk[6][7][2])+((ik[2][2][0]*Wpk[6][7][0])
          +(ik[2][2][1]*Wpk[6][7][1])));
        IkWpk[6][8][0] = ((ik[3][0][2]*Wpk[6][8][2])+((ik[3][0][0]*Wpk[6][8][0])
          +(ik[3][0][1]*Wpk[6][8][1])));
        IkWpk[6][8][1] = ((ik[3][1][2]*Wpk[6][8][2])+((ik[3][1][0]*Wpk[6][8][0])
          +(ik[3][1][1]*Wpk[6][8][1])));
        IkWpk[6][8][2] = ((ik[3][2][2]*Wpk[6][8][2])+((ik[3][2][0]*Wpk[6][8][0])
          +(ik[3][2][1]*Wpk[6][8][1])));
        IkWpk[7][7][0] = ((ik[2][0][2]*pin[7][2])+((ik[2][0][0]*pin[7][0])+(
          ik[2][0][1]*pin[7][1])));
        IkWpk[7][7][1] = ((ik[2][1][2]*pin[7][2])+((ik[2][1][0]*pin[7][0])+(
          ik[2][1][1]*pin[7][1])));
        IkWpk[7][7][2] = ((ik[2][2][2]*pin[7][2])+((ik[2][2][0]*pin[7][0])+(
          ik[2][2][1]*pin[7][1])));
        IkWpk[7][8][0] = ((ik[3][0][2]*Wpk[7][8][2])+((ik[3][0][0]*Wpk[7][8][0])
          +(ik[3][0][1]*Wpk[7][8][1])));
        IkWpk[7][8][1] = ((ik[3][1][2]*Wpk[7][8][2])+((ik[3][1][0]*Wpk[7][8][0])
          +(ik[3][1][1]*Wpk[7][8][1])));
        IkWpk[7][8][2] = ((ik[3][2][2]*Wpk[7][8][2])+((ik[3][2][0]*Wpk[7][8][0])
          +(ik[3][2][1]*Wpk[7][8][1])));
        IkWpk[8][8][0] = ((ik[3][0][2]*pin[8][2])+((ik[3][0][0]*pin[8][0])+(
          ik[3][0][1]*pin[8][1])));
        IkWpk[8][8][1] = ((ik[3][1][2]*pin[8][2])+((ik[3][1][0]*pin[8][0])+(
          ik[3][1][1]*pin[8][1])));
        IkWpk[8][8][2] = ((ik[3][2][2]*pin[8][2])+((ik[3][2][0]*pin[8][0])+(
          ik[3][2][1]*pin[8][1])));
        IkWpk[9][9][0] = ((ik[4][0][2]*pin[9][2])+((ik[4][0][0]*pin[9][0])+(
          ik[4][0][1]*pin[9][1])));
        IkWpk[9][9][1] = ((ik[4][1][2]*pin[9][2])+((ik[4][1][0]*pin[9][0])+(
          ik[4][1][1]*pin[9][1])));
        IkWpk[9][9][2] = ((ik[4][2][2]*pin[9][2])+((ik[4][2][0]*pin[9][0])+(
          ik[4][2][1]*pin[9][1])));
        IkWpk[9][10][0] = ((ik[5][0][2]*Wpk[9][10][2])+((ik[5][0][0]*
          Wpk[9][10][0])+(ik[5][0][1]*Wpk[9][10][1])));
        IkWpk[9][10][1] = ((ik[5][1][2]*Wpk[9][10][2])+((ik[5][1][0]*
          Wpk[9][10][0])+(ik[5][1][1]*Wpk[9][10][1])));
        IkWpk[9][10][2] = ((ik[5][2][2]*Wpk[9][10][2])+((ik[5][2][0]*
          Wpk[9][10][0])+(ik[5][2][1]*Wpk[9][10][1])));
        IkWpk[9][11][0] = ((ik[6][0][2]*Wpk[9][11][2])+((ik[6][0][0]*
          Wpk[9][11][0])+(ik[6][0][1]*Wpk[9][11][1])));
        IkWpk[9][11][1] = ((ik[6][1][2]*Wpk[9][11][2])+((ik[6][1][0]*
          Wpk[9][11][0])+(ik[6][1][1]*Wpk[9][11][1])));
        IkWpk[9][11][2] = ((ik[6][2][2]*Wpk[9][11][2])+((ik[6][2][0]*
          Wpk[9][11][0])+(ik[6][2][1]*Wpk[9][11][1])));
        IkWpk[10][10][0] = ((ik[5][0][2]*pin[10][2])+((ik[5][0][0]*pin[10][0])+(
          ik[5][0][1]*pin[10][1])));
        IkWpk[10][10][1] = ((ik[5][1][2]*pin[10][2])+((ik[5][1][0]*pin[10][0])+(
          ik[5][1][1]*pin[10][1])));
        IkWpk[10][10][2] = ((ik[5][2][2]*pin[10][2])+((ik[5][2][0]*pin[10][0])+(
          ik[5][2][1]*pin[10][1])));
        IkWpk[10][11][0] = ((ik[6][0][2]*Wpk[10][11][2])+((ik[6][0][0]*
          Wpk[10][11][0])+(ik[6][0][1]*Wpk[10][11][1])));
        IkWpk[10][11][1] = ((ik[6][1][2]*Wpk[10][11][2])+((ik[6][1][0]*
          Wpk[10][11][0])+(ik[6][1][1]*Wpk[10][11][1])));
        IkWpk[10][11][2] = ((ik[6][2][2]*Wpk[10][11][2])+((ik[6][2][0]*
          Wpk[10][11][0])+(ik[6][2][1]*Wpk[10][11][1])));
        IkWpk[11][11][0] = ((ik[6][0][2]*pin[11][2])+((ik[6][0][0]*pin[11][0])+(
          ik[6][0][1]*pin[11][1])));
        IkWpk[11][11][1] = ((ik[6][1][2]*pin[11][2])+((ik[6][1][0]*pin[11][0])+(
          ik[6][1][1]*pin[11][1])));
        IkWpk[11][11][2] = ((ik[6][2][2]*pin[11][2])+((ik[6][2][0]*pin[11][0])+(
          ik[6][2][1]*pin[11][1])));
        IkWpk[12][12][0] = ((ik[7][0][2]*pin[12][2])+((ik[7][0][0]*pin[12][0])+(
          ik[7][0][1]*pin[12][1])));
        IkWpk[12][12][1] = ((ik[7][1][2]*pin[12][2])+((ik[7][1][0]*pin[12][0])+(
          ik[7][1][1]*pin[12][1])));
        IkWpk[12][12][2] = ((ik[7][2][2]*pin[12][2])+((ik[7][2][0]*pin[12][0])+(
          ik[7][2][1]*pin[12][1])));
        IkWpk[12][13][0] = ((ik[8][0][2]*Wpk[12][13][2])+((ik[8][0][0]*
          Wpk[12][13][0])+(ik[8][0][1]*Wpk[12][13][1])));
        IkWpk[12][13][1] = ((ik[8][1][2]*Wpk[12][13][2])+((ik[8][1][0]*
          Wpk[12][13][0])+(ik[8][1][1]*Wpk[12][13][1])));
        IkWpk[12][13][2] = ((ik[8][2][2]*Wpk[12][13][2])+((ik[8][2][0]*
          Wpk[12][13][0])+(ik[8][2][1]*Wpk[12][13][1])));
        IkWpk[12][14][0] = ((ik[9][0][2]*Wpk[12][14][2])+((ik[9][0][0]*
          Wpk[12][14][0])+(ik[9][0][1]*Wpk[12][14][1])));
        IkWpk[12][14][1] = ((ik[9][1][2]*Wpk[12][14][2])+((ik[9][1][0]*
          Wpk[12][14][0])+(ik[9][1][1]*Wpk[12][14][1])));
        IkWpk[12][14][2] = ((ik[9][2][2]*Wpk[12][14][2])+((ik[9][2][0]*
          Wpk[12][14][0])+(ik[9][2][1]*Wpk[12][14][1])));
        IkWpk[13][13][0] = ((ik[8][0][2]*pin[13][2])+((ik[8][0][0]*pin[13][0])+(
          ik[8][0][1]*pin[13][1])));
        IkWpk[13][13][1] = ((ik[8][1][2]*pin[13][2])+((ik[8][1][0]*pin[13][0])+(
          ik[8][1][1]*pin[13][1])));
        IkWpk[13][13][2] = ((ik[8][2][2]*pin[13][2])+((ik[8][2][0]*pin[13][0])+(
          ik[8][2][1]*pin[13][1])));
        IkWpk[13][14][0] = ((ik[9][0][2]*Wpk[13][14][2])+((ik[9][0][0]*
          Wpk[13][14][0])+(ik[9][0][1]*Wpk[13][14][1])));
        IkWpk[13][14][1] = ((ik[9][1][2]*Wpk[13][14][2])+((ik[9][1][0]*
          Wpk[13][14][0])+(ik[9][1][1]*Wpk[13][14][1])));
        IkWpk[13][14][2] = ((ik[9][2][2]*Wpk[13][14][2])+((ik[9][2][0]*
          Wpk[13][14][0])+(ik[9][2][1]*Wpk[13][14][1])));
        IkWpk[14][14][0] = ((ik[9][0][2]*pin[14][2])+((ik[9][0][0]*pin[14][0])+(
          ik[9][0][1]*pin[14][1])));
        IkWpk[14][14][1] = ((ik[9][1][2]*pin[14][2])+((ik[9][1][0]*pin[14][0])+(
          ik[9][1][1]*pin[14][1])));
        IkWpk[14][14][2] = ((ik[9][2][2]*pin[14][2])+((ik[9][2][0]*pin[14][0])+(
          ik[9][2][1]*pin[14][1])));
        IkWpk[15][15][0] = ((ik[10][0][2]*pin[15][2])+((ik[10][0][0]*pin[15][0])
          +(ik[10][0][1]*pin[15][1])));
        IkWpk[15][15][1] = ((ik[10][1][2]*pin[15][2])+((ik[10][1][0]*pin[15][0])
          +(ik[10][1][1]*pin[15][1])));
        IkWpk[15][15][2] = ((ik[10][2][2]*pin[15][2])+((ik[10][2][0]*pin[15][0])
          +(ik[10][2][1]*pin[15][1])));
        IkWpk[15][16][0] = ((ik[11][0][2]*Wpk[15][16][2])+((ik[11][0][0]*
          Wpk[15][16][0])+(ik[11][0][1]*Wpk[15][16][1])));
        IkWpk[15][16][1] = ((ik[11][1][2]*Wpk[15][16][2])+((ik[11][1][0]*
          Wpk[15][16][0])+(ik[11][1][1]*Wpk[15][16][1])));
        IkWpk[15][16][2] = ((ik[11][2][2]*Wpk[15][16][2])+((ik[11][2][0]*
          Wpk[15][16][0])+(ik[11][2][1]*Wpk[15][16][1])));
        IkWpk[15][17][0] = ((ik[12][0][2]*Wpk[15][17][2])+((ik[12][0][0]*
          Wpk[15][17][0])+(ik[12][0][1]*Wpk[15][17][1])));
        IkWpk[15][17][1] = ((ik[12][1][2]*Wpk[15][17][2])+((ik[12][1][0]*
          Wpk[15][17][0])+(ik[12][1][1]*Wpk[15][17][1])));
        IkWpk[15][17][2] = ((ik[12][2][2]*Wpk[15][17][2])+((ik[12][2][0]*
          Wpk[15][17][0])+(ik[12][2][1]*Wpk[15][17][1])));
        IkWpk[16][16][0] = ((ik[11][0][2]*pin[16][2])+((ik[11][0][0]*pin[16][0])
          +(ik[11][0][1]*pin[16][1])));
        IkWpk[16][16][1] = ((ik[11][1][2]*pin[16][2])+((ik[11][1][0]*pin[16][0])
          +(ik[11][1][1]*pin[16][1])));
        IkWpk[16][16][2] = ((ik[11][2][2]*pin[16][2])+((ik[11][2][0]*pin[16][0])
          +(ik[11][2][1]*pin[16][1])));
        IkWpk[16][17][0] = ((ik[12][0][2]*Wpk[16][17][2])+((ik[12][0][0]*
          Wpk[16][17][0])+(ik[12][0][1]*Wpk[16][17][1])));
        IkWpk[16][17][1] = ((ik[12][1][2]*Wpk[16][17][2])+((ik[12][1][0]*
          Wpk[16][17][0])+(ik[12][1][1]*Wpk[16][17][1])));
        IkWpk[16][17][2] = ((ik[12][2][2]*Wpk[16][17][2])+((ik[12][2][0]*
          Wpk[16][17][0])+(ik[12][2][1]*Wpk[16][17][1])));
        IkWpk[17][17][0] = ((ik[12][0][2]*pin[17][2])+((ik[12][0][0]*pin[17][0])
          +(ik[12][0][1]*pin[17][1])));
        IkWpk[17][17][1] = ((ik[12][1][2]*pin[17][2])+((ik[12][1][0]*pin[17][0])
          +(ik[12][1][1]*pin[17][1])));
        IkWpk[17][17][2] = ((ik[12][2][2]*pin[17][2])+((ik[12][2][0]*pin[17][0])
          +(ik[12][2][1]*pin[17][1])));
        temp[0] = ((mk[2]*((Vpk[0][7][2]*Vpk[0][7][2])+((Vpk[0][7][0]*
          Vpk[0][7][0])+(Vpk[0][7][1]*Vpk[0][7][1]))))+((mk[0]*((Vpk[0][3][2]*
          Vpk[0][3][2])+((Vpk[0][3][0]*Vpk[0][3][0])+(Vpk[0][3][1]*Vpk[0][3][1])
          )))+(mk[1]*((Vpk[0][6][2]*Vpk[0][6][2])+((Vpk[0][6][0]*Vpk[0][6][0])+(
          Vpk[0][6][1]*Vpk[0][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[0][10][2]*Vpk[0][10][2])+((Vpk[0][10][0]*
          Vpk[0][10][0])+(Vpk[0][10][1]*Vpk[0][10][1]))))+((mk[4]*((Vpk[0][9][2]
          *Vpk[0][9][2])+((Vpk[0][9][0]*Vpk[0][9][0])+(Vpk[0][9][1]*Vpk[0][9][1]
          ))))+((mk[3]*((Vpk[0][8][2]*Vpk[0][8][2])+((Vpk[0][8][0]*Vpk[0][8][0])
          +(Vpk[0][8][1]*Vpk[0][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[0][13][2]*Vpk[0][13][2])+((Vpk[0][13][0]*
          Vpk[0][13][0])+(Vpk[0][13][1]*Vpk[0][13][1]))))+((mk[7]*((
          Vpk[0][12][2]*Vpk[0][12][2])+((Vpk[0][12][0]*Vpk[0][12][0])+(
          Vpk[0][12][1]*Vpk[0][12][1]))))+((mk[6]*((Vpk[0][11][2]*Vpk[0][11][2])
          +((Vpk[0][11][0]*Vpk[0][11][0])+(Vpk[0][11][1]*Vpk[0][11][1]))))+
          temp[1])));
        temp[3] = ((mk[11]*((Vpk[0][16][2]*Vpk[0][16][2])+((Vpk[0][16][0]*
          Vpk[0][16][0])+(Vpk[0][16][1]*Vpk[0][16][1]))))+((mk[10]*((
          Vpk[0][15][2]*Vpk[0][15][2])+((Vpk[0][15][0]*Vpk[0][15][0])+(
          Vpk[0][15][1]*Vpk[0][15][1]))))+((mk[9]*((Vpk[0][14][2]*Vpk[0][14][2])
          +((Vpk[0][14][0]*Vpk[0][14][0])+(Vpk[0][14][1]*Vpk[0][14][1]))))+
          temp[2])));
        mm[0][0] = ((mk[12]*((Vpk[0][17][2]*Vpk[0][17][2])+((Vpk[0][17][0]*
          Vpk[0][17][0])+(Vpk[0][17][1]*Vpk[0][17][1]))))+temp[3]);
        temp[0] = ((mk[2]*((Vpk[0][7][2]*Vpk[1][7][2])+((Vpk[0][7][0]*
          Vpk[1][7][0])+(Vpk[0][7][1]*Vpk[1][7][1]))))+((mk[0]*((Vpk[0][3][2]*
          Vpk[1][3][2])+((Vpk[0][3][0]*Vpk[1][3][0])+(Vpk[0][3][1]*Vpk[1][3][1])
          )))+(mk[1]*((Vpk[0][6][2]*Vpk[1][6][2])+((Vpk[0][6][0]*Vpk[1][6][0])+(
          Vpk[0][6][1]*Vpk[1][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[0][10][2]*Vpk[1][10][2])+((Vpk[0][10][0]*
          Vpk[1][10][0])+(Vpk[0][10][1]*Vpk[1][10][1]))))+((mk[4]*((Vpk[0][9][2]
          *Vpk[1][9][2])+((Vpk[0][9][0]*Vpk[1][9][0])+(Vpk[0][9][1]*Vpk[1][9][1]
          ))))+((mk[3]*((Vpk[0][8][2]*Vpk[1][8][2])+((Vpk[0][8][0]*Vpk[1][8][0])
          +(Vpk[0][8][1]*Vpk[1][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[0][13][2]*Vpk[1][13][2])+((Vpk[0][13][0]*
          Vpk[1][13][0])+(Vpk[0][13][1]*Vpk[1][13][1]))))+((mk[7]*((
          Vpk[0][12][2]*Vpk[1][12][2])+((Vpk[0][12][0]*Vpk[1][12][0])+(
          Vpk[0][12][1]*Vpk[1][12][1]))))+((mk[6]*((Vpk[0][11][2]*Vpk[1][11][2])
          +((Vpk[0][11][0]*Vpk[1][11][0])+(Vpk[0][11][1]*Vpk[1][11][1]))))+
          temp[1])));
        temp[3] = ((mk[11]*((Vpk[0][16][2]*Vpk[1][16][2])+((Vpk[0][16][0]*
          Vpk[1][16][0])+(Vpk[0][16][1]*Vpk[1][16][1]))))+((mk[10]*((
          Vpk[0][15][2]*Vpk[1][15][2])+((Vpk[0][15][0]*Vpk[1][15][0])+(
          Vpk[0][15][1]*Vpk[1][15][1]))))+((mk[9]*((Vpk[0][14][2]*Vpk[1][14][2])
          +((Vpk[0][14][0]*Vpk[1][14][0])+(Vpk[0][14][1]*Vpk[1][14][1]))))+
          temp[2])));
        mm[0][1] = ((mk[12]*((Vpk[0][17][2]*Vpk[1][17][2])+((Vpk[0][17][0]*
          Vpk[1][17][0])+(Vpk[0][17][1]*Vpk[1][17][1]))))+temp[3]);
        temp[0] = ((mk[2]*((Vpk[0][7][2]*Vpk[2][7][2])+((Vpk[0][7][0]*
          Vpk[2][7][0])+(Vpk[0][7][1]*Vpk[2][7][1]))))+((mk[0]*((Vpk[0][3][2]*
          Vpk[2][3][2])+((Vpk[0][3][0]*Vpk[2][3][0])+(Vpk[0][3][1]*Vpk[2][3][1])
          )))+(mk[1]*((Vpk[0][6][2]*Vpk[2][6][2])+((Vpk[0][6][0]*Vpk[2][6][0])+(
          Vpk[0][6][1]*Vpk[2][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[0][10][2]*Vpk[2][10][2])+((Vpk[0][10][0]*
          Vpk[2][10][0])+(Vpk[0][10][1]*Vpk[2][10][1]))))+((mk[4]*((Vpk[0][9][2]
          *Vpk[2][9][2])+((Vpk[0][9][0]*Vpk[2][9][0])+(Vpk[0][9][1]*Vpk[2][9][1]
          ))))+((mk[3]*((Vpk[0][8][2]*Vpk[2][8][2])+((Vpk[0][8][0]*Vpk[2][8][0])
          +(Vpk[0][8][1]*Vpk[2][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[0][13][2]*Vpk[2][13][2])+((Vpk[0][13][0]*
          Vpk[2][13][0])+(Vpk[0][13][1]*Vpk[2][13][1]))))+((mk[7]*((
          Vpk[0][12][2]*Vpk[2][12][2])+((Vpk[0][12][0]*Vpk[2][12][0])+(
          Vpk[0][12][1]*Vpk[2][12][1]))))+((mk[6]*((Vpk[0][11][2]*Vpk[2][11][2])
          +((Vpk[0][11][0]*Vpk[2][11][0])+(Vpk[0][11][1]*Vpk[2][11][1]))))+
          temp[1])));
        temp[3] = ((mk[11]*((Vpk[0][16][2]*Vpk[2][16][2])+((Vpk[0][16][0]*
          Vpk[2][16][0])+(Vpk[0][16][1]*Vpk[2][16][1]))))+((mk[10]*((
          Vpk[0][15][2]*Vpk[2][15][2])+((Vpk[0][15][0]*Vpk[2][15][0])+(
          Vpk[0][15][1]*Vpk[2][15][1]))))+((mk[9]*((Vpk[0][14][2]*Vpk[2][14][2])
          +((Vpk[0][14][0]*Vpk[2][14][0])+(Vpk[0][14][1]*Vpk[2][14][1]))))+
          temp[2])));
        mm[0][2] = ((mk[12]*((Vpk[0][17][2]*Vpk[2][17][2])+((Vpk[0][17][0]*
          Vpk[2][17][0])+(Vpk[0][17][1]*Vpk[2][17][1]))))+temp[3]);
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[3][8][2])+((Vpk[0][8][0]*
          Vpk[3][8][0])+(Vpk[0][8][1]*Vpk[3][8][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[3][7][2])+((Vpk[0][7][0]*Vpk[3][7][0])+(Vpk[0][7][1]*Vpk[3][7][1])
          )))+((mk[0]*((rk[0][2]*Vpk[0][3][1])-(rk[0][1]*Vpk[0][3][2])))+(mk[1]*
          ((Vpk[0][6][2]*Vpk[3][6][2])+((Vpk[0][6][0]*Vpk[3][6][0])+(
          Vpk[0][6][1]*Vpk[3][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[0][11][2]*Vpk[3][11][2])+((Vpk[0][11][0]*
          Vpk[3][11][0])+(Vpk[0][11][1]*Vpk[3][11][1]))))+((mk[5]*((
          Vpk[0][10][2]*Vpk[3][10][2])+((Vpk[0][10][0]*Vpk[3][10][0])+(
          Vpk[0][10][1]*Vpk[3][10][1]))))+((mk[4]*((Vpk[0][9][2]*Vpk[3][9][2])+(
          (Vpk[0][9][0]*Vpk[3][9][0])+(Vpk[0][9][1]*Vpk[3][9][1]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[0][14][2]*Vpk[3][14][2])+((Vpk[0][14][0]*
          Vpk[3][14][0])+(Vpk[0][14][1]*Vpk[3][14][1]))))+((mk[8]*((
          Vpk[0][13][2]*Vpk[3][13][2])+((Vpk[0][13][0]*Vpk[3][13][0])+(
          Vpk[0][13][1]*Vpk[3][13][1]))))+((mk[7]*((Vpk[0][12][2]*Vpk[3][12][2])
          +((Vpk[0][12][0]*Vpk[3][12][0])+(Vpk[0][12][1]*Vpk[3][12][1]))))+
          temp[1])));
        mm[0][3] = ((mk[12]*((Vpk[0][17][2]*Vpk[3][17][2])+((Vpk[0][17][0]*
          Vpk[3][17][0])+(Vpk[0][17][1]*Vpk[3][17][1]))))+((mk[11]*((
          Vpk[0][16][2]*Vpk[3][16][2])+((Vpk[0][16][0]*Vpk[3][16][0])+(
          Vpk[0][16][1]*Vpk[3][16][1]))))+((mk[10]*((Vpk[0][15][2]*Vpk[3][15][2]
          )+((Vpk[0][15][0]*Vpk[3][15][0])+(Vpk[0][15][1]*Vpk[3][15][1]))))+
          temp[2])));
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[4][8][2])+((Vpk[0][8][0]*
          Vpk[4][8][0])+(Vpk[0][8][1]*Vpk[4][8][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[4][7][2])+((Vpk[0][7][0]*Vpk[4][7][0])+(Vpk[0][7][1]*Vpk[4][7][1])
          )))+((mk[0]*((rk[0][0]*Vpk[0][3][2])-(rk[0][2]*Vpk[0][3][0])))+(mk[1]*
          ((Vpk[0][6][2]*Vpk[4][6][2])+((Vpk[0][6][0]*Vpk[4][6][0])+(
          Vpk[0][6][1]*Vpk[4][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[0][11][2]*Vpk[4][11][2])+((Vpk[0][11][0]*
          Vpk[4][11][0])+(Vpk[0][11][1]*Vpk[4][11][1]))))+((mk[5]*((
          Vpk[0][10][2]*Vpk[4][10][2])+((Vpk[0][10][0]*Vpk[4][10][0])+(
          Vpk[0][10][1]*Vpk[4][10][1]))))+((mk[4]*((Vpk[0][9][2]*Vpk[4][9][2])+(
          (Vpk[0][9][0]*Vpk[4][9][0])+(Vpk[0][9][1]*Vpk[4][9][1]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[0][14][2]*Vpk[4][14][2])+((Vpk[0][14][0]*
          Vpk[4][14][0])+(Vpk[0][14][1]*Vpk[4][14][1]))))+((mk[8]*((
          Vpk[0][13][2]*Vpk[4][13][2])+((Vpk[0][13][0]*Vpk[4][13][0])+(
          Vpk[0][13][1]*Vpk[4][13][1]))))+((mk[7]*((Vpk[0][12][2]*Vpk[4][12][2])
          +((Vpk[0][12][0]*Vpk[4][12][0])+(Vpk[0][12][1]*Vpk[4][12][1]))))+
          temp[1])));
        mm[0][4] = ((mk[12]*((Vpk[0][17][2]*Vpk[4][17][2])+((Vpk[0][17][0]*
          Vpk[4][17][0])+(Vpk[0][17][1]*Vpk[4][17][1]))))+((mk[11]*((
          Vpk[0][16][2]*Vpk[4][16][2])+((Vpk[0][16][0]*Vpk[4][16][0])+(
          Vpk[0][16][1]*Vpk[4][16][1]))))+((mk[10]*((Vpk[0][15][2]*Vpk[4][15][2]
          )+((Vpk[0][15][0]*Vpk[4][15][0])+(Vpk[0][15][1]*Vpk[4][15][1]))))+
          temp[2])));
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[5][8][2])+((Vpk[0][8][0]*
          Vpk[5][8][0])+(Vpk[0][8][1]*Vpk[5][8][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[5][7][2])+((Vpk[0][7][0]*Vpk[5][7][0])+(Vpk[0][7][1]*Vpk[5][7][1])
          )))+((mk[0]*((rk[0][1]*Vpk[0][3][0])-(rk[0][0]*Vpk[0][3][1])))+(mk[1]*
          ((Vpk[0][6][2]*Vpk[5][6][2])+((Vpk[0][6][0]*Vpk[5][6][0])+(
          Vpk[0][6][1]*Vpk[5][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[0][11][2]*Vpk[5][11][2])+((Vpk[0][11][0]*
          Vpk[5][11][0])+(Vpk[0][11][1]*Vpk[5][11][1]))))+((mk[5]*((
          Vpk[0][10][2]*Vpk[5][10][2])+((Vpk[0][10][0]*Vpk[5][10][0])+(
          Vpk[0][10][1]*Vpk[5][10][1]))))+((mk[4]*((Vpk[0][9][2]*Vpk[5][9][2])+(
          (Vpk[0][9][0]*Vpk[5][9][0])+(Vpk[0][9][1]*Vpk[5][9][1]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[0][14][2]*Vpk[5][14][2])+((Vpk[0][14][0]*
          Vpk[5][14][0])+(Vpk[0][14][1]*Vpk[5][14][1]))))+((mk[8]*((
          Vpk[0][13][2]*Vpk[5][13][2])+((Vpk[0][13][0]*Vpk[5][13][0])+(
          Vpk[0][13][1]*Vpk[5][13][1]))))+((mk[7]*((Vpk[0][12][2]*Vpk[5][12][2])
          +((Vpk[0][12][0]*Vpk[5][12][0])+(Vpk[0][12][1]*Vpk[5][12][1]))))+
          temp[1])));
        mm[0][5] = ((mk[12]*((Vpk[0][17][2]*Vpk[5][17][2])+((Vpk[0][17][0]*
          Vpk[5][17][0])+(Vpk[0][17][1]*Vpk[5][17][1]))))+((mk[11]*((
          Vpk[0][16][2]*Vpk[5][16][2])+((Vpk[0][16][0]*Vpk[5][16][0])+(
          Vpk[0][16][1]*Vpk[5][16][1]))))+((mk[10]*((Vpk[0][15][2]*Vpk[5][15][2]
          )+((Vpk[0][15][0]*Vpk[5][15][0])+(Vpk[0][15][1]*Vpk[5][15][1]))))+
          temp[2])));
        mm[0][6] = ((mk[3]*((Vpk[0][8][2]*Vpk[6][8][2])+((Vpk[0][8][0]*
          Vpk[6][8][0])+(Vpk[0][8][1]*Vpk[6][8][1]))))+((mk[1]*((Vpk[0][6][2]*
          Vpk[6][6][2])+((Vpk[0][6][0]*Vpk[6][6][0])+(Vpk[0][6][1]*Vpk[6][6][1])
          )))+(mk[2]*((Vpk[0][7][2]*Vpk[6][7][2])+((Vpk[0][7][0]*Vpk[6][7][0])+(
          Vpk[0][7][1]*Vpk[6][7][1]))))));
        mm[0][7] = ((mk[2]*((Vpk[0][7][2]*Vpk[7][7][2])+((Vpk[0][7][0]*
          Vpk[7][7][0])+(Vpk[0][7][1]*Vpk[7][7][1]))))+(mk[3]*((Vpk[0][8][2]*
          Vpk[7][8][2])+((Vpk[0][8][0]*Vpk[7][8][0])+(Vpk[0][8][1]*Vpk[7][8][1])
          ))));
        mm[0][8] = (mk[3]*((Vpk[0][8][2]*Vpk[8][8][2])+((Vpk[0][8][0]*
          Vpk[8][8][0])+(Vpk[0][8][1]*Vpk[8][8][1]))));
        mm[0][9] = ((mk[6]*((Vpk[0][11][2]*Vpk[9][11][2])+((Vpk[0][11][0]*
          Vpk[9][11][0])+(Vpk[0][11][1]*Vpk[9][11][1]))))+((mk[4]*((Vpk[0][9][2]
          *Vpk[9][9][2])+((Vpk[0][9][0]*Vpk[9][9][0])+(Vpk[0][9][1]*Vpk[9][9][1]
          ))))+(mk[5]*((Vpk[0][10][2]*Vpk[9][10][2])+((Vpk[0][10][0]*
          Vpk[9][10][0])+(Vpk[0][10][1]*Vpk[9][10][1]))))));
        mm[0][10] = ((mk[5]*((Vpk[0][10][2]*Vpk[10][10][2])+((Vpk[0][10][0]*
          Vpk[10][10][0])+(Vpk[0][10][1]*Vpk[10][10][1]))))+(mk[6]*((
          Vpk[0][11][2]*Vpk[10][11][2])+((Vpk[0][11][0]*Vpk[10][11][0])+(
          Vpk[0][11][1]*Vpk[10][11][1])))));
        mm[0][11] = (mk[6]*((Vpk[0][11][2]*Vpk[11][11][2])+((Vpk[0][11][0]*
          Vpk[11][11][0])+(Vpk[0][11][1]*Vpk[11][11][1]))));
        mm[0][12] = ((mk[9]*((Vpk[0][14][2]*Vpk[12][14][2])+((Vpk[0][14][0]*
          Vpk[12][14][0])+(Vpk[0][14][1]*Vpk[12][14][1]))))+((mk[7]*((
          Vpk[0][12][2]*Vpk[12][12][2])+((Vpk[0][12][0]*Vpk[12][12][0])+(
          Vpk[0][12][1]*Vpk[12][12][1]))))+(mk[8]*((Vpk[0][13][2]*Vpk[12][13][2]
          )+((Vpk[0][13][0]*Vpk[12][13][0])+(Vpk[0][13][1]*Vpk[12][13][1]))))));
        mm[0][13] = ((mk[8]*((Vpk[0][13][2]*Vpk[13][13][2])+((Vpk[0][13][0]*
          Vpk[13][13][0])+(Vpk[0][13][1]*Vpk[13][13][1]))))+(mk[9]*((
          Vpk[0][14][2]*Vpk[13][14][2])+((Vpk[0][14][0]*Vpk[13][14][0])+(
          Vpk[0][14][1]*Vpk[13][14][1])))));
        mm[0][14] = (mk[9]*((Vpk[0][14][2]*Vpk[14][14][2])+((Vpk[0][14][0]*
          Vpk[14][14][0])+(Vpk[0][14][1]*Vpk[14][14][1]))));
        mm[0][15] = ((mk[12]*((Vpk[0][17][2]*Vpk[15][17][2])+((Vpk[0][17][0]*
          Vpk[15][17][0])+(Vpk[0][17][1]*Vpk[15][17][1]))))+((mk[10]*((
          Vpk[0][15][2]*Vpk[15][15][2])+((Vpk[0][15][0]*Vpk[15][15][0])+(
          Vpk[0][15][1]*Vpk[15][15][1]))))+(mk[11]*((Vpk[0][16][2]*
          Vpk[15][16][2])+((Vpk[0][16][0]*Vpk[15][16][0])+(Vpk[0][16][1]*
          Vpk[15][16][1]))))));
        mm[0][16] = ((mk[11]*((Vpk[0][16][2]*Vpk[16][16][2])+((Vpk[0][16][0]*
          Vpk[16][16][0])+(Vpk[0][16][1]*Vpk[16][16][1]))))+(mk[12]*((
          Vpk[0][17][2]*Vpk[16][17][2])+((Vpk[0][17][0]*Vpk[16][17][0])+(
          Vpk[0][17][1]*Vpk[16][17][1])))));
        mm[0][17] = (mk[12]*((Vpk[0][17][2]*Vpk[17][17][2])+((Vpk[0][17][0]*
          Vpk[17][17][0])+(Vpk[0][17][1]*Vpk[17][17][1]))));
        temp[0] = ((mk[2]*((Vpk[1][7][2]*Vpk[1][7][2])+((Vpk[1][7][0]*
          Vpk[1][7][0])+(Vpk[1][7][1]*Vpk[1][7][1]))))+((mk[0]*((Vpk[1][3][2]*
          Vpk[1][3][2])+((Vpk[1][3][0]*Vpk[1][3][0])+(Vpk[1][3][1]*Vpk[1][3][1])
          )))+(mk[1]*((Vpk[1][6][2]*Vpk[1][6][2])+((Vpk[1][6][0]*Vpk[1][6][0])+(
          Vpk[1][6][1]*Vpk[1][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[1][10][2]*Vpk[1][10][2])+((Vpk[1][10][0]*
          Vpk[1][10][0])+(Vpk[1][10][1]*Vpk[1][10][1]))))+((mk[4]*((Vpk[1][9][2]
          *Vpk[1][9][2])+((Vpk[1][9][0]*Vpk[1][9][0])+(Vpk[1][9][1]*Vpk[1][9][1]
          ))))+((mk[3]*((Vpk[1][8][2]*Vpk[1][8][2])+((Vpk[1][8][0]*Vpk[1][8][0])
          +(Vpk[1][8][1]*Vpk[1][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[1][13][2]*Vpk[1][13][2])+((Vpk[1][13][0]*
          Vpk[1][13][0])+(Vpk[1][13][1]*Vpk[1][13][1]))))+((mk[7]*((
          Vpk[1][12][2]*Vpk[1][12][2])+((Vpk[1][12][0]*Vpk[1][12][0])+(
          Vpk[1][12][1]*Vpk[1][12][1]))))+((mk[6]*((Vpk[1][11][2]*Vpk[1][11][2])
          +((Vpk[1][11][0]*Vpk[1][11][0])+(Vpk[1][11][1]*Vpk[1][11][1]))))+
          temp[1])));
        temp[3] = ((mk[11]*((Vpk[1][16][2]*Vpk[1][16][2])+((Vpk[1][16][0]*
          Vpk[1][16][0])+(Vpk[1][16][1]*Vpk[1][16][1]))))+((mk[10]*((
          Vpk[1][15][2]*Vpk[1][15][2])+((Vpk[1][15][0]*Vpk[1][15][0])+(
          Vpk[1][15][1]*Vpk[1][15][1]))))+((mk[9]*((Vpk[1][14][2]*Vpk[1][14][2])
          +((Vpk[1][14][0]*Vpk[1][14][0])+(Vpk[1][14][1]*Vpk[1][14][1]))))+
          temp[2])));
        mm[1][1] = ((mk[12]*((Vpk[1][17][2]*Vpk[1][17][2])+((Vpk[1][17][0]*
          Vpk[1][17][0])+(Vpk[1][17][1]*Vpk[1][17][1]))))+temp[3]);
        temp[0] = ((mk[2]*((Vpk[1][7][2]*Vpk[2][7][2])+((Vpk[1][7][0]*
          Vpk[2][7][0])+(Vpk[1][7][1]*Vpk[2][7][1]))))+((mk[0]*((Vpk[1][3][2]*
          Vpk[2][3][2])+((Vpk[1][3][0]*Vpk[2][3][0])+(Vpk[1][3][1]*Vpk[2][3][1])
          )))+(mk[1]*((Vpk[1][6][2]*Vpk[2][6][2])+((Vpk[1][6][0]*Vpk[2][6][0])+(
          Vpk[1][6][1]*Vpk[2][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[1][10][2]*Vpk[2][10][2])+((Vpk[1][10][0]*
          Vpk[2][10][0])+(Vpk[1][10][1]*Vpk[2][10][1]))))+((mk[4]*((Vpk[1][9][2]
          *Vpk[2][9][2])+((Vpk[1][9][0]*Vpk[2][9][0])+(Vpk[1][9][1]*Vpk[2][9][1]
          ))))+((mk[3]*((Vpk[1][8][2]*Vpk[2][8][2])+((Vpk[1][8][0]*Vpk[2][8][0])
          +(Vpk[1][8][1]*Vpk[2][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[1][13][2]*Vpk[2][13][2])+((Vpk[1][13][0]*
          Vpk[2][13][0])+(Vpk[1][13][1]*Vpk[2][13][1]))))+((mk[7]*((
          Vpk[1][12][2]*Vpk[2][12][2])+((Vpk[1][12][0]*Vpk[2][12][0])+(
          Vpk[1][12][1]*Vpk[2][12][1]))))+((mk[6]*((Vpk[1][11][2]*Vpk[2][11][2])
          +((Vpk[1][11][0]*Vpk[2][11][0])+(Vpk[1][11][1]*Vpk[2][11][1]))))+
          temp[1])));
        temp[3] = ((mk[11]*((Vpk[1][16][2]*Vpk[2][16][2])+((Vpk[1][16][0]*
          Vpk[2][16][0])+(Vpk[1][16][1]*Vpk[2][16][1]))))+((mk[10]*((
          Vpk[1][15][2]*Vpk[2][15][2])+((Vpk[1][15][0]*Vpk[2][15][0])+(
          Vpk[1][15][1]*Vpk[2][15][1]))))+((mk[9]*((Vpk[1][14][2]*Vpk[2][14][2])
          +((Vpk[1][14][0]*Vpk[2][14][0])+(Vpk[1][14][1]*Vpk[2][14][1]))))+
          temp[2])));
        mm[1][2] = ((mk[12]*((Vpk[1][17][2]*Vpk[2][17][2])+((Vpk[1][17][0]*
          Vpk[2][17][0])+(Vpk[1][17][1]*Vpk[2][17][1]))))+temp[3]);
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[3][8][2])+((Vpk[1][8][0]*
          Vpk[3][8][0])+(Vpk[1][8][1]*Vpk[3][8][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[3][7][2])+((Vpk[1][7][0]*Vpk[3][7][0])+(Vpk[1][7][1]*Vpk[3][7][1])
          )))+((mk[0]*((rk[0][2]*Vpk[1][3][1])-(rk[0][1]*Vpk[1][3][2])))+(mk[1]*
          ((Vpk[1][6][2]*Vpk[3][6][2])+((Vpk[1][6][0]*Vpk[3][6][0])+(
          Vpk[1][6][1]*Vpk[3][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[1][11][2]*Vpk[3][11][2])+((Vpk[1][11][0]*
          Vpk[3][11][0])+(Vpk[1][11][1]*Vpk[3][11][1]))))+((mk[5]*((
          Vpk[1][10][2]*Vpk[3][10][2])+((Vpk[1][10][0]*Vpk[3][10][0])+(
          Vpk[1][10][1]*Vpk[3][10][1]))))+((mk[4]*((Vpk[1][9][2]*Vpk[3][9][2])+(
          (Vpk[1][9][0]*Vpk[3][9][0])+(Vpk[1][9][1]*Vpk[3][9][1]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[1][14][2]*Vpk[3][14][2])+((Vpk[1][14][0]*
          Vpk[3][14][0])+(Vpk[1][14][1]*Vpk[3][14][1]))))+((mk[8]*((
          Vpk[1][13][2]*Vpk[3][13][2])+((Vpk[1][13][0]*Vpk[3][13][0])+(
          Vpk[1][13][1]*Vpk[3][13][1]))))+((mk[7]*((Vpk[1][12][2]*Vpk[3][12][2])
          +((Vpk[1][12][0]*Vpk[3][12][0])+(Vpk[1][12][1]*Vpk[3][12][1]))))+
          temp[1])));
        mm[1][3] = ((mk[12]*((Vpk[1][17][2]*Vpk[3][17][2])+((Vpk[1][17][0]*
          Vpk[3][17][0])+(Vpk[1][17][1]*Vpk[3][17][1]))))+((mk[11]*((
          Vpk[1][16][2]*Vpk[3][16][2])+((Vpk[1][16][0]*Vpk[3][16][0])+(
          Vpk[1][16][1]*Vpk[3][16][1]))))+((mk[10]*((Vpk[1][15][2]*Vpk[3][15][2]
          )+((Vpk[1][15][0]*Vpk[3][15][0])+(Vpk[1][15][1]*Vpk[3][15][1]))))+
          temp[2])));
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[4][8][2])+((Vpk[1][8][0]*
          Vpk[4][8][0])+(Vpk[1][8][1]*Vpk[4][8][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[4][7][2])+((Vpk[1][7][0]*Vpk[4][7][0])+(Vpk[1][7][1]*Vpk[4][7][1])
          )))+((mk[0]*((rk[0][0]*Vpk[1][3][2])-(rk[0][2]*Vpk[1][3][0])))+(mk[1]*
          ((Vpk[1][6][2]*Vpk[4][6][2])+((Vpk[1][6][0]*Vpk[4][6][0])+(
          Vpk[1][6][1]*Vpk[4][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[1][11][2]*Vpk[4][11][2])+((Vpk[1][11][0]*
          Vpk[4][11][0])+(Vpk[1][11][1]*Vpk[4][11][1]))))+((mk[5]*((
          Vpk[1][10][2]*Vpk[4][10][2])+((Vpk[1][10][0]*Vpk[4][10][0])+(
          Vpk[1][10][1]*Vpk[4][10][1]))))+((mk[4]*((Vpk[1][9][2]*Vpk[4][9][2])+(
          (Vpk[1][9][0]*Vpk[4][9][0])+(Vpk[1][9][1]*Vpk[4][9][1]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[1][14][2]*Vpk[4][14][2])+((Vpk[1][14][0]*
          Vpk[4][14][0])+(Vpk[1][14][1]*Vpk[4][14][1]))))+((mk[8]*((
          Vpk[1][13][2]*Vpk[4][13][2])+((Vpk[1][13][0]*Vpk[4][13][0])+(
          Vpk[1][13][1]*Vpk[4][13][1]))))+((mk[7]*((Vpk[1][12][2]*Vpk[4][12][2])
          +((Vpk[1][12][0]*Vpk[4][12][0])+(Vpk[1][12][1]*Vpk[4][12][1]))))+
          temp[1])));
        mm[1][4] = ((mk[12]*((Vpk[1][17][2]*Vpk[4][17][2])+((Vpk[1][17][0]*
          Vpk[4][17][0])+(Vpk[1][17][1]*Vpk[4][17][1]))))+((mk[11]*((
          Vpk[1][16][2]*Vpk[4][16][2])+((Vpk[1][16][0]*Vpk[4][16][0])+(
          Vpk[1][16][1]*Vpk[4][16][1]))))+((mk[10]*((Vpk[1][15][2]*Vpk[4][15][2]
          )+((Vpk[1][15][0]*Vpk[4][15][0])+(Vpk[1][15][1]*Vpk[4][15][1]))))+
          temp[2])));
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[5][8][2])+((Vpk[1][8][0]*
          Vpk[5][8][0])+(Vpk[1][8][1]*Vpk[5][8][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[5][7][2])+((Vpk[1][7][0]*Vpk[5][7][0])+(Vpk[1][7][1]*Vpk[5][7][1])
          )))+((mk[0]*((rk[0][1]*Vpk[1][3][0])-(rk[0][0]*Vpk[1][3][1])))+(mk[1]*
          ((Vpk[1][6][2]*Vpk[5][6][2])+((Vpk[1][6][0]*Vpk[5][6][0])+(
          Vpk[1][6][1]*Vpk[5][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[1][11][2]*Vpk[5][11][2])+((Vpk[1][11][0]*
          Vpk[5][11][0])+(Vpk[1][11][1]*Vpk[5][11][1]))))+((mk[5]*((
          Vpk[1][10][2]*Vpk[5][10][2])+((Vpk[1][10][0]*Vpk[5][10][0])+(
          Vpk[1][10][1]*Vpk[5][10][1]))))+((mk[4]*((Vpk[1][9][2]*Vpk[5][9][2])+(
          (Vpk[1][9][0]*Vpk[5][9][0])+(Vpk[1][9][1]*Vpk[5][9][1]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[1][14][2]*Vpk[5][14][2])+((Vpk[1][14][0]*
          Vpk[5][14][0])+(Vpk[1][14][1]*Vpk[5][14][1]))))+((mk[8]*((
          Vpk[1][13][2]*Vpk[5][13][2])+((Vpk[1][13][0]*Vpk[5][13][0])+(
          Vpk[1][13][1]*Vpk[5][13][1]))))+((mk[7]*((Vpk[1][12][2]*Vpk[5][12][2])
          +((Vpk[1][12][0]*Vpk[5][12][0])+(Vpk[1][12][1]*Vpk[5][12][1]))))+
          temp[1])));
        mm[1][5] = ((mk[12]*((Vpk[1][17][2]*Vpk[5][17][2])+((Vpk[1][17][0]*
          Vpk[5][17][0])+(Vpk[1][17][1]*Vpk[5][17][1]))))+((mk[11]*((
          Vpk[1][16][2]*Vpk[5][16][2])+((Vpk[1][16][0]*Vpk[5][16][0])+(
          Vpk[1][16][1]*Vpk[5][16][1]))))+((mk[10]*((Vpk[1][15][2]*Vpk[5][15][2]
          )+((Vpk[1][15][0]*Vpk[5][15][0])+(Vpk[1][15][1]*Vpk[5][15][1]))))+
          temp[2])));
        mm[1][6] = ((mk[3]*((Vpk[1][8][2]*Vpk[6][8][2])+((Vpk[1][8][0]*
          Vpk[6][8][0])+(Vpk[1][8][1]*Vpk[6][8][1]))))+((mk[1]*((Vpk[1][6][2]*
          Vpk[6][6][2])+((Vpk[1][6][0]*Vpk[6][6][0])+(Vpk[1][6][1]*Vpk[6][6][1])
          )))+(mk[2]*((Vpk[1][7][2]*Vpk[6][7][2])+((Vpk[1][7][0]*Vpk[6][7][0])+(
          Vpk[1][7][1]*Vpk[6][7][1]))))));
        mm[1][7] = ((mk[2]*((Vpk[1][7][2]*Vpk[7][7][2])+((Vpk[1][7][0]*
          Vpk[7][7][0])+(Vpk[1][7][1]*Vpk[7][7][1]))))+(mk[3]*((Vpk[1][8][2]*
          Vpk[7][8][2])+((Vpk[1][8][0]*Vpk[7][8][0])+(Vpk[1][8][1]*Vpk[7][8][1])
          ))));
        mm[1][8] = (mk[3]*((Vpk[1][8][2]*Vpk[8][8][2])+((Vpk[1][8][0]*
          Vpk[8][8][0])+(Vpk[1][8][1]*Vpk[8][8][1]))));
        mm[1][9] = ((mk[6]*((Vpk[1][11][2]*Vpk[9][11][2])+((Vpk[1][11][0]*
          Vpk[9][11][0])+(Vpk[1][11][1]*Vpk[9][11][1]))))+((mk[4]*((Vpk[1][9][2]
          *Vpk[9][9][2])+((Vpk[1][9][0]*Vpk[9][9][0])+(Vpk[1][9][1]*Vpk[9][9][1]
          ))))+(mk[5]*((Vpk[1][10][2]*Vpk[9][10][2])+((Vpk[1][10][0]*
          Vpk[9][10][0])+(Vpk[1][10][1]*Vpk[9][10][1]))))));
        mm[1][10] = ((mk[5]*((Vpk[1][10][2]*Vpk[10][10][2])+((Vpk[1][10][0]*
          Vpk[10][10][0])+(Vpk[1][10][1]*Vpk[10][10][1]))))+(mk[6]*((
          Vpk[1][11][2]*Vpk[10][11][2])+((Vpk[1][11][0]*Vpk[10][11][0])+(
          Vpk[1][11][1]*Vpk[10][11][1])))));
        mm[1][11] = (mk[6]*((Vpk[1][11][2]*Vpk[11][11][2])+((Vpk[1][11][0]*
          Vpk[11][11][0])+(Vpk[1][11][1]*Vpk[11][11][1]))));
        mm[1][12] = ((mk[9]*((Vpk[1][14][2]*Vpk[12][14][2])+((Vpk[1][14][0]*
          Vpk[12][14][0])+(Vpk[1][14][1]*Vpk[12][14][1]))))+((mk[7]*((
          Vpk[1][12][2]*Vpk[12][12][2])+((Vpk[1][12][0]*Vpk[12][12][0])+(
          Vpk[1][12][1]*Vpk[12][12][1]))))+(mk[8]*((Vpk[1][13][2]*Vpk[12][13][2]
          )+((Vpk[1][13][0]*Vpk[12][13][0])+(Vpk[1][13][1]*Vpk[12][13][1]))))));
        mm[1][13] = ((mk[8]*((Vpk[1][13][2]*Vpk[13][13][2])+((Vpk[1][13][0]*
          Vpk[13][13][0])+(Vpk[1][13][1]*Vpk[13][13][1]))))+(mk[9]*((
          Vpk[1][14][2]*Vpk[13][14][2])+((Vpk[1][14][0]*Vpk[13][14][0])+(
          Vpk[1][14][1]*Vpk[13][14][1])))));
        mm[1][14] = (mk[9]*((Vpk[1][14][2]*Vpk[14][14][2])+((Vpk[1][14][0]*
          Vpk[14][14][0])+(Vpk[1][14][1]*Vpk[14][14][1]))));
        mm[1][15] = ((mk[12]*((Vpk[1][17][2]*Vpk[15][17][2])+((Vpk[1][17][0]*
          Vpk[15][17][0])+(Vpk[1][17][1]*Vpk[15][17][1]))))+((mk[10]*((
          Vpk[1][15][2]*Vpk[15][15][2])+((Vpk[1][15][0]*Vpk[15][15][0])+(
          Vpk[1][15][1]*Vpk[15][15][1]))))+(mk[11]*((Vpk[1][16][2]*
          Vpk[15][16][2])+((Vpk[1][16][0]*Vpk[15][16][0])+(Vpk[1][16][1]*
          Vpk[15][16][1]))))));
        mm[1][16] = ((mk[11]*((Vpk[1][16][2]*Vpk[16][16][2])+((Vpk[1][16][0]*
          Vpk[16][16][0])+(Vpk[1][16][1]*Vpk[16][16][1]))))+(mk[12]*((
          Vpk[1][17][2]*Vpk[16][17][2])+((Vpk[1][17][0]*Vpk[16][17][0])+(
          Vpk[1][17][1]*Vpk[16][17][1])))));
        mm[1][17] = (mk[12]*((Vpk[1][17][2]*Vpk[17][17][2])+((Vpk[1][17][0]*
          Vpk[17][17][0])+(Vpk[1][17][1]*Vpk[17][17][1]))));
        temp[0] = ((mk[2]*((Vpk[2][7][2]*Vpk[2][7][2])+((Vpk[2][7][0]*
          Vpk[2][7][0])+(Vpk[2][7][1]*Vpk[2][7][1]))))+((mk[0]*((Vpk[2][3][2]*
          Vpk[2][3][2])+((Vpk[2][3][0]*Vpk[2][3][0])+(Vpk[2][3][1]*Vpk[2][3][1])
          )))+(mk[1]*((Vpk[2][6][2]*Vpk[2][6][2])+((Vpk[2][6][0]*Vpk[2][6][0])+(
          Vpk[2][6][1]*Vpk[2][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[2][10][2]*Vpk[2][10][2])+((Vpk[2][10][0]*
          Vpk[2][10][0])+(Vpk[2][10][1]*Vpk[2][10][1]))))+((mk[4]*((Vpk[2][9][2]
          *Vpk[2][9][2])+((Vpk[2][9][0]*Vpk[2][9][0])+(Vpk[2][9][1]*Vpk[2][9][1]
          ))))+((mk[3]*((Vpk[2][8][2]*Vpk[2][8][2])+((Vpk[2][8][0]*Vpk[2][8][0])
          +(Vpk[2][8][1]*Vpk[2][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[2][13][2]*Vpk[2][13][2])+((Vpk[2][13][0]*
          Vpk[2][13][0])+(Vpk[2][13][1]*Vpk[2][13][1]))))+((mk[7]*((
          Vpk[2][12][2]*Vpk[2][12][2])+((Vpk[2][12][0]*Vpk[2][12][0])+(
          Vpk[2][12][1]*Vpk[2][12][1]))))+((mk[6]*((Vpk[2][11][2]*Vpk[2][11][2])
          +((Vpk[2][11][0]*Vpk[2][11][0])+(Vpk[2][11][1]*Vpk[2][11][1]))))+
          temp[1])));
        temp[3] = ((mk[11]*((Vpk[2][16][2]*Vpk[2][16][2])+((Vpk[2][16][0]*
          Vpk[2][16][0])+(Vpk[2][16][1]*Vpk[2][16][1]))))+((mk[10]*((
          Vpk[2][15][2]*Vpk[2][15][2])+((Vpk[2][15][0]*Vpk[2][15][0])+(
          Vpk[2][15][1]*Vpk[2][15][1]))))+((mk[9]*((Vpk[2][14][2]*Vpk[2][14][2])
          +((Vpk[2][14][0]*Vpk[2][14][0])+(Vpk[2][14][1]*Vpk[2][14][1]))))+
          temp[2])));
        mm[2][2] = ((mk[12]*((Vpk[2][17][2]*Vpk[2][17][2])+((Vpk[2][17][0]*
          Vpk[2][17][0])+(Vpk[2][17][1]*Vpk[2][17][1]))))+temp[3]);
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[3][8][2])+((Vpk[2][8][0]*
          Vpk[3][8][0])+(Vpk[2][8][1]*Vpk[3][8][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[3][7][2])+((Vpk[2][7][0]*Vpk[3][7][0])+(Vpk[2][7][1]*Vpk[3][7][1])
          )))+((mk[0]*((rk[0][2]*Vpk[2][3][1])-(rk[0][1]*Vpk[2][3][2])))+(mk[1]*
          ((Vpk[2][6][2]*Vpk[3][6][2])+((Vpk[2][6][0]*Vpk[3][6][0])+(
          Vpk[2][6][1]*Vpk[3][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[2][11][2]*Vpk[3][11][2])+((Vpk[2][11][0]*
          Vpk[3][11][0])+(Vpk[2][11][1]*Vpk[3][11][1]))))+((mk[5]*((
          Vpk[2][10][2]*Vpk[3][10][2])+((Vpk[2][10][0]*Vpk[3][10][0])+(
          Vpk[2][10][1]*Vpk[3][10][1]))))+((mk[4]*((Vpk[2][9][2]*Vpk[3][9][2])+(
          (Vpk[2][9][0]*Vpk[3][9][0])+(Vpk[2][9][1]*Vpk[3][9][1]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[2][14][2]*Vpk[3][14][2])+((Vpk[2][14][0]*
          Vpk[3][14][0])+(Vpk[2][14][1]*Vpk[3][14][1]))))+((mk[8]*((
          Vpk[2][13][2]*Vpk[3][13][2])+((Vpk[2][13][0]*Vpk[3][13][0])+(
          Vpk[2][13][1]*Vpk[3][13][1]))))+((mk[7]*((Vpk[2][12][2]*Vpk[3][12][2])
          +((Vpk[2][12][0]*Vpk[3][12][0])+(Vpk[2][12][1]*Vpk[3][12][1]))))+
          temp[1])));
        mm[2][3] = ((mk[12]*((Vpk[2][17][2]*Vpk[3][17][2])+((Vpk[2][17][0]*
          Vpk[3][17][0])+(Vpk[2][17][1]*Vpk[3][17][1]))))+((mk[11]*((
          Vpk[2][16][2]*Vpk[3][16][2])+((Vpk[2][16][0]*Vpk[3][16][0])+(
          Vpk[2][16][1]*Vpk[3][16][1]))))+((mk[10]*((Vpk[2][15][2]*Vpk[3][15][2]
          )+((Vpk[2][15][0]*Vpk[3][15][0])+(Vpk[2][15][1]*Vpk[3][15][1]))))+
          temp[2])));
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[4][8][2])+((Vpk[2][8][0]*
          Vpk[4][8][0])+(Vpk[2][8][1]*Vpk[4][8][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[4][7][2])+((Vpk[2][7][0]*Vpk[4][7][0])+(Vpk[2][7][1]*Vpk[4][7][1])
          )))+((mk[0]*((rk[0][0]*Vpk[2][3][2])-(rk[0][2]*Vpk[2][3][0])))+(mk[1]*
          ((Vpk[2][6][2]*Vpk[4][6][2])+((Vpk[2][6][0]*Vpk[4][6][0])+(
          Vpk[2][6][1]*Vpk[4][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[2][11][2]*Vpk[4][11][2])+((Vpk[2][11][0]*
          Vpk[4][11][0])+(Vpk[2][11][1]*Vpk[4][11][1]))))+((mk[5]*((
          Vpk[2][10][2]*Vpk[4][10][2])+((Vpk[2][10][0]*Vpk[4][10][0])+(
          Vpk[2][10][1]*Vpk[4][10][1]))))+((mk[4]*((Vpk[2][9][2]*Vpk[4][9][2])+(
          (Vpk[2][9][0]*Vpk[4][9][0])+(Vpk[2][9][1]*Vpk[4][9][1]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[2][14][2]*Vpk[4][14][2])+((Vpk[2][14][0]*
          Vpk[4][14][0])+(Vpk[2][14][1]*Vpk[4][14][1]))))+((mk[8]*((
          Vpk[2][13][2]*Vpk[4][13][2])+((Vpk[2][13][0]*Vpk[4][13][0])+(
          Vpk[2][13][1]*Vpk[4][13][1]))))+((mk[7]*((Vpk[2][12][2]*Vpk[4][12][2])
          +((Vpk[2][12][0]*Vpk[4][12][0])+(Vpk[2][12][1]*Vpk[4][12][1]))))+
          temp[1])));
        mm[2][4] = ((mk[12]*((Vpk[2][17][2]*Vpk[4][17][2])+((Vpk[2][17][0]*
          Vpk[4][17][0])+(Vpk[2][17][1]*Vpk[4][17][1]))))+((mk[11]*((
          Vpk[2][16][2]*Vpk[4][16][2])+((Vpk[2][16][0]*Vpk[4][16][0])+(
          Vpk[2][16][1]*Vpk[4][16][1]))))+((mk[10]*((Vpk[2][15][2]*Vpk[4][15][2]
          )+((Vpk[2][15][0]*Vpk[4][15][0])+(Vpk[2][15][1]*Vpk[4][15][1]))))+
          temp[2])));
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[5][8][2])+((Vpk[2][8][0]*
          Vpk[5][8][0])+(Vpk[2][8][1]*Vpk[5][8][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[5][7][2])+((Vpk[2][7][0]*Vpk[5][7][0])+(Vpk[2][7][1]*Vpk[5][7][1])
          )))+((mk[0]*((rk[0][1]*Vpk[2][3][0])-(rk[0][0]*Vpk[2][3][1])))+(mk[1]*
          ((Vpk[2][6][2]*Vpk[5][6][2])+((Vpk[2][6][0]*Vpk[5][6][0])+(
          Vpk[2][6][1]*Vpk[5][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[2][11][2]*Vpk[5][11][2])+((Vpk[2][11][0]*
          Vpk[5][11][0])+(Vpk[2][11][1]*Vpk[5][11][1]))))+((mk[5]*((
          Vpk[2][10][2]*Vpk[5][10][2])+((Vpk[2][10][0]*Vpk[5][10][0])+(
          Vpk[2][10][1]*Vpk[5][10][1]))))+((mk[4]*((Vpk[2][9][2]*Vpk[5][9][2])+(
          (Vpk[2][9][0]*Vpk[5][9][0])+(Vpk[2][9][1]*Vpk[5][9][1]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[2][14][2]*Vpk[5][14][2])+((Vpk[2][14][0]*
          Vpk[5][14][0])+(Vpk[2][14][1]*Vpk[5][14][1]))))+((mk[8]*((
          Vpk[2][13][2]*Vpk[5][13][2])+((Vpk[2][13][0]*Vpk[5][13][0])+(
          Vpk[2][13][1]*Vpk[5][13][1]))))+((mk[7]*((Vpk[2][12][2]*Vpk[5][12][2])
          +((Vpk[2][12][0]*Vpk[5][12][0])+(Vpk[2][12][1]*Vpk[5][12][1]))))+
          temp[1])));
        mm[2][5] = ((mk[12]*((Vpk[2][17][2]*Vpk[5][17][2])+((Vpk[2][17][0]*
          Vpk[5][17][0])+(Vpk[2][17][1]*Vpk[5][17][1]))))+((mk[11]*((
          Vpk[2][16][2]*Vpk[5][16][2])+((Vpk[2][16][0]*Vpk[5][16][0])+(
          Vpk[2][16][1]*Vpk[5][16][1]))))+((mk[10]*((Vpk[2][15][2]*Vpk[5][15][2]
          )+((Vpk[2][15][0]*Vpk[5][15][0])+(Vpk[2][15][1]*Vpk[5][15][1]))))+
          temp[2])));
        mm[2][6] = ((mk[3]*((Vpk[2][8][2]*Vpk[6][8][2])+((Vpk[2][8][0]*
          Vpk[6][8][0])+(Vpk[2][8][1]*Vpk[6][8][1]))))+((mk[1]*((Vpk[2][6][2]*
          Vpk[6][6][2])+((Vpk[2][6][0]*Vpk[6][6][0])+(Vpk[2][6][1]*Vpk[6][6][1])
          )))+(mk[2]*((Vpk[2][7][2]*Vpk[6][7][2])+((Vpk[2][7][0]*Vpk[6][7][0])+(
          Vpk[2][7][1]*Vpk[6][7][1]))))));
        mm[2][7] = ((mk[2]*((Vpk[2][7][2]*Vpk[7][7][2])+((Vpk[2][7][0]*
          Vpk[7][7][0])+(Vpk[2][7][1]*Vpk[7][7][1]))))+(mk[3]*((Vpk[2][8][2]*
          Vpk[7][8][2])+((Vpk[2][8][0]*Vpk[7][8][0])+(Vpk[2][8][1]*Vpk[7][8][1])
          ))));
        mm[2][8] = (mk[3]*((Vpk[2][8][2]*Vpk[8][8][2])+((Vpk[2][8][0]*
          Vpk[8][8][0])+(Vpk[2][8][1]*Vpk[8][8][1]))));
        mm[2][9] = ((mk[6]*((Vpk[2][11][2]*Vpk[9][11][2])+((Vpk[2][11][0]*
          Vpk[9][11][0])+(Vpk[2][11][1]*Vpk[9][11][1]))))+((mk[4]*((Vpk[2][9][2]
          *Vpk[9][9][2])+((Vpk[2][9][0]*Vpk[9][9][0])+(Vpk[2][9][1]*Vpk[9][9][1]
          ))))+(mk[5]*((Vpk[2][10][2]*Vpk[9][10][2])+((Vpk[2][10][0]*
          Vpk[9][10][0])+(Vpk[2][10][1]*Vpk[9][10][1]))))));
        mm[2][10] = ((mk[5]*((Vpk[2][10][2]*Vpk[10][10][2])+((Vpk[2][10][0]*
          Vpk[10][10][0])+(Vpk[2][10][1]*Vpk[10][10][1]))))+(mk[6]*((
          Vpk[2][11][2]*Vpk[10][11][2])+((Vpk[2][11][0]*Vpk[10][11][0])+(
          Vpk[2][11][1]*Vpk[10][11][1])))));
        mm[2][11] = (mk[6]*((Vpk[2][11][2]*Vpk[11][11][2])+((Vpk[2][11][0]*
          Vpk[11][11][0])+(Vpk[2][11][1]*Vpk[11][11][1]))));
        mm[2][12] = ((mk[9]*((Vpk[2][14][2]*Vpk[12][14][2])+((Vpk[2][14][0]*
          Vpk[12][14][0])+(Vpk[2][14][1]*Vpk[12][14][1]))))+((mk[7]*((
          Vpk[2][12][2]*Vpk[12][12][2])+((Vpk[2][12][0]*Vpk[12][12][0])+(
          Vpk[2][12][1]*Vpk[12][12][1]))))+(mk[8]*((Vpk[2][13][2]*Vpk[12][13][2]
          )+((Vpk[2][13][0]*Vpk[12][13][0])+(Vpk[2][13][1]*Vpk[12][13][1]))))));
        mm[2][13] = ((mk[8]*((Vpk[2][13][2]*Vpk[13][13][2])+((Vpk[2][13][0]*
          Vpk[13][13][0])+(Vpk[2][13][1]*Vpk[13][13][1]))))+(mk[9]*((
          Vpk[2][14][2]*Vpk[13][14][2])+((Vpk[2][14][0]*Vpk[13][14][0])+(
          Vpk[2][14][1]*Vpk[13][14][1])))));
        mm[2][14] = (mk[9]*((Vpk[2][14][2]*Vpk[14][14][2])+((Vpk[2][14][0]*
          Vpk[14][14][0])+(Vpk[2][14][1]*Vpk[14][14][1]))));
        mm[2][15] = ((mk[12]*((Vpk[2][17][2]*Vpk[15][17][2])+((Vpk[2][17][0]*
          Vpk[15][17][0])+(Vpk[2][17][1]*Vpk[15][17][1]))))+((mk[10]*((
          Vpk[2][15][2]*Vpk[15][15][2])+((Vpk[2][15][0]*Vpk[15][15][0])+(
          Vpk[2][15][1]*Vpk[15][15][1]))))+(mk[11]*((Vpk[2][16][2]*
          Vpk[15][16][2])+((Vpk[2][16][0]*Vpk[15][16][0])+(Vpk[2][16][1]*
          Vpk[15][16][1]))))));
        mm[2][16] = ((mk[11]*((Vpk[2][16][2]*Vpk[16][16][2])+((Vpk[2][16][0]*
          Vpk[16][16][0])+(Vpk[2][16][1]*Vpk[16][16][1]))))+(mk[12]*((
          Vpk[2][17][2]*Vpk[16][17][2])+((Vpk[2][17][0]*Vpk[16][17][0])+(
          Vpk[2][17][1]*Vpk[16][17][1])))));
        mm[2][17] = (mk[12]*((Vpk[2][17][2]*Vpk[17][17][2])+((Vpk[2][17][0]*
          Vpk[17][17][0])+(Vpk[2][17][1]*Vpk[17][17][1]))));
        temp[0] = ((ik[0][0][0]+(mk[0]*((rk[0][1]*rk[0][1])+(rk[0][2]*rk[0][2]))
          ))+((mk[1]*((Vpk[3][6][2]*Vpk[3][6][2])+((Vpk[3][6][0]*Vpk[3][6][0])+(
          Vpk[3][6][1]*Vpk[3][6][1]))))+((Cik[6][0][2]*IkWpk[3][6][2])+((
          Cik[6][0][0]*IkWpk[3][6][0])+(Cik[6][0][1]*IkWpk[3][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[3][7][2]*Vpk[3][7][2])+((Vpk[3][7][0]*
          Vpk[3][7][0])+(Vpk[3][7][1]*Vpk[3][7][1]))))+((IkWpk[3][7][2]*
          Wpk[3][7][2])+((IkWpk[3][7][0]*Wpk[3][7][0])+(IkWpk[3][7][1]*
          Wpk[3][7][1])))));
        temp[2] = (((mk[3]*((Vpk[3][8][2]*Vpk[3][8][2])+((Vpk[3][8][0]*
          Vpk[3][8][0])+(Vpk[3][8][1]*Vpk[3][8][1]))))+((IkWpk[3][8][2]*
          Wpk[3][8][2])+((IkWpk[3][8][0]*Wpk[3][8][0])+(IkWpk[3][8][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((mk[4]*((Vpk[3][9][2]*Vpk[3][9][2])+((Vpk[3][9][0]*
          Vpk[3][9][0])+(Vpk[3][9][1]*Vpk[3][9][1]))))+((Cik[9][0][2]*
          IkWpk[3][9][2])+((Cik[9][0][0]*IkWpk[3][9][0])+(Cik[9][0][1]*
          IkWpk[3][9][1]))))+temp[2]);
        temp[4] = (((mk[5]*((Vpk[3][10][2]*Vpk[3][10][2])+((Vpk[3][10][0]*
          Vpk[3][10][0])+(Vpk[3][10][1]*Vpk[3][10][1]))))+((IkWpk[3][10][2]*
          Wpk[3][10][2])+((IkWpk[3][10][0]*Wpk[3][10][0])+(IkWpk[3][10][1]*
          Wpk[3][10][1]))))+temp[3]);
        temp[5] = (((mk[6]*((Vpk[3][11][2]*Vpk[3][11][2])+((Vpk[3][11][0]*
          Vpk[3][11][0])+(Vpk[3][11][1]*Vpk[3][11][1]))))+((IkWpk[3][11][2]*
          Wpk[3][11][2])+((IkWpk[3][11][0]*Wpk[3][11][0])+(IkWpk[3][11][1]*
          Wpk[3][11][1]))))+temp[4]);
        temp[6] = (((mk[7]*((Vpk[3][12][2]*Vpk[3][12][2])+((Vpk[3][12][0]*
          Vpk[3][12][0])+(Vpk[3][12][1]*Vpk[3][12][1]))))+((Cik[12][0][2]*
          IkWpk[3][12][2])+((Cik[12][0][0]*IkWpk[3][12][0])+(Cik[12][0][1]*
          IkWpk[3][12][1]))))+temp[5]);
        temp[7] = (((mk[8]*((Vpk[3][13][2]*Vpk[3][13][2])+((Vpk[3][13][0]*
          Vpk[3][13][0])+(Vpk[3][13][1]*Vpk[3][13][1]))))+((IkWpk[3][13][2]*
          Wpk[3][13][2])+((IkWpk[3][13][0]*Wpk[3][13][0])+(IkWpk[3][13][1]*
          Wpk[3][13][1]))))+temp[6]);
        temp[8] = (((mk[9]*((Vpk[3][14][2]*Vpk[3][14][2])+((Vpk[3][14][0]*
          Vpk[3][14][0])+(Vpk[3][14][1]*Vpk[3][14][1]))))+((IkWpk[3][14][2]*
          Wpk[3][14][2])+((IkWpk[3][14][0]*Wpk[3][14][0])+(IkWpk[3][14][1]*
          Wpk[3][14][1]))))+temp[7]);
        temp[9] = (((mk[10]*((Vpk[3][15][2]*Vpk[3][15][2])+((Vpk[3][15][0]*
          Vpk[3][15][0])+(Vpk[3][15][1]*Vpk[3][15][1]))))+((Cik[15][0][2]*
          IkWpk[3][15][2])+((Cik[15][0][0]*IkWpk[3][15][0])+(Cik[15][0][1]*
          IkWpk[3][15][1]))))+temp[8]);
        temp[10] = (((mk[11]*((Vpk[3][16][2]*Vpk[3][16][2])+((Vpk[3][16][0]*
          Vpk[3][16][0])+(Vpk[3][16][1]*Vpk[3][16][1]))))+((IkWpk[3][16][2]*
          Wpk[3][16][2])+((IkWpk[3][16][0]*Wpk[3][16][0])+(IkWpk[3][16][1]*
          Wpk[3][16][1]))))+temp[9]);
        mm[3][3] = (((mk[12]*((Vpk[3][17][2]*Vpk[3][17][2])+((Vpk[3][17][0]*
          Vpk[3][17][0])+(Vpk[3][17][1]*Vpk[3][17][1]))))+((IkWpk[3][17][2]*
          Wpk[3][17][2])+((IkWpk[3][17][0]*Wpk[3][17][0])+(IkWpk[3][17][1]*
          Wpk[3][17][1]))))+temp[10]);
        temp[0] = ((ik[0][0][1]-(mk[0]*(rk[0][0]*rk[0][1])))+((mk[1]*((
          Vpk[3][6][2]*Vpk[4][6][2])+((Vpk[3][6][0]*Vpk[4][6][0])+(Vpk[3][6][1]*
          Vpk[4][6][1]))))+((Cik[6][0][2]*IkWpk[4][6][2])+((Cik[6][0][0]*
          IkWpk[4][6][0])+(Cik[6][0][1]*IkWpk[4][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[3][7][2]*Vpk[4][7][2])+((Vpk[3][7][0]*
          Vpk[4][7][0])+(Vpk[3][7][1]*Vpk[4][7][1]))))+((IkWpk[4][7][2]*
          Wpk[3][7][2])+((IkWpk[4][7][0]*Wpk[3][7][0])+(IkWpk[4][7][1]*
          Wpk[3][7][1])))));
        temp[2] = (((mk[3]*((Vpk[3][8][2]*Vpk[4][8][2])+((Vpk[3][8][0]*
          Vpk[4][8][0])+(Vpk[3][8][1]*Vpk[4][8][1]))))+((IkWpk[4][8][2]*
          Wpk[3][8][2])+((IkWpk[4][8][0]*Wpk[3][8][0])+(IkWpk[4][8][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((mk[4]*((Vpk[3][9][2]*Vpk[4][9][2])+((Vpk[3][9][0]*
          Vpk[4][9][0])+(Vpk[3][9][1]*Vpk[4][9][1]))))+((Cik[9][0][2]*
          IkWpk[4][9][2])+((Cik[9][0][0]*IkWpk[4][9][0])+(Cik[9][0][1]*
          IkWpk[4][9][1]))))+temp[2]);
        temp[4] = (((mk[5]*((Vpk[3][10][2]*Vpk[4][10][2])+((Vpk[3][10][0]*
          Vpk[4][10][0])+(Vpk[3][10][1]*Vpk[4][10][1]))))+((IkWpk[4][10][2]*
          Wpk[3][10][2])+((IkWpk[4][10][0]*Wpk[3][10][0])+(IkWpk[4][10][1]*
          Wpk[3][10][1]))))+temp[3]);
        temp[5] = (((mk[6]*((Vpk[3][11][2]*Vpk[4][11][2])+((Vpk[3][11][0]*
          Vpk[4][11][0])+(Vpk[3][11][1]*Vpk[4][11][1]))))+((IkWpk[4][11][2]*
          Wpk[3][11][2])+((IkWpk[4][11][0]*Wpk[3][11][0])+(IkWpk[4][11][1]*
          Wpk[3][11][1]))))+temp[4]);
        temp[6] = (((mk[7]*((Vpk[3][12][2]*Vpk[4][12][2])+((Vpk[3][12][0]*
          Vpk[4][12][0])+(Vpk[3][12][1]*Vpk[4][12][1]))))+((Cik[12][0][2]*
          IkWpk[4][12][2])+((Cik[12][0][0]*IkWpk[4][12][0])+(Cik[12][0][1]*
          IkWpk[4][12][1]))))+temp[5]);
        temp[7] = (((mk[8]*((Vpk[3][13][2]*Vpk[4][13][2])+((Vpk[3][13][0]*
          Vpk[4][13][0])+(Vpk[3][13][1]*Vpk[4][13][1]))))+((IkWpk[4][13][2]*
          Wpk[3][13][2])+((IkWpk[4][13][0]*Wpk[3][13][0])+(IkWpk[4][13][1]*
          Wpk[3][13][1]))))+temp[6]);
        temp[8] = (((mk[9]*((Vpk[3][14][2]*Vpk[4][14][2])+((Vpk[3][14][0]*
          Vpk[4][14][0])+(Vpk[3][14][1]*Vpk[4][14][1]))))+((IkWpk[4][14][2]*
          Wpk[3][14][2])+((IkWpk[4][14][0]*Wpk[3][14][0])+(IkWpk[4][14][1]*
          Wpk[3][14][1]))))+temp[7]);
        temp[9] = (((mk[10]*((Vpk[3][15][2]*Vpk[4][15][2])+((Vpk[3][15][0]*
          Vpk[4][15][0])+(Vpk[3][15][1]*Vpk[4][15][1]))))+((Cik[15][0][2]*
          IkWpk[4][15][2])+((Cik[15][0][0]*IkWpk[4][15][0])+(Cik[15][0][1]*
          IkWpk[4][15][1]))))+temp[8]);
        temp[10] = (((mk[11]*((Vpk[3][16][2]*Vpk[4][16][2])+((Vpk[3][16][0]*
          Vpk[4][16][0])+(Vpk[3][16][1]*Vpk[4][16][1]))))+((IkWpk[4][16][2]*
          Wpk[3][16][2])+((IkWpk[4][16][0]*Wpk[3][16][0])+(IkWpk[4][16][1]*
          Wpk[3][16][1]))))+temp[9]);
        mm[3][4] = (((mk[12]*((Vpk[3][17][2]*Vpk[4][17][2])+((Vpk[3][17][0]*
          Vpk[4][17][0])+(Vpk[3][17][1]*Vpk[4][17][1]))))+((IkWpk[4][17][2]*
          Wpk[3][17][2])+((IkWpk[4][17][0]*Wpk[3][17][0])+(IkWpk[4][17][1]*
          Wpk[3][17][1]))))+temp[10]);
        temp[0] = ((ik[0][0][2]-(mk[0]*(rk[0][0]*rk[0][2])))+((mk[1]*((
          Vpk[3][6][2]*Vpk[5][6][2])+((Vpk[3][6][0]*Vpk[5][6][0])+(Vpk[3][6][1]*
          Vpk[5][6][1]))))+((Cik[6][0][2]*IkWpk[5][6][2])+((Cik[6][0][0]*
          IkWpk[5][6][0])+(Cik[6][0][1]*IkWpk[5][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[3][7][2]*Vpk[5][7][2])+((Vpk[3][7][0]*
          Vpk[5][7][0])+(Vpk[3][7][1]*Vpk[5][7][1]))))+((IkWpk[5][7][2]*
          Wpk[3][7][2])+((IkWpk[5][7][0]*Wpk[3][7][0])+(IkWpk[5][7][1]*
          Wpk[3][7][1])))));
        temp[2] = (((mk[3]*((Vpk[3][8][2]*Vpk[5][8][2])+((Vpk[3][8][0]*
          Vpk[5][8][0])+(Vpk[3][8][1]*Vpk[5][8][1]))))+((IkWpk[5][8][2]*
          Wpk[3][8][2])+((IkWpk[5][8][0]*Wpk[3][8][0])+(IkWpk[5][8][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((mk[4]*((Vpk[3][9][2]*Vpk[5][9][2])+((Vpk[3][9][0]*
          Vpk[5][9][0])+(Vpk[3][9][1]*Vpk[5][9][1]))))+((Cik[9][0][2]*
          IkWpk[5][9][2])+((Cik[9][0][0]*IkWpk[5][9][0])+(Cik[9][0][1]*
          IkWpk[5][9][1]))))+temp[2]);
        temp[4] = (((mk[5]*((Vpk[3][10][2]*Vpk[5][10][2])+((Vpk[3][10][0]*
          Vpk[5][10][0])+(Vpk[3][10][1]*Vpk[5][10][1]))))+((IkWpk[5][10][2]*
          Wpk[3][10][2])+((IkWpk[5][10][0]*Wpk[3][10][0])+(IkWpk[5][10][1]*
          Wpk[3][10][1]))))+temp[3]);
        temp[5] = (((mk[6]*((Vpk[3][11][2]*Vpk[5][11][2])+((Vpk[3][11][0]*
          Vpk[5][11][0])+(Vpk[3][11][1]*Vpk[5][11][1]))))+((IkWpk[5][11][2]*
          Wpk[3][11][2])+((IkWpk[5][11][0]*Wpk[3][11][0])+(IkWpk[5][11][1]*
          Wpk[3][11][1]))))+temp[4]);
        temp[6] = (((mk[7]*((Vpk[3][12][2]*Vpk[5][12][2])+((Vpk[3][12][0]*
          Vpk[5][12][0])+(Vpk[3][12][1]*Vpk[5][12][1]))))+((Cik[12][0][2]*
          IkWpk[5][12][2])+((Cik[12][0][0]*IkWpk[5][12][0])+(Cik[12][0][1]*
          IkWpk[5][12][1]))))+temp[5]);
        temp[7] = (((mk[8]*((Vpk[3][13][2]*Vpk[5][13][2])+((Vpk[3][13][0]*
          Vpk[5][13][0])+(Vpk[3][13][1]*Vpk[5][13][1]))))+((IkWpk[5][13][2]*
          Wpk[3][13][2])+((IkWpk[5][13][0]*Wpk[3][13][0])+(IkWpk[5][13][1]*
          Wpk[3][13][1]))))+temp[6]);
        temp[8] = (((mk[9]*((Vpk[3][14][2]*Vpk[5][14][2])+((Vpk[3][14][0]*
          Vpk[5][14][0])+(Vpk[3][14][1]*Vpk[5][14][1]))))+((IkWpk[5][14][2]*
          Wpk[3][14][2])+((IkWpk[5][14][0]*Wpk[3][14][0])+(IkWpk[5][14][1]*
          Wpk[3][14][1]))))+temp[7]);
        temp[9] = (((mk[10]*((Vpk[3][15][2]*Vpk[5][15][2])+((Vpk[3][15][0]*
          Vpk[5][15][0])+(Vpk[3][15][1]*Vpk[5][15][1]))))+((Cik[15][0][2]*
          IkWpk[5][15][2])+((Cik[15][0][0]*IkWpk[5][15][0])+(Cik[15][0][1]*
          IkWpk[5][15][1]))))+temp[8]);
        temp[10] = (((mk[11]*((Vpk[3][16][2]*Vpk[5][16][2])+((Vpk[3][16][0]*
          Vpk[5][16][0])+(Vpk[3][16][1]*Vpk[5][16][1]))))+((IkWpk[5][16][2]*
          Wpk[3][16][2])+((IkWpk[5][16][0]*Wpk[3][16][0])+(IkWpk[5][16][1]*
          Wpk[3][16][1]))))+temp[9]);
        mm[3][5] = (((mk[12]*((Vpk[3][17][2]*Vpk[5][17][2])+((Vpk[3][17][0]*
          Vpk[5][17][0])+(Vpk[3][17][1]*Vpk[5][17][1]))))+((IkWpk[5][17][2]*
          Wpk[3][17][2])+((IkWpk[5][17][0]*Wpk[3][17][0])+(IkWpk[5][17][1]*
          Wpk[3][17][1]))))+temp[10]);
        temp[0] = (((mk[1]*((Vpk[3][6][2]*Vpk[6][6][2])+((Vpk[3][6][0]*
          Vpk[6][6][0])+(Vpk[3][6][1]*Vpk[6][6][1]))))+((Cik[6][0][2]*
          IkWpk[6][6][2])+((Cik[6][0][0]*IkWpk[6][6][0])+(Cik[6][0][1]*
          IkWpk[6][6][1]))))+((mk[2]*((Vpk[3][7][2]*Vpk[6][7][2])+((Vpk[3][7][0]
          *Vpk[6][7][0])+(Vpk[3][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*
          Wpk[3][7][2])+((IkWpk[6][7][0]*Wpk[3][7][0])+(IkWpk[6][7][1]*
          Wpk[3][7][1])))));
        mm[3][6] = (((mk[3]*((Vpk[3][8][2]*Vpk[6][8][2])+((Vpk[3][8][0]*
          Vpk[6][8][0])+(Vpk[3][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[3][8][2])+((IkWpk[6][8][0]*Wpk[3][8][0])+(IkWpk[6][8][1]*
          Wpk[3][8][1]))))+temp[0]);
        mm[3][7] = (((mk[2]*((Vpk[3][7][2]*Vpk[7][7][2])+((Vpk[3][7][0]*
          Vpk[7][7][0])+(Vpk[3][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          Wpk[3][7][2])+((IkWpk[7][7][0]*Wpk[3][7][0])+(IkWpk[7][7][1]*
          Wpk[3][7][1]))))+((mk[3]*((Vpk[3][8][2]*Vpk[7][8][2])+((Vpk[3][8][0]*
          Vpk[7][8][0])+(Vpk[3][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*
          Wpk[3][8][2])+((IkWpk[7][8][0]*Wpk[3][8][0])+(IkWpk[7][8][1]*
          Wpk[3][8][1])))));
        mm[3][8] = ((mk[3]*((Vpk[3][8][2]*Vpk[8][8][2])+((Vpk[3][8][0]*
          Vpk[8][8][0])+(Vpk[3][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[3][8][2])+((IkWpk[8][8][0]*Wpk[3][8][0])+(IkWpk[8][8][1]*
          Wpk[3][8][1]))));
        temp[0] = (((mk[4]*((Vpk[3][9][2]*Vpk[9][9][2])+((Vpk[3][9][0]*
          Vpk[9][9][0])+(Vpk[3][9][1]*Vpk[9][9][1]))))+((Cik[9][0][2]*
          IkWpk[9][9][2])+((Cik[9][0][0]*IkWpk[9][9][0])+(Cik[9][0][1]*
          IkWpk[9][9][1]))))+((mk[5]*((Vpk[3][10][2]*Vpk[9][10][2])+((
          Vpk[3][10][0]*Vpk[9][10][0])+(Vpk[3][10][1]*Vpk[9][10][1]))))+((
          IkWpk[9][10][2]*Wpk[3][10][2])+((IkWpk[9][10][0]*Wpk[3][10][0])+(
          IkWpk[9][10][1]*Wpk[3][10][1])))));
        mm[3][9] = (((mk[6]*((Vpk[3][11][2]*Vpk[9][11][2])+((Vpk[3][11][0]*
          Vpk[9][11][0])+(Vpk[3][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[3][11][2])+((IkWpk[9][11][0]*Wpk[3][11][0])+(IkWpk[9][11][1]*
          Wpk[3][11][1]))))+temp[0]);
        mm[3][10] = (((mk[5]*((Vpk[3][10][2]*Vpk[10][10][2])+((Vpk[3][10][0]*
          Vpk[10][10][0])+(Vpk[3][10][1]*Vpk[10][10][1]))))+((IkWpk[10][10][2]*
          Wpk[3][10][2])+((IkWpk[10][10][0]*Wpk[3][10][0])+(IkWpk[10][10][1]*
          Wpk[3][10][1]))))+((mk[6]*((Vpk[3][11][2]*Vpk[10][11][2])+((
          Vpk[3][11][0]*Vpk[10][11][0])+(Vpk[3][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[3][11][2])+((IkWpk[10][11][0]*Wpk[3][11][0])+(
          IkWpk[10][11][1]*Wpk[3][11][1])))));
        mm[3][11] = ((mk[6]*((Vpk[3][11][2]*Vpk[11][11][2])+((Vpk[3][11][0]*
          Vpk[11][11][0])+(Vpk[3][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          Wpk[3][11][2])+((IkWpk[11][11][0]*Wpk[3][11][0])+(IkWpk[11][11][1]*
          Wpk[3][11][1]))));
        temp[0] = (((mk[7]*((Vpk[3][12][2]*Vpk[12][12][2])+((Vpk[3][12][0]*
          Vpk[12][12][0])+(Vpk[3][12][1]*Vpk[12][12][1]))))+((Cik[12][0][2]*
          IkWpk[12][12][2])+((Cik[12][0][0]*IkWpk[12][12][0])+(Cik[12][0][1]*
          IkWpk[12][12][1]))))+((mk[8]*((Vpk[3][13][2]*Vpk[12][13][2])+((
          Vpk[3][13][0]*Vpk[12][13][0])+(Vpk[3][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[3][13][2])+((IkWpk[12][13][0]*Wpk[3][13][0])+(
          IkWpk[12][13][1]*Wpk[3][13][1])))));
        mm[3][12] = (((mk[9]*((Vpk[3][14][2]*Vpk[12][14][2])+((Vpk[3][14][0]*
          Vpk[12][14][0])+(Vpk[3][14][1]*Vpk[12][14][1]))))+((IkWpk[12][14][2]*
          Wpk[3][14][2])+((IkWpk[12][14][0]*Wpk[3][14][0])+(IkWpk[12][14][1]*
          Wpk[3][14][1]))))+temp[0]);
        mm[3][13] = (((mk[8]*((Vpk[3][13][2]*Vpk[13][13][2])+((Vpk[3][13][0]*
          Vpk[13][13][0])+(Vpk[3][13][1]*Vpk[13][13][1]))))+((IkWpk[13][13][2]*
          Wpk[3][13][2])+((IkWpk[13][13][0]*Wpk[3][13][0])+(IkWpk[13][13][1]*
          Wpk[3][13][1]))))+((mk[9]*((Vpk[3][14][2]*Vpk[13][14][2])+((
          Vpk[3][14][0]*Vpk[13][14][0])+(Vpk[3][14][1]*Vpk[13][14][1]))))+((
          IkWpk[13][14][2]*Wpk[3][14][2])+((IkWpk[13][14][0]*Wpk[3][14][0])+(
          IkWpk[13][14][1]*Wpk[3][14][1])))));
        mm[3][14] = ((mk[9]*((Vpk[3][14][2]*Vpk[14][14][2])+((Vpk[3][14][0]*
          Vpk[14][14][0])+(Vpk[3][14][1]*Vpk[14][14][1]))))+((IkWpk[14][14][2]*
          Wpk[3][14][2])+((IkWpk[14][14][0]*Wpk[3][14][0])+(IkWpk[14][14][1]*
          Wpk[3][14][1]))));
        temp[0] = (((mk[10]*((Vpk[3][15][2]*Vpk[15][15][2])+((Vpk[3][15][0]*
          Vpk[15][15][0])+(Vpk[3][15][1]*Vpk[15][15][1]))))+((Cik[15][0][2]*
          IkWpk[15][15][2])+((Cik[15][0][0]*IkWpk[15][15][0])+(Cik[15][0][1]*
          IkWpk[15][15][1]))))+((mk[11]*((Vpk[3][16][2]*Vpk[15][16][2])+((
          Vpk[3][16][0]*Vpk[15][16][0])+(Vpk[3][16][1]*Vpk[15][16][1]))))+((
          IkWpk[15][16][2]*Wpk[3][16][2])+((IkWpk[15][16][0]*Wpk[3][16][0])+(
          IkWpk[15][16][1]*Wpk[3][16][1])))));
        mm[3][15] = (((mk[12]*((Vpk[3][17][2]*Vpk[15][17][2])+((Vpk[3][17][0]*
          Vpk[15][17][0])+(Vpk[3][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]*
          Wpk[3][17][2])+((IkWpk[15][17][0]*Wpk[3][17][0])+(IkWpk[15][17][1]*
          Wpk[3][17][1]))))+temp[0]);
        mm[3][16] = (((mk[11]*((Vpk[3][16][2]*Vpk[16][16][2])+((Vpk[3][16][0]*
          Vpk[16][16][0])+(Vpk[3][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]*
          Wpk[3][16][2])+((IkWpk[16][16][0]*Wpk[3][16][0])+(IkWpk[16][16][1]*
          Wpk[3][16][1]))))+((mk[12]*((Vpk[3][17][2]*Vpk[16][17][2])+((
          Vpk[3][17][0]*Vpk[16][17][0])+(Vpk[3][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[3][17][2])+((IkWpk[16][17][0]*Wpk[3][17][0])+(
          IkWpk[16][17][1]*Wpk[3][17][1])))));
        mm[3][17] = ((mk[12]*((Vpk[3][17][2]*Vpk[17][17][2])+((Vpk[3][17][0]*
          Vpk[17][17][0])+(Vpk[3][17][1]*Vpk[17][17][1]))))+((IkWpk[17][17][2]*
          Wpk[3][17][2])+((IkWpk[17][17][0]*Wpk[3][17][0])+(IkWpk[17][17][1]*
          Wpk[3][17][1]))));
        temp[0] = ((ik[0][1][1]+(mk[0]*((rk[0][0]*rk[0][0])+(rk[0][2]*rk[0][2]))
          ))+((mk[1]*((Vpk[4][6][2]*Vpk[4][6][2])+((Vpk[4][6][0]*Vpk[4][6][0])+(
          Vpk[4][6][1]*Vpk[4][6][1]))))+((Cik[6][1][2]*IkWpk[4][6][2])+((
          Cik[6][1][0]*IkWpk[4][6][0])+(Cik[6][1][1]*IkWpk[4][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[4][7][2]*Vpk[4][7][2])+((Vpk[4][7][0]*
          Vpk[4][7][0])+(Vpk[4][7][1]*Vpk[4][7][1]))))+((IkWpk[4][7][2]*
          Wpk[4][7][2])+((IkWpk[4][7][0]*Wpk[4][7][0])+(IkWpk[4][7][1]*
          Wpk[4][7][1])))));
        temp[2] = (((mk[3]*((Vpk[4][8][2]*Vpk[4][8][2])+((Vpk[4][8][0]*
          Vpk[4][8][0])+(Vpk[4][8][1]*Vpk[4][8][1]))))+((IkWpk[4][8][2]*
          Wpk[4][8][2])+((IkWpk[4][8][0]*Wpk[4][8][0])+(IkWpk[4][8][1]*
          Wpk[4][8][1]))))+temp[1]);
        temp[3] = (((mk[4]*((Vpk[4][9][2]*Vpk[4][9][2])+((Vpk[4][9][0]*
          Vpk[4][9][0])+(Vpk[4][9][1]*Vpk[4][9][1]))))+((Cik[9][1][2]*
          IkWpk[4][9][2])+((Cik[9][1][0]*IkWpk[4][9][0])+(Cik[9][1][1]*
          IkWpk[4][9][1]))))+temp[2]);
        temp[4] = (((mk[5]*((Vpk[4][10][2]*Vpk[4][10][2])+((Vpk[4][10][0]*
          Vpk[4][10][0])+(Vpk[4][10][1]*Vpk[4][10][1]))))+((IkWpk[4][10][2]*
          Wpk[4][10][2])+((IkWpk[4][10][0]*Wpk[4][10][0])+(IkWpk[4][10][1]*
          Wpk[4][10][1]))))+temp[3]);
        temp[5] = (((mk[6]*((Vpk[4][11][2]*Vpk[4][11][2])+((Vpk[4][11][0]*
          Vpk[4][11][0])+(Vpk[4][11][1]*Vpk[4][11][1]))))+((IkWpk[4][11][2]*
          Wpk[4][11][2])+((IkWpk[4][11][0]*Wpk[4][11][0])+(IkWpk[4][11][1]*
          Wpk[4][11][1]))))+temp[4]);
        temp[6] = (((mk[7]*((Vpk[4][12][2]*Vpk[4][12][2])+((Vpk[4][12][0]*
          Vpk[4][12][0])+(Vpk[4][12][1]*Vpk[4][12][1]))))+((Cik[12][1][2]*
          IkWpk[4][12][2])+((Cik[12][1][0]*IkWpk[4][12][0])+(Cik[12][1][1]*
          IkWpk[4][12][1]))))+temp[5]);
        temp[7] = (((mk[8]*((Vpk[4][13][2]*Vpk[4][13][2])+((Vpk[4][13][0]*
          Vpk[4][13][0])+(Vpk[4][13][1]*Vpk[4][13][1]))))+((IkWpk[4][13][2]*
          Wpk[4][13][2])+((IkWpk[4][13][0]*Wpk[4][13][0])+(IkWpk[4][13][1]*
          Wpk[4][13][1]))))+temp[6]);
        temp[8] = (((mk[9]*((Vpk[4][14][2]*Vpk[4][14][2])+((Vpk[4][14][0]*
          Vpk[4][14][0])+(Vpk[4][14][1]*Vpk[4][14][1]))))+((IkWpk[4][14][2]*
          Wpk[4][14][2])+((IkWpk[4][14][0]*Wpk[4][14][0])+(IkWpk[4][14][1]*
          Wpk[4][14][1]))))+temp[7]);
        temp[9] = (((mk[10]*((Vpk[4][15][2]*Vpk[4][15][2])+((Vpk[4][15][0]*
          Vpk[4][15][0])+(Vpk[4][15][1]*Vpk[4][15][1]))))+((Cik[15][1][2]*
          IkWpk[4][15][2])+((Cik[15][1][0]*IkWpk[4][15][0])+(Cik[15][1][1]*
          IkWpk[4][15][1]))))+temp[8]);
        temp[10] = (((mk[11]*((Vpk[4][16][2]*Vpk[4][16][2])+((Vpk[4][16][0]*
          Vpk[4][16][0])+(Vpk[4][16][1]*Vpk[4][16][1]))))+((IkWpk[4][16][2]*
          Wpk[4][16][2])+((IkWpk[4][16][0]*Wpk[4][16][0])+(IkWpk[4][16][1]*
          Wpk[4][16][1]))))+temp[9]);
        mm[4][4] = (((mk[12]*((Vpk[4][17][2]*Vpk[4][17][2])+((Vpk[4][17][0]*
          Vpk[4][17][0])+(Vpk[4][17][1]*Vpk[4][17][1]))))+((IkWpk[4][17][2]*
          Wpk[4][17][2])+((IkWpk[4][17][0]*Wpk[4][17][0])+(IkWpk[4][17][1]*
          Wpk[4][17][1]))))+temp[10]);
        temp[0] = ((ik[0][1][2]-(mk[0]*(rk[0][1]*rk[0][2])))+((mk[1]*((
          Vpk[4][6][2]*Vpk[5][6][2])+((Vpk[4][6][0]*Vpk[5][6][0])+(Vpk[4][6][1]*
          Vpk[5][6][1]))))+((Cik[6][1][2]*IkWpk[5][6][2])+((Cik[6][1][0]*
          IkWpk[5][6][0])+(Cik[6][1][1]*IkWpk[5][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[4][7][2]*Vpk[5][7][2])+((Vpk[4][7][0]*
          Vpk[5][7][0])+(Vpk[4][7][1]*Vpk[5][7][1]))))+((IkWpk[5][7][2]*
          Wpk[4][7][2])+((IkWpk[5][7][0]*Wpk[4][7][0])+(IkWpk[5][7][1]*
          Wpk[4][7][1])))));
        temp[2] = (((mk[3]*((Vpk[4][8][2]*Vpk[5][8][2])+((Vpk[4][8][0]*
          Vpk[5][8][0])+(Vpk[4][8][1]*Vpk[5][8][1]))))+((IkWpk[5][8][2]*
          Wpk[4][8][2])+((IkWpk[5][8][0]*Wpk[4][8][0])+(IkWpk[5][8][1]*
          Wpk[4][8][1]))))+temp[1]);
        temp[3] = (((mk[4]*((Vpk[4][9][2]*Vpk[5][9][2])+((Vpk[4][9][0]*
          Vpk[5][9][0])+(Vpk[4][9][1]*Vpk[5][9][1]))))+((Cik[9][1][2]*
          IkWpk[5][9][2])+((Cik[9][1][0]*IkWpk[5][9][0])+(Cik[9][1][1]*
          IkWpk[5][9][1]))))+temp[2]);
        temp[4] = (((mk[5]*((Vpk[4][10][2]*Vpk[5][10][2])+((Vpk[4][10][0]*
          Vpk[5][10][0])+(Vpk[4][10][1]*Vpk[5][10][1]))))+((IkWpk[5][10][2]*
          Wpk[4][10][2])+((IkWpk[5][10][0]*Wpk[4][10][0])+(IkWpk[5][10][1]*
          Wpk[4][10][1]))))+temp[3]);
        temp[5] = (((mk[6]*((Vpk[4][11][2]*Vpk[5][11][2])+((Vpk[4][11][0]*
          Vpk[5][11][0])+(Vpk[4][11][1]*Vpk[5][11][1]))))+((IkWpk[5][11][2]*
          Wpk[4][11][2])+((IkWpk[5][11][0]*Wpk[4][11][0])+(IkWpk[5][11][1]*
          Wpk[4][11][1]))))+temp[4]);
        temp[6] = (((mk[7]*((Vpk[4][12][2]*Vpk[5][12][2])+((Vpk[4][12][0]*
          Vpk[5][12][0])+(Vpk[4][12][1]*Vpk[5][12][1]))))+((Cik[12][1][2]*
          IkWpk[5][12][2])+((Cik[12][1][0]*IkWpk[5][12][0])+(Cik[12][1][1]*
          IkWpk[5][12][1]))))+temp[5]);
        temp[7] = (((mk[8]*((Vpk[4][13][2]*Vpk[5][13][2])+((Vpk[4][13][0]*
          Vpk[5][13][0])+(Vpk[4][13][1]*Vpk[5][13][1]))))+((IkWpk[5][13][2]*
          Wpk[4][13][2])+((IkWpk[5][13][0]*Wpk[4][13][0])+(IkWpk[5][13][1]*
          Wpk[4][13][1]))))+temp[6]);
        temp[8] = (((mk[9]*((Vpk[4][14][2]*Vpk[5][14][2])+((Vpk[4][14][0]*
          Vpk[5][14][0])+(Vpk[4][14][1]*Vpk[5][14][1]))))+((IkWpk[5][14][2]*
          Wpk[4][14][2])+((IkWpk[5][14][0]*Wpk[4][14][0])+(IkWpk[5][14][1]*
          Wpk[4][14][1]))))+temp[7]);
        temp[9] = (((mk[10]*((Vpk[4][15][2]*Vpk[5][15][2])+((Vpk[4][15][0]*
          Vpk[5][15][0])+(Vpk[4][15][1]*Vpk[5][15][1]))))+((Cik[15][1][2]*
          IkWpk[5][15][2])+((Cik[15][1][0]*IkWpk[5][15][0])+(Cik[15][1][1]*
          IkWpk[5][15][1]))))+temp[8]);
        temp[10] = (((mk[11]*((Vpk[4][16][2]*Vpk[5][16][2])+((Vpk[4][16][0]*
          Vpk[5][16][0])+(Vpk[4][16][1]*Vpk[5][16][1]))))+((IkWpk[5][16][2]*
          Wpk[4][16][2])+((IkWpk[5][16][0]*Wpk[4][16][0])+(IkWpk[5][16][1]*
          Wpk[4][16][1]))))+temp[9]);
        mm[4][5] = (((mk[12]*((Vpk[4][17][2]*Vpk[5][17][2])+((Vpk[4][17][0]*
          Vpk[5][17][0])+(Vpk[4][17][1]*Vpk[5][17][1]))))+((IkWpk[5][17][2]*
          Wpk[4][17][2])+((IkWpk[5][17][0]*Wpk[4][17][0])+(IkWpk[5][17][1]*
          Wpk[4][17][1]))))+temp[10]);
        temp[0] = (((mk[1]*((Vpk[4][6][2]*Vpk[6][6][2])+((Vpk[4][6][0]*
          Vpk[6][6][0])+(Vpk[4][6][1]*Vpk[6][6][1]))))+((Cik[6][1][2]*
          IkWpk[6][6][2])+((Cik[6][1][0]*IkWpk[6][6][0])+(Cik[6][1][1]*
          IkWpk[6][6][1]))))+((mk[2]*((Vpk[4][7][2]*Vpk[6][7][2])+((Vpk[4][7][0]
          *Vpk[6][7][0])+(Vpk[4][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*
          Wpk[4][7][2])+((IkWpk[6][7][0]*Wpk[4][7][0])+(IkWpk[6][7][1]*
          Wpk[4][7][1])))));
        mm[4][6] = (((mk[3]*((Vpk[4][8][2]*Vpk[6][8][2])+((Vpk[4][8][0]*
          Vpk[6][8][0])+(Vpk[4][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[4][8][2])+((IkWpk[6][8][0]*Wpk[4][8][0])+(IkWpk[6][8][1]*
          Wpk[4][8][1]))))+temp[0]);
        mm[4][7] = (((mk[2]*((Vpk[4][7][2]*Vpk[7][7][2])+((Vpk[4][7][0]*
          Vpk[7][7][0])+(Vpk[4][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          Wpk[4][7][2])+((IkWpk[7][7][0]*Wpk[4][7][0])+(IkWpk[7][7][1]*
          Wpk[4][7][1]))))+((mk[3]*((Vpk[4][8][2]*Vpk[7][8][2])+((Vpk[4][8][0]*
          Vpk[7][8][0])+(Vpk[4][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*
          Wpk[4][8][2])+((IkWpk[7][8][0]*Wpk[4][8][0])+(IkWpk[7][8][1]*
          Wpk[4][8][1])))));
        mm[4][8] = ((mk[3]*((Vpk[4][8][2]*Vpk[8][8][2])+((Vpk[4][8][0]*
          Vpk[8][8][0])+(Vpk[4][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[4][8][2])+((IkWpk[8][8][0]*Wpk[4][8][0])+(IkWpk[8][8][1]*
          Wpk[4][8][1]))));
        temp[0] = (((mk[4]*((Vpk[4][9][2]*Vpk[9][9][2])+((Vpk[4][9][0]*
          Vpk[9][9][0])+(Vpk[4][9][1]*Vpk[9][9][1]))))+((Cik[9][1][2]*
          IkWpk[9][9][2])+((Cik[9][1][0]*IkWpk[9][9][0])+(Cik[9][1][1]*
          IkWpk[9][9][1]))))+((mk[5]*((Vpk[4][10][2]*Vpk[9][10][2])+((
          Vpk[4][10][0]*Vpk[9][10][0])+(Vpk[4][10][1]*Vpk[9][10][1]))))+((
          IkWpk[9][10][2]*Wpk[4][10][2])+((IkWpk[9][10][0]*Wpk[4][10][0])+(
          IkWpk[9][10][1]*Wpk[4][10][1])))));
        mm[4][9] = (((mk[6]*((Vpk[4][11][2]*Vpk[9][11][2])+((Vpk[4][11][0]*
          Vpk[9][11][0])+(Vpk[4][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[4][11][2])+((IkWpk[9][11][0]*Wpk[4][11][0])+(IkWpk[9][11][1]*
          Wpk[4][11][1]))))+temp[0]);
        mm[4][10] = (((mk[5]*((Vpk[4][10][2]*Vpk[10][10][2])+((Vpk[4][10][0]*
          Vpk[10][10][0])+(Vpk[4][10][1]*Vpk[10][10][1]))))+((IkWpk[10][10][2]*
          Wpk[4][10][2])+((IkWpk[10][10][0]*Wpk[4][10][0])+(IkWpk[10][10][1]*
          Wpk[4][10][1]))))+((mk[6]*((Vpk[4][11][2]*Vpk[10][11][2])+((
          Vpk[4][11][0]*Vpk[10][11][0])+(Vpk[4][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[4][11][2])+((IkWpk[10][11][0]*Wpk[4][11][0])+(
          IkWpk[10][11][1]*Wpk[4][11][1])))));
        mm[4][11] = ((mk[6]*((Vpk[4][11][2]*Vpk[11][11][2])+((Vpk[4][11][0]*
          Vpk[11][11][0])+(Vpk[4][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          Wpk[4][11][2])+((IkWpk[11][11][0]*Wpk[4][11][0])+(IkWpk[11][11][1]*
          Wpk[4][11][1]))));
        temp[0] = (((mk[7]*((Vpk[4][12][2]*Vpk[12][12][2])+((Vpk[4][12][0]*
          Vpk[12][12][0])+(Vpk[4][12][1]*Vpk[12][12][1]))))+((Cik[12][1][2]*
          IkWpk[12][12][2])+((Cik[12][1][0]*IkWpk[12][12][0])+(Cik[12][1][1]*
          IkWpk[12][12][1]))))+((mk[8]*((Vpk[4][13][2]*Vpk[12][13][2])+((
          Vpk[4][13][0]*Vpk[12][13][0])+(Vpk[4][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[4][13][2])+((IkWpk[12][13][0]*Wpk[4][13][0])+(
          IkWpk[12][13][1]*Wpk[4][13][1])))));
        mm[4][12] = (((mk[9]*((Vpk[4][14][2]*Vpk[12][14][2])+((Vpk[4][14][0]*
          Vpk[12][14][0])+(Vpk[4][14][1]*Vpk[12][14][1]))))+((IkWpk[12][14][2]*
          Wpk[4][14][2])+((IkWpk[12][14][0]*Wpk[4][14][0])+(IkWpk[12][14][1]*
          Wpk[4][14][1]))))+temp[0]);
        mm[4][13] = (((mk[8]*((Vpk[4][13][2]*Vpk[13][13][2])+((Vpk[4][13][0]*
          Vpk[13][13][0])+(Vpk[4][13][1]*Vpk[13][13][1]))))+((IkWpk[13][13][2]*
          Wpk[4][13][2])+((IkWpk[13][13][0]*Wpk[4][13][0])+(IkWpk[13][13][1]*
          Wpk[4][13][1]))))+((mk[9]*((Vpk[4][14][2]*Vpk[13][14][2])+((
          Vpk[4][14][0]*Vpk[13][14][0])+(Vpk[4][14][1]*Vpk[13][14][1]))))+((
          IkWpk[13][14][2]*Wpk[4][14][2])+((IkWpk[13][14][0]*Wpk[4][14][0])+(
          IkWpk[13][14][1]*Wpk[4][14][1])))));
        mm[4][14] = ((mk[9]*((Vpk[4][14][2]*Vpk[14][14][2])+((Vpk[4][14][0]*
          Vpk[14][14][0])+(Vpk[4][14][1]*Vpk[14][14][1]))))+((IkWpk[14][14][2]*
          Wpk[4][14][2])+((IkWpk[14][14][0]*Wpk[4][14][0])+(IkWpk[14][14][1]*
          Wpk[4][14][1]))));
        temp[0] = (((mk[10]*((Vpk[4][15][2]*Vpk[15][15][2])+((Vpk[4][15][0]*
          Vpk[15][15][0])+(Vpk[4][15][1]*Vpk[15][15][1]))))+((Cik[15][1][2]*
          IkWpk[15][15][2])+((Cik[15][1][0]*IkWpk[15][15][0])+(Cik[15][1][1]*
          IkWpk[15][15][1]))))+((mk[11]*((Vpk[4][16][2]*Vpk[15][16][2])+((
          Vpk[4][16][0]*Vpk[15][16][0])+(Vpk[4][16][1]*Vpk[15][16][1]))))+((
          IkWpk[15][16][2]*Wpk[4][16][2])+((IkWpk[15][16][0]*Wpk[4][16][0])+(
          IkWpk[15][16][1]*Wpk[4][16][1])))));
        mm[4][15] = (((mk[12]*((Vpk[4][17][2]*Vpk[15][17][2])+((Vpk[4][17][0]*
          Vpk[15][17][0])+(Vpk[4][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]*
          Wpk[4][17][2])+((IkWpk[15][17][0]*Wpk[4][17][0])+(IkWpk[15][17][1]*
          Wpk[4][17][1]))))+temp[0]);
        mm[4][16] = (((mk[11]*((Vpk[4][16][2]*Vpk[16][16][2])+((Vpk[4][16][0]*
          Vpk[16][16][0])+(Vpk[4][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]*
          Wpk[4][16][2])+((IkWpk[16][16][0]*Wpk[4][16][0])+(IkWpk[16][16][1]*
          Wpk[4][16][1]))))+((mk[12]*((Vpk[4][17][2]*Vpk[16][17][2])+((
          Vpk[4][17][0]*Vpk[16][17][0])+(Vpk[4][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[4][17][2])+((IkWpk[16][17][0]*Wpk[4][17][0])+(
          IkWpk[16][17][1]*Wpk[4][17][1])))));
        mm[4][17] = ((mk[12]*((Vpk[4][17][2]*Vpk[17][17][2])+((Vpk[4][17][0]*
          Vpk[17][17][0])+(Vpk[4][17][1]*Vpk[17][17][1]))))+((IkWpk[17][17][2]*
          Wpk[4][17][2])+((IkWpk[17][17][0]*Wpk[4][17][0])+(IkWpk[17][17][1]*
          Wpk[4][17][1]))));
        temp[0] = ((ik[0][2][2]+(mk[0]*((rk[0][0]*rk[0][0])+(rk[0][1]*rk[0][1]))
          ))+((mk[1]*((Vpk[5][6][2]*Vpk[5][6][2])+((Vpk[5][6][0]*Vpk[5][6][0])+(
          Vpk[5][6][1]*Vpk[5][6][1]))))+((Cik[6][2][2]*IkWpk[5][6][2])+((
          Cik[6][2][0]*IkWpk[5][6][0])+(Cik[6][2][1]*IkWpk[5][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[5][7][2]*Vpk[5][7][2])+((Vpk[5][7][0]*
          Vpk[5][7][0])+(Vpk[5][7][1]*Vpk[5][7][1]))))+((IkWpk[5][7][2]*
          Wpk[5][7][2])+((IkWpk[5][7][0]*Wpk[5][7][0])+(IkWpk[5][7][1]*
          Wpk[5][7][1])))));
        temp[2] = (((mk[3]*((Vpk[5][8][2]*Vpk[5][8][2])+((Vpk[5][8][0]*
          Vpk[5][8][0])+(Vpk[5][8][1]*Vpk[5][8][1]))))+((IkWpk[5][8][2]*
          Wpk[5][8][2])+((IkWpk[5][8][0]*Wpk[5][8][0])+(IkWpk[5][8][1]*
          Wpk[5][8][1]))))+temp[1]);
        temp[3] = (((mk[4]*((Vpk[5][9][2]*Vpk[5][9][2])+((Vpk[5][9][0]*
          Vpk[5][9][0])+(Vpk[5][9][1]*Vpk[5][9][1]))))+((Cik[9][2][2]*
          IkWpk[5][9][2])+((Cik[9][2][0]*IkWpk[5][9][0])+(Cik[9][2][1]*
          IkWpk[5][9][1]))))+temp[2]);
        temp[4] = (((mk[5]*((Vpk[5][10][2]*Vpk[5][10][2])+((Vpk[5][10][0]*
          Vpk[5][10][0])+(Vpk[5][10][1]*Vpk[5][10][1]))))+((IkWpk[5][10][2]*
          Wpk[5][10][2])+((IkWpk[5][10][0]*Wpk[5][10][0])+(IkWpk[5][10][1]*
          Wpk[5][10][1]))))+temp[3]);
        temp[5] = (((mk[6]*((Vpk[5][11][2]*Vpk[5][11][2])+((Vpk[5][11][0]*
          Vpk[5][11][0])+(Vpk[5][11][1]*Vpk[5][11][1]))))+((IkWpk[5][11][2]*
          Wpk[5][11][2])+((IkWpk[5][11][0]*Wpk[5][11][0])+(IkWpk[5][11][1]*
          Wpk[5][11][1]))))+temp[4]);
        temp[6] = (((mk[7]*((Vpk[5][12][2]*Vpk[5][12][2])+((Vpk[5][12][0]*
          Vpk[5][12][0])+(Vpk[5][12][1]*Vpk[5][12][1]))))+((Cik[12][2][2]*
          IkWpk[5][12][2])+((Cik[12][2][0]*IkWpk[5][12][0])+(Cik[12][2][1]*
          IkWpk[5][12][1]))))+temp[5]);
        temp[7] = (((mk[8]*((Vpk[5][13][2]*Vpk[5][13][2])+((Vpk[5][13][0]*
          Vpk[5][13][0])+(Vpk[5][13][1]*Vpk[5][13][1]))))+((IkWpk[5][13][2]*
          Wpk[5][13][2])+((IkWpk[5][13][0]*Wpk[5][13][0])+(IkWpk[5][13][1]*
          Wpk[5][13][1]))))+temp[6]);
        temp[8] = (((mk[9]*((Vpk[5][14][2]*Vpk[5][14][2])+((Vpk[5][14][0]*
          Vpk[5][14][0])+(Vpk[5][14][1]*Vpk[5][14][1]))))+((IkWpk[5][14][2]*
          Wpk[5][14][2])+((IkWpk[5][14][0]*Wpk[5][14][0])+(IkWpk[5][14][1]*
          Wpk[5][14][1]))))+temp[7]);
        temp[9] = (((mk[10]*((Vpk[5][15][2]*Vpk[5][15][2])+((Vpk[5][15][0]*
          Vpk[5][15][0])+(Vpk[5][15][1]*Vpk[5][15][1]))))+((Cik[15][2][2]*
          IkWpk[5][15][2])+((Cik[15][2][0]*IkWpk[5][15][0])+(Cik[15][2][1]*
          IkWpk[5][15][1]))))+temp[8]);
        temp[10] = (((mk[11]*((Vpk[5][16][2]*Vpk[5][16][2])+((Vpk[5][16][0]*
          Vpk[5][16][0])+(Vpk[5][16][1]*Vpk[5][16][1]))))+((IkWpk[5][16][2]*
          Wpk[5][16][2])+((IkWpk[5][16][0]*Wpk[5][16][0])+(IkWpk[5][16][1]*
          Wpk[5][16][1]))))+temp[9]);
        mm[5][5] = (((mk[12]*((Vpk[5][17][2]*Vpk[5][17][2])+((Vpk[5][17][0]*
          Vpk[5][17][0])+(Vpk[5][17][1]*Vpk[5][17][1]))))+((IkWpk[5][17][2]*
          Wpk[5][17][2])+((IkWpk[5][17][0]*Wpk[5][17][0])+(IkWpk[5][17][1]*
          Wpk[5][17][1]))))+temp[10]);
        temp[0] = (((mk[1]*((Vpk[5][6][2]*Vpk[6][6][2])+((Vpk[5][6][0]*
          Vpk[6][6][0])+(Vpk[5][6][1]*Vpk[6][6][1]))))+((Cik[6][2][2]*
          IkWpk[6][6][2])+((Cik[6][2][0]*IkWpk[6][6][0])+(Cik[6][2][1]*
          IkWpk[6][6][1]))))+((mk[2]*((Vpk[5][7][2]*Vpk[6][7][2])+((Vpk[5][7][0]
          *Vpk[6][7][0])+(Vpk[5][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*
          Wpk[5][7][2])+((IkWpk[6][7][0]*Wpk[5][7][0])+(IkWpk[6][7][1]*
          Wpk[5][7][1])))));
        mm[5][6] = (((mk[3]*((Vpk[5][8][2]*Vpk[6][8][2])+((Vpk[5][8][0]*
          Vpk[6][8][0])+(Vpk[5][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[5][8][2])+((IkWpk[6][8][0]*Wpk[5][8][0])+(IkWpk[6][8][1]*
          Wpk[5][8][1]))))+temp[0]);
        mm[5][7] = (((mk[2]*((Vpk[5][7][2]*Vpk[7][7][2])+((Vpk[5][7][0]*
          Vpk[7][7][0])+(Vpk[5][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          Wpk[5][7][2])+((IkWpk[7][7][0]*Wpk[5][7][0])+(IkWpk[7][7][1]*
          Wpk[5][7][1]))))+((mk[3]*((Vpk[5][8][2]*Vpk[7][8][2])+((Vpk[5][8][0]*
          Vpk[7][8][0])+(Vpk[5][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*
          Wpk[5][8][2])+((IkWpk[7][8][0]*Wpk[5][8][0])+(IkWpk[7][8][1]*
          Wpk[5][8][1])))));
        mm[5][8] = ((mk[3]*((Vpk[5][8][2]*Vpk[8][8][2])+((Vpk[5][8][0]*
          Vpk[8][8][0])+(Vpk[5][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[5][8][2])+((IkWpk[8][8][0]*Wpk[5][8][0])+(IkWpk[8][8][1]*
          Wpk[5][8][1]))));
        temp[0] = (((mk[4]*((Vpk[5][9][2]*Vpk[9][9][2])+((Vpk[5][9][0]*
          Vpk[9][9][0])+(Vpk[5][9][1]*Vpk[9][9][1]))))+((Cik[9][2][2]*
          IkWpk[9][9][2])+((Cik[9][2][0]*IkWpk[9][9][0])+(Cik[9][2][1]*
          IkWpk[9][9][1]))))+((mk[5]*((Vpk[5][10][2]*Vpk[9][10][2])+((
          Vpk[5][10][0]*Vpk[9][10][0])+(Vpk[5][10][1]*Vpk[9][10][1]))))+((
          IkWpk[9][10][2]*Wpk[5][10][2])+((IkWpk[9][10][0]*Wpk[5][10][0])+(
          IkWpk[9][10][1]*Wpk[5][10][1])))));
        mm[5][9] = (((mk[6]*((Vpk[5][11][2]*Vpk[9][11][2])+((Vpk[5][11][0]*
          Vpk[9][11][0])+(Vpk[5][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[5][11][2])+((IkWpk[9][11][0]*Wpk[5][11][0])+(IkWpk[9][11][1]*
          Wpk[5][11][1]))))+temp[0]);
        mm[5][10] = (((mk[5]*((Vpk[5][10][2]*Vpk[10][10][2])+((Vpk[5][10][0]*
          Vpk[10][10][0])+(Vpk[5][10][1]*Vpk[10][10][1]))))+((IkWpk[10][10][2]*
          Wpk[5][10][2])+((IkWpk[10][10][0]*Wpk[5][10][0])+(IkWpk[10][10][1]*
          Wpk[5][10][1]))))+((mk[6]*((Vpk[5][11][2]*Vpk[10][11][2])+((
          Vpk[5][11][0]*Vpk[10][11][0])+(Vpk[5][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[5][11][2])+((IkWpk[10][11][0]*Wpk[5][11][0])+(
          IkWpk[10][11][1]*Wpk[5][11][1])))));
        mm[5][11] = ((mk[6]*((Vpk[5][11][2]*Vpk[11][11][2])+((Vpk[5][11][0]*
          Vpk[11][11][0])+(Vpk[5][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          Wpk[5][11][2])+((IkWpk[11][11][0]*Wpk[5][11][0])+(IkWpk[11][11][1]*
          Wpk[5][11][1]))));
        temp[0] = (((mk[7]*((Vpk[5][12][2]*Vpk[12][12][2])+((Vpk[5][12][0]*
          Vpk[12][12][0])+(Vpk[5][12][1]*Vpk[12][12][1]))))+((Cik[12][2][2]*
          IkWpk[12][12][2])+((Cik[12][2][0]*IkWpk[12][12][0])+(Cik[12][2][1]*
          IkWpk[12][12][1]))))+((mk[8]*((Vpk[5][13][2]*Vpk[12][13][2])+((
          Vpk[5][13][0]*Vpk[12][13][0])+(Vpk[5][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[5][13][2])+((IkWpk[12][13][0]*Wpk[5][13][0])+(
          IkWpk[12][13][1]*Wpk[5][13][1])))));
        mm[5][12] = (((mk[9]*((Vpk[5][14][2]*Vpk[12][14][2])+((Vpk[5][14][0]*
          Vpk[12][14][0])+(Vpk[5][14][1]*Vpk[12][14][1]))))+((IkWpk[12][14][2]*
          Wpk[5][14][2])+((IkWpk[12][14][0]*Wpk[5][14][0])+(IkWpk[12][14][1]*
          Wpk[5][14][1]))))+temp[0]);
        mm[5][13] = (((mk[8]*((Vpk[5][13][2]*Vpk[13][13][2])+((Vpk[5][13][0]*
          Vpk[13][13][0])+(Vpk[5][13][1]*Vpk[13][13][1]))))+((IkWpk[13][13][2]*
          Wpk[5][13][2])+((IkWpk[13][13][0]*Wpk[5][13][0])+(IkWpk[13][13][1]*
          Wpk[5][13][1]))))+((mk[9]*((Vpk[5][14][2]*Vpk[13][14][2])+((
          Vpk[5][14][0]*Vpk[13][14][0])+(Vpk[5][14][1]*Vpk[13][14][1]))))+((
          IkWpk[13][14][2]*Wpk[5][14][2])+((IkWpk[13][14][0]*Wpk[5][14][0])+(
          IkWpk[13][14][1]*Wpk[5][14][1])))));
        mm[5][14] = ((mk[9]*((Vpk[5][14][2]*Vpk[14][14][2])+((Vpk[5][14][0]*
          Vpk[14][14][0])+(Vpk[5][14][1]*Vpk[14][14][1]))))+((IkWpk[14][14][2]*
          Wpk[5][14][2])+((IkWpk[14][14][0]*Wpk[5][14][0])+(IkWpk[14][14][1]*
          Wpk[5][14][1]))));
        temp[0] = (((mk[10]*((Vpk[5][15][2]*Vpk[15][15][2])+((Vpk[5][15][0]*
          Vpk[15][15][0])+(Vpk[5][15][1]*Vpk[15][15][1]))))+((Cik[15][2][2]*
          IkWpk[15][15][2])+((Cik[15][2][0]*IkWpk[15][15][0])+(Cik[15][2][1]*
          IkWpk[15][15][1]))))+((mk[11]*((Vpk[5][16][2]*Vpk[15][16][2])+((
          Vpk[5][16][0]*Vpk[15][16][0])+(Vpk[5][16][1]*Vpk[15][16][1]))))+((
          IkWpk[15][16][2]*Wpk[5][16][2])+((IkWpk[15][16][0]*Wpk[5][16][0])+(
          IkWpk[15][16][1]*Wpk[5][16][1])))));
        mm[5][15] = (((mk[12]*((Vpk[5][17][2]*Vpk[15][17][2])+((Vpk[5][17][0]*
          Vpk[15][17][0])+(Vpk[5][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]*
          Wpk[5][17][2])+((IkWpk[15][17][0]*Wpk[5][17][0])+(IkWpk[15][17][1]*
          Wpk[5][17][1]))))+temp[0]);
        mm[5][16] = (((mk[11]*((Vpk[5][16][2]*Vpk[16][16][2])+((Vpk[5][16][0]*
          Vpk[16][16][0])+(Vpk[5][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]*
          Wpk[5][16][2])+((IkWpk[16][16][0]*Wpk[5][16][0])+(IkWpk[16][16][1]*
          Wpk[5][16][1]))))+((mk[12]*((Vpk[5][17][2]*Vpk[16][17][2])+((
          Vpk[5][17][0]*Vpk[16][17][0])+(Vpk[5][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[5][17][2])+((IkWpk[16][17][0]*Wpk[5][17][0])+(
          IkWpk[16][17][1]*Wpk[5][17][1])))));
        mm[5][17] = ((mk[12]*((Vpk[5][17][2]*Vpk[17][17][2])+((Vpk[5][17][0]*
          Vpk[17][17][0])+(Vpk[5][17][1]*Vpk[17][17][1]))))+((IkWpk[17][17][2]*
          Wpk[5][17][2])+((IkWpk[17][17][0]*Wpk[5][17][0])+(IkWpk[17][17][1]*
          Wpk[5][17][1]))));
        temp[0] = (((mk[1]*((Vpk[6][6][2]*Vpk[6][6][2])+((Vpk[6][6][0]*
          Vpk[6][6][0])+(Vpk[6][6][1]*Vpk[6][6][1]))))+((IkWpk[6][6][2]*
          pin[6][2])+((IkWpk[6][6][0]*pin[6][0])+(IkWpk[6][6][1]*pin[6][1]))))+(
          (mk[2]*((Vpk[6][7][2]*Vpk[6][7][2])+((Vpk[6][7][0]*Vpk[6][7][0])+(
          Vpk[6][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*Wpk[6][7][2])+((
          IkWpk[6][7][0]*Wpk[6][7][0])+(IkWpk[6][7][1]*Wpk[6][7][1])))));
        mm[6][6] = (((mk[3]*((Vpk[6][8][2]*Vpk[6][8][2])+((Vpk[6][8][0]*
          Vpk[6][8][0])+(Vpk[6][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[6][8][2])+((IkWpk[6][8][0]*Wpk[6][8][0])+(IkWpk[6][8][1]*
          Wpk[6][8][1]))))+temp[0]);
        mm[6][7] = (((mk[2]*((Vpk[6][7][2]*Vpk[7][7][2])+((Vpk[6][7][0]*
          Vpk[7][7][0])+(Vpk[6][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          Wpk[6][7][2])+((IkWpk[7][7][0]*Wpk[6][7][0])+(IkWpk[7][7][1]*
          Wpk[6][7][1]))))+((mk[3]*((Vpk[6][8][2]*Vpk[7][8][2])+((Vpk[6][8][0]*
          Vpk[7][8][0])+(Vpk[6][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*
          Wpk[6][8][2])+((IkWpk[7][8][0]*Wpk[6][8][0])+(IkWpk[7][8][1]*
          Wpk[6][8][1])))));
        mm[6][8] = ((mk[3]*((Vpk[6][8][2]*Vpk[8][8][2])+((Vpk[6][8][0]*
          Vpk[8][8][0])+(Vpk[6][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[6][8][2])+((IkWpk[8][8][0]*Wpk[6][8][0])+(IkWpk[8][8][1]*
          Wpk[6][8][1]))));
        mm[6][9] = 0.;
        mm[6][10] = 0.;
        mm[6][11] = 0.;
        mm[6][12] = 0.;
        mm[6][13] = 0.;
        mm[6][14] = 0.;
        mm[6][15] = 0.;
        mm[6][16] = 0.;
        mm[6][17] = 0.;
        mm[7][7] = (((mk[2]*((Vpk[7][7][2]*Vpk[7][7][2])+((Vpk[7][7][0]*
          Vpk[7][7][0])+(Vpk[7][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          pin[7][2])+((IkWpk[7][7][0]*pin[7][0])+(IkWpk[7][7][1]*pin[7][1]))))+(
          (mk[3]*((Vpk[7][8][2]*Vpk[7][8][2])+((Vpk[7][8][0]*Vpk[7][8][0])+(
          Vpk[7][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*Wpk[7][8][2])+((
          IkWpk[7][8][0]*Wpk[7][8][0])+(IkWpk[7][8][1]*Wpk[7][8][1])))));
        mm[7][8] = ((mk[3]*((Vpk[7][8][2]*Vpk[8][8][2])+((Vpk[7][8][0]*
          Vpk[8][8][0])+(Vpk[7][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[7][8][2])+((IkWpk[8][8][0]*Wpk[7][8][0])+(IkWpk[8][8][1]*
          Wpk[7][8][1]))));
        mm[7][9] = 0.;
        mm[7][10] = 0.;
        mm[7][11] = 0.;
        mm[7][12] = 0.;
        mm[7][13] = 0.;
        mm[7][14] = 0.;
        mm[7][15] = 0.;
        mm[7][16] = 0.;
        mm[7][17] = 0.;
        mm[8][8] = ((mk[3]*((Vpk[8][8][2]*Vpk[8][8][2])+((Vpk[8][8][0]*
          Vpk[8][8][0])+(Vpk[8][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          pin[8][2])+((IkWpk[8][8][0]*pin[8][0])+(IkWpk[8][8][1]*pin[8][1]))));
        mm[8][9] = 0.;
        mm[8][10] = 0.;
        mm[8][11] = 0.;
        mm[8][12] = 0.;
        mm[8][13] = 0.;
        mm[8][14] = 0.;
        mm[8][15] = 0.;
        mm[8][16] = 0.;
        mm[8][17] = 0.;
        temp[0] = (((mk[4]*((Vpk[9][9][2]*Vpk[9][9][2])+((Vpk[9][9][0]*
          Vpk[9][9][0])+(Vpk[9][9][1]*Vpk[9][9][1]))))+((IkWpk[9][9][2]*
          pin[9][2])+((IkWpk[9][9][0]*pin[9][0])+(IkWpk[9][9][1]*pin[9][1]))))+(
          (mk[5]*((Vpk[9][10][2]*Vpk[9][10][2])+((Vpk[9][10][0]*Vpk[9][10][0])+(
          Vpk[9][10][1]*Vpk[9][10][1]))))+((IkWpk[9][10][2]*Wpk[9][10][2])+((
          IkWpk[9][10][0]*Wpk[9][10][0])+(IkWpk[9][10][1]*Wpk[9][10][1])))));
        mm[9][9] = (((mk[6]*((Vpk[9][11][2]*Vpk[9][11][2])+((Vpk[9][11][0]*
          Vpk[9][11][0])+(Vpk[9][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[9][11][2])+((IkWpk[9][11][0]*Wpk[9][11][0])+(IkWpk[9][11][1]*
          Wpk[9][11][1]))))+temp[0]);
        mm[9][10] = (((mk[5]*((Vpk[9][10][2]*Vpk[10][10][2])+((Vpk[9][10][0]*
          Vpk[10][10][0])+(Vpk[9][10][1]*Vpk[10][10][1]))))+((IkWpk[10][10][2]*
          Wpk[9][10][2])+((IkWpk[10][10][0]*Wpk[9][10][0])+(IkWpk[10][10][1]*
          Wpk[9][10][1]))))+((mk[6]*((Vpk[9][11][2]*Vpk[10][11][2])+((
          Vpk[9][11][0]*Vpk[10][11][0])+(Vpk[9][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[9][11][2])+((IkWpk[10][11][0]*Wpk[9][11][0])+(
          IkWpk[10][11][1]*Wpk[9][11][1])))));
        mm[9][11] = ((mk[6]*((Vpk[9][11][2]*Vpk[11][11][2])+((Vpk[9][11][0]*
          Vpk[11][11][0])+(Vpk[9][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          Wpk[9][11][2])+((IkWpk[11][11][0]*Wpk[9][11][0])+(IkWpk[11][11][1]*
          Wpk[9][11][1]))));
        mm[9][12] = 0.;
        mm[9][13] = 0.;
        mm[9][14] = 0.;
        mm[9][15] = 0.;
        mm[9][16] = 0.;
        mm[9][17] = 0.;
        mm[10][10] = (((mk[5]*((Vpk[10][10][2]*Vpk[10][10][2])+((Vpk[10][10][0]*
          Vpk[10][10][0])+(Vpk[10][10][1]*Vpk[10][10][1]))))+((IkWpk[10][10][2]*
          pin[10][2])+((IkWpk[10][10][0]*pin[10][0])+(IkWpk[10][10][1]*
          pin[10][1]))))+((mk[6]*((Vpk[10][11][2]*Vpk[10][11][2])+((
          Vpk[10][11][0]*Vpk[10][11][0])+(Vpk[10][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[10][11][2])+((IkWpk[10][11][0]*Wpk[10][11][0])+(
          IkWpk[10][11][1]*Wpk[10][11][1])))));
        mm[10][11] = ((mk[6]*((Vpk[10][11][2]*Vpk[11][11][2])+((Vpk[10][11][0]*
          Vpk[11][11][0])+(Vpk[10][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          Wpk[10][11][2])+((IkWpk[11][11][0]*Wpk[10][11][0])+(IkWpk[11][11][1]*
          Wpk[10][11][1]))));
        mm[10][12] = 0.;
        mm[10][13] = 0.;
        mm[10][14] = 0.;
        mm[10][15] = 0.;
        mm[10][16] = 0.;
        mm[10][17] = 0.;
        mm[11][11] = ((mk[6]*((Vpk[11][11][2]*Vpk[11][11][2])+((Vpk[11][11][0]*
          Vpk[11][11][0])+(Vpk[11][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          pin[11][2])+((IkWpk[11][11][0]*pin[11][0])+(IkWpk[11][11][1]*
          pin[11][1]))));
        mm[11][12] = 0.;
        mm[11][13] = 0.;
        mm[11][14] = 0.;
        mm[11][15] = 0.;
        mm[11][16] = 0.;
        mm[11][17] = 0.;
        temp[0] = (((mk[7]*((Vpk[12][12][2]*Vpk[12][12][2])+((Vpk[12][12][0]*
          Vpk[12][12][0])+(Vpk[12][12][1]*Vpk[12][12][1]))))+((IkWpk[12][12][2]*
          pin[12][2])+((IkWpk[12][12][0]*pin[12][0])+(IkWpk[12][12][1]*
          pin[12][1]))))+((mk[8]*((Vpk[12][13][2]*Vpk[12][13][2])+((
          Vpk[12][13][0]*Vpk[12][13][0])+(Vpk[12][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[12][13][2])+((IkWpk[12][13][0]*Wpk[12][13][0])+(
          IkWpk[12][13][1]*Wpk[12][13][1])))));
        mm[12][12] = (((mk[9]*((Vpk[12][14][2]*Vpk[12][14][2])+((Vpk[12][14][0]*
          Vpk[12][14][0])+(Vpk[12][14][1]*Vpk[12][14][1]))))+((IkWpk[12][14][2]*
          Wpk[12][14][2])+((IkWpk[12][14][0]*Wpk[12][14][0])+(IkWpk[12][14][1]*
          Wpk[12][14][1]))))+temp[0]);
        mm[12][13] = (((mk[8]*((Vpk[12][13][2]*Vpk[13][13][2])+((Vpk[12][13][0]*
          Vpk[13][13][0])+(Vpk[12][13][1]*Vpk[13][13][1]))))+((IkWpk[13][13][2]*
          Wpk[12][13][2])+((IkWpk[13][13][0]*Wpk[12][13][0])+(IkWpk[13][13][1]*
          Wpk[12][13][1]))))+((mk[9]*((Vpk[12][14][2]*Vpk[13][14][2])+((
          Vpk[12][14][0]*Vpk[13][14][0])+(Vpk[12][14][1]*Vpk[13][14][1]))))+((
          IkWpk[13][14][2]*Wpk[12][14][2])+((IkWpk[13][14][0]*Wpk[12][14][0])+(
          IkWpk[13][14][1]*Wpk[12][14][1])))));
        mm[12][14] = ((mk[9]*((Vpk[12][14][2]*Vpk[14][14][2])+((Vpk[12][14][0]*
          Vpk[14][14][0])+(Vpk[12][14][1]*Vpk[14][14][1]))))+((IkWpk[14][14][2]*
          Wpk[12][14][2])+((IkWpk[14][14][0]*Wpk[12][14][0])+(IkWpk[14][14][1]*
          Wpk[12][14][1]))));
        mm[12][15] = 0.;
        mm[12][16] = 0.;
        mm[12][17] = 0.;
        mm[13][13] = (((mk[8]*((Vpk[13][13][2]*Vpk[13][13][2])+((Vpk[13][13][0]*
          Vpk[13][13][0])+(Vpk[13][13][1]*Vpk[13][13][1]))))+((IkWpk[13][13][2]*
          pin[13][2])+((IkWpk[13][13][0]*pin[13][0])+(IkWpk[13][13][1]*
          pin[13][1]))))+((mk[9]*((Vpk[13][14][2]*Vpk[13][14][2])+((
          Vpk[13][14][0]*Vpk[13][14][0])+(Vpk[13][14][1]*Vpk[13][14][1]))))+((
          IkWpk[13][14][2]*Wpk[13][14][2])+((IkWpk[13][14][0]*Wpk[13][14][0])+(
          IkWpk[13][14][1]*Wpk[13][14][1])))));
        mm[13][14] = ((mk[9]*((Vpk[13][14][2]*Vpk[14][14][2])+((Vpk[13][14][0]*
          Vpk[14][14][0])+(Vpk[13][14][1]*Vpk[14][14][1]))))+((IkWpk[14][14][2]*
          Wpk[13][14][2])+((IkWpk[14][14][0]*Wpk[13][14][0])+(IkWpk[14][14][1]*
          Wpk[13][14][1]))));
        mm[13][15] = 0.;
        mm[13][16] = 0.;
        mm[13][17] = 0.;
        mm[14][14] = ((mk[9]*((Vpk[14][14][2]*Vpk[14][14][2])+((Vpk[14][14][0]*
          Vpk[14][14][0])+(Vpk[14][14][1]*Vpk[14][14][1]))))+((IkWpk[14][14][2]*
          pin[14][2])+((IkWpk[14][14][0]*pin[14][0])+(IkWpk[14][14][1]*
          pin[14][1]))));
        mm[14][15] = 0.;
        mm[14][16] = 0.;
        mm[14][17] = 0.;
        temp[0] = (((mk[10]*((Vpk[15][15][2]*Vpk[15][15][2])+((Vpk[15][15][0]*
          Vpk[15][15][0])+(Vpk[15][15][1]*Vpk[15][15][1]))))+((IkWpk[15][15][2]*
          pin[15][2])+((IkWpk[15][15][0]*pin[15][0])+(IkWpk[15][15][1]*
          pin[15][1]))))+((mk[11]*((Vpk[15][16][2]*Vpk[15][16][2])+((
          Vpk[15][16][0]*Vpk[15][16][0])+(Vpk[15][16][1]*Vpk[15][16][1]))))+((
          IkWpk[15][16][2]*Wpk[15][16][2])+((IkWpk[15][16][0]*Wpk[15][16][0])+(
          IkWpk[15][16][1]*Wpk[15][16][1])))));
        mm[15][15] = (((mk[12]*((Vpk[15][17][2]*Vpk[15][17][2])+((Vpk[15][17][0]
          *Vpk[15][17][0])+(Vpk[15][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]
          *Wpk[15][17][2])+((IkWpk[15][17][0]*Wpk[15][17][0])+(IkWpk[15][17][1]*
          Wpk[15][17][1]))))+temp[0]);
        mm[15][16] = (((mk[11]*((Vpk[15][16][2]*Vpk[16][16][2])+((Vpk[15][16][0]
          *Vpk[16][16][0])+(Vpk[15][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]
          *Wpk[15][16][2])+((IkWpk[16][16][0]*Wpk[15][16][0])+(IkWpk[16][16][1]*
          Wpk[15][16][1]))))+((mk[12]*((Vpk[15][17][2]*Vpk[16][17][2])+((
          Vpk[15][17][0]*Vpk[16][17][0])+(Vpk[15][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[15][17][2])+((IkWpk[16][17][0]*Wpk[15][17][0])+(
          IkWpk[16][17][1]*Wpk[15][17][1])))));
        mm[15][17] = ((mk[12]*((Vpk[15][17][2]*Vpk[17][17][2])+((Vpk[15][17][0]*
          Vpk[17][17][0])+(Vpk[15][17][1]*Vpk[17][17][1]))))+((IkWpk[17][17][2]*
          Wpk[15][17][2])+((IkWpk[17][17][0]*Wpk[15][17][0])+(IkWpk[17][17][1]*
          Wpk[15][17][1]))));
        mm[16][16] = (((mk[11]*((Vpk[16][16][2]*Vpk[16][16][2])+((Vpk[16][16][0]
          *Vpk[16][16][0])+(Vpk[16][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]
          *pin[16][2])+((IkWpk[16][16][0]*pin[16][0])+(IkWpk[16][16][1]*
          pin[16][1]))))+((mk[12]*((Vpk[16][17][2]*Vpk[16][17][2])+((
          Vpk[16][17][0]*Vpk[16][17][0])+(Vpk[16][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[16][17][2])+((IkWpk[16][17][0]*Wpk[16][17][0])+(
          IkWpk[16][17][1]*Wpk[16][17][1])))));
        mm[16][17] = ((mk[12]*((Vpk[16][17][2]*Vpk[17][17][2])+((Vpk[16][17][0]*
          Vpk[17][17][0])+(Vpk[16][17][1]*Vpk[17][17][1]))))+((IkWpk[17][17][2]*
          Wpk[16][17][2])+((IkWpk[17][17][0]*Wpk[16][17][0])+(IkWpk[17][17][1]*
          Wpk[16][17][1]))));
        mm[17][17] = ((mk[12]*((Vpk[17][17][2]*Vpk[17][17][2])+((Vpk[17][17][0]*
          Vpk[17][17][0])+(Vpk[17][17][1]*Vpk[17][17][1]))))+((IkWpk[17][17][2]*
          pin[17][2])+((IkWpk[17][17][0]*pin[17][0])+(IkWpk[17][17][1]*
          pin[17][1]))));
/*
Check for singular mass matrix
*/
        for (i = 0; i < 18; i++) {
            if (mm[i][i] < 1e-13) {
                sdseterr(routine,47);
            }
        }
        sderror(&dumroutine,&errnum);
        if (errnum == 0) {
            mmflg = 1;
        }
    }
/*
 Used 0.02 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 2154 adds/subtracts/negates
                   2902 multiplies
                      0 divides
                    484 assignments
*/
}

void sddommldu(int routine)
{
    int i;
    int dumroutine,errnum;

    if (mmlduflg == 0) {
        sddomm(routine);
/*
Numerically decompose the mass matrix
*/
        sdldudcomp(18,18,mmap,1e-13,workss,works,mm,mlo,mdi);
/*
Check for singular mass matrix
*/
        for (i = 0; i < 18; i++) {
            if (mdi[i] <= 1e-13) {
                sdseterr(routine,47);
            }
        }
        sderror(&dumroutine,&errnum);
        if (errnum == 0) {
            mmlduflg = 1;
        }
    }
}

void sdlhs(int routine)
{
/* Compute all remaining state- and force-dependent quantities
*/

    roustate = 2;
    sddommldu(routine);
    sddofs0();
}

void sdmfrc(double imult[1])
{

}

void sdequivht(double tau[18])
{
/* Compute tree hinge torques to match effect of applied loads
*/
    double fstareq[18][3],tstareq[18][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(56,23);
        return;
    }
/*
Compute fstareq (forces)
*/
    fstareq[5][0] = -(ufk[0][0]+(gk[3][0]*mk[0]));
    fstareq[5][1] = -(ufk[0][1]+(gk[3][1]*mk[0]));
    fstareq[5][2] = -(ufk[0][2]+(gk[3][2]*mk[0]));
    fstareq[6][0] = -(ufk[1][0]+(gk[6][0]*mk[1]));
    fstareq[6][1] = -(ufk[1][1]+(gk[6][1]*mk[1]));
    fstareq[6][2] = -(ufk[1][2]+(gk[6][2]*mk[1]));
    fstareq[7][0] = -(ufk[2][0]+(gk[7][0]*mk[2]));
    fstareq[7][1] = -(ufk[2][1]+(gk[7][1]*mk[2]));
    fstareq[7][2] = -(ufk[2][2]+(gk[7][2]*mk[2]));
    fstareq[8][0] = -(ufk[3][0]+(gk[8][0]*mk[3]));
    fstareq[8][1] = -(ufk[3][1]+(gk[8][1]*mk[3]));
    fstareq[8][2] = -(ufk[3][2]+(gk[8][2]*mk[3]));
    fstareq[9][0] = -(ufk[4][0]+(gk[9][0]*mk[4]));
    fstareq[9][1] = -(ufk[4][1]+(gk[9][1]*mk[4]));
    fstareq[9][2] = -(ufk[4][2]+(gk[9][2]*mk[4]));
    fstareq[10][0] = -(ufk[5][0]+(gk[10][0]*mk[5]));
    fstareq[10][1] = -(ufk[5][1]+(gk[10][1]*mk[5]));
    fstareq[10][2] = -(ufk[5][2]+(gk[10][2]*mk[5]));
    fstareq[11][0] = -(ufk[6][0]+(gk[11][0]*mk[6]));
    fstareq[11][1] = -(ufk[6][1]+(gk[11][1]*mk[6]));
    fstareq[11][2] = -(ufk[6][2]+(gk[11][2]*mk[6]));
    fstareq[12][0] = -(ufk[7][0]+(gk[12][0]*mk[7]));
    fstareq[12][1] = -(ufk[7][1]+(gk[12][1]*mk[7]));
    fstareq[12][2] = -(ufk[7][2]+(gk[12][2]*mk[7]));
    fstareq[13][0] = -(ufk[8][0]+(gk[13][0]*mk[8]));
    fstareq[13][1] = -(ufk[8][1]+(gk[13][1]*mk[8]));
    fstareq[13][2] = -(ufk[8][2]+(gk[13][2]*mk[8]));
    fstareq[14][0] = -(ufk[9][0]+(gk[14][0]*mk[9]));
    fstareq[14][1] = -(ufk[9][1]+(gk[14][1]*mk[9]));
    fstareq[14][2] = -(ufk[9][2]+(gk[14][2]*mk[9]));
    fstareq[15][0] = -(ufk[10][0]+(gk[15][0]*mk[10]));
    fstareq[15][1] = -(ufk[10][1]+(gk[15][1]*mk[10]));
    fstareq[15][2] = -(ufk[10][2]+(gk[15][2]*mk[10]));
    fstareq[16][0] = -(ufk[11][0]+(gk[16][0]*mk[11]));
    fstareq[16][1] = -(ufk[11][1]+(gk[16][1]*mk[11]));
    fstareq[16][2] = -(ufk[11][2]+(gk[16][2]*mk[11]));
    fstareq[17][0] = -(ufk[12][0]+(gk[17][0]*mk[12]));
    fstareq[17][1] = -(ufk[12][1]+(gk[17][1]*mk[12]));
    fstareq[17][2] = -(ufk[12][2]+(gk[17][2]*mk[12]));
/*
Compute tstareq (torques)
*/
/*
Compute taus (RHS ignoring constraints and inertial forces)
*/
    sddovpk();
    temp[0] = (((fstareq[8][2]*Vpk[0][8][2])+((fstareq[8][0]*Vpk[0][8][0])+(
      fstareq[8][1]*Vpk[0][8][1])))+(((fstareq[7][2]*Vpk[0][7][2])+((
      fstareq[7][0]*Vpk[0][7][0])+(fstareq[7][1]*Vpk[0][7][1])))+(((
      fstareq[5][2]*Vpk[0][3][2])+((fstareq[5][0]*Vpk[0][3][0])+(fstareq[5][1]*
      Vpk[0][3][1])))+((fstareq[6][2]*Vpk[0][6][2])+((fstareq[6][0]*Vpk[0][6][0]
      )+(fstareq[6][1]*Vpk[0][6][1]))))));
    temp[1] = (((fstareq[12][2]*Vpk[0][12][2])+((fstareq[12][0]*Vpk[0][12][0])+(
      fstareq[12][1]*Vpk[0][12][1])))+(((fstareq[11][2]*Vpk[0][11][2])+((
      fstareq[11][0]*Vpk[0][11][0])+(fstareq[11][1]*Vpk[0][11][1])))+(((
      fstareq[10][2]*Vpk[0][10][2])+((fstareq[10][0]*Vpk[0][10][0])+(
      fstareq[10][1]*Vpk[0][10][1])))+(((fstareq[9][2]*Vpk[0][9][2])+((
      fstareq[9][0]*Vpk[0][9][0])+(fstareq[9][1]*Vpk[0][9][1])))+temp[0]))));
    temp[2] = (((fstareq[16][2]*Vpk[0][16][2])+((fstareq[16][0]*Vpk[0][16][0])+(
      fstareq[16][1]*Vpk[0][16][1])))+(((fstareq[15][2]*Vpk[0][15][2])+((
      fstareq[15][0]*Vpk[0][15][0])+(fstareq[15][1]*Vpk[0][15][1])))+(((
      fstareq[14][2]*Vpk[0][14][2])+((fstareq[14][0]*Vpk[0][14][0])+(
      fstareq[14][1]*Vpk[0][14][1])))+(((fstareq[13][2]*Vpk[0][13][2])+((
      fstareq[13][0]*Vpk[0][13][0])+(fstareq[13][1]*Vpk[0][13][1])))+temp[1]))))
      ;
    tau[0] = (utau[0]-(((fstareq[17][2]*Vpk[0][17][2])+((fstareq[17][0]*
      Vpk[0][17][0])+(fstareq[17][1]*Vpk[0][17][1])))+temp[2]));
    temp[0] = (((fstareq[8][2]*Vpk[1][8][2])+((fstareq[8][0]*Vpk[1][8][0])+(
      fstareq[8][1]*Vpk[1][8][1])))+(((fstareq[7][2]*Vpk[1][7][2])+((
      fstareq[7][0]*Vpk[1][7][0])+(fstareq[7][1]*Vpk[1][7][1])))+(((
      fstareq[5][2]*Vpk[1][3][2])+((fstareq[5][0]*Vpk[1][3][0])+(fstareq[5][1]*
      Vpk[1][3][1])))+((fstareq[6][2]*Vpk[1][6][2])+((fstareq[6][0]*Vpk[1][6][0]
      )+(fstareq[6][1]*Vpk[1][6][1]))))));
    temp[1] = (((fstareq[12][2]*Vpk[1][12][2])+((fstareq[12][0]*Vpk[1][12][0])+(
      fstareq[12][1]*Vpk[1][12][1])))+(((fstareq[11][2]*Vpk[1][11][2])+((
      fstareq[11][0]*Vpk[1][11][0])+(fstareq[11][1]*Vpk[1][11][1])))+(((
      fstareq[10][2]*Vpk[1][10][2])+((fstareq[10][0]*Vpk[1][10][0])+(
      fstareq[10][1]*Vpk[1][10][1])))+(((fstareq[9][2]*Vpk[1][9][2])+((
      fstareq[9][0]*Vpk[1][9][0])+(fstareq[9][1]*Vpk[1][9][1])))+temp[0]))));
    temp[2] = (((fstareq[16][2]*Vpk[1][16][2])+((fstareq[16][0]*Vpk[1][16][0])+(
      fstareq[16][1]*Vpk[1][16][1])))+(((fstareq[15][2]*Vpk[1][15][2])+((
      fstareq[15][0]*Vpk[1][15][0])+(fstareq[15][1]*Vpk[1][15][1])))+(((
      fstareq[14][2]*Vpk[1][14][2])+((fstareq[14][0]*Vpk[1][14][0])+(
      fstareq[14][1]*Vpk[1][14][1])))+(((fstareq[13][2]*Vpk[1][13][2])+((
      fstareq[13][0]*Vpk[1][13][0])+(fstareq[13][1]*Vpk[1][13][1])))+temp[1]))))
      ;
    tau[1] = (utau[1]-(((fstareq[17][2]*Vpk[1][17][2])+((fstareq[17][0]*
      Vpk[1][17][0])+(fstareq[17][1]*Vpk[1][17][1])))+temp[2]));
    temp[0] = (((fstareq[8][2]*Vpk[2][8][2])+((fstareq[8][0]*Vpk[2][8][0])+(
      fstareq[8][1]*Vpk[2][8][1])))+(((fstareq[7][2]*Vpk[2][7][2])+((
      fstareq[7][0]*Vpk[2][7][0])+(fstareq[7][1]*Vpk[2][7][1])))+(((
      fstareq[5][2]*Vpk[2][3][2])+((fstareq[5][0]*Vpk[2][3][0])+(fstareq[5][1]*
      Vpk[2][3][1])))+((fstareq[6][2]*Vpk[2][6][2])+((fstareq[6][0]*Vpk[2][6][0]
      )+(fstareq[6][1]*Vpk[2][6][1]))))));
    temp[1] = (((fstareq[12][2]*Vpk[2][12][2])+((fstareq[12][0]*Vpk[2][12][0])+(
      fstareq[12][1]*Vpk[2][12][1])))+(((fstareq[11][2]*Vpk[2][11][2])+((
      fstareq[11][0]*Vpk[2][11][0])+(fstareq[11][1]*Vpk[2][11][1])))+(((
      fstareq[10][2]*Vpk[2][10][2])+((fstareq[10][0]*Vpk[2][10][0])+(
      fstareq[10][1]*Vpk[2][10][1])))+(((fstareq[9][2]*Vpk[2][9][2])+((
      fstareq[9][0]*Vpk[2][9][0])+(fstareq[9][1]*Vpk[2][9][1])))+temp[0]))));
    temp[2] = (((fstareq[16][2]*Vpk[2][16][2])+((fstareq[16][0]*Vpk[2][16][0])+(
      fstareq[16][1]*Vpk[2][16][1])))+(((fstareq[15][2]*Vpk[2][15][2])+((
      fstareq[15][0]*Vpk[2][15][0])+(fstareq[15][1]*Vpk[2][15][1])))+(((
      fstareq[14][2]*Vpk[2][14][2])+((fstareq[14][0]*Vpk[2][14][0])+(
      fstareq[14][1]*Vpk[2][14][1])))+(((fstareq[13][2]*Vpk[2][13][2])+((
      fstareq[13][0]*Vpk[2][13][0])+(fstareq[13][1]*Vpk[2][13][1])))+temp[1]))))
      ;
    tau[2] = (utau[2]-(((fstareq[17][2]*Vpk[2][17][2])+((fstareq[17][0]*
      Vpk[2][17][0])+(fstareq[17][1]*Vpk[2][17][1])))+temp[2]));
    temp[0] = ((((fstareq[7][2]*Vpk[3][7][2])+((fstareq[7][0]*Vpk[3][7][0])+(
      fstareq[7][1]*Vpk[3][7][1])))-((utk[2][2]*Wpk[3][7][2])+((utk[2][0]*
      Wpk[3][7][0])+(utk[2][1]*Wpk[3][7][1]))))+((((fstareq[5][1]*rk[0][2])-(
      fstareq[5][2]*rk[0][1]))-utk[0][0])+(((fstareq[6][2]*Vpk[3][6][2])+((
      fstareq[6][0]*Vpk[3][6][0])+(fstareq[6][1]*Vpk[3][6][1])))-((Cik[6][0][2]*
      utk[1][2])+((Cik[6][0][0]*utk[1][0])+(Cik[6][0][1]*utk[1][1]))))));
    temp[1] = ((((fstareq[9][2]*Vpk[3][9][2])+((fstareq[9][0]*Vpk[3][9][0])+(
      fstareq[9][1]*Vpk[3][9][1])))-((Cik[9][0][2]*utk[4][2])+((Cik[9][0][0]*
      utk[4][0])+(Cik[9][0][1]*utk[4][1]))))+((((fstareq[8][2]*Vpk[3][8][2])+((
      fstareq[8][0]*Vpk[3][8][0])+(fstareq[8][1]*Vpk[3][8][1])))-((utk[3][2]*
      Wpk[3][8][2])+((utk[3][0]*Wpk[3][8][0])+(utk[3][1]*Wpk[3][8][1]))))+
      temp[0]));
    temp[2] = ((((fstareq[11][2]*Vpk[3][11][2])+((fstareq[11][0]*Vpk[3][11][0])+
      (fstareq[11][1]*Vpk[3][11][1])))-((utk[6][2]*Wpk[3][11][2])+((utk[6][0]*
      Wpk[3][11][0])+(utk[6][1]*Wpk[3][11][1]))))+((((fstareq[10][2]*
      Vpk[3][10][2])+((fstareq[10][0]*Vpk[3][10][0])+(fstareq[10][1]*
      Vpk[3][10][1])))-((utk[5][2]*Wpk[3][10][2])+((utk[5][0]*Wpk[3][10][0])+(
      utk[5][1]*Wpk[3][10][1]))))+temp[1]));
    temp[3] = ((((fstareq[13][2]*Vpk[3][13][2])+((fstareq[13][0]*Vpk[3][13][0])+
      (fstareq[13][1]*Vpk[3][13][1])))-((utk[8][2]*Wpk[3][13][2])+((utk[8][0]*
      Wpk[3][13][0])+(utk[8][1]*Wpk[3][13][1]))))+((((fstareq[12][2]*
      Vpk[3][12][2])+((fstareq[12][0]*Vpk[3][12][0])+(fstareq[12][1]*
      Vpk[3][12][1])))-((Cik[12][0][2]*utk[7][2])+((Cik[12][0][0]*utk[7][0])+(
      Cik[12][0][1]*utk[7][1]))))+temp[2]));
    temp[4] = ((((fstareq[15][2]*Vpk[3][15][2])+((fstareq[15][0]*Vpk[3][15][0])+
      (fstareq[15][1]*Vpk[3][15][1])))-((Cik[15][0][2]*utk[10][2])+((
      Cik[15][0][0]*utk[10][0])+(Cik[15][0][1]*utk[10][1]))))+((((fstareq[14][2]
      *Vpk[3][14][2])+((fstareq[14][0]*Vpk[3][14][0])+(fstareq[14][1]*
      Vpk[3][14][1])))-((utk[9][2]*Wpk[3][14][2])+((utk[9][0]*Wpk[3][14][0])+(
      utk[9][1]*Wpk[3][14][1]))))+temp[3]));
    tau[3] = (utau[3]-((((fstareq[17][2]*Vpk[3][17][2])+((fstareq[17][0]*
      Vpk[3][17][0])+(fstareq[17][1]*Vpk[3][17][1])))-((utk[12][2]*Wpk[3][17][2]
      )+((utk[12][0]*Wpk[3][17][0])+(utk[12][1]*Wpk[3][17][1]))))+((((
      fstareq[16][2]*Vpk[3][16][2])+((fstareq[16][0]*Vpk[3][16][0])+(
      fstareq[16][1]*Vpk[3][16][1])))-((utk[11][2]*Wpk[3][16][2])+((utk[11][0]*
      Wpk[3][16][0])+(utk[11][1]*Wpk[3][16][1]))))+temp[4])));
    temp[0] = ((((fstareq[7][2]*Vpk[4][7][2])+((fstareq[7][0]*Vpk[4][7][0])+(
      fstareq[7][1]*Vpk[4][7][1])))-((utk[2][2]*Wpk[4][7][2])+((utk[2][0]*
      Wpk[4][7][0])+(utk[2][1]*Wpk[4][7][1]))))+((((fstareq[5][2]*rk[0][0])-(
      fstareq[5][0]*rk[0][2]))-utk[0][1])+(((fstareq[6][2]*Vpk[4][6][2])+((
      fstareq[6][0]*Vpk[4][6][0])+(fstareq[6][1]*Vpk[4][6][1])))-((Cik[6][1][2]*
      utk[1][2])+((Cik[6][1][0]*utk[1][0])+(Cik[6][1][1]*utk[1][1]))))));
    temp[1] = ((((fstareq[9][2]*Vpk[4][9][2])+((fstareq[9][0]*Vpk[4][9][0])+(
      fstareq[9][1]*Vpk[4][9][1])))-((Cik[9][1][2]*utk[4][2])+((Cik[9][1][0]*
      utk[4][0])+(Cik[9][1][1]*utk[4][1]))))+((((fstareq[8][2]*Vpk[4][8][2])+((
      fstareq[8][0]*Vpk[4][8][0])+(fstareq[8][1]*Vpk[4][8][1])))-((utk[3][2]*
      Wpk[4][8][2])+((utk[3][0]*Wpk[4][8][0])+(utk[3][1]*Wpk[4][8][1]))))+
      temp[0]));
    temp[2] = ((((fstareq[11][2]*Vpk[4][11][2])+((fstareq[11][0]*Vpk[4][11][0])+
      (fstareq[11][1]*Vpk[4][11][1])))-((utk[6][2]*Wpk[4][11][2])+((utk[6][0]*
      Wpk[4][11][0])+(utk[6][1]*Wpk[4][11][1]))))+((((fstareq[10][2]*
      Vpk[4][10][2])+((fstareq[10][0]*Vpk[4][10][0])+(fstareq[10][1]*
      Vpk[4][10][1])))-((utk[5][2]*Wpk[4][10][2])+((utk[5][0]*Wpk[4][10][0])+(
      utk[5][1]*Wpk[4][10][1]))))+temp[1]));
    temp[3] = ((((fstareq[13][2]*Vpk[4][13][2])+((fstareq[13][0]*Vpk[4][13][0])+
      (fstareq[13][1]*Vpk[4][13][1])))-((utk[8][2]*Wpk[4][13][2])+((utk[8][0]*
      Wpk[4][13][0])+(utk[8][1]*Wpk[4][13][1]))))+((((fstareq[12][2]*
      Vpk[4][12][2])+((fstareq[12][0]*Vpk[4][12][0])+(fstareq[12][1]*
      Vpk[4][12][1])))-((Cik[12][1][2]*utk[7][2])+((Cik[12][1][0]*utk[7][0])+(
      Cik[12][1][1]*utk[7][1]))))+temp[2]));
    temp[4] = ((((fstareq[15][2]*Vpk[4][15][2])+((fstareq[15][0]*Vpk[4][15][0])+
      (fstareq[15][1]*Vpk[4][15][1])))-((Cik[15][1][2]*utk[10][2])+((
      Cik[15][1][0]*utk[10][0])+(Cik[15][1][1]*utk[10][1]))))+((((fstareq[14][2]
      *Vpk[4][14][2])+((fstareq[14][0]*Vpk[4][14][0])+(fstareq[14][1]*
      Vpk[4][14][1])))-((utk[9][2]*Wpk[4][14][2])+((utk[9][0]*Wpk[4][14][0])+(
      utk[9][1]*Wpk[4][14][1]))))+temp[3]));
    tau[4] = (utau[4]-((((fstareq[17][2]*Vpk[4][17][2])+((fstareq[17][0]*
      Vpk[4][17][0])+(fstareq[17][1]*Vpk[4][17][1])))-((utk[12][2]*Wpk[4][17][2]
      )+((utk[12][0]*Wpk[4][17][0])+(utk[12][1]*Wpk[4][17][1]))))+((((
      fstareq[16][2]*Vpk[4][16][2])+((fstareq[16][0]*Vpk[4][16][0])+(
      fstareq[16][1]*Vpk[4][16][1])))-((utk[11][2]*Wpk[4][16][2])+((utk[11][0]*
      Wpk[4][16][0])+(utk[11][1]*Wpk[4][16][1]))))+temp[4])));
    temp[0] = ((((fstareq[7][2]*Vpk[5][7][2])+((fstareq[7][0]*Vpk[5][7][0])+(
      fstareq[7][1]*Vpk[5][7][1])))-((utk[2][2]*Wpk[5][7][2])+((utk[2][0]*
      Wpk[5][7][0])+(utk[2][1]*Wpk[5][7][1]))))+((((fstareq[5][0]*rk[0][1])-(
      fstareq[5][1]*rk[0][0]))-utk[0][2])+(((fstareq[6][2]*Vpk[5][6][2])+((
      fstareq[6][0]*Vpk[5][6][0])+(fstareq[6][1]*Vpk[5][6][1])))-((Cik[6][2][2]*
      utk[1][2])+((Cik[6][2][0]*utk[1][0])+(Cik[6][2][1]*utk[1][1]))))));
    temp[1] = ((((fstareq[9][2]*Vpk[5][9][2])+((fstareq[9][0]*Vpk[5][9][0])+(
      fstareq[9][1]*Vpk[5][9][1])))-((Cik[9][2][2]*utk[4][2])+((Cik[9][2][0]*
      utk[4][0])+(Cik[9][2][1]*utk[4][1]))))+((((fstareq[8][2]*Vpk[5][8][2])+((
      fstareq[8][0]*Vpk[5][8][0])+(fstareq[8][1]*Vpk[5][8][1])))-((utk[3][2]*
      Wpk[5][8][2])+((utk[3][0]*Wpk[5][8][0])+(utk[3][1]*Wpk[5][8][1]))))+
      temp[0]));
    temp[2] = ((((fstareq[11][2]*Vpk[5][11][2])+((fstareq[11][0]*Vpk[5][11][0])+
      (fstareq[11][1]*Vpk[5][11][1])))-((utk[6][2]*Wpk[5][11][2])+((utk[6][0]*
      Wpk[5][11][0])+(utk[6][1]*Wpk[5][11][1]))))+((((fstareq[10][2]*
      Vpk[5][10][2])+((fstareq[10][0]*Vpk[5][10][0])+(fstareq[10][1]*
      Vpk[5][10][1])))-((utk[5][2]*Wpk[5][10][2])+((utk[5][0]*Wpk[5][10][0])+(
      utk[5][1]*Wpk[5][10][1]))))+temp[1]));
    temp[3] = ((((fstareq[13][2]*Vpk[5][13][2])+((fstareq[13][0]*Vpk[5][13][0])+
      (fstareq[13][1]*Vpk[5][13][1])))-((utk[8][2]*Wpk[5][13][2])+((utk[8][0]*
      Wpk[5][13][0])+(utk[8][1]*Wpk[5][13][1]))))+((((fstareq[12][2]*
      Vpk[5][12][2])+((fstareq[12][0]*Vpk[5][12][0])+(fstareq[12][1]*
      Vpk[5][12][1])))-((Cik[12][2][2]*utk[7][2])+((Cik[12][2][0]*utk[7][0])+(
      Cik[12][2][1]*utk[7][1]))))+temp[2]));
    temp[4] = ((((fstareq[15][2]*Vpk[5][15][2])+((fstareq[15][0]*Vpk[5][15][0])+
      (fstareq[15][1]*Vpk[5][15][1])))-((Cik[15][2][2]*utk[10][2])+((
      Cik[15][2][0]*utk[10][0])+(Cik[15][2][1]*utk[10][1]))))+((((fstareq[14][2]
      *Vpk[5][14][2])+((fstareq[14][0]*Vpk[5][14][0])+(fstareq[14][1]*
      Vpk[5][14][1])))-((utk[9][2]*Wpk[5][14][2])+((utk[9][0]*Wpk[5][14][0])+(
      utk[9][1]*Wpk[5][14][1]))))+temp[3]));
    tau[5] = (utau[5]-((((fstareq[17][2]*Vpk[5][17][2])+((fstareq[17][0]*
      Vpk[5][17][0])+(fstareq[17][1]*Vpk[5][17][1])))-((utk[12][2]*Wpk[5][17][2]
      )+((utk[12][0]*Wpk[5][17][0])+(utk[12][1]*Wpk[5][17][1]))))+((((
      fstareq[16][2]*Vpk[5][16][2])+((fstareq[16][0]*Vpk[5][16][0])+(
      fstareq[16][1]*Vpk[5][16][1])))-((utk[11][2]*Wpk[5][16][2])+((utk[11][0]*
      Wpk[5][16][0])+(utk[11][1]*Wpk[5][16][1]))))+temp[4])));
    temp[0] = ((((fstareq[6][2]*Vpk[6][6][2])+((fstareq[6][0]*Vpk[6][6][0])+(
      fstareq[6][1]*Vpk[6][6][1])))-((pin[6][2]*utk[1][2])+((pin[6][0]*utk[1][0]
      )+(pin[6][1]*utk[1][1]))))+(((fstareq[7][2]*Vpk[6][7][2])+((fstareq[7][0]*
      Vpk[6][7][0])+(fstareq[7][1]*Vpk[6][7][1])))-((utk[2][2]*Wpk[6][7][2])+((
      utk[2][0]*Wpk[6][7][0])+(utk[2][1]*Wpk[6][7][1])))));
    tau[6] = (utau[6]-((((fstareq[8][2]*Vpk[6][8][2])+((fstareq[8][0]*
      Vpk[6][8][0])+(fstareq[8][1]*Vpk[6][8][1])))-((utk[3][2]*Wpk[6][8][2])+((
      utk[3][0]*Wpk[6][8][0])+(utk[3][1]*Wpk[6][8][1]))))+temp[0]));
    tau[7] = (utau[7]-((((fstareq[7][2]*Vpk[7][7][2])+((fstareq[7][0]*
      Vpk[7][7][0])+(fstareq[7][1]*Vpk[7][7][1])))-((pin[7][2]*utk[2][2])+((
      pin[7][0]*utk[2][0])+(pin[7][1]*utk[2][1]))))+(((fstareq[8][2]*
      Vpk[7][8][2])+((fstareq[8][0]*Vpk[7][8][0])+(fstareq[8][1]*Vpk[7][8][1])))
      -((utk[3][2]*Wpk[7][8][2])+((utk[3][0]*Wpk[7][8][0])+(utk[3][1]*
      Wpk[7][8][1]))))));
    tau[8] = (utau[8]-(((fstareq[8][2]*Vpk[8][8][2])+((fstareq[8][0]*
      Vpk[8][8][0])+(fstareq[8][1]*Vpk[8][8][1])))-((pin[8][2]*utk[3][2])+((
      pin[8][0]*utk[3][0])+(pin[8][1]*utk[3][1])))));
    temp[0] = ((((fstareq[9][2]*Vpk[9][9][2])+((fstareq[9][0]*Vpk[9][9][0])+(
      fstareq[9][1]*Vpk[9][9][1])))-((pin[9][2]*utk[4][2])+((pin[9][0]*utk[4][0]
      )+(pin[9][1]*utk[4][1]))))+(((fstareq[10][2]*Vpk[9][10][2])+((
      fstareq[10][0]*Vpk[9][10][0])+(fstareq[10][1]*Vpk[9][10][1])))-((utk[5][2]
      *Wpk[9][10][2])+((utk[5][0]*Wpk[9][10][0])+(utk[5][1]*Wpk[9][10][1])))));
    tau[9] = (utau[9]-((((fstareq[11][2]*Vpk[9][11][2])+((fstareq[11][0]*
      Vpk[9][11][0])+(fstareq[11][1]*Vpk[9][11][1])))-((utk[6][2]*Wpk[9][11][2])
      +((utk[6][0]*Wpk[9][11][0])+(utk[6][1]*Wpk[9][11][1]))))+temp[0]));
    tau[10] = (utau[10]-((((fstareq[10][2]*Vpk[10][10][2])+((fstareq[10][0]*
      Vpk[10][10][0])+(fstareq[10][1]*Vpk[10][10][1])))-((pin[10][2]*utk[5][2])+
      ((pin[10][0]*utk[5][0])+(pin[10][1]*utk[5][1]))))+(((fstareq[11][2]*
      Vpk[10][11][2])+((fstareq[11][0]*Vpk[10][11][0])+(fstareq[11][1]*
      Vpk[10][11][1])))-((utk[6][2]*Wpk[10][11][2])+((utk[6][0]*Wpk[10][11][0])+
      (utk[6][1]*Wpk[10][11][1]))))));
    tau[11] = (utau[11]-(((fstareq[11][2]*Vpk[11][11][2])+((fstareq[11][0]*
      Vpk[11][11][0])+(fstareq[11][1]*Vpk[11][11][1])))-((pin[11][2]*utk[6][2])+
      ((pin[11][0]*utk[6][0])+(pin[11][1]*utk[6][1])))));
    temp[0] = ((((fstareq[12][2]*Vpk[12][12][2])+((fstareq[12][0]*Vpk[12][12][0]
      )+(fstareq[12][1]*Vpk[12][12][1])))-((pin[12][2]*utk[7][2])+((pin[12][0]*
      utk[7][0])+(pin[12][1]*utk[7][1]))))+(((fstareq[13][2]*Vpk[12][13][2])+((
      fstareq[13][0]*Vpk[12][13][0])+(fstareq[13][1]*Vpk[12][13][1])))-((
      utk[8][2]*Wpk[12][13][2])+((utk[8][0]*Wpk[12][13][0])+(utk[8][1]*
      Wpk[12][13][1])))));
    tau[12] = (utau[12]-((((fstareq[14][2]*Vpk[12][14][2])+((fstareq[14][0]*
      Vpk[12][14][0])+(fstareq[14][1]*Vpk[12][14][1])))-((utk[9][2]*
      Wpk[12][14][2])+((utk[9][0]*Wpk[12][14][0])+(utk[9][1]*Wpk[12][14][1]))))+
      temp[0]));
    tau[13] = (utau[13]-((((fstareq[13][2]*Vpk[13][13][2])+((fstareq[13][0]*
      Vpk[13][13][0])+(fstareq[13][1]*Vpk[13][13][1])))-((pin[13][2]*utk[8][2])+
      ((pin[13][0]*utk[8][0])+(pin[13][1]*utk[8][1]))))+(((fstareq[14][2]*
      Vpk[13][14][2])+((fstareq[14][0]*Vpk[13][14][0])+(fstareq[14][1]*
      Vpk[13][14][1])))-((utk[9][2]*Wpk[13][14][2])+((utk[9][0]*Wpk[13][14][0])+
      (utk[9][1]*Wpk[13][14][1]))))));
    tau[14] = (utau[14]-(((fstareq[14][2]*Vpk[14][14][2])+((fstareq[14][0]*
      Vpk[14][14][0])+(fstareq[14][1]*Vpk[14][14][1])))-((pin[14][2]*utk[9][2])+
      ((pin[14][0]*utk[9][0])+(pin[14][1]*utk[9][1])))));
    temp[0] = ((((fstareq[15][2]*Vpk[15][15][2])+((fstareq[15][0]*Vpk[15][15][0]
      )+(fstareq[15][1]*Vpk[15][15][1])))-((pin[15][2]*utk[10][2])+((pin[15][0]*
      utk[10][0])+(pin[15][1]*utk[10][1]))))+(((fstareq[16][2]*Vpk[15][16][2])+(
      (fstareq[16][0]*Vpk[15][16][0])+(fstareq[16][1]*Vpk[15][16][1])))-((
      utk[11][2]*Wpk[15][16][2])+((utk[11][0]*Wpk[15][16][0])+(utk[11][1]*
      Wpk[15][16][1])))));
    tau[15] = (utau[15]-((((fstareq[17][2]*Vpk[15][17][2])+((fstareq[17][0]*
      Vpk[15][17][0])+(fstareq[17][1]*Vpk[15][17][1])))-((utk[12][2]*
      Wpk[15][17][2])+((utk[12][0]*Wpk[15][17][0])+(utk[12][1]*Wpk[15][17][1])))
      )+temp[0]));
    tau[16] = (utau[16]-((((fstareq[16][2]*Vpk[16][16][2])+((fstareq[16][0]*
      Vpk[16][16][0])+(fstareq[16][1]*Vpk[16][16][1])))-((pin[16][2]*utk[11][2])
      +((pin[16][0]*utk[11][0])+(pin[16][1]*utk[11][1]))))+(((fstareq[17][2]*
      Vpk[16][17][2])+((fstareq[17][0]*Vpk[16][17][0])+(fstareq[17][1]*
      Vpk[16][17][1])))-((utk[12][2]*Wpk[16][17][2])+((utk[12][0]*Wpk[16][17][0]
      )+(utk[12][1]*Wpk[16][17][1]))))));
    tau[17] = (utau[17]-(((fstareq[17][2]*Vpk[17][17][2])+((fstareq[17][0]*
      Vpk[17][17][0])+(fstareq[17][1]*Vpk[17][17][1])))-((pin[17][2]*utk[12][2])
      +((pin[17][0]*utk[12][0])+(pin[17][1]*utk[12][1])))));
/*
Op counts below do not include called subroutines
*/
/*
 Used 0.02 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  564 adds/subtracts/negates
                    522 multiplies
                      0 divides
                     85 assignments
*/
}

void sdfs0(void)
{

/*
Compute Fs (ignoring multiplier forces)
*/
    fs[0] = fs0[0];
    fs[1] = fs0[1];
    fs[2] = fs0[2];
    fs[3] = fs0[3];
    fs[4] = fs0[4];
    fs[5] = fs0[5];
    fs[6] = fs0[6];
    fs[7] = fs0[7];
    fs[8] = fs0[8];
    fs[9] = fs0[9];
    fs[10] = fs0[10];
    fs[11] = fs0[11];
    fs[12] = fs0[12];
    fs[13] = fs0[13];
    fs[14] = fs0[14];
    fs[15] = fs0[15];
    fs[16] = fs0[16];
    fs[17] = fs0[17];
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     18 assignments
*/
}

void sdfsmult(void)
{
    int i;

/*
Compute Fs (multiplier-generated forces only)
*/
    for (i = 0; i < 18; i++) {
        fs[i] = 0.;
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     18 assignments
*/
}

void sdfsfull(void)
{

/*
Compute Fs (including all forces)
*/
    sdfsmult();
    fs[0] = (fs[0]+fs0[0]);
    fs[1] = (fs[1]+fs0[1]);
    fs[2] = (fs[2]+fs0[2]);
    fs[3] = (fs[3]+fs0[3]);
    fs[4] = (fs[4]+fs0[4]);
    fs[5] = (fs[5]+fs0[5]);
    fs[6] = (fs[6]+fs0[6]);
    fs[7] = (fs[7]+fs0[7]);
    fs[8] = (fs[8]+fs0[8]);
    fs[9] = (fs[9]+fs0[9]);
    fs[10] = (fs[10]+fs0[10]);
    fs[11] = (fs[11]+fs0[11]);
    fs[12] = (fs[12]+fs0[12]);
    fs[13] = (fs[13]+fs0[13]);
    fs[14] = (fs[14]+fs0[14]);
    fs[15] = (fs[15]+fs0[15]);
    fs[16] = (fs[16]+fs0[16]);
    fs[17] = (fs[17]+fs0[17]);
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   18 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     18 assignments
*/
}

void sdfsgenmult(void)
{
    int i;

/*
Compute Fs (generic multiplier-generated forces)
*/
    for (i = 0; i < 18; i++) {
        fs[i] = 0.;
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     18 assignments
*/
}

void sdfsgenfull(void)
{

/*
Compute Fs (incl generic mult & other forces)
*/
    sdfsgenmult();
    fs[0] = (fs[0]+fs0[0]);
    fs[1] = (fs[1]+fs0[1]);
    fs[2] = (fs[2]+fs0[2]);
    fs[3] = (fs[3]+fs0[3]);
    fs[4] = (fs[4]+fs0[4]);
    fs[5] = (fs[5]+fs0[5]);
    fs[6] = (fs[6]+fs0[6]);
    fs[7] = (fs[7]+fs0[7]);
    fs[8] = (fs[8]+fs0[8]);
    fs[9] = (fs[9]+fs0[9]);
    fs[10] = (fs[10]+fs0[10]);
    fs[11] = (fs[11]+fs0[11]);
    fs[12] = (fs[12]+fs0[12]);
    fs[13] = (fs[13]+fs0[13]);
    fs[14] = (fs[14]+fs0[14]);
    fs[15] = (fs[15]+fs0[15]);
    fs[16] = (fs[16]+fs0[16]);
    fs[17] = (fs[17]+fs0[17]);
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   18 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     18 assignments
*/
}

void sdfulltrq(double udotin[18],
    double multin[1],
    double trqout[18])
{
/* Compute hinge torques which would produce indicated udots
*/
    double fstarr[18][3],tstarr[18][3],Otkr[18][3],Atir[18][3],Atkr[18][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(61,23);
        return;
    }
/*
Account for inertial accelerations and supplied udots
*/
    Otkr[6][0] = (((Cik[6][2][0]*udotin[5])+((Cik[6][0][0]*udotin[3])+(
      Cik[6][1][0]*udotin[4])))+((pin[6][0]*udotin[6])+((Wik[6][2]*wk[6][1])-(
      Wik[6][1]*wk[6][2]))));
    Otkr[6][1] = (((Cik[6][2][1]*udotin[5])+((Cik[6][0][1]*udotin[3])+(
      Cik[6][1][1]*udotin[4])))+((pin[6][1]*udotin[6])+((Wik[6][0]*wk[6][2])-(
      Wik[6][2]*wk[6][0]))));
    Otkr[6][2] = (((Cik[6][2][2]*udotin[5])+((Cik[6][0][2]*udotin[3])+(
      Cik[6][1][2]*udotin[4])))+((pin[6][2]*udotin[6])+((Wik[6][1]*wk[6][0])-(
      Wik[6][0]*wk[6][1]))));
    Otkr[7][0] = (((Cik[7][2][0]*Otkr[6][2])+((Cik[7][0][0]*Otkr[6][0])+(
      Cik[7][1][0]*Otkr[6][1])))+((pin[7][0]*udotin[7])+((Wik[7][2]*wk[7][1])-(
      Wik[7][1]*wk[7][2]))));
    Otkr[7][1] = (((Cik[7][2][1]*Otkr[6][2])+((Cik[7][0][1]*Otkr[6][0])+(
      Cik[7][1][1]*Otkr[6][1])))+((pin[7][1]*udotin[7])+((Wik[7][0]*wk[7][2])-(
      Wik[7][2]*wk[7][0]))));
    Otkr[7][2] = (((Cik[7][2][2]*Otkr[6][2])+((Cik[7][0][2]*Otkr[6][0])+(
      Cik[7][1][2]*Otkr[6][1])))+((pin[7][2]*udotin[7])+((Wik[7][1]*wk[7][0])-(
      Wik[7][0]*wk[7][1]))));
    Otkr[8][0] = (((Cik[8][2][0]*Otkr[7][2])+((Cik[8][0][0]*Otkr[7][0])+(
      Cik[8][1][0]*Otkr[7][1])))+((pin[8][0]*udotin[8])+((Wik[8][2]*wk[8][1])-(
      Wik[8][1]*wk[8][2]))));
    Otkr[8][1] = (((Cik[8][2][1]*Otkr[7][2])+((Cik[8][0][1]*Otkr[7][0])+(
      Cik[8][1][1]*Otkr[7][1])))+((pin[8][1]*udotin[8])+((Wik[8][0]*wk[8][2])-(
      Wik[8][2]*wk[8][0]))));
    Otkr[8][2] = (((Cik[8][2][2]*Otkr[7][2])+((Cik[8][0][2]*Otkr[7][0])+(
      Cik[8][1][2]*Otkr[7][1])))+((pin[8][2]*udotin[8])+((Wik[8][1]*wk[8][0])-(
      Wik[8][0]*wk[8][1]))));
    Otkr[9][0] = (((Cik[9][2][0]*udotin[5])+((Cik[9][0][0]*udotin[3])+(
      Cik[9][1][0]*udotin[4])))+((pin[9][0]*udotin[9])+((Wik[9][2]*wk[9][1])-(
      Wik[9][1]*wk[9][2]))));
    Otkr[9][1] = (((Cik[9][2][1]*udotin[5])+((Cik[9][0][1]*udotin[3])+(
      Cik[9][1][1]*udotin[4])))+((pin[9][1]*udotin[9])+((Wik[9][0]*wk[9][2])-(
      Wik[9][2]*wk[9][0]))));
    Otkr[9][2] = (((Cik[9][2][2]*udotin[5])+((Cik[9][0][2]*udotin[3])+(
      Cik[9][1][2]*udotin[4])))+((pin[9][2]*udotin[9])+((Wik[9][1]*wk[9][0])-(
      Wik[9][0]*wk[9][1]))));
    Otkr[10][0] = (((Cik[10][2][0]*Otkr[9][2])+((Cik[10][0][0]*Otkr[9][0])+(
      Cik[10][1][0]*Otkr[9][1])))+((pin[10][0]*udotin[10])+((Wik[10][2]*
      wk[10][1])-(Wik[10][1]*wk[10][2]))));
    Otkr[10][1] = (((Cik[10][2][1]*Otkr[9][2])+((Cik[10][0][1]*Otkr[9][0])+(
      Cik[10][1][1]*Otkr[9][1])))+((pin[10][1]*udotin[10])+((Wik[10][0]*
      wk[10][2])-(Wik[10][2]*wk[10][0]))));
    Otkr[10][2] = (((Cik[10][2][2]*Otkr[9][2])+((Cik[10][0][2]*Otkr[9][0])+(
      Cik[10][1][2]*Otkr[9][1])))+((pin[10][2]*udotin[10])+((Wik[10][1]*
      wk[10][0])-(Wik[10][0]*wk[10][1]))));
    Otkr[11][0] = (((Cik[11][2][0]*Otkr[10][2])+((Cik[11][0][0]*Otkr[10][0])+(
      Cik[11][1][0]*Otkr[10][1])))+((pin[11][0]*udotin[11])+((Wik[11][2]*
      wk[11][1])-(Wik[11][1]*wk[11][2]))));
    Otkr[11][1] = (((Cik[11][2][1]*Otkr[10][2])+((Cik[11][0][1]*Otkr[10][0])+(
      Cik[11][1][1]*Otkr[10][1])))+((pin[11][1]*udotin[11])+((Wik[11][0]*
      wk[11][2])-(Wik[11][2]*wk[11][0]))));
    Otkr[11][2] = (((Cik[11][2][2]*Otkr[10][2])+((Cik[11][0][2]*Otkr[10][0])+(
      Cik[11][1][2]*Otkr[10][1])))+((pin[11][2]*udotin[11])+((Wik[11][1]*
      wk[11][0])-(Wik[11][0]*wk[11][1]))));
    Otkr[12][0] = (((Cik[12][2][0]*udotin[5])+((Cik[12][0][0]*udotin[3])+(
      Cik[12][1][0]*udotin[4])))+((pin[12][0]*udotin[12])+((Wik[12][2]*wk[12][1]
      )-(Wik[12][1]*wk[12][2]))));
    Otkr[12][1] = (((Cik[12][2][1]*udotin[5])+((Cik[12][0][1]*udotin[3])+(
      Cik[12][1][1]*udotin[4])))+((pin[12][1]*udotin[12])+((Wik[12][0]*wk[12][2]
      )-(Wik[12][2]*wk[12][0]))));
    Otkr[12][2] = (((Cik[12][2][2]*udotin[5])+((Cik[12][0][2]*udotin[3])+(
      Cik[12][1][2]*udotin[4])))+((pin[12][2]*udotin[12])+((Wik[12][1]*wk[12][0]
      )-(Wik[12][0]*wk[12][1]))));
    Otkr[13][0] = (((Cik[13][2][0]*Otkr[12][2])+((Cik[13][0][0]*Otkr[12][0])+(
      Cik[13][1][0]*Otkr[12][1])))+((pin[13][0]*udotin[13])+((Wik[13][2]*
      wk[13][1])-(Wik[13][1]*wk[13][2]))));
    Otkr[13][1] = (((Cik[13][2][1]*Otkr[12][2])+((Cik[13][0][1]*Otkr[12][0])+(
      Cik[13][1][1]*Otkr[12][1])))+((pin[13][1]*udotin[13])+((Wik[13][0]*
      wk[13][2])-(Wik[13][2]*wk[13][0]))));
    Otkr[13][2] = (((Cik[13][2][2]*Otkr[12][2])+((Cik[13][0][2]*Otkr[12][0])+(
      Cik[13][1][2]*Otkr[12][1])))+((pin[13][2]*udotin[13])+((Wik[13][1]*
      wk[13][0])-(Wik[13][0]*wk[13][1]))));
    Otkr[14][0] = (((Cik[14][2][0]*Otkr[13][2])+((Cik[14][0][0]*Otkr[13][0])+(
      Cik[14][1][0]*Otkr[13][1])))+((pin[14][0]*udotin[14])+((Wik[14][2]*
      wk[14][1])-(Wik[14][1]*wk[14][2]))));
    Otkr[14][1] = (((Cik[14][2][1]*Otkr[13][2])+((Cik[14][0][1]*Otkr[13][0])+(
      Cik[14][1][1]*Otkr[13][1])))+((pin[14][1]*udotin[14])+((Wik[14][0]*
      wk[14][2])-(Wik[14][2]*wk[14][0]))));
    Otkr[14][2] = (((Cik[14][2][2]*Otkr[13][2])+((Cik[14][0][2]*Otkr[13][0])+(
      Cik[14][1][2]*Otkr[13][1])))+((pin[14][2]*udotin[14])+((Wik[14][1]*
      wk[14][0])-(Wik[14][0]*wk[14][1]))));
    Otkr[15][0] = (((Cik[15][2][0]*udotin[5])+((Cik[15][0][0]*udotin[3])+(
      Cik[15][1][0]*udotin[4])))+((pin[15][0]*udotin[15])+((Wik[15][2]*wk[15][1]
      )-(Wik[15][1]*wk[15][2]))));
    Otkr[15][1] = (((Cik[15][2][1]*udotin[5])+((Cik[15][0][1]*udotin[3])+(
      Cik[15][1][1]*udotin[4])))+((pin[15][1]*udotin[15])+((Wik[15][0]*wk[15][2]
      )-(Wik[15][2]*wk[15][0]))));
    Otkr[15][2] = (((Cik[15][2][2]*udotin[5])+((Cik[15][0][2]*udotin[3])+(
      Cik[15][1][2]*udotin[4])))+((pin[15][2]*udotin[15])+((Wik[15][1]*wk[15][0]
      )-(Wik[15][0]*wk[15][1]))));
    Otkr[16][0] = (((Cik[16][2][0]*Otkr[15][2])+((Cik[16][0][0]*Otkr[15][0])+(
      Cik[16][1][0]*Otkr[15][1])))+((pin[16][0]*udotin[16])+((Wik[16][2]*
      wk[16][1])-(Wik[16][1]*wk[16][2]))));
    Otkr[16][1] = (((Cik[16][2][1]*Otkr[15][2])+((Cik[16][0][1]*Otkr[15][0])+(
      Cik[16][1][1]*Otkr[15][1])))+((pin[16][1]*udotin[16])+((Wik[16][0]*
      wk[16][2])-(Wik[16][2]*wk[16][0]))));
    Otkr[16][2] = (((Cik[16][2][2]*Otkr[15][2])+((Cik[16][0][2]*Otkr[15][0])+(
      Cik[16][1][2]*Otkr[15][1])))+((pin[16][2]*udotin[16])+((Wik[16][1]*
      wk[16][0])-(Wik[16][0]*wk[16][1]))));
    Otkr[17][0] = (((Cik[17][2][0]*Otkr[16][2])+((Cik[17][0][0]*Otkr[16][0])+(
      Cik[17][1][0]*Otkr[16][1])))+((pin[17][0]*udotin[17])+((Wik[17][2]*
      wk[17][1])-(Wik[17][1]*wk[17][2]))));
    Otkr[17][1] = (((Cik[17][2][1]*Otkr[16][2])+((Cik[17][0][1]*Otkr[16][0])+(
      Cik[17][1][1]*Otkr[16][1])))+((pin[17][1]*udotin[17])+((Wik[17][0]*
      wk[17][2])-(Wik[17][2]*wk[17][0]))));
    Otkr[17][2] = (((Cik[17][2][2]*Otkr[16][2])+((Cik[17][0][2]*Otkr[16][0])+(
      Cik[17][1][2]*Otkr[16][1])))+((pin[17][2]*udotin[17])+((Wik[17][1]*
      wk[17][0])-(Wik[17][0]*wk[17][1]))));
    Atkr[0][0] = (pin[0][0]*udotin[0]);
    Atkr[0][1] = (pin[0][1]*udotin[0]);
    Atkr[0][2] = (pin[0][2]*udotin[0]);
    Atkr[1][0] = (Atkr[0][0]+(pin[1][0]*udotin[1]));
    Atkr[1][1] = (Atkr[0][1]+(pin[1][1]*udotin[1]));
    Atkr[1][2] = (Atkr[0][2]+(pin[1][2]*udotin[1]));
    Atkr[2][0] = (Atkr[1][0]+(pin[2][0]*udotin[2]));
    Atkr[2][1] = (Atkr[1][1]+(pin[2][1]*udotin[2]));
    Atkr[2][2] = (Atkr[1][2]+(pin[2][2]*udotin[2]));
    Atkr[3][0] = ((Atkr[2][2]*Cik[3][2][0])+((Atkr[2][0]*Cik[3][0][0])+(
      Atkr[2][1]*Cik[3][1][0])));
    Atkr[3][1] = ((Atkr[2][2]*Cik[3][2][1])+((Atkr[2][0]*Cik[3][0][1])+(
      Atkr[2][1]*Cik[3][1][1])));
    Atkr[3][2] = ((Atkr[2][2]*Cik[3][2][2])+((Atkr[2][0]*Cik[3][0][2])+(
      Atkr[2][1]*Cik[3][1][2])));
    Atkr[5][0] = (Atkr[3][0]+(((rk[0][1]*udotin[5])-(rk[0][2]*udotin[4]))+((u[4]
      *Wkrpk[5][2])-(u[5]*Wkrpk[5][1]))));
    Atkr[5][1] = (Atkr[3][1]+(((rk[0][2]*udotin[3])-(rk[0][0]*udotin[5]))+((u[5]
      *Wkrpk[5][0])-(u[3]*Wkrpk[5][2]))));
    Atkr[5][2] = (Atkr[3][2]+(((rk[0][0]*udotin[4])-(rk[0][1]*udotin[3]))+((u[3]
      *Wkrpk[5][1])-(u[4]*Wkrpk[5][0]))));
    Atir[6][0] = (Atkr[5][0]+(((ri[1][2]*udotin[4])-(ri[1][1]*udotin[5]))+((u[4]
      *Wirk[6][2])-(u[5]*Wirk[6][1]))));
    Atir[6][1] = (Atkr[5][1]+(((ri[1][0]*udotin[5])-(ri[1][2]*udotin[3]))+((u[5]
      *Wirk[6][0])-(u[3]*Wirk[6][2]))));
    Atir[6][2] = (Atkr[5][2]+(((ri[1][1]*udotin[3])-(ri[1][0]*udotin[4]))+((u[3]
      *Wirk[6][1])-(u[4]*Wirk[6][0]))));
    Atkr[6][0] = (((Atir[6][2]*Cik[6][2][0])+((Atir[6][0]*Cik[6][0][0])+(
      Atir[6][1]*Cik[6][1][0])))+(((Otkr[6][2]*rk[1][1])-(Otkr[6][1]*rk[1][2]))+
      ((wk[6][1]*Wkrpk[6][2])-(wk[6][2]*Wkrpk[6][1]))));
    Atkr[6][1] = (((Atir[6][2]*Cik[6][2][1])+((Atir[6][0]*Cik[6][0][1])+(
      Atir[6][1]*Cik[6][1][1])))+(((Otkr[6][0]*rk[1][2])-(Otkr[6][2]*rk[1][0]))+
      ((wk[6][2]*Wkrpk[6][0])-(wk[6][0]*Wkrpk[6][2]))));
    Atkr[6][2] = (((Atir[6][2]*Cik[6][2][2])+((Atir[6][0]*Cik[6][0][2])+(
      Atir[6][1]*Cik[6][1][2])))+(((Otkr[6][1]*rk[1][0])-(Otkr[6][0]*rk[1][1]))+
      ((wk[6][0]*Wkrpk[6][1])-(wk[6][1]*Wkrpk[6][0]))));
    Atir[7][0] = (Atkr[6][0]+(((Otkr[6][1]*ri[2][2])-(Otkr[6][2]*ri[2][1]))+((
      Wirk[7][2]*wk[6][1])-(Wirk[7][1]*wk[6][2]))));
    Atir[7][1] = (Atkr[6][1]+(((Otkr[6][2]*ri[2][0])-(Otkr[6][0]*ri[2][2]))+((
      Wirk[7][0]*wk[6][2])-(Wirk[7][2]*wk[6][0]))));
    Atir[7][2] = (Atkr[6][2]+(((Otkr[6][0]*ri[2][1])-(Otkr[6][1]*ri[2][0]))+((
      Wirk[7][1]*wk[6][0])-(Wirk[7][0]*wk[6][1]))));
    Atkr[7][0] = (((Atir[7][2]*Cik[7][2][0])+((Atir[7][0]*Cik[7][0][0])+(
      Atir[7][1]*Cik[7][1][0])))+(((Otkr[7][2]*rk[2][1])-(Otkr[7][1]*rk[2][2]))+
      ((wk[7][1]*Wkrpk[7][2])-(wk[7][2]*Wkrpk[7][1]))));
    Atkr[7][1] = (((Atir[7][2]*Cik[7][2][1])+((Atir[7][0]*Cik[7][0][1])+(
      Atir[7][1]*Cik[7][1][1])))+(((Otkr[7][0]*rk[2][2])-(Otkr[7][2]*rk[2][0]))+
      ((wk[7][2]*Wkrpk[7][0])-(wk[7][0]*Wkrpk[7][2]))));
    Atkr[7][2] = (((Atir[7][2]*Cik[7][2][2])+((Atir[7][0]*Cik[7][0][2])+(
      Atir[7][1]*Cik[7][1][2])))+(((Otkr[7][1]*rk[2][0])-(Otkr[7][0]*rk[2][1]))+
      ((wk[7][0]*Wkrpk[7][1])-(wk[7][1]*Wkrpk[7][0]))));
    Atir[8][0] = (Atkr[7][0]+(((Otkr[7][1]*ri[3][2])-(Otkr[7][2]*ri[3][1]))+((
      Wirk[8][2]*wk[7][1])-(Wirk[8][1]*wk[7][2]))));
    Atir[8][1] = (Atkr[7][1]+(((Otkr[7][2]*ri[3][0])-(Otkr[7][0]*ri[3][2]))+((
      Wirk[8][0]*wk[7][2])-(Wirk[8][2]*wk[7][0]))));
    Atir[8][2] = (Atkr[7][2]+(((Otkr[7][0]*ri[3][1])-(Otkr[7][1]*ri[3][0]))+((
      Wirk[8][1]*wk[7][0])-(Wirk[8][0]*wk[7][1]))));
    Atkr[8][0] = (((Atir[8][2]*Cik[8][2][0])+((Atir[8][0]*Cik[8][0][0])+(
      Atir[8][1]*Cik[8][1][0])))+(((Otkr[8][2]*rk[3][1])-(Otkr[8][1]*rk[3][2]))+
      ((wk[8][1]*Wkrpk[8][2])-(wk[8][2]*Wkrpk[8][1]))));
    Atkr[8][1] = (((Atir[8][2]*Cik[8][2][1])+((Atir[8][0]*Cik[8][0][1])+(
      Atir[8][1]*Cik[8][1][1])))+(((Otkr[8][0]*rk[3][2])-(Otkr[8][2]*rk[3][0]))+
      ((wk[8][2]*Wkrpk[8][0])-(wk[8][0]*Wkrpk[8][2]))));
    Atkr[8][2] = (((Atir[8][2]*Cik[8][2][2])+((Atir[8][0]*Cik[8][0][2])+(
      Atir[8][1]*Cik[8][1][2])))+(((Otkr[8][1]*rk[3][0])-(Otkr[8][0]*rk[3][1]))+
      ((wk[8][0]*Wkrpk[8][1])-(wk[8][1]*Wkrpk[8][0]))));
    Atir[9][0] = (Atkr[5][0]+(((ri[4][2]*udotin[4])-(ri[4][1]*udotin[5]))+((u[4]
      *Wirk[9][2])-(u[5]*Wirk[9][1]))));
    Atir[9][1] = (Atkr[5][1]+(((ri[4][0]*udotin[5])-(ri[4][2]*udotin[3]))+((u[5]
      *Wirk[9][0])-(u[3]*Wirk[9][2]))));
    Atir[9][2] = (Atkr[5][2]+(((ri[4][1]*udotin[3])-(ri[4][0]*udotin[4]))+((u[3]
      *Wirk[9][1])-(u[4]*Wirk[9][0]))));
    Atkr[9][0] = (((Atir[9][2]*Cik[9][2][0])+((Atir[9][0]*Cik[9][0][0])+(
      Atir[9][1]*Cik[9][1][0])))+(((Otkr[9][2]*rk[4][1])-(Otkr[9][1]*rk[4][2]))+
      ((wk[9][1]*Wkrpk[9][2])-(wk[9][2]*Wkrpk[9][1]))));
    Atkr[9][1] = (((Atir[9][2]*Cik[9][2][1])+((Atir[9][0]*Cik[9][0][1])+(
      Atir[9][1]*Cik[9][1][1])))+(((Otkr[9][0]*rk[4][2])-(Otkr[9][2]*rk[4][0]))+
      ((wk[9][2]*Wkrpk[9][0])-(wk[9][0]*Wkrpk[9][2]))));
    Atkr[9][2] = (((Atir[9][2]*Cik[9][2][2])+((Atir[9][0]*Cik[9][0][2])+(
      Atir[9][1]*Cik[9][1][2])))+(((Otkr[9][1]*rk[4][0])-(Otkr[9][0]*rk[4][1]))+
      ((wk[9][0]*Wkrpk[9][1])-(wk[9][1]*Wkrpk[9][0]))));
    Atir[10][0] = (Atkr[9][0]+(((Otkr[9][1]*ri[5][2])-(Otkr[9][2]*ri[5][1]))+((
      Wirk[10][2]*wk[9][1])-(Wirk[10][1]*wk[9][2]))));
    Atir[10][1] = (Atkr[9][1]+(((Otkr[9][2]*ri[5][0])-(Otkr[9][0]*ri[5][2]))+((
      Wirk[10][0]*wk[9][2])-(Wirk[10][2]*wk[9][0]))));
    Atir[10][2] = (Atkr[9][2]+(((Otkr[9][0]*ri[5][1])-(Otkr[9][1]*ri[5][0]))+((
      Wirk[10][1]*wk[9][0])-(Wirk[10][0]*wk[9][1]))));
    Atkr[10][0] = (((Atir[10][2]*Cik[10][2][0])+((Atir[10][0]*Cik[10][0][0])+(
      Atir[10][1]*Cik[10][1][0])))+(((Otkr[10][2]*rk[5][1])-(Otkr[10][1]*
      rk[5][2]))+((wk[10][1]*Wkrpk[10][2])-(wk[10][2]*Wkrpk[10][1]))));
    Atkr[10][1] = (((Atir[10][2]*Cik[10][2][1])+((Atir[10][0]*Cik[10][0][1])+(
      Atir[10][1]*Cik[10][1][1])))+(((Otkr[10][0]*rk[5][2])-(Otkr[10][2]*
      rk[5][0]))+((wk[10][2]*Wkrpk[10][0])-(wk[10][0]*Wkrpk[10][2]))));
    Atkr[10][2] = (((Atir[10][2]*Cik[10][2][2])+((Atir[10][0]*Cik[10][0][2])+(
      Atir[10][1]*Cik[10][1][2])))+(((Otkr[10][1]*rk[5][0])-(Otkr[10][0]*
      rk[5][1]))+((wk[10][0]*Wkrpk[10][1])-(wk[10][1]*Wkrpk[10][0]))));
    Atir[11][0] = (Atkr[10][0]+(((Otkr[10][1]*ri[6][2])-(Otkr[10][2]*ri[6][1]))+
      ((Wirk[11][2]*wk[10][1])-(Wirk[11][1]*wk[10][2]))));
    Atir[11][1] = (Atkr[10][1]+(((Otkr[10][2]*ri[6][0])-(Otkr[10][0]*ri[6][2]))+
      ((Wirk[11][0]*wk[10][2])-(Wirk[11][2]*wk[10][0]))));
    Atir[11][2] = (Atkr[10][2]+(((Otkr[10][0]*ri[6][1])-(Otkr[10][1]*ri[6][0]))+
      ((Wirk[11][1]*wk[10][0])-(Wirk[11][0]*wk[10][1]))));
    Atkr[11][0] = (((Atir[11][2]*Cik[11][2][0])+((Atir[11][0]*Cik[11][0][0])+(
      Atir[11][1]*Cik[11][1][0])))+(((Otkr[11][2]*rk[6][1])-(Otkr[11][1]*
      rk[6][2]))+((wk[11][1]*Wkrpk[11][2])-(wk[11][2]*Wkrpk[11][1]))));
    Atkr[11][1] = (((Atir[11][2]*Cik[11][2][1])+((Atir[11][0]*Cik[11][0][1])+(
      Atir[11][1]*Cik[11][1][1])))+(((Otkr[11][0]*rk[6][2])-(Otkr[11][2]*
      rk[6][0]))+((wk[11][2]*Wkrpk[11][0])-(wk[11][0]*Wkrpk[11][2]))));
    Atkr[11][2] = (((Atir[11][2]*Cik[11][2][2])+((Atir[11][0]*Cik[11][0][2])+(
      Atir[11][1]*Cik[11][1][2])))+(((Otkr[11][1]*rk[6][0])-(Otkr[11][0]*
      rk[6][1]))+((wk[11][0]*Wkrpk[11][1])-(wk[11][1]*Wkrpk[11][0]))));
    Atir[12][0] = (Atkr[5][0]+(((ri[7][2]*udotin[4])-(ri[7][1]*udotin[5]))+((
      u[4]*Wirk[12][2])-(u[5]*Wirk[12][1]))));
    Atir[12][1] = (Atkr[5][1]+(((ri[7][0]*udotin[5])-(ri[7][2]*udotin[3]))+((
      u[5]*Wirk[12][0])-(u[3]*Wirk[12][2]))));
    Atir[12][2] = (Atkr[5][2]+(((ri[7][1]*udotin[3])-(ri[7][0]*udotin[4]))+((
      u[3]*Wirk[12][1])-(u[4]*Wirk[12][0]))));
    Atkr[12][0] = (((Atir[12][2]*Cik[12][2][0])+((Atir[12][0]*Cik[12][0][0])+(
      Atir[12][1]*Cik[12][1][0])))+(((Otkr[12][2]*rk[7][1])-(Otkr[12][1]*
      rk[7][2]))+((wk[12][1]*Wkrpk[12][2])-(wk[12][2]*Wkrpk[12][1]))));
    Atkr[12][1] = (((Atir[12][2]*Cik[12][2][1])+((Atir[12][0]*Cik[12][0][1])+(
      Atir[12][1]*Cik[12][1][1])))+(((Otkr[12][0]*rk[7][2])-(Otkr[12][2]*
      rk[7][0]))+((wk[12][2]*Wkrpk[12][0])-(wk[12][0]*Wkrpk[12][2]))));
    Atkr[12][2] = (((Atir[12][2]*Cik[12][2][2])+((Atir[12][0]*Cik[12][0][2])+(
      Atir[12][1]*Cik[12][1][2])))+(((Otkr[12][1]*rk[7][0])-(Otkr[12][0]*
      rk[7][1]))+((wk[12][0]*Wkrpk[12][1])-(wk[12][1]*Wkrpk[12][0]))));
    Atir[13][0] = (Atkr[12][0]+(((Otkr[12][1]*ri[8][2])-(Otkr[12][2]*ri[8][1]))+
      ((Wirk[13][2]*wk[12][1])-(Wirk[13][1]*wk[12][2]))));
    Atir[13][1] = (Atkr[12][1]+(((Otkr[12][2]*ri[8][0])-(Otkr[12][0]*ri[8][2]))+
      ((Wirk[13][0]*wk[12][2])-(Wirk[13][2]*wk[12][0]))));
    Atir[13][2] = (Atkr[12][2]+(((Otkr[12][0]*ri[8][1])-(Otkr[12][1]*ri[8][0]))+
      ((Wirk[13][1]*wk[12][0])-(Wirk[13][0]*wk[12][1]))));
    Atkr[13][0] = (((Atir[13][2]*Cik[13][2][0])+((Atir[13][0]*Cik[13][0][0])+(
      Atir[13][1]*Cik[13][1][0])))+(((Otkr[13][2]*rk[8][1])-(Otkr[13][1]*
      rk[8][2]))+((wk[13][1]*Wkrpk[13][2])-(wk[13][2]*Wkrpk[13][1]))));
    Atkr[13][1] = (((Atir[13][2]*Cik[13][2][1])+((Atir[13][0]*Cik[13][0][1])+(
      Atir[13][1]*Cik[13][1][1])))+(((Otkr[13][0]*rk[8][2])-(Otkr[13][2]*
      rk[8][0]))+((wk[13][2]*Wkrpk[13][0])-(wk[13][0]*Wkrpk[13][2]))));
    Atkr[13][2] = (((Atir[13][2]*Cik[13][2][2])+((Atir[13][0]*Cik[13][0][2])+(
      Atir[13][1]*Cik[13][1][2])))+(((Otkr[13][1]*rk[8][0])-(Otkr[13][0]*
      rk[8][1]))+((wk[13][0]*Wkrpk[13][1])-(wk[13][1]*Wkrpk[13][0]))));
    Atir[14][0] = (Atkr[13][0]+(((Otkr[13][1]*ri[9][2])-(Otkr[13][2]*ri[9][1]))+
      ((Wirk[14][2]*wk[13][1])-(Wirk[14][1]*wk[13][2]))));
    Atir[14][1] = (Atkr[13][1]+(((Otkr[13][2]*ri[9][0])-(Otkr[13][0]*ri[9][2]))+
      ((Wirk[14][0]*wk[13][2])-(Wirk[14][2]*wk[13][0]))));
    Atir[14][2] = (Atkr[13][2]+(((Otkr[13][0]*ri[9][1])-(Otkr[13][1]*ri[9][0]))+
      ((Wirk[14][1]*wk[13][0])-(Wirk[14][0]*wk[13][1]))));
    Atkr[14][0] = (((Atir[14][2]*Cik[14][2][0])+((Atir[14][0]*Cik[14][0][0])+(
      Atir[14][1]*Cik[14][1][0])))+(((Otkr[14][2]*rk[9][1])-(Otkr[14][1]*
      rk[9][2]))+((wk[14][1]*Wkrpk[14][2])-(wk[14][2]*Wkrpk[14][1]))));
    Atkr[14][1] = (((Atir[14][2]*Cik[14][2][1])+((Atir[14][0]*Cik[14][0][1])+(
      Atir[14][1]*Cik[14][1][1])))+(((Otkr[14][0]*rk[9][2])-(Otkr[14][2]*
      rk[9][0]))+((wk[14][2]*Wkrpk[14][0])-(wk[14][0]*Wkrpk[14][2]))));
    Atkr[14][2] = (((Atir[14][2]*Cik[14][2][2])+((Atir[14][0]*Cik[14][0][2])+(
      Atir[14][1]*Cik[14][1][2])))+(((Otkr[14][1]*rk[9][0])-(Otkr[14][0]*
      rk[9][1]))+((wk[14][0]*Wkrpk[14][1])-(wk[14][1]*Wkrpk[14][0]))));
    Atir[15][0] = (Atkr[5][0]+(((ri[10][2]*udotin[4])-(ri[10][1]*udotin[5]))+((
      u[4]*Wirk[15][2])-(u[5]*Wirk[15][1]))));
    Atir[15][1] = (Atkr[5][1]+(((ri[10][0]*udotin[5])-(ri[10][2]*udotin[3]))+((
      u[5]*Wirk[15][0])-(u[3]*Wirk[15][2]))));
    Atir[15][2] = (Atkr[5][2]+(((ri[10][1]*udotin[3])-(ri[10][0]*udotin[4]))+((
      u[3]*Wirk[15][1])-(u[4]*Wirk[15][0]))));
    Atkr[15][0] = (((Atir[15][2]*Cik[15][2][0])+((Atir[15][0]*Cik[15][0][0])+(
      Atir[15][1]*Cik[15][1][0])))+(((Otkr[15][2]*rk[10][1])-(Otkr[15][1]*
      rk[10][2]))+((wk[15][1]*Wkrpk[15][2])-(wk[15][2]*Wkrpk[15][1]))));
    Atkr[15][1] = (((Atir[15][2]*Cik[15][2][1])+((Atir[15][0]*Cik[15][0][1])+(
      Atir[15][1]*Cik[15][1][1])))+(((Otkr[15][0]*rk[10][2])-(Otkr[15][2]*
      rk[10][0]))+((wk[15][2]*Wkrpk[15][0])-(wk[15][0]*Wkrpk[15][2]))));
    Atkr[15][2] = (((Atir[15][2]*Cik[15][2][2])+((Atir[15][0]*Cik[15][0][2])+(
      Atir[15][1]*Cik[15][1][2])))+(((Otkr[15][1]*rk[10][0])-(Otkr[15][0]*
      rk[10][1]))+((wk[15][0]*Wkrpk[15][1])-(wk[15][1]*Wkrpk[15][0]))));
    Atir[16][0] = (Atkr[15][0]+(((Otkr[15][1]*ri[11][2])-(Otkr[15][2]*ri[11][1])
      )+((Wirk[16][2]*wk[15][1])-(Wirk[16][1]*wk[15][2]))));
    Atir[16][1] = (Atkr[15][1]+(((Otkr[15][2]*ri[11][0])-(Otkr[15][0]*ri[11][2])
      )+((Wirk[16][0]*wk[15][2])-(Wirk[16][2]*wk[15][0]))));
    Atir[16][2] = (Atkr[15][2]+(((Otkr[15][0]*ri[11][1])-(Otkr[15][1]*ri[11][0])
      )+((Wirk[16][1]*wk[15][0])-(Wirk[16][0]*wk[15][1]))));
    Atkr[16][0] = (((Atir[16][2]*Cik[16][2][0])+((Atir[16][0]*Cik[16][0][0])+(
      Atir[16][1]*Cik[16][1][0])))+(((Otkr[16][2]*rk[11][1])-(Otkr[16][1]*
      rk[11][2]))+((wk[16][1]*Wkrpk[16][2])-(wk[16][2]*Wkrpk[16][1]))));
    Atkr[16][1] = (((Atir[16][2]*Cik[16][2][1])+((Atir[16][0]*Cik[16][0][1])+(
      Atir[16][1]*Cik[16][1][1])))+(((Otkr[16][0]*rk[11][2])-(Otkr[16][2]*
      rk[11][0]))+((wk[16][2]*Wkrpk[16][0])-(wk[16][0]*Wkrpk[16][2]))));
    Atkr[16][2] = (((Atir[16][2]*Cik[16][2][2])+((Atir[16][0]*Cik[16][0][2])+(
      Atir[16][1]*Cik[16][1][2])))+(((Otkr[16][1]*rk[11][0])-(Otkr[16][0]*
      rk[11][1]))+((wk[16][0]*Wkrpk[16][1])-(wk[16][1]*Wkrpk[16][0]))));
    Atir[17][0] = (Atkr[16][0]+(((Otkr[16][1]*ri[12][2])-(Otkr[16][2]*ri[12][1])
      )+((Wirk[17][2]*wk[16][1])-(Wirk[17][1]*wk[16][2]))));
    Atir[17][1] = (Atkr[16][1]+(((Otkr[16][2]*ri[12][0])-(Otkr[16][0]*ri[12][2])
      )+((Wirk[17][0]*wk[16][2])-(Wirk[17][2]*wk[16][0]))));
    Atir[17][2] = (Atkr[16][2]+(((Otkr[16][0]*ri[12][1])-(Otkr[16][1]*ri[12][0])
      )+((Wirk[17][1]*wk[16][0])-(Wirk[17][0]*wk[16][1]))));
    Atkr[17][0] = (((Atir[17][2]*Cik[17][2][0])+((Atir[17][0]*Cik[17][0][0])+(
      Atir[17][1]*Cik[17][1][0])))+(((Otkr[17][2]*rk[12][1])-(Otkr[17][1]*
      rk[12][2]))+((wk[17][1]*Wkrpk[17][2])-(wk[17][2]*Wkrpk[17][1]))));
    Atkr[17][1] = (((Atir[17][2]*Cik[17][2][1])+((Atir[17][0]*Cik[17][0][1])+(
      Atir[17][1]*Cik[17][1][1])))+(((Otkr[17][0]*rk[12][2])-(Otkr[17][2]*
      rk[12][0]))+((wk[17][2]*Wkrpk[17][0])-(wk[17][0]*Wkrpk[17][2]))));
    Atkr[17][2] = (((Atir[17][2]*Cik[17][2][2])+((Atir[17][0]*Cik[17][0][2])+(
      Atir[17][1]*Cik[17][1][2])))+(((Otkr[17][1]*rk[12][0])-(Otkr[17][0]*
      rk[12][1]))+((wk[17][0]*Wkrpk[17][1])-(wk[17][1]*Wkrpk[17][0]))));
/*
Accumulate all forces and torques
*/
    fstarr[5][0] = (ufk[0][0]+(mk[0]*(gk[3][0]-Atkr[5][0])));
    fstarr[5][1] = (ufk[0][1]+(mk[0]*(gk[3][1]-Atkr[5][1])));
    fstarr[5][2] = (ufk[0][2]+(mk[0]*(gk[3][2]-Atkr[5][2])));
    fstarr[6][0] = (ufk[1][0]+(mk[1]*(gk[6][0]-Atkr[6][0])));
    fstarr[6][1] = (ufk[1][1]+(mk[1]*(gk[6][1]-Atkr[6][1])));
    fstarr[6][2] = (ufk[1][2]+(mk[1]*(gk[6][2]-Atkr[6][2])));
    fstarr[7][0] = (ufk[2][0]+(mk[2]*(gk[7][0]-Atkr[7][0])));
    fstarr[7][1] = (ufk[2][1]+(mk[2]*(gk[7][1]-Atkr[7][1])));
    fstarr[7][2] = (ufk[2][2]+(mk[2]*(gk[7][2]-Atkr[7][2])));
    fstarr[8][0] = (ufk[3][0]+(mk[3]*(gk[8][0]-Atkr[8][0])));
    fstarr[8][1] = (ufk[3][1]+(mk[3]*(gk[8][1]-Atkr[8][1])));
    fstarr[8][2] = (ufk[3][2]+(mk[3]*(gk[8][2]-Atkr[8][2])));
    fstarr[9][0] = (ufk[4][0]+(mk[4]*(gk[9][0]-Atkr[9][0])));
    fstarr[9][1] = (ufk[4][1]+(mk[4]*(gk[9][1]-Atkr[9][1])));
    fstarr[9][2] = (ufk[4][2]+(mk[4]*(gk[9][2]-Atkr[9][2])));
    fstarr[10][0] = (ufk[5][0]+(mk[5]*(gk[10][0]-Atkr[10][0])));
    fstarr[10][1] = (ufk[5][1]+(mk[5]*(gk[10][1]-Atkr[10][1])));
    fstarr[10][2] = (ufk[5][2]+(mk[5]*(gk[10][2]-Atkr[10][2])));
    fstarr[11][0] = (ufk[6][0]+(mk[6]*(gk[11][0]-Atkr[11][0])));
    fstarr[11][1] = (ufk[6][1]+(mk[6]*(gk[11][1]-Atkr[11][1])));
    fstarr[11][2] = (ufk[6][2]+(mk[6]*(gk[11][2]-Atkr[11][2])));
    fstarr[12][0] = (ufk[7][0]+(mk[7]*(gk[12][0]-Atkr[12][0])));
    fstarr[12][1] = (ufk[7][1]+(mk[7]*(gk[12][1]-Atkr[12][1])));
    fstarr[12][2] = (ufk[7][2]+(mk[7]*(gk[12][2]-Atkr[12][2])));
    fstarr[13][0] = (ufk[8][0]+(mk[8]*(gk[13][0]-Atkr[13][0])));
    fstarr[13][1] = (ufk[8][1]+(mk[8]*(gk[13][1]-Atkr[13][1])));
    fstarr[13][2] = (ufk[8][2]+(mk[8]*(gk[13][2]-Atkr[13][2])));
    fstarr[14][0] = (ufk[9][0]+(mk[9]*(gk[14][0]-Atkr[14][0])));
    fstarr[14][1] = (ufk[9][1]+(mk[9]*(gk[14][1]-Atkr[14][1])));
    fstarr[14][2] = (ufk[9][2]+(mk[9]*(gk[14][2]-Atkr[14][2])));
    fstarr[15][0] = (ufk[10][0]+(mk[10]*(gk[15][0]-Atkr[15][0])));
    fstarr[15][1] = (ufk[10][1]+(mk[10]*(gk[15][1]-Atkr[15][1])));
    fstarr[15][2] = (ufk[10][2]+(mk[10]*(gk[15][2]-Atkr[15][2])));
    fstarr[16][0] = (ufk[11][0]+(mk[11]*(gk[16][0]-Atkr[16][0])));
    fstarr[16][1] = (ufk[11][1]+(mk[11]*(gk[16][1]-Atkr[16][1])));
    fstarr[16][2] = (ufk[11][2]+(mk[11]*(gk[16][2]-Atkr[16][2])));
    fstarr[17][0] = (ufk[12][0]+(mk[12]*(gk[17][0]-Atkr[17][0])));
    fstarr[17][1] = (ufk[12][1]+(mk[12]*(gk[17][1]-Atkr[17][1])));
    fstarr[17][2] = (ufk[12][2]+(mk[12]*(gk[17][2]-Atkr[17][2])));
    tstarr[5][0] = (utk[0][0]-(WkIkWk[5][0]+((ik[0][0][2]*udotin[5])+((
      ik[0][0][0]*udotin[3])+(ik[0][0][1]*udotin[4])))));
    tstarr[5][1] = (utk[0][1]-(WkIkWk[5][1]+((ik[0][1][2]*udotin[5])+((
      ik[0][1][0]*udotin[3])+(ik[0][1][1]*udotin[4])))));
    tstarr[5][2] = (utk[0][2]-(WkIkWk[5][2]+((ik[0][2][2]*udotin[5])+((
      ik[0][2][0]*udotin[3])+(ik[0][2][1]*udotin[4])))));
    tstarr[6][0] = (utk[1][0]-(WkIkWk[6][0]+((ik[1][0][2]*Otkr[6][2])+((
      ik[1][0][0]*Otkr[6][0])+(ik[1][0][1]*Otkr[6][1])))));
    tstarr[6][1] = (utk[1][1]-(WkIkWk[6][1]+((ik[1][1][2]*Otkr[6][2])+((
      ik[1][1][0]*Otkr[6][0])+(ik[1][1][1]*Otkr[6][1])))));
    tstarr[6][2] = (utk[1][2]-(WkIkWk[6][2]+((ik[1][2][2]*Otkr[6][2])+((
      ik[1][2][0]*Otkr[6][0])+(ik[1][2][1]*Otkr[6][1])))));
    tstarr[7][0] = (utk[2][0]-(WkIkWk[7][0]+((ik[2][0][2]*Otkr[7][2])+((
      ik[2][0][0]*Otkr[7][0])+(ik[2][0][1]*Otkr[7][1])))));
    tstarr[7][1] = (utk[2][1]-(WkIkWk[7][1]+((ik[2][1][2]*Otkr[7][2])+((
      ik[2][1][0]*Otkr[7][0])+(ik[2][1][1]*Otkr[7][1])))));
    tstarr[7][2] = (utk[2][2]-(WkIkWk[7][2]+((ik[2][2][2]*Otkr[7][2])+((
      ik[2][2][0]*Otkr[7][0])+(ik[2][2][1]*Otkr[7][1])))));
    tstarr[8][0] = (utk[3][0]-(WkIkWk[8][0]+((ik[3][0][2]*Otkr[8][2])+((
      ik[3][0][0]*Otkr[8][0])+(ik[3][0][1]*Otkr[8][1])))));
    tstarr[8][1] = (utk[3][1]-(WkIkWk[8][1]+((ik[3][1][2]*Otkr[8][2])+((
      ik[3][1][0]*Otkr[8][0])+(ik[3][1][1]*Otkr[8][1])))));
    tstarr[8][2] = (utk[3][2]-(WkIkWk[8][2]+((ik[3][2][2]*Otkr[8][2])+((
      ik[3][2][0]*Otkr[8][0])+(ik[3][2][1]*Otkr[8][1])))));
    tstarr[9][0] = (utk[4][0]-(WkIkWk[9][0]+((ik[4][0][2]*Otkr[9][2])+((
      ik[4][0][0]*Otkr[9][0])+(ik[4][0][1]*Otkr[9][1])))));
    tstarr[9][1] = (utk[4][1]-(WkIkWk[9][1]+((ik[4][1][2]*Otkr[9][2])+((
      ik[4][1][0]*Otkr[9][0])+(ik[4][1][1]*Otkr[9][1])))));
    tstarr[9][2] = (utk[4][2]-(WkIkWk[9][2]+((ik[4][2][2]*Otkr[9][2])+((
      ik[4][2][0]*Otkr[9][0])+(ik[4][2][1]*Otkr[9][1])))));
    tstarr[10][0] = (utk[5][0]-(WkIkWk[10][0]+((ik[5][0][2]*Otkr[10][2])+((
      ik[5][0][0]*Otkr[10][0])+(ik[5][0][1]*Otkr[10][1])))));
    tstarr[10][1] = (utk[5][1]-(WkIkWk[10][1]+((ik[5][1][2]*Otkr[10][2])+((
      ik[5][1][0]*Otkr[10][0])+(ik[5][1][1]*Otkr[10][1])))));
    tstarr[10][2] = (utk[5][2]-(WkIkWk[10][2]+((ik[5][2][2]*Otkr[10][2])+((
      ik[5][2][0]*Otkr[10][0])+(ik[5][2][1]*Otkr[10][1])))));
    tstarr[11][0] = (utk[6][0]-(WkIkWk[11][0]+((ik[6][0][2]*Otkr[11][2])+((
      ik[6][0][0]*Otkr[11][0])+(ik[6][0][1]*Otkr[11][1])))));
    tstarr[11][1] = (utk[6][1]-(WkIkWk[11][1]+((ik[6][1][2]*Otkr[11][2])+((
      ik[6][1][0]*Otkr[11][0])+(ik[6][1][1]*Otkr[11][1])))));
    tstarr[11][2] = (utk[6][2]-(WkIkWk[11][2]+((ik[6][2][2]*Otkr[11][2])+((
      ik[6][2][0]*Otkr[11][0])+(ik[6][2][1]*Otkr[11][1])))));
    tstarr[12][0] = (utk[7][0]-(WkIkWk[12][0]+((ik[7][0][2]*Otkr[12][2])+((
      ik[7][0][0]*Otkr[12][0])+(ik[7][0][1]*Otkr[12][1])))));
    tstarr[12][1] = (utk[7][1]-(WkIkWk[12][1]+((ik[7][1][2]*Otkr[12][2])+((
      ik[7][1][0]*Otkr[12][0])+(ik[7][1][1]*Otkr[12][1])))));
    tstarr[12][2] = (utk[7][2]-(WkIkWk[12][2]+((ik[7][2][2]*Otkr[12][2])+((
      ik[7][2][0]*Otkr[12][0])+(ik[7][2][1]*Otkr[12][1])))));
    tstarr[13][0] = (utk[8][0]-(WkIkWk[13][0]+((ik[8][0][2]*Otkr[13][2])+((
      ik[8][0][0]*Otkr[13][0])+(ik[8][0][1]*Otkr[13][1])))));
    tstarr[13][1] = (utk[8][1]-(WkIkWk[13][1]+((ik[8][1][2]*Otkr[13][2])+((
      ik[8][1][0]*Otkr[13][0])+(ik[8][1][1]*Otkr[13][1])))));
    tstarr[13][2] = (utk[8][2]-(WkIkWk[13][2]+((ik[8][2][2]*Otkr[13][2])+((
      ik[8][2][0]*Otkr[13][0])+(ik[8][2][1]*Otkr[13][1])))));
    tstarr[14][0] = (utk[9][0]-(WkIkWk[14][0]+((ik[9][0][2]*Otkr[14][2])+((
      ik[9][0][0]*Otkr[14][0])+(ik[9][0][1]*Otkr[14][1])))));
    tstarr[14][1] = (utk[9][1]-(WkIkWk[14][1]+((ik[9][1][2]*Otkr[14][2])+((
      ik[9][1][0]*Otkr[14][0])+(ik[9][1][1]*Otkr[14][1])))));
    tstarr[14][2] = (utk[9][2]-(WkIkWk[14][2]+((ik[9][2][2]*Otkr[14][2])+((
      ik[9][2][0]*Otkr[14][0])+(ik[9][2][1]*Otkr[14][1])))));
    tstarr[15][0] = (utk[10][0]-(WkIkWk[15][0]+((ik[10][0][2]*Otkr[15][2])+((
      ik[10][0][0]*Otkr[15][0])+(ik[10][0][1]*Otkr[15][1])))));
    tstarr[15][1] = (utk[10][1]-(WkIkWk[15][1]+((ik[10][1][2]*Otkr[15][2])+((
      ik[10][1][0]*Otkr[15][0])+(ik[10][1][1]*Otkr[15][1])))));
    tstarr[15][2] = (utk[10][2]-(WkIkWk[15][2]+((ik[10][2][2]*Otkr[15][2])+((
      ik[10][2][0]*Otkr[15][0])+(ik[10][2][1]*Otkr[15][1])))));
    tstarr[16][0] = (utk[11][0]-(WkIkWk[16][0]+((ik[11][0][2]*Otkr[16][2])+((
      ik[11][0][0]*Otkr[16][0])+(ik[11][0][1]*Otkr[16][1])))));
    tstarr[16][1] = (utk[11][1]-(WkIkWk[16][1]+((ik[11][1][2]*Otkr[16][2])+((
      ik[11][1][0]*Otkr[16][0])+(ik[11][1][1]*Otkr[16][1])))));
    tstarr[16][2] = (utk[11][2]-(WkIkWk[16][2]+((ik[11][2][2]*Otkr[16][2])+((
      ik[11][2][0]*Otkr[16][0])+(ik[11][2][1]*Otkr[16][1])))));
    tstarr[17][0] = (utk[12][0]-(WkIkWk[17][0]+((ik[12][0][2]*Otkr[17][2])+((
      ik[12][0][0]*Otkr[17][0])+(ik[12][0][1]*Otkr[17][1])))));
    tstarr[17][1] = (utk[12][1]-(WkIkWk[17][1]+((ik[12][1][2]*Otkr[17][2])+((
      ik[12][1][0]*Otkr[17][0])+(ik[12][1][1]*Otkr[17][1])))));
    tstarr[17][2] = (utk[12][2]-(WkIkWk[17][2]+((ik[12][2][2]*Otkr[17][2])+((
      ik[12][2][0]*Otkr[17][0])+(ik[12][2][1]*Otkr[17][1])))));
/*
Now calculate the torques
*/
    sddovpk();
    temp[0] = (((fstarr[8][2]*Vpk[0][8][2])+((fstarr[8][0]*Vpk[0][8][0])+(
      fstarr[8][1]*Vpk[0][8][1])))+(((fstarr[7][2]*Vpk[0][7][2])+((fstarr[7][0]*
      Vpk[0][7][0])+(fstarr[7][1]*Vpk[0][7][1])))+(((fstarr[5][2]*Vpk[0][3][2])+
      ((fstarr[5][0]*Vpk[0][3][0])+(fstarr[5][1]*Vpk[0][3][1])))+((fstarr[6][2]*
      Vpk[0][6][2])+((fstarr[6][0]*Vpk[0][6][0])+(fstarr[6][1]*Vpk[0][6][1])))))
      );
    temp[1] = (((fstarr[12][2]*Vpk[0][12][2])+((fstarr[12][0]*Vpk[0][12][0])+(
      fstarr[12][1]*Vpk[0][12][1])))+(((fstarr[11][2]*Vpk[0][11][2])+((
      fstarr[11][0]*Vpk[0][11][0])+(fstarr[11][1]*Vpk[0][11][1])))+(((
      fstarr[10][2]*Vpk[0][10][2])+((fstarr[10][0]*Vpk[0][10][0])+(fstarr[10][1]
      *Vpk[0][10][1])))+(((fstarr[9][2]*Vpk[0][9][2])+((fstarr[9][0]*
      Vpk[0][9][0])+(fstarr[9][1]*Vpk[0][9][1])))+temp[0]))));
    temp[2] = (((fstarr[16][2]*Vpk[0][16][2])+((fstarr[16][0]*Vpk[0][16][0])+(
      fstarr[16][1]*Vpk[0][16][1])))+(((fstarr[15][2]*Vpk[0][15][2])+((
      fstarr[15][0]*Vpk[0][15][0])+(fstarr[15][1]*Vpk[0][15][1])))+(((
      fstarr[14][2]*Vpk[0][14][2])+((fstarr[14][0]*Vpk[0][14][0])+(fstarr[14][1]
      *Vpk[0][14][1])))+(((fstarr[13][2]*Vpk[0][13][2])+((fstarr[13][0]*
      Vpk[0][13][0])+(fstarr[13][1]*Vpk[0][13][1])))+temp[1]))));
    trqout[0] = -(utau[0]+(((fstarr[17][2]*Vpk[0][17][2])+((fstarr[17][0]*
      Vpk[0][17][0])+(fstarr[17][1]*Vpk[0][17][1])))+temp[2]));
    temp[0] = (((fstarr[8][2]*Vpk[1][8][2])+((fstarr[8][0]*Vpk[1][8][0])+(
      fstarr[8][1]*Vpk[1][8][1])))+(((fstarr[7][2]*Vpk[1][7][2])+((fstarr[7][0]*
      Vpk[1][7][0])+(fstarr[7][1]*Vpk[1][7][1])))+(((fstarr[5][2]*Vpk[1][3][2])+
      ((fstarr[5][0]*Vpk[1][3][0])+(fstarr[5][1]*Vpk[1][3][1])))+((fstarr[6][2]*
      Vpk[1][6][2])+((fstarr[6][0]*Vpk[1][6][0])+(fstarr[6][1]*Vpk[1][6][1])))))
      );
    temp[1] = (((fstarr[12][2]*Vpk[1][12][2])+((fstarr[12][0]*Vpk[1][12][0])+(
      fstarr[12][1]*Vpk[1][12][1])))+(((fstarr[11][2]*Vpk[1][11][2])+((
      fstarr[11][0]*Vpk[1][11][0])+(fstarr[11][1]*Vpk[1][11][1])))+(((
      fstarr[10][2]*Vpk[1][10][2])+((fstarr[10][0]*Vpk[1][10][0])+(fstarr[10][1]
      *Vpk[1][10][1])))+(((fstarr[9][2]*Vpk[1][9][2])+((fstarr[9][0]*
      Vpk[1][9][0])+(fstarr[9][1]*Vpk[1][9][1])))+temp[0]))));
    temp[2] = (((fstarr[16][2]*Vpk[1][16][2])+((fstarr[16][0]*Vpk[1][16][0])+(
      fstarr[16][1]*Vpk[1][16][1])))+(((fstarr[15][2]*Vpk[1][15][2])+((
      fstarr[15][0]*Vpk[1][15][0])+(fstarr[15][1]*Vpk[1][15][1])))+(((
      fstarr[14][2]*Vpk[1][14][2])+((fstarr[14][0]*Vpk[1][14][0])+(fstarr[14][1]
      *Vpk[1][14][1])))+(((fstarr[13][2]*Vpk[1][13][2])+((fstarr[13][0]*
      Vpk[1][13][0])+(fstarr[13][1]*Vpk[1][13][1])))+temp[1]))));
    trqout[1] = -(utau[1]+(((fstarr[17][2]*Vpk[1][17][2])+((fstarr[17][0]*
      Vpk[1][17][0])+(fstarr[17][1]*Vpk[1][17][1])))+temp[2]));
    temp[0] = (((fstarr[8][2]*Vpk[2][8][2])+((fstarr[8][0]*Vpk[2][8][0])+(
      fstarr[8][1]*Vpk[2][8][1])))+(((fstarr[7][2]*Vpk[2][7][2])+((fstarr[7][0]*
      Vpk[2][7][0])+(fstarr[7][1]*Vpk[2][7][1])))+(((fstarr[5][2]*Vpk[2][3][2])+
      ((fstarr[5][0]*Vpk[2][3][0])+(fstarr[5][1]*Vpk[2][3][1])))+((fstarr[6][2]*
      Vpk[2][6][2])+((fstarr[6][0]*Vpk[2][6][0])+(fstarr[6][1]*Vpk[2][6][1])))))
      );
    temp[1] = (((fstarr[12][2]*Vpk[2][12][2])+((fstarr[12][0]*Vpk[2][12][0])+(
      fstarr[12][1]*Vpk[2][12][1])))+(((fstarr[11][2]*Vpk[2][11][2])+((
      fstarr[11][0]*Vpk[2][11][0])+(fstarr[11][1]*Vpk[2][11][1])))+(((
      fstarr[10][2]*Vpk[2][10][2])+((fstarr[10][0]*Vpk[2][10][0])+(fstarr[10][1]
      *Vpk[2][10][1])))+(((fstarr[9][2]*Vpk[2][9][2])+((fstarr[9][0]*
      Vpk[2][9][0])+(fstarr[9][1]*Vpk[2][9][1])))+temp[0]))));
    temp[2] = (((fstarr[16][2]*Vpk[2][16][2])+((fstarr[16][0]*Vpk[2][16][0])+(
      fstarr[16][1]*Vpk[2][16][1])))+(((fstarr[15][2]*Vpk[2][15][2])+((
      fstarr[15][0]*Vpk[2][15][0])+(fstarr[15][1]*Vpk[2][15][1])))+(((
      fstarr[14][2]*Vpk[2][14][2])+((fstarr[14][0]*Vpk[2][14][0])+(fstarr[14][1]
      *Vpk[2][14][1])))+(((fstarr[13][2]*Vpk[2][13][2])+((fstarr[13][0]*
      Vpk[2][13][0])+(fstarr[13][1]*Vpk[2][13][1])))+temp[1]))));
    trqout[2] = -(utau[2]+(((fstarr[17][2]*Vpk[2][17][2])+((fstarr[17][0]*
      Vpk[2][17][0])+(fstarr[17][1]*Vpk[2][17][1])))+temp[2]));
    temp[0] = (((tstarr[5][0]+((fstarr[5][1]*rk[0][2])-(fstarr[5][2]*rk[0][1])))
      +(((Cik[6][0][2]*tstarr[6][2])+((Cik[6][0][0]*tstarr[6][0])+(Cik[6][0][1]*
      tstarr[6][1])))+((fstarr[6][2]*Vpk[3][6][2])+((fstarr[6][0]*Vpk[3][6][0])+
      (fstarr[6][1]*Vpk[3][6][1])))))+(((fstarr[7][2]*Vpk[3][7][2])+((
      fstarr[7][0]*Vpk[3][7][0])+(fstarr[7][1]*Vpk[3][7][1])))+((tstarr[7][2]*
      Wpk[3][7][2])+((tstarr[7][0]*Wpk[3][7][0])+(tstarr[7][1]*Wpk[3][7][1])))))
      ;
    temp[1] = ((((Cik[9][0][2]*tstarr[9][2])+((Cik[9][0][0]*tstarr[9][0])+(
      Cik[9][0][1]*tstarr[9][1])))+((fstarr[9][2]*Vpk[3][9][2])+((fstarr[9][0]*
      Vpk[3][9][0])+(fstarr[9][1]*Vpk[3][9][1]))))+((((fstarr[8][2]*Vpk[3][8][2]
      )+((fstarr[8][0]*Vpk[3][8][0])+(fstarr[8][1]*Vpk[3][8][1])))+((
      tstarr[8][2]*Wpk[3][8][2])+((tstarr[8][0]*Wpk[3][8][0])+(tstarr[8][1]*
      Wpk[3][8][1]))))+temp[0]));
    temp[2] = ((((fstarr[11][2]*Vpk[3][11][2])+((fstarr[11][0]*Vpk[3][11][0])+(
      fstarr[11][1]*Vpk[3][11][1])))+((tstarr[11][2]*Wpk[3][11][2])+((
      tstarr[11][0]*Wpk[3][11][0])+(tstarr[11][1]*Wpk[3][11][1]))))+((((
      fstarr[10][2]*Vpk[3][10][2])+((fstarr[10][0]*Vpk[3][10][0])+(fstarr[10][1]
      *Vpk[3][10][1])))+((tstarr[10][2]*Wpk[3][10][2])+((tstarr[10][0]*
      Wpk[3][10][0])+(tstarr[10][1]*Wpk[3][10][1]))))+temp[1]));
    temp[3] = ((((fstarr[13][2]*Vpk[3][13][2])+((fstarr[13][0]*Vpk[3][13][0])+(
      fstarr[13][1]*Vpk[3][13][1])))+((tstarr[13][2]*Wpk[3][13][2])+((
      tstarr[13][0]*Wpk[3][13][0])+(tstarr[13][1]*Wpk[3][13][1]))))+((((
      Cik[12][0][2]*tstarr[12][2])+((Cik[12][0][0]*tstarr[12][0])+(Cik[12][0][1]
      *tstarr[12][1])))+((fstarr[12][2]*Vpk[3][12][2])+((fstarr[12][0]*
      Vpk[3][12][0])+(fstarr[12][1]*Vpk[3][12][1]))))+temp[2]));
    temp[4] = ((((Cik[15][0][2]*tstarr[15][2])+((Cik[15][0][0]*tstarr[15][0])+(
      Cik[15][0][1]*tstarr[15][1])))+((fstarr[15][2]*Vpk[3][15][2])+((
      fstarr[15][0]*Vpk[3][15][0])+(fstarr[15][1]*Vpk[3][15][1]))))+((((
      fstarr[14][2]*Vpk[3][14][2])+((fstarr[14][0]*Vpk[3][14][0])+(fstarr[14][1]
      *Vpk[3][14][1])))+((tstarr[14][2]*Wpk[3][14][2])+((tstarr[14][0]*
      Wpk[3][14][0])+(tstarr[14][1]*Wpk[3][14][1]))))+temp[3]));
    trqout[3] = -(utau[3]+((((fstarr[17][2]*Vpk[3][17][2])+((fstarr[17][0]*
      Vpk[3][17][0])+(fstarr[17][1]*Vpk[3][17][1])))+((tstarr[17][2]*
      Wpk[3][17][2])+((tstarr[17][0]*Wpk[3][17][0])+(tstarr[17][1]*Wpk[3][17][1]
      ))))+((((fstarr[16][2]*Vpk[3][16][2])+((fstarr[16][0]*Vpk[3][16][0])+(
      fstarr[16][1]*Vpk[3][16][1])))+((tstarr[16][2]*Wpk[3][16][2])+((
      tstarr[16][0]*Wpk[3][16][0])+(tstarr[16][1]*Wpk[3][16][1]))))+temp[4])));
    temp[0] = (((tstarr[5][1]+((fstarr[5][2]*rk[0][0])-(fstarr[5][0]*rk[0][2])))
      +(((Cik[6][1][2]*tstarr[6][2])+((Cik[6][1][0]*tstarr[6][0])+(Cik[6][1][1]*
      tstarr[6][1])))+((fstarr[6][2]*Vpk[4][6][2])+((fstarr[6][0]*Vpk[4][6][0])+
      (fstarr[6][1]*Vpk[4][6][1])))))+(((fstarr[7][2]*Vpk[4][7][2])+((
      fstarr[7][0]*Vpk[4][7][0])+(fstarr[7][1]*Vpk[4][7][1])))+((tstarr[7][2]*
      Wpk[4][7][2])+((tstarr[7][0]*Wpk[4][7][0])+(tstarr[7][1]*Wpk[4][7][1])))))
      ;
    temp[1] = ((((Cik[9][1][2]*tstarr[9][2])+((Cik[9][1][0]*tstarr[9][0])+(
      Cik[9][1][1]*tstarr[9][1])))+((fstarr[9][2]*Vpk[4][9][2])+((fstarr[9][0]*
      Vpk[4][9][0])+(fstarr[9][1]*Vpk[4][9][1]))))+((((fstarr[8][2]*Vpk[4][8][2]
      )+((fstarr[8][0]*Vpk[4][8][0])+(fstarr[8][1]*Vpk[4][8][1])))+((
      tstarr[8][2]*Wpk[4][8][2])+((tstarr[8][0]*Wpk[4][8][0])+(tstarr[8][1]*
      Wpk[4][8][1]))))+temp[0]));
    temp[2] = ((((fstarr[11][2]*Vpk[4][11][2])+((fstarr[11][0]*Vpk[4][11][0])+(
      fstarr[11][1]*Vpk[4][11][1])))+((tstarr[11][2]*Wpk[4][11][2])+((
      tstarr[11][0]*Wpk[4][11][0])+(tstarr[11][1]*Wpk[4][11][1]))))+((((
      fstarr[10][2]*Vpk[4][10][2])+((fstarr[10][0]*Vpk[4][10][0])+(fstarr[10][1]
      *Vpk[4][10][1])))+((tstarr[10][2]*Wpk[4][10][2])+((tstarr[10][0]*
      Wpk[4][10][0])+(tstarr[10][1]*Wpk[4][10][1]))))+temp[1]));
    temp[3] = ((((fstarr[13][2]*Vpk[4][13][2])+((fstarr[13][0]*Vpk[4][13][0])+(
      fstarr[13][1]*Vpk[4][13][1])))+((tstarr[13][2]*Wpk[4][13][2])+((
      tstarr[13][0]*Wpk[4][13][0])+(tstarr[13][1]*Wpk[4][13][1]))))+((((
      Cik[12][1][2]*tstarr[12][2])+((Cik[12][1][0]*tstarr[12][0])+(Cik[12][1][1]
      *tstarr[12][1])))+((fstarr[12][2]*Vpk[4][12][2])+((fstarr[12][0]*
      Vpk[4][12][0])+(fstarr[12][1]*Vpk[4][12][1]))))+temp[2]));
    temp[4] = ((((Cik[15][1][2]*tstarr[15][2])+((Cik[15][1][0]*tstarr[15][0])+(
      Cik[15][1][1]*tstarr[15][1])))+((fstarr[15][2]*Vpk[4][15][2])+((
      fstarr[15][0]*Vpk[4][15][0])+(fstarr[15][1]*Vpk[4][15][1]))))+((((
      fstarr[14][2]*Vpk[4][14][2])+((fstarr[14][0]*Vpk[4][14][0])+(fstarr[14][1]
      *Vpk[4][14][1])))+((tstarr[14][2]*Wpk[4][14][2])+((tstarr[14][0]*
      Wpk[4][14][0])+(tstarr[14][1]*Wpk[4][14][1]))))+temp[3]));
    trqout[4] = -(utau[4]+((((fstarr[17][2]*Vpk[4][17][2])+((fstarr[17][0]*
      Vpk[4][17][0])+(fstarr[17][1]*Vpk[4][17][1])))+((tstarr[17][2]*
      Wpk[4][17][2])+((tstarr[17][0]*Wpk[4][17][0])+(tstarr[17][1]*Wpk[4][17][1]
      ))))+((((fstarr[16][2]*Vpk[4][16][2])+((fstarr[16][0]*Vpk[4][16][0])+(
      fstarr[16][1]*Vpk[4][16][1])))+((tstarr[16][2]*Wpk[4][16][2])+((
      tstarr[16][0]*Wpk[4][16][0])+(tstarr[16][1]*Wpk[4][16][1]))))+temp[4])));
    temp[0] = (((tstarr[5][2]+((fstarr[5][0]*rk[0][1])-(fstarr[5][1]*rk[0][0])))
      +(((Cik[6][2][2]*tstarr[6][2])+((Cik[6][2][0]*tstarr[6][0])+(Cik[6][2][1]*
      tstarr[6][1])))+((fstarr[6][2]*Vpk[5][6][2])+((fstarr[6][0]*Vpk[5][6][0])+
      (fstarr[6][1]*Vpk[5][6][1])))))+(((fstarr[7][2]*Vpk[5][7][2])+((
      fstarr[7][0]*Vpk[5][7][0])+(fstarr[7][1]*Vpk[5][7][1])))+((tstarr[7][2]*
      Wpk[5][7][2])+((tstarr[7][0]*Wpk[5][7][0])+(tstarr[7][1]*Wpk[5][7][1])))))
      ;
    temp[1] = ((((Cik[9][2][2]*tstarr[9][2])+((Cik[9][2][0]*tstarr[9][0])+(
      Cik[9][2][1]*tstarr[9][1])))+((fstarr[9][2]*Vpk[5][9][2])+((fstarr[9][0]*
      Vpk[5][9][0])+(fstarr[9][1]*Vpk[5][9][1]))))+((((fstarr[8][2]*Vpk[5][8][2]
      )+((fstarr[8][0]*Vpk[5][8][0])+(fstarr[8][1]*Vpk[5][8][1])))+((
      tstarr[8][2]*Wpk[5][8][2])+((tstarr[8][0]*Wpk[5][8][0])+(tstarr[8][1]*
      Wpk[5][8][1]))))+temp[0]));
    temp[2] = ((((fstarr[11][2]*Vpk[5][11][2])+((fstarr[11][0]*Vpk[5][11][0])+(
      fstarr[11][1]*Vpk[5][11][1])))+((tstarr[11][2]*Wpk[5][11][2])+((
      tstarr[11][0]*Wpk[5][11][0])+(tstarr[11][1]*Wpk[5][11][1]))))+((((
      fstarr[10][2]*Vpk[5][10][2])+((fstarr[10][0]*Vpk[5][10][0])+(fstarr[10][1]
      *Vpk[5][10][1])))+((tstarr[10][2]*Wpk[5][10][2])+((tstarr[10][0]*
      Wpk[5][10][0])+(tstarr[10][1]*Wpk[5][10][1]))))+temp[1]));
    temp[3] = ((((fstarr[13][2]*Vpk[5][13][2])+((fstarr[13][0]*Vpk[5][13][0])+(
      fstarr[13][1]*Vpk[5][13][1])))+((tstarr[13][2]*Wpk[5][13][2])+((
      tstarr[13][0]*Wpk[5][13][0])+(tstarr[13][1]*Wpk[5][13][1]))))+((((
      Cik[12][2][2]*tstarr[12][2])+((Cik[12][2][0]*tstarr[12][0])+(Cik[12][2][1]
      *tstarr[12][1])))+((fstarr[12][2]*Vpk[5][12][2])+((fstarr[12][0]*
      Vpk[5][12][0])+(fstarr[12][1]*Vpk[5][12][1]))))+temp[2]));
    temp[4] = ((((Cik[15][2][2]*tstarr[15][2])+((Cik[15][2][0]*tstarr[15][0])+(
      Cik[15][2][1]*tstarr[15][1])))+((fstarr[15][2]*Vpk[5][15][2])+((
      fstarr[15][0]*Vpk[5][15][0])+(fstarr[15][1]*Vpk[5][15][1]))))+((((
      fstarr[14][2]*Vpk[5][14][2])+((fstarr[14][0]*Vpk[5][14][0])+(fstarr[14][1]
      *Vpk[5][14][1])))+((tstarr[14][2]*Wpk[5][14][2])+((tstarr[14][0]*
      Wpk[5][14][0])+(tstarr[14][1]*Wpk[5][14][1]))))+temp[3]));
    trqout[5] = -(utau[5]+((((fstarr[17][2]*Vpk[5][17][2])+((fstarr[17][0]*
      Vpk[5][17][0])+(fstarr[17][1]*Vpk[5][17][1])))+((tstarr[17][2]*
      Wpk[5][17][2])+((tstarr[17][0]*Wpk[5][17][0])+(tstarr[17][1]*Wpk[5][17][1]
      ))))+((((fstarr[16][2]*Vpk[5][16][2])+((fstarr[16][0]*Vpk[5][16][0])+(
      fstarr[16][1]*Vpk[5][16][1])))+((tstarr[16][2]*Wpk[5][16][2])+((
      tstarr[16][0]*Wpk[5][16][0])+(tstarr[16][1]*Wpk[5][16][1]))))+temp[4])));
    temp[0] = ((((fstarr[6][2]*Vpk[6][6][2])+((fstarr[6][0]*Vpk[6][6][0])+(
      fstarr[6][1]*Vpk[6][6][1])))+((pin[6][2]*tstarr[6][2])+((pin[6][0]*
      tstarr[6][0])+(pin[6][1]*tstarr[6][1]))))+(((fstarr[7][2]*Vpk[6][7][2])+((
      fstarr[7][0]*Vpk[6][7][0])+(fstarr[7][1]*Vpk[6][7][1])))+((tstarr[7][2]*
      Wpk[6][7][2])+((tstarr[7][0]*Wpk[6][7][0])+(tstarr[7][1]*Wpk[6][7][1])))))
      ;
    trqout[6] = -(utau[6]+((((fstarr[8][2]*Vpk[6][8][2])+((fstarr[8][0]*
      Vpk[6][8][0])+(fstarr[8][1]*Vpk[6][8][1])))+((tstarr[8][2]*Wpk[6][8][2])+(
      (tstarr[8][0]*Wpk[6][8][0])+(tstarr[8][1]*Wpk[6][8][1]))))+temp[0]));
    trqout[7] = -(utau[7]+((((fstarr[7][2]*Vpk[7][7][2])+((fstarr[7][0]*
      Vpk[7][7][0])+(fstarr[7][1]*Vpk[7][7][1])))+((pin[7][2]*tstarr[7][2])+((
      pin[7][0]*tstarr[7][0])+(pin[7][1]*tstarr[7][1]))))+(((fstarr[8][2]*
      Vpk[7][8][2])+((fstarr[8][0]*Vpk[7][8][0])+(fstarr[8][1]*Vpk[7][8][1])))+(
      (tstarr[8][2]*Wpk[7][8][2])+((tstarr[8][0]*Wpk[7][8][0])+(tstarr[8][1]*
      Wpk[7][8][1]))))));
    trqout[8] = -(utau[8]+(((fstarr[8][2]*Vpk[8][8][2])+((fstarr[8][0]*
      Vpk[8][8][0])+(fstarr[8][1]*Vpk[8][8][1])))+((pin[8][2]*tstarr[8][2])+((
      pin[8][0]*tstarr[8][0])+(pin[8][1]*tstarr[8][1])))));
    temp[0] = ((((fstarr[9][2]*Vpk[9][9][2])+((fstarr[9][0]*Vpk[9][9][0])+(
      fstarr[9][1]*Vpk[9][9][1])))+((pin[9][2]*tstarr[9][2])+((pin[9][0]*
      tstarr[9][0])+(pin[9][1]*tstarr[9][1]))))+(((fstarr[10][2]*Vpk[9][10][2])+
      ((fstarr[10][0]*Vpk[9][10][0])+(fstarr[10][1]*Vpk[9][10][1])))+((
      tstarr[10][2]*Wpk[9][10][2])+((tstarr[10][0]*Wpk[9][10][0])+(tstarr[10][1]
      *Wpk[9][10][1])))));
    trqout[9] = -(utau[9]+((((fstarr[11][2]*Vpk[9][11][2])+((fstarr[11][0]*
      Vpk[9][11][0])+(fstarr[11][1]*Vpk[9][11][1])))+((tstarr[11][2]*
      Wpk[9][11][2])+((tstarr[11][0]*Wpk[9][11][0])+(tstarr[11][1]*Wpk[9][11][1]
      ))))+temp[0]));
    trqout[10] = -(utau[10]+((((fstarr[10][2]*Vpk[10][10][2])+((fstarr[10][0]*
      Vpk[10][10][0])+(fstarr[10][1]*Vpk[10][10][1])))+((pin[10][2]*
      tstarr[10][2])+((pin[10][0]*tstarr[10][0])+(pin[10][1]*tstarr[10][1]))))+(
      ((fstarr[11][2]*Vpk[10][11][2])+((fstarr[11][0]*Vpk[10][11][0])+(
      fstarr[11][1]*Vpk[10][11][1])))+((tstarr[11][2]*Wpk[10][11][2])+((
      tstarr[11][0]*Wpk[10][11][0])+(tstarr[11][1]*Wpk[10][11][1]))))));
    trqout[11] = -(utau[11]+(((fstarr[11][2]*Vpk[11][11][2])+((fstarr[11][0]*
      Vpk[11][11][0])+(fstarr[11][1]*Vpk[11][11][1])))+((pin[11][2]*
      tstarr[11][2])+((pin[11][0]*tstarr[11][0])+(pin[11][1]*tstarr[11][1])))));
    temp[0] = ((((fstarr[12][2]*Vpk[12][12][2])+((fstarr[12][0]*Vpk[12][12][0])+
      (fstarr[12][1]*Vpk[12][12][1])))+((pin[12][2]*tstarr[12][2])+((pin[12][0]*
      tstarr[12][0])+(pin[12][1]*tstarr[12][1]))))+(((fstarr[13][2]*
      Vpk[12][13][2])+((fstarr[13][0]*Vpk[12][13][0])+(fstarr[13][1]*
      Vpk[12][13][1])))+((tstarr[13][2]*Wpk[12][13][2])+((tstarr[13][0]*
      Wpk[12][13][0])+(tstarr[13][1]*Wpk[12][13][1])))));
    trqout[12] = -(utau[12]+((((fstarr[14][2]*Vpk[12][14][2])+((fstarr[14][0]*
      Vpk[12][14][0])+(fstarr[14][1]*Vpk[12][14][1])))+((tstarr[14][2]*
      Wpk[12][14][2])+((tstarr[14][0]*Wpk[12][14][0])+(tstarr[14][1]*
      Wpk[12][14][1]))))+temp[0]));
    trqout[13] = -(utau[13]+((((fstarr[13][2]*Vpk[13][13][2])+((fstarr[13][0]*
      Vpk[13][13][0])+(fstarr[13][1]*Vpk[13][13][1])))+((pin[13][2]*
      tstarr[13][2])+((pin[13][0]*tstarr[13][0])+(pin[13][1]*tstarr[13][1]))))+(
      ((fstarr[14][2]*Vpk[13][14][2])+((fstarr[14][0]*Vpk[13][14][0])+(
      fstarr[14][1]*Vpk[13][14][1])))+((tstarr[14][2]*Wpk[13][14][2])+((
      tstarr[14][0]*Wpk[13][14][0])+(tstarr[14][1]*Wpk[13][14][1]))))));
    trqout[14] = -(utau[14]+(((fstarr[14][2]*Vpk[14][14][2])+((fstarr[14][0]*
      Vpk[14][14][0])+(fstarr[14][1]*Vpk[14][14][1])))+((pin[14][2]*
      tstarr[14][2])+((pin[14][0]*tstarr[14][0])+(pin[14][1]*tstarr[14][1])))));
    temp[0] = ((((fstarr[15][2]*Vpk[15][15][2])+((fstarr[15][0]*Vpk[15][15][0])+
      (fstarr[15][1]*Vpk[15][15][1])))+((pin[15][2]*tstarr[15][2])+((pin[15][0]*
      tstarr[15][0])+(pin[15][1]*tstarr[15][1]))))+(((fstarr[16][2]*
      Vpk[15][16][2])+((fstarr[16][0]*Vpk[15][16][0])+(fstarr[16][1]*
      Vpk[15][16][1])))+((tstarr[16][2]*Wpk[15][16][2])+((tstarr[16][0]*
      Wpk[15][16][0])+(tstarr[16][1]*Wpk[15][16][1])))));
    trqout[15] = -(utau[15]+((((fstarr[17][2]*Vpk[15][17][2])+((fstarr[17][0]*
      Vpk[15][17][0])+(fstarr[17][1]*Vpk[15][17][1])))+((tstarr[17][2]*
      Wpk[15][17][2])+((tstarr[17][0]*Wpk[15][17][0])+(tstarr[17][1]*
      Wpk[15][17][1]))))+temp[0]));
    trqout[16] = -(utau[16]+((((fstarr[16][2]*Vpk[16][16][2])+((fstarr[16][0]*
      Vpk[16][16][0])+(fstarr[16][1]*Vpk[16][16][1])))+((pin[16][2]*
      tstarr[16][2])+((pin[16][0]*tstarr[16][0])+(pin[16][1]*tstarr[16][1]))))+(
      ((fstarr[17][2]*Vpk[16][17][2])+((fstarr[17][0]*Vpk[16][17][0])+(
      fstarr[17][1]*Vpk[16][17][1])))+((tstarr[17][2]*Wpk[16][17][2])+((
      tstarr[17][0]*Wpk[16][17][0])+(tstarr[17][1]*Wpk[16][17][1]))))));
    trqout[17] = -(utau[17]+(((fstarr[17][2]*Vpk[17][17][2])+((fstarr[17][0]*
      Vpk[17][17][0])+(fstarr[17][1]*Vpk[17][17][1])))+((pin[17][2]*
      tstarr[17][2])+((pin[17][0]*tstarr[17][0])+(pin[17][1]*tstarr[17][1])))));
/*
Op counts below do not include called subroutines
*/
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1302 adds/subtracts/negates
                   1281 multiplies
                      0 divides
                    247 assignments
*/
}

void sdcomptrq(double udotin[18],
    double trqout[18])
{
/* Compute hinge torques to produce these udots, ignoring constraints
*/
    double multin[1];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(60,23);
        return;
    }
    sdfulltrq(udotin,multin,trqout);
}

void sdmulttrq(double multin[1],
    double trqout[18])
{
/* Compute hinge trqs which would be produced by these mults.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(65,23);
        return;
    }
    for (i = 0; i < 18; i++) {
        trqout[i] = 0.;
    }
}

void sdrhs(void)
{
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

/*
Compute hinge torques for tree hinges
*/
    tauc[0] = utau[0];
    tauc[1] = utau[1];
    tauc[2] = utau[2];
    tauc[3] = utau[3];
    tauc[4] = utau[4];
    tauc[5] = utau[5];
    tauc[6] = utau[6];
    tauc[7] = utau[7];
    tauc[8] = utau[8];
    tauc[9] = utau[9];
    tauc[10] = utau[10];
    tauc[11] = utau[11];
    tauc[12] = utau[12];
    tauc[13] = utau[13];
    tauc[14] = utau[14];
    tauc[15] = utau[15];
    tauc[16] = utau[16];
    tauc[17] = utau[17];
    sddoiner();
/*
Compute onk & onb (angular accels in N)
*/
    Onkb[6][0] = ((pin[6][0]*udot[6])+((Cik[6][2][0]*udot[5])+((Cik[6][0][0]*
      udot[3])+(Cik[6][1][0]*udot[4]))));
    Onkb[6][1] = ((pin[6][1]*udot[6])+((Cik[6][2][1]*udot[5])+((Cik[6][0][1]*
      udot[3])+(Cik[6][1][1]*udot[4]))));
    Onkb[6][2] = ((pin[6][2]*udot[6])+((Cik[6][2][2]*udot[5])+((Cik[6][0][2]*
      udot[3])+(Cik[6][1][2]*udot[4]))));
    Onkb[7][0] = ((pin[7][0]*udot[7])+((Cik[7][2][0]*Onkb[6][2])+((Cik[7][0][0]*
      Onkb[6][0])+(Cik[7][1][0]*Onkb[6][1]))));
    Onkb[7][1] = ((pin[7][1]*udot[7])+((Cik[7][2][1]*Onkb[6][2])+((Cik[7][0][1]*
      Onkb[6][0])+(Cik[7][1][1]*Onkb[6][1]))));
    Onkb[7][2] = ((pin[7][2]*udot[7])+((Cik[7][2][2]*Onkb[6][2])+((Cik[7][0][2]*
      Onkb[6][0])+(Cik[7][1][2]*Onkb[6][1]))));
    Onkb[8][0] = ((pin[8][0]*udot[8])+((Cik[8][2][0]*Onkb[7][2])+((Cik[8][0][0]*
      Onkb[7][0])+(Cik[8][1][0]*Onkb[7][1]))));
    Onkb[8][1] = ((pin[8][1]*udot[8])+((Cik[8][2][1]*Onkb[7][2])+((Cik[8][0][1]*
      Onkb[7][0])+(Cik[8][1][1]*Onkb[7][1]))));
    Onkb[8][2] = ((pin[8][2]*udot[8])+((Cik[8][2][2]*Onkb[7][2])+((Cik[8][0][2]*
      Onkb[7][0])+(Cik[8][1][2]*Onkb[7][1]))));
    Onkb[9][0] = ((pin[9][0]*udot[9])+((Cik[9][2][0]*udot[5])+((Cik[9][0][0]*
      udot[3])+(Cik[9][1][0]*udot[4]))));
    Onkb[9][1] = ((pin[9][1]*udot[9])+((Cik[9][2][1]*udot[5])+((Cik[9][0][1]*
      udot[3])+(Cik[9][1][1]*udot[4]))));
    Onkb[9][2] = ((pin[9][2]*udot[9])+((Cik[9][2][2]*udot[5])+((Cik[9][0][2]*
      udot[3])+(Cik[9][1][2]*udot[4]))));
    Onkb[10][0] = ((pin[10][0]*udot[10])+((Cik[10][2][0]*Onkb[9][2])+((
      Cik[10][0][0]*Onkb[9][0])+(Cik[10][1][0]*Onkb[9][1]))));
    Onkb[10][1] = ((pin[10][1]*udot[10])+((Cik[10][2][1]*Onkb[9][2])+((
      Cik[10][0][1]*Onkb[9][0])+(Cik[10][1][1]*Onkb[9][1]))));
    Onkb[10][2] = ((pin[10][2]*udot[10])+((Cik[10][2][2]*Onkb[9][2])+((
      Cik[10][0][2]*Onkb[9][0])+(Cik[10][1][2]*Onkb[9][1]))));
    Onkb[11][0] = ((pin[11][0]*udot[11])+((Cik[11][2][0]*Onkb[10][2])+((
      Cik[11][0][0]*Onkb[10][0])+(Cik[11][1][0]*Onkb[10][1]))));
    Onkb[11][1] = ((pin[11][1]*udot[11])+((Cik[11][2][1]*Onkb[10][2])+((
      Cik[11][0][1]*Onkb[10][0])+(Cik[11][1][1]*Onkb[10][1]))));
    Onkb[11][2] = ((pin[11][2]*udot[11])+((Cik[11][2][2]*Onkb[10][2])+((
      Cik[11][0][2]*Onkb[10][0])+(Cik[11][1][2]*Onkb[10][1]))));
    Onkb[12][0] = ((pin[12][0]*udot[12])+((Cik[12][2][0]*udot[5])+((
      Cik[12][0][0]*udot[3])+(Cik[12][1][0]*udot[4]))));
    Onkb[12][1] = ((pin[12][1]*udot[12])+((Cik[12][2][1]*udot[5])+((
      Cik[12][0][1]*udot[3])+(Cik[12][1][1]*udot[4]))));
    Onkb[12][2] = ((pin[12][2]*udot[12])+((Cik[12][2][2]*udot[5])+((
      Cik[12][0][2]*udot[3])+(Cik[12][1][2]*udot[4]))));
    Onkb[13][0] = ((pin[13][0]*udot[13])+((Cik[13][2][0]*Onkb[12][2])+((
      Cik[13][0][0]*Onkb[12][0])+(Cik[13][1][0]*Onkb[12][1]))));
    Onkb[13][1] = ((pin[13][1]*udot[13])+((Cik[13][2][1]*Onkb[12][2])+((
      Cik[13][0][1]*Onkb[12][0])+(Cik[13][1][1]*Onkb[12][1]))));
    Onkb[13][2] = ((pin[13][2]*udot[13])+((Cik[13][2][2]*Onkb[12][2])+((
      Cik[13][0][2]*Onkb[12][0])+(Cik[13][1][2]*Onkb[12][1]))));
    Onkb[14][0] = ((pin[14][0]*udot[14])+((Cik[14][2][0]*Onkb[13][2])+((
      Cik[14][0][0]*Onkb[13][0])+(Cik[14][1][0]*Onkb[13][1]))));
    Onkb[14][1] = ((pin[14][1]*udot[14])+((Cik[14][2][1]*Onkb[13][2])+((
      Cik[14][0][1]*Onkb[13][0])+(Cik[14][1][1]*Onkb[13][1]))));
    Onkb[14][2] = ((pin[14][2]*udot[14])+((Cik[14][2][2]*Onkb[13][2])+((
      Cik[14][0][2]*Onkb[13][0])+(Cik[14][1][2]*Onkb[13][1]))));
    Onkb[15][0] = ((pin[15][0]*udot[15])+((Cik[15][2][0]*udot[5])+((
      Cik[15][0][0]*udot[3])+(Cik[15][1][0]*udot[4]))));
    Onkb[15][1] = ((pin[15][1]*udot[15])+((Cik[15][2][1]*udot[5])+((
      Cik[15][0][1]*udot[3])+(Cik[15][1][1]*udot[4]))));
    Onkb[15][2] = ((pin[15][2]*udot[15])+((Cik[15][2][2]*udot[5])+((
      Cik[15][0][2]*udot[3])+(Cik[15][1][2]*udot[4]))));
    Onkb[16][0] = ((pin[16][0]*udot[16])+((Cik[16][2][0]*Onkb[15][2])+((
      Cik[16][0][0]*Onkb[15][0])+(Cik[16][1][0]*Onkb[15][1]))));
    Onkb[16][1] = ((pin[16][1]*udot[16])+((Cik[16][2][1]*Onkb[15][2])+((
      Cik[16][0][1]*Onkb[15][0])+(Cik[16][1][1]*Onkb[15][1]))));
    Onkb[16][2] = ((pin[16][2]*udot[16])+((Cik[16][2][2]*Onkb[15][2])+((
      Cik[16][0][2]*Onkb[15][0])+(Cik[16][1][2]*Onkb[15][1]))));
    Onkb[17][0] = ((pin[17][0]*udot[17])+((Cik[17][2][0]*Onkb[16][2])+((
      Cik[17][0][0]*Onkb[16][0])+(Cik[17][1][0]*Onkb[16][1]))));
    Onkb[17][1] = ((pin[17][1]*udot[17])+((Cik[17][2][1]*Onkb[16][2])+((
      Cik[17][0][1]*Onkb[16][0])+(Cik[17][1][1]*Onkb[16][1]))));
    Onkb[17][2] = ((pin[17][2]*udot[17])+((Cik[17][2][2]*Onkb[16][2])+((
      Cik[17][0][2]*Onkb[16][0])+(Cik[17][1][2]*Onkb[16][1]))));
    onk[6][0] = (Onkb[6][0]+Otk[6][0]);
    onk[6][1] = (Onkb[6][1]+Otk[6][1]);
    onk[6][2] = (Onkb[6][2]+Otk[6][2]);
    onk[7][0] = (Onkb[7][0]+Otk[7][0]);
    onk[7][1] = (Onkb[7][1]+Otk[7][1]);
    onk[7][2] = (Onkb[7][2]+Otk[7][2]);
    onk[8][0] = (Onkb[8][0]+Otk[8][0]);
    onk[8][1] = (Onkb[8][1]+Otk[8][1]);
    onk[8][2] = (Onkb[8][2]+Otk[8][2]);
    onk[9][0] = (Onkb[9][0]+Otk[9][0]);
    onk[9][1] = (Onkb[9][1]+Otk[9][1]);
    onk[9][2] = (Onkb[9][2]+Otk[9][2]);
    onk[10][0] = (Onkb[10][0]+Otk[10][0]);
    onk[10][1] = (Onkb[10][1]+Otk[10][1]);
    onk[10][2] = (Onkb[10][2]+Otk[10][2]);
    onk[11][0] = (Onkb[11][0]+Otk[11][0]);
    onk[11][1] = (Onkb[11][1]+Otk[11][1]);
    onk[11][2] = (Onkb[11][2]+Otk[11][2]);
    onk[12][0] = (Onkb[12][0]+Otk[12][0]);
    onk[12][1] = (Onkb[12][1]+Otk[12][1]);
    onk[12][2] = (Onkb[12][2]+Otk[12][2]);
    onk[13][0] = (Onkb[13][0]+Otk[13][0]);
    onk[13][1] = (Onkb[13][1]+Otk[13][1]);
    onk[13][2] = (Onkb[13][2]+Otk[13][2]);
    onk[14][0] = (Onkb[14][0]+Otk[14][0]);
    onk[14][1] = (Onkb[14][1]+Otk[14][1]);
    onk[14][2] = (Onkb[14][2]+Otk[14][2]);
    onk[15][0] = (Onkb[15][0]+Otk[15][0]);
    onk[15][1] = (Onkb[15][1]+Otk[15][1]);
    onk[15][2] = (Onkb[15][2]+Otk[15][2]);
    onk[16][0] = (Onkb[16][0]+Otk[16][0]);
    onk[16][1] = (Onkb[16][1]+Otk[16][1]);
    onk[16][2] = (Onkb[16][2]+Otk[16][2]);
    onk[17][0] = (Onkb[17][0]+Otk[17][0]);
    onk[17][1] = (Onkb[17][1]+Otk[17][1]);
    onk[17][2] = (Onkb[17][2]+Otk[17][2]);
    onb[0][0] = udot[3];
    onb[0][1] = udot[4];
    onb[0][2] = udot[5];
    onb[1][0] = onk[6][0];
    onb[1][1] = onk[6][1];
    onb[1][2] = onk[6][2];
    onb[2][0] = onk[7][0];
    onb[2][1] = onk[7][1];
    onb[2][2] = onk[7][2];
    onb[3][0] = onk[8][0];
    onb[3][1] = onk[8][1];
    onb[3][2] = onk[8][2];
    onb[4][0] = onk[9][0];
    onb[4][1] = onk[9][1];
    onb[4][2] = onk[9][2];
    onb[5][0] = onk[10][0];
    onb[5][1] = onk[10][1];
    onb[5][2] = onk[10][2];
    onb[6][0] = onk[11][0];
    onb[6][1] = onk[11][1];
    onb[6][2] = onk[11][2];
    onb[7][0] = onk[12][0];
    onb[7][1] = onk[12][1];
    onb[7][2] = onk[12][2];
    onb[8][0] = onk[13][0];
    onb[8][1] = onk[13][1];
    onb[8][2] = onk[13][2];
    onb[9][0] = onk[14][0];
    onb[9][1] = onk[14][1];
    onb[9][2] = onk[14][2];
    onb[10][0] = onk[15][0];
    onb[10][1] = onk[15][1];
    onb[10][2] = onk[15][2];
    onb[11][0] = onk[16][0];
    onb[11][1] = onk[16][1];
    onb[11][2] = onk[16][2];
    onb[12][0] = onk[17][0];
    onb[12][1] = onk[17][1];
    onb[12][2] = onk[17][2];
/*
Compute acceleration dyadics
*/
    dyad[0][0][0] = w11w22[0];
    dyad[0][0][1] = (w0w1[0]-udot[5]);
    dyad[0][0][2] = (udot[4]+w0w2[0]);
    dyad[0][1][0] = (udot[5]+w0w1[0]);
    dyad[0][1][1] = w00w22[0];
    dyad[0][1][2] = (w1w2[0]-udot[3]);
    dyad[0][2][0] = (w0w2[0]-udot[4]);
    dyad[0][2][1] = (udot[3]+w1w2[0]);
    dyad[0][2][2] = w00w11[0];
    dyad[1][0][0] = w11w22[1];
    dyad[1][0][1] = (w0w1[1]-onk[6][2]);
    dyad[1][0][2] = (onk[6][1]+w0w2[1]);
    dyad[1][1][0] = (onk[6][2]+w0w1[1]);
    dyad[1][1][1] = w00w22[1];
    dyad[1][1][2] = (w1w2[1]-onk[6][0]);
    dyad[1][2][0] = (w0w2[1]-onk[6][1]);
    dyad[1][2][1] = (onk[6][0]+w1w2[1]);
    dyad[1][2][2] = w00w11[1];
    dyad[2][0][0] = w11w22[2];
    dyad[2][0][1] = (w0w1[2]-onk[7][2]);
    dyad[2][0][2] = (onk[7][1]+w0w2[2]);
    dyad[2][1][0] = (onk[7][2]+w0w1[2]);
    dyad[2][1][1] = w00w22[2];
    dyad[2][1][2] = (w1w2[2]-onk[7][0]);
    dyad[2][2][0] = (w0w2[2]-onk[7][1]);
    dyad[2][2][1] = (onk[7][0]+w1w2[2]);
    dyad[2][2][2] = w00w11[2];
    dyad[3][0][0] = w11w22[3];
    dyad[3][0][1] = (w0w1[3]-onk[8][2]);
    dyad[3][0][2] = (onk[8][1]+w0w2[3]);
    dyad[3][1][0] = (onk[8][2]+w0w1[3]);
    dyad[3][1][1] = w00w22[3];
    dyad[3][1][2] = (w1w2[3]-onk[8][0]);
    dyad[3][2][0] = (w0w2[3]-onk[8][1]);
    dyad[3][2][1] = (onk[8][0]+w1w2[3]);
    dyad[3][2][2] = w00w11[3];
    dyad[4][0][0] = w11w22[4];
    dyad[4][0][1] = (w0w1[4]-onk[9][2]);
    dyad[4][0][2] = (onk[9][1]+w0w2[4]);
    dyad[4][1][0] = (onk[9][2]+w0w1[4]);
    dyad[4][1][1] = w00w22[4];
    dyad[4][1][2] = (w1w2[4]-onk[9][0]);
    dyad[4][2][0] = (w0w2[4]-onk[9][1]);
    dyad[4][2][1] = (onk[9][0]+w1w2[4]);
    dyad[4][2][2] = w00w11[4];
    dyad[5][0][0] = w11w22[5];
    dyad[5][0][1] = (w0w1[5]-onk[10][2]);
    dyad[5][0][2] = (onk[10][1]+w0w2[5]);
    dyad[5][1][0] = (onk[10][2]+w0w1[5]);
    dyad[5][1][1] = w00w22[5];
    dyad[5][1][2] = (w1w2[5]-onk[10][0]);
    dyad[5][2][0] = (w0w2[5]-onk[10][1]);
    dyad[5][2][1] = (onk[10][0]+w1w2[5]);
    dyad[5][2][2] = w00w11[5];
    dyad[6][0][0] = w11w22[6];
    dyad[6][0][1] = (w0w1[6]-onk[11][2]);
    dyad[6][0][2] = (onk[11][1]+w0w2[6]);
    dyad[6][1][0] = (onk[11][2]+w0w1[6]);
    dyad[6][1][1] = w00w22[6];
    dyad[6][1][2] = (w1w2[6]-onk[11][0]);
    dyad[6][2][0] = (w0w2[6]-onk[11][1]);
    dyad[6][2][1] = (onk[11][0]+w1w2[6]);
    dyad[6][2][2] = w00w11[6];
    dyad[7][0][0] = w11w22[7];
    dyad[7][0][1] = (w0w1[7]-onk[12][2]);
    dyad[7][0][2] = (onk[12][1]+w0w2[7]);
    dyad[7][1][0] = (onk[12][2]+w0w1[7]);
    dyad[7][1][1] = w00w22[7];
    dyad[7][1][2] = (w1w2[7]-onk[12][0]);
    dyad[7][2][0] = (w0w2[7]-onk[12][1]);
    dyad[7][2][1] = (onk[12][0]+w1w2[7]);
    dyad[7][2][2] = w00w11[7];
    dyad[8][0][0] = w11w22[8];
    dyad[8][0][1] = (w0w1[8]-onk[13][2]);
    dyad[8][0][2] = (onk[13][1]+w0w2[8]);
    dyad[8][1][0] = (onk[13][2]+w0w1[8]);
    dyad[8][1][1] = w00w22[8];
    dyad[8][1][2] = (w1w2[8]-onk[13][0]);
    dyad[8][2][0] = (w0w2[8]-onk[13][1]);
    dyad[8][2][1] = (onk[13][0]+w1w2[8]);
    dyad[8][2][2] = w00w11[8];
    dyad[9][0][0] = w11w22[9];
    dyad[9][0][1] = (w0w1[9]-onk[14][2]);
    dyad[9][0][2] = (onk[14][1]+w0w2[9]);
    dyad[9][1][0] = (onk[14][2]+w0w1[9]);
    dyad[9][1][1] = w00w22[9];
    dyad[9][1][2] = (w1w2[9]-onk[14][0]);
    dyad[9][2][0] = (w0w2[9]-onk[14][1]);
    dyad[9][2][1] = (onk[14][0]+w1w2[9]);
    dyad[9][2][2] = w00w11[9];
    dyad[10][0][0] = w11w22[10];
    dyad[10][0][1] = (w0w1[10]-onk[15][2]);
    dyad[10][0][2] = (onk[15][1]+w0w2[10]);
    dyad[10][1][0] = (onk[15][2]+w0w1[10]);
    dyad[10][1][1] = w00w22[10];
    dyad[10][1][2] = (w1w2[10]-onk[15][0]);
    dyad[10][2][0] = (w0w2[10]-onk[15][1]);
    dyad[10][2][1] = (onk[15][0]+w1w2[10]);
    dyad[10][2][2] = w00w11[10];
    dyad[11][0][0] = w11w22[11];
    dyad[11][0][1] = (w0w1[11]-onk[16][2]);
    dyad[11][0][2] = (onk[16][1]+w0w2[11]);
    dyad[11][1][0] = (onk[16][2]+w0w1[11]);
    dyad[11][1][1] = w00w22[11];
    dyad[11][1][2] = (w1w2[11]-onk[16][0]);
    dyad[11][2][0] = (w0w2[11]-onk[16][1]);
    dyad[11][2][1] = (onk[16][0]+w1w2[11]);
    dyad[11][2][2] = w00w11[11];
    dyad[12][0][0] = w11w22[12];
    dyad[12][0][1] = (w0w1[12]-onk[17][2]);
    dyad[12][0][2] = (onk[17][1]+w0w2[12]);
    dyad[12][1][0] = (onk[17][2]+w0w1[12]);
    dyad[12][1][1] = w00w22[12];
    dyad[12][1][2] = (w1w2[12]-onk[17][0]);
    dyad[12][2][0] = (w0w2[12]-onk[17][1]);
    dyad[12][2][1] = (onk[17][0]+w1w2[12]);
    dyad[12][2][2] = w00w11[12];
/*
Compute ank & anb (mass center linear accels in N)
*/
    Ankb[0][0] = (pin[0][0]*udot[0]);
    Ankb[0][1] = (pin[0][1]*udot[0]);
    Ankb[0][2] = (pin[0][2]*udot[0]);
    Ankb[1][0] = (Ankb[0][0]+(pin[1][0]*udot[1]));
    Ankb[1][1] = (Ankb[0][1]+(pin[1][1]*udot[1]));
    Ankb[1][2] = (Ankb[0][2]+(pin[1][2]*udot[1]));
    Ankb[2][0] = (Ankb[1][0]+(pin[2][0]*udot[2]));
    Ankb[2][1] = (Ankb[1][1]+(pin[2][1]*udot[2]));
    Ankb[2][2] = (Ankb[1][2]+(pin[2][2]*udot[2]));
    Ankb[3][0] = ((Ankb[2][2]*Cik[3][2][0])+((Ankb[2][0]*Cik[3][0][0])+(
      Ankb[2][1]*Cik[3][1][0])));
    Ankb[3][1] = ((Ankb[2][2]*Cik[3][2][1])+((Ankb[2][0]*Cik[3][0][1])+(
      Ankb[2][1]*Cik[3][1][1])));
    Ankb[3][2] = ((Ankb[2][2]*Cik[3][2][2])+((Ankb[2][0]*Cik[3][0][2])+(
      Ankb[2][1]*Cik[3][1][2])));
    Ankb[5][0] = (Ankb[3][0]+((rk[0][1]*udot[5])-(rk[0][2]*udot[4])));
    Ankb[5][1] = (Ankb[3][1]+((rk[0][2]*udot[3])-(rk[0][0]*udot[5])));
    Ankb[5][2] = (Ankb[3][2]+((rk[0][0]*udot[4])-(rk[0][1]*udot[3])));
    AOnkri[6][0] = (Ankb[5][0]+((ri[1][2]*udot[4])-(ri[1][1]*udot[5])));
    AOnkri[6][1] = (Ankb[5][1]+((ri[1][0]*udot[5])-(ri[1][2]*udot[3])));
    AOnkri[6][2] = (Ankb[5][2]+((ri[1][1]*udot[3])-(ri[1][0]*udot[4])));
    Ankb[6][0] = (((AOnkri[6][2]*Cik[6][2][0])+((AOnkri[6][0]*Cik[6][0][0])+(
      AOnkri[6][1]*Cik[6][1][0])))+((Onkb[6][2]*rk[1][1])-(Onkb[6][1]*rk[1][2]))
      );
    Ankb[6][1] = (((AOnkri[6][2]*Cik[6][2][1])+((AOnkri[6][0]*Cik[6][0][1])+(
      AOnkri[6][1]*Cik[6][1][1])))+((Onkb[6][0]*rk[1][2])-(Onkb[6][2]*rk[1][0]))
      );
    Ankb[6][2] = (((AOnkri[6][2]*Cik[6][2][2])+((AOnkri[6][0]*Cik[6][0][2])+(
      AOnkri[6][1]*Cik[6][1][2])))+((Onkb[6][1]*rk[1][0])-(Onkb[6][0]*rk[1][1]))
      );
    AOnkri[7][0] = (Ankb[6][0]+((Onkb[6][1]*ri[2][2])-(Onkb[6][2]*ri[2][1])));
    AOnkri[7][1] = (Ankb[6][1]+((Onkb[6][2]*ri[2][0])-(Onkb[6][0]*ri[2][2])));
    AOnkri[7][2] = (Ankb[6][2]+((Onkb[6][0]*ri[2][1])-(Onkb[6][1]*ri[2][0])));
    Ankb[7][0] = (((AOnkri[7][2]*Cik[7][2][0])+((AOnkri[7][0]*Cik[7][0][0])+(
      AOnkri[7][1]*Cik[7][1][0])))+((Onkb[7][2]*rk[2][1])-(Onkb[7][1]*rk[2][2]))
      );
    Ankb[7][1] = (((AOnkri[7][2]*Cik[7][2][1])+((AOnkri[7][0]*Cik[7][0][1])+(
      AOnkri[7][1]*Cik[7][1][1])))+((Onkb[7][0]*rk[2][2])-(Onkb[7][2]*rk[2][0]))
      );
    Ankb[7][2] = (((AOnkri[7][2]*Cik[7][2][2])+((AOnkri[7][0]*Cik[7][0][2])+(
      AOnkri[7][1]*Cik[7][1][2])))+((Onkb[7][1]*rk[2][0])-(Onkb[7][0]*rk[2][1]))
      );
    AOnkri[8][0] = (Ankb[7][0]+((Onkb[7][1]*ri[3][2])-(Onkb[7][2]*ri[3][1])));
    AOnkri[8][1] = (Ankb[7][1]+((Onkb[7][2]*ri[3][0])-(Onkb[7][0]*ri[3][2])));
    AOnkri[8][2] = (Ankb[7][2]+((Onkb[7][0]*ri[3][1])-(Onkb[7][1]*ri[3][0])));
    Ankb[8][0] = (((AOnkri[8][2]*Cik[8][2][0])+((AOnkri[8][0]*Cik[8][0][0])+(
      AOnkri[8][1]*Cik[8][1][0])))+((Onkb[8][2]*rk[3][1])-(Onkb[8][1]*rk[3][2]))
      );
    Ankb[8][1] = (((AOnkri[8][2]*Cik[8][2][1])+((AOnkri[8][0]*Cik[8][0][1])+(
      AOnkri[8][1]*Cik[8][1][1])))+((Onkb[8][0]*rk[3][2])-(Onkb[8][2]*rk[3][0]))
      );
    Ankb[8][2] = (((AOnkri[8][2]*Cik[8][2][2])+((AOnkri[8][0]*Cik[8][0][2])+(
      AOnkri[8][1]*Cik[8][1][2])))+((Onkb[8][1]*rk[3][0])-(Onkb[8][0]*rk[3][1]))
      );
    AOnkri[9][0] = (Ankb[5][0]+((ri[4][2]*udot[4])-(ri[4][1]*udot[5])));
    AOnkri[9][1] = (Ankb[5][1]+((ri[4][0]*udot[5])-(ri[4][2]*udot[3])));
    AOnkri[9][2] = (Ankb[5][2]+((ri[4][1]*udot[3])-(ri[4][0]*udot[4])));
    Ankb[9][0] = (((AOnkri[9][2]*Cik[9][2][0])+((AOnkri[9][0]*Cik[9][0][0])+(
      AOnkri[9][1]*Cik[9][1][0])))+((Onkb[9][2]*rk[4][1])-(Onkb[9][1]*rk[4][2]))
      );
    Ankb[9][1] = (((AOnkri[9][2]*Cik[9][2][1])+((AOnkri[9][0]*Cik[9][0][1])+(
      AOnkri[9][1]*Cik[9][1][1])))+((Onkb[9][0]*rk[4][2])-(Onkb[9][2]*rk[4][0]))
      );
    Ankb[9][2] = (((AOnkri[9][2]*Cik[9][2][2])+((AOnkri[9][0]*Cik[9][0][2])+(
      AOnkri[9][1]*Cik[9][1][2])))+((Onkb[9][1]*rk[4][0])-(Onkb[9][0]*rk[4][1]))
      );
    AOnkri[10][0] = (Ankb[9][0]+((Onkb[9][1]*ri[5][2])-(Onkb[9][2]*ri[5][1])));
    AOnkri[10][1] = (Ankb[9][1]+((Onkb[9][2]*ri[5][0])-(Onkb[9][0]*ri[5][2])));
    AOnkri[10][2] = (Ankb[9][2]+((Onkb[9][0]*ri[5][1])-(Onkb[9][1]*ri[5][0])));
    Ankb[10][0] = (((AOnkri[10][2]*Cik[10][2][0])+((AOnkri[10][0]*Cik[10][0][0])
      +(AOnkri[10][1]*Cik[10][1][0])))+((Onkb[10][2]*rk[5][1])-(Onkb[10][1]*
      rk[5][2])));
    Ankb[10][1] = (((AOnkri[10][2]*Cik[10][2][1])+((AOnkri[10][0]*Cik[10][0][1])
      +(AOnkri[10][1]*Cik[10][1][1])))+((Onkb[10][0]*rk[5][2])-(Onkb[10][2]*
      rk[5][0])));
    Ankb[10][2] = (((AOnkri[10][2]*Cik[10][2][2])+((AOnkri[10][0]*Cik[10][0][2])
      +(AOnkri[10][1]*Cik[10][1][2])))+((Onkb[10][1]*rk[5][0])-(Onkb[10][0]*
      rk[5][1])));
    AOnkri[11][0] = (Ankb[10][0]+((Onkb[10][1]*ri[6][2])-(Onkb[10][2]*ri[6][1]))
      );
    AOnkri[11][1] = (Ankb[10][1]+((Onkb[10][2]*ri[6][0])-(Onkb[10][0]*ri[6][2]))
      );
    AOnkri[11][2] = (Ankb[10][2]+((Onkb[10][0]*ri[6][1])-(Onkb[10][1]*ri[6][0]))
      );
    Ankb[11][0] = (((AOnkri[11][2]*Cik[11][2][0])+((AOnkri[11][0]*Cik[11][0][0])
      +(AOnkri[11][1]*Cik[11][1][0])))+((Onkb[11][2]*rk[6][1])-(Onkb[11][1]*
      rk[6][2])));
    Ankb[11][1] = (((AOnkri[11][2]*Cik[11][2][1])+((AOnkri[11][0]*Cik[11][0][1])
      +(AOnkri[11][1]*Cik[11][1][1])))+((Onkb[11][0]*rk[6][2])-(Onkb[11][2]*
      rk[6][0])));
    Ankb[11][2] = (((AOnkri[11][2]*Cik[11][2][2])+((AOnkri[11][0]*Cik[11][0][2])
      +(AOnkri[11][1]*Cik[11][1][2])))+((Onkb[11][1]*rk[6][0])-(Onkb[11][0]*
      rk[6][1])));
    AOnkri[12][0] = (Ankb[5][0]+((ri[7][2]*udot[4])-(ri[7][1]*udot[5])));
    AOnkri[12][1] = (Ankb[5][1]+((ri[7][0]*udot[5])-(ri[7][2]*udot[3])));
    AOnkri[12][2] = (Ankb[5][2]+((ri[7][1]*udot[3])-(ri[7][0]*udot[4])));
    Ankb[12][0] = (((AOnkri[12][2]*Cik[12][2][0])+((AOnkri[12][0]*Cik[12][0][0])
      +(AOnkri[12][1]*Cik[12][1][0])))+((Onkb[12][2]*rk[7][1])-(Onkb[12][1]*
      rk[7][2])));
    Ankb[12][1] = (((AOnkri[12][2]*Cik[12][2][1])+((AOnkri[12][0]*Cik[12][0][1])
      +(AOnkri[12][1]*Cik[12][1][1])))+((Onkb[12][0]*rk[7][2])-(Onkb[12][2]*
      rk[7][0])));
    Ankb[12][2] = (((AOnkri[12][2]*Cik[12][2][2])+((AOnkri[12][0]*Cik[12][0][2])
      +(AOnkri[12][1]*Cik[12][1][2])))+((Onkb[12][1]*rk[7][0])-(Onkb[12][0]*
      rk[7][1])));
    AOnkri[13][0] = (Ankb[12][0]+((Onkb[12][1]*ri[8][2])-(Onkb[12][2]*ri[8][1]))
      );
    AOnkri[13][1] = (Ankb[12][1]+((Onkb[12][2]*ri[8][0])-(Onkb[12][0]*ri[8][2]))
      );
    AOnkri[13][2] = (Ankb[12][2]+((Onkb[12][0]*ri[8][1])-(Onkb[12][1]*ri[8][0]))
      );
    Ankb[13][0] = (((AOnkri[13][2]*Cik[13][2][0])+((AOnkri[13][0]*Cik[13][0][0])
      +(AOnkri[13][1]*Cik[13][1][0])))+((Onkb[13][2]*rk[8][1])-(Onkb[13][1]*
      rk[8][2])));
    Ankb[13][1] = (((AOnkri[13][2]*Cik[13][2][1])+((AOnkri[13][0]*Cik[13][0][1])
      +(AOnkri[13][1]*Cik[13][1][1])))+((Onkb[13][0]*rk[8][2])-(Onkb[13][2]*
      rk[8][0])));
    Ankb[13][2] = (((AOnkri[13][2]*Cik[13][2][2])+((AOnkri[13][0]*Cik[13][0][2])
      +(AOnkri[13][1]*Cik[13][1][2])))+((Onkb[13][1]*rk[8][0])-(Onkb[13][0]*
      rk[8][1])));
    AOnkri[14][0] = (Ankb[13][0]+((Onkb[13][1]*ri[9][2])-(Onkb[13][2]*ri[9][1]))
      );
    AOnkri[14][1] = (Ankb[13][1]+((Onkb[13][2]*ri[9][0])-(Onkb[13][0]*ri[9][2]))
      );
    AOnkri[14][2] = (Ankb[13][2]+((Onkb[13][0]*ri[9][1])-(Onkb[13][1]*ri[9][0]))
      );
    Ankb[14][0] = (((AOnkri[14][2]*Cik[14][2][0])+((AOnkri[14][0]*Cik[14][0][0])
      +(AOnkri[14][1]*Cik[14][1][0])))+((Onkb[14][2]*rk[9][1])-(Onkb[14][1]*
      rk[9][2])));
    Ankb[14][1] = (((AOnkri[14][2]*Cik[14][2][1])+((AOnkri[14][0]*Cik[14][0][1])
      +(AOnkri[14][1]*Cik[14][1][1])))+((Onkb[14][0]*rk[9][2])-(Onkb[14][2]*
      rk[9][0])));
    Ankb[14][2] = (((AOnkri[14][2]*Cik[14][2][2])+((AOnkri[14][0]*Cik[14][0][2])
      +(AOnkri[14][1]*Cik[14][1][2])))+((Onkb[14][1]*rk[9][0])-(Onkb[14][0]*
      rk[9][1])));
    AOnkri[15][0] = (Ankb[5][0]+((ri[10][2]*udot[4])-(ri[10][1]*udot[5])));
    AOnkri[15][1] = (Ankb[5][1]+((ri[10][0]*udot[5])-(ri[10][2]*udot[3])));
    AOnkri[15][2] = (Ankb[5][2]+((ri[10][1]*udot[3])-(ri[10][0]*udot[4])));
    Ankb[15][0] = (((AOnkri[15][2]*Cik[15][2][0])+((AOnkri[15][0]*Cik[15][0][0])
      +(AOnkri[15][1]*Cik[15][1][0])))+((Onkb[15][2]*rk[10][1])-(Onkb[15][1]*
      rk[10][2])));
    Ankb[15][1] = (((AOnkri[15][2]*Cik[15][2][1])+((AOnkri[15][0]*Cik[15][0][1])
      +(AOnkri[15][1]*Cik[15][1][1])))+((Onkb[15][0]*rk[10][2])-(Onkb[15][2]*
      rk[10][0])));
    Ankb[15][2] = (((AOnkri[15][2]*Cik[15][2][2])+((AOnkri[15][0]*Cik[15][0][2])
      +(AOnkri[15][1]*Cik[15][1][2])))+((Onkb[15][1]*rk[10][0])-(Onkb[15][0]*
      rk[10][1])));
    AOnkri[16][0] = (Ankb[15][0]+((Onkb[15][1]*ri[11][2])-(Onkb[15][2]*ri[11][1]
      )));
    AOnkri[16][1] = (Ankb[15][1]+((Onkb[15][2]*ri[11][0])-(Onkb[15][0]*ri[11][2]
      )));
    AOnkri[16][2] = (Ankb[15][2]+((Onkb[15][0]*ri[11][1])-(Onkb[15][1]*ri[11][0]
      )));
    Ankb[16][0] = (((AOnkri[16][2]*Cik[16][2][0])+((AOnkri[16][0]*Cik[16][0][0])
      +(AOnkri[16][1]*Cik[16][1][0])))+((Onkb[16][2]*rk[11][1])-(Onkb[16][1]*
      rk[11][2])));
    Ankb[16][1] = (((AOnkri[16][2]*Cik[16][2][1])+((AOnkri[16][0]*Cik[16][0][1])
      +(AOnkri[16][1]*Cik[16][1][1])))+((Onkb[16][0]*rk[11][2])-(Onkb[16][2]*
      rk[11][0])));
    Ankb[16][2] = (((AOnkri[16][2]*Cik[16][2][2])+((AOnkri[16][0]*Cik[16][0][2])
      +(AOnkri[16][1]*Cik[16][1][2])))+((Onkb[16][1]*rk[11][0])-(Onkb[16][0]*
      rk[11][1])));
    AOnkri[17][0] = (Ankb[16][0]+((Onkb[16][1]*ri[12][2])-(Onkb[16][2]*ri[12][1]
      )));
    AOnkri[17][1] = (Ankb[16][1]+((Onkb[16][2]*ri[12][0])-(Onkb[16][0]*ri[12][2]
      )));
    AOnkri[17][2] = (Ankb[16][2]+((Onkb[16][0]*ri[12][1])-(Onkb[16][1]*ri[12][0]
      )));
    Ankb[17][0] = (((AOnkri[17][2]*Cik[17][2][0])+((AOnkri[17][0]*Cik[17][0][0])
      +(AOnkri[17][1]*Cik[17][1][0])))+((Onkb[17][2]*rk[12][1])-(Onkb[17][1]*
      rk[12][2])));
    Ankb[17][1] = (((AOnkri[17][2]*Cik[17][2][1])+((AOnkri[17][0]*Cik[17][0][1])
      +(AOnkri[17][1]*Cik[17][1][1])))+((Onkb[17][0]*rk[12][2])-(Onkb[17][2]*
      rk[12][0])));
    Ankb[17][2] = (((AOnkri[17][2]*Cik[17][2][2])+((AOnkri[17][0]*Cik[17][0][2])
      +(AOnkri[17][1]*Cik[17][1][2])))+((Onkb[17][1]*rk[12][0])-(Onkb[17][0]*
      rk[12][1])));
    AnkAtk[5][0] = (Ankb[5][0]+Atk[5][0]);
    AnkAtk[5][1] = (Ankb[5][1]+Atk[5][1]);
    AnkAtk[5][2] = (Ankb[5][2]+Atk[5][2]);
    ank[5][0] = ((AnkAtk[5][2]*Cik[3][0][2])+((AnkAtk[5][0]*Cik[3][0][0])+(
      AnkAtk[5][1]*Cik[3][0][1])));
    ank[5][1] = ((AnkAtk[5][2]*Cik[3][1][2])+((AnkAtk[5][0]*Cik[3][1][0])+(
      AnkAtk[5][1]*Cik[3][1][1])));
    ank[5][2] = ((AnkAtk[5][2]*Cik[3][2][2])+((AnkAtk[5][0]*Cik[3][2][0])+(
      AnkAtk[5][1]*Cik[3][2][1])));
    AnkAtk[6][0] = (Ankb[6][0]+Atk[6][0]);
    AnkAtk[6][1] = (Ankb[6][1]+Atk[6][1]);
    AnkAtk[6][2] = (Ankb[6][2]+Atk[6][2]);
    ank[6][0] = ((AnkAtk[6][2]*cnk[6][0][2])+((AnkAtk[6][0]*cnk[6][0][0])+(
      AnkAtk[6][1]*cnk[6][0][1])));
    ank[6][1] = ((AnkAtk[6][2]*cnk[6][1][2])+((AnkAtk[6][0]*cnk[6][1][0])+(
      AnkAtk[6][1]*cnk[6][1][1])));
    ank[6][2] = ((AnkAtk[6][2]*cnk[6][2][2])+((AnkAtk[6][0]*cnk[6][2][0])+(
      AnkAtk[6][1]*cnk[6][2][1])));
    AnkAtk[7][0] = (Ankb[7][0]+Atk[7][0]);
    AnkAtk[7][1] = (Ankb[7][1]+Atk[7][1]);
    AnkAtk[7][2] = (Ankb[7][2]+Atk[7][2]);
    ank[7][0] = ((AnkAtk[7][2]*cnk[7][0][2])+((AnkAtk[7][0]*cnk[7][0][0])+(
      AnkAtk[7][1]*cnk[7][0][1])));
    ank[7][1] = ((AnkAtk[7][2]*cnk[7][1][2])+((AnkAtk[7][0]*cnk[7][1][0])+(
      AnkAtk[7][1]*cnk[7][1][1])));
    ank[7][2] = ((AnkAtk[7][2]*cnk[7][2][2])+((AnkAtk[7][0]*cnk[7][2][0])+(
      AnkAtk[7][1]*cnk[7][2][1])));
    AnkAtk[8][0] = (Ankb[8][0]+Atk[8][0]);
    AnkAtk[8][1] = (Ankb[8][1]+Atk[8][1]);
    AnkAtk[8][2] = (Ankb[8][2]+Atk[8][2]);
    ank[8][0] = ((AnkAtk[8][2]*cnk[8][0][2])+((AnkAtk[8][0]*cnk[8][0][0])+(
      AnkAtk[8][1]*cnk[8][0][1])));
    ank[8][1] = ((AnkAtk[8][2]*cnk[8][1][2])+((AnkAtk[8][0]*cnk[8][1][0])+(
      AnkAtk[8][1]*cnk[8][1][1])));
    ank[8][2] = ((AnkAtk[8][2]*cnk[8][2][2])+((AnkAtk[8][0]*cnk[8][2][0])+(
      AnkAtk[8][1]*cnk[8][2][1])));
    AnkAtk[9][0] = (Ankb[9][0]+Atk[9][0]);
    AnkAtk[9][1] = (Ankb[9][1]+Atk[9][1]);
    AnkAtk[9][2] = (Ankb[9][2]+Atk[9][2]);
    ank[9][0] = ((AnkAtk[9][2]*cnk[9][0][2])+((AnkAtk[9][0]*cnk[9][0][0])+(
      AnkAtk[9][1]*cnk[9][0][1])));
    ank[9][1] = ((AnkAtk[9][2]*cnk[9][1][2])+((AnkAtk[9][0]*cnk[9][1][0])+(
      AnkAtk[9][1]*cnk[9][1][1])));
    ank[9][2] = ((AnkAtk[9][2]*cnk[9][2][2])+((AnkAtk[9][0]*cnk[9][2][0])+(
      AnkAtk[9][1]*cnk[9][2][1])));
    AnkAtk[10][0] = (Ankb[10][0]+Atk[10][0]);
    AnkAtk[10][1] = (Ankb[10][1]+Atk[10][1]);
    AnkAtk[10][2] = (Ankb[10][2]+Atk[10][2]);
    ank[10][0] = ((AnkAtk[10][2]*cnk[10][0][2])+((AnkAtk[10][0]*cnk[10][0][0])+(
      AnkAtk[10][1]*cnk[10][0][1])));
    ank[10][1] = ((AnkAtk[10][2]*cnk[10][1][2])+((AnkAtk[10][0]*cnk[10][1][0])+(
      AnkAtk[10][1]*cnk[10][1][1])));
    ank[10][2] = ((AnkAtk[10][2]*cnk[10][2][2])+((AnkAtk[10][0]*cnk[10][2][0])+(
      AnkAtk[10][1]*cnk[10][2][1])));
    AnkAtk[11][0] = (Ankb[11][0]+Atk[11][0]);
    AnkAtk[11][1] = (Ankb[11][1]+Atk[11][1]);
    AnkAtk[11][2] = (Ankb[11][2]+Atk[11][2]);
    ank[11][0] = ((AnkAtk[11][2]*cnk[11][0][2])+((AnkAtk[11][0]*cnk[11][0][0])+(
      AnkAtk[11][1]*cnk[11][0][1])));
    ank[11][1] = ((AnkAtk[11][2]*cnk[11][1][2])+((AnkAtk[11][0]*cnk[11][1][0])+(
      AnkAtk[11][1]*cnk[11][1][1])));
    ank[11][2] = ((AnkAtk[11][2]*cnk[11][2][2])+((AnkAtk[11][0]*cnk[11][2][0])+(
      AnkAtk[11][1]*cnk[11][2][1])));
    AnkAtk[12][0] = (Ankb[12][0]+Atk[12][0]);
    AnkAtk[12][1] = (Ankb[12][1]+Atk[12][1]);
    AnkAtk[12][2] = (Ankb[12][2]+Atk[12][2]);
    ank[12][0] = ((AnkAtk[12][2]*cnk[12][0][2])+((AnkAtk[12][0]*cnk[12][0][0])+(
      AnkAtk[12][1]*cnk[12][0][1])));
    ank[12][1] = ((AnkAtk[12][2]*cnk[12][1][2])+((AnkAtk[12][0]*cnk[12][1][0])+(
      AnkAtk[12][1]*cnk[12][1][1])));
    ank[12][2] = ((AnkAtk[12][2]*cnk[12][2][2])+((AnkAtk[12][0]*cnk[12][2][0])+(
      AnkAtk[12][1]*cnk[12][2][1])));
    AnkAtk[13][0] = (Ankb[13][0]+Atk[13][0]);
    AnkAtk[13][1] = (Ankb[13][1]+Atk[13][1]);
    AnkAtk[13][2] = (Ankb[13][2]+Atk[13][2]);
    ank[13][0] = ((AnkAtk[13][2]*cnk[13][0][2])+((AnkAtk[13][0]*cnk[13][0][0])+(
      AnkAtk[13][1]*cnk[13][0][1])));
    ank[13][1] = ((AnkAtk[13][2]*cnk[13][1][2])+((AnkAtk[13][0]*cnk[13][1][0])+(
      AnkAtk[13][1]*cnk[13][1][1])));
    ank[13][2] = ((AnkAtk[13][2]*cnk[13][2][2])+((AnkAtk[13][0]*cnk[13][2][0])+(
      AnkAtk[13][1]*cnk[13][2][1])));
    AnkAtk[14][0] = (Ankb[14][0]+Atk[14][0]);
    AnkAtk[14][1] = (Ankb[14][1]+Atk[14][1]);
    AnkAtk[14][2] = (Ankb[14][2]+Atk[14][2]);
    ank[14][0] = ((AnkAtk[14][2]*cnk[14][0][2])+((AnkAtk[14][0]*cnk[14][0][0])+(
      AnkAtk[14][1]*cnk[14][0][1])));
    ank[14][1] = ((AnkAtk[14][2]*cnk[14][1][2])+((AnkAtk[14][0]*cnk[14][1][0])+(
      AnkAtk[14][1]*cnk[14][1][1])));
    ank[14][2] = ((AnkAtk[14][2]*cnk[14][2][2])+((AnkAtk[14][0]*cnk[14][2][0])+(
      AnkAtk[14][1]*cnk[14][2][1])));
    AnkAtk[15][0] = (Ankb[15][0]+Atk[15][0]);
    AnkAtk[15][1] = (Ankb[15][1]+Atk[15][1]);
    AnkAtk[15][2] = (Ankb[15][2]+Atk[15][2]);
    ank[15][0] = ((AnkAtk[15][2]*cnk[15][0][2])+((AnkAtk[15][0]*cnk[15][0][0])+(
      AnkAtk[15][1]*cnk[15][0][1])));
    ank[15][1] = ((AnkAtk[15][2]*cnk[15][1][2])+((AnkAtk[15][0]*cnk[15][1][0])+(
      AnkAtk[15][1]*cnk[15][1][1])));
    ank[15][2] = ((AnkAtk[15][2]*cnk[15][2][2])+((AnkAtk[15][0]*cnk[15][2][0])+(
      AnkAtk[15][1]*cnk[15][2][1])));
    AnkAtk[16][0] = (Ankb[16][0]+Atk[16][0]);
    AnkAtk[16][1] = (Ankb[16][1]+Atk[16][1]);
    AnkAtk[16][2] = (Ankb[16][2]+Atk[16][2]);
    ank[16][0] = ((AnkAtk[16][2]*cnk[16][0][2])+((AnkAtk[16][0]*cnk[16][0][0])+(
      AnkAtk[16][1]*cnk[16][0][1])));
    ank[16][1] = ((AnkAtk[16][2]*cnk[16][1][2])+((AnkAtk[16][0]*cnk[16][1][0])+(
      AnkAtk[16][1]*cnk[16][1][1])));
    ank[16][2] = ((AnkAtk[16][2]*cnk[16][2][2])+((AnkAtk[16][0]*cnk[16][2][0])+(
      AnkAtk[16][1]*cnk[16][2][1])));
    AnkAtk[17][0] = (Ankb[17][0]+Atk[17][0]);
    AnkAtk[17][1] = (Ankb[17][1]+Atk[17][1]);
    AnkAtk[17][2] = (Ankb[17][2]+Atk[17][2]);
    ank[17][0] = ((AnkAtk[17][2]*cnk[17][0][2])+((AnkAtk[17][0]*cnk[17][0][0])+(
      AnkAtk[17][1]*cnk[17][0][1])));
    ank[17][1] = ((AnkAtk[17][2]*cnk[17][1][2])+((AnkAtk[17][0]*cnk[17][1][0])+(
      AnkAtk[17][1]*cnk[17][1][1])));
    ank[17][2] = ((AnkAtk[17][2]*cnk[17][2][2])+((AnkAtk[17][0]*cnk[17][2][0])+(
      AnkAtk[17][1]*cnk[17][2][1])));
    anb[0][0] = ank[5][0];
    anb[0][1] = ank[5][1];
    anb[0][2] = ank[5][2];
    anb[1][0] = ank[6][0];
    anb[1][1] = ank[6][1];
    anb[1][2] = ank[6][2];
    anb[2][0] = ank[7][0];
    anb[2][1] = ank[7][1];
    anb[2][2] = ank[7][2];
    anb[3][0] = ank[8][0];
    anb[3][1] = ank[8][1];
    anb[3][2] = ank[8][2];
    anb[4][0] = ank[9][0];
    anb[4][1] = ank[9][1];
    anb[4][2] = ank[9][2];
    anb[5][0] = ank[10][0];
    anb[5][1] = ank[10][1];
    anb[5][2] = ank[10][2];
    anb[6][0] = ank[11][0];
    anb[6][1] = ank[11][1];
    anb[6][2] = ank[11][2];
    anb[7][0] = ank[12][0];
    anb[7][1] = ank[12][1];
    anb[7][2] = ank[12][2];
    anb[8][0] = ank[13][0];
    anb[8][1] = ank[13][1];
    anb[8][2] = ank[13][2];
    anb[9][0] = ank[14][0];
    anb[9][1] = ank[14][1];
    anb[9][2] = ank[14][2];
    anb[10][0] = ank[15][0];
    anb[10][1] = ank[15][1];
    anb[10][2] = ank[15][2];
    anb[11][0] = ank[16][0];
    anb[11][1] = ank[16][1];
    anb[11][2] = ank[16][2];
    anb[12][0] = ank[17][0];
    anb[12][1] = ank[17][1];
    anb[12][2] = ank[17][2];
    roustate = 3;
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  573 adds/subtracts/negates
                    537 multiplies
                      0 divides
                    450 assignments
*/
}

void sdmassmat(double mmat[18][18])
{
/* Return the system mass matrix (LHS)
*/
    int i,j;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(57,23);
        return;
    }
    sddomm(57);
    for (i = 0; i < 18; i++) {
        for (j = i; j <= 17; j++) {
            mmat[i][j] = mm[i][j];
            mmat[j][i] = mm[i][j];
        }
    }
}

void sdfrcmat(double fmat[18])
{
/* Return the system force matrix (RHS), excluding constraints
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(58,23);
        return;
    }
    sddofs0();
    for (i = 0; i < 18; i++) {
        fmat[i] = fs0[i];
    }
}

void sdpseudo(double lqout[1],
    double luout[1])
{
/*
Return pseudo-coordinates for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void sdpsqdot(double lqdout[1])
{
/*
Return pseudo-coordinate derivatives for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void sdpsudot(double ludout[1])
{
/*
Return pseudo-coordinate accelerations for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void sdperr(double errs[1])
{

}

void sdverr(double errs[1])
{

}

void sdaerr(double errs[1])
{

}
int 
sdchkbnum(int routine,
    int bnum)
{

    if ((bnum < -1) || (bnum > 12)) {
        sdseterr(routine,15);
        return 1;
    }
    return 0;
}
int 
sdchkjnum(int routine,
    int jnum)
{

    if ((jnum < 0) || (jnum > 12)) {
        sdseterr(routine,16);
        return 1;
    }
    return 0;
}
int 
sdchkucnum(int routine,
    int ucnum)
{

    if ((ucnum < 0) || (ucnum > -1)) {
        sdseterr(routine,21);
        return 1;
    }
    return 0;
}
int 
sdchkjaxis(int routine,
    int jnum,
    int axnum)
{
    int maxax;

    if (sdchkjnum(routine,jnum) != 0) {
        return 1;
    }
    if ((axnum < 0) || (axnum > 6)) {
        sdseterr(routine,17);
        return 1;
    }
    maxax = njntdof[jnum]-1;
    if ((jtype[jnum] == 4) || (jtype[jnum] == 6) || (jtype[jnum] == 21)) {
        maxax = maxax+1;
    }
    if (axnum > maxax) {
        sdseterr(routine,18);
        return 1;
    }
    return 0;
}
int 
sdchkjpin(int routine,
    int jnum,
    int pinno)
{
    int maxax,pinok;

    if (sdchkjnum(routine,jnum) != 0) {
        return 1;
    }
    if ((pinno < 0) || (pinno > 5)) {
        sdseterr(routine,17);
        return 1;
    }
    if (njntdof[jnum] >= 3) {
        maxax = 2;
    } else {
        maxax = njntdof[jnum]-1;
    }
    if (jtype[jnum] == 4) {
        maxax = -1;
    }
    if (jtype[jnum] == 7) {
        maxax = 0;
    }
    pinok = 0;
    if (pinno <= maxax) {
        pinok = 1;
    }
    if (pinok == 0) {
        sdseterr(routine,18);
        return 1;
    }
    return 0;
}
int 
sdindx(int joint,
    int axis)
{
    int offs,gotit;

    if (sdchkjaxis(36,joint,axis) != 0) {
        return 0;
    }
    gotit = 0;
    if (jtype[joint] == 4) {
        if (axis == 3) {
            offs = ballq[joint];
            gotit = 1;
        }
    } else {
        if ((jtype[joint] == 6) || (jtype[joint] == 21)) {
            if (axis == 6) {
                offs = ballq[joint];
                gotit = 1;
            }
        }
    }
    if (gotit == 0) {
        offs = firstq[joint]+axis;
    }
    return offs;
}

void sdpresacc(int joint,
    int axis,
    double prval)
{

}

void sdpresvel(int joint,
    int axis,
    double prval)
{

}

void sdprespos(int joint,
    int axis,
    double prval)
{

}

void sdgetht(int joint,
    int axis,
    double *torque)
{

    if (sdchkjaxis(30,joint,axis) != 0) {
        return;
    }
    if (roustate != 3) {
        sdseterr(30,24);
        return;
    }
    *torque = tauc[sdindx(joint,axis)];
}

void sdhinget(int joint,
    int axis,
    double torque)
{

    if (sdchkjaxis(10,joint,axis) != 0) {
        return;
    }
    if (roustate != 2) {
        sdseterr(10,23);
        return;
    }
    if (mfrcflg != 0) {
        mtau[sdindx(joint,axis)] = mtau[sdindx(joint,axis)]+torque;
    } else {
        fs0flg = 0;
        utau[sdindx(joint,axis)] = utau[sdindx(joint,axis)]+torque;
    }
}

void sdpointf(int body,
    double point[3],
    double force[3])
{
    double torque[3];

    if (sdchkbnum(11,body) != 0) {
        return;
    }
    if (roustate != 2) {
        sdseterr(11,23);
        return;
    }
    if (body == -1) {
        return;
    }
    torque[0] = point[1]*force[2]-point[2]*force[1];
    torque[1] = point[2]*force[0]-point[0]*force[2];
    torque[2] = point[0]*force[1]-point[1]*force[0];
    if (mfrcflg != 0) {
        mfk[body][0] = mfk[body][0]+force[0];
        mtk[body][0] = mtk[body][0]+torque[0];
        mfk[body][1] = mfk[body][1]+force[1];
        mtk[body][1] = mtk[body][1]+torque[1];
        mfk[body][2] = mfk[body][2]+force[2];
        mtk[body][2] = mtk[body][2]+torque[2];
    } else {
        fs0flg = 0;
        ufk[body][0] = ufk[body][0]+force[0];
        utk[body][0] = utk[body][0]+torque[0];
        ufk[body][1] = ufk[body][1]+force[1];
        utk[body][1] = utk[body][1]+torque[1];
        ufk[body][2] = ufk[body][2]+force[2];
        utk[body][2] = utk[body][2]+torque[2];
    }
}

void sdbodyt(int body,
    double torque[3])
{

    if (sdchkbnum(12,body) != 0) {
        return;
    }
    if (roustate != 2) {
        sdseterr(12,23);
        return;
    }
    if (body == -1) {
        return;
    }
    if (mfrcflg != 0) {
        mtk[body][0] = mtk[body][0]+torque[0];
        mtk[body][1] = mtk[body][1]+torque[1];
        mtk[body][2] = mtk[body][2]+torque[2];
    } else {
        fs0flg = 0;
        utk[body][0] = utk[body][0]+torque[0];
        utk[body][1] = utk[body][1]+torque[1];
        utk[body][2] = utk[body][2]+torque[2];
    }
}

void sddoww(int routine)
{

    roustate = 2;
    if (wwflg == 0) {
        wwflg = 1;
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                      0 assignments
*/
}

void sdxudot0(int routine,
    double oudot0[18])
{
/*
Compute unconstrained equations
*/
    int i;

    sdlhs(routine);
/*
Solve equations for udots
*/
    sdfs0();
    sdldubslv(18,18,mmap,works,mlo,mdi,fs,udot);
    for (i = 0; i <= 17; i++) {
        oudot0[i] = udot[i];
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     18 assignments
*/
}

void sdudot0(double oudot0[18])
{

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(66,23);
        return;
    }
    sdxudot0(66,oudot0);
}

void sdsetudot(double iudot[18])
{
/*
Assign udots and advance to stage Dynamics Ready
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(68,23);
        return;
    }
    for (i = 0; i <= 17; i++) {
        udot[i] = iudot[i];
    }
    sdrhs();
}

void sdxudotm(int routine,
    double imult[1],
    double oudotm[18])
{
/*
Compute udots due only to multipliers
*/
    int i;

    sdlhs(routine);
    for (i = 0; i <= 17; i++) {
        udot[i] = 0.;
    }
    for (i = 0; i <= 17; i++) {
        oudotm[i] = udot[i];
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     36 assignments
*/
}

void sdudotm(double imult[1],
    double oudotm[18])
{

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(67,23);
        return;
    }
    sdxudotm(67,imult,oudotm);
}

void sdderiv(double oqdot[19],
    double oudot[18])
{
/*
This is the derivative section for a 13-body ground-based
system with 18 hinge degree(s) of freedom.
*/
    int i;
    double udot0[18],udot1[18];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(17,23);
        return;
    }
    if (stabvelq == 1) {
        sdseterr(17,32);
    }
    if (stabposq == 1) {
        sdseterr(17,33);
    }
    wsiz = 0;
/*
Compute unconstrained equations
*/
    sdxudot0(17,udot0);
    sdrhs();
    wrank = 0;
    for (i = 0; i <= 18; i++) {
        oqdot[i] = qdot[i];
    }
    for (i = 0; i <= 17; i++) {
        oudot[i] = udot[i];
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     37 assignments
*/
}
/*
Compute residuals for use with DAE integrator
*/

void sdresid(double eqdot[19],
    double eudot[18],
    double emults[1],
    double resid[37])
{
    int i;
    double uderrs[18];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(16,23);
        return;
    }
    if (stabposq == 1) {
        sdseterr(16,33);
    }
    sdfulltrq(eudot,emults,uderrs);
    for (i = 0; i < 19; i++) {
        resid[i] = eqdot[i]-qdot[i];
    }
    for (i = 0; i < 18; i++) {
        resid[19+i] = uderrs[i];
    }
    for (i = 0; i < 18; i++) {
        udot[i] = eudot[i];
    }
    sdrhs();
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   19 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     55 assignments
*/
}

void sdmult(double omults[1],
    int *owrank,
    int omultmap[1])
{

    if (roustate != 3) {
        sdseterr(34,24);
        return;
    }
    *owrank = wrank;
}

void sdreac(double force[13][3],
    double torque[13][3])
{
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

    if (roustate != 3) {
        sdseterr(31,24);
        return;
    }
/*
Compute reaction forces for non-weld tree joints
*/
    fc[17][0] = ((mk[12]*(AnkAtk[17][0]-gk[17][0]))-ufk[12][0]);
    fc[17][1] = ((mk[12]*(AnkAtk[17][1]-gk[17][1]))-ufk[12][1]);
    fc[17][2] = ((mk[12]*(AnkAtk[17][2]-gk[17][2]))-ufk[12][2]);
    tc[17][0] = ((WkIkWk[17][0]+((ik[12][0][2]*onk[17][2])+((ik[12][0][0]*
      onk[17][0])+(ik[12][0][1]*onk[17][1]))))-(utk[12][0]+((fc[17][2]*rk[12][1]
      )-(fc[17][1]*rk[12][2]))));
    tc[17][1] = ((WkIkWk[17][1]+((ik[12][1][2]*onk[17][2])+((ik[12][1][0]*
      onk[17][0])+(ik[12][1][1]*onk[17][1]))))-(utk[12][1]+((fc[17][0]*rk[12][2]
      )-(fc[17][2]*rk[12][0]))));
    tc[17][2] = ((WkIkWk[17][2]+((ik[12][2][2]*onk[17][2])+((ik[12][2][0]*
      onk[17][0])+(ik[12][2][1]*onk[17][1]))))-(utk[12][2]+((fc[17][1]*rk[12][0]
      )-(fc[17][0]*rk[12][1]))));
    fccikt[17][0] = ((Cik[17][0][2]*fc[17][2])+((Cik[17][0][0]*fc[17][0])+(
      Cik[17][0][1]*fc[17][1])));
    fccikt[17][1] = ((Cik[17][1][2]*fc[17][2])+((Cik[17][1][0]*fc[17][0])+(
      Cik[17][1][1]*fc[17][1])));
    fccikt[17][2] = ((Cik[17][2][2]*fc[17][2])+((Cik[17][2][0]*fc[17][0])+(
      Cik[17][2][1]*fc[17][1])));
    ffk[16][0] = (ufk[11][0]-fccikt[17][0]);
    ffk[16][1] = (ufk[11][1]-fccikt[17][1]);
    ffk[16][2] = (ufk[11][2]-fccikt[17][2]);
    ttk[16][0] = (utk[11][0]-(((Cik[17][0][2]*tc[17][2])+((Cik[17][0][0]*
      tc[17][0])+(Cik[17][0][1]*tc[17][1])))+((fccikt[17][2]*ri[12][1])-(
      fccikt[17][1]*ri[12][2]))));
    ttk[16][1] = (utk[11][1]-(((Cik[17][1][2]*tc[17][2])+((Cik[17][1][0]*
      tc[17][0])+(Cik[17][1][1]*tc[17][1])))+((fccikt[17][0]*ri[12][2])-(
      fccikt[17][2]*ri[12][0]))));
    ttk[16][2] = (utk[11][2]-(((Cik[17][2][2]*tc[17][2])+((Cik[17][2][0]*
      tc[17][0])+(Cik[17][2][1]*tc[17][1])))+((fccikt[17][1]*ri[12][0])-(
      fccikt[17][0]*ri[12][1]))));
    fc[16][0] = ((mk[11]*(AnkAtk[16][0]-gk[16][0]))-ffk[16][0]);
    fc[16][1] = ((mk[11]*(AnkAtk[16][1]-gk[16][1]))-ffk[16][1]);
    fc[16][2] = ((mk[11]*(AnkAtk[16][2]-gk[16][2]))-ffk[16][2]);
    tc[16][0] = ((WkIkWk[16][0]+((ik[11][0][2]*onk[16][2])+((ik[11][0][0]*
      onk[16][0])+(ik[11][0][1]*onk[16][1]))))-(ttk[16][0]+((fc[16][2]*rk[11][1]
      )-(fc[16][1]*rk[11][2]))));
    tc[16][1] = ((WkIkWk[16][1]+((ik[11][1][2]*onk[16][2])+((ik[11][1][0]*
      onk[16][0])+(ik[11][1][1]*onk[16][1]))))-(ttk[16][1]+((fc[16][0]*rk[11][2]
      )-(fc[16][2]*rk[11][0]))));
    tc[16][2] = ((WkIkWk[16][2]+((ik[11][2][2]*onk[16][2])+((ik[11][2][0]*
      onk[16][0])+(ik[11][2][1]*onk[16][1]))))-(ttk[16][2]+((fc[16][1]*rk[11][0]
      )-(fc[16][0]*rk[11][1]))));
    fccikt[16][0] = ((Cik[16][0][2]*fc[16][2])+((Cik[16][0][0]*fc[16][0])+(
      Cik[16][0][1]*fc[16][1])));
    fccikt[16][1] = ((Cik[16][1][2]*fc[16][2])+((Cik[16][1][0]*fc[16][0])+(
      Cik[16][1][1]*fc[16][1])));
    fccikt[16][2] = ((Cik[16][2][2]*fc[16][2])+((Cik[16][2][0]*fc[16][0])+(
      Cik[16][2][1]*fc[16][1])));
    ffk[15][0] = (ufk[10][0]-fccikt[16][0]);
    ffk[15][1] = (ufk[10][1]-fccikt[16][1]);
    ffk[15][2] = (ufk[10][2]-fccikt[16][2]);
    ttk[15][0] = (utk[10][0]-(((Cik[16][0][2]*tc[16][2])+((Cik[16][0][0]*
      tc[16][0])+(Cik[16][0][1]*tc[16][1])))+((fccikt[16][2]*ri[11][1])-(
      fccikt[16][1]*ri[11][2]))));
    ttk[15][1] = (utk[10][1]-(((Cik[16][1][2]*tc[16][2])+((Cik[16][1][0]*
      tc[16][0])+(Cik[16][1][1]*tc[16][1])))+((fccikt[16][0]*ri[11][2])-(
      fccikt[16][2]*ri[11][0]))));
    ttk[15][2] = (utk[10][2]-(((Cik[16][2][2]*tc[16][2])+((Cik[16][2][0]*
      tc[16][0])+(Cik[16][2][1]*tc[16][1])))+((fccikt[16][1]*ri[11][0])-(
      fccikt[16][0]*ri[11][1]))));
    fc[15][0] = ((mk[10]*(AnkAtk[15][0]-gk[15][0]))-ffk[15][0]);
    fc[15][1] = ((mk[10]*(AnkAtk[15][1]-gk[15][1]))-ffk[15][1]);
    fc[15][2] = ((mk[10]*(AnkAtk[15][2]-gk[15][2]))-ffk[15][2]);
    tc[15][0] = ((WkIkWk[15][0]+((ik[10][0][2]*onk[15][2])+((ik[10][0][0]*
      onk[15][0])+(ik[10][0][1]*onk[15][1]))))-(ttk[15][0]+((fc[15][2]*rk[10][1]
      )-(fc[15][1]*rk[10][2]))));
    tc[15][1] = ((WkIkWk[15][1]+((ik[10][1][2]*onk[15][2])+((ik[10][1][0]*
      onk[15][0])+(ik[10][1][1]*onk[15][1]))))-(ttk[15][1]+((fc[15][0]*rk[10][2]
      )-(fc[15][2]*rk[10][0]))));
    tc[15][2] = ((WkIkWk[15][2]+((ik[10][2][2]*onk[15][2])+((ik[10][2][0]*
      onk[15][0])+(ik[10][2][1]*onk[15][1]))))-(ttk[15][2]+((fc[15][1]*rk[10][0]
      )-(fc[15][0]*rk[10][1]))));
    fccikt[15][0] = ((Cik[15][0][2]*fc[15][2])+((Cik[15][0][0]*fc[15][0])+(
      Cik[15][0][1]*fc[15][1])));
    fccikt[15][1] = ((Cik[15][1][2]*fc[15][2])+((Cik[15][1][0]*fc[15][0])+(
      Cik[15][1][1]*fc[15][1])));
    fccikt[15][2] = ((Cik[15][2][2]*fc[15][2])+((Cik[15][2][0]*fc[15][0])+(
      Cik[15][2][1]*fc[15][1])));
    ffk[5][0] = (ufk[0][0]-fccikt[15][0]);
    ffk[5][1] = (ufk[0][1]-fccikt[15][1]);
    ffk[5][2] = (ufk[0][2]-fccikt[15][2]);
    ttk[5][0] = (utk[0][0]-(((Cik[15][0][2]*tc[15][2])+((Cik[15][0][0]*tc[15][0]
      )+(Cik[15][0][1]*tc[15][1])))+((fccikt[15][2]*ri[10][1])-(fccikt[15][1]*
      ri[10][2]))));
    ttk[5][1] = (utk[0][1]-(((Cik[15][1][2]*tc[15][2])+((Cik[15][1][0]*tc[15][0]
      )+(Cik[15][1][1]*tc[15][1])))+((fccikt[15][0]*ri[10][2])-(fccikt[15][2]*
      ri[10][0]))));
    ttk[5][2] = (utk[0][2]-(((Cik[15][2][2]*tc[15][2])+((Cik[15][2][0]*tc[15][0]
      )+(Cik[15][2][1]*tc[15][1])))+((fccikt[15][1]*ri[10][0])-(fccikt[15][0]*
      ri[10][1]))));
    fc[14][0] = ((mk[9]*(AnkAtk[14][0]-gk[14][0]))-ufk[9][0]);
    fc[14][1] = ((mk[9]*(AnkAtk[14][1]-gk[14][1]))-ufk[9][1]);
    fc[14][2] = ((mk[9]*(AnkAtk[14][2]-gk[14][2]))-ufk[9][2]);
    tc[14][0] = ((WkIkWk[14][0]+((ik[9][0][2]*onk[14][2])+((ik[9][0][0]*
      onk[14][0])+(ik[9][0][1]*onk[14][1]))))-(utk[9][0]+((fc[14][2]*rk[9][1])-(
      fc[14][1]*rk[9][2]))));
    tc[14][1] = ((WkIkWk[14][1]+((ik[9][1][2]*onk[14][2])+((ik[9][1][0]*
      onk[14][0])+(ik[9][1][1]*onk[14][1]))))-(utk[9][1]+((fc[14][0]*rk[9][2])-(
      fc[14][2]*rk[9][0]))));
    tc[14][2] = ((WkIkWk[14][2]+((ik[9][2][2]*onk[14][2])+((ik[9][2][0]*
      onk[14][0])+(ik[9][2][1]*onk[14][1]))))-(utk[9][2]+((fc[14][1]*rk[9][0])-(
      fc[14][0]*rk[9][1]))));
    fccikt[14][0] = ((Cik[14][0][2]*fc[14][2])+((Cik[14][0][0]*fc[14][0])+(
      Cik[14][0][1]*fc[14][1])));
    fccikt[14][1] = ((Cik[14][1][2]*fc[14][2])+((Cik[14][1][0]*fc[14][0])+(
      Cik[14][1][1]*fc[14][1])));
    fccikt[14][2] = ((Cik[14][2][2]*fc[14][2])+((Cik[14][2][0]*fc[14][0])+(
      Cik[14][2][1]*fc[14][1])));
    ffk[13][0] = (ufk[8][0]-fccikt[14][0]);
    ffk[13][1] = (ufk[8][1]-fccikt[14][1]);
    ffk[13][2] = (ufk[8][2]-fccikt[14][2]);
    ttk[13][0] = (utk[8][0]-(((Cik[14][0][2]*tc[14][2])+((Cik[14][0][0]*
      tc[14][0])+(Cik[14][0][1]*tc[14][1])))+((fccikt[14][2]*ri[9][1])-(
      fccikt[14][1]*ri[9][2]))));
    ttk[13][1] = (utk[8][1]-(((Cik[14][1][2]*tc[14][2])+((Cik[14][1][0]*
      tc[14][0])+(Cik[14][1][1]*tc[14][1])))+((fccikt[14][0]*ri[9][2])-(
      fccikt[14][2]*ri[9][0]))));
    ttk[13][2] = (utk[8][2]-(((Cik[14][2][2]*tc[14][2])+((Cik[14][2][0]*
      tc[14][0])+(Cik[14][2][1]*tc[14][1])))+((fccikt[14][1]*ri[9][0])-(
      fccikt[14][0]*ri[9][1]))));
    fc[13][0] = ((mk[8]*(AnkAtk[13][0]-gk[13][0]))-ffk[13][0]);
    fc[13][1] = ((mk[8]*(AnkAtk[13][1]-gk[13][1]))-ffk[13][1]);
    fc[13][2] = ((mk[8]*(AnkAtk[13][2]-gk[13][2]))-ffk[13][2]);
    tc[13][0] = ((WkIkWk[13][0]+((ik[8][0][2]*onk[13][2])+((ik[8][0][0]*
      onk[13][0])+(ik[8][0][1]*onk[13][1]))))-(ttk[13][0]+((fc[13][2]*rk[8][1])-
      (fc[13][1]*rk[8][2]))));
    tc[13][1] = ((WkIkWk[13][1]+((ik[8][1][2]*onk[13][2])+((ik[8][1][0]*
      onk[13][0])+(ik[8][1][1]*onk[13][1]))))-(ttk[13][1]+((fc[13][0]*rk[8][2])-
      (fc[13][2]*rk[8][0]))));
    tc[13][2] = ((WkIkWk[13][2]+((ik[8][2][2]*onk[13][2])+((ik[8][2][0]*
      onk[13][0])+(ik[8][2][1]*onk[13][1]))))-(ttk[13][2]+((fc[13][1]*rk[8][0])-
      (fc[13][0]*rk[8][1]))));
    fccikt[13][0] = ((Cik[13][0][2]*fc[13][2])+((Cik[13][0][0]*fc[13][0])+(
      Cik[13][0][1]*fc[13][1])));
    fccikt[13][1] = ((Cik[13][1][2]*fc[13][2])+((Cik[13][1][0]*fc[13][0])+(
      Cik[13][1][1]*fc[13][1])));
    fccikt[13][2] = ((Cik[13][2][2]*fc[13][2])+((Cik[13][2][0]*fc[13][0])+(
      Cik[13][2][1]*fc[13][1])));
    ffk[12][0] = (ufk[7][0]-fccikt[13][0]);
    ffk[12][1] = (ufk[7][1]-fccikt[13][1]);
    ffk[12][2] = (ufk[7][2]-fccikt[13][2]);
    ttk[12][0] = (utk[7][0]-(((Cik[13][0][2]*tc[13][2])+((Cik[13][0][0]*
      tc[13][0])+(Cik[13][0][1]*tc[13][1])))+((fccikt[13][2]*ri[8][1])-(
      fccikt[13][1]*ri[8][2]))));
    ttk[12][1] = (utk[7][1]-(((Cik[13][1][2]*tc[13][2])+((Cik[13][1][0]*
      tc[13][0])+(Cik[13][1][1]*tc[13][1])))+((fccikt[13][0]*ri[8][2])-(
      fccikt[13][2]*ri[8][0]))));
    ttk[12][2] = (utk[7][2]-(((Cik[13][2][2]*tc[13][2])+((Cik[13][2][0]*
      tc[13][0])+(Cik[13][2][1]*tc[13][1])))+((fccikt[13][1]*ri[8][0])-(
      fccikt[13][0]*ri[8][1]))));
    fc[12][0] = ((mk[7]*(AnkAtk[12][0]-gk[12][0]))-ffk[12][0]);
    fc[12][1] = ((mk[7]*(AnkAtk[12][1]-gk[12][1]))-ffk[12][1]);
    fc[12][2] = ((mk[7]*(AnkAtk[12][2]-gk[12][2]))-ffk[12][2]);
    tc[12][0] = ((WkIkWk[12][0]+((ik[7][0][2]*onk[12][2])+((ik[7][0][0]*
      onk[12][0])+(ik[7][0][1]*onk[12][1]))))-(ttk[12][0]+((fc[12][2]*rk[7][1])-
      (fc[12][1]*rk[7][2]))));
    tc[12][1] = ((WkIkWk[12][1]+((ik[7][1][2]*onk[12][2])+((ik[7][1][0]*
      onk[12][0])+(ik[7][1][1]*onk[12][1]))))-(ttk[12][1]+((fc[12][0]*rk[7][2])-
      (fc[12][2]*rk[7][0]))));
    tc[12][2] = ((WkIkWk[12][2]+((ik[7][2][2]*onk[12][2])+((ik[7][2][0]*
      onk[12][0])+(ik[7][2][1]*onk[12][1]))))-(ttk[12][2]+((fc[12][1]*rk[7][0])-
      (fc[12][0]*rk[7][1]))));
    fccikt[12][0] = ((Cik[12][0][2]*fc[12][2])+((Cik[12][0][0]*fc[12][0])+(
      Cik[12][0][1]*fc[12][1])));
    fccikt[12][1] = ((Cik[12][1][2]*fc[12][2])+((Cik[12][1][0]*fc[12][0])+(
      Cik[12][1][1]*fc[12][1])));
    fccikt[12][2] = ((Cik[12][2][2]*fc[12][2])+((Cik[12][2][0]*fc[12][0])+(
      Cik[12][2][1]*fc[12][1])));
    ffk[5][0] = (ffk[5][0]-fccikt[12][0]);
    ffk[5][1] = (ffk[5][1]-fccikt[12][1]);
    ffk[5][2] = (ffk[5][2]-fccikt[12][2]);
    ttk[5][0] = (ttk[5][0]-(((Cik[12][0][2]*tc[12][2])+((Cik[12][0][0]*tc[12][0]
      )+(Cik[12][0][1]*tc[12][1])))+((fccikt[12][2]*ri[7][1])-(fccikt[12][1]*
      ri[7][2]))));
    ttk[5][1] = (ttk[5][1]-(((Cik[12][1][2]*tc[12][2])+((Cik[12][1][0]*tc[12][0]
      )+(Cik[12][1][1]*tc[12][1])))+((fccikt[12][0]*ri[7][2])-(fccikt[12][2]*
      ri[7][0]))));
    ttk[5][2] = (ttk[5][2]-(((Cik[12][2][2]*tc[12][2])+((Cik[12][2][0]*tc[12][0]
      )+(Cik[12][2][1]*tc[12][1])))+((fccikt[12][1]*ri[7][0])-(fccikt[12][0]*
      ri[7][1]))));
    fc[11][0] = ((mk[6]*(AnkAtk[11][0]-gk[11][0]))-ufk[6][0]);
    fc[11][1] = ((mk[6]*(AnkAtk[11][1]-gk[11][1]))-ufk[6][1]);
    fc[11][2] = ((mk[6]*(AnkAtk[11][2]-gk[11][2]))-ufk[6][2]);
    tc[11][0] = ((WkIkWk[11][0]+((ik[6][0][2]*onk[11][2])+((ik[6][0][0]*
      onk[11][0])+(ik[6][0][1]*onk[11][1]))))-(utk[6][0]+((fc[11][2]*rk[6][1])-(
      fc[11][1]*rk[6][2]))));
    tc[11][1] = ((WkIkWk[11][1]+((ik[6][1][2]*onk[11][2])+((ik[6][1][0]*
      onk[11][0])+(ik[6][1][1]*onk[11][1]))))-(utk[6][1]+((fc[11][0]*rk[6][2])-(
      fc[11][2]*rk[6][0]))));
    tc[11][2] = ((WkIkWk[11][2]+((ik[6][2][2]*onk[11][2])+((ik[6][2][0]*
      onk[11][0])+(ik[6][2][1]*onk[11][1]))))-(utk[6][2]+((fc[11][1]*rk[6][0])-(
      fc[11][0]*rk[6][1]))));
    fccikt[11][0] = ((Cik[11][0][2]*fc[11][2])+((Cik[11][0][0]*fc[11][0])+(
      Cik[11][0][1]*fc[11][1])));
    fccikt[11][1] = ((Cik[11][1][2]*fc[11][2])+((Cik[11][1][0]*fc[11][0])+(
      Cik[11][1][1]*fc[11][1])));
    fccikt[11][2] = ((Cik[11][2][2]*fc[11][2])+((Cik[11][2][0]*fc[11][0])+(
      Cik[11][2][1]*fc[11][1])));
    ffk[10][0] = (ufk[5][0]-fccikt[11][0]);
    ffk[10][1] = (ufk[5][1]-fccikt[11][1]);
    ffk[10][2] = (ufk[5][2]-fccikt[11][2]);
    ttk[10][0] = (utk[5][0]-(((Cik[11][0][2]*tc[11][2])+((Cik[11][0][0]*
      tc[11][0])+(Cik[11][0][1]*tc[11][1])))+((fccikt[11][2]*ri[6][1])-(
      fccikt[11][1]*ri[6][2]))));
    ttk[10][1] = (utk[5][1]-(((Cik[11][1][2]*tc[11][2])+((Cik[11][1][0]*
      tc[11][0])+(Cik[11][1][1]*tc[11][1])))+((fccikt[11][0]*ri[6][2])-(
      fccikt[11][2]*ri[6][0]))));
    ttk[10][2] = (utk[5][2]-(((Cik[11][2][2]*tc[11][2])+((Cik[11][2][0]*
      tc[11][0])+(Cik[11][2][1]*tc[11][1])))+((fccikt[11][1]*ri[6][0])-(
      fccikt[11][0]*ri[6][1]))));
    fc[10][0] = ((mk[5]*(AnkAtk[10][0]-gk[10][0]))-ffk[10][0]);
    fc[10][1] = ((mk[5]*(AnkAtk[10][1]-gk[10][1]))-ffk[10][1]);
    fc[10][2] = ((mk[5]*(AnkAtk[10][2]-gk[10][2]))-ffk[10][2]);
    tc[10][0] = ((WkIkWk[10][0]+((ik[5][0][2]*onk[10][2])+((ik[5][0][0]*
      onk[10][0])+(ik[5][0][1]*onk[10][1]))))-(ttk[10][0]+((fc[10][2]*rk[5][1])-
      (fc[10][1]*rk[5][2]))));
    tc[10][1] = ((WkIkWk[10][1]+((ik[5][1][2]*onk[10][2])+((ik[5][1][0]*
      onk[10][0])+(ik[5][1][1]*onk[10][1]))))-(ttk[10][1]+((fc[10][0]*rk[5][2])-
      (fc[10][2]*rk[5][0]))));
    tc[10][2] = ((WkIkWk[10][2]+((ik[5][2][2]*onk[10][2])+((ik[5][2][0]*
      onk[10][0])+(ik[5][2][1]*onk[10][1]))))-(ttk[10][2]+((fc[10][1]*rk[5][0])-
      (fc[10][0]*rk[5][1]))));
    fccikt[10][0] = ((Cik[10][0][2]*fc[10][2])+((Cik[10][0][0]*fc[10][0])+(
      Cik[10][0][1]*fc[10][1])));
    fccikt[10][1] = ((Cik[10][1][2]*fc[10][2])+((Cik[10][1][0]*fc[10][0])+(
      Cik[10][1][1]*fc[10][1])));
    fccikt[10][2] = ((Cik[10][2][2]*fc[10][2])+((Cik[10][2][0]*fc[10][0])+(
      Cik[10][2][1]*fc[10][1])));
    ffk[9][0] = (ufk[4][0]-fccikt[10][0]);
    ffk[9][1] = (ufk[4][1]-fccikt[10][1]);
    ffk[9][2] = (ufk[4][2]-fccikt[10][2]);
    ttk[9][0] = (utk[4][0]-(((Cik[10][0][2]*tc[10][2])+((Cik[10][0][0]*tc[10][0]
      )+(Cik[10][0][1]*tc[10][1])))+((fccikt[10][2]*ri[5][1])-(fccikt[10][1]*
      ri[5][2]))));
    ttk[9][1] = (utk[4][1]-(((Cik[10][1][2]*tc[10][2])+((Cik[10][1][0]*tc[10][0]
      )+(Cik[10][1][1]*tc[10][1])))+((fccikt[10][0]*ri[5][2])-(fccikt[10][2]*
      ri[5][0]))));
    ttk[9][2] = (utk[4][2]-(((Cik[10][2][2]*tc[10][2])+((Cik[10][2][0]*tc[10][0]
      )+(Cik[10][2][1]*tc[10][1])))+((fccikt[10][1]*ri[5][0])-(fccikt[10][0]*
      ri[5][1]))));
    fc[9][0] = ((mk[4]*(AnkAtk[9][0]-gk[9][0]))-ffk[9][0]);
    fc[9][1] = ((mk[4]*(AnkAtk[9][1]-gk[9][1]))-ffk[9][1]);
    fc[9][2] = ((mk[4]*(AnkAtk[9][2]-gk[9][2]))-ffk[9][2]);
    tc[9][0] = ((WkIkWk[9][0]+((ik[4][0][2]*onk[9][2])+((ik[4][0][0]*onk[9][0])+
      (ik[4][0][1]*onk[9][1]))))-(ttk[9][0]+((fc[9][2]*rk[4][1])-(fc[9][1]*
      rk[4][2]))));
    tc[9][1] = ((WkIkWk[9][1]+((ik[4][1][2]*onk[9][2])+((ik[4][1][0]*onk[9][0])+
      (ik[4][1][1]*onk[9][1]))))-(ttk[9][1]+((fc[9][0]*rk[4][2])-(fc[9][2]*
      rk[4][0]))));
    tc[9][2] = ((WkIkWk[9][2]+((ik[4][2][2]*onk[9][2])+((ik[4][2][0]*onk[9][0])+
      (ik[4][2][1]*onk[9][1]))))-(ttk[9][2]+((fc[9][1]*rk[4][0])-(fc[9][0]*
      rk[4][1]))));
    fccikt[9][0] = ((Cik[9][0][2]*fc[9][2])+((Cik[9][0][0]*fc[9][0])+(
      Cik[9][0][1]*fc[9][1])));
    fccikt[9][1] = ((Cik[9][1][2]*fc[9][2])+((Cik[9][1][0]*fc[9][0])+(
      Cik[9][1][1]*fc[9][1])));
    fccikt[9][2] = ((Cik[9][2][2]*fc[9][2])+((Cik[9][2][0]*fc[9][0])+(
      Cik[9][2][1]*fc[9][1])));
    ffk[5][0] = (ffk[5][0]-fccikt[9][0]);
    ffk[5][1] = (ffk[5][1]-fccikt[9][1]);
    ffk[5][2] = (ffk[5][2]-fccikt[9][2]);
    ttk[5][0] = (ttk[5][0]-(((Cik[9][0][2]*tc[9][2])+((Cik[9][0][0]*tc[9][0])+(
      Cik[9][0][1]*tc[9][1])))+((fccikt[9][2]*ri[4][1])-(fccikt[9][1]*ri[4][2]))
      ));
    ttk[5][1] = (ttk[5][1]-(((Cik[9][1][2]*tc[9][2])+((Cik[9][1][0]*tc[9][0])+(
      Cik[9][1][1]*tc[9][1])))+((fccikt[9][0]*ri[4][2])-(fccikt[9][2]*ri[4][0]))
      ));
    ttk[5][2] = (ttk[5][2]-(((Cik[9][2][2]*tc[9][2])+((Cik[9][2][0]*tc[9][0])+(
      Cik[9][2][1]*tc[9][1])))+((fccikt[9][1]*ri[4][0])-(fccikt[9][0]*ri[4][1]))
      ));
    fc[8][0] = ((mk[3]*(AnkAtk[8][0]-gk[8][0]))-ufk[3][0]);
    fc[8][1] = ((mk[3]*(AnkAtk[8][1]-gk[8][1]))-ufk[3][1]);
    fc[8][2] = ((mk[3]*(AnkAtk[8][2]-gk[8][2]))-ufk[3][2]);
    tc[8][0] = ((WkIkWk[8][0]+((ik[3][0][2]*onk[8][2])+((ik[3][0][0]*onk[8][0])+
      (ik[3][0][1]*onk[8][1]))))-(utk[3][0]+((fc[8][2]*rk[3][1])-(fc[8][1]*
      rk[3][2]))));
    tc[8][1] = ((WkIkWk[8][1]+((ik[3][1][2]*onk[8][2])+((ik[3][1][0]*onk[8][0])+
      (ik[3][1][1]*onk[8][1]))))-(utk[3][1]+((fc[8][0]*rk[3][2])-(fc[8][2]*
      rk[3][0]))));
    tc[8][2] = ((WkIkWk[8][2]+((ik[3][2][2]*onk[8][2])+((ik[3][2][0]*onk[8][0])+
      (ik[3][2][1]*onk[8][1]))))-(utk[3][2]+((fc[8][1]*rk[3][0])-(fc[8][0]*
      rk[3][1]))));
    fccikt[8][0] = ((Cik[8][0][2]*fc[8][2])+((Cik[8][0][0]*fc[8][0])+(
      Cik[8][0][1]*fc[8][1])));
    fccikt[8][1] = ((Cik[8][1][2]*fc[8][2])+((Cik[8][1][0]*fc[8][0])+(
      Cik[8][1][1]*fc[8][1])));
    fccikt[8][2] = ((Cik[8][2][2]*fc[8][2])+((Cik[8][2][0]*fc[8][0])+(
      Cik[8][2][1]*fc[8][1])));
    ffk[7][0] = (ufk[2][0]-fccikt[8][0]);
    ffk[7][1] = (ufk[2][1]-fccikt[8][1]);
    ffk[7][2] = (ufk[2][2]-fccikt[8][2]);
    ttk[7][0] = (utk[2][0]-(((Cik[8][0][2]*tc[8][2])+((Cik[8][0][0]*tc[8][0])+(
      Cik[8][0][1]*tc[8][1])))+((fccikt[8][2]*ri[3][1])-(fccikt[8][1]*ri[3][2]))
      ));
    ttk[7][1] = (utk[2][1]-(((Cik[8][1][2]*tc[8][2])+((Cik[8][1][0]*tc[8][0])+(
      Cik[8][1][1]*tc[8][1])))+((fccikt[8][0]*ri[3][2])-(fccikt[8][2]*ri[3][0]))
      ));
    ttk[7][2] = (utk[2][2]-(((Cik[8][2][2]*tc[8][2])+((Cik[8][2][0]*tc[8][0])+(
      Cik[8][2][1]*tc[8][1])))+((fccikt[8][1]*ri[3][0])-(fccikt[8][0]*ri[3][1]))
      ));
    fc[7][0] = ((mk[2]*(AnkAtk[7][0]-gk[7][0]))-ffk[7][0]);
    fc[7][1] = ((mk[2]*(AnkAtk[7][1]-gk[7][1]))-ffk[7][1]);
    fc[7][2] = ((mk[2]*(AnkAtk[7][2]-gk[7][2]))-ffk[7][2]);
    tc[7][0] = ((WkIkWk[7][0]+((ik[2][0][2]*onk[7][2])+((ik[2][0][0]*onk[7][0])+
      (ik[2][0][1]*onk[7][1]))))-(ttk[7][0]+((fc[7][2]*rk[2][1])-(fc[7][1]*
      rk[2][2]))));
    tc[7][1] = ((WkIkWk[7][1]+((ik[2][1][2]*onk[7][2])+((ik[2][1][0]*onk[7][0])+
      (ik[2][1][1]*onk[7][1]))))-(ttk[7][1]+((fc[7][0]*rk[2][2])-(fc[7][2]*
      rk[2][0]))));
    tc[7][2] = ((WkIkWk[7][2]+((ik[2][2][2]*onk[7][2])+((ik[2][2][0]*onk[7][0])+
      (ik[2][2][1]*onk[7][1]))))-(ttk[7][2]+((fc[7][1]*rk[2][0])-(fc[7][0]*
      rk[2][1]))));
    fccikt[7][0] = ((Cik[7][0][2]*fc[7][2])+((Cik[7][0][0]*fc[7][0])+(
      Cik[7][0][1]*fc[7][1])));
    fccikt[7][1] = ((Cik[7][1][2]*fc[7][2])+((Cik[7][1][0]*fc[7][0])+(
      Cik[7][1][1]*fc[7][1])));
    fccikt[7][2] = ((Cik[7][2][2]*fc[7][2])+((Cik[7][2][0]*fc[7][0])+(
      Cik[7][2][1]*fc[7][1])));
    ffk[6][0] = (ufk[1][0]-fccikt[7][0]);
    ffk[6][1] = (ufk[1][1]-fccikt[7][1]);
    ffk[6][2] = (ufk[1][2]-fccikt[7][2]);
    ttk[6][0] = (utk[1][0]-(((Cik[7][0][2]*tc[7][2])+((Cik[7][0][0]*tc[7][0])+(
      Cik[7][0][1]*tc[7][1])))+((fccikt[7][2]*ri[2][1])-(fccikt[7][1]*ri[2][2]))
      ));
    ttk[6][1] = (utk[1][1]-(((Cik[7][1][2]*tc[7][2])+((Cik[7][1][0]*tc[7][0])+(
      Cik[7][1][1]*tc[7][1])))+((fccikt[7][0]*ri[2][2])-(fccikt[7][2]*ri[2][0]))
      ));
    ttk[6][2] = (utk[1][2]-(((Cik[7][2][2]*tc[7][2])+((Cik[7][2][0]*tc[7][0])+(
      Cik[7][2][1]*tc[7][1])))+((fccikt[7][1]*ri[2][0])-(fccikt[7][0]*ri[2][1]))
      ));
    fc[6][0] = ((mk[1]*(AnkAtk[6][0]-gk[6][0]))-ffk[6][0]);
    fc[6][1] = ((mk[1]*(AnkAtk[6][1]-gk[6][1]))-ffk[6][1]);
    fc[6][2] = ((mk[1]*(AnkAtk[6][2]-gk[6][2]))-ffk[6][2]);
    tc[6][0] = ((WkIkWk[6][0]+((ik[1][0][2]*onk[6][2])+((ik[1][0][0]*onk[6][0])+
      (ik[1][0][1]*onk[6][1]))))-(ttk[6][0]+((fc[6][2]*rk[1][1])-(fc[6][1]*
      rk[1][2]))));
    tc[6][1] = ((WkIkWk[6][1]+((ik[1][1][2]*onk[6][2])+((ik[1][1][0]*onk[6][0])+
      (ik[1][1][1]*onk[6][1]))))-(ttk[6][1]+((fc[6][0]*rk[1][2])-(fc[6][2]*
      rk[1][0]))));
    tc[6][2] = ((WkIkWk[6][2]+((ik[1][2][2]*onk[6][2])+((ik[1][2][0]*onk[6][0])+
      (ik[1][2][1]*onk[6][1]))))-(ttk[6][2]+((fc[6][1]*rk[1][0])-(fc[6][0]*
      rk[1][1]))));
    fccikt[6][0] = ((Cik[6][0][2]*fc[6][2])+((Cik[6][0][0]*fc[6][0])+(
      Cik[6][0][1]*fc[6][1])));
    fccikt[6][1] = ((Cik[6][1][2]*fc[6][2])+((Cik[6][1][0]*fc[6][0])+(
      Cik[6][1][1]*fc[6][1])));
    fccikt[6][2] = ((Cik[6][2][2]*fc[6][2])+((Cik[6][2][0]*fc[6][0])+(
      Cik[6][2][1]*fc[6][1])));
    ffk[5][0] = (ffk[5][0]-fccikt[6][0]);
    ffk[5][1] = (ffk[5][1]-fccikt[6][1]);
    ffk[5][2] = (ffk[5][2]-fccikt[6][2]);
    ttk[5][0] = (ttk[5][0]-(((Cik[6][0][2]*tc[6][2])+((Cik[6][0][0]*tc[6][0])+(
      Cik[6][0][1]*tc[6][1])))+((fccikt[6][2]*ri[1][1])-(fccikt[6][1]*ri[1][2]))
      ));
    ttk[5][1] = (ttk[5][1]-(((Cik[6][1][2]*tc[6][2])+((Cik[6][1][0]*tc[6][0])+(
      Cik[6][1][1]*tc[6][1])))+((fccikt[6][0]*ri[1][2])-(fccikt[6][2]*ri[1][0]))
      ));
    ttk[5][2] = (ttk[5][2]-(((Cik[6][2][2]*tc[6][2])+((Cik[6][2][0]*tc[6][0])+(
      Cik[6][2][1]*tc[6][1])))+((fccikt[6][1]*ri[1][0])-(fccikt[6][0]*ri[1][1]))
      ));
    fc[5][0] = ((mk[0]*(AnkAtk[5][0]-gk[3][0]))-ffk[5][0]);
    fc[5][1] = ((mk[0]*(AnkAtk[5][1]-gk[3][1]))-ffk[5][1]);
    fc[5][2] = ((mk[0]*(AnkAtk[5][2]-gk[3][2]))-ffk[5][2]);
    tc[5][0] = ((WkIkWk[5][0]+((ik[0][0][2]*udot[5])+((ik[0][0][0]*udot[3])+(
      ik[0][0][1]*udot[4]))))-(ttk[5][0]+((fc[5][2]*rk[0][1])-(fc[5][1]*rk[0][2]
      ))));
    tc[5][1] = ((WkIkWk[5][1]+((ik[0][1][2]*udot[5])+((ik[0][1][0]*udot[3])+(
      ik[0][1][1]*udot[4]))))-(ttk[5][1]+((fc[5][0]*rk[0][2])-(fc[5][2]*rk[0][0]
      ))));
    tc[5][2] = ((WkIkWk[5][2]+((ik[0][2][2]*udot[5])+((ik[0][2][0]*udot[3])+(
      ik[0][2][1]*udot[4]))))-(ttk[5][2]+((fc[5][1]*rk[0][0])-(fc[5][0]*rk[0][1]
      ))));
    fccikt[5][0] = fc[5][0];
    fccikt[5][1] = fc[5][1];
    fccikt[5][2] = fc[5][2];
    ffk[4][0] = -fccikt[5][0];
    ffk[4][1] = -fccikt[5][1];
    ffk[4][2] = -fccikt[5][2];
    ttk[4][0] = -tc[5][0];
    ttk[4][1] = -tc[5][1];
    ttk[4][2] = -tc[5][2];
    fc[4][0] = -ffk[4][0];
    fc[4][1] = -ffk[4][1];
    fc[4][2] = -ffk[4][2];
    tc[4][0] = -ttk[4][0];
    tc[4][1] = -ttk[4][1];
    tc[4][2] = -ttk[4][2];
    fccikt[4][0] = fc[4][0];
    fccikt[4][1] = fc[4][1];
    fccikt[4][2] = fc[4][2];
    ffk[3][0] = -fccikt[4][0];
    ffk[3][1] = -fccikt[4][1];
    ffk[3][2] = -fccikt[4][2];
    ttk[3][0] = -tc[4][0];
    ttk[3][1] = -tc[4][1];
    ttk[3][2] = -tc[4][2];
    fc[3][0] = -ffk[3][0];
    fc[3][1] = -ffk[3][1];
    fc[3][2] = -ffk[3][2];
    tc[3][0] = -ttk[3][0];
    tc[3][1] = -ttk[3][1];
    tc[3][2] = -ttk[3][2];
    fccikt[3][0] = ((Cik[3][0][2]*fc[3][2])+((Cik[3][0][0]*fc[3][0])+(
      Cik[3][0][1]*fc[3][1])));
    fccikt[3][1] = ((Cik[3][1][2]*fc[3][2])+((Cik[3][1][0]*fc[3][0])+(
      Cik[3][1][1]*fc[3][1])));
    fccikt[3][2] = ((Cik[3][2][2]*fc[3][2])+((Cik[3][2][0]*fc[3][0])+(
      Cik[3][2][1]*fc[3][1])));
    ffk[2][0] = -fccikt[3][0];
    ffk[2][1] = -fccikt[3][1];
    ffk[2][2] = -fccikt[3][2];
    ttk[2][0] = -((Cik[3][0][2]*tc[3][2])+((Cik[3][0][0]*tc[3][0])+(Cik[3][0][1]
      *tc[3][1])));
    ttk[2][1] = -((Cik[3][1][2]*tc[3][2])+((Cik[3][1][0]*tc[3][0])+(Cik[3][1][1]
      *tc[3][1])));
    ttk[2][2] = -((Cik[3][2][2]*tc[3][2])+((Cik[3][2][0]*tc[3][0])+(Cik[3][2][1]
      *tc[3][1])));
    fc[2][0] = -ffk[2][0];
    fc[2][1] = -ffk[2][1];
    fc[2][2] = -ffk[2][2];
    tc[2][0] = -ttk[2][0];
    tc[2][1] = -ttk[2][1];
    tc[2][2] = -ttk[2][2];
    fccikt[2][0] = fc[2][0];
    fccikt[2][1] = fc[2][1];
    fccikt[2][2] = fc[2][2];
    ffk[1][0] = -fccikt[2][0];
    ffk[1][1] = -fccikt[2][1];
    ffk[1][2] = -fccikt[2][2];
    ttk[1][0] = -(tc[2][0]+((fccikt[2][2]*rpp[2][1])-(fccikt[2][1]*rpp[2][2])));
    ttk[1][1] = -(tc[2][1]+((fccikt[2][0]*rpp[2][2])-(fccikt[2][2]*rpp[2][0])));
    ttk[1][2] = -(tc[2][2]+((fccikt[2][1]*rpp[2][0])-(fccikt[2][0]*rpp[2][1])));
    fc[1][0] = -ffk[1][0];
    fc[1][1] = -ffk[1][1];
    fc[1][2] = -ffk[1][2];
    tc[1][0] = -ttk[1][0];
    tc[1][1] = -ttk[1][1];
    tc[1][2] = -ttk[1][2];
    fccikt[1][0] = fc[1][0];
    fccikt[1][1] = fc[1][1];
    fccikt[1][2] = fc[1][2];
    ffk[0][0] = -fccikt[1][0];
    ffk[0][1] = -fccikt[1][1];
    ffk[0][2] = -fccikt[1][2];
    ttk[0][0] = -(tc[1][0]+((fccikt[1][2]*rpp[1][1])-(fccikt[1][1]*rpp[1][2])));
    ttk[0][1] = -(tc[1][1]+((fccikt[1][0]*rpp[1][2])-(fccikt[1][2]*rpp[1][0])));
    ttk[0][2] = -(tc[1][2]+((fccikt[1][1]*rpp[1][0])-(fccikt[1][0]*rpp[1][1])));
    fc[0][0] = -ffk[0][0];
    fc[0][1] = -ffk[0][1];
    fc[0][2] = -ffk[0][2];
    tc[0][0] = -ttk[0][0];
    tc[0][1] = -ttk[0][1];
    tc[0][2] = -ttk[0][2];
    force[0][0] = fc[5][0];
    torque[0][0] = tc[5][0];
    force[0][1] = fc[5][1];
    torque[0][1] = tc[5][1];
    force[0][2] = fc[5][2];
    torque[0][2] = tc[5][2];
    force[1][0] = fc[6][0];
    torque[1][0] = tc[6][0];
    force[1][1] = fc[6][1];
    torque[1][1] = tc[6][1];
    force[1][2] = fc[6][2];
    torque[1][2] = tc[6][2];
    force[2][0] = fc[7][0];
    torque[2][0] = tc[7][0];
    force[2][1] = fc[7][1];
    torque[2][1] = tc[7][1];
    force[2][2] = fc[7][2];
    torque[2][2] = tc[7][2];
    force[3][0] = fc[8][0];
    torque[3][0] = tc[8][0];
    force[3][1] = fc[8][1];
    torque[3][1] = tc[8][1];
    force[3][2] = fc[8][2];
    torque[3][2] = tc[8][2];
    force[4][0] = fc[9][0];
    torque[4][0] = tc[9][0];
    force[4][1] = fc[9][1];
    torque[4][1] = tc[9][1];
    force[4][2] = fc[9][2];
    torque[4][2] = tc[9][2];
    force[5][0] = fc[10][0];
    torque[5][0] = tc[10][0];
    force[5][1] = fc[10][1];
    torque[5][1] = tc[10][1];
    force[5][2] = fc[10][2];
    torque[5][2] = tc[10][2];
    force[6][0] = fc[11][0];
    torque[6][0] = tc[11][0];
    force[6][1] = fc[11][1];
    torque[6][1] = tc[11][1];
    force[6][2] = fc[11][2];
    torque[6][2] = tc[11][2];
    force[7][0] = fc[12][0];
    torque[7][0] = tc[12][0];
    force[7][1] = fc[12][1];
    torque[7][1] = tc[12][1];
    force[7][2] = fc[12][2];
    torque[7][2] = tc[12][2];
    force[8][0] = fc[13][0];
    torque[8][0] = tc[13][0];
    force[8][1] = fc[13][1];
    torque[8][1] = tc[13][1];
    force[8][2] = fc[13][2];
    torque[8][2] = tc[13][2];
    force[9][0] = fc[14][0];
    torque[9][0] = tc[14][0];
    force[9][1] = fc[14][1];
    torque[9][1] = tc[14][1];
    force[9][2] = fc[14][2];
    torque[9][2] = tc[14][2];
    force[10][0] = fc[15][0];
    torque[10][0] = tc[15][0];
    force[10][1] = fc[15][1];
    torque[10][1] = tc[15][1];
    force[10][2] = fc[15][2];
    torque[10][2] = tc[15][2];
    force[11][0] = fc[16][0];
    torque[11][0] = tc[16][0];
    force[11][1] = fc[16][1];
    torque[11][1] = tc[16][1];
    force[11][2] = fc[16][2];
    torque[11][2] = tc[16][2];
    force[12][0] = fc[17][0];
    torque[12][0] = tc[17][0];
    force[12][1] = fc[17][1];
    torque[12][1] = tc[17][1];
    force[12][2] = fc[17][2];
    torque[12][2] = tc[17][2];
/*
Compute reaction forces for tree weld joints
*/
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  684 adds/subtracts/negates
                    552 multiplies
                      0 divides
                    339 assignments
*/
}

void sdmom(double lm[3],
    double am[3],
    double *ke)
{
/*
Compute system linear and angular momentum, and kinetic energy.

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
    double lk[13][3],hnk[13][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(19,23);
        return;
    }
    lk[0][0] = (mk[0]*vnk[5][0]);
    lk[0][1] = (mk[0]*vnk[5][1]);
    lk[0][2] = (mk[0]*vnk[5][2]);
    lk[1][0] = (mk[1]*vnk[6][0]);
    lk[1][1] = (mk[1]*vnk[6][1]);
    lk[1][2] = (mk[1]*vnk[6][2]);
    lk[2][0] = (mk[2]*vnk[7][0]);
    lk[2][1] = (mk[2]*vnk[7][1]);
    lk[2][2] = (mk[2]*vnk[7][2]);
    lk[3][0] = (mk[3]*vnk[8][0]);
    lk[3][1] = (mk[3]*vnk[8][1]);
    lk[3][2] = (mk[3]*vnk[8][2]);
    lk[4][0] = (mk[4]*vnk[9][0]);
    lk[4][1] = (mk[4]*vnk[9][1]);
    lk[4][2] = (mk[4]*vnk[9][2]);
    lk[5][0] = (mk[5]*vnk[10][0]);
    lk[5][1] = (mk[5]*vnk[10][1]);
    lk[5][2] = (mk[5]*vnk[10][2]);
    lk[6][0] = (mk[6]*vnk[11][0]);
    lk[6][1] = (mk[6]*vnk[11][1]);
    lk[6][2] = (mk[6]*vnk[11][2]);
    lk[7][0] = (mk[7]*vnk[12][0]);
    lk[7][1] = (mk[7]*vnk[12][1]);
    lk[7][2] = (mk[7]*vnk[12][2]);
    lk[8][0] = (mk[8]*vnk[13][0]);
    lk[8][1] = (mk[8]*vnk[13][1]);
    lk[8][2] = (mk[8]*vnk[13][2]);
    lk[9][0] = (mk[9]*vnk[14][0]);
    lk[9][1] = (mk[9]*vnk[14][1]);
    lk[9][2] = (mk[9]*vnk[14][2]);
    lk[10][0] = (mk[10]*vnk[15][0]);
    lk[10][1] = (mk[10]*vnk[15][1]);
    lk[10][2] = (mk[10]*vnk[15][2]);
    lk[11][0] = (mk[11]*vnk[16][0]);
    lk[11][1] = (mk[11]*vnk[16][1]);
    lk[11][2] = (mk[11]*vnk[16][2]);
    lk[12][0] = (mk[12]*vnk[17][0]);
    lk[12][1] = (mk[12]*vnk[17][1]);
    lk[12][2] = (mk[12]*vnk[17][2]);
    hnk[0][0] = ((ik[0][0][2]*u[5])+((ik[0][0][0]*u[3])+(ik[0][0][1]*u[4])));
    hnk[0][1] = ((ik[0][1][2]*u[5])+((ik[0][1][0]*u[3])+(ik[0][1][1]*u[4])));
    hnk[0][2] = ((ik[0][2][2]*u[5])+((ik[0][2][0]*u[3])+(ik[0][2][1]*u[4])));
    hnk[1][0] = ((ik[1][0][2]*wk[6][2])+((ik[1][0][0]*wk[6][0])+(ik[1][0][1]*
      wk[6][1])));
    hnk[1][1] = ((ik[1][1][2]*wk[6][2])+((ik[1][1][0]*wk[6][0])+(ik[1][1][1]*
      wk[6][1])));
    hnk[1][2] = ((ik[1][2][2]*wk[6][2])+((ik[1][2][0]*wk[6][0])+(ik[1][2][1]*
      wk[6][1])));
    hnk[2][0] = ((ik[2][0][2]*wk[7][2])+((ik[2][0][0]*wk[7][0])+(ik[2][0][1]*
      wk[7][1])));
    hnk[2][1] = ((ik[2][1][2]*wk[7][2])+((ik[2][1][0]*wk[7][0])+(ik[2][1][1]*
      wk[7][1])));
    hnk[2][2] = ((ik[2][2][2]*wk[7][2])+((ik[2][2][0]*wk[7][0])+(ik[2][2][1]*
      wk[7][1])));
    hnk[3][0] = ((ik[3][0][2]*wk[8][2])+((ik[3][0][0]*wk[8][0])+(ik[3][0][1]*
      wk[8][1])));
    hnk[3][1] = ((ik[3][1][2]*wk[8][2])+((ik[3][1][0]*wk[8][0])+(ik[3][1][1]*
      wk[8][1])));
    hnk[3][2] = ((ik[3][2][2]*wk[8][2])+((ik[3][2][0]*wk[8][0])+(ik[3][2][1]*
      wk[8][1])));
    hnk[4][0] = ((ik[4][0][2]*wk[9][2])+((ik[4][0][0]*wk[9][0])+(ik[4][0][1]*
      wk[9][1])));
    hnk[4][1] = ((ik[4][1][2]*wk[9][2])+((ik[4][1][0]*wk[9][0])+(ik[4][1][1]*
      wk[9][1])));
    hnk[4][2] = ((ik[4][2][2]*wk[9][2])+((ik[4][2][0]*wk[9][0])+(ik[4][2][1]*
      wk[9][1])));
    hnk[5][0] = ((ik[5][0][2]*wk[10][2])+((ik[5][0][0]*wk[10][0])+(ik[5][0][1]*
      wk[10][1])));
    hnk[5][1] = ((ik[5][1][2]*wk[10][2])+((ik[5][1][0]*wk[10][0])+(ik[5][1][1]*
      wk[10][1])));
    hnk[5][2] = ((ik[5][2][2]*wk[10][2])+((ik[5][2][0]*wk[10][0])+(ik[5][2][1]*
      wk[10][1])));
    hnk[6][0] = ((ik[6][0][2]*wk[11][2])+((ik[6][0][0]*wk[11][0])+(ik[6][0][1]*
      wk[11][1])));
    hnk[6][1] = ((ik[6][1][2]*wk[11][2])+((ik[6][1][0]*wk[11][0])+(ik[6][1][1]*
      wk[11][1])));
    hnk[6][2] = ((ik[6][2][2]*wk[11][2])+((ik[6][2][0]*wk[11][0])+(ik[6][2][1]*
      wk[11][1])));
    hnk[7][0] = ((ik[7][0][2]*wk[12][2])+((ik[7][0][0]*wk[12][0])+(ik[7][0][1]*
      wk[12][1])));
    hnk[7][1] = ((ik[7][1][2]*wk[12][2])+((ik[7][1][0]*wk[12][0])+(ik[7][1][1]*
      wk[12][1])));
    hnk[7][2] = ((ik[7][2][2]*wk[12][2])+((ik[7][2][0]*wk[12][0])+(ik[7][2][1]*
      wk[12][1])));
    hnk[8][0] = ((ik[8][0][2]*wk[13][2])+((ik[8][0][0]*wk[13][0])+(ik[8][0][1]*
      wk[13][1])));
    hnk[8][1] = ((ik[8][1][2]*wk[13][2])+((ik[8][1][0]*wk[13][0])+(ik[8][1][1]*
      wk[13][1])));
    hnk[8][2] = ((ik[8][2][2]*wk[13][2])+((ik[8][2][0]*wk[13][0])+(ik[8][2][1]*
      wk[13][1])));
    hnk[9][0] = ((ik[9][0][2]*wk[14][2])+((ik[9][0][0]*wk[14][0])+(ik[9][0][1]*
      wk[14][1])));
    hnk[9][1] = ((ik[9][1][2]*wk[14][2])+((ik[9][1][0]*wk[14][0])+(ik[9][1][1]*
      wk[14][1])));
    hnk[9][2] = ((ik[9][2][2]*wk[14][2])+((ik[9][2][0]*wk[14][0])+(ik[9][2][1]*
      wk[14][1])));
    hnk[10][0] = ((ik[10][0][2]*wk[15][2])+((ik[10][0][0]*wk[15][0])+(
      ik[10][0][1]*wk[15][1])));
    hnk[10][1] = ((ik[10][1][2]*wk[15][2])+((ik[10][1][0]*wk[15][0])+(
      ik[10][1][1]*wk[15][1])));
    hnk[10][2] = ((ik[10][2][2]*wk[15][2])+((ik[10][2][0]*wk[15][0])+(
      ik[10][2][1]*wk[15][1])));
    hnk[11][0] = ((ik[11][0][2]*wk[16][2])+((ik[11][0][0]*wk[16][0])+(
      ik[11][0][1]*wk[16][1])));
    hnk[11][1] = ((ik[11][1][2]*wk[16][2])+((ik[11][1][0]*wk[16][0])+(
      ik[11][1][1]*wk[16][1])));
    hnk[11][2] = ((ik[11][2][2]*wk[16][2])+((ik[11][2][0]*wk[16][0])+(
      ik[11][2][1]*wk[16][1])));
    hnk[12][0] = ((ik[12][0][2]*wk[17][2])+((ik[12][0][0]*wk[17][0])+(
      ik[12][0][1]*wk[17][1])));
    hnk[12][1] = ((ik[12][1][2]*wk[17][2])+((ik[12][1][0]*wk[17][0])+(
      ik[12][1][1]*wk[17][1])));
    hnk[12][2] = ((ik[12][2][2]*wk[17][2])+((ik[12][2][0]*wk[17][0])+(
      ik[12][2][1]*wk[17][1])));
    lm[0] = (lk[12][0]+(lk[11][0]+(lk[10][0]+(lk[9][0]+(lk[8][0]+(lk[7][0]+(
      lk[6][0]+(lk[5][0]+(lk[4][0]+(lk[3][0]+(lk[2][0]+(lk[0][0]+lk[1][0])))))))
      )))));
    lm[1] = (lk[12][1]+(lk[11][1]+(lk[10][1]+(lk[9][1]+(lk[8][1]+(lk[7][1]+(
      lk[6][1]+(lk[5][1]+(lk[4][1]+(lk[3][1]+(lk[2][1]+(lk[0][1]+lk[1][1])))))))
      )))));
    lm[2] = (lk[12][2]+(lk[11][2]+(lk[10][2]+(lk[9][2]+(lk[8][2]+(lk[7][2]+(
      lk[6][2]+(lk[5][2]+(lk[4][2]+(lk[3][2]+(lk[2][2]+(lk[0][2]+lk[1][2])))))))
      )))));
    temp[0] = ((((cnk[7][0][2]*hnk[2][2])+((cnk[7][0][0]*hnk[2][0])+(
      cnk[7][0][1]*hnk[2][1])))+((lk[2][2]*rnk[7][1])-(lk[2][1]*rnk[7][2])))+(((
      (Cik[3][0][2]*hnk[0][2])+((Cik[3][0][0]*hnk[0][0])+(Cik[3][0][1]*hnk[0][1]
      )))+((lk[0][2]*rnk[5][1])-(lk[0][1]*rnk[5][2])))+(((cnk[6][0][2]*hnk[1][2]
      )+((cnk[6][0][0]*hnk[1][0])+(cnk[6][0][1]*hnk[1][1])))+((lk[1][2]*
      rnk[6][1])-(lk[1][1]*rnk[6][2])))));
    temp[1] = ((((cnk[9][0][2]*hnk[4][2])+((cnk[9][0][0]*hnk[4][0])+(
      cnk[9][0][1]*hnk[4][1])))+((lk[4][2]*rnk[9][1])-(lk[4][1]*rnk[9][2])))+(((
      (cnk[8][0][2]*hnk[3][2])+((cnk[8][0][0]*hnk[3][0])+(cnk[8][0][1]*hnk[3][1]
      )))+((lk[3][2]*rnk[8][1])-(lk[3][1]*rnk[8][2])))+temp[0]));
    temp[2] = ((((cnk[11][0][2]*hnk[6][2])+((cnk[11][0][0]*hnk[6][0])+(
      cnk[11][0][1]*hnk[6][1])))+((lk[6][2]*rnk[11][1])-(lk[6][1]*rnk[11][2])))+
      ((((cnk[10][0][2]*hnk[5][2])+((cnk[10][0][0]*hnk[5][0])+(cnk[10][0][1]*
      hnk[5][1])))+((lk[5][2]*rnk[10][1])-(lk[5][1]*rnk[10][2])))+temp[1]));
    temp[3] = ((((cnk[13][0][2]*hnk[8][2])+((cnk[13][0][0]*hnk[8][0])+(
      cnk[13][0][1]*hnk[8][1])))+((lk[8][2]*rnk[13][1])-(lk[8][1]*rnk[13][2])))+
      ((((cnk[12][0][2]*hnk[7][2])+((cnk[12][0][0]*hnk[7][0])+(cnk[12][0][1]*
      hnk[7][1])))+((lk[7][2]*rnk[12][1])-(lk[7][1]*rnk[12][2])))+temp[2]));
    temp[4] = ((((cnk[15][0][2]*hnk[10][2])+((cnk[15][0][0]*hnk[10][0])+(
      cnk[15][0][1]*hnk[10][1])))+((lk[10][2]*rnk[15][1])-(lk[10][1]*rnk[15][2])
      ))+((((cnk[14][0][2]*hnk[9][2])+((cnk[14][0][0]*hnk[9][0])+(cnk[14][0][1]*
      hnk[9][1])))+((lk[9][2]*rnk[14][1])-(lk[9][1]*rnk[14][2])))+temp[3]));
    am[0] = (((((cnk[17][0][2]*hnk[12][2])+((cnk[17][0][0]*hnk[12][0])+(
      cnk[17][0][1]*hnk[12][1])))+((lk[12][2]*rnk[17][1])-(lk[12][1]*rnk[17][2])
      ))+((((cnk[16][0][2]*hnk[11][2])+((cnk[16][0][0]*hnk[11][0])+(
      cnk[16][0][1]*hnk[11][1])))+((lk[11][2]*rnk[16][1])-(lk[11][1]*rnk[16][2])
      ))+temp[4]))-((com[1]*lm[2])-(com[2]*lm[1])));
    temp[0] = ((((cnk[7][1][2]*hnk[2][2])+((cnk[7][1][0]*hnk[2][0])+(
      cnk[7][1][1]*hnk[2][1])))+((lk[2][0]*rnk[7][2])-(lk[2][2]*rnk[7][0])))+(((
      (Cik[3][1][2]*hnk[0][2])+((Cik[3][1][0]*hnk[0][0])+(Cik[3][1][1]*hnk[0][1]
      )))+((lk[0][0]*rnk[5][2])-(lk[0][2]*rnk[5][0])))+(((cnk[6][1][2]*hnk[1][2]
      )+((cnk[6][1][0]*hnk[1][0])+(cnk[6][1][1]*hnk[1][1])))+((lk[1][0]*
      rnk[6][2])-(lk[1][2]*rnk[6][0])))));
    temp[1] = ((((cnk[9][1][2]*hnk[4][2])+((cnk[9][1][0]*hnk[4][0])+(
      cnk[9][1][1]*hnk[4][1])))+((lk[4][0]*rnk[9][2])-(lk[4][2]*rnk[9][0])))+(((
      (cnk[8][1][2]*hnk[3][2])+((cnk[8][1][0]*hnk[3][0])+(cnk[8][1][1]*hnk[3][1]
      )))+((lk[3][0]*rnk[8][2])-(lk[3][2]*rnk[8][0])))+temp[0]));
    temp[2] = ((((cnk[11][1][2]*hnk[6][2])+((cnk[11][1][0]*hnk[6][0])+(
      cnk[11][1][1]*hnk[6][1])))+((lk[6][0]*rnk[11][2])-(lk[6][2]*rnk[11][0])))+
      ((((cnk[10][1][2]*hnk[5][2])+((cnk[10][1][0]*hnk[5][0])+(cnk[10][1][1]*
      hnk[5][1])))+((lk[5][0]*rnk[10][2])-(lk[5][2]*rnk[10][0])))+temp[1]));
    temp[3] = ((((cnk[13][1][2]*hnk[8][2])+((cnk[13][1][0]*hnk[8][0])+(
      cnk[13][1][1]*hnk[8][1])))+((lk[8][0]*rnk[13][2])-(lk[8][2]*rnk[13][0])))+
      ((((cnk[12][1][2]*hnk[7][2])+((cnk[12][1][0]*hnk[7][0])+(cnk[12][1][1]*
      hnk[7][1])))+((lk[7][0]*rnk[12][2])-(lk[7][2]*rnk[12][0])))+temp[2]));
    temp[4] = ((((cnk[15][1][2]*hnk[10][2])+((cnk[15][1][0]*hnk[10][0])+(
      cnk[15][1][1]*hnk[10][1])))+((lk[10][0]*rnk[15][2])-(lk[10][2]*rnk[15][0])
      ))+((((cnk[14][1][2]*hnk[9][2])+((cnk[14][1][0]*hnk[9][0])+(cnk[14][1][1]*
      hnk[9][1])))+((lk[9][0]*rnk[14][2])-(lk[9][2]*rnk[14][0])))+temp[3]));
    am[1] = (((((cnk[17][1][2]*hnk[12][2])+((cnk[17][1][0]*hnk[12][0])+(
      cnk[17][1][1]*hnk[12][1])))+((lk[12][0]*rnk[17][2])-(lk[12][2]*rnk[17][0])
      ))+((((cnk[16][1][2]*hnk[11][2])+((cnk[16][1][0]*hnk[11][0])+(
      cnk[16][1][1]*hnk[11][1])))+((lk[11][0]*rnk[16][2])-(lk[11][2]*rnk[16][0])
      ))+temp[4]))-((com[2]*lm[0])-(com[0]*lm[2])));
    temp[0] = ((((cnk[7][2][2]*hnk[2][2])+((cnk[7][2][0]*hnk[2][0])+(
      cnk[7][2][1]*hnk[2][1])))+((lk[2][1]*rnk[7][0])-(lk[2][0]*rnk[7][1])))+(((
      (Cik[3][2][2]*hnk[0][2])+((Cik[3][2][0]*hnk[0][0])+(Cik[3][2][1]*hnk[0][1]
      )))+((lk[0][1]*rnk[5][0])-(lk[0][0]*rnk[5][1])))+(((cnk[6][2][2]*hnk[1][2]
      )+((cnk[6][2][0]*hnk[1][0])+(cnk[6][2][1]*hnk[1][1])))+((lk[1][1]*
      rnk[6][0])-(lk[1][0]*rnk[6][1])))));
    temp[1] = ((((cnk[9][2][2]*hnk[4][2])+((cnk[9][2][0]*hnk[4][0])+(
      cnk[9][2][1]*hnk[4][1])))+((lk[4][1]*rnk[9][0])-(lk[4][0]*rnk[9][1])))+(((
      (cnk[8][2][2]*hnk[3][2])+((cnk[8][2][0]*hnk[3][0])+(cnk[8][2][1]*hnk[3][1]
      )))+((lk[3][1]*rnk[8][0])-(lk[3][0]*rnk[8][1])))+temp[0]));
    temp[2] = ((((cnk[11][2][2]*hnk[6][2])+((cnk[11][2][0]*hnk[6][0])+(
      cnk[11][2][1]*hnk[6][1])))+((lk[6][1]*rnk[11][0])-(lk[6][0]*rnk[11][1])))+
      ((((cnk[10][2][2]*hnk[5][2])+((cnk[10][2][0]*hnk[5][0])+(cnk[10][2][1]*
      hnk[5][1])))+((lk[5][1]*rnk[10][0])-(lk[5][0]*rnk[10][1])))+temp[1]));
    temp[3] = ((((cnk[13][2][2]*hnk[8][2])+((cnk[13][2][0]*hnk[8][0])+(
      cnk[13][2][1]*hnk[8][1])))+((lk[8][1]*rnk[13][0])-(lk[8][0]*rnk[13][1])))+
      ((((cnk[12][2][2]*hnk[7][2])+((cnk[12][2][0]*hnk[7][0])+(cnk[12][2][1]*
      hnk[7][1])))+((lk[7][1]*rnk[12][0])-(lk[7][0]*rnk[12][1])))+temp[2]));
    temp[4] = ((((cnk[15][2][2]*hnk[10][2])+((cnk[15][2][0]*hnk[10][0])+(
      cnk[15][2][1]*hnk[10][1])))+((lk[10][1]*rnk[15][0])-(lk[10][0]*rnk[15][1])
      ))+((((cnk[14][2][2]*hnk[9][2])+((cnk[14][2][0]*hnk[9][0])+(cnk[14][2][1]*
      hnk[9][1])))+((lk[9][1]*rnk[14][0])-(lk[9][0]*rnk[14][1])))+temp[3]));
    am[2] = (((((cnk[17][2][2]*hnk[12][2])+((cnk[17][2][0]*hnk[12][0])+(
      cnk[17][2][1]*hnk[12][1])))+((lk[12][1]*rnk[17][0])-(lk[12][0]*rnk[17][1])
      ))+((((cnk[16][2][2]*hnk[11][2])+((cnk[16][2][0]*hnk[11][0])+(
      cnk[16][2][1]*hnk[11][1])))+((lk[11][1]*rnk[16][0])-(lk[11][0]*rnk[16][1])
      ))+temp[4]))-((com[0]*lm[1])-(com[1]*lm[0])));
    temp[0] = ((((hnk[0][2]*u[5])+((hnk[0][0]*u[3])+(hnk[0][1]*u[4])))+((
      lk[0][2]*vnk[5][2])+((lk[0][0]*vnk[5][0])+(lk[0][1]*vnk[5][1]))))+(((
      hnk[1][2]*wk[6][2])+((hnk[1][0]*wk[6][0])+(hnk[1][1]*wk[6][1])))+((
      lk[1][2]*vnk[6][2])+((lk[1][0]*vnk[6][0])+(lk[1][1]*vnk[6][1])))));
    temp[1] = ((((hnk[3][2]*wk[8][2])+((hnk[3][0]*wk[8][0])+(hnk[3][1]*wk[8][1])
      ))+((lk[3][2]*vnk[8][2])+((lk[3][0]*vnk[8][0])+(lk[3][1]*vnk[8][1]))))+(((
      (hnk[2][2]*wk[7][2])+((hnk[2][0]*wk[7][0])+(hnk[2][1]*wk[7][1])))+((
      lk[2][2]*vnk[7][2])+((lk[2][0]*vnk[7][0])+(lk[2][1]*vnk[7][1]))))+temp[0])
      );
    temp[2] = ((((hnk[5][2]*wk[10][2])+((hnk[5][0]*wk[10][0])+(hnk[5][1]*
      wk[10][1])))+((lk[5][2]*vnk[10][2])+((lk[5][0]*vnk[10][0])+(lk[5][1]*
      vnk[10][1]))))+((((hnk[4][2]*wk[9][2])+((hnk[4][0]*wk[9][0])+(hnk[4][1]*
      wk[9][1])))+((lk[4][2]*vnk[9][2])+((lk[4][0]*vnk[9][0])+(lk[4][1]*
      vnk[9][1]))))+temp[1]));
    temp[3] = ((((hnk[7][2]*wk[12][2])+((hnk[7][0]*wk[12][0])+(hnk[7][1]*
      wk[12][1])))+((lk[7][2]*vnk[12][2])+((lk[7][0]*vnk[12][0])+(lk[7][1]*
      vnk[12][1]))))+((((hnk[6][2]*wk[11][2])+((hnk[6][0]*wk[11][0])+(hnk[6][1]*
      wk[11][1])))+((lk[6][2]*vnk[11][2])+((lk[6][0]*vnk[11][0])+(lk[6][1]*
      vnk[11][1]))))+temp[2]));
    temp[4] = ((((hnk[9][2]*wk[14][2])+((hnk[9][0]*wk[14][0])+(hnk[9][1]*
      wk[14][1])))+((lk[9][2]*vnk[14][2])+((lk[9][0]*vnk[14][0])+(lk[9][1]*
      vnk[14][1]))))+((((hnk[8][2]*wk[13][2])+((hnk[8][0]*wk[13][0])+(hnk[8][1]*
      wk[13][1])))+((lk[8][2]*vnk[13][2])+((lk[8][0]*vnk[13][0])+(lk[8][1]*
      vnk[13][1]))))+temp[3]));
    temp[5] = ((((hnk[11][2]*wk[16][2])+((hnk[11][0]*wk[16][0])+(hnk[11][1]*
      wk[16][1])))+((lk[11][2]*vnk[16][2])+((lk[11][0]*vnk[16][0])+(lk[11][1]*
      vnk[16][1]))))+((((hnk[10][2]*wk[15][2])+((hnk[10][0]*wk[15][0])+(
      hnk[10][1]*wk[15][1])))+((lk[10][2]*vnk[15][2])+((lk[10][0]*vnk[15][0])+(
      lk[10][1]*vnk[15][1]))))+temp[4]));
    *ke = (.5*((((hnk[12][2]*wk[17][2])+((hnk[12][0]*wk[17][0])+(hnk[12][1]*
      wk[17][1])))+((lk[12][2]*vnk[17][2])+((lk[12][0]*vnk[17][0])+(lk[12][1]*
      vnk[17][1]))))+temp[5]));
/*
 Used 0.02 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  389 adds/subtracts/negates
                    436 multiplies
                      0 divides
                    106 assignments
*/
}

void sdsys(double *mtoto,
    double cm[3],
    double icm[3][3])
{
/*
Compute system total mass, and instantaneous center of mass and
inertia matrix.

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
    double ikcnkt[18][3][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(20,23);
        return;
    }
    *mtoto = mtot;
    cm[0] = com[0];
    cm[1] = com[1];
    cm[2] = com[2];
    ikcnkt[5][0][0] = ((Cik[3][0][2]*ik[0][0][2])+((Cik[3][0][0]*ik[0][0][0])+(
      Cik[3][0][1]*ik[0][0][1])));
    ikcnkt[5][0][1] = ((Cik[3][1][2]*ik[0][0][2])+((Cik[3][1][0]*ik[0][0][0])+(
      Cik[3][1][1]*ik[0][0][1])));
    ikcnkt[5][0][2] = ((Cik[3][2][2]*ik[0][0][2])+((Cik[3][2][0]*ik[0][0][0])+(
      Cik[3][2][1]*ik[0][0][1])));
    ikcnkt[5][1][0] = ((Cik[3][0][2]*ik[0][1][2])+((Cik[3][0][0]*ik[0][1][0])+(
      Cik[3][0][1]*ik[0][1][1])));
    ikcnkt[5][1][1] = ((Cik[3][1][2]*ik[0][1][2])+((Cik[3][1][0]*ik[0][1][0])+(
      Cik[3][1][1]*ik[0][1][1])));
    ikcnkt[5][1][2] = ((Cik[3][2][2]*ik[0][1][2])+((Cik[3][2][0]*ik[0][1][0])+(
      Cik[3][2][1]*ik[0][1][1])));
    ikcnkt[5][2][0] = ((Cik[3][0][2]*ik[0][2][2])+((Cik[3][0][0]*ik[0][2][0])+(
      Cik[3][0][1]*ik[0][2][1])));
    ikcnkt[5][2][1] = ((Cik[3][1][2]*ik[0][2][2])+((Cik[3][1][0]*ik[0][2][0])+(
      Cik[3][1][1]*ik[0][2][1])));
    ikcnkt[5][2][2] = ((Cik[3][2][2]*ik[0][2][2])+((Cik[3][2][0]*ik[0][2][0])+(
      Cik[3][2][1]*ik[0][2][1])));
    ikcnkt[6][0][0] = ((cnk[6][0][2]*ik[1][0][2])+((cnk[6][0][0]*ik[1][0][0])+(
      cnk[6][0][1]*ik[1][0][1])));
    ikcnkt[6][0][1] = ((cnk[6][1][2]*ik[1][0][2])+((cnk[6][1][0]*ik[1][0][0])+(
      cnk[6][1][1]*ik[1][0][1])));
    ikcnkt[6][0][2] = ((cnk[6][2][2]*ik[1][0][2])+((cnk[6][2][0]*ik[1][0][0])+(
      cnk[6][2][1]*ik[1][0][1])));
    ikcnkt[6][1][0] = ((cnk[6][0][2]*ik[1][1][2])+((cnk[6][0][0]*ik[1][1][0])+(
      cnk[6][0][1]*ik[1][1][1])));
    ikcnkt[6][1][1] = ((cnk[6][1][2]*ik[1][1][2])+((cnk[6][1][0]*ik[1][1][0])+(
      cnk[6][1][1]*ik[1][1][1])));
    ikcnkt[6][1][2] = ((cnk[6][2][2]*ik[1][1][2])+((cnk[6][2][0]*ik[1][1][0])+(
      cnk[6][2][1]*ik[1][1][1])));
    ikcnkt[6][2][0] = ((cnk[6][0][2]*ik[1][2][2])+((cnk[6][0][0]*ik[1][2][0])+(
      cnk[6][0][1]*ik[1][2][1])));
    ikcnkt[6][2][1] = ((cnk[6][1][2]*ik[1][2][2])+((cnk[6][1][0]*ik[1][2][0])+(
      cnk[6][1][1]*ik[1][2][1])));
    ikcnkt[6][2][2] = ((cnk[6][2][2]*ik[1][2][2])+((cnk[6][2][0]*ik[1][2][0])+(
      cnk[6][2][1]*ik[1][2][1])));
    ikcnkt[7][0][0] = ((cnk[7][0][2]*ik[2][0][2])+((cnk[7][0][0]*ik[2][0][0])+(
      cnk[7][0][1]*ik[2][0][1])));
    ikcnkt[7][0][1] = ((cnk[7][1][2]*ik[2][0][2])+((cnk[7][1][0]*ik[2][0][0])+(
      cnk[7][1][1]*ik[2][0][1])));
    ikcnkt[7][0][2] = ((cnk[7][2][2]*ik[2][0][2])+((cnk[7][2][0]*ik[2][0][0])+(
      cnk[7][2][1]*ik[2][0][1])));
    ikcnkt[7][1][0] = ((cnk[7][0][2]*ik[2][1][2])+((cnk[7][0][0]*ik[2][1][0])+(
      cnk[7][0][1]*ik[2][1][1])));
    ikcnkt[7][1][1] = ((cnk[7][1][2]*ik[2][1][2])+((cnk[7][1][0]*ik[2][1][0])+(
      cnk[7][1][1]*ik[2][1][1])));
    ikcnkt[7][1][2] = ((cnk[7][2][2]*ik[2][1][2])+((cnk[7][2][0]*ik[2][1][0])+(
      cnk[7][2][1]*ik[2][1][1])));
    ikcnkt[7][2][0] = ((cnk[7][0][2]*ik[2][2][2])+((cnk[7][0][0]*ik[2][2][0])+(
      cnk[7][0][1]*ik[2][2][1])));
    ikcnkt[7][2][1] = ((cnk[7][1][2]*ik[2][2][2])+((cnk[7][1][0]*ik[2][2][0])+(
      cnk[7][1][1]*ik[2][2][1])));
    ikcnkt[7][2][2] = ((cnk[7][2][2]*ik[2][2][2])+((cnk[7][2][0]*ik[2][2][0])+(
      cnk[7][2][1]*ik[2][2][1])));
    ikcnkt[8][0][0] = ((cnk[8][0][2]*ik[3][0][2])+((cnk[8][0][0]*ik[3][0][0])+(
      cnk[8][0][1]*ik[3][0][1])));
    ikcnkt[8][0][1] = ((cnk[8][1][2]*ik[3][0][2])+((cnk[8][1][0]*ik[3][0][0])+(
      cnk[8][1][1]*ik[3][0][1])));
    ikcnkt[8][0][2] = ((cnk[8][2][2]*ik[3][0][2])+((cnk[8][2][0]*ik[3][0][0])+(
      cnk[8][2][1]*ik[3][0][1])));
    ikcnkt[8][1][0] = ((cnk[8][0][2]*ik[3][1][2])+((cnk[8][0][0]*ik[3][1][0])+(
      cnk[8][0][1]*ik[3][1][1])));
    ikcnkt[8][1][1] = ((cnk[8][1][2]*ik[3][1][2])+((cnk[8][1][0]*ik[3][1][0])+(
      cnk[8][1][1]*ik[3][1][1])));
    ikcnkt[8][1][2] = ((cnk[8][2][2]*ik[3][1][2])+((cnk[8][2][0]*ik[3][1][0])+(
      cnk[8][2][1]*ik[3][1][1])));
    ikcnkt[8][2][0] = ((cnk[8][0][2]*ik[3][2][2])+((cnk[8][0][0]*ik[3][2][0])+(
      cnk[8][0][1]*ik[3][2][1])));
    ikcnkt[8][2][1] = ((cnk[8][1][2]*ik[3][2][2])+((cnk[8][1][0]*ik[3][2][0])+(
      cnk[8][1][1]*ik[3][2][1])));
    ikcnkt[8][2][2] = ((cnk[8][2][2]*ik[3][2][2])+((cnk[8][2][0]*ik[3][2][0])+(
      cnk[8][2][1]*ik[3][2][1])));
    ikcnkt[9][0][0] = ((cnk[9][0][2]*ik[4][0][2])+((cnk[9][0][0]*ik[4][0][0])+(
      cnk[9][0][1]*ik[4][0][1])));
    ikcnkt[9][0][1] = ((cnk[9][1][2]*ik[4][0][2])+((cnk[9][1][0]*ik[4][0][0])+(
      cnk[9][1][1]*ik[4][0][1])));
    ikcnkt[9][0][2] = ((cnk[9][2][2]*ik[4][0][2])+((cnk[9][2][0]*ik[4][0][0])+(
      cnk[9][2][1]*ik[4][0][1])));
    ikcnkt[9][1][0] = ((cnk[9][0][2]*ik[4][1][2])+((cnk[9][0][0]*ik[4][1][0])+(
      cnk[9][0][1]*ik[4][1][1])));
    ikcnkt[9][1][1] = ((cnk[9][1][2]*ik[4][1][2])+((cnk[9][1][0]*ik[4][1][0])+(
      cnk[9][1][1]*ik[4][1][1])));
    ikcnkt[9][1][2] = ((cnk[9][2][2]*ik[4][1][2])+((cnk[9][2][0]*ik[4][1][0])+(
      cnk[9][2][1]*ik[4][1][1])));
    ikcnkt[9][2][0] = ((cnk[9][0][2]*ik[4][2][2])+((cnk[9][0][0]*ik[4][2][0])+(
      cnk[9][0][1]*ik[4][2][1])));
    ikcnkt[9][2][1] = ((cnk[9][1][2]*ik[4][2][2])+((cnk[9][1][0]*ik[4][2][0])+(
      cnk[9][1][1]*ik[4][2][1])));
    ikcnkt[9][2][2] = ((cnk[9][2][2]*ik[4][2][2])+((cnk[9][2][0]*ik[4][2][0])+(
      cnk[9][2][1]*ik[4][2][1])));
    ikcnkt[10][0][0] = ((cnk[10][0][2]*ik[5][0][2])+((cnk[10][0][0]*ik[5][0][0])
      +(cnk[10][0][1]*ik[5][0][1])));
    ikcnkt[10][0][1] = ((cnk[10][1][2]*ik[5][0][2])+((cnk[10][1][0]*ik[5][0][0])
      +(cnk[10][1][1]*ik[5][0][1])));
    ikcnkt[10][0][2] = ((cnk[10][2][2]*ik[5][0][2])+((cnk[10][2][0]*ik[5][0][0])
      +(cnk[10][2][1]*ik[5][0][1])));
    ikcnkt[10][1][0] = ((cnk[10][0][2]*ik[5][1][2])+((cnk[10][0][0]*ik[5][1][0])
      +(cnk[10][0][1]*ik[5][1][1])));
    ikcnkt[10][1][1] = ((cnk[10][1][2]*ik[5][1][2])+((cnk[10][1][0]*ik[5][1][0])
      +(cnk[10][1][1]*ik[5][1][1])));
    ikcnkt[10][1][2] = ((cnk[10][2][2]*ik[5][1][2])+((cnk[10][2][0]*ik[5][1][0])
      +(cnk[10][2][1]*ik[5][1][1])));
    ikcnkt[10][2][0] = ((cnk[10][0][2]*ik[5][2][2])+((cnk[10][0][0]*ik[5][2][0])
      +(cnk[10][0][1]*ik[5][2][1])));
    ikcnkt[10][2][1] = ((cnk[10][1][2]*ik[5][2][2])+((cnk[10][1][0]*ik[5][2][0])
      +(cnk[10][1][1]*ik[5][2][1])));
    ikcnkt[10][2][2] = ((cnk[10][2][2]*ik[5][2][2])+((cnk[10][2][0]*ik[5][2][0])
      +(cnk[10][2][1]*ik[5][2][1])));
    ikcnkt[11][0][0] = ((cnk[11][0][2]*ik[6][0][2])+((cnk[11][0][0]*ik[6][0][0])
      +(cnk[11][0][1]*ik[6][0][1])));
    ikcnkt[11][0][1] = ((cnk[11][1][2]*ik[6][0][2])+((cnk[11][1][0]*ik[6][0][0])
      +(cnk[11][1][1]*ik[6][0][1])));
    ikcnkt[11][0][2] = ((cnk[11][2][2]*ik[6][0][2])+((cnk[11][2][0]*ik[6][0][0])
      +(cnk[11][2][1]*ik[6][0][1])));
    ikcnkt[11][1][0] = ((cnk[11][0][2]*ik[6][1][2])+((cnk[11][0][0]*ik[6][1][0])
      +(cnk[11][0][1]*ik[6][1][1])));
    ikcnkt[11][1][1] = ((cnk[11][1][2]*ik[6][1][2])+((cnk[11][1][0]*ik[6][1][0])
      +(cnk[11][1][1]*ik[6][1][1])));
    ikcnkt[11][1][2] = ((cnk[11][2][2]*ik[6][1][2])+((cnk[11][2][0]*ik[6][1][0])
      +(cnk[11][2][1]*ik[6][1][1])));
    ikcnkt[11][2][0] = ((cnk[11][0][2]*ik[6][2][2])+((cnk[11][0][0]*ik[6][2][0])
      +(cnk[11][0][1]*ik[6][2][1])));
    ikcnkt[11][2][1] = ((cnk[11][1][2]*ik[6][2][2])+((cnk[11][1][0]*ik[6][2][0])
      +(cnk[11][1][1]*ik[6][2][1])));
    ikcnkt[11][2][2] = ((cnk[11][2][2]*ik[6][2][2])+((cnk[11][2][0]*ik[6][2][0])
      +(cnk[11][2][1]*ik[6][2][1])));
    ikcnkt[12][0][0] = ((cnk[12][0][2]*ik[7][0][2])+((cnk[12][0][0]*ik[7][0][0])
      +(cnk[12][0][1]*ik[7][0][1])));
    ikcnkt[12][0][1] = ((cnk[12][1][2]*ik[7][0][2])+((cnk[12][1][0]*ik[7][0][0])
      +(cnk[12][1][1]*ik[7][0][1])));
    ikcnkt[12][0][2] = ((cnk[12][2][2]*ik[7][0][2])+((cnk[12][2][0]*ik[7][0][0])
      +(cnk[12][2][1]*ik[7][0][1])));
    ikcnkt[12][1][0] = ((cnk[12][0][2]*ik[7][1][2])+((cnk[12][0][0]*ik[7][1][0])
      +(cnk[12][0][1]*ik[7][1][1])));
    ikcnkt[12][1][1] = ((cnk[12][1][2]*ik[7][1][2])+((cnk[12][1][0]*ik[7][1][0])
      +(cnk[12][1][1]*ik[7][1][1])));
    ikcnkt[12][1][2] = ((cnk[12][2][2]*ik[7][1][2])+((cnk[12][2][0]*ik[7][1][0])
      +(cnk[12][2][1]*ik[7][1][1])));
    ikcnkt[12][2][0] = ((cnk[12][0][2]*ik[7][2][2])+((cnk[12][0][0]*ik[7][2][0])
      +(cnk[12][0][1]*ik[7][2][1])));
    ikcnkt[12][2][1] = ((cnk[12][1][2]*ik[7][2][2])+((cnk[12][1][0]*ik[7][2][0])
      +(cnk[12][1][1]*ik[7][2][1])));
    ikcnkt[12][2][2] = ((cnk[12][2][2]*ik[7][2][2])+((cnk[12][2][0]*ik[7][2][0])
      +(cnk[12][2][1]*ik[7][2][1])));
    ikcnkt[13][0][0] = ((cnk[13][0][2]*ik[8][0][2])+((cnk[13][0][0]*ik[8][0][0])
      +(cnk[13][0][1]*ik[8][0][1])));
    ikcnkt[13][0][1] = ((cnk[13][1][2]*ik[8][0][2])+((cnk[13][1][0]*ik[8][0][0])
      +(cnk[13][1][1]*ik[8][0][1])));
    ikcnkt[13][0][2] = ((cnk[13][2][2]*ik[8][0][2])+((cnk[13][2][0]*ik[8][0][0])
      +(cnk[13][2][1]*ik[8][0][1])));
    ikcnkt[13][1][0] = ((cnk[13][0][2]*ik[8][1][2])+((cnk[13][0][0]*ik[8][1][0])
      +(cnk[13][0][1]*ik[8][1][1])));
    ikcnkt[13][1][1] = ((cnk[13][1][2]*ik[8][1][2])+((cnk[13][1][0]*ik[8][1][0])
      +(cnk[13][1][1]*ik[8][1][1])));
    ikcnkt[13][1][2] = ((cnk[13][2][2]*ik[8][1][2])+((cnk[13][2][0]*ik[8][1][0])
      +(cnk[13][2][1]*ik[8][1][1])));
    ikcnkt[13][2][0] = ((cnk[13][0][2]*ik[8][2][2])+((cnk[13][0][0]*ik[8][2][0])
      +(cnk[13][0][1]*ik[8][2][1])));
    ikcnkt[13][2][1] = ((cnk[13][1][2]*ik[8][2][2])+((cnk[13][1][0]*ik[8][2][0])
      +(cnk[13][1][1]*ik[8][2][1])));
    ikcnkt[13][2][2] = ((cnk[13][2][2]*ik[8][2][2])+((cnk[13][2][0]*ik[8][2][0])
      +(cnk[13][2][1]*ik[8][2][1])));
    ikcnkt[14][0][0] = ((cnk[14][0][2]*ik[9][0][2])+((cnk[14][0][0]*ik[9][0][0])
      +(cnk[14][0][1]*ik[9][0][1])));
    ikcnkt[14][0][1] = ((cnk[14][1][2]*ik[9][0][2])+((cnk[14][1][0]*ik[9][0][0])
      +(cnk[14][1][1]*ik[9][0][1])));
    ikcnkt[14][0][2] = ((cnk[14][2][2]*ik[9][0][2])+((cnk[14][2][0]*ik[9][0][0])
      +(cnk[14][2][1]*ik[9][0][1])));
    ikcnkt[14][1][0] = ((cnk[14][0][2]*ik[9][1][2])+((cnk[14][0][0]*ik[9][1][0])
      +(cnk[14][0][1]*ik[9][1][1])));
    ikcnkt[14][1][1] = ((cnk[14][1][2]*ik[9][1][2])+((cnk[14][1][0]*ik[9][1][0])
      +(cnk[14][1][1]*ik[9][1][1])));
    ikcnkt[14][1][2] = ((cnk[14][2][2]*ik[9][1][2])+((cnk[14][2][0]*ik[9][1][0])
      +(cnk[14][2][1]*ik[9][1][1])));
    ikcnkt[14][2][0] = ((cnk[14][0][2]*ik[9][2][2])+((cnk[14][0][0]*ik[9][2][0])
      +(cnk[14][0][1]*ik[9][2][1])));
    ikcnkt[14][2][1] = ((cnk[14][1][2]*ik[9][2][2])+((cnk[14][1][0]*ik[9][2][0])
      +(cnk[14][1][1]*ik[9][2][1])));
    ikcnkt[14][2][2] = ((cnk[14][2][2]*ik[9][2][2])+((cnk[14][2][0]*ik[9][2][0])
      +(cnk[14][2][1]*ik[9][2][1])));
    ikcnkt[15][0][0] = ((cnk[15][0][2]*ik[10][0][2])+((cnk[15][0][0]*
      ik[10][0][0])+(cnk[15][0][1]*ik[10][0][1])));
    ikcnkt[15][0][1] = ((cnk[15][1][2]*ik[10][0][2])+((cnk[15][1][0]*
      ik[10][0][0])+(cnk[15][1][1]*ik[10][0][1])));
    ikcnkt[15][0][2] = ((cnk[15][2][2]*ik[10][0][2])+((cnk[15][2][0]*
      ik[10][0][0])+(cnk[15][2][1]*ik[10][0][1])));
    ikcnkt[15][1][0] = ((cnk[15][0][2]*ik[10][1][2])+((cnk[15][0][0]*
      ik[10][1][0])+(cnk[15][0][1]*ik[10][1][1])));
    ikcnkt[15][1][1] = ((cnk[15][1][2]*ik[10][1][2])+((cnk[15][1][0]*
      ik[10][1][0])+(cnk[15][1][1]*ik[10][1][1])));
    ikcnkt[15][1][2] = ((cnk[15][2][2]*ik[10][1][2])+((cnk[15][2][0]*
      ik[10][1][0])+(cnk[15][2][1]*ik[10][1][1])));
    ikcnkt[15][2][0] = ((cnk[15][0][2]*ik[10][2][2])+((cnk[15][0][0]*
      ik[10][2][0])+(cnk[15][0][1]*ik[10][2][1])));
    ikcnkt[15][2][1] = ((cnk[15][1][2]*ik[10][2][2])+((cnk[15][1][0]*
      ik[10][2][0])+(cnk[15][1][1]*ik[10][2][1])));
    ikcnkt[15][2][2] = ((cnk[15][2][2]*ik[10][2][2])+((cnk[15][2][0]*
      ik[10][2][0])+(cnk[15][2][1]*ik[10][2][1])));
    ikcnkt[16][0][0] = ((cnk[16][0][2]*ik[11][0][2])+((cnk[16][0][0]*
      ik[11][0][0])+(cnk[16][0][1]*ik[11][0][1])));
    ikcnkt[16][0][1] = ((cnk[16][1][2]*ik[11][0][2])+((cnk[16][1][0]*
      ik[11][0][0])+(cnk[16][1][1]*ik[11][0][1])));
    ikcnkt[16][0][2] = ((cnk[16][2][2]*ik[11][0][2])+((cnk[16][2][0]*
      ik[11][0][0])+(cnk[16][2][1]*ik[11][0][1])));
    ikcnkt[16][1][0] = ((cnk[16][0][2]*ik[11][1][2])+((cnk[16][0][0]*
      ik[11][1][0])+(cnk[16][0][1]*ik[11][1][1])));
    ikcnkt[16][1][1] = ((cnk[16][1][2]*ik[11][1][2])+((cnk[16][1][0]*
      ik[11][1][0])+(cnk[16][1][1]*ik[11][1][1])));
    ikcnkt[16][1][2] = ((cnk[16][2][2]*ik[11][1][2])+((cnk[16][2][0]*
      ik[11][1][0])+(cnk[16][2][1]*ik[11][1][1])));
    ikcnkt[16][2][0] = ((cnk[16][0][2]*ik[11][2][2])+((cnk[16][0][0]*
      ik[11][2][0])+(cnk[16][0][1]*ik[11][2][1])));
    ikcnkt[16][2][1] = ((cnk[16][1][2]*ik[11][2][2])+((cnk[16][1][0]*
      ik[11][2][0])+(cnk[16][1][1]*ik[11][2][1])));
    ikcnkt[16][2][2] = ((cnk[16][2][2]*ik[11][2][2])+((cnk[16][2][0]*
      ik[11][2][0])+(cnk[16][2][1]*ik[11][2][1])));
    ikcnkt[17][0][0] = ((cnk[17][0][2]*ik[12][0][2])+((cnk[17][0][0]*
      ik[12][0][0])+(cnk[17][0][1]*ik[12][0][1])));
    ikcnkt[17][0][1] = ((cnk[17][1][2]*ik[12][0][2])+((cnk[17][1][0]*
      ik[12][0][0])+(cnk[17][1][1]*ik[12][0][1])));
    ikcnkt[17][0][2] = ((cnk[17][2][2]*ik[12][0][2])+((cnk[17][2][0]*
      ik[12][0][0])+(cnk[17][2][1]*ik[12][0][1])));
    ikcnkt[17][1][0] = ((cnk[17][0][2]*ik[12][1][2])+((cnk[17][0][0]*
      ik[12][1][0])+(cnk[17][0][1]*ik[12][1][1])));
    ikcnkt[17][1][1] = ((cnk[17][1][2]*ik[12][1][2])+((cnk[17][1][0]*
      ik[12][1][0])+(cnk[17][1][1]*ik[12][1][1])));
    ikcnkt[17][1][2] = ((cnk[17][2][2]*ik[12][1][2])+((cnk[17][2][0]*
      ik[12][1][0])+(cnk[17][2][1]*ik[12][1][1])));
    ikcnkt[17][2][0] = ((cnk[17][0][2]*ik[12][2][2])+((cnk[17][0][0]*
      ik[12][2][0])+(cnk[17][0][1]*ik[12][2][1])));
    ikcnkt[17][2][1] = ((cnk[17][1][2]*ik[12][2][2])+((cnk[17][1][0]*
      ik[12][2][0])+(cnk[17][1][1]*ik[12][2][1])));
    ikcnkt[17][2][2] = ((cnk[17][2][2]*ik[12][2][2])+((cnk[17][2][0]*
      ik[12][2][0])+(cnk[17][2][1]*ik[12][2][1])));
    temp[0] = (((mk[0]*((rnk[5][1]*rnk[5][1])+(rnk[5][2]*rnk[5][2])))+((
      Cik[3][0][2]*ikcnkt[5][2][0])+((Cik[3][0][0]*ikcnkt[5][0][0])+(
      Cik[3][0][1]*ikcnkt[5][1][0]))))+((mk[1]*((rnk[6][1]*rnk[6][1])+(rnk[6][2]
      *rnk[6][2])))+((cnk[6][0][2]*ikcnkt[6][2][0])+((cnk[6][0][0]*
      ikcnkt[6][0][0])+(cnk[6][0][1]*ikcnkt[6][1][0])))));
    temp[1] = (((mk[3]*((rnk[8][1]*rnk[8][1])+(rnk[8][2]*rnk[8][2])))+((
      cnk[8][0][2]*ikcnkt[8][2][0])+((cnk[8][0][0]*ikcnkt[8][0][0])+(
      cnk[8][0][1]*ikcnkt[8][1][0]))))+(((mk[2]*((rnk[7][1]*rnk[7][1])+(
      rnk[7][2]*rnk[7][2])))+((cnk[7][0][2]*ikcnkt[7][2][0])+((cnk[7][0][0]*
      ikcnkt[7][0][0])+(cnk[7][0][1]*ikcnkt[7][1][0]))))+temp[0]));
    temp[2] = (((mk[5]*((rnk[10][1]*rnk[10][1])+(rnk[10][2]*rnk[10][2])))+((
      cnk[10][0][2]*ikcnkt[10][2][0])+((cnk[10][0][0]*ikcnkt[10][0][0])+(
      cnk[10][0][1]*ikcnkt[10][1][0]))))+(((mk[4]*((rnk[9][1]*rnk[9][1])+(
      rnk[9][2]*rnk[9][2])))+((cnk[9][0][2]*ikcnkt[9][2][0])+((cnk[9][0][0]*
      ikcnkt[9][0][0])+(cnk[9][0][1]*ikcnkt[9][1][0]))))+temp[1]));
    temp[3] = (((mk[7]*((rnk[12][1]*rnk[12][1])+(rnk[12][2]*rnk[12][2])))+((
      cnk[12][0][2]*ikcnkt[12][2][0])+((cnk[12][0][0]*ikcnkt[12][0][0])+(
      cnk[12][0][1]*ikcnkt[12][1][0]))))+(((mk[6]*((rnk[11][1]*rnk[11][1])+(
      rnk[11][2]*rnk[11][2])))+((cnk[11][0][2]*ikcnkt[11][2][0])+((cnk[11][0][0]
      *ikcnkt[11][0][0])+(cnk[11][0][1]*ikcnkt[11][1][0]))))+temp[2]));
    temp[4] = (((mk[9]*((rnk[14][1]*rnk[14][1])+(rnk[14][2]*rnk[14][2])))+((
      cnk[14][0][2]*ikcnkt[14][2][0])+((cnk[14][0][0]*ikcnkt[14][0][0])+(
      cnk[14][0][1]*ikcnkt[14][1][0]))))+(((mk[8]*((rnk[13][1]*rnk[13][1])+(
      rnk[13][2]*rnk[13][2])))+((cnk[13][0][2]*ikcnkt[13][2][0])+((cnk[13][0][0]
      *ikcnkt[13][0][0])+(cnk[13][0][1]*ikcnkt[13][1][0]))))+temp[3]));
    temp[5] = (((mk[11]*((rnk[16][1]*rnk[16][1])+(rnk[16][2]*rnk[16][2])))+((
      cnk[16][0][2]*ikcnkt[16][2][0])+((cnk[16][0][0]*ikcnkt[16][0][0])+(
      cnk[16][0][1]*ikcnkt[16][1][0]))))+(((mk[10]*((rnk[15][1]*rnk[15][1])+(
      rnk[15][2]*rnk[15][2])))+((cnk[15][0][2]*ikcnkt[15][2][0])+((cnk[15][0][0]
      *ikcnkt[15][0][0])+(cnk[15][0][1]*ikcnkt[15][1][0]))))+temp[4]));
    icm[0][0] = ((((mk[12]*((rnk[17][1]*rnk[17][1])+(rnk[17][2]*rnk[17][2])))+((
      cnk[17][0][2]*ikcnkt[17][2][0])+((cnk[17][0][0]*ikcnkt[17][0][0])+(
      cnk[17][0][1]*ikcnkt[17][1][0]))))+temp[5])-(mtot*((com[1]*com[1])+(com[2]
      *com[2]))));
    temp[0] = ((((cnk[7][0][2]*ikcnkt[7][2][1])+((cnk[7][0][0]*ikcnkt[7][0][1])+
      (cnk[7][0][1]*ikcnkt[7][1][1])))-(mk[2]*(rnk[7][0]*rnk[7][1])))+((((
      Cik[3][0][2]*ikcnkt[5][2][1])+((Cik[3][0][0]*ikcnkt[5][0][1])+(
      Cik[3][0][1]*ikcnkt[5][1][1])))-(mk[0]*(rnk[5][0]*rnk[5][1])))+(((
      cnk[6][0][2]*ikcnkt[6][2][1])+((cnk[6][0][0]*ikcnkt[6][0][1])+(
      cnk[6][0][1]*ikcnkt[6][1][1])))-(mk[1]*(rnk[6][0]*rnk[6][1])))));
    temp[1] = ((((cnk[10][0][2]*ikcnkt[10][2][1])+((cnk[10][0][0]*
      ikcnkt[10][0][1])+(cnk[10][0][1]*ikcnkt[10][1][1])))-(mk[5]*(rnk[10][0]*
      rnk[10][1])))+((((cnk[9][0][2]*ikcnkt[9][2][1])+((cnk[9][0][0]*
      ikcnkt[9][0][1])+(cnk[9][0][1]*ikcnkt[9][1][1])))-(mk[4]*(rnk[9][0]*
      rnk[9][1])))+((((cnk[8][0][2]*ikcnkt[8][2][1])+((cnk[8][0][0]*
      ikcnkt[8][0][1])+(cnk[8][0][1]*ikcnkt[8][1][1])))-(mk[3]*(rnk[8][0]*
      rnk[8][1])))+temp[0])));
    temp[2] = ((((cnk[13][0][2]*ikcnkt[13][2][1])+((cnk[13][0][0]*
      ikcnkt[13][0][1])+(cnk[13][0][1]*ikcnkt[13][1][1])))-(mk[8]*(rnk[13][0]*
      rnk[13][1])))+((((cnk[12][0][2]*ikcnkt[12][2][1])+((cnk[12][0][0]*
      ikcnkt[12][0][1])+(cnk[12][0][1]*ikcnkt[12][1][1])))-(mk[7]*(rnk[12][0]*
      rnk[12][1])))+((((cnk[11][0][2]*ikcnkt[11][2][1])+((cnk[11][0][0]*
      ikcnkt[11][0][1])+(cnk[11][0][1]*ikcnkt[11][1][1])))-(mk[6]*(rnk[11][0]*
      rnk[11][1])))+temp[1])));
    temp[3] = ((((cnk[16][0][2]*ikcnkt[16][2][1])+((cnk[16][0][0]*
      ikcnkt[16][0][1])+(cnk[16][0][1]*ikcnkt[16][1][1])))-(mk[11]*(rnk[16][0]*
      rnk[16][1])))+((((cnk[15][0][2]*ikcnkt[15][2][1])+((cnk[15][0][0]*
      ikcnkt[15][0][1])+(cnk[15][0][1]*ikcnkt[15][1][1])))-(mk[10]*(rnk[15][0]*
      rnk[15][1])))+((((cnk[14][0][2]*ikcnkt[14][2][1])+((cnk[14][0][0]*
      ikcnkt[14][0][1])+(cnk[14][0][1]*ikcnkt[14][1][1])))-(mk[9]*(rnk[14][0]*
      rnk[14][1])))+temp[2])));
    icm[0][1] = ((mtot*(com[0]*com[1]))+((((cnk[17][0][2]*ikcnkt[17][2][1])+((
      cnk[17][0][0]*ikcnkt[17][0][1])+(cnk[17][0][1]*ikcnkt[17][1][1])))-(mk[12]
      *(rnk[17][0]*rnk[17][1])))+temp[3]));
    temp[0] = ((((cnk[7][0][2]*ikcnkt[7][2][2])+((cnk[7][0][0]*ikcnkt[7][0][2])+
      (cnk[7][0][1]*ikcnkt[7][1][2])))-(mk[2]*(rnk[7][0]*rnk[7][2])))+((((
      Cik[3][0][2]*ikcnkt[5][2][2])+((Cik[3][0][0]*ikcnkt[5][0][2])+(
      Cik[3][0][1]*ikcnkt[5][1][2])))-(mk[0]*(rnk[5][0]*rnk[5][2])))+(((
      cnk[6][0][2]*ikcnkt[6][2][2])+((cnk[6][0][0]*ikcnkt[6][0][2])+(
      cnk[6][0][1]*ikcnkt[6][1][2])))-(mk[1]*(rnk[6][0]*rnk[6][2])))));
    temp[1] = ((((cnk[10][0][2]*ikcnkt[10][2][2])+((cnk[10][0][0]*
      ikcnkt[10][0][2])+(cnk[10][0][1]*ikcnkt[10][1][2])))-(mk[5]*(rnk[10][0]*
      rnk[10][2])))+((((cnk[9][0][2]*ikcnkt[9][2][2])+((cnk[9][0][0]*
      ikcnkt[9][0][2])+(cnk[9][0][1]*ikcnkt[9][1][2])))-(mk[4]*(rnk[9][0]*
      rnk[9][2])))+((((cnk[8][0][2]*ikcnkt[8][2][2])+((cnk[8][0][0]*
      ikcnkt[8][0][2])+(cnk[8][0][1]*ikcnkt[8][1][2])))-(mk[3]*(rnk[8][0]*
      rnk[8][2])))+temp[0])));
    temp[2] = ((((cnk[13][0][2]*ikcnkt[13][2][2])+((cnk[13][0][0]*
      ikcnkt[13][0][2])+(cnk[13][0][1]*ikcnkt[13][1][2])))-(mk[8]*(rnk[13][0]*
      rnk[13][2])))+((((cnk[12][0][2]*ikcnkt[12][2][2])+((cnk[12][0][0]*
      ikcnkt[12][0][2])+(cnk[12][0][1]*ikcnkt[12][1][2])))-(mk[7]*(rnk[12][0]*
      rnk[12][2])))+((((cnk[11][0][2]*ikcnkt[11][2][2])+((cnk[11][0][0]*
      ikcnkt[11][0][2])+(cnk[11][0][1]*ikcnkt[11][1][2])))-(mk[6]*(rnk[11][0]*
      rnk[11][2])))+temp[1])));
    temp[3] = ((((cnk[16][0][2]*ikcnkt[16][2][2])+((cnk[16][0][0]*
      ikcnkt[16][0][2])+(cnk[16][0][1]*ikcnkt[16][1][2])))-(mk[11]*(rnk[16][0]*
      rnk[16][2])))+((((cnk[15][0][2]*ikcnkt[15][2][2])+((cnk[15][0][0]*
      ikcnkt[15][0][2])+(cnk[15][0][1]*ikcnkt[15][1][2])))-(mk[10]*(rnk[15][0]*
      rnk[15][2])))+((((cnk[14][0][2]*ikcnkt[14][2][2])+((cnk[14][0][0]*
      ikcnkt[14][0][2])+(cnk[14][0][1]*ikcnkt[14][1][2])))-(mk[9]*(rnk[14][0]*
      rnk[14][2])))+temp[2])));
    icm[0][2] = ((mtot*(com[0]*com[2]))+((((cnk[17][0][2]*ikcnkt[17][2][2])+((
      cnk[17][0][0]*ikcnkt[17][0][2])+(cnk[17][0][1]*ikcnkt[17][1][2])))-(mk[12]
      *(rnk[17][0]*rnk[17][2])))+temp[3]));
    icm[1][0] = icm[0][1];
    temp[0] = (((mk[0]*((rnk[5][0]*rnk[5][0])+(rnk[5][2]*rnk[5][2])))+((
      Cik[3][1][2]*ikcnkt[5][2][1])+((Cik[3][1][0]*ikcnkt[5][0][1])+(
      Cik[3][1][1]*ikcnkt[5][1][1]))))+((mk[1]*((rnk[6][0]*rnk[6][0])+(rnk[6][2]
      *rnk[6][2])))+((cnk[6][1][2]*ikcnkt[6][2][1])+((cnk[6][1][0]*
      ikcnkt[6][0][1])+(cnk[6][1][1]*ikcnkt[6][1][1])))));
    temp[1] = (((mk[3]*((rnk[8][0]*rnk[8][0])+(rnk[8][2]*rnk[8][2])))+((
      cnk[8][1][2]*ikcnkt[8][2][1])+((cnk[8][1][0]*ikcnkt[8][0][1])+(
      cnk[8][1][1]*ikcnkt[8][1][1]))))+(((mk[2]*((rnk[7][0]*rnk[7][0])+(
      rnk[7][2]*rnk[7][2])))+((cnk[7][1][2]*ikcnkt[7][2][1])+((cnk[7][1][0]*
      ikcnkt[7][0][1])+(cnk[7][1][1]*ikcnkt[7][1][1]))))+temp[0]));
    temp[2] = (((mk[5]*((rnk[10][0]*rnk[10][0])+(rnk[10][2]*rnk[10][2])))+((
      cnk[10][1][2]*ikcnkt[10][2][1])+((cnk[10][1][0]*ikcnkt[10][0][1])+(
      cnk[10][1][1]*ikcnkt[10][1][1]))))+(((mk[4]*((rnk[9][0]*rnk[9][0])+(
      rnk[9][2]*rnk[9][2])))+((cnk[9][1][2]*ikcnkt[9][2][1])+((cnk[9][1][0]*
      ikcnkt[9][0][1])+(cnk[9][1][1]*ikcnkt[9][1][1]))))+temp[1]));
    temp[3] = (((mk[7]*((rnk[12][0]*rnk[12][0])+(rnk[12][2]*rnk[12][2])))+((
      cnk[12][1][2]*ikcnkt[12][2][1])+((cnk[12][1][0]*ikcnkt[12][0][1])+(
      cnk[12][1][1]*ikcnkt[12][1][1]))))+(((mk[6]*((rnk[11][0]*rnk[11][0])+(
      rnk[11][2]*rnk[11][2])))+((cnk[11][1][2]*ikcnkt[11][2][1])+((cnk[11][1][0]
      *ikcnkt[11][0][1])+(cnk[11][1][1]*ikcnkt[11][1][1]))))+temp[2]));
    temp[4] = (((mk[9]*((rnk[14][0]*rnk[14][0])+(rnk[14][2]*rnk[14][2])))+((
      cnk[14][1][2]*ikcnkt[14][2][1])+((cnk[14][1][0]*ikcnkt[14][0][1])+(
      cnk[14][1][1]*ikcnkt[14][1][1]))))+(((mk[8]*((rnk[13][0]*rnk[13][0])+(
      rnk[13][2]*rnk[13][2])))+((cnk[13][1][2]*ikcnkt[13][2][1])+((cnk[13][1][0]
      *ikcnkt[13][0][1])+(cnk[13][1][1]*ikcnkt[13][1][1]))))+temp[3]));
    temp[5] = (((mk[11]*((rnk[16][0]*rnk[16][0])+(rnk[16][2]*rnk[16][2])))+((
      cnk[16][1][2]*ikcnkt[16][2][1])+((cnk[16][1][0]*ikcnkt[16][0][1])+(
      cnk[16][1][1]*ikcnkt[16][1][1]))))+(((mk[10]*((rnk[15][0]*rnk[15][0])+(
      rnk[15][2]*rnk[15][2])))+((cnk[15][1][2]*ikcnkt[15][2][1])+((cnk[15][1][0]
      *ikcnkt[15][0][1])+(cnk[15][1][1]*ikcnkt[15][1][1]))))+temp[4]));
    icm[1][1] = ((((mk[12]*((rnk[17][0]*rnk[17][0])+(rnk[17][2]*rnk[17][2])))+((
      cnk[17][1][2]*ikcnkt[17][2][1])+((cnk[17][1][0]*ikcnkt[17][0][1])+(
      cnk[17][1][1]*ikcnkt[17][1][1]))))+temp[5])-(mtot*((com[0]*com[0])+(com[2]
      *com[2]))));
    temp[0] = ((((cnk[7][1][2]*ikcnkt[7][2][2])+((cnk[7][1][0]*ikcnkt[7][0][2])+
      (cnk[7][1][1]*ikcnkt[7][1][2])))-(mk[2]*(rnk[7][1]*rnk[7][2])))+((((
      Cik[3][1][2]*ikcnkt[5][2][2])+((Cik[3][1][0]*ikcnkt[5][0][2])+(
      Cik[3][1][1]*ikcnkt[5][1][2])))-(mk[0]*(rnk[5][1]*rnk[5][2])))+(((
      cnk[6][1][2]*ikcnkt[6][2][2])+((cnk[6][1][0]*ikcnkt[6][0][2])+(
      cnk[6][1][1]*ikcnkt[6][1][2])))-(mk[1]*(rnk[6][1]*rnk[6][2])))));
    temp[1] = ((((cnk[10][1][2]*ikcnkt[10][2][2])+((cnk[10][1][0]*
      ikcnkt[10][0][2])+(cnk[10][1][1]*ikcnkt[10][1][2])))-(mk[5]*(rnk[10][1]*
      rnk[10][2])))+((((cnk[9][1][2]*ikcnkt[9][2][2])+((cnk[9][1][0]*
      ikcnkt[9][0][2])+(cnk[9][1][1]*ikcnkt[9][1][2])))-(mk[4]*(rnk[9][1]*
      rnk[9][2])))+((((cnk[8][1][2]*ikcnkt[8][2][2])+((cnk[8][1][0]*
      ikcnkt[8][0][2])+(cnk[8][1][1]*ikcnkt[8][1][2])))-(mk[3]*(rnk[8][1]*
      rnk[8][2])))+temp[0])));
    temp[2] = ((((cnk[13][1][2]*ikcnkt[13][2][2])+((cnk[13][1][0]*
      ikcnkt[13][0][2])+(cnk[13][1][1]*ikcnkt[13][1][2])))-(mk[8]*(rnk[13][1]*
      rnk[13][2])))+((((cnk[12][1][2]*ikcnkt[12][2][2])+((cnk[12][1][0]*
      ikcnkt[12][0][2])+(cnk[12][1][1]*ikcnkt[12][1][2])))-(mk[7]*(rnk[12][1]*
      rnk[12][2])))+((((cnk[11][1][2]*ikcnkt[11][2][2])+((cnk[11][1][0]*
      ikcnkt[11][0][2])+(cnk[11][1][1]*ikcnkt[11][1][2])))-(mk[6]*(rnk[11][1]*
      rnk[11][2])))+temp[1])));
    temp[3] = ((((cnk[16][1][2]*ikcnkt[16][2][2])+((cnk[16][1][0]*
      ikcnkt[16][0][2])+(cnk[16][1][1]*ikcnkt[16][1][2])))-(mk[11]*(rnk[16][1]*
      rnk[16][2])))+((((cnk[15][1][2]*ikcnkt[15][2][2])+((cnk[15][1][0]*
      ikcnkt[15][0][2])+(cnk[15][1][1]*ikcnkt[15][1][2])))-(mk[10]*(rnk[15][1]*
      rnk[15][2])))+((((cnk[14][1][2]*ikcnkt[14][2][2])+((cnk[14][1][0]*
      ikcnkt[14][0][2])+(cnk[14][1][1]*ikcnkt[14][1][2])))-(mk[9]*(rnk[14][1]*
      rnk[14][2])))+temp[2])));
    icm[1][2] = ((mtot*(com[1]*com[2]))+((((cnk[17][1][2]*ikcnkt[17][2][2])+((
      cnk[17][1][0]*ikcnkt[17][0][2])+(cnk[17][1][1]*ikcnkt[17][1][2])))-(mk[12]
      *(rnk[17][1]*rnk[17][2])))+temp[3]));
    icm[2][0] = icm[0][2];
    icm[2][1] = icm[1][2];
    temp[0] = (((mk[0]*((rnk[5][0]*rnk[5][0])+(rnk[5][1]*rnk[5][1])))+((
      Cik[3][2][2]*ikcnkt[5][2][2])+((Cik[3][2][0]*ikcnkt[5][0][2])+(
      Cik[3][2][1]*ikcnkt[5][1][2]))))+((mk[1]*((rnk[6][0]*rnk[6][0])+(rnk[6][1]
      *rnk[6][1])))+((cnk[6][2][2]*ikcnkt[6][2][2])+((cnk[6][2][0]*
      ikcnkt[6][0][2])+(cnk[6][2][1]*ikcnkt[6][1][2])))));
    temp[1] = (((mk[3]*((rnk[8][0]*rnk[8][0])+(rnk[8][1]*rnk[8][1])))+((
      cnk[8][2][2]*ikcnkt[8][2][2])+((cnk[8][2][0]*ikcnkt[8][0][2])+(
      cnk[8][2][1]*ikcnkt[8][1][2]))))+(((mk[2]*((rnk[7][0]*rnk[7][0])+(
      rnk[7][1]*rnk[7][1])))+((cnk[7][2][2]*ikcnkt[7][2][2])+((cnk[7][2][0]*
      ikcnkt[7][0][2])+(cnk[7][2][1]*ikcnkt[7][1][2]))))+temp[0]));
    temp[2] = (((mk[5]*((rnk[10][0]*rnk[10][0])+(rnk[10][1]*rnk[10][1])))+((
      cnk[10][2][2]*ikcnkt[10][2][2])+((cnk[10][2][0]*ikcnkt[10][0][2])+(
      cnk[10][2][1]*ikcnkt[10][1][2]))))+(((mk[4]*((rnk[9][0]*rnk[9][0])+(
      rnk[9][1]*rnk[9][1])))+((cnk[9][2][2]*ikcnkt[9][2][2])+((cnk[9][2][0]*
      ikcnkt[9][0][2])+(cnk[9][2][1]*ikcnkt[9][1][2]))))+temp[1]));
    temp[3] = (((mk[7]*((rnk[12][0]*rnk[12][0])+(rnk[12][1]*rnk[12][1])))+((
      cnk[12][2][2]*ikcnkt[12][2][2])+((cnk[12][2][0]*ikcnkt[12][0][2])+(
      cnk[12][2][1]*ikcnkt[12][1][2]))))+(((mk[6]*((rnk[11][0]*rnk[11][0])+(
      rnk[11][1]*rnk[11][1])))+((cnk[11][2][2]*ikcnkt[11][2][2])+((cnk[11][2][0]
      *ikcnkt[11][0][2])+(cnk[11][2][1]*ikcnkt[11][1][2]))))+temp[2]));
    temp[4] = (((mk[9]*((rnk[14][0]*rnk[14][0])+(rnk[14][1]*rnk[14][1])))+((
      cnk[14][2][2]*ikcnkt[14][2][2])+((cnk[14][2][0]*ikcnkt[14][0][2])+(
      cnk[14][2][1]*ikcnkt[14][1][2]))))+(((mk[8]*((rnk[13][0]*rnk[13][0])+(
      rnk[13][1]*rnk[13][1])))+((cnk[13][2][2]*ikcnkt[13][2][2])+((cnk[13][2][0]
      *ikcnkt[13][0][2])+(cnk[13][2][1]*ikcnkt[13][1][2]))))+temp[3]));
    temp[5] = (((mk[11]*((rnk[16][0]*rnk[16][0])+(rnk[16][1]*rnk[16][1])))+((
      cnk[16][2][2]*ikcnkt[16][2][2])+((cnk[16][2][0]*ikcnkt[16][0][2])+(
      cnk[16][2][1]*ikcnkt[16][1][2]))))+(((mk[10]*((rnk[15][0]*rnk[15][0])+(
      rnk[15][1]*rnk[15][1])))+((cnk[15][2][2]*ikcnkt[15][2][2])+((cnk[15][2][0]
      *ikcnkt[15][0][2])+(cnk[15][2][1]*ikcnkt[15][1][2]))))+temp[4]));
    icm[2][2] = ((((mk[12]*((rnk[17][0]*rnk[17][0])+(rnk[17][1]*rnk[17][1])))+((
      cnk[17][2][2]*ikcnkt[17][2][2])+((cnk[17][2][0]*ikcnkt[17][0][2])+(
      cnk[17][2][1]*ikcnkt[17][1][2]))))+temp[5])-(mtot*((com[0]*com[0])+(com[1]
      *com[1]))));
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  588 adds/subtracts/negates
                    795 multiplies
                      0 divides
                    160 assignments
*/
}

void sdpos(int body,
    double pt[3],
    double loc[3])
{
/*
Return inertial frame location of a point on a body.

*/
    double pv[3];

    if (sdchkbnum(21,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(21,23);
        return;
    }
    if (body  ==  -1) {
        loc[0] = pt[0];
        loc[1] = pt[1];
        loc[2] = pt[2];
    } else {
        pv[0] = rnb[body][0]+pt[0]*cnb[body][0][0]+pt[1]*cnb[body][0][1]+pt[2]*
          cnb[body][0][2];
        pv[1] = rnb[body][1]+pt[0]*cnb[body][1][0]+pt[1]*cnb[body][1][1]+pt[2]*
          cnb[body][1][2];
        pv[2] = rnb[body][2]+pt[0]*cnb[body][2][0]+pt[1]*cnb[body][2][1]+pt[2]*
          cnb[body][2][2];
        loc[0] = pv[0];
        loc[1] = pv[1];
        loc[2] = pv[2];
    }
}

void sdvel(int body,
    double pt[3],
    double velo[3])
{
/*
Return inertial frame velocity of a point on a body.

*/
    double pv[3];

    if (sdchkbnum(22,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(22,23);
        return;
    }
    if (body  ==  -1) {
        velo[0] = 0.;
        velo[1] = 0.;
        velo[2] = 0.;
    } else {
        pv[0] = wb[body][1]*pt[2]-wb[body][2]*pt[1];
        pv[1] = wb[body][2]*pt[0]-wb[body][0]*pt[2];
        pv[2] = wb[body][0]*pt[1]-wb[body][1]*pt[0];
        velo[0] = vnb[body][0]+pv[0]*cnb[body][0][0]+pv[1]*cnb[body][0][1]+pv[2]
          *cnb[body][0][2];
        velo[1] = vnb[body][1]+pv[0]*cnb[body][1][0]+pv[1]*cnb[body][1][1]+pv[2]
          *cnb[body][1][2];
        velo[2] = vnb[body][2]+pv[0]*cnb[body][2][0]+pv[1]*cnb[body][2][1]+pv[2]
          *cnb[body][2][2];
    }
}

void sdorient(int body,
    double dircos[3][3])
{
/*
Return orientation of body w.r.t. ground frame.

*/

    if (sdchkbnum(23,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(23,23);
        return;
    }
    if (body == -1) {
        dircos[0][0] = 1.;
        dircos[0][1] = 0.;
        dircos[0][2] = 0.;
        dircos[1][0] = 0.;
        dircos[1][1] = 1.;
        dircos[1][2] = 0.;
        dircos[2][0] = 0.;
        dircos[2][1] = 0.;
        dircos[2][2] = 1.;
    } else {
        dircos[0][0] = cnb[body][0][0];
        dircos[0][1] = cnb[body][0][1];
        dircos[0][2] = cnb[body][0][2];
        dircos[1][0] = cnb[body][1][0];
        dircos[1][1] = cnb[body][1][1];
        dircos[1][2] = cnb[body][1][2];
        dircos[2][0] = cnb[body][2][0];
        dircos[2][1] = cnb[body][2][1];
        dircos[2][2] = cnb[body][2][2];
    }
}

void sdangvel(int body,
    double avel[3])
{
/*
Return angular velocity of the body.

*/

    if (sdchkbnum(24,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(24,23);
        return;
    }
    if (body == -1) {
        avel[0] = 0.;
        avel[1] = 0.;
        avel[2] = 0.;
    } else {
        avel[0] = wb[body][0];
        avel[1] = wb[body][1];
        avel[2] = wb[body][2];
    }
}

void sdtrans(int frbod,
    double ivec[3],
    int tobod,
    double ovec[3])
{
/*
Transform ivec from frbod frame to tobod frame.

*/
    double pv[3];

    if (sdchkbnum(25,frbod) != 0) {
        return;
    }
    if (sdchkbnum(25,tobod) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(25,23);
        return;
    }
    if (frbod == tobod) {
        sdvcopy(ivec,ovec);
        return;
    }
    if (frbod == -1) {
        sdvcopy(ivec,pv);
        ovec[0] = pv[0]*cnb[tobod][0][0]+pv[1]*cnb[tobod][1][0]+pv[2]*cnb[tobod
          ][2][0];
        ovec[1] = pv[0]*cnb[tobod][0][1]+pv[1]*cnb[tobod][1][1]+pv[2]*cnb[tobod
          ][2][1];
        ovec[2] = pv[0]*cnb[tobod][0][2]+pv[1]*cnb[tobod][1][2]+pv[2]*cnb[tobod
          ][2][2];
        return;
    }
    if (tobod == -1) {
        sdvcopy(ivec,pv);
        ovec[0] = pv[0]*cnb[frbod][0][0]+pv[1]*cnb[frbod][0][1]+pv[2]*cnb[frbod
          ][0][2];
        ovec[1] = pv[0]*cnb[frbod][1][0]+pv[1]*cnb[frbod][1][1]+pv[2]*cnb[frbod
          ][1][2];
        ovec[2] = pv[0]*cnb[frbod][2][0]+pv[1]*cnb[frbod][2][1]+pv[2]*cnb[frbod
          ][2][2];
        return;
    }
    pv[0] = ivec[0]*cnb[frbod][0][0]+ivec[1]*cnb[frbod][0][1]+ivec[2]*cnb[frbod
      ][0][2];
    pv[1] = ivec[0]*cnb[frbod][1][0]+ivec[1]*cnb[frbod][1][1]+ivec[2]*cnb[frbod
      ][1][2];
    pv[2] = ivec[0]*cnb[frbod][2][0]+ivec[1]*cnb[frbod][2][1]+ivec[2]*cnb[frbod
      ][2][2];
    ovec[0] = pv[0]*cnb[tobod][0][0]+pv[1]*cnb[tobod][1][0]+pv[2]*cnb[tobod][2][
      0];
    ovec[1] = pv[0]*cnb[tobod][0][1]+pv[1]*cnb[tobod][1][1]+pv[2]*cnb[tobod][2][
      1];
    ovec[2] = pv[0]*cnb[tobod][0][2]+pv[1]*cnb[tobod][1][2]+pv[2]*cnb[tobod][2][
      2];
}

void sdrel2cart(int coord,
    int body,
    double point[3],
    double linchg[3],
    double rotchg[3])
{
/* Return derivative of pt loc and body orient w.r.t. hinge rate
*/
    int x,i,gnd;
    double lin[3],pv[3];

    if ((coord < 0) || (coord > 17)) {
        sdseterr(59,45);
        return;
    }
    if (sdchkbnum(59,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(59,23);
        return;
    }
    gnd = -1;
    if (body == gnd) {
        x = -1;
    } else {
        x = firstq[body]+njntdof[body]-1;
    }
    if (x < coord) {
        sdvset(0.,0.,0.,linchg);
        sdvset(0.,0.,0.,rotchg);
        return;
    }
    sddovpk();
    for (i = 0; i < 3; i++) {
        rotchg[i] = Wpk[coord][x][i];
        lin[i] = Vpk[coord][x][i];
    }
    if (body == gnd) {
        sdvcopy(point,pv);
    } else {
        pv[0] = rcom[body][0]+point[0];
        pv[1] = rcom[body][1]+point[1];
        pv[2] = rcom[body][2]+point[2];
    }
    sdvcross(rotchg,pv,linchg);
    sdvadd(linchg,lin,linchg);
}

void sdacc(int body,
    double pt[3],
    double accel[3])
{
/*
Return linear acceleration a point of the specified body.

*/
    double pv[3];

    if (sdchkbnum(32,body) != 0) {
        return;
    }
    if (roustate != 3) {
        sdseterr(32,24);
        return;
    }
    if (body  ==  -1) {
        accel[0] = 0.;
        accel[1] = 0.;
        accel[2] = 0.;
    } else {
        pv[0] = pt[0]*dyad[body][0][0]+pt[1]*dyad[body][0][1]+pt[2]*dyad[body][0
          ][2];
        pv[1] = pt[0]*dyad[body][1][0]+pt[1]*dyad[body][1][1]+pt[2]*dyad[body][1
          ][2];
        pv[2] = pt[0]*dyad[body][2][0]+pt[1]*dyad[body][2][1]+pt[2]*dyad[body][2
          ][2];
        accel[0] = anb[body][0]+pv[0]*cnb[body][0][0]+pv[1]*cnb[body][0][1]+pv[2
          ]*cnb[body][0][2];
        accel[1] = anb[body][1]+pv[0]*cnb[body][1][0]+pv[1]*cnb[body][1][1]+pv[2
          ]*cnb[body][1][2];
        accel[2] = anb[body][2]+pv[0]*cnb[body][2][0]+pv[1]*cnb[body][2][1]+pv[2
          ]*cnb[body][2][2];
    }
}

void sdangacc(int body,
    double aacc[3])
{
/*
Return angular acceleration of the body.

*/

    if (sdchkbnum(33,body) != 0) {
        return;
    }
    if (roustate != 3) {
        sdseterr(33,24);
        return;
    }
    if (body == -1) {
        aacc[0] = 0.;
        aacc[1] = 0.;
        aacc[2] = 0.;
    } else {
        aacc[0] = onb[body][0];
        aacc[1] = onb[body][1];
        aacc[2] = onb[body][2];
    }
}

void sdgrav(double gravin[3])
{

    grav[0] = gravin[0];
    gravq[0] = 3;
    grav[1] = gravin[1];
    gravq[1] = 3;
    grav[2] = gravin[2];
    gravq[2] = 3;
    roustate = 0;
}

void sdmass(int body,
    double massin)
{

    if (sdchkbnum(2,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(2,15);
        return;
    }
    if (mkq[body] != 0) {
        mk[body] = massin;
        mkq[body] = 3;
    } else {
        sdseterr(2,19);
    }
    roustate = 0;
}

void sdiner(int body,
    double inerin[3][3])
{
    int anyques;

    if (sdchkbnum(3,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(3,15);
        return;
    }
    anyques = 0;
    if (ikq[body][0][0]  !=  0) {
        ik[body][0][0] = inerin[0][0];
        ikq[body][0][0] = 3;
        anyques = 1;
    }
    if (ikq[body][0][1]  !=  0) {
        ik[body][0][1] = inerin[0][1];
        ikq[body][0][1] = 3;
        ik[body][1][0] = inerin[0][1];
        ikq[body][1][0] = 3;
        anyques = 1;
    }
    if (ikq[body][0][2]  !=  0) {
        ik[body][0][2] = inerin[0][2];
        ikq[body][0][2] = 3;
        ik[body][2][0] = inerin[0][2];
        ikq[body][2][0] = 3;
        anyques = 1;
    }
    if (ikq[body][1][1]  !=  0) {
        ik[body][1][1] = inerin[1][1];
        ikq[body][1][1] = 3;
        anyques = 1;
    }
    if (ikq[body][1][2]  !=  0) {
        ik[body][1][2] = inerin[1][2];
        ikq[body][1][2] = 3;
        ik[body][2][1] = inerin[1][2];
        ikq[body][2][1] = 3;
        anyques = 1;
    }
    if (ikq[body][2][2]  !=  0) {
        ik[body][2][2] = inerin[2][2];
        ikq[body][2][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(3,19);
    }
    roustate = 0;
}

void sdbtj(int joint,
    double btjin[3])
{
    int anyques;

    if (sdchkjnum(4,joint) != 0) {
        return;
    }
    anyques = 0;
    if (rkq[joint][0]  !=  0) {
        rk[joint][0] = btjin[0];
        rkq[joint][0] = 3;
        anyques = 1;
    }
    if (rkq[joint][1]  !=  0) {
        rk[joint][1] = btjin[1];
        rkq[joint][1] = 3;
        anyques = 1;
    }
    if (rkq[joint][2]  !=  0) {
        rk[joint][2] = btjin[2];
        rkq[joint][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(4,19);
    }
    roustate = 0;
}

void sditj(int joint,
    double itjin[3])
{
    int anyques;

    if (sdchkjnum(5,joint) != 0) {
        return;
    }
    anyques = 0;
    if (riq[joint][0]  !=  0) {
        ri[joint][0] = itjin[0];
        riq[joint][0] = 3;
        anyques = 1;
    }
    if (riq[joint][1]  !=  0) {
        ri[joint][1] = itjin[1];
        riq[joint][1] = 3;
        anyques = 1;
    }
    if (riq[joint][2]  !=  0) {
        ri[joint][2] = itjin[2];
        riq[joint][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(5,19);
    }
    roustate = 0;
}

void sdpin(int joint,
    int pinno,
    double pinin[3])
{
    int anyques,offs;

    if (sdchkjpin(6,joint,pinno) != 0) {
        return;
    }
    anyques = 0;
    offs = firstq[joint]+pinno;
    if (jtype[joint] == 21) {
        offs = offs+3;
    }
    if (jtype[joint] == 11) {
        offs = offs+1;
    }
    if (pinq[offs][0]  !=  0) {
        pin[offs][0] = pinin[0];
        pinq[offs][0] = 3;
        anyques = 1;
    }
    if (pinq[offs][1]  !=  0) {
        pin[offs][1] = pinin[1];
        pinq[offs][1] = 3;
        anyques = 1;
    }
    if (pinq[offs][2]  !=  0) {
        pin[offs][2] = pinin[2];
        pinq[offs][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(6,19);
    }
    roustate = 0;
}

void sdpres(int joint,
    int axis,
    int presin)
{
    int anyques;

    if (sdchkjaxis(37,joint,axis) != 0) {
        return;
    }
    if ((presin != 0) && (presin != 1)) {
        sdseterr(37,20);
    }
    anyques = 0;
    if (presq[sdindx(joint,axis)]  !=  0) {
        if (presin  !=  0) {
            pres[sdindx(joint,axis)] = 1.;
        } else {
            pres[sdindx(joint,axis)] = 0.;
        }
        presq[sdindx(joint,axis)] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(37,19);
    }
    wwflg = 0;
}

void sdconschg(void)
{

    wwflg = 0;
}

void sdstab(double velin,
    double posin)
{

    stabvel = velin;
    stabvelq = 3;
    stabpos = posin;
    stabposq = 3;
}

void sdgetgrav(double gravout[3])
{

    gravout[0] = grav[0];
    gravout[1] = grav[1];
    gravout[2] = grav[2];
}

void sdgetmass(int body,
    double *massout)
{

    if (sdchkbnum(40,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(40,15);
        return;
    }
    *massout = mk[body];
}

void sdgetiner(int body,
    double inerout[3][3])
{

    if (sdchkbnum(41,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(41,15);
        return;
    }
    inerout[0][0] = ik[body][0][0];
    inerout[0][1] = ik[body][0][1];
    inerout[0][2] = ik[body][0][2];
    inerout[1][0] = ik[body][1][0];
    inerout[1][1] = ik[body][1][1];
    inerout[1][2] = ik[body][1][2];
    inerout[2][0] = ik[body][2][0];
    inerout[2][1] = ik[body][2][1];
    inerout[2][2] = ik[body][2][2];
}

void sdgetbtj(int joint,
    double btjout[3])
{

    if (sdchkjnum(42,joint) != 0) {
        return;
    }
    btjout[0] = rk[joint][0];
    btjout[1] = rk[joint][1];
    btjout[2] = rk[joint][2];
}

void sdgetitj(int joint,
    double itjout[3])
{

    if (sdchkjnum(43,joint) != 0) {
        return;
    }
    itjout[0] = ri[joint][0];
    itjout[1] = ri[joint][1];
    itjout[2] = ri[joint][2];
}

void sdgetpin(int joint,
    int pinno,
    double pinout[3])
{
    int offs;

    if (sdchkjpin(44,joint,pinno) != 0) {
        return;
    }
    offs = firstq[joint]+pinno;
    if (jtype[joint] == 21) {
        offs = offs+3;
    }
    if (jtype[joint] == 11) {
        offs = offs+1;
    }
    pinout[0] = pin[offs][0];
    pinout[1] = pin[offs][1];
    pinout[2] = pin[offs][2];
}

void sdgetpres(int joint,
    int axis,
    int *presout)
{

    if (sdchkjaxis(45,joint,axis) != 0) {
        return;
    }
    if (pres[sdindx(joint,axis)]  !=  0.) {
        *presout = 1;
    } else {
        *presout = 0;
    }
}

void sdgetstab(double *velout,
    double *posout)
{

    *velout = stabvel;
    *posout = stabpos;
}

void sdinfo(int info[50])
{

    info[0] = ground;
    info[1] = nbod;
    info[2] = ndof;
    info[3] = ncons;
    info[4] = nloop;
    info[5] = nldof;
    info[6] = nloopc;
    info[7] = nball;
    info[8] = nlball;
    info[9] = npres;
    info[10] = nuser;
    info[11] = 0;
/* info entries from 12-49 are reserved */
}

void sdjnt(int joint,
    int info[50],
    int tran[6])
{
    int i,offs;

    if (sdchkjnum(48,joint) != 0) {
        return;
    }
    info[0] = jtype[joint];
    info[1] = 0;
    offs = 0;
    info[2] = inb[joint];
    info[3] = outb[joint];
    info[4] = njntdof[joint];
    info[5] = njntc[joint];
    info[6] = njntp[joint];
    info[7] = firstq[joint];
    info[8] = ballq[joint];
    info[9] = firstm[joint];
    info[10] = firstp[joint];
/* info entries from 11-49 are reserved */

    for (i = 0; i <= 5; i++) {
        if (i  <  njntdof[joint]) {
            tran[i] = trans[offs+firstq[joint]+i];
        } else {
            tran[i] = -1;
        }
    }
}

void sdcons(int consno,
    int info[50])
{

    if (sdchkucnum(49,consno) != 0) {
        return;
    }
/* There are no user constraints in this problem. */
}

void sdgentime(int *gentm)
{

    *gentm = 131321;
}
/*
Done. CPU seconds used: 0.08  Memory used: 1703936 bytes.
Equation complexity:
  sdstate:  1532 adds  2074 multiplies     4 divides  1154 assignments
  sdderiv:  6447 adds  7702 multiplies    18 divides  4189 assignments
  sdresid:  3163 adds  3465 multiplies     0 divides  1409 assignments
  sdreac:    684 adds   552 multiplies     0 divides   339 assignments
  sdmom:     389 adds   436 multiplies     0 divides   106 assignments
  sdsys:     588 adds   795 multiplies     0 divides   160 assignments
*/
