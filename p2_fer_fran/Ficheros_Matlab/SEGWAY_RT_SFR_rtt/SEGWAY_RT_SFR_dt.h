/*
 * SEGWAY_RT_SFR_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SEGWAY_RT_SFR".
 *
 * Model version              : 1.370
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Oct 27 10:01:11 2021
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&SEGWAY_RT_SFR_B.Gain6), 0, 0, 2 },

  { (char_T *)(&SEGWAY_RT_SFR_B.Saturation), 1, 0, 14 },

  { (char_T *)(&SEGWAY_RT_SFR_B.Compare), 8, 0, 2 }
  ,

  { (char_T *)(&SEGWAY_RT_SFR_DWork.Y_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE), 1, 0, 10 },

  { (char_T *)(&SEGWAY_RT_SFR_DWork.Integrator_IWORK.IcNeedsLoading), 10, 0, 1 },

  { (char_T *)(&SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_Subs), 2, 0, 4 },

  { (char_T *)(&SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_MODE), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&SEGWAY_RT_SFR_P.R), 1, 0, 8 },

  { (char_T *)(&SEGWAY_RT_SFR_P.Speaker_speakerVolume), 7, 0, 1 },

  { (char_T *)(&SEGWAY_RT_SFR_P.Gain6_Gain), 0, 0, 2 },

  { (char_T *)(&SEGWAY_RT_SFR_P.Gain8_Gain), 1, 0, 51 },

  { (char_T *)(&SEGWAY_RT_SFR_P.Speaker_p2), 7, 0, 2 },

  { (char_T *)(&SEGWAY_RT_SFR_P.Speaker_p1), 3, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] SEGWAY_RT_SFR_dt.h */
