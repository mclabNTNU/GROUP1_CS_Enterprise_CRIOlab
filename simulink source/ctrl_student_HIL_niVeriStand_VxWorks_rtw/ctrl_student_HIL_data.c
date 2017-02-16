/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_student_HIL_P            ctrl_student_HIL_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_student_HIL_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.126
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Feb 16 10:46:40 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_HIL_T ctrl_student_HIL_P = {
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S1>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/counter'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Des_samp_freq'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Des_samp_freq'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Des_samp_freq'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Des_samp_freq'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Des_samp_freq'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Des_samp_freq'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Noise_power'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Noise_power'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Noise_power'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Noise_power'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Noise_power'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Noise_power'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S11>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S11>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S12>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S12>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Noise_powhead'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Noise_powhead'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/Noise_powhead'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Noise_powhead'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Noise_powhead'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Noise_powhead'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S10>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S10>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_in'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/dead'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/dead'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/dead'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/dead'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/dead'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/dead'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/k_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/k_psi'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/k_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/k_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/k_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/k_psi'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/uhat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/uhat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/uhat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/uhat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/uhat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/uhat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/uin'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/uin'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/uin'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/uin'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/uin'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/uin'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/utilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/utilde'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/utilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/utilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/utilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/utilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  -0.5,                                /* Expression: -.5
                                        * Referenced by: '<S3>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/True'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_student_HIL_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_student_HIL_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
