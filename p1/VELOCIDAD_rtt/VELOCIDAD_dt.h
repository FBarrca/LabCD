/*
 * VELOCIDAD_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VELOCIDAD".
 *
 * Model version              : 1.1080
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Sep 29 09:38:46 2021
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
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64m_T),
  sizeof(int8_T),
  sizeof(int16_T),
  sizeof(int64m_T),
  sizeof(uint64m_T),
  sizeof(int96m_T),
  sizeof(uint96m_T),
  sizeof(int128m_T),
  sizeof(uint128m_T),
  sizeof(int160m_T),
  sizeof(uint160m_T),
  sizeof(int192m_T),
  sizeof(uint192m_T),
  sizeof(int224m_T),
  sizeof(uint224m_T),
  sizeof(int256m_T),
  sizeof(uint256m_T)
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
  "timer_uint32_pair_T",
  "int32_T",
  "int64m_T",
  "int8_T",
  "int16_T",
  "int64m_T",
  "uint64m_T",
  "int96m_T",
  "uint96m_T",
  "int128m_T",
  "uint128m_T",
  "int160m_T",
  "uint160m_T",
  "int192m_T",
  "uint192m_T",
  "int224m_T",
  "uint224m_T",
  "int256m_T",
  "uint256m_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&VELOCIDAD_B.Gain6), 0, 0, 3 },

  { (char_T *)(&VELOCIDAD_B.Saturation), 1, 0, 9 },

  { (char_T *)(&VELOCIDAD_B.UnitDelay), 3, 0, 2 }
  ,

  { (char_T *)(&VELOCIDAD_DWork.Velocidad_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&VELOCIDAD_DWork.UnitDelay_DSTATE), 1, 0, 8 },

  { (char_T *)(&VELOCIDAD_DWork.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&VELOCIDAD_DWork.Integrator_IWORK.IcNeedsLoading), 10, 0, 1 },

  { (char_T *)(&VELOCIDAD_DWork.UnitDelay_DSTATE_c), 3, 0, 1 },

  { (char_T *)(&VELOCIDAD_DWork.DiscreteTimeIntegrator_PrevRese), 2, 0, 1 },

  { (char_T *)(&VELOCIDAD_DWork.DiscreteTimeIntegrator_SYSTEM_E), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&VELOCIDAD_P.ts), 0, 0, 1 },

  { (char_T *)(&VELOCIDAD_P.K), 1, 0, 2 },

  { (char_T *)(&VELOCIDAD_P.Referenciavelocidad_Vmin), 0, 0, 1 },

  { (char_T *)(&VELOCIDAD_P.Referenciavelocidad_T), 1, 0, 2 },

  { (char_T *)(&VELOCIDAD_P.Gain8_Gain), 0, 0, 13 },

  { (char_T *)(&VELOCIDAD_P.UnitDelay_InitialCondition), 1, 0, 24 },

  { (char_T *)(&VELOCIDAD_P.Gain2_Gain), 14, 0, 2 },

  { (char_T *)(&VELOCIDAD_P.UnitDelay_InitialCondition_a), 3, 0, 2 },

  { (char_T *)(&VELOCIDAD_P.Gain4_Gain), 16, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  9U,
  rtPTransitions
};

/* [EOF] VELOCIDAD_dt.h */
