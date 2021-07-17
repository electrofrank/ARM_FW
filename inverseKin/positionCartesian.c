/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * positionCartesian.c
 *
 * Code generation for function 'positionCartesian'
 *
 */

/* Include files */
#include "positionCartesian.h"
#include "invOrientation.h"
#include "inverseKinematics.h"
#include "wristPositionOrientation.h"
#include <math.h>

/* Function Definitions */
void positionCartesian(double L1, double L2, const double wrist[3], double
  angles[12])
{
  double c3_tmp;
  double c3;
  double x;
  double q3_idx_0;
  double q3_idx_1;
  double q1_idx_0;
  double q1_idx_1;
  double angles_tmp;
  double b_angles_tmp;
  double c_angles_tmp;
  double d_angles_tmp;
  double e_angles_tmp;
  double f_angles_tmp;

  /*  This function calculates angles of the first three joints given the */
  /*  position of the wrist */
  /*  Initializing variables */
  /*  Computing joint angles (keeping singularities) */
  /*  Calculate q3  */
  c3_tmp = wrist[0] * wrist[0] + wrist[1] * wrist[1];
  c3 = (((c3_tmp + wrist[2] * wrist[2]) - L1 * L1) - L2 * L2) / (2.0 * L1 * L2);
  x = sqrt(1.0 - c3 * c3);

  /*  s3 plus   */
  /*  s3 minus  */
  q3_idx_0 = atan2(x, c3);
  q3_idx_1 = atan2(-x, c3);

  /*  Calculate q2 corresponding to s3(1) (s3 plus) */
  /*  Calculate q2 corresponding to s3(2) (s3 minus) */
  /*  Calculate q1  */
  /*  if x=0 and y=0, then there are infinite number of solutions for q1, */
  /*  because it is possible to obtain joints q2 and q3 independently of  */
  /*  q1. */
  if ((wrist[1] == 0.0) && (wrist[0] == 0.0)) {
    q1_idx_0 = 0.0;
    q1_idx_1 = 3.1415926535897931;
  } else {
    q1_idx_0 = atan2(wrist[1], wrist[0]);
    q1_idx_1 = atan2(-wrist[1], -wrist[0]);
  }

  /*  Calculated joint angles */
  /*  There are 4 possible combinations. */
  angles[0] = q1_idx_0;
  angles_tmp = L1 + L2 * c3;
  b_angles_tmp = sqrt(c3_tmp);
  c_angles_tmp = L2 * x;
  d_angles_tmp = angles_tmp * wrist[2];
  e_angles_tmp = angles_tmp * b_angles_tmp;
  f_angles_tmp = c_angles_tmp * b_angles_tmp;
  c_angles_tmp *= wrist[2];
  angles[4] = atan2(d_angles_tmp - f_angles_tmp, e_angles_tmp + c_angles_tmp);
  angles[8] = q3_idx_0;
  angles[1] = q1_idx_0;
  c3 = L2 * -x;
  c3_tmp = c3 * b_angles_tmp;
  c3 *= wrist[2];
  angles[5] = atan2(d_angles_tmp - c3_tmp, e_angles_tmp + c3);
  angles[9] = q3_idx_1;
  angles[2] = q1_idx_1;
  angles_tmp = -angles_tmp * b_angles_tmp;
  angles[6] = atan2(d_angles_tmp + f_angles_tmp, angles_tmp + c_angles_tmp);
  angles[10] = q3_idx_0;
  angles[3] = q1_idx_1;
  angles[7] = atan2(d_angles_tmp + c3_tmp, angles_tmp + c3);
  angles[11] = q3_idx_1;
}

/* End of code generation (positionCartesian.c) */
