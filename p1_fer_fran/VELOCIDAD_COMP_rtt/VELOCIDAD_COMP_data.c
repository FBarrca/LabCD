/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VELOCIDAD_COMP_data.c
 *
 * Code generated for Simulink model 'VELOCIDAD_COMP'.
 *
 * Model version                  : 1.1090
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Oct 13 10:09:51 2021
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VELOCIDAD_COMP.h"
#include "VELOCIDAD_COMP_private.h"

/* Block parameters (auto storage) */
Parameters_VELOCIDAD_COMP VELOCIDAD_COMP_P = {
  0.04305F,                            /* Variable: R
                                        * Referenced by:
                                        *   '<S16>/Radio'
                                        *   '<S17>/Radio'
                                        */
  0.1,                                 /* Mask Parameter: Referenciavelocidad1_Vmin
                                        * Referenced by: '<S7>/Gain1'
                                        */
  2.0F,                                /* Mask Parameter: Referenciavelocidad1_T
                                        * Referenced by: '<S23>/Constant'
                                        */
  1.0F,                                /* Mask Parameter: Detecciondesector_const
                                        * Referenced by: '<S22>/Constant'
                                        */
  3.0F,                                /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  2.0F,                                /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S18>/Constant'
                                        */
  3.0F,                                /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S19>/Constant'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S11>/Gain8'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S9>/Gain6'
                                        */
  -0.08,                               /* Expression: -0.08
                                        * Referenced by: '<Root>/OFFSET'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S1>/Gain1'
                                        */
  44.5,                                /* Expression: 44.5
                                        * Referenced by: '<S3>/Hit  Crossing'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  -100.0,                              /* Expression: -100
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S1>/Gain3'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -100.0,                              /* Expression: -100
                                        * Referenced by: '<S1>/Saturation'
                                        */
  0.2,                                 /* Expression: 1/5
                                        * Referenced by: '<S9>/Gain1'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  0.5F,                                /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S8>/Switch'
                                        */
  1.0F,                                /* Computed Parameter: Saturation_UpperSat_b
                                        * Referenced by: '<S8>/Saturation'
                                        */
  0.0F,                                /* Computed Parameter: Saturation_LowerSat_i
                                        * Referenced by: '<S8>/Saturation'
                                        */
  0.055F,                              /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  0.05F,                               /* Computed Parameter: ang_refmaximo4_Value
                                        * Referenced by: '<S7>/ang_ref maximo4'
                                        */

  /*  Computed Parameter: Crdz_NumCoef
   * Referenced by: '<S2>/Crd(z) '
   */
  { 76.9021225F, -87.7392883F, 22.9003239F },

  /*  Computed Parameter: Crdz_DenCoef
   * Referenced by: '<S2>/Crd(z) '
   */
  { 1.0F, -0.599440753F, -0.400559276F },
  0.0F,                                /* Computed Parameter: Crdz_InitialStates
                                        * Referenced by: '<S2>/Crd(z) '
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_f
                                        * Referenced by: '<S17>/Unit Delay'
                                        */
  200.0F,                              /* Computed Parameter: Radio1_Gain
                                        * Referenced by: '<S17>/Radio1'
                                        */
  0.0174532924F,                       /* Computed Parameter: Pasoarads_Gain
                                        * Referenced by: '<S17>/Paso a rad//s'
                                        */

  /*  Computed Parameter: DiscreteTransferFcn_NumCoef
   * Referenced by: '<S17>/Discrete Transfer Fcn'
   */
  { 0.0246900879F, 0.0F },

  /*  Computed Parameter: DiscreteTransferFcn_DenCoef
   * Referenced by: '<S17>/Discrete Transfer Fcn'
   */
  { 1.0F, -0.975309908F },
  0.0F,                                /* Computed Parameter: DiscreteTransferFcn_InitialStat
                                        * Referenced by: '<S17>/Discrete Transfer Fcn'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_p
                                        * Referenced by: '<S16>/Unit Delay'
                                        */
  200.0F,                              /* Computed Parameter: Radio1_Gain_d
                                        * Referenced by: '<S16>/Radio1'
                                        */
  0.0174532924F,                       /* Computed Parameter: Pasoarads_Gain_a
                                        * Referenced by: '<S16>/Paso a rad//s'
                                        */

  /*  Computed Parameter: DiscreteTransferFcn_NumCoef_m
   * Referenced by: '<S16>/Discrete Transfer Fcn'
   */
  { 0.0246900879F, 0.0F },

  /*  Computed Parameter: DiscreteTransferFcn_DenCoef_a
   * Referenced by: '<S16>/Discrete Transfer Fcn'
   */
  { 1.0F, -0.975309908F },
  0.0F,                                /* Computed Parameter: DiscreteTransferFcn_InitialSt_p
                                        * Referenced by: '<S16>/Discrete Transfer Fcn'
                                        */
  0.5F,                                /* Computed Parameter: Media_Gain
                                        * Referenced by: '<S13>/Media'
                                        */

  /*  Computed Parameter: Cdz_NumCoef
   * Referenced by: '<S2>/Cd(z)'
   */
  { 76.9021225F, -87.7392883F, 22.9003239F },

  /*  Computed Parameter: Cdz_DenCoef
   * Referenced by: '<S2>/Cd(z)'
   */
  { 1.0F, -0.599440753F, -0.400559276F },
  0.0F,                                /* Computed Parameter: Cdz_InitialStates
                                        * Referenced by: '<S2>/Cd(z)'
                                        */
  1.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_f2
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  0.0F,                                /* Computed Parameter: RateTransition_X0
                                        * Referenced by: '<S1>/Rate Transition'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_h
                                        * Referenced by: '<S20>/Unit Delay'
                                        */
  1.0F,                                /* Computed Parameter: UnitDelay1_InitialCondition
                                        * Referenced by: '<S20>/Unit Delay1'
                                        */
  300000.0F,                           /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S20>/Gain2'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S20>/Unit Delay2'
                                        */
  0.0025F,                             /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S20>/Gain1'
                                        */
  300000.0F,                           /* Computed Parameter: Gain3_Gain_p
                                        * Referenced by: '<S20>/Gain3'
                                        */
  0U                                   /* Computed Parameter: UnitDelay_InitialCondition_a
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
};

/* Constant parameters (auto storage) */
const ConstParam_VELOCIDAD_COMP VELOCIDAD_COMP_ConstP = {
  /* Expression: lcdStr1
   * Referenced by: '<S14>/LCD'
   */
  { 68U, 69U, 84U, 69U, 67U, 84U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S15>/LCD'
   */
  { 69U, 83U, 84U, 65U, 68U, 79U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S21>/LCD'
   */
  { 73U, 65U, 69U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
