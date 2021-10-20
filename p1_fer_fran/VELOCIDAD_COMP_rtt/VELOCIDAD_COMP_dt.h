/*
 * VELOCIDAD_COMP_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VELOCIDAD_COMP".
 *
 * Model version              : 1.1090
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Oct 13 10:09:51 2021
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
  { (char_T *)(&VELOCIDAD_COMP_B.Gain6), 0, 0, 4 },

  { (char_T *)(&VELOCIDAD_COMP_B.Saturation), 1, 0, 20 },

  { (char_T *)(&VELOCIDAD_COMP_B.UnitDelay), 3, 0, 2 },

  { (char_T *)(&VELOCIDAD_COMP_B.HitCrossing), 8, 0, 1 }
  ,

  { (char_T *)(&VELOCIDAD_COMP_DWork.Velocidad_PWORK.LoggedData), 11, 0, 2 },

  { (char_T *)(&VELOCIDAD_COMP_DWork.UnitDelay_DSTATE), 1, 0, 19 },

  { (char_T *)(&VELOCIDAD_COMP_DWork.Integrator_IWORK.IcNeedsLoading), 10, 0, 2
  },

  { (char_T *)(&VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_n), 3, 0, 1 },

  { (char_T *)(&VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_PrevRese), 2, 0, 1 },

  { (char_T *)(&VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_SYSTEM_E), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&VELOCIDAD_COMP_P.R), 1, 0, 1 },

  { (char_T *)(&VELOCIDAD_COMP_P.Referenciavelocidad1_Vmin), 0, 0, 1 },

  { (char_T *)(&VELOCIDAD_COMP_P.Referenciavelocidad1_T), 1, 0, 5 },

  { (char_T *)(&VELOCIDAD_COMP_P.Gain8_Gain), 0, 0, 11 },

  { (char_T *)(&VELOCIDAD_COMP_P.UnitDelay_InitialCondition), 1, 0, 46 },

  { (char_T *)(&VELOCIDAD_COMP_P.UnitDelay_InitialCondition_a), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] VELOCIDAD_COMP_dt.h */
