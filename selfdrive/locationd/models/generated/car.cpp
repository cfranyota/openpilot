#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3335309639026812248) {
   out_3335309639026812248[0] = delta_x[0] + nom_x[0];
   out_3335309639026812248[1] = delta_x[1] + nom_x[1];
   out_3335309639026812248[2] = delta_x[2] + nom_x[2];
   out_3335309639026812248[3] = delta_x[3] + nom_x[3];
   out_3335309639026812248[4] = delta_x[4] + nom_x[4];
   out_3335309639026812248[5] = delta_x[5] + nom_x[5];
   out_3335309639026812248[6] = delta_x[6] + nom_x[6];
   out_3335309639026812248[7] = delta_x[7] + nom_x[7];
   out_3335309639026812248[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4612421392779340364) {
   out_4612421392779340364[0] = -nom_x[0] + true_x[0];
   out_4612421392779340364[1] = -nom_x[1] + true_x[1];
   out_4612421392779340364[2] = -nom_x[2] + true_x[2];
   out_4612421392779340364[3] = -nom_x[3] + true_x[3];
   out_4612421392779340364[4] = -nom_x[4] + true_x[4];
   out_4612421392779340364[5] = -nom_x[5] + true_x[5];
   out_4612421392779340364[6] = -nom_x[6] + true_x[6];
   out_4612421392779340364[7] = -nom_x[7] + true_x[7];
   out_4612421392779340364[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_788104945221143856) {
   out_788104945221143856[0] = 1.0;
   out_788104945221143856[1] = 0;
   out_788104945221143856[2] = 0;
   out_788104945221143856[3] = 0;
   out_788104945221143856[4] = 0;
   out_788104945221143856[5] = 0;
   out_788104945221143856[6] = 0;
   out_788104945221143856[7] = 0;
   out_788104945221143856[8] = 0;
   out_788104945221143856[9] = 0;
   out_788104945221143856[10] = 1.0;
   out_788104945221143856[11] = 0;
   out_788104945221143856[12] = 0;
   out_788104945221143856[13] = 0;
   out_788104945221143856[14] = 0;
   out_788104945221143856[15] = 0;
   out_788104945221143856[16] = 0;
   out_788104945221143856[17] = 0;
   out_788104945221143856[18] = 0;
   out_788104945221143856[19] = 0;
   out_788104945221143856[20] = 1.0;
   out_788104945221143856[21] = 0;
   out_788104945221143856[22] = 0;
   out_788104945221143856[23] = 0;
   out_788104945221143856[24] = 0;
   out_788104945221143856[25] = 0;
   out_788104945221143856[26] = 0;
   out_788104945221143856[27] = 0;
   out_788104945221143856[28] = 0;
   out_788104945221143856[29] = 0;
   out_788104945221143856[30] = 1.0;
   out_788104945221143856[31] = 0;
   out_788104945221143856[32] = 0;
   out_788104945221143856[33] = 0;
   out_788104945221143856[34] = 0;
   out_788104945221143856[35] = 0;
   out_788104945221143856[36] = 0;
   out_788104945221143856[37] = 0;
   out_788104945221143856[38] = 0;
   out_788104945221143856[39] = 0;
   out_788104945221143856[40] = 1.0;
   out_788104945221143856[41] = 0;
   out_788104945221143856[42] = 0;
   out_788104945221143856[43] = 0;
   out_788104945221143856[44] = 0;
   out_788104945221143856[45] = 0;
   out_788104945221143856[46] = 0;
   out_788104945221143856[47] = 0;
   out_788104945221143856[48] = 0;
   out_788104945221143856[49] = 0;
   out_788104945221143856[50] = 1.0;
   out_788104945221143856[51] = 0;
   out_788104945221143856[52] = 0;
   out_788104945221143856[53] = 0;
   out_788104945221143856[54] = 0;
   out_788104945221143856[55] = 0;
   out_788104945221143856[56] = 0;
   out_788104945221143856[57] = 0;
   out_788104945221143856[58] = 0;
   out_788104945221143856[59] = 0;
   out_788104945221143856[60] = 1.0;
   out_788104945221143856[61] = 0;
   out_788104945221143856[62] = 0;
   out_788104945221143856[63] = 0;
   out_788104945221143856[64] = 0;
   out_788104945221143856[65] = 0;
   out_788104945221143856[66] = 0;
   out_788104945221143856[67] = 0;
   out_788104945221143856[68] = 0;
   out_788104945221143856[69] = 0;
   out_788104945221143856[70] = 1.0;
   out_788104945221143856[71] = 0;
   out_788104945221143856[72] = 0;
   out_788104945221143856[73] = 0;
   out_788104945221143856[74] = 0;
   out_788104945221143856[75] = 0;
   out_788104945221143856[76] = 0;
   out_788104945221143856[77] = 0;
   out_788104945221143856[78] = 0;
   out_788104945221143856[79] = 0;
   out_788104945221143856[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5669767093813339343) {
   out_5669767093813339343[0] = state[0];
   out_5669767093813339343[1] = state[1];
   out_5669767093813339343[2] = state[2];
   out_5669767093813339343[3] = state[3];
   out_5669767093813339343[4] = state[4];
   out_5669767093813339343[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5669767093813339343[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5669767093813339343[7] = state[7];
   out_5669767093813339343[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3427546550500955444) {
   out_3427546550500955444[0] = 1;
   out_3427546550500955444[1] = 0;
   out_3427546550500955444[2] = 0;
   out_3427546550500955444[3] = 0;
   out_3427546550500955444[4] = 0;
   out_3427546550500955444[5] = 0;
   out_3427546550500955444[6] = 0;
   out_3427546550500955444[7] = 0;
   out_3427546550500955444[8] = 0;
   out_3427546550500955444[9] = 0;
   out_3427546550500955444[10] = 1;
   out_3427546550500955444[11] = 0;
   out_3427546550500955444[12] = 0;
   out_3427546550500955444[13] = 0;
   out_3427546550500955444[14] = 0;
   out_3427546550500955444[15] = 0;
   out_3427546550500955444[16] = 0;
   out_3427546550500955444[17] = 0;
   out_3427546550500955444[18] = 0;
   out_3427546550500955444[19] = 0;
   out_3427546550500955444[20] = 1;
   out_3427546550500955444[21] = 0;
   out_3427546550500955444[22] = 0;
   out_3427546550500955444[23] = 0;
   out_3427546550500955444[24] = 0;
   out_3427546550500955444[25] = 0;
   out_3427546550500955444[26] = 0;
   out_3427546550500955444[27] = 0;
   out_3427546550500955444[28] = 0;
   out_3427546550500955444[29] = 0;
   out_3427546550500955444[30] = 1;
   out_3427546550500955444[31] = 0;
   out_3427546550500955444[32] = 0;
   out_3427546550500955444[33] = 0;
   out_3427546550500955444[34] = 0;
   out_3427546550500955444[35] = 0;
   out_3427546550500955444[36] = 0;
   out_3427546550500955444[37] = 0;
   out_3427546550500955444[38] = 0;
   out_3427546550500955444[39] = 0;
   out_3427546550500955444[40] = 1;
   out_3427546550500955444[41] = 0;
   out_3427546550500955444[42] = 0;
   out_3427546550500955444[43] = 0;
   out_3427546550500955444[44] = 0;
   out_3427546550500955444[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3427546550500955444[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3427546550500955444[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3427546550500955444[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3427546550500955444[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3427546550500955444[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3427546550500955444[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3427546550500955444[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3427546550500955444[53] = -9.8000000000000007*dt;
   out_3427546550500955444[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3427546550500955444[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3427546550500955444[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3427546550500955444[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3427546550500955444[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3427546550500955444[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3427546550500955444[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3427546550500955444[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3427546550500955444[62] = 0;
   out_3427546550500955444[63] = 0;
   out_3427546550500955444[64] = 0;
   out_3427546550500955444[65] = 0;
   out_3427546550500955444[66] = 0;
   out_3427546550500955444[67] = 0;
   out_3427546550500955444[68] = 0;
   out_3427546550500955444[69] = 0;
   out_3427546550500955444[70] = 1;
   out_3427546550500955444[71] = 0;
   out_3427546550500955444[72] = 0;
   out_3427546550500955444[73] = 0;
   out_3427546550500955444[74] = 0;
   out_3427546550500955444[75] = 0;
   out_3427546550500955444[76] = 0;
   out_3427546550500955444[77] = 0;
   out_3427546550500955444[78] = 0;
   out_3427546550500955444[79] = 0;
   out_3427546550500955444[80] = 1;
}
void h_25(double *state, double *unused, double *out_5256817848986689824) {
   out_5256817848986689824[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1444888812377779496) {
   out_1444888812377779496[0] = 0;
   out_1444888812377779496[1] = 0;
   out_1444888812377779496[2] = 0;
   out_1444888812377779496[3] = 0;
   out_1444888812377779496[4] = 0;
   out_1444888812377779496[5] = 0;
   out_1444888812377779496[6] = 1;
   out_1444888812377779496[7] = 0;
   out_1444888812377779496[8] = 0;
}
void h_24(double *state, double *unused, double *out_6218402356070309809) {
   out_6218402356070309809[0] = state[4];
   out_6218402356070309809[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3132705248246883687) {
   out_3132705248246883687[0] = 0;
   out_3132705248246883687[1] = 0;
   out_3132705248246883687[2] = 0;
   out_3132705248246883687[3] = 0;
   out_3132705248246883687[4] = 1;
   out_3132705248246883687[5] = 0;
   out_3132705248246883687[6] = 0;
   out_3132705248246883687[7] = 0;
   out_3132705248246883687[8] = 0;
   out_3132705248246883687[9] = 0;
   out_3132705248246883687[10] = 0;
   out_3132705248246883687[11] = 0;
   out_3132705248246883687[12] = 0;
   out_3132705248246883687[13] = 0;
   out_3132705248246883687[14] = 1;
   out_3132705248246883687[15] = 0;
   out_3132705248246883687[16] = 0;
   out_3132705248246883687[17] = 0;
}
void h_30(double *state, double *unused, double *out_5323865128810039981) {
   out_5323865128810039981[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3963221770885028123) {
   out_3963221770885028123[0] = 0;
   out_3963221770885028123[1] = 0;
   out_3963221770885028123[2] = 0;
   out_3963221770885028123[3] = 0;
   out_3963221770885028123[4] = 1;
   out_3963221770885028123[5] = 0;
   out_3963221770885028123[6] = 0;
   out_3963221770885028123[7] = 0;
   out_3963221770885028123[8] = 0;
}
void h_26(double *state, double *unused, double *out_97957912974715034) {
   out_97957912974715034[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2296614506496276728) {
   out_2296614506496276728[0] = 0;
   out_2296614506496276728[1] = 0;
   out_2296614506496276728[2] = 0;
   out_2296614506496276728[3] = 0;
   out_2296614506496276728[4] = 0;
   out_2296614506496276728[5] = 0;
   out_2296614506496276728[6] = 0;
   out_2296614506496276728[7] = 1;
   out_2296614506496276728[8] = 0;
}
void h_27(double *state, double *unused, double *out_8266725501459320961) {
   out_8266725501459320961[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6186815842068971340) {
   out_6186815842068971340[0] = 0;
   out_6186815842068971340[1] = 0;
   out_6186815842068971340[2] = 0;
   out_6186815842068971340[3] = 1;
   out_6186815842068971340[4] = 0;
   out_6186815842068971340[5] = 0;
   out_6186815842068971340[6] = 0;
   out_6186815842068971340[7] = 0;
   out_6186815842068971340[8] = 0;
}
void h_29(double *state, double *unused, double *out_4326569480633514495) {
   out_4326569480633514495[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4473453115199420307) {
   out_4473453115199420307[0] = 0;
   out_4473453115199420307[1] = 1;
   out_4473453115199420307[2] = 0;
   out_4473453115199420307[3] = 0;
   out_4473453115199420307[4] = 0;
   out_4473453115199420307[5] = 0;
   out_4473453115199420307[6] = 0;
   out_4473453115199420307[7] = 0;
   out_4473453115199420307[8] = 0;
}
void h_28(double *state, double *unused, double *out_3265052233798475316) {
   out_3265052233798475316[0] = state[0];
}
void H_28(double *state, double *unused, double *out_608945901870110267) {
   out_608945901870110267[0] = 1;
   out_608945901870110267[1] = 0;
   out_608945901870110267[2] = 0;
   out_608945901870110267[3] = 0;
   out_608945901870110267[4] = 0;
   out_608945901870110267[5] = 0;
   out_608945901870110267[6] = 0;
   out_608945901870110267[7] = 0;
   out_608945901870110267[8] = 0;
}
void h_31(double *state, double *unused, double *out_1106776129315126037) {
   out_1106776129315126037[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1475534774254739924) {
   out_1475534774254739924[0] = 0;
   out_1475534774254739924[1] = 0;
   out_1475534774254739924[2] = 0;
   out_1475534774254739924[3] = 0;
   out_1475534774254739924[4] = 0;
   out_1475534774254739924[5] = 0;
   out_1475534774254739924[6] = 0;
   out_1475534774254739924[7] = 0;
   out_1475534774254739924[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_3335309639026812248) {
  err_fun(nom_x, delta_x, out_3335309639026812248);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4612421392779340364) {
  inv_err_fun(nom_x, true_x, out_4612421392779340364);
}
void car_H_mod_fun(double *state, double *out_788104945221143856) {
  H_mod_fun(state, out_788104945221143856);
}
void car_f_fun(double *state, double dt, double *out_5669767093813339343) {
  f_fun(state,  dt, out_5669767093813339343);
}
void car_F_fun(double *state, double dt, double *out_3427546550500955444) {
  F_fun(state,  dt, out_3427546550500955444);
}
void car_h_25(double *state, double *unused, double *out_5256817848986689824) {
  h_25(state, unused, out_5256817848986689824);
}
void car_H_25(double *state, double *unused, double *out_1444888812377779496) {
  H_25(state, unused, out_1444888812377779496);
}
void car_h_24(double *state, double *unused, double *out_6218402356070309809) {
  h_24(state, unused, out_6218402356070309809);
}
void car_H_24(double *state, double *unused, double *out_3132705248246883687) {
  H_24(state, unused, out_3132705248246883687);
}
void car_h_30(double *state, double *unused, double *out_5323865128810039981) {
  h_30(state, unused, out_5323865128810039981);
}
void car_H_30(double *state, double *unused, double *out_3963221770885028123) {
  H_30(state, unused, out_3963221770885028123);
}
void car_h_26(double *state, double *unused, double *out_97957912974715034) {
  h_26(state, unused, out_97957912974715034);
}
void car_H_26(double *state, double *unused, double *out_2296614506496276728) {
  H_26(state, unused, out_2296614506496276728);
}
void car_h_27(double *state, double *unused, double *out_8266725501459320961) {
  h_27(state, unused, out_8266725501459320961);
}
void car_H_27(double *state, double *unused, double *out_6186815842068971340) {
  H_27(state, unused, out_6186815842068971340);
}
void car_h_29(double *state, double *unused, double *out_4326569480633514495) {
  h_29(state, unused, out_4326569480633514495);
}
void car_H_29(double *state, double *unused, double *out_4473453115199420307) {
  H_29(state, unused, out_4473453115199420307);
}
void car_h_28(double *state, double *unused, double *out_3265052233798475316) {
  h_28(state, unused, out_3265052233798475316);
}
void car_H_28(double *state, double *unused, double *out_608945901870110267) {
  H_28(state, unused, out_608945901870110267);
}
void car_h_31(double *state, double *unused, double *out_1106776129315126037) {
  h_31(state, unused, out_1106776129315126037);
}
void car_H_31(double *state, double *unused, double *out_1475534774254739924) {
  H_31(state, unused, out_1475534774254739924);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
