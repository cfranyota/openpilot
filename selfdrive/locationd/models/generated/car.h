#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3335309639026812248);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4612421392779340364);
void car_H_mod_fun(double *state, double *out_788104945221143856);
void car_f_fun(double *state, double dt, double *out_5669767093813339343);
void car_F_fun(double *state, double dt, double *out_3427546550500955444);
void car_h_25(double *state, double *unused, double *out_5256817848986689824);
void car_H_25(double *state, double *unused, double *out_1444888812377779496);
void car_h_24(double *state, double *unused, double *out_6218402356070309809);
void car_H_24(double *state, double *unused, double *out_3132705248246883687);
void car_h_30(double *state, double *unused, double *out_5323865128810039981);
void car_H_30(double *state, double *unused, double *out_3963221770885028123);
void car_h_26(double *state, double *unused, double *out_97957912974715034);
void car_H_26(double *state, double *unused, double *out_2296614506496276728);
void car_h_27(double *state, double *unused, double *out_8266725501459320961);
void car_H_27(double *state, double *unused, double *out_6186815842068971340);
void car_h_29(double *state, double *unused, double *out_4326569480633514495);
void car_H_29(double *state, double *unused, double *out_4473453115199420307);
void car_h_28(double *state, double *unused, double *out_3265052233798475316);
void car_H_28(double *state, double *unused, double *out_608945901870110267);
void car_h_31(double *state, double *unused, double *out_1106776129315126037);
void car_H_31(double *state, double *unused, double *out_1475534774254739924);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}