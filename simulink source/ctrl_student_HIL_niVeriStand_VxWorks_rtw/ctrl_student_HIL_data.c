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
 * Model version              : 1.153
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Mar 30 13:15:43 2017
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  -0.5,                                /* Expression: -.5
                                        * Referenced by: '<S7>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<Root>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/True'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/posX'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/posX'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/posX'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/posX'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/posX'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/posX'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/posY'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/posY'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/posY'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/posY'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/posY'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/posY'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S9>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/guidance_switch'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S1>/Memory4'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S1>/Memory5'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S1>/Gain'
   */
  { 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<S1>/Memory6'
   */
  { 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S12>/Kd1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/Kd1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/Kd1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/Kd1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/Kd1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/Kd1'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S12>/Kd2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/Kd2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/Kd2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/Kd2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/Kd2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/Kd2'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S12>/Kd3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/Kd3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/Kd3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/Kd3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/Kd3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/Kd3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tauut'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tauut'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/tauut'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tauut'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tauut'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tauut'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tauJ'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tauJ'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/tauJ'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tauJ'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tauJ'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tauJ'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  4.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/N_power'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/N_power'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/N_power'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/N_power'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/N_power'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/N_power'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/dead'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/dead'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/dead'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/dead'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/dead'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/dead'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/counter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S27>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S27>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_f
                                        * Referenced by: '<S28>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S28>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S26>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_p
                                        * Referenced by: '<S26>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S26>/White Noise'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/x_noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/x_noise'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/x_noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/x_noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/x_noise'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/x_noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/y_noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/y_noise'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/y_noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/y_noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/y_noise'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/y_noise'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S49>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S49>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S49>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S49>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S49>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S49>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/s'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/s'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/s'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/s'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/s'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/s'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/D'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/D'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/D'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/D'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/D'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/D'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/z1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/z1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/z1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/z1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/z1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/z1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/ma'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/ma'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/ma'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/ma'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/ma'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/ma'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/kdz'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/kdz'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/kdz'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/kdz'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/kdz'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/kdz'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/etaaa'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/etaaa'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/etaaa'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/etaaa'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/etaaa'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/etaaa'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/etav'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/etav'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/etav'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/etav'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/etav'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/etav'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/uref '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/uref '
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/uref '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/uref '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/uref '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/uref '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory3'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S1>/Memory1'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/sdot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/sdot'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/sdot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/sdot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/sdot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/sdot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/i'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/i'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/i'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/i'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/i'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/i'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/eta_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/eta_d'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/eta_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/eta_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/eta_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/eta_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/eta_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/eta_0'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/eta_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/eta_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/eta_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/eta_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S34>/bias_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S34>/bias_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S34>/bias_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S34>/bias_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S34>/bias_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S34>/bias_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S34>/bias_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S34>/bias_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S34>/bias_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S34>/bias_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S34>/bias_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S34>/bias_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S34>/bias_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S34>/bias_3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S34>/bias_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S34>/bias_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S34>/bias_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S34>/bias_3'
                                        */

  /*  Expression: [0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S8>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S8>/Memory1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/x_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/x_bar'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/x_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/x_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/x_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/x_bar'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/y_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/y_bar'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/y_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/y_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/y_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/y_bar'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S36>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S36>/x_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S36>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S36>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S36>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S36>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S36>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S36>/y_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S36>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S36>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S36>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S36>/y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/r_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/r_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/r_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/v_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/v_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/v_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S30>/L12'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S30>/L12'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S30>/L12'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S30>/L12'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S30>/L12'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S30>/L12'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S30>/L11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S30>/L11'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S30>/L11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S30>/L11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S30>/L11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S30>/L11'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S30>/L13'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S30>/L13'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S30>/L13'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S30>/L13'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S30>/L13'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S30>/L13'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S31>/L21'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S31>/L21'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S31>/L21'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S31>/L21'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S31>/L21'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S31>/L21'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S31>/L22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S31>/L22'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S31>/L22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S31>/L22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S31>/L22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S31>/L22'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S31>/L23'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S31>/L23'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S31>/L23'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S31>/L23'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S31>/L23'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S31>/L23'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S32>/L31'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S32>/L31'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S32>/L31'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S32>/L31'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S32>/L31'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S32>/L31'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S32>/L32'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S32>/L32'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S32>/L32'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S32>/L32'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S32>/L32'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S32>/L32'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S32>/L33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S32>/L33'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S32>/L33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S32>/L33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S32>/L33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S32>/L33'
                                        */

  /*  Expression: inv([14.79 0 0;
     0 14.79 14.79*0.0375;
     0 14.79*0.0375 1.76])
   * Referenced by: '<S3>/inv(M)'
   */
  { 0.0676132521974307, 0.0, 0.0, 0.0, 0.068421812878562208,
    -0.021561618163507136, 0.0, -0.021561618163507136, 0.57497648436019044 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/lost'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/lost'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/lost'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/lost'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/lost'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/lost'
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

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 10, 0 },

  { sizeof(real_T), 10, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
