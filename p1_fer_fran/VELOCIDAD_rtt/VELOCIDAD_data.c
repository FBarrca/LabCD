/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VELOCIDAD_data.c
 *
 * Code generated for Simulink model 'VELOCIDAD'.
 *
 * Model version                  : 1.1080
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Sep 29 09:38:46 2021
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VELOCIDAD.h"
#include "VELOCIDAD_private.h"

/* Block parameters (auto storage) */
Parameters_VELOCIDAD VELOCIDAD_P = {
  0.005,                               /* Variable: ts
                                        * Referenced by: '<S8>/Tension comun'
                                        */
  16.6856136F,                         /* Variable: K
                                        * Referenced by: '<S2>/Gain2'
                                        */
  0.04305F,                            /* Variable: R
                                        * Referenced by:
                                        *   '<S14>/Radio'
                                        *   '<S15>/Radio'
                                        */
  0.1,                                 /* Mask Parameter: Referenciavelocidad_Vmin
                                        * Referenced by: '<S7>/Gain1'
                                        */
  2.0F,                                /* Mask Parameter: Referenciavelocidad_T
                                        * Referenced by: '<S17>/Constant'
                                        */
  1.0F,                                /* Mask Parameter: Detecciondesector_const
                                        * Referenced by: '<S16>/Constant'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S11>/Gain8'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S10>/Gain6'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S8>/Tension comun'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Tension comun'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S8>/Constant'
                                        */
  -0.08,                               /* Expression: -0.08
                                        * Referenced by: '<Root>/Constant'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S1>/Gain1'
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
                                        * Referenced by: '<S10>/Gain1'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S9>/Unit Delay'
                                        */
  0.5F,                                /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S9>/Switch'
                                        */
  1.0F,                                /* Computed Parameter: Saturation_UpperSat_b
                                        * Referenced by: '<S9>/Saturation'
                                        */
  0.0F,                                /* Computed Parameter: Saturation_LowerSat_i
                                        * Referenced by: '<S9>/Saturation'
                                        */
  0.005F,                              /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  0.05F,                               /* Computed Parameter: ang_refmaximo4_Value
                                        * Referenced by: '<S7>/ang_ref maximo4'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_f
                                        * Referenced by: '<S15>/Unit Delay'
                                        */
  200.0F,                              /* Computed Parameter: Radio1_Gain
                                        * Referenced by: '<S15>/Radio1'
                                        */
  0.0174532924F,                       /* Computed Parameter: Pasoarads_Gain
                                        * Referenced by: '<S15>/Paso a rad//s'
                                        */

  /*  Computed Parameter: DiscreteTransferFcn_NumCoef
   * Referenced by: '<S15>/Discrete Transfer Fcn'
   */
  { 0.0246900879F, 0.0F },

  /*  Computed Parameter: DiscreteTransferFcn_DenCoef
   * Referenced by: '<S15>/Discrete Transfer Fcn'
   */
  { 1.0F, -0.975309908F },
  0.0F,                                /* Computed Parameter: DiscreteTransferFcn_InitialStat
                                        * Referenced by: '<S15>/Discrete Transfer Fcn'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_p
                                        * Referenced by: '<S14>/Unit Delay'
                                        */
  200.0F,                              /* Computed Parameter: Radio1_Gain_d
                                        * Referenced by: '<S14>/Radio1'
                                        */
  0.0174532924F,                       /* Computed Parameter: Pasoarads_Gain_a
                                        * Referenced by: '<S14>/Paso a rad//s'
                                        */

  /*  Computed Parameter: DiscreteTransferFcn_NumCoef_m
   * Referenced by: '<S14>/Discrete Transfer Fcn'
   */
  { 0.0246900879F, 0.0F },

  /*  Computed Parameter: DiscreteTransferFcn_DenCoef_a
   * Referenced by: '<S14>/Discrete Transfer Fcn'
   */
  { 1.0F, -0.975309908F },
  0.0F,                                /* Computed Parameter: DiscreteTransferFcn_InitialSt_p
                                        * Referenced by: '<S14>/Discrete Transfer Fcn'
                                        */
  0.5F,                                /* Computed Parameter: Media_Gain
                                        * Referenced by: '<S13>/Media'
                                        */
  1073741824,                          /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S13>/Gain2'
                                        */
  1073741824,                          /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S13>/Gain1'
                                        */
  0U,                                  /* Computed Parameter: UnitDelay_InitialCondition_a
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  64,                                  /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S1>/Gain4'
                                        */
  64                                   /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S1>/Gain2'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
