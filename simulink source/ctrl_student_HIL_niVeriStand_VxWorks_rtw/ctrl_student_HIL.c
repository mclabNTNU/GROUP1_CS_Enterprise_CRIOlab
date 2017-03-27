/*
 * ctrl_student_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.465
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 27 12:49:36 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

/* Block signals (auto storage) */
B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states */
X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_student_HIL_T ctrl_student_HIL_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_student_HIL_T ctrl_student_HIL_M_;
RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M = &ctrl_student_HIL_M_;

/* Forward declaration for local functions */
static real_T ctrl_student_HIL_norm(const real_T x[3]);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S12>/MATLAB Function'
 *    '<S29>/MATLAB Function'
 *    '<S30>/MATLAB Function'
 *    '<S31>/MATLAB Function'
 */
void ctrl_student_HIL_MATLABFunction(real_T rtu_u, real_T rtu_u_j, real_T
  rtu_u_c, B_MATLABFunction_ctrl_student_T *localB)
{
  /* MATLAB Function 'DP-system/Kd/MATLAB Function': '<S19>:1' */
  /* '<S19>:1:2' */
  memset(&localB->y[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S19>/TmpSignal ConversionAt SFunction Inport1' */
  localB->y[0] = rtu_u;
  localB->y[4] = rtu_u_j;
  localB->y[8] = rtu_u_c;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/update law' */
static real_T ctrl_student_HIL_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Model output function */
void ctrl_student_HIL_output(void)
{
  /* local block i/o variables */
  real_T rtb_Sum2[3];
  real_T tau[3];
  real_T u[3];
  real_T u_VSP_x;
  real_T x;
  real_T b_x;
  real_T b_a;
  real_T c_a;
  int32_T k;
  real_T D[9];
  real_T R[9];
  real_T S[9];
  static const real_T a[9] = { -0.2, -0.0, -0.0, -0.0, -0.2, -0.0, -0.0, -0.0,
    -0.1 };

  static const real_T b_a_0[9] = { 16.79, 0.0, 0.0, 0.0, 15.79,
    0.55462499999999992, 0.0, 0.55462499999999992, 2.76 };

  real_T V1_s;
  int32_T d;
  int32_T idx[10];
  int32_T nb;
  int32_T khi;
  int32_T iwork[10];
  int32_T b_i;
  int32_T kEnd;
  int32_T f_k;
  int32_T exponent;
  int32_T d_j;
  int32_T b_pEnd;
  int32_T b_qEnd;
  int32_T b_kEnd;
  int32_T b_exponent;
  boolean_T guard1 = false;
  real_T rtb_u;
  real_T rtb_Gain1;
  real_T rtb_a_1[3];
  real_T rtb_tau[3];
  real_T rtb_R[9];
  real_T R_0[3];
  real_T S_0[9];
  real_T S_1[3];
  real_T R_1[3];
  real_T a_0[3];
  real_T tmp[9];
  real_T tmp_0[9];
  real_T tmp_1[9];
  real_T b_data[10];
  real_T rtb_Product_idx_1;
  real_T rtb_Product_idx_2;
  real_T rtb_y_idx_2;
  real_T rtb_y_idx_0;
  real_T rtb_y_idx_1;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* set solver stop time */
    if (!(ctrl_student_HIL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTickH0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTick0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 +
        ctrl_student_HIL_M->Timing.clockTickH0 *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_HIL_M)) {
    ctrl_student_HIL_M->Timing.t[0] = rtsiGetT(&ctrl_student_HIL_M->solverInfo);
  }

  /* Product: '<S7>/Product' incorporates:
   *  Gain: '<S7>/Gain'
   *  Sum: '<S7>/Sum'
   */
  /* MATLAB Function 'joystick/MATLAB Function': '<S39>:1' */
  rtb_Product_idx_1 = ctrl_student_HIL_B.PosXRight;
  rtb_Product_idx_2 = (ctrl_student_HIL_B.L2_continuous -
                       ctrl_student_HIL_B.R2_continuous) *
    ctrl_student_HIL_P.Gain_Gain;

  /* Gain: '<S7>/Gain1' incorporates:
   *  Product: '<S7>/Product'
   */
  rtb_Gain1 = ctrl_student_HIL_P.Gain1_Gain * ctrl_student_HIL_B.PosYRight;

  /* MATLAB Function: '<S7>/Thrust allocation' incorporates:
   *  Constant: '<S7>/True'
   *  Product: '<S7>/Product'
   */
  /* MATLAB Function 'joystick/Thrust allocation': '<S40>:1' */
  /*  Forces and moments vector */
  /* '<S40>:1:4' */
  /*  Extended thrust configuration matrix */
  /*  Extended thrust coefficient matrix */
  /*  tau = T*K*u inverse */
  /* '<S40>:1:23' */
  u[1] = ctrl_student_HIL_B.PosXRight - rtb_Gain1 * 0.0;
  u[2] = (rtb_Product_idx_2 - rtb_Gain1 * 0.0) - u[1] * -0.4575;
  u[2] /= 2.221505;
  u[0] = rtb_Gain1 - u[2] * 0.0;
  u[1] -= u[2] * 2.629;
  rtb_u = u[1] / 1.165;
  u[1] /= 1.165;
  u[0] -= u[1] * 0.0;

  /* '<S40>:1:25' */
  /* '<S40>:1:27' */
  u_VSP_x = u[0] / 1.165;

  /* '<S40>:1:28' */
  /* '<S40>:1:29' */
  /* '<S40>:1:30' */
  if (ctrl_student_HIL_P.True_Value != 0.0) {
    /* '<S40>:1:33' */
    ctrl_student_HIL_B.omega_VSP = 0.3;
  } else {
    /* '<S40>:1:35' */
    ctrl_student_HIL_B.omega_VSP = 0.0;
  }

  ctrl_student_HIL_B.u_BT = u[2];
  ctrl_student_HIL_B.u_VSP = sqrt(u_VSP_x * u_VSP_x + rtb_u * rtb_u);
  ctrl_student_HIL_B.alpha_VSP = rt_atan2d_snf(rtb_u, u[0] / 1.165);

  /* End of MATLAB Function: '<S7>/Thrust allocation' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Integrator: '<Root>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_student_HIL_B.ArrowRight);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator_CSTATE[0] = ctrl_student_HIL_P.Integrator_IC;
      ctrl_student_HIL_X.Integrator_CSTATE[1] = ctrl_student_HIL_P.Integrator_IC;
      ctrl_student_HIL_X.Integrator_CSTATE[2] = ctrl_student_HIL_P.Integrator_IC;
    }
  }

  ctrl_student_HIL_B.Integrator[0] = ctrl_student_HIL_X.Integrator_CSTATE[0];
  ctrl_student_HIL_B.Integrator[1] = ctrl_student_HIL_X.Integrator_CSTATE[1];
  ctrl_student_HIL_B.Integrator[2] = ctrl_student_HIL_X.Integrator_CSTATE[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S9>/Memory' */
    ctrl_student_HIL_B.Memory = ctrl_student_HIL_DW.Memory_PreviousInput;
  }

  /* MATLAB Function: '<S9>/Switch_function' incorporates:
   *  SignalConversion: '<S42>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'switch/Switch_function': '<S42>:1' */
  /* % Function that takes in impulse button sigals [0,1] and sends out a  */
  /*  different signal depentent pn which button has been pressed */
  /* '<S42>:1:8' */
  rtb_u = ctrl_student_HIL_B.Memory;
  if (ctrl_student_HIL_B.ArrowUp != 0.0) {
    /* '<S42>:1:10' */
    /* '<S42>:1:11' */
    rtb_u = 1.0;
  }

  if (ctrl_student_HIL_B.ArrowDown != 0.0) {
    /* '<S42>:1:14' */
    /* '<S42>:1:15' */
    rtb_u = 2.0;
  }

  if (ctrl_student_HIL_B.ArrowLeft != 0.0) {
    /* '<S42>:1:18' */
    /* '<S42>:1:19' */
    rtb_u = 3.0;
  }

  /* '<S42>:1:22' */
  ctrl_student_HIL_B.switch_signal = rtb_u;

  /* End of MATLAB Function: '<S9>/Switch_function' */

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   */
  if (ctrl_student_HIL_B.dead != 0.0) {
    rtb_u = ctrl_student_HIL_P.Constant_Value;
  } else {
    rtb_u = ctrl_student_HIL_P.Constant1_Value;
  }

  /* End of Switch: '<S5>/Switch1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S20>/counter' */
    ctrl_student_HIL_B.counter = ctrl_student_HIL_DW.counter_PreviousInput;
  }

  /* MATLAB Function: '<S20>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Step size'
   */
  /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S23>:1' */
  /* '<S23>:1:3' */
  if ((ctrl_student_HIL_B.counter + 1.0) * ctrl_student_HIL_P.Stepsize_Value >=
      1.0 / ctrl_student_HIL_B.Samp_freq) {
    /* '<S23>:1:4' */
    /* '<S23>:1:5' */
    ctrl_student_HIL_B.count = 0.0;
  } else {
    /* '<S23>:1:7' */
    ctrl_student_HIL_B.count = ctrl_student_HIL_B.counter + 1.0;
  }

  /* End of MATLAB Function: '<S20>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S26>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise = ctrl_student_HIL_DW.NextOutput;

    /* RandomNumber: '<S27>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_e = ctrl_student_HIL_DW.NextOutput_c;

    /* RandomNumber: '<S25>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_m = ctrl_student_HIL_DW.NextOutput_p;
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtetaaaInport1' */
  ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor[0] =
    ctrl_student_HIL_B.x_in;
  ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor[1] =
    ctrl_student_HIL_B.y_in;
  ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor[2] =
    ctrl_student_HIL_B.psi_in;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S21>/Hold' */
    ctrl_student_HIL_B.Hold[0] = ctrl_student_HIL_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_B.Hold[1] = ctrl_student_HIL_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_B.Hold[2] = ctrl_student_HIL_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S21>/MATLAB Function1' incorporates:
   *  Constant: '<S2>/Step size'
   *  Product: '<S25>/Divide'
   *  Product: '<S25>/Product'
   *  Product: '<S26>/Divide'
   *  Product: '<S26>/Product'
   *  Product: '<S27>/Divide'
   *  Product: '<S27>/Product'
   *  Sqrt: '<S25>/Sqrt'
   *  Sqrt: '<S26>/Sqrt'
   *  Sqrt: '<S27>/Sqrt'
   *  Sum: '<S2>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S24>:1' */
  if (ctrl_student_HIL_B.count == 0.0) {
    /* '<S24>:1:4' */
    /* '<S24>:1:5' */
    ctrl_student_HIL_B.output[0] = sqrt(ctrl_student_HIL_B.N_power /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise +
      ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor[0];
    ctrl_student_HIL_B.output[1] = sqrt(ctrl_student_HIL_B.N_power /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise_e +
      ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor[1];
    ctrl_student_HIL_B.output[2] = sqrt(ctrl_student_HIL_B.N_power_H /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise_m +
      ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor[2];
  } else {
    /* '<S24>:1:7' */
    ctrl_student_HIL_B.output[0] = ctrl_student_HIL_B.Hold[0];
    ctrl_student_HIL_B.output[1] = ctrl_student_HIL_B.Hold[1];
    ctrl_student_HIL_B.output[2] = ctrl_student_HIL_B.Hold[2];
  }

  /* End of MATLAB Function: '<S21>/MATLAB Function1' */

  /* Switch: '<S2>/Switch' */
  if (ctrl_student_HIL_B.Enable_noise != 0.0) {
    rtb_Sum2[0] = ctrl_student_HIL_B.output[0];
    rtb_Sum2[1] = ctrl_student_HIL_B.output[1];
    rtb_Sum2[2] = ctrl_student_HIL_B.output[2];
  } else {
    rtb_Sum2[0] = ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor[0];
    rtb_Sum2[1] = ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor[1];
    rtb_Sum2[2] = ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor[2];
  }

  /* End of Switch: '<S2>/Switch' */

  /* Product: '<Root>/Product' */
  ctrl_student_HIL_B.Product[0] = rtb_u * rtb_Sum2[0];
  ctrl_student_HIL_B.Product[1] = rtb_u * rtb_Sum2[1];
  ctrl_student_HIL_B.Product[2] = rtb_u * rtb_Sum2[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S1>/Memory4' */
    ctrl_student_HIL_B.Memory4[0] = ctrl_student_HIL_DW.Memory4_PreviousInput[0];
    ctrl_student_HIL_B.Memory4[1] = ctrl_student_HIL_DW.Memory4_PreviousInput[1];
    ctrl_student_HIL_B.Memory4[2] = ctrl_student_HIL_DW.Memory4_PreviousInput[2];

    /* Memory: '<S1>/Memory5' */
    ctrl_student_HIL_B.Memory5[0] = ctrl_student_HIL_DW.Memory5_PreviousInput[0];
    ctrl_student_HIL_B.Memory5[1] = ctrl_student_HIL_DW.Memory5_PreviousInput[1];
    ctrl_student_HIL_B.Memory5[2] = ctrl_student_HIL_DW.Memory5_PreviousInput[2];

    /* Memory: '<S1>/Memory2' */
    ctrl_student_HIL_B.Memory2 = ctrl_student_HIL_DW.Memory2_PreviousInput;
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1' */
  rtb_Sum2[0] = ctrl_student_HIL_B.ArrowUp;
  rtb_Sum2[1] = ctrl_student_HIL_B.ArrowDown;
  rtb_Sum2[2] = ctrl_student_HIL_B.ArrowLeft;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Gain'
   */
  ctrl_student_HIL_B.Sum = ((ctrl_student_HIL_P.Gain_Gain_l[0] * rtb_Sum2[0] +
    ctrl_student_HIL_P.Gain_Gain_l[1] * rtb_Sum2[1]) +
    ctrl_student_HIL_P.Gain_Gain_l[2] * rtb_Sum2[2]) +
    ctrl_student_HIL_B.ArrowRight;

  /* Integrator: '<S1>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_student_HIL_B.Sum);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator1_CSTATE = ctrl_student_HIL_P.Integrator1_IC;
    }
  }

  ctrl_student_HIL_B.Integrator1 = ctrl_student_HIL_X.Integrator1_CSTATE;

  /* MATLAB Function: '<S1>/inputs' */
  /* MATLAB Function 'DP-system/inputs': '<S15>:1' */
  /*  i = temp1(1);   */
  /*  U_ref_l = temp1(2);  */
  /* '<S15>:1:4' */
  /* '<S15>:1:5' */
  /* '<S15>:1:6' */
  /* '<S15>:1:7' */
  /* '<S15>:1:9' */
  /*  my må være null hvis dp = 1 */
  /* '<S15>:1:11' */
  ctrl_student_HIL_B.U_ref_l = 0.1;

  /* '<S15>:1:12' */
  /*  % ikke dp i starten */
  /*   */
  /*      if i == 0 */
  /*          U_ref_l = U_max/5;  */
  /*          if s > 1; */
  /*              i = 1;  */
  /*          end  */
  /*      end  */
  /*   */
  /*      if i == 1 */
  /*          U_ref_l = -U_max/5; */
  /*          if s < 0 */
  /*              i = 0;  */
  /*          end */
  /*      end  */
  /*  U_ref = U_ref_l; */
  /*   */
  /*  % error = [0 0]; */
  /*  % error(1) = eta(1) - eta_0(1); */
  /*  % error(2) = eta(2) - eta_0(2);  */
  /*  % DP i starten */
  /*  % if dp == 1  */
  /*  % if i == 0  */
  /*  %     if (abs(error(1)) < 0.01 && abs(error(2)) < 0.01) */
  /*  %     U_ref_l = U_max/5; */
  /*  %     i = 1;  */
  /*  %     end */
  /*  % end  */
  /*  %  */
  /*  % if i == 1 */
  /*  %     if s >= 1 */
  /*  %         U_ref_l = -U_max/5; */
  /*  %         i = 2;  */
  /*  %     end      */
  /*  % end */
  /*  %  */
  /*  % if i == 2 */
  /*  %     if s <= 0  */
  /*  %         U_ref_l = U_max/5;  */
  /*  %         i = 1;  */
  /*  %     end  */
  /*  % end  */
  /*  % end */
  /*   */
  /*  temp = [0 0]; */
  /*  temp(1) = i;  */
  /*  temp(2) = U_ref_l;  */
  /* MATLAB Function 'DP-system/Straight -line ': '<S13>:1' */
  /* '<S13>:1:3' */
  /* '<S13>:1:7' */
  /* '<S13>:1:10' */
  /* '<S13>:1:15' */
  /* '<S13>:1:17' */
  /* '<S13>:1:20' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S1>/Memory' */
    memcpy(&ctrl_student_HIL_B.Memory_p[0],
           &ctrl_student_HIL_DW.Memory_PreviousInput_l[0], 11U * sizeof(real_T));
  }

  /* MATLAB Function: '<S1>/Ellipsoidal path' incorporates:
   *  MATLAB Function: '<S1>/inputs'
   */
  /* MATLAB Function 'DP-system/Ellipsoidal path': '<S11>:1' */
  /* '<S11>:1:3' */
  tau[2] = rt_atan2d_snf(cos(6.2831853071795862 * ctrl_student_HIL_B.Integrator1)
    * -7.0, sin(6.2831853071795862 * ctrl_student_HIL_B.Integrator1) * 7.0);

  /* wrapping psi_d      */
  /* '<S11>:1:9' */
  k = 0;
  if (fabs(tau[2] - ctrl_student_HIL_B.Memory_p[2]) > 3.1415926535897931) {
    /* '<S11>:1:11' */
    if (ctrl_student_HIL_B.Memory_p[2] < tau[2]) {
      /* '<S11>:1:12' */
      /* '<S11>:1:13' */
      k = -1;
    } else {
      if (ctrl_student_HIL_B.Memory_p[2] > tau[2]) {
        /* '<S11>:1:14' */
        /* '<S11>:1:15' */
        k = 1;
      }
    }
  }

  /* '<S11>:1:18' */
  tau[2] += 6.2831853071795862 * (real_T)k;

  /* '<S11>:1:21' */
  x = cos(6.2831853071795862 * ctrl_student_HIL_B.Integrator1);
  b_x = sin(6.2831853071795862 * ctrl_student_HIL_B.Integrator1);

  /* '<S11>:1:25' */
  V1_s = (cos(12.566370614359172 * ctrl_student_HIL_B.Integrator1) * 49.0 + 98.0)
    - cos(12.566370614359172 * ctrl_student_HIL_B.Integrator1) * 49.0;

  /* '<S11>:1:30' */
  u_VSP_x = sin(6.2831853071795862 * ctrl_student_HIL_B.Integrator1);
  rtb_u = cos(6.2831853071795862 * ctrl_student_HIL_B.Integrator1);

  /* '<S11>:1:32' */
  b_a = sin(6.2831853071795862 * ctrl_student_HIL_B.Integrator1) *
    -43.982297150257104;
  c_a = cos(6.2831853071795862 * ctrl_student_HIL_B.Integrator1) * 7.0 * 2.0 *
    3.1415926535897931;

  /* '<S11>:1:35' */
  ctrl_student_HIL_B.eta_v[0] = cos(6.2831853071795862 *
    ctrl_student_HIL_B.Integrator1) * 7.0;
  ctrl_student_HIL_B.eta_v[1] = sin(6.2831853071795862 *
    ctrl_student_HIL_B.Integrator1) * 7.0;
  ctrl_student_HIL_B.eta_v[2] = tau[2];
  ctrl_student_HIL_B.eta_v[3] = sin(6.2831853071795862 *
    ctrl_student_HIL_B.Integrator1) * -7.0 * 6.2831853071795862;
  ctrl_student_HIL_B.eta_v[4] = cos(6.2831853071795862 *
    ctrl_student_HIL_B.Integrator1) * 7.0 * 6.2831853071795862;
  ctrl_student_HIL_B.eta_v[5] = -49.0 / (x * x * 49.0 + b_x * b_x * 49.0) *
    6.2831853071795862;
  ctrl_student_HIL_B.eta_v[6] = cos(6.2831853071795862 *
    ctrl_student_HIL_B.Integrator1) * -7.0 * 39.478417604357432;
  ctrl_student_HIL_B.eta_v[7] = sin(6.2831853071795862 *
    ctrl_student_HIL_B.Integrator1) * -7.0 * 39.478417604357432;
  ctrl_student_HIL_B.eta_v[8] = sin(12.566370614359172 *
    ctrl_student_HIL_B.Integrator1) * 0.0 / (V1_s * V1_s) * 39.478417604357432;
  ctrl_student_HIL_B.eta_v[9] = 0.05 / sqrt(u_VSP_x * u_VSP_x * 49.0 + rtb_u *
    rtb_u * 49.0);
  ctrl_student_HIL_B.eta_v[10] = (sin(6.2831853071795862 *
    ctrl_student_HIL_B.Integrator1) * 49.0 * 248.05021344239853 * cos
    (6.2831853071795862 * ctrl_student_HIL_B.Integrator1) - cos
    (6.2831853071795862 * ctrl_student_HIL_B.Integrator1) * 49.0 *
    248.05021344239853 * sin(6.2831853071795862 * ctrl_student_HIL_B.Integrator1))
    * -0.05 / rt_powd_snf(b_a * b_a + c_a * c_a, 1.5);

  /* End of MATLAB Function: '<S1>/Ellipsoidal path' */

  /* MATLAB Function: '<S1>/signal switch ' incorporates:
   *  MATLAB Function: '<S1>/Straight -line '
   *  MATLAB Function: '<S1>/inputs'
   */
  /* MATLAB Function 'DP-system/signal switch ': '<S16>:1' */
  /* '<S16>:1:3' */
  ctrl_student_HIL_B.signal[0] = 2.0 * ctrl_student_HIL_B.Integrator1 + 2.0;
  ctrl_student_HIL_B.signal[1] = 2.0 * ctrl_student_HIL_B.Integrator1;
  ctrl_student_HIL_B.signal[2] = 0.78539816339744828;
  ctrl_student_HIL_B.signal[3] = 2.0;
  ctrl_student_HIL_B.signal[4] = 2.0;
  ctrl_student_HIL_B.signal[5] = 0.0;
  ctrl_student_HIL_B.signal[6] = 0.0;
  ctrl_student_HIL_B.signal[7] = 0.0;
  ctrl_student_HIL_B.signal[8] = 0.0;
  ctrl_student_HIL_B.signal[9] = ctrl_student_HIL_B.U_ref_l / 2.8284271247461903;
  ctrl_student_HIL_B.signal[10] = 0.0;
  if (ctrl_student_HIL_B.switch_signal == 2.0) {
    /* '<S16>:1:8' */
    /* '<S16>:1:9' */
    memcpy(&ctrl_student_HIL_B.signal[0], &ctrl_student_HIL_B.eta_v[0], 11U *
           sizeof(real_T));
  }

  /* End of MATLAB Function: '<S1>/signal switch ' */

  /* MATLAB Function: '<S12>/MATLAB Function' */
  ctrl_student_HIL_MATLABFunction(ctrl_student_HIL_B.Kd1, ctrl_student_HIL_B.Kd2,
    ctrl_student_HIL_B.Kd3, &ctrl_student_HIL_B.sf_MATLABFunction_h);

  /* SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport5' incorporates:
   *  MATLAB Function: '<S1>/controller'
   */
  tau[0] = ctrl_student_HIL_B.u_in;
  tau[1] = ctrl_student_HIL_B.v_in;
  tau[2] = ctrl_student_HIL_B.r_in;

  /* MATLAB Function: '<S1>/controller' incorporates:
   *  SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport5'
   */
  /* MATLAB Function 'DP-system/controller': '<S14>:1' */
  /* Kinetics */
  /* '<S14>:1:3' */
  /* '<S14>:1:4' */
  /* '<S14>:1:5' */
  /*  MATRICES */
  /*  Added mass */
  /*  Table B.1 */
  /*  Table B.1 guestimate */
  /*  Table B.1 */
  /*  Total mass matrix */
  /*  Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S14>:1:28' */
  /* '<S14>:1:31' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S14>:1:35' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /*  Correolis matrix */
  /*  Assembly of the damping matrix */
  /* '<S14>:1:48' */
  /* '<S14>:1:49' */
  /* '<S14>:1:50' */
  /*  using abs(r) */
  /* '<S14>:1:52' */
  /* '<S14>:1:53' */
  /* '<S14>:1:54' */
  /* '<S14>:1:56' */
  D[0] = (0.6555 - 0.3545 * ctrl_student_HIL_B.u_in) - ctrl_student_HIL_B.u_in *
    ctrl_student_HIL_B.u_in * -3.787;
  D[3] = (-0.0 - -2.443 * ctrl_student_HIL_B.v_in) - ctrl_student_HIL_B.v_in *
    ctrl_student_HIL_B.v_in * 0.0;
  D[6] = 0.0;
  D[1] = 0.0;
  D[4] = ((1.33 - -2.776 * ctrl_student_HIL_B.v_in) - ctrl_student_HIL_B.v_in *
          ctrl_student_HIL_B.v_in * -64.91) - -0.805 * fabs
    (ctrl_student_HIL_B.r_in);
  D[7] = ((7.25 - -3.45 * fabs(ctrl_student_HIL_B.r_in)) -
          ctrl_student_HIL_B.r_in * ctrl_student_HIL_B.r_in * 0.0) - -0.845 *
    fabs(ctrl_student_HIL_B.v_in);
  D[2] = 0.0;
  D[5] = ((-0.0 - -0.2088 * ctrl_student_HIL_B.v_in) - ctrl_student_HIL_B.v_in *
          ctrl_student_HIL_B.v_in * 0.0) - 0.13 * fabs(ctrl_student_HIL_B.r_in);
  D[8] = ((1.9 - -0.75 * fabs(ctrl_student_HIL_B.r_in)) -
          ctrl_student_HIL_B.r_in * ctrl_student_HIL_B.r_in * 0.0) - 0.08 * fabs
    (ctrl_student_HIL_B.v_in);

  /* Eta_d derivatives and U_s */
  /* '<S14>:1:63' */
  /* '<S14>:1:64' */
  /* '<S14>:1:65' */
  /* '<S14>:1:66' */
  /* '<S14>:1:67' */
  /* Rotation matrix and derivative */
  /* '<S14>:1:69' */
  R[0] = cos(ctrl_student_HIL_B.signal[2]);
  R[3] = -sin(ctrl_student_HIL_B.signal[2]);
  R[6] = 0.0;
  R[1] = sin(ctrl_student_HIL_B.signal[2]);
  R[4] = cos(ctrl_student_HIL_B.signal[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* '<S14>:1:73' */
  S[0] = 0.0;
  S[3] = -ctrl_student_HIL_B.signal[2];
  S[6] = 0.0;
  S[1] = ctrl_student_HIL_B.signal[2];
  S[4] = 0.0;
  S[7] = 0.0;
  S[2] = 0.0;
  S[5] = 0.0;
  S[8] = 0.0;

  /* Gain matrices  */
  /* Kd = diag([25 15 30]); */
  /* Controller alpha 1 */
  /* '<S14>:1:82' */
  for (k = 0; k < 3; k++) {
    R_0[k] = R[3 * k + 2] * ctrl_student_HIL_B.signal[5] + (R[3 * k + 1] *
      ctrl_student_HIL_B.signal[4] + R[3 * k] * ctrl_student_HIL_B.signal[3]);
  }

  for (k = 0; k < 3; k++) {
    rtb_a_1[k] = ((a[k + 3] * ctrl_student_HIL_B.Memory4[1] + a[k] *
                   ctrl_student_HIL_B.Memory4[0]) + a[k + 6] *
                  ctrl_student_HIL_B.Memory4[2]) + R_0[k] *
      ctrl_student_HIL_B.signal[9];
  }

  /* Alpha derivative */
  /* '<S14>:1:86' */
  /* '<S14>:1:87' */
  /* '<S14>:1:88' */
  for (k = 0; k < 3; k++) {
    S_0[3 * k] = -S[3 * k];
    S_0[1 + 3 * k] = -S[3 * k + 1];
    S_0[2 + 3 * k] = -S[3 * k + 2];
  }

  for (k = 0; k < 3; k++) {
    rtb_tau[k] = ((S_0[k + 3] * ctrl_student_HIL_B.Memory4[1] + S_0[k] *
                   ctrl_student_HIL_B.Memory4[0]) + S_0[k + 6] *
                  ctrl_student_HIL_B.Memory4[2]) + tau[k];
  }

  for (k = 0; k < 3; k++) {
    for (d = 0; d < 3; d++) {
      S_0[k + 3 * d] = 0.0;
      S_0[k + 3 * d] += S[k] * R[d];
      S_0[k + 3 * d] += S[k + 3] * R[d + 3];
    }
  }

  for (k = 0; k < 3; k++) {
    S_1[k] = S_0[k + 6] * ctrl_student_HIL_B.signal[5] + (S_0[k + 3] *
      ctrl_student_HIL_B.signal[4] + S_0[k] * ctrl_student_HIL_B.signal[3]);
  }

  for (k = 0; k < 3; k++) {
    for (d = 0; d < 3; d++) {
      S[k + 3 * d] = 0.0;
      S[k + 3 * d] += a[k] * R[d];
      S[k + 3 * d] += a[k + 3] * R[d + 3];
      S[k + 3 * d] += a[k + 6] * R[d + 6];
    }
  }

  for (k = 0; k < 3; k++) {
    R_0[k] = R[3 * k + 2] * ctrl_student_HIL_B.signal[8] + (R[3 * k + 1] *
      ctrl_student_HIL_B.signal[7] + R[3 * k] * ctrl_student_HIL_B.signal[6]);
  }

  for (k = 0; k < 3; k++) {
    R_1[k] = R[3 * k + 2] * ctrl_student_HIL_B.signal[5] + (R[3 * k + 1] *
      ctrl_student_HIL_B.signal[4] + R[3 * k] * ctrl_student_HIL_B.signal[3]);
  }

  for (k = 0; k < 3; k++) {
    a_0[k] = (((S[k + 3] * ctrl_student_HIL_B.signal[4] + S[k] *
                ctrl_student_HIL_B.signal[3]) + S[k + 6] *
               ctrl_student_HIL_B.signal[5]) + R_0[k] *
              ctrl_student_HIL_B.signal[9]) + R_1[k] *
      ctrl_student_HIL_B.signal[10];
  }

  for (k = 0; k < 3; k++) {
    u[k] = (((a[k + 3] * rtb_tau[1] + a[k] * rtb_tau[0]) + a[k + 6] * rtb_tau[2])
            - S_1[k] * ctrl_student_HIL_B.signal[9]) + a_0[k] *
      ctrl_student_HIL_B.Memory2;
  }

  /* Controller tau - C removed */
  /* '<S14>:1:91' */
  for (k = 0; k < 3; k++) {
    R_0[k] = ((D[k + 3] * ctrl_student_HIL_B.v_in + D[k] *
               ctrl_student_HIL_B.u_in) + D[k + 6] * ctrl_student_HIL_B.r_in) -
      ctrl_student_HIL_B.Memory4[k];
  }

  for (k = 0; k < 3; k++) {
    R_1[k] = b_a_0[k + 6] * u[2] + (b_a_0[k + 3] * u[1] + b_a_0[k] * u[0]);
  }

  for (k = 0; k < 3; k++) {
    rtb_tau[k] = (R_0[k] + R_1[k]) -
      ((ctrl_student_HIL_B.sf_MATLABFunction_h.y[k + 3] *
        ctrl_student_HIL_B.Memory5[1] +
        ctrl_student_HIL_B.sf_MATLABFunction_h.y[k] *
        ctrl_student_HIL_B.Memory5[0]) +
       ctrl_student_HIL_B.sf_MATLABFunction_h.y[k + 6] *
       ctrl_student_HIL_B.Memory5[2]);
  }

  /* '<S14>:1:92' */
  /* '<S14>:1:93' */
  ctrl_student_HIL_B.z11[0] = ctrl_student_HIL_B.Memory4[0];
  ctrl_student_HIL_B.z11[1] = ctrl_student_HIL_B.Memory4[1];
  ctrl_student_HIL_B.z11[2] = ctrl_student_HIL_B.Memory4[2];

  /* '<S14>:1:94' */
  /* '<S14>:1:95' */
  /* tau = a_1; */
  /* tau = [tau(1);tau(2);tau(3)]; */
  for (k = 0; k < 3; k++) {
    ctrl_student_HIL_B.D1[k] = 0.0;
    ctrl_student_HIL_B.D1[k] += D[k] * ctrl_student_HIL_B.u_in;
    ctrl_student_HIL_B.D1[k] += D[k + 3] * ctrl_student_HIL_B.v_in;
    ctrl_student_HIL_B.D1[k] += D[k + 6] * ctrl_student_HIL_B.r_in;
  }

  for (k = 0; k < 3; k++) {
    ctrl_student_HIL_B.ma[k] = 0.0;
    ctrl_student_HIL_B.ma[k] += b_a_0[k] * u[0];
    ctrl_student_HIL_B.ma[k] += b_a_0[k + 3] * u[1];
    ctrl_student_HIL_B.ma[k] += b_a_0[k + 6] * u[2];
  }

  for (k = 0; k < 3; k++) {
    ctrl_student_HIL_B.Kdz[k] = 0.0;
    ctrl_student_HIL_B.Kdz[k] += ctrl_student_HIL_B.sf_MATLABFunction_h.y[k] *
      ctrl_student_HIL_B.Memory5[0];
    ctrl_student_HIL_B.Kdz[k] += ctrl_student_HIL_B.sf_MATLABFunction_h.y[k + 3]
      * ctrl_student_HIL_B.Memory5[1];
    ctrl_student_HIL_B.Kdz[k] += ctrl_student_HIL_B.sf_MATLABFunction_h.y[k + 6]
      * ctrl_student_HIL_B.Memory5[2];
  }

  /* MATLAB Function: '<Root>/Switch joystick  and DP-system' incorporates:
   *  SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport3'
   */
  /* MATLAB Function 'Switch joystick  and DP-system': '<S4>:1' */
  /* % Function that takes in impulse button sigals [0,1] and sends out a  */
  /*  different signal depentent pn which button has been pressed */
  /* '<S4>:1:6' */
  tau[0] = 0.0;
  tau[1] = 0.0;
  tau[2] = 0.0;
  if (ctrl_student_HIL_B.switch_signal == 1.0) {
    /* '<S4>:1:7' */
    /* '<S4>:1:8' */
    tau[0] = rtb_tau[0];
    tau[1] = rtb_tau[1];
    tau[2] = rtb_tau[2];
  }

  if (ctrl_student_HIL_B.switch_signal == 2.0) {
    /* '<S4>:1:11' */
    /* '<S4>:1:12' */
    tau[0] = rtb_tau[0];
    tau[1] = rtb_tau[1];
    tau[2] = rtb_tau[2];
  }

  if (ctrl_student_HIL_B.switch_signal == 3.0) {
    /* '<S4>:1:15' */
    /* '<S4>:1:16' */
    tau[0] = rtb_Gain1;
    tau[1] = rtb_Product_idx_1;
    tau[2] = rtb_Product_idx_2;
  }

  /* End of MATLAB Function: '<Root>/Switch joystick  and DP-system' */

  /* Integrator: '<S3>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator2_Reset_ZCE,
                       ctrl_student_HIL_B.ArrowRight);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator2_CSTATE[0] =
        ctrl_student_HIL_P.Integrator2_IC;
      ctrl_student_HIL_X.Integrator2_CSTATE[1] =
        ctrl_student_HIL_P.Integrator2_IC;
      ctrl_student_HIL_X.Integrator2_CSTATE[2] =
        ctrl_student_HIL_P.Integrator2_IC;
    }
  }

  rtb_Sum2[0] = ctrl_student_HIL_X.Integrator2_CSTATE[0];
  rtb_Sum2[1] = ctrl_student_HIL_X.Integrator2_CSTATE[1];
  rtb_Sum2[2] = ctrl_student_HIL_X.Integrator2_CSTATE[2];

  /* Sum: '<Root>/Sum' */
  ctrl_student_HIL_B.Sum_k[0] = tau[0] + rtb_Sum2[0];
  ctrl_student_HIL_B.Sum_k[1] = tau[1] + rtb_Sum2[1];
  ctrl_student_HIL_B.Sum_k[2] = tau[2] + rtb_Sum2[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S1>/Memory3' */
    ctrl_student_HIL_B.Memory3[0] = ctrl_student_HIL_DW.Memory3_PreviousInput[0];
    ctrl_student_HIL_B.Memory3[1] = ctrl_student_HIL_DW.Memory3_PreviousInput[1];
    ctrl_student_HIL_B.Memory3[2] = ctrl_student_HIL_DW.Memory3_PreviousInput[2];

    /* Memory: '<S1>/Memory1' */
    ctrl_student_HIL_B.Memory1[0] = ctrl_student_HIL_DW.Memory1_PreviousInput[0];
    ctrl_student_HIL_B.Memory1[1] = ctrl_student_HIL_DW.Memory1_PreviousInput[1];
    ctrl_student_HIL_B.Memory1[2] = ctrl_student_HIL_DW.Memory1_PreviousInput[2];
  }

  /* MATLAB Function: '<S1>/update law' incorporates:
   *  MATLAB Function: '<S1>/inputs'
   *  SignalConversion: '<S17>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'DP-system/update law': '<S17>:1' */
  /* '<S17>:1:3' */
  rtb_u = ctrl_student_HIL_B.Memory1[0];

  /* '<S17>:1:4' */
  /* '<S17>:1:5' */
  u_VSP_x = ctrl_student_HIL_B.Memory1[1];

  /* Getting vectors */
  /* '<S17>:1:8' */
  /* '<S17>:1:10' */
  /* '<S17>:1:13' */
  /* '<S17>:1:17' */
  tmp[0] = cos(ctrl_student_HIL_B.psi_in);
  tmp[1] = -sin(ctrl_student_HIL_B.psi_in);
  tmp[2] = 0.0;
  tmp[3] = sin(ctrl_student_HIL_B.psi_in);
  tmp[4] = cos(ctrl_student_HIL_B.psi_in);
  tmp[5] = 0.0;
  tmp[6] = 0.0;
  tmp[7] = 0.0;
  tmp[8] = 1.0;
  for (k = 0; k < 3; k++) {
    R_1[k] = tmp[3 * k + 2] * -ctrl_student_HIL_B.Memory3[2] + (tmp[3 * k + 1] *
      -ctrl_student_HIL_B.Memory3[1] + tmp[3 * k] * -ctrl_student_HIL_B.Memory3
      [0]);
  }

  V1_s = (R_1[0] * ctrl_student_HIL_B.signal[3] + R_1[1] *
          ctrl_student_HIL_B.signal[4]) + R_1[2] * ctrl_student_HIL_B.signal[5];
  if (ctrl_student_HIL_B.Memory1[0] == 0.0) {
    /* '<S17>:1:22' */
    /* '<S17>:1:23' */
    u_VSP_x = ctrl_student_HIL_B.signal[9] - 0.0 / ctrl_student_HIL_norm
      (*(real_T (*)[3])&ctrl_student_HIL_B.signal[3]) * V1_s;
    if (ctrl_student_HIL_B.Memory1[2] > 1.0) {
      /* '<S17>:1:24' */
      /* '<S17>:1:25' */
      rtb_u = 1.0;
    }
  }

  if (rtb_u == 1.0) {
    /* '<S17>:1:29' */
    /* '<S17>:1:30' */
    u_VSP_x = -(ctrl_student_HIL_B.signal[9] - 0.0 / ctrl_student_HIL_norm
                (*(real_T (*)[3])&ctrl_student_HIL_B.signal[3]) * V1_s);
    if (ctrl_student_HIL_B.Memory1[2] < 0.0) {
      /* '<S17>:1:31' */
      /* '<S17>:1:32' */
      rtb_u = 0.0;
    }
  }

  ctrl_student_HIL_B.s_dot1 = u_VSP_x;
  ctrl_student_HIL_B.i = rtb_u;

  /* End of MATLAB Function: '<S1>/update law' */

  /* MATLAB Function: '<S1>/z1//z2' incorporates:
   *  SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport2'
   *  SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport3'
   */
  /* MATLAB Function 'DP-system/z1//z2': '<S18>:1' */
  /* '<S18>:1:4' */
  /* '<S18>:1:5' */
  /* '<S18>:1:7' */
  /* '<S18>:1:11' */
  /* '<S18>:1:13' */
  ctrl_student_HIL_B.z2[0] = ctrl_student_HIL_B.u_in - rtb_a_1[0];
  ctrl_student_HIL_B.z2[1] = ctrl_student_HIL_B.v_in - rtb_a_1[1];
  ctrl_student_HIL_B.z2[2] = ctrl_student_HIL_B.r_in - rtb_a_1[2];
  tmp_0[0] = cos(ctrl_student_HIL_B.psi_in);
  tmp_0[1] = -sin(ctrl_student_HIL_B.psi_in);
  tmp_0[2] = 0.0;
  tmp_0[3] = sin(ctrl_student_HIL_B.psi_in);
  tmp_0[4] = cos(ctrl_student_HIL_B.psi_in);
  tmp_0[5] = 0.0;
  tmp_0[6] = 0.0;
  tmp_0[7] = 0.0;
  tmp_0[8] = 1.0;
  V1_s = ctrl_student_HIL_B.x_in - ctrl_student_HIL_B.signal[0];
  u_VSP_x = ctrl_student_HIL_B.y_in - ctrl_student_HIL_B.signal[1];
  rtb_u = ctrl_student_HIL_B.psi_in - ctrl_student_HIL_B.signal[2];
  for (k = 0; k < 3; k++) {
    ctrl_student_HIL_B.z1[k] = 0.0;
    ctrl_student_HIL_B.z1[k] += tmp_0[k] * V1_s;
    ctrl_student_HIL_B.z1[k] += tmp_0[k + 3] * u_VSP_x;
    ctrl_student_HIL_B.z1[k] += tmp_0[k + 6] * rtb_u;
  }

  /* End of MATLAB Function: '<S1>/z1//z2' */

  /* Integrator: '<S3>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_b,
                       ctrl_student_HIL_B.ArrowRight);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator_CSTATE_h[0] =
        ctrl_student_HIL_P.Integrator_IC_d;
      ctrl_student_HIL_X.Integrator_CSTATE_h[1] =
        ctrl_student_HIL_P.Integrator_IC_d;
      ctrl_student_HIL_X.Integrator_CSTATE_h[2] =
        ctrl_student_HIL_P.Integrator_IC_d;
    }
  }

  ctrl_student_HIL_B.Integrator_e[0] = ctrl_student_HIL_X.Integrator_CSTATE_h[0];
  ctrl_student_HIL_B.Integrator_e[1] = ctrl_student_HIL_X.Integrator_CSTATE_h[1];
  ctrl_student_HIL_B.Integrator_e[2] = ctrl_student_HIL_X.Integrator_CSTATE_h[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    for (k = 0; k < 10; k++) {
      /* Memory: '<S8>/Memory' */
      ctrl_student_HIL_B.Memory_d[k] =
        ctrl_student_HIL_DW.Memory_PreviousInput_p[k];

      /* Memory: '<S8>/Memory1' */
      ctrl_student_HIL_B.Memory1_l[k] =
        ctrl_student_HIL_DW.Memory1_PreviousInput_m[k];
    }
  }

  /* MATLAB Function: '<S8>/MATLAB Function' */
  /* MATLAB Function 'signal dropout check /MATLAB Function': '<S41>:1' */
  /* '<S41>:1:2' */
  /* '<S41>:1:3' */
  for (k = 0; k < 10; k++) {
    ctrl_student_HIL_B.vecx[k] = ctrl_student_HIL_B.Memory_d[k];
    ctrl_student_HIL_B.vecy[k] = ctrl_student_HIL_B.Memory1_l[k];
  }

  /* '<S41>:1:4' */
  for (k = 0; k < 9; k++) {
    /* '<S41>:1:4' */
    /* '<S41>:1:5' */
    ctrl_student_HIL_B.vecx[k + 1] = ctrl_student_HIL_B.vecx[k];

    /* '<S41>:1:6' */
    ctrl_student_HIL_B.vecy[k + 1] = ctrl_student_HIL_B.vecy[k];

    /* '<S41>:1:4' */
  }

  /* '<S41>:1:8' */
  ctrl_student_HIL_B.vecx[0] = ctrl_student_HIL_B.Product[0];

  /* '<S41>:1:9' */
  ctrl_student_HIL_B.vecy[0] = ctrl_student_HIL_B.Product[1];

  /* '<S41>:1:11' */
  d = 1;
  for (k = 0; k <= 9; k += 2) {
    if ((ctrl_student_HIL_B.vecx[k] <= ctrl_student_HIL_B.vecx[k + 1]) ||
        rtIsNaN(ctrl_student_HIL_B.vecx[k + 1])) {
      idx[k] = k + 1;
      idx[k + 1] = k + 2;
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  b_i = 2;
  while (b_i < 10) {
    d_j = b_i << 1;
    b_qEnd = 1;
    for (k = 1 + b_i; k < 11; k = b_kEnd + b_i) {
      f_k = b_qEnd;
      khi = k - 1;
      b_kEnd = b_qEnd + d_j;
      if (b_kEnd > 11) {
        b_kEnd = 11;
      }

      nb = 0;
      kEnd = b_kEnd - b_qEnd;
      while (nb + 1 <= kEnd) {
        if ((ctrl_student_HIL_B.vecx[idx[f_k - 1] - 1] <=
             ctrl_student_HIL_B.vecx[idx[khi] - 1]) || rtIsNaN
            (ctrl_student_HIL_B.vecx[idx[khi] - 1])) {
          iwork[nb] = idx[f_k - 1];
          f_k++;
          if (f_k == k) {
            while (khi + 1 < b_kEnd) {
              nb++;
              iwork[nb] = idx[khi];
              khi++;
            }
          }
        } else {
          iwork[nb] = idx[khi];
          khi++;
          if (khi + 1 == b_kEnd) {
            while (f_k < k) {
              nb++;
              iwork[nb] = idx[f_k - 1];
              f_k++;
            }
          }
        }

        nb++;
      }

      for (b_pEnd = 0; b_pEnd + 1 <= kEnd; b_pEnd++) {
        idx[(b_qEnd + b_pEnd) - 1] = iwork[b_pEnd];
      }

      b_qEnd = b_kEnd;
    }

    b_i = d_j;
  }

  for (k = 0; k < 10; k++) {
    b_data[k] = ctrl_student_HIL_B.vecx[idx[k] - 1];
  }

  f_k = 0;
  while ((f_k + 1 <= 10) && rtIsInf(b_data[f_k]) && (b_data[f_k] < 0.0)) {
    f_k++;
  }

  k = f_k;
  f_k = 10;
  while ((f_k >= 1) && rtIsNaN(b_data[f_k - 1])) {
    f_k--;
  }

  b_i = 10 - f_k;
  while ((f_k >= 1) && rtIsInf(b_data[f_k - 1]) && (b_data[f_k - 1] > 0.0)) {
    f_k--;
  }

  nb = 0;
  if (k > 0) {
    nb = 1;
  }

  khi = (k + f_k) - k;
  while (k + 1 <= khi) {
    x = b_data[k];
    do {
      b_pEnd = 0;
      k++;
      if (k + 1 > khi) {
        b_pEnd = 1;
      } else {
        rtb_u = fabs(x / 2.0);
        if ((!rtIsInf(rtb_u)) && (!rtIsNaN(rtb_u))) {
          if (rtb_u <= 2.2250738585072014E-308) {
            rtb_u = 4.94065645841247E-324;
          } else {
            frexp(rtb_u, &exponent);
            rtb_u = ldexp(1.0, exponent - 53);
          }
        } else {
          rtb_u = (rtNaN);
        }

        if (!((fabs(x - b_data[k]) < rtb_u) || (rtIsInf(b_data[k]) && rtIsInf(x)
              && ((b_data[k] > 0.0) == (x > 0.0))))) {
          b_pEnd = 1;
        }
      }
    } while (b_pEnd == 0);

    nb++;
    b_data[nb - 1] = x;
  }

  if (10 - (f_k + b_i) > 0) {
    nb++;
  }

  for (k = 1; k <= b_i; k++) {
    nb++;
  }

  if (1 > nb) {
    nb = 0;
  }

  if (nb == 1) {
    /* '<S41>:1:12' */
    guard1 = true;
  } else {
    for (k = 0; k <= 9; k += 2) {
      if ((ctrl_student_HIL_B.vecy[k] <= ctrl_student_HIL_B.vecy[k + 1]) ||
          rtIsNaN(ctrl_student_HIL_B.vecy[k + 1])) {
        idx[k] = k + 1;
        idx[k + 1] = k + 2;
      } else {
        idx[k] = k + 2;
        idx[k + 1] = k + 1;
      }
    }

    b_i = 2;
    while (b_i < 10) {
      nb = b_i << 1;
      d_j = 1;
      for (b_pEnd = 1 + b_i; b_pEnd < 11; b_pEnd = b_qEnd + b_i) {
        k = d_j;
        f_k = b_pEnd - 1;
        b_qEnd = d_j + nb;
        if (b_qEnd > 11) {
          b_qEnd = 11;
        }

        khi = 0;
        b_kEnd = b_qEnd - d_j;
        while (khi + 1 <= b_kEnd) {
          if ((ctrl_student_HIL_B.vecy[idx[k - 1] - 1] <=
               ctrl_student_HIL_B.vecy[idx[f_k] - 1]) || rtIsNaN
              (ctrl_student_HIL_B.vecy[idx[f_k] - 1])) {
            iwork[khi] = idx[k - 1];
            k++;
            if (k == b_pEnd) {
              while (f_k + 1 < b_qEnd) {
                khi++;
                iwork[khi] = idx[f_k];
                f_k++;
              }
            }
          } else {
            iwork[khi] = idx[f_k];
            f_k++;
            if (f_k + 1 == b_qEnd) {
              while (k < b_pEnd) {
                khi++;
                iwork[khi] = idx[k - 1];
                k++;
              }
            }
          }

          khi++;
        }

        for (k = 0; k + 1 <= b_kEnd; k++) {
          idx[(d_j + k) - 1] = iwork[k];
        }

        d_j = b_qEnd;
      }

      b_i = nb;
    }

    for (k = 0; k < 10; k++) {
      b_data[k] = ctrl_student_HIL_B.vecy[idx[k] - 1];
    }

    k = 0;
    while ((k + 1 <= 10) && rtIsInf(b_data[k]) && (b_data[k] < 0.0)) {
      k++;
    }

    khi = k;
    k = 10;
    while ((k >= 1) && rtIsNaN(b_data[k - 1])) {
      k--;
    }

    b_i = 10 - k;
    while ((k >= 1) && rtIsInf(b_data[k - 1]) && (b_data[k - 1] > 0.0)) {
      k--;
    }

    nb = 0;
    if (khi > 0) {
      nb = 1;
    }

    f_k = (khi + k) - khi;
    while (khi + 1 <= f_k) {
      b_x = b_data[khi];
      do {
        b_pEnd = 0;
        khi++;
        if (khi + 1 > f_k) {
          b_pEnd = 1;
        } else {
          rtb_u = fabs(b_x / 2.0);
          if ((!rtIsInf(rtb_u)) && (!rtIsNaN(rtb_u))) {
            if (rtb_u <= 2.2250738585072014E-308) {
              rtb_u = 4.94065645841247E-324;
            } else {
              frexp(rtb_u, &b_exponent);
              rtb_u = ldexp(1.0, b_exponent - 53);
            }
          } else {
            rtb_u = (rtNaN);
          }

          if (!((fabs(b_x - b_data[khi]) < rtb_u) || (rtIsInf(b_data[khi]) &&
                rtIsInf(b_x) && ((b_data[khi] > 0.0) == (b_x > 0.0))))) {
            b_pEnd = 1;
          }
        }
      } while (b_pEnd == 0);

      nb++;
      b_data[nb - 1] = b_x;
    }

    if (10 - (k + b_i) > 0) {
      nb++;
    }

    for (k = 1; k <= b_i; k++) {
      nb++;
    }

    if (1 > nb) {
      nb = 0;
    }

    if (nb == 1) {
      /* '<S41>:1:12' */
      guard1 = true;
    } else {
      /* '<S41>:1:16' */
      rtb_y_idx_0 = ctrl_student_HIL_B.Product[0];
      rtb_y_idx_1 = ctrl_student_HIL_B.Product[1];
      rtb_y_idx_2 = ctrl_student_HIL_B.Product[2];
    }
  }

  if (guard1) {
    /* '<S41>:1:13' */
    rtb_y_idx_0 = ctrl_student_HIL_B.Integrator[0];
    rtb_y_idx_1 = ctrl_student_HIL_B.Integrator[1];
    rtb_y_idx_2 = ctrl_student_HIL_B.Integrator[2];

    /* '<S41>:1:14' */
    d = 0;
  }

  ctrl_student_HIL_B.d = d;

  /* End of MATLAB Function: '<S8>/MATLAB Function' */

  /* Sum: '<S3>/Sum1' */
  ctrl_student_HIL_B.Sum1[0] = rtb_y_idx_0 - ctrl_student_HIL_B.Integrator_e[0];
  ctrl_student_HIL_B.Sum1[1] = rtb_y_idx_1 - ctrl_student_HIL_B.Integrator_e[1];
  ctrl_student_HIL_B.Sum1[2] = rtb_y_idx_2 - ctrl_student_HIL_B.Integrator_e[2];

  /* Integrator: '<S3>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE_n,
                       ctrl_student_HIL_B.ArrowRight);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator1_CSTATE_k[0] =
        ctrl_student_HIL_P.Integrator1_IC_p;
      ctrl_student_HIL_X.Integrator1_CSTATE_k[1] =
        ctrl_student_HIL_P.Integrator1_IC_p;
      ctrl_student_HIL_X.Integrator1_CSTATE_k[2] =
        ctrl_student_HIL_P.Integrator1_IC_p;
    }
  }

  ctrl_student_HIL_B.Integrator1_c[0] = ctrl_student_HIL_X.Integrator1_CSTATE_k
    [0];
  ctrl_student_HIL_B.Integrator1_c[1] = ctrl_student_HIL_X.Integrator1_CSTATE_k
    [1];
  ctrl_student_HIL_B.Integrator1_c[2] = ctrl_student_HIL_X.Integrator1_CSTATE_k
    [2];

  /* MATLAB Function 'Observer/D': '<S28>:1' */
  /* '<S28>:1:3' */
  /* '<S28>:1:4' */
  /* '<S28>:1:5' */
  /* '<S28>:1:6' */
  /* '<S28>:1:7' */
  /* '<S28>:1:9' */

  /* MATLAB Function: '<S29>/MATLAB Function' */
  ctrl_student_HIL_MATLABFunction(ctrl_student_HIL_B.L11, ctrl_student_HIL_B.L12,
    ctrl_student_HIL_B.L13, &ctrl_student_HIL_B.sf_MATLABFunction_a);

  /* MATLAB Function: '<S30>/MATLAB Function' */
  ctrl_student_HIL_MATLABFunction(ctrl_student_HIL_B.L21, ctrl_student_HIL_B.L22,
    ctrl_student_HIL_B.L23, &ctrl_student_HIL_B.sf_MATLABFunction_hb);

  /* MATLAB Function: '<S31>/MATLAB Function' */
  ctrl_student_HIL_MATLABFunction(ctrl_student_HIL_B.L31, ctrl_student_HIL_B.L32,
    ctrl_student_HIL_B.L33, &ctrl_student_HIL_B.sf_MATLABFunction_an);

  /* MATLAB Function: '<S3>/Rotation matrix' */
  /* MATLAB Function 'Observer/Rotation matrix': '<S32>:1' */
  /* '<S32>:1:2' */
  rtb_R[0] = cos(rtb_y_idx_2);
  rtb_R[3] = -sin(rtb_y_idx_2);
  rtb_R[6] = 0.0;
  rtb_R[1] = sin(rtb_y_idx_2);
  rtb_R[4] = cos(rtb_y_idx_2);
  rtb_R[7] = 0.0;
  rtb_R[2] = 0.0;
  rtb_R[5] = 0.0;
  rtb_R[8] = 1.0;

  /* '<S32>:1:6' */
  for (k = 0; k < 3; k++) {
    S[3 * k] = rtb_R[k];
    S[1 + 3 * k] = rtb_R[k + 3];
    S[2 + 3 * k] = rtb_R[k + 6];
  }

  /* End of MATLAB Function: '<S3>/Rotation matrix' */

  /* Product: '<S3>/Product3' */
  for (k = 0; k < 3; k++) {
    ctrl_student_HIL_B.Product3[k] = 0.0;
    ctrl_student_HIL_B.Product3[k] +=
      ctrl_student_HIL_B.sf_MATLABFunction_an.y[k] * ctrl_student_HIL_B.Sum1[0];
    ctrl_student_HIL_B.Product3[k] +=
      ctrl_student_HIL_B.sf_MATLABFunction_an.y[k + 3] *
      ctrl_student_HIL_B.Sum1[1];
    ctrl_student_HIL_B.Product3[k] +=
      ctrl_student_HIL_B.sf_MATLABFunction_an.y[k + 6] *
      ctrl_student_HIL_B.Sum1[2];
  }

  /* End of Product: '<S3>/Product3' */

  /* Product: '<S3>/Product4' */
  for (k = 0; k < 3; k++) {
    tau[k] = S[k + 6] * rtb_Sum2[2] + (S[k + 3] * rtb_Sum2[1] + S[k] * rtb_Sum2
      [0]);
  }

  /* End of Product: '<S3>/Product4' */

  /* Product: '<S3>/Product5' */
  for (k = 0; k < 3; k++) {
    R_1[k] = ctrl_student_HIL_B.sf_MATLABFunction_hb.y[k + 6] *
      ctrl_student_HIL_B.Sum1[2] + (ctrl_student_HIL_B.sf_MATLABFunction_hb.y[k
      + 3] * ctrl_student_HIL_B.Sum1[1] +
      ctrl_student_HIL_B.sf_MATLABFunction_hb.y[k] * ctrl_student_HIL_B.Sum1[0]);
  }

  for (k = 0; k < 3; k++) {
    rtb_Sum2[k] = 0.0;
    rtb_Sum2[k] += S[k] * R_1[0];
    rtb_Sum2[k] += S[k + 3] * R_1[1];
    rtb_Sum2[k] += S[k + 6] * R_1[2];
  }

  /* End of Product: '<S3>/Product5' */

  /* Product: '<S3>/Product' incorporates:
   *  Sum: '<S3>/Sum'
   */
  for (k = 0; k < 3; k++) {
    R_1[k] = ctrl_student_HIL_B.sf_MATLABFunction_a.y[k + 6] *
      ctrl_student_HIL_B.Sum1[2] + (ctrl_student_HIL_B.sf_MATLABFunction_a.y[k +
      3] * ctrl_student_HIL_B.Sum1[1] +
      ctrl_student_HIL_B.sf_MATLABFunction_a.y[k] * ctrl_student_HIL_B.Sum1[0]);
  }

  /* End of Product: '<S3>/Product' */

  /* Product: '<S3>/Product1' incorporates:
   *  Sum: '<S3>/Sum'
   */
  for (k = 0; k < 3; k++) {
    R_0[k] = rtb_R[k + 6] * ctrl_student_HIL_B.Integrator1_c[2] + (rtb_R[k + 3] *
      ctrl_student_HIL_B.Integrator1_c[1] + rtb_R[k] *
      ctrl_student_HIL_B.Integrator1_c[0]);
  }

  /* End of Product: '<S3>/Product1' */

  /* Sum: '<S3>/Sum' */
  ctrl_student_HIL_B.Sum_j[0] = R_1[0] + R_0[0];
  ctrl_student_HIL_B.Sum_j[1] = R_1[1] + R_0[1];
  ctrl_student_HIL_B.Sum_j[2] = R_1[2] + R_0[2];

  /* MATLAB Function: '<S3>/D' */
  tmp_1[0] = (0.6555 - 0.354 * fabs(ctrl_student_HIL_B.Integrator1_c[0])) +
    ctrl_student_HIL_B.Integrator1_c[0] * ctrl_student_HIL_B.Integrator1_c[0] *
    3.787;
  tmp_1[3] = 0.0;
  tmp_1[6] = 0.0;
  tmp_1[1] = 0.0;
  tmp_1[4] = ((2.776 * fabs(ctrl_student_HIL_B.Integrator1_c[1]) + 1.33) +
              ctrl_student_HIL_B.Integrator1_c[1] *
              ctrl_student_HIL_B.Integrator1_c[1] * 64.91) + 0.805 * fabs
    (ctrl_student_HIL_B.Integrator1_c[2]);
  tmp_1[7] = (0.845 * fabs(ctrl_student_HIL_B.Integrator1_c[1]) + 7.25) + 3.45 *
    fabs(ctrl_student_HIL_B.Integrator1_c[2]);
  tmp_1[2] = 0.0;
  tmp_1[5] = 0.2088 * fabs(ctrl_student_HIL_B.Integrator1_c[1]) - 0.13 * fabs
    (ctrl_student_HIL_B.Integrator1_c[2]);
  tmp_1[8] = (1.9 - 0.08 * fabs(ctrl_student_HIL_B.Integrator1_c[1])) + 0.75 *
    fabs(ctrl_student_HIL_B.Integrator1_c[2]);

  /* Sum: '<S3>/Sum2' incorporates:
   *  Product: '<S3>/Product2'
   *  Sum: '<S3>/Sum3'
   */
  for (k = 0; k < 3; k++) {
    rtb_Sum2[k] = (tau[k] - ((tmp_1[k + 3] * ctrl_student_HIL_B.Integrator1_c[1]
      + tmp_1[k] * ctrl_student_HIL_B.Integrator1_c[0]) + tmp_1[k + 6] *
      ctrl_student_HIL_B.Integrator1_c[2])) + (rtb_Sum2[k] +
      ctrl_student_HIL_B.Sum_k[k]);
  }

  /* End of Sum: '<S3>/Sum2' */

  /* Gain: '<S3>/inv(M)' */
  for (k = 0; k < 3; k++) {
    ctrl_student_HIL_B.invM[k] = 0.0;
    ctrl_student_HIL_B.invM[k] += ctrl_student_HIL_P.invM_Gain[k] * rtb_Sum2[0];
    ctrl_student_HIL_B.invM[k] += ctrl_student_HIL_P.invM_Gain[k + 3] *
      rtb_Sum2[1];
    ctrl_student_HIL_B.invM[k] += ctrl_student_HIL_P.invM_Gain[k + 6] *
      rtb_Sum2[2];
  }

  /* End of Gain: '<S3>/inv(M)' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  int32_T i;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S9>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput = ctrl_student_HIL_B.switch_signal;

    /* Update for Memory: '<S20>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_B.count;

    /* Update for RandomNumber: '<S26>/White Noise' */
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S27>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_d
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S25>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) * ctrl_student_HIL_P.WhiteNoise_StdDev_g
      + ctrl_student_HIL_P.WhiteNoise_Mean_f;

    /* Update for Memory: '<S21>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_B.output[2];

    /* Update for Memory: '<S1>/Memory4' */
    ctrl_student_HIL_DW.Memory4_PreviousInput[0] = ctrl_student_HIL_B.z1[0];
    ctrl_student_HIL_DW.Memory4_PreviousInput[1] = ctrl_student_HIL_B.z1[1];
    ctrl_student_HIL_DW.Memory4_PreviousInput[2] = ctrl_student_HIL_B.z1[2];

    /* Update for Memory: '<S1>/Memory5' */
    ctrl_student_HIL_DW.Memory5_PreviousInput[0] = ctrl_student_HIL_B.z2[0];
    ctrl_student_HIL_DW.Memory5_PreviousInput[1] = ctrl_student_HIL_B.z2[1];
    ctrl_student_HIL_DW.Memory5_PreviousInput[2] = ctrl_student_HIL_B.z2[2];

    /* Update for Memory: '<S1>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput = ctrl_student_HIL_B.s_dot1;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S1>/Memory' */
    memcpy(&ctrl_student_HIL_DW.Memory_PreviousInput_l[0],
           &ctrl_student_HIL_B.eta_v[0], 11U * sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S1>/Memory3' */
    ctrl_student_HIL_DW.Memory3_PreviousInput[0] = ctrl_student_HIL_B.z1[0];
    ctrl_student_HIL_DW.Memory3_PreviousInput[1] = ctrl_student_HIL_B.z1[1];
    ctrl_student_HIL_DW.Memory3_PreviousInput[2] = ctrl_student_HIL_B.z1[2];

    /* Update for Memory: '<S1>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput[0] = ctrl_student_HIL_B.i;
    ctrl_student_HIL_DW.Memory1_PreviousInput[1] = ctrl_student_HIL_B.s_dot1;
    ctrl_student_HIL_DW.Memory1_PreviousInput[2] =
      ctrl_student_HIL_B.Integrator1;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    for (i = 0; i < 10; i++) {
      /* Update for Memory: '<S8>/Memory' */
      ctrl_student_HIL_DW.Memory_PreviousInput_p[i] = ctrl_student_HIL_B.vecx[i];

      /* Update for Memory: '<S8>/Memory1' */
      ctrl_student_HIL_DW.Memory1_PreviousInput_m[i] = ctrl_student_HIL_B.vecy[i];
    }
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_HIL_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_student_HIL_M->Timing.clockTick0)) {
    ++ctrl_student_HIL_M->Timing.clockTickH0;
  }

  ctrl_student_HIL_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_HIL_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_student_HIL_M->Timing.clockTick1)) {
      ++ctrl_student_HIL_M->Timing.clockTickH1;
    }

    ctrl_student_HIL_M->Timing.t[1] = ctrl_student_HIL_M->Timing.clockTick1 *
      ctrl_student_HIL_M->Timing.stepSize1 +
      ctrl_student_HIL_M->Timing.clockTickH1 *
      ctrl_student_HIL_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_HIL_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE[0] = ctrl_student_HIL_B.u_in;
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE[1] = ctrl_student_HIL_B.v_in;
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE[2] = ctrl_student_HIL_B.r_in;
  }

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE = ctrl_student_HIL_B.s_dot1;
  }

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator2_CSTATE[0] = ctrl_student_HIL_B.Product3[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator2_CSTATE[1] = ctrl_student_HIL_B.Product3[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator2_CSTATE[2] = ctrl_student_HIL_B.Product3[2];
  }

  /* Derivatives for Integrator: '<S3>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_h[0] = ctrl_student_HIL_B.Sum_j[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_h[1] = ctrl_student_HIL_B.Sum_j[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_h[2] = ctrl_student_HIL_B.Sum_j[2];
  }

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE_k[0] = ctrl_student_HIL_B.invM[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE_k[1] = ctrl_student_HIL_B.invM[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE_k[2] = ctrl_student_HIL_B.invM[2];
  }
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T t;
    int32_T i;
    real_T tmp;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE[0] = ctrl_student_HIL_P.Integrator_IC;
    ctrl_student_HIL_X.Integrator_CSTATE[1] = ctrl_student_HIL_P.Integrator_IC;
    ctrl_student_HIL_X.Integrator_CSTATE[2] = ctrl_student_HIL_P.Integrator_IC;

    /* InitializeConditions for Memory: '<S9>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput = ctrl_student_HIL_P.Memory_X0;

    /* InitializeConditions for Memory: '<S20>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S26>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed = tseed;
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S26>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S27>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_b);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_j = tseed;
    ctrl_student_HIL_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_d
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S27>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S25>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_l);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_c = tseed;
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) * ctrl_student_HIL_P.WhiteNoise_StdDev_g
      + ctrl_student_HIL_P.WhiteNoise_Mean_f;

    /* End of InitializeConditions for RandomNumber: '<S25>/White Noise' */

    /* InitializeConditions for Memory: '<S21>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_P.Hold_X0;

    /* InitializeConditions for Memory: '<S1>/Memory4' */
    ctrl_student_HIL_DW.Memory4_PreviousInput[0] =
      ctrl_student_HIL_P.Memory4_X0[0];
    ctrl_student_HIL_DW.Memory4_PreviousInput[1] =
      ctrl_student_HIL_P.Memory4_X0[1];
    ctrl_student_HIL_DW.Memory4_PreviousInput[2] =
      ctrl_student_HIL_P.Memory4_X0[2];

    /* InitializeConditions for Memory: '<S1>/Memory5' */
    ctrl_student_HIL_DW.Memory5_PreviousInput[0] =
      ctrl_student_HIL_P.Memory5_X0[0];
    ctrl_student_HIL_DW.Memory5_PreviousInput[1] =
      ctrl_student_HIL_P.Memory5_X0[1];
    ctrl_student_HIL_DW.Memory5_PreviousInput[2] =
      ctrl_student_HIL_P.Memory5_X0[2];

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput = ctrl_student_HIL_P.Memory2_X0;

    /* InitializeConditions for Integrator: '<S1>/Integrator1' */
    ctrl_student_HIL_X.Integrator1_CSTATE = ctrl_student_HIL_P.Integrator1_IC;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    for (i = 0; i < 11; i++) {
      ctrl_student_HIL_DW.Memory_PreviousInput_l[i] =
        ctrl_student_HIL_P.Memory_X0_j;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory' */
    /* InitializeConditions for Integrator: '<S3>/Integrator2' */
    ctrl_student_HIL_X.Integrator2_CSTATE[0] = ctrl_student_HIL_P.Integrator2_IC;
    ctrl_student_HIL_X.Integrator2_CSTATE[1] = ctrl_student_HIL_P.Integrator2_IC;
    ctrl_student_HIL_X.Integrator2_CSTATE[2] = ctrl_student_HIL_P.Integrator2_IC;

    /* InitializeConditions for Memory: '<S1>/Memory3' */
    ctrl_student_HIL_DW.Memory3_PreviousInput[0] = ctrl_student_HIL_P.Memory3_X0;
    ctrl_student_HIL_DW.Memory3_PreviousInput[1] = ctrl_student_HIL_P.Memory3_X0;
    ctrl_student_HIL_DW.Memory3_PreviousInput[2] = ctrl_student_HIL_P.Memory3_X0;

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput[0] =
      ctrl_student_HIL_P.Memory1_X0[0];
    ctrl_student_HIL_DW.Memory1_PreviousInput[1] =
      ctrl_student_HIL_P.Memory1_X0[1];
    ctrl_student_HIL_DW.Memory1_PreviousInput[2] =
      ctrl_student_HIL_P.Memory1_X0[2];

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_h[0] =
      ctrl_student_HIL_P.Integrator_IC_d;
    ctrl_student_HIL_X.Integrator_CSTATE_h[1] =
      ctrl_student_HIL_P.Integrator_IC_d;
    ctrl_student_HIL_X.Integrator_CSTATE_h[2] =
      ctrl_student_HIL_P.Integrator_IC_d;
    for (i = 0; i < 10; i++) {
      /* InitializeConditions for Memory: '<S8>/Memory' */
      ctrl_student_HIL_DW.Memory_PreviousInput_p[i] =
        ctrl_student_HIL_P.Memory_X0_d[i];

      /* InitializeConditions for Memory: '<S8>/Memory1' */
      ctrl_student_HIL_DW.Memory1_PreviousInput_m[i] =
        ctrl_student_HIL_P.Memory1_X0_e[i];
    }

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    ctrl_student_HIL_X.Integrator1_CSTATE_k[0] =
      ctrl_student_HIL_P.Integrator1_IC_p;
    ctrl_student_HIL_X.Integrator1_CSTATE_k[1] =
      ctrl_student_HIL_P.Integrator1_IC_p;
    ctrl_student_HIL_X.Integrator1_CSTATE_k[2] =
      ctrl_student_HIL_P.Integrator1_IC_p;
  }
}

