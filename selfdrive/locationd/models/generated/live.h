#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_2777757199287464545);
void live_err_fun(double *nom_x, double *delta_x, double *out_5367815787538398854);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_5584533176148752683);
void live_H_mod_fun(double *state, double *out_4329246194809616632);
void live_f_fun(double *state, double dt, double *out_5992521947480762617);
void live_F_fun(double *state, double dt, double *out_4649644131871762932);
void live_h_4(double *state, double *unused, double *out_6124528919913981966);
void live_H_4(double *state, double *unused, double *out_7267858052716951485);
void live_h_9(double *state, double *unused, double *out_2464761248593869412);
void live_H_9(double *state, double *unused, double *out_3891667085728152661);
void live_h_10(double *state, double *unused, double *out_7625164934370633875);
void live_H_10(double *state, double *unused, double *out_4274723642592768505);
void live_h_12(double *state, double *unused, double *out_3240055958119241978);
void live_H_12(double *state, double *unused, double *out_886599675674218489);
void live_h_35(double *state, double *unused, double *out_6730900078470589679);
void live_H_35(double *state, double *unused, double *out_3413866580635624627);
void live_h_32(double *state, double *unused, double *out_1851695392969102110);
void live_H_32(double *state, double *unused, double *out_708842067733874690);
void live_h_13(double *state, double *unused, double *out_1589135582029383415);
void live_H_13(double *state, double *unused, double *out_3334532719869429421);
void live_h_14(double *state, double *unused, double *out_2464761248593869412);
void live_H_14(double *state, double *unused, double *out_3891667085728152661);
void live_h_33(double *state, double *unused, double *out_4825231622042140479);
void live_H_33(double *state, double *unused, double *out_6782719712638089802);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}