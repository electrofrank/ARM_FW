/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "invOrientation.h"
#include "invOrientation_terminate.h"
#include "inverseKinematics.h"
#include "positionCartesian.h"
#include "wristPositionOrientation.h"

/* Function Declarations */
static void argInit_1x6_real_T(double result[6]);
static void argInit_3x1_real_T(double result[3]);
static void argInit_3x3_real_T(double result[9]);
static double argInit_real_T(void);
static void main_invOrientation(void);
static void main_inverseKinematics(void);
static void main_positionCartesian(void);
static void main_wristPositionOrientation(void);

/* Function Definitions */
static void argInit_1x6_real_T(double result[6])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 6; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_3x1_real_T(double result[3])
{
  double result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[2] = result_tmp;
}

static void argInit_3x3_real_T(double result[9])
{
  double result_tmp;
  int idx0;

  /* Loop over the array to initialize each element. */
  result_tmp = argInit_real_T();
  for (idx0 = 0; idx0 < 3; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 3] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 6] = result_tmp;
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_invOrientation(void)
{
  double q1_tmp;
  double dv[9];
  double qOri[3];

  /* Initialize function 'invOrientation' input arguments. */
  /* Initialize function input argument 'R_in'. */
  q1_tmp = argInit_real_T();

  /* Call the entry-point 'invOrientation'. */
  argInit_3x3_real_T(dv);
  invOrientation(dv, q1_tmp, q1_tmp, q1_tmp, qOri);
}

static void main_inverseKinematics(void)
{
  double dv[6];
  double jointAngles[6];

  /* Initialize function 'inverseKinematics' input arguments. */
  /* Initialize function input argument 'pose'. */
  /* Call the entry-point 'inverseKinematics'. */
  argInit_1x6_real_T(dv);
  inverseKinematics(dv, jointAngles);
}

static void main_positionCartesian(void)
{
  double L1_tmp;
  double dv[3];
  double angles[12];

  /* Initialize function 'positionCartesian' input arguments. */
  L1_tmp = argInit_real_T();

  /* Initialize function input argument 'wrist'. */
  /* Call the entry-point 'positionCartesian'. */
  argInit_3x1_real_T(dv);
  positionCartesian(L1_tmp, L1_tmp, dv, angles);
}

static void main_wristPositionOrientation(void)
{
  double dv[3];
  double dv1[3];
  double p_w[3];
  double R_in[9];

  /* Initialize function 'wristPositionOrientation' input arguments. */
  /* Initialize function input argument 'p_E'. */
  /* Initialize function input argument 'RPY'. */
  /* Call the entry-point 'wristPositionOrientation'. */
  argInit_3x1_real_T(dv);
  argInit_3x1_real_T(dv1);
  wristPositionOrientation(dv, dv1, argInit_real_T(), p_w, R_in);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_inverseKinematics();
  main_invOrientation();
  main_positionCartesian();
  main_wristPositionOrientation();

  /* Terminate the application.
     You do not need to do this more than one time. */
  invOrientation_terminate();
  return 0;
}

/* End of code generation (main.c) */