/* Model terminate function */
void ctrl_student_HIL_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_student_HIL_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_HIL_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_student_HIL_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_HIL_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_HIL_T *ctrl_student_HIL(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_HIL_M, 0,
                sizeof(RT_MODEL_ctrl_student_HIL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_HIL_M->solverInfo,
                          &ctrl_student_HIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_HIL_M->solverInfo, &rtmGetTPtr(ctrl_student_HIL_M));
    rtsiSetStepSizePtr(&ctrl_student_HIL_M->solverInfo,
                       &ctrl_student_HIL_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_HIL_M->solverInfo,
                 &ctrl_student_HIL_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_HIL_M->solverInfo, (real_T **)
                         &ctrl_student_HIL_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_HIL_M->solverInfo,
      &ctrl_student_HIL_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_student_HIL_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_student_HIL_M)));
    rtsiSetRTModelPtr(&ctrl_student_HIL_M->solverInfo, ctrl_student_HIL_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_HIL_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_HIL_M->ModelData.intgData.y = ctrl_student_HIL_M->ModelData.odeY;
  ctrl_student_HIL_M->ModelData.intgData.f[0] =
    ctrl_student_HIL_M->ModelData.odeF[0];
  ctrl_student_HIL_M->ModelData.intgData.f[1] =
    ctrl_student_HIL_M->ModelData.odeF[1];
  ctrl_student_HIL_M->ModelData.intgData.f[2] =
    ctrl_student_HIL_M->ModelData.odeF[2];
  ctrl_student_HIL_M->ModelData.intgData.f[3] =
    ctrl_student_HIL_M->ModelData.odeF[3];
  ctrl_student_HIL_M->ModelData.contStates = ((real_T *) &ctrl_student_HIL_X);
  rtsiSetSolverData(&ctrl_student_HIL_M->solverInfo, (void *)
                    &ctrl_student_HIL_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_HIL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_HIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_HIL_M->Timing.sampleTimes =
      (&ctrl_student_HIL_M->Timing.sampleTimesArray[0]);
    ctrl_student_HIL_M->Timing.offsetTimes =
      (&ctrl_student_HIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_HIL_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_student_HIL_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_HIL_M, &ctrl_student_HIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_student_HIL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_HIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_HIL_M, -1);
  ctrl_student_HIL_M->Timing.stepSize0 = 0.01;
  ctrl_student_HIL_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_student_HIL_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_HIL_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_HIL_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_HIL_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_HIL_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_HIL_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
  }

  ctrl_student_HIL_M->solverInfoPtr = (&ctrl_student_HIL_M->solverInfo);
  ctrl_student_HIL_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_student_HIL_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_student_HIL_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_HIL_M->ModelData.blockIO = ((void *) &ctrl_student_HIL_B);
  (void) memset(((void *) &ctrl_student_HIL_B), 0,
                sizeof(B_ctrl_student_HIL_T));

  /* parameters */
  ctrl_student_HIL_M->ModelData.defaultParam = ((real_T *)&ctrl_student_HIL_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_HIL_X;
    ctrl_student_HIL_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_HIL_X, 0,
                  sizeof(X_ctrl_student_HIL_T));
  }

  /* states (dwork) */
  ctrl_student_HIL_M->ModelData.dwork = ((void *) &ctrl_student_HIL_DW);
  (void) memset((void *)&ctrl_student_HIL_DW, 0,
                sizeof(DW_ctrl_student_HIL_T));

  /* Initialize Sizes */
  ctrl_student_HIL_M->Sizes.numContStates = (13);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (179);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (86);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (515);/* Sum of parameter "widths" */
  return ctrl_student_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================*
 * This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_student_HIL
