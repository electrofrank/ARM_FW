/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * wristPositionOrientation.c
 *
 * Code generation for function 'wristPositionOrientation'
 *
 */

/* Include files */
#include "wristPositionOrientation.h"
#include "invOrientation.h"
#include "inverseKinematics.h"
#include "positionCartesian.h"
#include <math.h>

/* Function Definitions */
void wristPositionOrientation(const double p_E[3], const double RPY[3], double
  L3, double p_w[3], double R_in[9])
{
  double z_tmp;
  double b_z_tmp;
  double c_z_tmp;
  double d_z_tmp;
  double e_z_tmp;
  double x_tmp;

  /*  This function calculates desired position and orientation of the wrist  */
  /*  given TCP position and rotation. */
  /*  p_w  - position of the wrist in Cartesian coordinate system */
  /*  R_in - orientation of the wrist  */
  /*  p_E  - desired position of the end effector */
  /*  RPY  - roll-pitch-yaw angles: */
  /*    RPY(1) - roll angle; */
  /*    RPY(2) - pitch angle; */
  /*    RPY(3) - yaw angle. */
  /*  x,y,z variables are created just for clear understanding, they will be */
  /*  deleted and expressions would be put directly on p_w calculation. */
  /*  Expressions of  x and z are swapped. */
  z_tmp = sin(RPY[2]);
  b_z_tmp = sin(RPY[1]);
  c_z_tmp = cos(RPY[0]);
  d_z_tmp = cos(RPY[2]);
  e_z_tmp = sin(RPY[0]);
  x_tmp = cos(RPY[1]);

  /*  Calculation of the wrist position */
  p_w[0] = p_E[0] - L3 * (x_tmp * c_z_tmp);
  p_w[1] = p_E[1] - L3 * (z_tmp * b_z_tmp * c_z_tmp - d_z_tmp * e_z_tmp);
  p_w[2] = p_E[2] - L3 * (c_z_tmp * b_z_tmp * d_z_tmp + e_z_tmp * z_tmp);

  /*  Calculation of the orientation */
  R_in[0] = d_z_tmp * x_tmp;
  R_in[3] = x_tmp * z_tmp;
  R_in[6] = -b_z_tmp;
  R_in[1] = e_z_tmp * b_z_tmp * d_z_tmp - c_z_tmp * z_tmp;
  R_in[4] = sin(RPY[0]) * sin(RPY[1]) * z_tmp + c_z_tmp * d_z_tmp;
  R_in[7] = e_z_tmp * x_tmp;
  R_in[2] = cos(RPY[0]) * sin(RPY[1]) * cos(RPY[2]) + sin(RPY[0]) * sin(RPY[2]);
  R_in[5] = cos(RPY[0]) * sin(RPY[1]) * z_tmp - sin(RPY[0]) * cos(RPY[2]);
  R_in[8] = cos(RPY[1]) * cos(RPY[0]);
}

/* End of code generation (wristPositionOrientation.c) */
