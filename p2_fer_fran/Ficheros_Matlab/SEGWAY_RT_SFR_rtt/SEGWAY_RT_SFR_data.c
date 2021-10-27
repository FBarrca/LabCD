/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SEGWAY_RT_SFR_data.c
 *
 * Code generated for Simulink model 'SEGWAY_RT_SFR'.
 *
 * Model version                  : 1.370
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Oct 27 10:01:11 2021
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SEGWAY_RT_SFR.h"
#include "SEGWAY_RT_SFR_private.h"

/* Block parameters (auto storage) */
Parameters_SEGWAY_RT_SFR SEGWAY_RT_SFR_P = {
  0.0408F,                             /* Variable: R
                                        * Referenced by: '<S16>/Gain3'
                                        */
  0.8F,                                /* Variable: alfa1
                                        * Referenced by:
                                        *   '<S18>/Gain2'
                                        *   '<S29>/Gain2'
                                        *   '<S31>/Gain2'
                                        *   '<S32>/Gain2'
                                        */
  615.0F,                              /* Variable: gyro0
                                        * Referenced by: '<S18>/Unit Delay'
                                        */
  440.0F,                              /* Variable: sound_freq
                                        * Referenced by: '<S12>/Constant2'
                                        */
  1.0F,                                /* Variable: time_start
                                        * Referenced by:
                                        *   '<S14>/Constant'
                                        *   '<S15>/Constant'
                                        */
  0.005F,                              /* Variable: ts
                                        * Referenced by: '<S21>/Gain1'
                                        */
  1.0F,                                /* Mask Parameter: Calculodelavelocidadapartirdelc
                                        * Referenced by: '<S20>/Paso a grados'
                                        */
  1.0F,                                /* Mask Parameter: Calculodelavelocidadapartirde_j
                                        * Referenced by: '<S19>/Paso a grados'
                                        */
  50U,                                 /* Mask Parameter: Speaker_speakerVolume
                                        * Referenced by: '<S17>/Speaker'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S8>/Gain6'
                                        */
  0.2,                                 /* Expression: 1/5
                                        * Referenced by: '<S8>/Gain1'
                                        */
  -1.0F,                               /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<S9>/Gain8'
                                        */
  -1.0F,                               /* Computed Parameter: Gain1_Gain_a
                                        * Referenced by: '<S9>/Gain1'
                                        */
  0.2F,                                /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S18>/Gain3'
                                        */
  0.0174532924F,                       /* Computed Parameter: Pasoarads_Gain
                                        * Referenced by: '<S20>/Paso a rad//s'
                                        */
  0.2F,                                /* Computed Parameter: Gain3_Gain_g
                                        * Referenced by: '<S31>/Gain3'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S31>/Unit Delay'
                                        */

  /*  Computed Parameter: DiscreteTransferFcn_NumCoef
   * Referenced by: '<S30>/Discrete Transfer Fcn'
   */
  { 200.0F, -200.0F },

  /*  Computed Parameter: DiscreteTransferFcn_DenCoef
   * Referenced by: '<S30>/Discrete Transfer Fcn'
   */
  { 1.0F, 0.0F },
  0.0F,                                /* Computed Parameter: DiscreteTransferFcn_InitialStat
                                        * Referenced by: '<S30>/Discrete Transfer Fcn'
                                        */
  0.2F,                                /* Computed Parameter: Gain3_Gain_a
                                        * Referenced by: '<S32>/Gain3'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_o
                                        * Referenced by: '<S32>/Unit Delay'
                                        */
  0.0174532924F,                       /* Computed Parameter: Gain3_Gain_f
                                        * Referenced by: '<S21>/Gain3'
                                        */
  0.0174532924F,                       /* Computed Parameter: Pasoarads_Gain_j
                                        * Referenced by: '<S19>/Paso a rad//s'
                                        */
  0.2F,                                /* Computed Parameter: Gain3_Gain_k
                                        * Referenced by: '<S29>/Gain3'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_j
                                        * Referenced by: '<S29>/Unit Delay'
                                        */

  /*  Computed Parameter: DiscreteTransferFcn_NumCoef_c
   * Referenced by: '<S28>/Discrete Transfer Fcn'
   */
  { 200.0F, -200.0F },

  /*  Computed Parameter: DiscreteTransferFcn_DenCoef_c
   * Referenced by: '<S28>/Discrete Transfer Fcn'
   */
  { 1.0F, 0.0F },
  0.0F,                                /* Computed Parameter: DiscreteTransferFcn_InitialSt_b
                                        * Referenced by: '<S28>/Discrete Transfer Fcn'
                                        */
  0.5F,                                /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S16>/Gain'
                                        */
  0.272F,                              /* Computed Parameter: deg2rad4_Gain
                                        * Referenced by: '<S16>/deg2rad4'
                                        */
  -1.0F,                               /* Computed Parameter: deg2rad5_Gain
                                        * Referenced by: '<S16>/deg2rad5'
                                        */
  57.2957802F,                         /* Computed Parameter: deg2rad2_Gain
                                        * Referenced by: '<S16>/deg2rad2'
                                        */
  0.02F,                               /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S21>/Gain2'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_m
                                        * Referenced by: '<S21>/Unit Delay'
                                        */
  0.98F,                               /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S21>/Gain'
                                        */
  0.0174532924F,                       /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S21>/Gain4'
                                        */
  57.2957802F,                         /* Computed Parameter: deg2rad1_Gain
                                        * Referenced by: '<S16>/deg2rad1'
                                        */
  0.001F,                              /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S2>/Gain'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay_InitialCondition_d
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  0.5F,                                /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S7>/Switch'
                                        */
  1.0F,                                /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S7>/Saturation'
                                        */
  0.0F,                                /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S7>/Saturation'
                                        */

  /*  Computed Parameter: Gain3_Gain_gu
   * Referenced by: '<S6>/Gain3'
   */
  { 28.1221542F, 4.85835409F, 39.6042747F },
  0.0F,                                /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.5F,                                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S1>/Gain'
                                        */
  100.0F,                              /* Computed Parameter: Gain3_Gain_c
                                        * Referenced by: '<S1>/Gain3'
                                        */
  100.0F,                              /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -100.0F,                             /* Computed Parameter: Saturation_LowerSat_m
                                        * Referenced by: '<S1>/Saturation'
                                        */
  1.0F,                                /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S1>/Gain2'
                                        */
  100.0F,                              /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S1>/Gain1'
                                        */
  100.0F,                              /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  -100.0F,                             /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  1.0F,                                /* Computed Parameter: Gain4_Gain_l
                                        * Referenced by: '<S1>/Gain4'
                                        */
  57.2957802F,                         /* Computed Parameter: deg2rad1_Gain_f
                                        * Referenced by: '<S6>/deg2rad1'
                                        */
  57.2957802F,                         /* Computed Parameter: deg2rad2_Gain_h
                                        * Referenced by: '<S6>/deg2rad2'
                                        */
  100U,                                /* Computed Parameter: Speaker_p2
                                        * Referenced by: '<S17>/Speaker'
                                        */
  100U,                                /* Computed Parameter: Speaker_p4
                                        * Referenced by: '<S17>/Speaker'
                                        */
  1U,                                  /* Computed Parameter: Speaker_p1
                                        * Referenced by: '<S17>/Speaker'
                                        */
  2U                                   /* Computed Parameter: AccelerationSensor_p1
                                        * Referenced by: '<Root>/Acceleration Sensor'
                                        */
};

/* Constant parameters (auto storage) */
const ConstParam_SEGWAY_RT_SFR SEGWAY_RT_SFR_ConstP = {
  /* Expression: lcdStr1
   * Referenced by: '<S22>/LCD'
   */
  { 118U, 82U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S23>/LCD'
   */
  { 119U, 112U, 104U, 105U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S24>/LCD'
   */
  { 103U, 121U, 114U, 111U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S25>/LCD'
   */
  { 119U, 116U, 104U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S26>/LCD'
   */
  { 116U, 104U, 32U, 40U, 186U, 41U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S27>/LCD'
   */
  { 116U, 104U, 97U, 32U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