#include "model_info.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;
double NIRT_GetValueByDataType(void* ptr,int subindex, int type, int Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

long NIRT_SetValueByDataType(void* ptr,int subindex, double value, int type, int
  Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_student_HIL_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // joystick/L2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowDown, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowUp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowLeft, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.v_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // N_power
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.N_power, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // N_power_H
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.N_power_H, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Samp_freq
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Samp_freq, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // dead rec  switch/dead
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.dead, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Enable_noise
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Enable_noise, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // DP-system/Kd/Kd1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Kd1, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // DP-system/Kd/Kd2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Kd2, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // DP-system/Kd/Kd3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Kd3, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // Observer/L1/L12
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L12, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // Observer/L1/L11
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L11, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // Observer/L1/L13
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L13, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // Observer/L2/L21
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L21, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // Observer/L2/L22
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L22, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // Observer/L2/L23
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L23, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // Observer/L3/L31
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L31, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // Observer/L3/L32
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L32, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }

  // Observer/L3/L33
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L33, 0, data[index++], 41, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 35;
}

double ni_extout[61];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // joystick/u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);
  } else {
    index += 1;
  }

  // joystick/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // joystick/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // imu: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      0,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      1,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      2,17,0);
  } else {
    index += 3;
  }

  // guidance_switch: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.switch_signal,0,0,0);
  } else {
    index += 1;
  }

  // eta_noise_ut/psi_noise: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product,2,
      17,0);
  } else {
    index += 1;
  }

  // eta_noise_ut/x_noise: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product,0,
      17,0);
  } else {
    index += 1;
  }

  // eta_noise_ut/y_noise: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product,1,
      17,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_k,0,17,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_k,2,17,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_k,1,17,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant1_Value_h,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ArrowRight,
      0,0,0);
  } else {
    index += 1;
  }

  // DP-system/s: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,
      0,0,0);
  } else {
    index += 1;
  }

  // DP-system/D: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.D1,0,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.D1,1,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.D1,2,17,0);
  } else {
    index += 3;
  }

  // DP-system/z1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z11,0,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z11,1,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z11,2,17,0);
  } else {
    index += 3;
  }

  // DP-system/ma: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ma,0,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ma,1,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ma,2,17,0);
  } else {
    index += 3;
  }

  // DP-system/kdz: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Kdz,0,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Kdz,1,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Kdz,2,17,0);
  } else {
    index += 3;
  }

  // DP-system/etaaa: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor,0,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor,1,17,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor,2,17,0);
  } else {
    index += 3;
  }

  // DP-system/etav: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    for (count = 0; count < 11; count++) {
      ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.signal,
        count,20,0);
    }
  } else {
    index += 11;
  }

  // DP-system/uref : Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_ref_l,0,0,
      0);
  } else {
    index += 1;
  }

  // DP-system/sdot: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.s_dot1,0,0,
      0);
  } else {
    index += 1;
  }

  // DP-system/i: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.i,0,0,0);
  } else {
    index += 1;
  }

  // Observer/eta_bar_ut/x_bar: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,17,0);
  } else {
    index += 1;
  }

  // Observer/eta_bar_ut/y_bar: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,17,0);
  } else {
    index += 1;
  }

  // Observer/eta_bar_ut/psi_bar: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,17,0);
  } else {
    index += 1;
  }

  // Observer/eta_hat_ut/psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator_e,2,17,0);
  } else {
    index += 1;
  }

  // Observer/eta_hat_ut/x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator_e,0,17,0);
  } else {
    index += 1;
  }

  // Observer/eta_hat_ut/y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator_e,1,17,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_ut/r_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator1_c,2,17,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_ut/u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator1_c,0,17,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_ut/v_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator1_c,1,17,0);
  } else {
    index += 1;
  }

  // signal dropout check /lost: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.d,0,0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 61;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // joystick/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);

  // joystick/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);

  // joystick/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);

  // joystick/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,0,
    0);

  // joystick/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,0,
    0);

  // joystick/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,0,
    0);

  // joystick/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,0,
    0);

  // imu: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,0,
    17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,1,
    17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,2,
    17,0);

  // guidance_switch: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.switch_signal,
    0,0,0);

  // eta_noise_ut/psi_noise: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product,2,17,
    0);

  // eta_noise_ut/x_noise: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product,0,17,
    0);

  // eta_noise_ut/y_noise: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Product,1,17,
    0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_k,0,17,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_k,2,17,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_k,1,17,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value_h,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ArrowRight,0,
    0,0);

  // DP-system/s: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,0,
    0,0);

  // DP-system/D: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.D1,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.D1,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.D1,2,17,0);

  // DP-system/z1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z11,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z11,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z11,2,17,0);

  // DP-system/ma: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ma,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ma,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ma,2,17,0);

  // DP-system/kdz: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Kdz,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Kdz,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Kdz,2,17,0);

  // DP-system/etaaa: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor,0,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor,1,17,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtetaaaInpor,2,17,0);

  // DP-system/etav: Virtual Signal # 0
  for (count = 0; count < 11; count++) {
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.signal,
      count,20,0);
  }

  // DP-system/uref : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_ref_l,0,0,0);

  // DP-system/sdot: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.s_dot1,0,0,0);

  // DP-system/i: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.i,0,0,0);

  // Observer/eta_bar_ut/x_bar: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,17,0);

  // Observer/eta_bar_ut/y_bar: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,17,0);

  // Observer/eta_bar_ut/psi_bar: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,17,0);

  // Observer/eta_hat_ut/psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator_e,
    2,17,0);

  // Observer/eta_hat_ut/x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator_e,
    0,17,0);

  // Observer/eta_hat_ut/y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator_e,
    1,17,0);

  // Observer/nu_hat_ut/r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1_c,
    2,17,0);

  // Observer/nu_hat_ut/u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1_c,
    0,17,0);

  // Observer/nu_hat_ut/v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1_c,
    1,17,0);

  // signal dropout check /lost: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.d,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil/joystick/Gain/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain_Gain), 41, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/joystick/Gain1/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain1_Gain), 41, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil/joystick/True/Value", offsetof(P_ctrl_student_HIL_T,
    True_Value), 41, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC), 41, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/switch/Memory/X0", offsetof(P_ctrl_student_HIL_T,
    Memory_X0), 41, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/dead rec  switch/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value), 41, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/dead rec  switch/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, Constant1_Value), 41, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/Noise generator/Step size/Value", offsetof
    (P_ctrl_student_HIL_T, Stepsize_Value), 41, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/Noise generator/Downsamplesignal/counter/X0", offsetof
    (P_ctrl_student_HIL_T, counter_X0), 41, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean), 41, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev), 41, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed), 41, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_h), 41, 1, 2, 24, 0 },

  { 13,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_d), 41, 1, 2, 26, 0 },

  { 14,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_b), 41, 1, 2, 28, 0 },

  { 15,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_f), 41, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_g), 41, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_l), 41, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_student_HIL_T, Hold_X0), 41, 1, 2, 36, 0 },

  { 19, "ctrl_student_hil/DP-system/Memory4/X0", offsetof(P_ctrl_student_HIL_T,
    Memory4_X0), 28, 3, 2, 38, 0 },

  { 20, "ctrl_student_hil/DP-system/Memory5/X0", offsetof(P_ctrl_student_HIL_T,
    Memory5_X0), 28, 3, 2, 40, 0 },

  { 21, "ctrl_student_hil/DP-system/Memory2/X0", offsetof(P_ctrl_student_HIL_T,
    Memory2_X0), 41, 1, 2, 42, 0 },

  { 22, "ctrl_student_hil/DP-system/Gain/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain_Gain_l), 29, 3, 2, 44, 0 },

  { 23, "ctrl_student_hil/DP-system/Integrator1/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator1_IC), 41, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil/DP-system/Memory/X0", offsetof(P_ctrl_student_HIL_T,
    Memory_X0_j), 41, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/Observer/Integrator2/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator2_IC), 41, 1, 2, 50, 0 },

  { 26,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value), 41, 1, 2, 52, 0 },

  { 27,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_i), 41, 1, 2, 54, 0 },

  { 28,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_h), 41, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil/DP-system/Memory3/X0", offsetof(P_ctrl_student_HIL_T,
    Memory3_X0), 41, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil/DP-system/Memory1/X0", offsetof(P_ctrl_student_HIL_T,
    Memory1_X0), 29, 3, 2, 60, 0 },

  { 31, "ctrl_student_hil/Observer/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC_d), 41, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil/signal dropout check /Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0_d), 30, 10, 2, 64, 0 },

  { 33, "ctrl_student_hil/signal dropout check /Memory1/X0", offsetof
    (P_ctrl_student_HIL_T, Memory1_X0_e), 30, 10, 2, 66, 0 },

  { 34, "ctrl_student_hil/Observer/Integrator1/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator1_IC_p), 41, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/Observer/inv(M)/Gain", offsetof(P_ctrl_student_HIL_T,
    invM_Gain), 21, 9, 2, 70, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 36;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  3, 1,                                /* Parameter at index 19 */
  3, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 3,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 3,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 10,                               /* Parameter at index 32 */
  1, 10,                               /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  3, 3,                                /* Parameter at index 35 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 1, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2,
    0 },

  { 2, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4,
    0 },

  { 3, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    6, 0 },

  { 4, "ctrl_student_hil/x_in", 0, "", offsetof(B_ctrl_student_HIL_T, x_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/y_in", 0, "", offsetof(B_ctrl_student_HIL_T, y_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12,
    0 },

  { 7, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14,
    0 },

  { 8, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 20,
    0 },

  { 11, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 22,
    0 },

  { 12, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 24,
    0 },

  { 13, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    26, 0 },

  { 14, "ctrl_student_hil/Integrator", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T,
    Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil/Integrator", 0, "(1,2)", offsetof(B_ctrl_student_HIL_T,
    Integrator)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 30, 0 },

  { 16, "ctrl_student_hil/Integrator", 0, "(1,3)", offsetof(B_ctrl_student_HIL_T,
    Integrator)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 32, 0 },

  { 17, "ctrl_student_hil/switch/Memory", 0, "", offsetof(B_ctrl_student_HIL_T,
    Memory)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/psi_in", 0, "", offsetof(B_ctrl_student_HIL_T, psi_in)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 36, 0 },

  { 19, "ctrl_student_hil/r_in", 0, "", offsetof(B_ctrl_student_HIL_T, r_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 38, 0 },

  { 20, "ctrl_student_hil/u_in", 0, "", offsetof(B_ctrl_student_HIL_T, u_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/v_in", 0, "", offsetof(B_ctrl_student_HIL_T, v_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 42, 0 },

  { 22, "ctrl_student_hil/N_power", 0, "", offsetof(B_ctrl_student_HIL_T,
    N_power)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/N_power_H", 0, "", offsetof(B_ctrl_student_HIL_T,
    N_power_H)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil/Samp_freq", 0, "", offsetof(B_ctrl_student_HIL_T,
    Samp_freq)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/dead rec  switch/dead", 0, "", offsetof
    (B_ctrl_student_HIL_T, dead)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/Noise generator/Downsamplesignal/counter", 0, "",
    offsetof(B_ctrl_student_HIL_T, counter)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 52, 0 },

  { 27,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 54, 0 },

  { 28,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_e)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 56, 0 },

  { 29,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    60, 0 },

  { 31, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    62, 0 },

  { 32, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    64, 0 },

  { 33, "ctrl_student_hil/Enable_noise", 0, "", offsetof(B_ctrl_student_HIL_T,
    Enable_noise)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/Product", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T,
    Product)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/Product", 0, "(1,2)", offsetof(B_ctrl_student_HIL_T,
    Product)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil/Product", 0, "(1,3)", offsetof(B_ctrl_student_HIL_T,
    Product)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 72, 0 },

  { 37, "ctrl_student_hil/DP-system/Memory4", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory4)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 74,
    0 },

  { 38, "ctrl_student_hil/DP-system/Memory4", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory4)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 76,
    0 },

  { 39, "ctrl_student_hil/DP-system/Memory4", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory4)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 78,
    0 },

  { 40, "ctrl_student_hil/DP-system/Memory5", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory5)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 80,
    0 },

  { 41, "ctrl_student_hil/DP-system/Memory5", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory5)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 82,
    0 },

  { 42, "ctrl_student_hil/DP-system/Memory5", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory5)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 84,
    0 },

  { 43, "ctrl_student_hil/DP-system/Memory2", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 86,
    0 },

  { 44, "ctrl_student_hil/DP-system/Sum", 0, "", offsetof(B_ctrl_student_HIL_T,
    Sum)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 88, 0 },

  { 45, "ctrl_student_hil/DP-system/Integrator1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    90, 0 },

  { 46, "ctrl_student_hil/DP-system/Memory", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+0*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 92,
    0 },

  { 47, "ctrl_student_hil/DP-system/Memory", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+1*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 94,
    0 },

  { 48, "ctrl_student_hil/DP-system/Memory", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+2*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 96,
    0 },

  { 49, "ctrl_student_hil/DP-system/Memory", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+3*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 98,
    0 },

  { 50, "ctrl_student_hil/DP-system/Memory", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+4*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2,
    100, 0 },

  { 51, "ctrl_student_hil/DP-system/Memory", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+5*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2,
    102, 0 },

  { 52, "ctrl_student_hil/DP-system/Memory", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+6*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2,
    104, 0 },

  { 53, "ctrl_student_hil/DP-system/Memory", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+7*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2,
    106, 0 },

  { 54, "ctrl_student_hil/DP-system/Memory", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+8*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2,
    108, 0 },

  { 55, "ctrl_student_hil/DP-system/Memory", 0, "(1,10)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+9*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2,
    110, 0 },

  { 56, "ctrl_student_hil/DP-system/Memory", 0, "(1,11)", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+10*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2,
    112, 0 },

  { 57, "ctrl_student_hil/DP-system/Kd/Kd1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Kd1)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 114, 0
  },

  { 58, "ctrl_student_hil/DP-system/Kd/Kd2", 0, "", offsetof
    (B_ctrl_student_HIL_T, Kd2)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 116, 0
  },

  { 59, "ctrl_student_hil/DP-system/Kd/Kd3", 0, "", offsetof
    (B_ctrl_student_HIL_T, Kd3)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 118, 0
  },

  { 60, "ctrl_student_hil/Sum", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum_k)
    +0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 120, 0 },

  { 61, "ctrl_student_hil/Sum", 0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Sum_k)
    +1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 122, 0 },

  { 62, "ctrl_student_hil/Sum", 0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Sum_k)
    +2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 124, 0 },

  { 63, "ctrl_student_hil/DP-system/Memory3", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory3)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 126,
    0 },

  { 64, "ctrl_student_hil/DP-system/Memory3", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory3)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 128,
    0 },

  { 65, "ctrl_student_hil/DP-system/Memory3", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory3)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 130,
    0 },

  { 66, "ctrl_student_hil/DP-system/Memory1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 132,
    0 },

  { 67, "ctrl_student_hil/DP-system/Memory1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 134,
    0 },

  { 68, "ctrl_student_hil/DP-system/Memory1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 136,
    0 },

  { 69, "ctrl_student_hil/Observer/Integrator", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator_e)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    138, 0 },

  { 70, "ctrl_student_hil/Observer/Integrator", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator_e)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    140, 0 },

  { 71, "ctrl_student_hil/Observer/Integrator", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator_e)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    142, 0 },

  { 72, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+0*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    144, 0 },

  { 73, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+1*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    146, 0 },

  { 74, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+2*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    148, 0 },

  { 75, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+3*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    150, 0 },

  { 76, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+4*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    152, 0 },

  { 77, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+5*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    154, 0 },

  { 78, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+6*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    156, 0 },

  { 79, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+7*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    158, 0 },

  { 80, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+8*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    160, 0 },

  { 81, "ctrl_student_hil/signal dropout check /Memory", 0, "(1,10)", offsetof
    (B_ctrl_student_HIL_T, Memory_d)+9*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    162, 0 },

  { 82, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+0*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    164, 0 },

  { 83, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+1*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    166, 0 },

  { 84, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+2*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    168, 0 },

  { 85, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+3*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    170, 0 },

  { 86, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+4*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    172, 0 },

  { 87, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+5*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    174, 0 },

  { 88, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+6*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    176, 0 },

  { 89, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+7*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    178, 0 },

  { 90, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+8*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    180, 0 },

  { 91, "ctrl_student_hil/signal dropout check /Memory1", 0, "(1,10)", offsetof
    (B_ctrl_student_HIL_T, Memory1_l)+9*sizeof(real_T), BLOCKIO_SIG, 23, 1, 2,
    182, 0 },

  { 92, "ctrl_student_hil/Observer/Sum1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Sum1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 184, 0
  },

  { 93, "ctrl_student_hil/Observer/Sum1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Sum1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 186, 0
  },

  { 94, "ctrl_student_hil/Observer/Sum1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Sum1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 188, 0
  },

  { 95, "ctrl_student_hil/Observer/Integrator1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator1_c)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 190, 0 },

  { 96, "ctrl_student_hil/Observer/Integrator1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator1_c)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 192, 0 },

  { 97, "ctrl_student_hil/Observer/Integrator1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator1_c)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1,
    2, 194, 0 },

  { 98, "ctrl_student_hil/Observer/L1/L12", 0, "", offsetof(B_ctrl_student_HIL_T,
    L12)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 196, 0 },

  { 99, "ctrl_student_hil/Observer/L1/L11", 0, "", offsetof(B_ctrl_student_HIL_T,
    L11)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 198, 0 },

  { 100, "ctrl_student_hil/Observer/L1/L13", 0, "", offsetof
    (B_ctrl_student_HIL_T, L13)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 200, 0
  },

  { 101, "ctrl_student_hil/Observer/L2/L21", 0, "", offsetof
    (B_ctrl_student_HIL_T, L21)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 202, 0
  },

  { 102, "ctrl_student_hil/Observer/L2/L22", 0, "", offsetof
    (B_ctrl_student_HIL_T, L22)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 204, 0
  },

  { 103, "ctrl_student_hil/Observer/L2/L23", 0, "", offsetof
    (B_ctrl_student_HIL_T, L23)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 206, 0
  },

  { 104, "ctrl_student_hil/Observer/L3/L31", 0, "", offsetof
    (B_ctrl_student_HIL_T, L31)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 208, 0
  },

  { 105, "ctrl_student_hil/Observer/L3/L32", 0, "", offsetof
    (B_ctrl_student_HIL_T, L32)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 210, 0
  },

  { 106, "ctrl_student_hil/Observer/L3/L33", 0, "", offsetof
    (B_ctrl_student_HIL_T, L33)+0*sizeof(real_T), BLOCKIO_SIG, 41, 1, 2, 212, 0
  },

  { 107, "ctrl_student_hil/Observer/Product3", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Product3)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    214, 0 },

  { 108, "ctrl_student_hil/Observer/Product3", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Product3)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    216, 0 },

  { 109, "ctrl_student_hil/Observer/Product3", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Product3)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    218, 0 },

  { 110, "ctrl_student_hil/Observer/Sum", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Sum_j)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 220,
    0 },

  { 111, "ctrl_student_hil/Observer/Sum", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Sum_j)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 222,
    0 },

  { 112, "ctrl_student_hil/Observer/Sum", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Sum_j)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 224,
    0 },

  { 113, "ctrl_student_hil/Observer/inv(M)", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, invM)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 226, 0
  },

  { 114, "ctrl_student_hil/Observer/inv(M)", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, invM)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 228, 0
  },

  { 115, "ctrl_student_hil/Observer/inv(M)", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, invM)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 230, 0
  },

  { 116, "ctrl_student_hil/switch/Switch_function", 0, "switch_signal", offsetof
    (B_ctrl_student_HIL_T, switch_signal)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    232, 0 },

  { 117, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,1)", offsetof(B_ctrl_student_HIL_T, vecx)+0*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 234, 0 },

  { 118, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,2)", offsetof(B_ctrl_student_HIL_T, vecx)+1*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 236, 0 },

  { 119, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,3)", offsetof(B_ctrl_student_HIL_T, vecx)+2*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 238, 0 },

  { 120, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,4)", offsetof(B_ctrl_student_HIL_T, vecx)+3*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 240, 0 },

  { 121, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,5)", offsetof(B_ctrl_student_HIL_T, vecx)+4*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 242, 0 },

  { 122, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,6)", offsetof(B_ctrl_student_HIL_T, vecx)+5*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 244, 0 },

  { 123, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,7)", offsetof(B_ctrl_student_HIL_T, vecx)+6*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 246, 0 },

  { 124, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,8)", offsetof(B_ctrl_student_HIL_T, vecx)+7*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 248, 0 },

  { 125, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,9)", offsetof(B_ctrl_student_HIL_T, vecx)+8*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 250, 0 },

  { 126, "ctrl_student_hil/signal dropout check /MATLAB Function", 1,
    "vecx(1,10)", offsetof(B_ctrl_student_HIL_T, vecx)+9*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 252, 0 },

  { 127, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,1)", offsetof(B_ctrl_student_HIL_T, vecy)+0*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 254, 0 },

  { 128, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,2)", offsetof(B_ctrl_student_HIL_T, vecy)+1*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 256, 0 },

  { 129, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,3)", offsetof(B_ctrl_student_HIL_T, vecy)+2*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 258, 0 },

  { 130, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,4)", offsetof(B_ctrl_student_HIL_T, vecy)+3*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 260, 0 },

  { 131, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,5)", offsetof(B_ctrl_student_HIL_T, vecy)+4*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 262, 0 },

  { 132, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,6)", offsetof(B_ctrl_student_HIL_T, vecy)+5*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 264, 0 },

  { 133, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,7)", offsetof(B_ctrl_student_HIL_T, vecy)+6*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 266, 0 },

  { 134, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,8)", offsetof(B_ctrl_student_HIL_T, vecy)+7*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 268, 0 },

  { 135, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,9)", offsetof(B_ctrl_student_HIL_T, vecy)+8*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 270, 0 },

  { 136, "ctrl_student_hil/signal dropout check /MATLAB Function", 2,
    "vecy(1,10)", offsetof(B_ctrl_student_HIL_T, vecy)+9*sizeof(real_T),
    BLOCKIO_SIG, 23, 1, 2, 272, 0 },

  { 137, "ctrl_student_hil/signal dropout check /MATLAB Function", 3, "d",
    offsetof(B_ctrl_student_HIL_T, d)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    274, 0 },

  { 138, "ctrl_student_hil/joystick/Thrust allocation", 0, "u_BT", offsetof
    (B_ctrl_student_HIL_T, u_BT)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 276, 0
  },

  { 139, "ctrl_student_hil/joystick/Thrust allocation", 1, "u_VSP", offsetof
    (B_ctrl_student_HIL_T, u_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 278, 0
  },

  { 140, "ctrl_student_hil/joystick/Thrust allocation", 2, "alpha_VSP", offsetof
    (B_ctrl_student_HIL_T, alpha_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    280, 0 },

  { 141, "ctrl_student_hil/joystick/Thrust allocation", 3, "omega_VSP", offsetof
    (B_ctrl_student_HIL_T, omega_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    282, 0 },

  { 142, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,1)", offsetof(B_ctrl_student_HIL_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 284, 0 },

  { 143, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,2)", offsetof(B_ctrl_student_HIL_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 286, 0 },

  { 144, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,3)", offsetof(B_ctrl_student_HIL_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 288, 0 },

  { 145, "ctrl_student_hil/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_student_HIL_T, count)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 290, 0 },

  { 146, "ctrl_student_hil/DP-system/z1//z2", 0, "z1(1,1)", offsetof
    (B_ctrl_student_HIL_T, z1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 292, 0 },

  { 147, "ctrl_student_hil/DP-system/z1//z2", 0, "z1(1,2)", offsetof
    (B_ctrl_student_HIL_T, z1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 294, 0 },

  { 148, "ctrl_student_hil/DP-system/z1//z2", 0, "z1(1,3)", offsetof
    (B_ctrl_student_HIL_T, z1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 296, 0 },

  { 149, "ctrl_student_hil/DP-system/z1//z2", 1, "z2(1,1)", offsetof
    (B_ctrl_student_HIL_T, z2)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 298, 0 },

  { 150, "ctrl_student_hil/DP-system/z1//z2", 1, "z2(1,2)", offsetof
    (B_ctrl_student_HIL_T, z2)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 300, 0 },

  { 151, "ctrl_student_hil/DP-system/z1//z2", 1, "z2(1,3)", offsetof
    (B_ctrl_student_HIL_T, z2)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 302, 0 },

  { 152, "ctrl_student_hil/DP-system/update law", 0, "s_dot1", offsetof
    (B_ctrl_student_HIL_T, s_dot1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 304,
    0 },

  { 153, "ctrl_student_hil/DP-system/update law", 1, "i", offsetof
    (B_ctrl_student_HIL_T, i)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 306, 0 },

  { 154, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,1)", offsetof
    (B_ctrl_student_HIL_T, signal)+0*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 308,
    0 },

  { 155, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,2)", offsetof
    (B_ctrl_student_HIL_T, signal)+1*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 310,
    0 },

  { 156, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,3)", offsetof
    (B_ctrl_student_HIL_T, signal)+2*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 312,
    0 },

  { 157, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,4)", offsetof
    (B_ctrl_student_HIL_T, signal)+3*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 314,
    0 },

  { 158, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,5)", offsetof
    (B_ctrl_student_HIL_T, signal)+4*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 316,
    0 },

  { 159, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,6)", offsetof
    (B_ctrl_student_HIL_T, signal)+5*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 318,
    0 },

  { 160, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,7)", offsetof
    (B_ctrl_student_HIL_T, signal)+6*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 320,
    0 },

  { 161, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,8)", offsetof
    (B_ctrl_student_HIL_T, signal)+7*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 322,
    0 },

  { 162, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,9)", offsetof
    (B_ctrl_student_HIL_T, signal)+8*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 324,
    0 },

  { 163, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,10)", offsetof
    (B_ctrl_student_HIL_T, signal)+9*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 326,
    0 },

  { 164, "ctrl_student_hil/DP-system/signal switch", 0, "signal(1,11)", offsetof
    (B_ctrl_student_HIL_T, signal)+10*sizeof(real_T), BLOCKIO_SIG, 20, 1, 2, 328,
    0 },

  { 165, "ctrl_student_hil/DP-system/inputs", 2, "U_ref_l", offsetof
    (B_ctrl_student_HIL_T, U_ref_l)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 330,
    0 },

  { 166, "ctrl_student_hil/DP-system/controller", 2, "D1(1,1)", offsetof
    (B_ctrl_student_HIL_T, D1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 332, 0 },

  { 167, "ctrl_student_hil/DP-system/controller", 2, "D1(1,2)", offsetof
    (B_ctrl_student_HIL_T, D1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 334, 0 },

  { 168, "ctrl_student_hil/DP-system/controller", 2, "D1(1,3)", offsetof
    (B_ctrl_student_HIL_T, D1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 336, 0 },

  { 169, "ctrl_student_hil/DP-system/controller", 3, "z11(1,1)", offsetof
    (B_ctrl_student_HIL_T, z11)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 338, 0
  },

  { 170, "ctrl_student_hil/DP-system/controller", 3, "z11(1,2)", offsetof
    (B_ctrl_student_HIL_T, z11)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 340, 0
  },

  { 171, "ctrl_student_hil/DP-system/controller", 3, "z11(1,3)", offsetof
    (B_ctrl_student_HIL_T, z11)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 342, 0
  },

  { 172, "ctrl_student_hil/DP-system/controller", 4, "ma(1,1)", offsetof
    (B_ctrl_student_HIL_T, ma)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 344, 0 },

  { 173, "ctrl_student_hil/DP-system/controller", 4, "ma(1,2)", offsetof
    (B_ctrl_student_HIL_T, ma)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 346, 0 },

  { 174, "ctrl_student_hil/DP-system/controller", 4, "ma(1,3)", offsetof
    (B_ctrl_student_HIL_T, ma)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 348, 0 },

  { 175, "ctrl_student_hil/DP-system/controller", 5, "Kdz(1,1)", offsetof
    (B_ctrl_student_HIL_T, Kdz)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 350, 0
  },

  { 176, "ctrl_student_hil/DP-system/controller", 5, "Kdz(1,2)", offsetof
    (B_ctrl_student_HIL_T, Kdz)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 352, 0
  },

  { 177, "ctrl_student_hil/DP-system/controller", 5, "Kdz(1,3)", offsetof
    (B_ctrl_student_HIL_T, Kdz)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 354, 0
  },

  { 178, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,1)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+0*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 356, 0 },

  { 179, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,2)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+1*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 358, 0 },

  { 180, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,3)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+2*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 360, 0 },

  { 181, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,4)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+3*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 362, 0 },

  { 182, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,5)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+4*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 364, 0 },

  { 183, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,6)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+5*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 366, 0 },

  { 184, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,7)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+6*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 368, 0 },

  { 185, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,8)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+7*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 370, 0 },

  { 186, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,9)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+8*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 372, 0 },

  { 187, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,10)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+9*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 374, 0 },

  { 188, "ctrl_student_hil/DP-system/Ellipsoidal path", 0, "eta_v(1,11)",
    offsetof(B_ctrl_student_HIL_T, eta_v)+10*sizeof(real_T), BLOCKIO_SIG, 20, 1,
    2, 376, 0 },

  { 189, "ctrl_student_hil/Observer/L3/MATLAB Function", 0, "y(1,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_an.y)+0*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 378, 0 },

  { 190, "ctrl_student_hil/Observer/L3/MATLAB Function", 0, "y(2,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_an.y)+1*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 380, 0 },

  { 191, "ctrl_student_hil/Observer/L3/MATLAB Function", 0, "y(3,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_an.y)+2*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 382, 0 },

  { 192, "ctrl_student_hil/Observer/L3/MATLAB Function", 0, "y(1,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_an.y)+3*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 384, 0 },

  { 193, "ctrl_student_hil/Observer/L3/MATLAB Function", 0, "y(2,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_an.y)+4*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 386, 0 },

  { 194, "ctrl_student_hil/Observer/L3/MATLAB Function", 0, "y(3,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_an.y)+5*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 388, 0 },

  { 195, "ctrl_student_hil/Observer/L3/MATLAB Function", 0, "y(1,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_an.y)+6*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 390, 0 },

  { 196, "ctrl_student_hil/Observer/L3/MATLAB Function", 0, "y(2,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_an.y)+7*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 392, 0 },

  { 197, "ctrl_student_hil/Observer/L3/MATLAB Function", 0, "y(3,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_an.y)+8*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 394, 0 },

  { 198, "ctrl_student_hil/Observer/L2/MATLAB Function", 0, "y(1,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_hb.y)+0*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 396, 0 },

  { 199, "ctrl_student_hil/Observer/L2/MATLAB Function", 0, "y(2,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_hb.y)+1*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 398, 0 },

  { 200, "ctrl_student_hil/Observer/L2/MATLAB Function", 0, "y(3,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_hb.y)+2*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 400, 0 },

  { 201, "ctrl_student_hil/Observer/L2/MATLAB Function", 0, "y(1,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_hb.y)+3*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 402, 0 },

  { 202, "ctrl_student_hil/Observer/L2/MATLAB Function", 0, "y(2,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_hb.y)+4*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 404, 0 },

  { 203, "ctrl_student_hil/Observer/L2/MATLAB Function", 0, "y(3,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_hb.y)+5*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 406, 0 },

  { 204, "ctrl_student_hil/Observer/L2/MATLAB Function", 0, "y(1,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_hb.y)+6*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 408, 0 },

  { 205, "ctrl_student_hil/Observer/L2/MATLAB Function", 0, "y(2,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_hb.y)+7*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 410, 0 },

  { 206, "ctrl_student_hil/Observer/L2/MATLAB Function", 0, "y(3,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_hb.y)+8*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 412, 0 },

  { 207, "ctrl_student_hil/Observer/L1/MATLAB Function", 0, "y(1,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_a.y)+0*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 414, 0 },

  { 208, "ctrl_student_hil/Observer/L1/MATLAB Function", 0, "y(2,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_a.y)+1*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 416, 0 },

  { 209, "ctrl_student_hil/Observer/L1/MATLAB Function", 0, "y(3,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_a.y)+2*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 418, 0 },

  { 210, "ctrl_student_hil/Observer/L1/MATLAB Function", 0, "y(1,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_a.y)+3*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 420, 0 },

  { 211, "ctrl_student_hil/Observer/L1/MATLAB Function", 0, "y(2,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_a.y)+4*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 422, 0 },

  { 212, "ctrl_student_hil/Observer/L1/MATLAB Function", 0, "y(3,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_a.y)+5*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 424, 0 },

  { 213, "ctrl_student_hil/Observer/L1/MATLAB Function", 0, "y(1,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_a.y)+6*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 426, 0 },

  { 214, "ctrl_student_hil/Observer/L1/MATLAB Function", 0, "y(2,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_a.y)+7*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 428, 0 },

  { 215, "ctrl_student_hil/Observer/L1/MATLAB Function", 0, "y(3,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_a.y)+8*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 430, 0 },

  { 216, "ctrl_student_hil/DP-system/Kd/MATLAB Function", 0, "y(1,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_h.y)+0*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 432, 0 },

  { 217, "ctrl_student_hil/DP-system/Kd/MATLAB Function", 0, "y(2,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_h.y)+1*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 434, 0 },

  { 218, "ctrl_student_hil/DP-system/Kd/MATLAB Function", 0, "y(3,1)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_h.y)+2*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 436, 0 },

  { 219, "ctrl_student_hil/DP-system/Kd/MATLAB Function", 0, "y(1,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_h.y)+3*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 438, 0 },

  { 220, "ctrl_student_hil/DP-system/Kd/MATLAB Function", 0, "y(2,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_h.y)+4*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 440, 0 },

  { 221, "ctrl_student_hil/DP-system/Kd/MATLAB Function", 0, "y(3,2)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_h.y)+5*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 442, 0 },

  { 222, "ctrl_student_hil/DP-system/Kd/MATLAB Function", 0, "y(1,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_h.y)+6*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 444, 0 },

  { 223, "ctrl_student_hil/DP-system/Kd/MATLAB Function", 0, "y(2,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_h.y)+7*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 446, 0 },

  { 224, "ctrl_student_hil/DP-system/Kd/MATLAB Function", 0, "y(3,3)", offsetof
    (B_ctrl_student_HIL_T, sf_MATLABFunction_h.y)+8*sizeof(real_T), BLOCKIO_SIG,
    21, 1, 2, 448, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 225;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 74;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "joystick/L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 1, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 2, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 3, "joystick/R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 4, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 5, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 6, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 7, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 8, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 9, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 10, "joystick/ArrowDown", 0, EXT_IN, 1, 1, 1 },

  { 11, "joystick/ArrowUp", 0, EXT_IN, 1, 1, 1 },

  { 12, "joystick/ArrowLeft", 0, EXT_IN, 1, 1, 1 },

  { 13, "joystick/ArrowRight", 0, EXT_IN, 1, 1, 1 },

  { 14, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 15, "r_in", 0, EXT_IN, 1, 1, 1 },

  { 16, "u_in", 0, EXT_IN, 1, 1, 1 },

  { 17, "v_in", 0, EXT_IN, 1, 1, 1 },

  { 18, "N_power", 0, EXT_IN, 1, 1, 1 },

  { 19, "N_power_H", 0, EXT_IN, 1, 1, 1 },

  { 20, "Samp_freq", 0, EXT_IN, 1, 1, 1 },

  { 21, "dead rec  switch/dead", 0, EXT_IN, 1, 1, 1 },

  { 22, "Enable_noise", 0, EXT_IN, 1, 1, 1 },

  { 23, "DP-system/Kd/Kd1", 0, EXT_IN, 1, 1, 1 },

  { 24, "DP-system/Kd/Kd2", 0, EXT_IN, 1, 1, 1 },

  { 25, "DP-system/Kd/Kd3", 0, EXT_IN, 1, 1, 1 },

  { 26, "Observer/L1/L12", 0, EXT_IN, 1, 1, 1 },

  { 27, "Observer/L1/L11", 0, EXT_IN, 1, 1, 1 },

  { 28, "Observer/L1/L13", 0, EXT_IN, 1, 1, 1 },

  { 29, "Observer/L2/L21", 0, EXT_IN, 1, 1, 1 },

  { 30, "Observer/L2/L22", 0, EXT_IN, 1, 1, 1 },

  { 31, "Observer/L2/L23", 0, EXT_IN, 1, 1, 1 },

  { 32, "Observer/L3/L31", 0, EXT_IN, 1, 1, 1 },

  { 33, "Observer/L3/L32", 0, EXT_IN, 1, 1, 1 },

  { 34, "Observer/L3/L33", 0, EXT_IN, 1, 1, 1 },

  { 0, "joystick/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 1, "joystick/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 2, "joystick/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 3, "joystick/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 4, "joystick/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 5, "joystick/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 6, "joystick/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 7, "imu", 0, EXT_OUT, 3, 3, 1 },

  { 8, "guidance_switch", 0, EXT_OUT, 1, 1, 1 },

  { 9, "eta_noise_ut/psi_noise", 0, EXT_OUT, 1, 1, 1 },

  { 10, "eta_noise_ut/x_noise", 0, EXT_OUT, 1, 1, 1 },

  { 11, "eta_noise_ut/y_noise", 0, EXT_OUT, 1, 1, 1 },

  { 12, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 13, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 14, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 15, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 16, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 17, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 18, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 0,
    EXT_OUT, 1, 1, 1 },

  { 19, "DP-system/s", 0, EXT_OUT, 1, 1, 1 },

  { 20, "DP-system/D", 0, EXT_OUT, 3, 3, 1 },

  { 21, "DP-system/z1", 0, EXT_OUT, 3, 3, 1 },

  { 22, "DP-system/ma", 0, EXT_OUT, 3, 3, 1 },

  { 23, "DP-system/kdz", 0, EXT_OUT, 3, 3, 1 },

  { 24, "DP-system/etaaa", 0, EXT_OUT, 3, 3, 1 },

  { 25, "DP-system/etav", 0, EXT_OUT, 11, 11, 1 },

  { 26, "DP-system/uref ", 0, EXT_OUT, 1, 1, 1 },

  { 27, "DP-system/sdot", 0, EXT_OUT, 1, 1, 1 },

  { 28, "DP-system/i", 0, EXT_OUT, 1, 1, 1 },

  { 29, "Observer/eta_bar_ut/x_bar", 0, EXT_OUT, 1, 1, 1 },

  { 30, "Observer/eta_bar_ut/y_bar", 0, EXT_OUT, 1, 1, 1 },

  { 31, "Observer/eta_bar_ut/psi_bar", 0, EXT_OUT, 1, 1, 1 },

  { 32, "Observer/eta_hat_ut/psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 33, "Observer/eta_hat_ut/x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 34, "Observer/eta_hat_ut/y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 35, "Observer/nu_hat_ut/r_hat", 0, EXT_OUT, 1, 1, 1 },

  { 36, "Observer/nu_hat_ut/u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 37, "Observer/nu_hat_ut/v_hat", 0, EXT_OUT, 1, 1, 1 },

  { 38, "signal dropout check /lost", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_student_hil";
static char* NI_CompiledModelVersion = "1.465";
static char* NI_CompiledModelDateTime = "Mon Mar 27 12:49:36 2017";
static char* NI_builder DataSection(".NIVS.builder") =
  "NI VeriStand 2014.0.0.82 (2014) RTW Build";
static char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2014.0.0.82";

/* Model Information Query fucntions for MATLAB
 */
/* dll information
 * Returns 1 for RTW DLL
 *		   2 for AutoCode DLL
 */
DLL_EXPORT long NIRT_GetBuildInfo(char* detail, long* len)
{
  // There are no console properties to set for VxWorks, because the console is simply serial output data.
  // Just do printf for VxWorks and ignore all console properties.
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  printf("\n*******************************************************************************\n");
  printf("%s\nModel Name: %s\nModel Version: %s\nCompiled On: %s",
         NI_builder, NI_CompiledModelName, NI_CompiledModelVersion,
         NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len>=(long)strlen(NI_builder))
    *len = strlen(NI_builder)+1;
  strncpy(detail,NI_builder,*len);
  return 1;
}

/*
 * Distinction between Index and ID:
 * Index is a long datatype (used to set parameter/probe signals).
 * ID on the other hand is a string (tag "2-3-2-12" for MatrixX/ Full path "f14/Gain/Gain" for Matlab).
 * If Bus support is added then signal path from the block name is added to the end of the port number (Model/subsystem1:1/X/A)
 * where X/A is the path from the block
 * NOTE: ID may not be the same as Paramname or signal name.
 */

/* signal information
   NOTE: signal ID == the blockname and port that feeds it extended with /sinalname.

   The port number in Simulation Environment is 1 indexed.. but on RT is 0 indexed.
 */
DLL_EXPORT long NIRT_GetSignalSpec(long* sidx, char* ID, long* ID_len, char
  * blkname, long *bnlen,
  long *portnum, char* signame, long *snlen, long *dattype, long* dims, long
  * numdim)
{
  long sigidx = *sidx;
  int i = 0;
  char *IDblk = 0;
  int IDport = 0;
  if (sigidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // parse ID into blkname and port
      i = strrchr(ID, ':') - ID;

      // malformed ID
      if (i<=0)
        return NI_SigListSize;

      //ID[i] = 0;
      IDblk = ID;
      IDport = atoi(ID+i+1);

      // lookup the table for matching ID
      // Bus support
      for (i=0;i<NI_SigListSize;i++) {
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname)+ 11, sizeof(char));

        //sprintf(tempID,"%s%s%s",NI_SigList[i].blockname,"/",NI_SigList[i].signalname);
        if (strlen(NI_SigList[i].signalname)>0)
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        else
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1))
          break;
        free(tempID);
      }

      if (i<NI_SigListSize)
        sigidx = *sidx = i;
      else
        return NI_SigListSize;
    } else                             // no index or ID specified.
      return NI_SigListSize;
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID) {
      // no need for return string to be null terminated!
      // 11 to accomodate ':','/', port number and null character
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0)
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      else
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      if ((long)strlen(tempID)<*ID_len)
        *ID_len = strlen(tempID);
      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].blockname)<*bnlen)
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].signalname)<*snlen)
        *snlen = strlen(NI_SigList[sigidx].signalname);
      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum)
      *portnum = NI_SigList[sigidx].portno;
    if (dattype)
      *dattype = NI_SigList[sigidx].datatype;
    if (dims && *numdim>=NI_SigList[sigidx].numofdims) {
      *numdim = NI_SigList[sigidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_SigListSize;
}

/*
 * Get parameter indices
 */
DLL_EXPORT long NIRT_GetParameterIndices(long* indices, long* len)
{
  long i;
  for (i=0;i<NI_ParamListSize && i<*len;i++)
    indices[i] = NI_ParamList[i].idx;
  *len = i;
  return NI_OK;
}

/*
 * parameter information
 *
 * if *pidx < 0, Lookup parameter by ID if ID != NULL.
 * if ID == NULL or no matching ID found, return number of parameters.
 *
 * plen  -> size of path
 * pnlen -> size of paramname
 * numdim -> size of dims array
 */
DLL_EXPORT long NIRT_GetParameterSpec(long* pidx, char* ID, long* ID_len, char
  * paramname, long *pnlen,
  long *dattype, long* dims, long* numdim)
{
  int i= 0;
  int paramidx = *pidx;
  if (paramidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // lookup the table for matching ID
      for (i=0;i<NI_ParamListSize;i++) {
        if (!strcmp(ID,NI_ParamList[i].paramname))
          break;
      }

      if (i<NI_ParamListSize)
        paramidx = *pidx = i;
      else
        return NI_ParamListSize;
    } else                             // no index or ID specified.
      return NI_ParamListSize;
  }

  if (paramidx>=0 && paramidx<NI_ParamListSize) {
    if (ID) {
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*ID_len)
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*pnlen)
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype)
      *dattype = NI_ParamList[paramidx].datatype;
    if (!numdim)
      return 0;
    if (*numdim>=NI_ParamList[paramidx].numofdims) {
      *numdim = NI_ParamList[paramidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_ParamListSize;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetParameterExpression(long paramidx, char* expression,
  long *exp_len)
{
  return 0;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetVariableName(long varidx, char* variable_name, long
  *var_len)
{
  return 0;
}

/*
 * NIRT_GetExtIOSpec
 *
 * Inputs:
 *		index: index of the task
 * Outputs:
 *		idx:  idx of the IO.
 *		name: Name of the IO block
 *		tid: task id
 *		type: EXT_IN or EXT_OUT
 *		dimX: size of 0th dimension
 *		dimY: size of 1th dimension
 * Return value: 0 if no error. (if index == -1, return number of tasks in the model)
 */
DLL_EXPORT long NIRT_GetExtIOSpec(long index, long *idx, char* name, long* tid,
  long *type, long *dims, long* numdims)
{
  if (index==-1)
    return NI_ExtListSize;
  if (idx)
    *idx = NI_ExtList[index].idx;
  if (name) {
    int sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid)
    *tid = NI_ExtList[index].TID;
  if (type)
    *type = NI_ExtList[index].type;
  if (numdims && dims) {
    if (*numdims>=2) {
      *numdims= 2;
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    } else
      *numdims= 0;
  }

  return 0;
}

/* Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG */
static long NI_ProbeOneSignal(long idx, double *value, long len, long *count,
  long vOffset, long vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (int)
    NI_SigList[idx].addr;
  long subindex = (vLength == -1) ? 0 : vOffset;
  long sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength + vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
}

/*
 * NIRT_ProbeSignals
 *
 * Inputs:
 *		sigindices: indeces of signals
 *		numsigs: number of signals
 *		len: total length of all signals
 * Outputs:
 *		value: probed signal data
 *		len: length of data (may vary from input)
 * Return value: equal to len
 */
DLL_EXPORT long NIRT_ProbeSignals(long* sigindices, long numsigs,
  double* value, long* len)
{
  int i, j, idx;
  long count = 0;
  if (!SITexportglobals.inCriticalSection)
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0)
      break;
    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        for (j = 0; j < 2; j++) {
          long vidx = NI_VirtualBlockSources[NI_SigList[idx].addr][j];
          long voff = NI_VirtualBlockOffsets[NI_SigList[idx].addr][j];
          long vlen = NI_VirtualBlockLengths[NI_SigList[idx].addr][j];
          if (vidx == -1)
            break;
          NI_ProbeOneSignal(vidx, value, *len, &count, voff, vlen);
        }
      } else
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
    }
  }

  *len = count;
  return count;
}

