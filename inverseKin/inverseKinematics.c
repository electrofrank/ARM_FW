/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * inverseKinematics.c
 *
 * Code generation for function 'inverseKinematics'
 *
 */

/* Include files */
#include "inverseKinematics.h"
#include "invOrientation.h"
#include "positionCartesian.h"
#include "wristPositionOrientation.h"

/* Function Definitions */
void inverseKinematics(const double pose[6], double jointAngles[6])
{
  double qOri[3];
  double R_in[9];
  double qPos[12];

  /*  Define Link Lengths */
  /*  Seperate End-Effector Pose into Position and Orientation */
  /*  Calculate Wrist Position and R_in */
  wristPositionOrientation(*(double (*)[3])&pose[0], *(double (*)[3])&pose[3],
    310.0, qOri, R_in);

  /*  Calculate Position Joint Variables */
  positionCartesian(590.0, 370.0, qOri, qPos);

  /*  Calculate Orientation Joint Variables */
  invOrientation(R_in, qPos[1], qPos[5], qPos[9], qOri);

  /*  Define jointAngles vector */
  jointAngles[0] = qPos[1];
  jointAngles[3] = qOri[0];
  jointAngles[1] = qPos[5];
  jointAngles[4] = qOri[1];
  jointAngles[2] = qPos[9];
  jointAngles[5] = qOri[2];
}

/* End of code generation (inverseKinematics.c) */
