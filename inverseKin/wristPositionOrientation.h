/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * wristPositionOrientation.h
 *
 * Code generation for function 'wristPositionOrientation'
 *
 */

#ifndef WRISTPOSITIONORIENTATION_H
#define WRISTPOSITIONORIENTATION_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "invOrientation_types.h"

/* Function Declarations */
extern void wristPositionOrientation(const double p_E[3], const double RPY[3],
  double L3, double p_w[3], double R_in[9]);

#endif

/* End of code generation (wristPositionOrientation.h) */