/* Copy the	statically initialized params into our copy of the param struct
   The undef allows us to access the real ctrl_student_HIL_P
   In the rest of the code ctrl_student_HIL_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_student_HIL_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_student_HIL_P, sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_HIL_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

static int NI_SetParamTxStatus = NI_OK;

// This function is called by the BGL to set parameters.  When a commit is requested (index < 0),
// the code enters a critical section shared with the TCL. This ensures that the flip occurs only
// when safe, and acts as a messaging scheme for us to copy back the parameters.
DLL_EXPORT long NIRT_SetParameter(long index, long subindex, double value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_student_HIL_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0)
        return NI_OK;
      SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                         1);
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    if (NI_SetParamTxStatus==NI_ERROR) {
      // fail the transaction.
      // copy old	list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1)
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_student_HIL_T));

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /*Do nothing if no new parameters were written after last commit*/
    if (WriteSideDirtyFlag == 0)
      return NI_OK;

    // commit changes
    S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
    WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
    READSIDE = 1 - READSIDE;
    SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
    ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

    // Copy back the newly set parameters to the writeside.
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_SetVectorParameter( unsigned long index, const double
  * paramvalues, unsigned long paramlength)
{
  unsigned int i = 0;
  long retval= NI_OK, temp_retval;
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    if (temp_retval = NIRT_SetValueByDataType(ptr, i, paramvalues[i],
         NI_ParamList[index].datatype, NI_ParamList[index].IsComplex))//assignment intended in if condition
      retval= temp_retval;
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

DLL_EXPORT long NIRT_SetScalarParameterInline( unsigned long index, unsigned
  long subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_GetParameter(long index, long subindex, double *value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

DLL_EXPORT long NIRT_GetVectorParameter(unsigned long index, double* paramvalues,
  unsigned long paramlength)
{
  char* ptr = NULL;
  unsigned int i = 0;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_GetSimState(long* numContStates, char* contStatesNames,
  double* contStates, long* numDiscStates, char* discStatesNames, double
  * discStates, long* numClockTicks, char* clockTicksNames, long* clockTicks)
{
  long count, idx;
  if (numContStates && numDiscStates && numClockTicks) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 13;
      *numDiscStates = 1487;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator2_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator2_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator2_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_h[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_h");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_h[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_h");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_h[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_h");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE_k[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE_k[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE_k[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_k");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.imu_DWORK1, 0,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.imu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.imu_DWORK1, 1,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.imu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.imu_DWORK1, 2,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.imu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.guidance_switch_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.guidance_switch_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.N_power_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.N_power_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.N_power_H_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.N_power_H_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Samp_freq_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Samp_freq_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.dead_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.dead_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_c,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Enable_noise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Enable_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_noise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.x_noise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.x_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.y_noise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.y_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory4_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory4_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory4_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory5_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory5_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory5_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory2_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory2_PreviousInput");
    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Memory_PreviousInput_l, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Memory_PreviousInput_l");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Kd1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Kd1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Kd2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Kd2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Kd3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Kd3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.D_DWORK1, 0,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.D_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.D_DWORK1, 1,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.D_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.D_DWORK1, 2,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.D_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z1_DWORK1, 0,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z1_DWORK1, 1,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z1_DWORK1, 2,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ma_DWORK1, 0,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ma_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ma_DWORK1, 1,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ma_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ma_DWORK1, 2,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ma_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kdz_DWORK1, 0,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kdz_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kdz_DWORK1, 1,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kdz_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kdz_DWORK1, 2,
      17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kdz_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.etaaa_DWORK1,
      0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.etaaa_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.etaaa_DWORK1,
      1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.etaaa_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.etaaa_DWORK1,
      2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.etaaa_DWORK1");
    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.etav_DWORK1,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.etav_DWORK1");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.uref_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.uref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory3_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory3_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory3_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.sdot_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.sdot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.i_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.i_DWORK1");
    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Memory_PreviousInput_p, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Memory_PreviousInput_p");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Memory1_PreviousInput_m, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Memory1_PreviousInput_m");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_bar_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_bar_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_bar_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_bar_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_bar_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_bar_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L12_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L12_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L11_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L11_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L13_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L13_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L21_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L21_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L22_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L22_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L23_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L23_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L31_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L31_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L32_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L32_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L33_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L33_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.lost_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.lost_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_j, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_c, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_c");
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_continuous_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYRight_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXRight_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.R2_continuous_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXLeft_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYLeft_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowDown_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowUp_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowRight_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.imu_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.imu_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.guidance_switch_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.guidance_switch_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_in_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.N_power_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.N_power_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.N_power_H_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.N_power_H_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Samp_freq_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Samp_freq_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.dead_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.dead_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Enable_noise_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Enable_noise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_noise_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_noise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_noise_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_noise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.y_noise_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.y_noise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Kd1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Kd1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Kd2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Kd2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Kd3_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Kd3_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_0_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.integratorresetmodel_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.D_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.D_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ma_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ma_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.kdz_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.kdz_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.etaaa_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.etaaa_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.etav_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.etav_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.uref_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.uref_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.sdot_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.sdot_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.i_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.i_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_bar_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_bar_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.y_bar_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.y_bar_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_bar_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_bar_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_hat_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_hat_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.y_hat_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.r_hat_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_hat_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.v_hat_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L12_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L12_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L11_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L11_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L13_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L13_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L21_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L21_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L22_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L22_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L23_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L23_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L31_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L31_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L32_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L32_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L33_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L33_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.lost_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.lost_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 60; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3");
    }
  }

  if (clockTicks && clockTicksNames) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_SetSimState(double* contStates, double* discStates, long
  * clockTicks)
{
  long count, idx;
  if (contStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator2_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator2_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator2_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_h[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_h[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_h[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE_k[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE_k[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE_k[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.imu_DWORK1, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.imu_DWORK1, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.imu_DWORK1, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.guidance_switch_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_power_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_power_H_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Samp_freq_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dead_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_c, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_noise_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_noise_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_noise_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_noise_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory4_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory4_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory4_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory5_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory5_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory5_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory2_PreviousInput, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_l, count,
        discStates[idx++], 20, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Kd1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Kd2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Kd3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.D_DWORK1, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.D_DWORK1, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.D_DWORK1, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_DWORK1, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_DWORK1, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_DWORK1, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ma_DWORK1, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ma_DWORK1, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ma_DWORK1, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kdz_DWORK1, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kdz_DWORK1, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kdz_DWORK1, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.etaaa_DWORK1, 0, discStates[idx
      ++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.etaaa_DWORK1, 1, discStates[idx
      ++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.etaaa_DWORK1, 2, discStates[idx
      ++], 17, 0);
    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.etav_DWORK1, count,
        discStates[idx++], 20, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.uref_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory3_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory3_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory3_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sdot_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.i_DWORK1, 0, discStates[idx++],
      0, 0);
    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_p, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput_m,
        count, discStates[idx++], 23, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_bar_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_bar_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_bar_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L12_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L11_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L13_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L21_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L22_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L23_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L31_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L32_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L33_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.lost_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2,
      0, discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_j, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_c, 0, discStates[idx++],
      7, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.imu_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.guidance_switch_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_power_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_power_H_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Samp_freq_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.dead_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_noise_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_noise_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_noise_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_noise_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Kd1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Kd2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Kd3_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK2,
        count, discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.D_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ma_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.kdz_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.etaaa_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.etav_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.uref_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sdot_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.i_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_bar_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_bar_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_bar_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_hat_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_hat_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_hat_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_hat_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L12_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L11_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L13_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L21_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L22_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L23_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L31_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L32_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L33_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.lost_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 18, 0);
    }

    for (count = 0; count < 60; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 22, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL
