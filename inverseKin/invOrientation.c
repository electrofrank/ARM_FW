/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * invOrientation.c
 *
 * Code generation for function 'invOrientation'
 *
 */

/* Include files */
#include "invOrientation.h"
#include "inverseKinematics.h"
#include "positionCartesian.h"
#include "wristPositionOrientation.h"
#include <math.h>

/* Function Definitions */
void invOrientation(const double R_in[9], double q1, double q2, double q3,
                    double qOri[3])
{
  double r11_tmp;
  double r11_tmp_tmp;
  double b_r11_tmp;
  double r12_tmp;
  double c_r11_tmp[9];
  int i;
  double R3_6[9];
  int i1;

  /*  R_in is the required orientation of the end-effector */
  /*  q1, q2 and q3 are the computed joint variables determining the position */
  /*  This function computes the joint variables of the spherical wrist, given */
  /*  the end effector's desired orientation and the computed position joint */
  /*  variables based on the end-effector's desired position. */
  /*  Define R^0_3 elements */
  /*  This is done on individual lines just for clarity and ease of access */
  r11_tmp = cos(q1);
  r11_tmp_tmp = q2 + q3;
  b_r11_tmp = cos(r11_tmp_tmp);
  r12_tmp = sin(r11_tmp_tmp);
  r11_tmp_tmp = sin(q1);

  /*  Compute R^3_6 */
  c_r11_tmp[0] = r11_tmp * b_r11_tmp;
  c_r11_tmp[1] = -r11_tmp * r12_tmp;
  c_r11_tmp[2] = r11_tmp_tmp;
  c_r11_tmp[3] = r11_tmp_tmp * b_r11_tmp;
  c_r11_tmp[4] = -r11_tmp_tmp * r12_tmp;
  c_r11_tmp[5] = -cos(q1);
  c_r11_tmp[6] = r12_tmp;
  c_r11_tmp[7] = b_r11_tmp;
  c_r11_tmp[8] = 0.0;
  for (i = 0; i < 3; i++) {
    r11_tmp_tmp = c_r11_tmp[i + 3];
    r12_tmp = c_r11_tmp[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      R3_6[i + 3 * i1] = (c_r11_tmp[i] * R_in[3 * i1] + r11_tmp_tmp * R_in[3 *
                          i1 + 1]) + r12_tmp * R_in[3 * i1 + 2];
    }
  }

  /*  Compute wrist angles */
  qOri[0] = atan2(-R3_6[7], -R3_6[6]);
  qOri[1] = atan2(-sqrt(R3_6[6] * R3_6[6] + R3_6[7] * R3_6[7]), R3_6[8]);
  qOri[2] = atan2(-R3_6[5], R3_6[2]);
}

/* End of code generation (invOrientation.c) */
