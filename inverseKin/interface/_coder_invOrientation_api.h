/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_invOrientation_api.h
 *
 * Code generation for function '_coder_invOrientation_api'
 *
 */

#ifndef _CODER_INVORIENTATION_API_H
#define _CODER_INVORIENTATION_API_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void invOrientation(real_T R_in[9], real_T q1, real_T q2, real_T q3,
  real_T qOri[3]);
extern void invOrientation_api(const mxArray * const prhs[4], int32_T nlhs,
  const mxArray *plhs[1]);
extern void invOrientation_atexit(void);
extern void invOrientation_initialize(void);
extern void invOrientation_terminate(void);
extern void invOrientation_xil_shutdown(void);
extern void invOrientation_xil_terminate(void);
extern void inverseKinematics(real_T pose[6], real_T jointAngles[6]);
extern void inverseKinematics_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[1]);
extern void positionCartesian(real_T L1, real_T L2, real_T wrist[3], real_T
  angles[12]);
extern void positionCartesian_api(const mxArray * const prhs[3], int32_T nlhs,
  const mxArray *plhs[1]);
extern void wristPositionOrientation(real_T p_E[3], real_T RPY[3], real_T L3,
  real_T p_w[3], real_T R_in[9]);
extern void wristPositionOrientation_api(const mxArray * const prhs[3], int32_T
  nlhs, const mxArray *plhs[2]);

#endif

/* End of code generation (_coder_invOrientation_api.h) */
