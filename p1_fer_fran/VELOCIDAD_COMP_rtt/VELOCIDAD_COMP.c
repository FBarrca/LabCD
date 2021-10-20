/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VELOCIDAD_COMP.c
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
#include "VELOCIDAD_COMP_dt.h"
#include "nxt_util.h"

/* Block signals (auto storage) */
BlockIO_VELOCIDAD_COMP VELOCIDAD_COMP_B;

/* Continuous states */
ContinuousStates_VELOCIDAD_COMP VELOCIDAD_COMP_X;

/* Block states (auto storage) */
D_Work_VELOCIDAD_COMP VELOCIDAD_COMP_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_VELOCIDAD_COMP VELOCIDAD_COMP_PrevZCSigState;

/* Real-time model */
RT_MODEL_VELOCIDAD_COMP VELOCIDAD_COMP_M_;
RT_MODEL_VELOCIDAD_COMP *const VELOCIDAD_COMP_M = &VELOCIDAD_COMP_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2])++;
  if ((VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2]) > 10) {/* Sample time: [0.055s, 0.0s] */
    VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] = 0;
  }

  (VELOCIDAD_COMP_M->Timing.TaskCounters.TID[3])++;
  if ((VELOCIDAD_COMP_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.1s, 0.0s] */
    VELOCIDAD_COMP_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  VELOCIDAD_COMP_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  VELOCIDAD_COMP_output();
  VELOCIDAD_COMP_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  VELOCIDAD_COMP_output();
  VELOCIDAD_COMP_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model output function */
void VELOCIDAD_COMP_output(void)
{
  int8_T rtb_DataTypeConversion1_n_0;
  uint16_T rtb_Battery_0;
  int32_T rtb_DataTypeConversion_e_0;
  ZCEventType zcEvent;
  int8_T tmp;
  int8_T tmp_0;
  real32_T rtb_DataTypeConversion_a;
  real32_T rtb_Product_c;
  boolean_T rtb_Compare_i;
  real_T rtb_Gain8;
  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&VELOCIDAD_COMP_M->solverInfo,
                          ((VELOCIDAD_COMP_M->Timing.clockTick0+1)*
      VELOCIDAD_COMP_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(VELOCIDAD_COMP_M)) {
    VELOCIDAD_COMP_M->Timing.t[0] = rtsiGetT(&VELOCIDAD_COMP_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (nxt_button): '<S8>/Button' */
    rtb_DataTypeConversion1_n_0 = pressButton(1U);

    /* Switch: '<S8>/Switch' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     *  S-Function (nxt_button): '<S8>/Button'
     *  UnitDelay: '<S8>/Unit Delay'
     */
    if (rtb_DataTypeConversion1_n_0 >= VELOCIDAD_COMP_P.Switch_Threshold) {
      rtb_DataTypeConversion_a = rtb_DataTypeConversion1_n_0;
    } else {
      rtb_DataTypeConversion_a = VELOCIDAD_COMP_DWork.UnitDelay_DSTATE;
    }

    /* End of Switch: '<S8>/Switch' */

    /* Saturate: '<S8>/Saturation' */
    if (rtb_DataTypeConversion_a > VELOCIDAD_COMP_P.Saturation_UpperSat_b) {
      VELOCIDAD_COMP_B.Saturation = VELOCIDAD_COMP_P.Saturation_UpperSat_b;
    } else if (rtb_DataTypeConversion_a < VELOCIDAD_COMP_P.Saturation_LowerSat_i)
    {
      VELOCIDAD_COMP_B.Saturation = VELOCIDAD_COMP_P.Saturation_LowerSat_i;
    } else {
      VELOCIDAD_COMP_B.Saturation = rtb_DataTypeConversion_a;
    }

    /* End of Saturate: '<S8>/Saturation' */
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[3] == 0) {
    /* S-Function (nxt_battery): '<S9>/Battery' */
    rtb_Battery_0 = getBattery();

    /* Gain: '<S9>/Gain6' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion'
     *  S-Function (nxt_battery): '<S9>/Battery'
     */
    VELOCIDAD_COMP_B.Gain6 = VELOCIDAD_COMP_P.Gain6_Gain * (real_T)rtb_Battery_0;
  }

  /* Integrator: '<S9>/Integrator' */
  if (VELOCIDAD_COMP_DWork.Integrator_IWORK.IcNeedsLoading) {
    VELOCIDAD_COMP_X.Integrator_CSTATE = VELOCIDAD_COMP_B.Gain6;
  }

  VELOCIDAD_COMP_B.Integrator = VELOCIDAD_COMP_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    rtb_DataTypeConversion_a = (real32_T)VELOCIDAD_COMP_B.Integrator;

    /* UnitDelay: '<S7>/Unit Delay' */
    VELOCIDAD_COMP_B.UnitDelay = VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_n;

    /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    if (VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_SYSTEM_E != 0) {
      VELOCIDAD_COMP_B.DiscreteTimeIntegrator =
        VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_DSTATE;
    } else if ((VELOCIDAD_COMP_B.UnitDelay > 0) &&
               (VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_PrevRese <= 0)) {
      VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_DSTATE =
        VELOCIDAD_COMP_P.DiscreteTimeIntegrator_IC;
      VELOCIDAD_COMP_B.DiscreteTimeIntegrator =
        VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_DSTATE;
    } else {
      VELOCIDAD_COMP_B.DiscreteTimeIntegrator =
        VELOCIDAD_COMP_P.DiscreteTimeIntegrator_gainval *
        VELOCIDAD_COMP_B.Saturation +
        VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_DSTATE;
    }

    /* End of DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */

    /* Sum: '<S7>/Sum' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S7>/ang_ref maximo4'
     *  Gain: '<S7>/Gain1'
     *  RelationalOperator: '<S22>/Compare'
     */
    VELOCIDAD_COMP_B.Sum = (real32_T)((real_T)
      (VELOCIDAD_COMP_B.DiscreteTimeIntegrator >=
       VELOCIDAD_COMP_P.Detecciondesector_const) *
      VELOCIDAD_COMP_P.Referenciavelocidad1_Vmin) +
      VELOCIDAD_COMP_P.ang_refmaximo4_Value;

    /* Product: '<S2>/Multiply1' */
    VELOCIDAD_COMP_B.Multiply1 = VELOCIDAD_COMP_B.Sum *
      VELOCIDAD_COMP_B.Saturation;

    /* DiscreteTransferFcn: '<S2>/Crd(z) ' */
    VELOCIDAD_COMP_DWork.Crdz_tmp = ((VELOCIDAD_COMP_B.Multiply1 -
      VELOCIDAD_COMP_P.Crdz_DenCoef[1] * VELOCIDAD_COMP_DWork.Crdz_states[0]) -
      VELOCIDAD_COMP_P.Crdz_DenCoef[2] * VELOCIDAD_COMP_DWork.Crdz_states[1]) /
      VELOCIDAD_COMP_P.Crdz_DenCoef[0];
    rtb_Product_c = (VELOCIDAD_COMP_P.Crdz_NumCoef[0] *
                     VELOCIDAD_COMP_DWork.Crdz_tmp +
                     VELOCIDAD_COMP_P.Crdz_NumCoef[1] *
                     VELOCIDAD_COMP_DWork.Crdz_states[0]) +
      VELOCIDAD_COMP_P.Crdz_NumCoef[2] * VELOCIDAD_COMP_DWork.Crdz_states[1];
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (nxt_encoder): '<Root>/Encoder IZQUIERDO' */
    rtb_DataTypeConversion_e_0 = getEncoderValueNoReset(2U);

    /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
     *  S-Function (nxt_encoder): '<Root>/Encoder IZQUIERDO'
     */
    VELOCIDAD_COMP_B.DataTypeConversion = (real32_T)rtb_DataTypeConversion_e_0;

    /* Gain: '<S17>/Radio' incorporates:
     *  Gain: '<S17>/Paso a rad//s'
     *  Gain: '<S17>/Radio1'
     *  Sum: '<S17>/Sum'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    VELOCIDAD_COMP_B.Radio = (VELOCIDAD_COMP_B.DataTypeConversion -
      VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_h) * VELOCIDAD_COMP_P.Radio1_Gain *
      VELOCIDAD_COMP_P.Pasoarads_Gain * VELOCIDAD_COMP_P.R;

    /* DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn' */
    VELOCIDAD_COMP_DWork.DiscreteTransferFcn_tmp = (VELOCIDAD_COMP_B.Radio -
      VELOCIDAD_COMP_P.DiscreteTransferFcn_DenCoef[1] *
      VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states) /
      VELOCIDAD_COMP_P.DiscreteTransferFcn_DenCoef[0];

    /* S-Function (nxt_encoder): '<Root>/Encoder DERECHO' */
    rtb_DataTypeConversion_e_0 = getEncoderValueNoReset(3U);

    /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
     *  S-Function (nxt_encoder): '<Root>/Encoder DERECHO'
     */
    VELOCIDAD_COMP_B.DataTypeConversion1 = (real32_T)rtb_DataTypeConversion_e_0;

    /* Gain: '<S16>/Radio' incorporates:
     *  Gain: '<S16>/Paso a rad//s'
     *  Gain: '<S16>/Radio1'
     *  Sum: '<S16>/Sum'
     *  UnitDelay: '<S16>/Unit Delay'
     */
    VELOCIDAD_COMP_B.Radio_l = (VELOCIDAD_COMP_B.DataTypeConversion1 -
      VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_e) * VELOCIDAD_COMP_P.Radio1_Gain_d *
      VELOCIDAD_COMP_P.Pasoarads_Gain_a * VELOCIDAD_COMP_P.R;

    /* DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn' */
    VELOCIDAD_COMP_DWork.DiscreteTransferFcn_tmp_e = (VELOCIDAD_COMP_B.Radio_l -
      VELOCIDAD_COMP_P.DiscreteTransferFcn_DenCoef_a[1] *
      VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states_h) /
      VELOCIDAD_COMP_P.DiscreteTransferFcn_DenCoef_a[0];

    /* Gain: '<S13>/Media' incorporates:
     *  DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn'
     *  DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn'
     *  Sum: '<S13>/Sum7'
     */
    VELOCIDAD_COMP_B.Media = ((VELOCIDAD_COMP_P.DiscreteTransferFcn_NumCoef[0] *
      VELOCIDAD_COMP_DWork.DiscreteTransferFcn_tmp +
      VELOCIDAD_COMP_P.DiscreteTransferFcn_NumCoef[1] *
      VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states) +
      (VELOCIDAD_COMP_P.DiscreteTransferFcn_NumCoef_m[0] *
       VELOCIDAD_COMP_DWork.DiscreteTransferFcn_tmp_e +
       VELOCIDAD_COMP_P.DiscreteTransferFcn_NumCoef_m[1] *
       VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states_h)) *
      VELOCIDAD_COMP_P.Media_Gain;
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0) {
    /* Product: '<S2>/Multiply' */
    VELOCIDAD_COMP_B.Multiply = VELOCIDAD_COMP_B.Media *
      VELOCIDAD_COMP_B.Saturation;

    /* DiscreteTransferFcn: '<S2>/Cd(z)' */
    VELOCIDAD_COMP_DWork.Cdz_tmp = ((VELOCIDAD_COMP_B.Multiply -
      VELOCIDAD_COMP_P.Cdz_DenCoef[1] * VELOCIDAD_COMP_DWork.Cdz_states[0]) -
      VELOCIDAD_COMP_P.Cdz_DenCoef[2] * VELOCIDAD_COMP_DWork.Cdz_states[1]) /
      VELOCIDAD_COMP_P.Cdz_DenCoef[0];

    /* Sum: '<S2>/Sum2' incorporates:
     *  DiscreteTransferFcn: '<S2>/Cd(z)'
     */
    rtb_Product_c -= (VELOCIDAD_COMP_P.Cdz_NumCoef[0] *
                      VELOCIDAD_COMP_DWork.Cdz_tmp +
                      VELOCIDAD_COMP_P.Cdz_NumCoef[1] *
                      VELOCIDAD_COMP_DWork.Cdz_states[0]) +
      VELOCIDAD_COMP_P.Cdz_NumCoef[2] * VELOCIDAD_COMP_DWork.Cdz_states[1];

    /* Switch: '<S12>/Switch2' incorporates:
     *  RelationalOperator: '<S12>/LowerRelop1'
     */
    if (rtb_Product_c > VELOCIDAD_COMP_B.Integrator) {
      VELOCIDAD_COMP_B.Switch2 = (real32_T)VELOCIDAD_COMP_B.Integrator;
    } else {
      /* Gain: '<S11>/Gain8' */
      rtb_Gain8 = VELOCIDAD_COMP_P.Gain8_Gain * VELOCIDAD_COMP_B.Integrator;

      /* Switch: '<S12>/Switch' incorporates:
       *  RelationalOperator: '<S12>/UpperRelop'
       */
      if (rtb_Product_c < rtb_Gain8) {
        VELOCIDAD_COMP_B.Switch2 = (real32_T)rtb_Gain8;
      } else {
        VELOCIDAD_COMP_B.Switch2 = rtb_Product_c;
      }

      /* End of Switch: '<S12>/Switch' */
    }

    /* End of Switch: '<S12>/Switch2' */

    /* S-Function (nxt_light_sensor): '<Root>/Light Sensor' */
    rtb_Battery_0 = getLightSensorValue(4U, 1U);

    /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
     *  S-Function (nxt_light_sensor): '<Root>/Light Sensor'
     */
    VELOCIDAD_COMP_B.DataTypeConversion4 = rtb_Battery_0;

    /* HitCross: '<S3>/Hit  Crossing' */
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                       &VELOCIDAD_COMP_PrevZCSigState.HitCrossing_Input_ZCE,
                       (VELOCIDAD_COMP_B.DataTypeConversion4 -
                        VELOCIDAD_COMP_P.HitCrossing_Offset));
    if (VELOCIDAD_COMP_DWork.HitCrossing_MODE == 0) {
      if (zcEvent != NO_ZCEVENT) {
        VELOCIDAD_COMP_B.HitCrossing = !VELOCIDAD_COMP_B.HitCrossing;
        VELOCIDAD_COMP_DWork.HitCrossing_MODE = 1;
      } else {
        if (VELOCIDAD_COMP_B.HitCrossing &&
            (VELOCIDAD_COMP_B.DataTypeConversion4 !=
             VELOCIDAD_COMP_P.HitCrossing_Offset)) {
          VELOCIDAD_COMP_B.HitCrossing = false;
        }
      }
    } else {
      if (VELOCIDAD_COMP_B.DataTypeConversion4 !=
          VELOCIDAD_COMP_P.HitCrossing_Offset) {
        VELOCIDAD_COMP_B.HitCrossing = false;
      }

      VELOCIDAD_COMP_DWork.HitCrossing_MODE = 0;
    }

    /* End of HitCross: '<S3>/Hit  Crossing' */

    /* Sum: '<S3>/Sum1' incorporates:
     *  Product: '<S3>/Product'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    VELOCIDAD_COMP_B.Sum1 = (real32_T)VELOCIDAD_COMP_B.HitCrossing *
      VELOCIDAD_COMP_B.Saturation + VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_d;

    /* RelationalOperator: '<S10>/Compare' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rtb_Compare_i = (VELOCIDAD_COMP_B.Sum1 <
                     VELOCIDAD_COMP_P.CompareToConstant_const);

    /* Product: '<S1>/Divide3' incorporates:
     *  Constant: '<Root>/OFFSET'
     *  Gain: '<S1>/Gain1'
     *  Product: '<S1>/Divide1'
     *  Sum: '<S1>/Sum5'
     */
    rtb_Gain8 = (VELOCIDAD_COMP_B.Switch2 + VELOCIDAD_COMP_P.OFFSET_Value) /
      rtb_DataTypeConversion_a * VELOCIDAD_COMP_P.Gain1_Gain *
      VELOCIDAD_COMP_B.Saturation * (real_T)rtb_Compare_i;

    /* Saturate: '<S1>/Saturation1' */
    if (rtb_Gain8 > VELOCIDAD_COMP_P.Saturation1_UpperSat) {
      rtb_Gain8 = VELOCIDAD_COMP_P.Saturation1_UpperSat;
    } else {
      if (rtb_Gain8 < VELOCIDAD_COMP_P.Saturation1_LowerSat) {
        rtb_Gain8 = VELOCIDAD_COMP_P.Saturation1_LowerSat;
      }
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
     *  Saturate: '<S1>/Saturation1'
     */
    rtb_Gain8 = floor(rtb_Gain8);
    if (rtIsNaN(rtb_Gain8) || rtIsInf(rtb_Gain8)) {
      rtb_Gain8 = 0.0;
    } else {
      rtb_Gain8 = fmod(rtb_Gain8, 256.0);
    }

    /* S-Function (nxt_motor): '<S5>/Motor' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion2'
     */
    tmp = (int8_T)(rtb_Gain8 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                   -rtb_Gain8 : (int32_T)(int8_T)(uint8_T)rtb_Gain8);
    setMotor(&tmp, 3U, 2U);

    /* Product: '<S1>/Divide2' incorporates:
     *  Constant: '<Root>/OFFSET'
     *  Gain: '<S1>/Gain3'
     *  Product: '<S1>/Divide'
     *  Sum: '<S1>/Sum4'
     */
    rtb_Gain8 = (VELOCIDAD_COMP_B.Switch2 - VELOCIDAD_COMP_P.OFFSET_Value) /
      rtb_DataTypeConversion_a * VELOCIDAD_COMP_P.Gain3_Gain *
      VELOCIDAD_COMP_B.Saturation * (real_T)rtb_Compare_i;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Gain8 > VELOCIDAD_COMP_P.Saturation_UpperSat) {
      rtb_Gain8 = VELOCIDAD_COMP_P.Saturation_UpperSat;
    } else {
      if (rtb_Gain8 < VELOCIDAD_COMP_P.Saturation_LowerSat) {
        rtb_Gain8 = VELOCIDAD_COMP_P.Saturation_LowerSat;
      }
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
     *  Saturate: '<S1>/Saturation'
     */
    rtb_Gain8 = floor(rtb_Gain8);
    if (rtIsNaN(rtb_Gain8) || rtIsInf(rtb_Gain8)) {
      rtb_Gain8 = 0.0;
    } else {
      rtb_Gain8 = fmod(rtb_Gain8, 256.0);
    }

    /* S-Function (nxt_motor): '<S6>/Motor' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     */
    tmp_0 = (int8_T)(rtb_Gain8 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                     -rtb_Gain8 : (int32_T)(int8_T)(uint8_T)rtb_Gain8);
    setMotor(&tmp_0, 2U, 2U);
  }

  /* Gain: '<S9>/Gain1' incorporates:
   *  Sum: '<S9>/Sum1'
   */
  VELOCIDAD_COMP_B.Gain1 = (VELOCIDAD_COMP_B.Gain6 - VELOCIDAD_COMP_B.Integrator)
    * VELOCIDAD_COMP_P.Gain1_Gain_l;

  /* RateTransition: '<S1>/Rate Transition' */
  if ((rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
       VELOCIDAD_COMP_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
       (VELOCIDAD_COMP_M) &&
       VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0)) {
    VELOCIDAD_COMP_B.RateTransition =
      VELOCIDAD_COMP_DWork.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition' */
  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<S14>/Data Type Conversion' */
    rtb_Gain8 = floor(VELOCIDAD_COMP_B.DataTypeConversion4);
    if (rtIsNaN(rtb_Gain8) || rtIsInf(rtb_Gain8)) {
      rtb_Gain8 = 0.0;
    } else {
      rtb_Gain8 = fmod(rtb_Gain8, 4.294967296E+9);
    }

    /* S-Function (nxt_lcd): '<S14>/LCD' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion'
     */
    lcdDisplay(rtb_Gain8 < 0.0 ? -(int32_T)(uint32_T)-rtb_Gain8 : (int32_T)
               (uint32_T)rtb_Gain8, VELOCIDAD_COMP_ConstP.LCD_p1, 2U, 1U);

    /* DataTypeConversion: '<S15>/Data Type Conversion' */
    rtb_Product_c = (real32_T)floor(VELOCIDAD_COMP_B.Sum1);
    if (rtIsNaNF(rtb_Product_c) || rtIsInfF(rtb_Product_c)) {
      rtb_Product_c = 0.0F;
    } else {
      rtb_Product_c = (real32_T)fmod(rtb_Product_c, 4.2949673E+9F);
    }

    /* S-Function (nxt_lcd): '<S15>/LCD' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion'
     */
    lcdDisplay(rtb_Product_c < 0.0F ? -(int32_T)(uint32_T)-rtb_Product_c :
               (int32_T)(uint32_T)rtb_Product_c, VELOCIDAD_COMP_ConstP.LCD_p1_e,
               3U, 1U);

    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    VELOCIDAD_COMP_B.DataTypeConversion1_d = (real32_T)
      VELOCIDAD_COMP_B.DataTypeConversion4;

    /* RelationalOperator: '<S23>/Compare' incorporates:
     *  Constant: '<S23>/Constant'
     */
    VELOCIDAD_COMP_B.Compare = (uint8_T)(VELOCIDAD_COMP_B.DiscreteTimeIntegrator
      >= VELOCIDAD_COMP_P.Referenciavelocidad1_T);
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S20>/Gain2' incorporates:
     *  Product: '<S20>/Product'
     *  UnitDelay: '<S20>/Unit Delay'
     *  UnitDelay: '<S20>/Unit Delay1'
     */
    VELOCIDAD_COMP_B.Gain2 = VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_p /
      VELOCIDAD_COMP_DWork.UnitDelay1_DSTATE * VELOCIDAD_COMP_P.Gain2_Gain;

    /* Gain: '<S20>/Gain3' incorporates:
     *  Gain: '<S20>/Gain1'
     *  Product: '<S20>/Product3'
     *  UnitDelay: '<S20>/Unit Delay1'
     *  UnitDelay: '<S20>/Unit Delay2'
     */
    VELOCIDAD_COMP_B.Gain3 = VELOCIDAD_COMP_DWork.UnitDelay2_DSTATE /
      VELOCIDAD_COMP_DWork.UnitDelay1_DSTATE * VELOCIDAD_COMP_P.Gain1_Gain_n *
      VELOCIDAD_COMP_P.Gain3_Gain_p;

    /* Sum: '<S20>/Sum3' */
    VELOCIDAD_COMP_B.Sum3 = VELOCIDAD_COMP_B.Gain2 + VELOCIDAD_COMP_B.Gain3;

    /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S19>/Constant'
     *  Logic: '<S4>/Logical Operator'
     *  RelationalOperator: '<S18>/Compare'
     *  RelationalOperator: '<S19>/Compare'
     */
    rtb_DataTypeConversion_a = (real32_T)((VELOCIDAD_COMP_B.Saturation != 0.0F) &&
      (VELOCIDAD_COMP_B.Sum1 >= VELOCIDAD_COMP_P.CompareToConstant1_const) &&
      (VELOCIDAD_COMP_B.Sum1 < VELOCIDAD_COMP_P.CompareToConstant2_const));

    /* DataTypeConversion: '<S21>/Data Type Conversion' incorporates:
     *  Rounding: '<S20>/Rounding Function1'
     */
    rtb_Product_c = (real32_T)floor(rt_roundf_snf(VELOCIDAD_COMP_B.Sum3));
    if (rtIsNaNF(rtb_Product_c) || rtIsInfF(rtb_Product_c)) {
      rtb_Product_c = 0.0F;
    } else {
      rtb_Product_c = (real32_T)fmod(rtb_Product_c, 4.2949673E+9F);
    }

    /* S-Function (nxt_lcd): '<S21>/LCD' incorporates:
     *  DataTypeConversion: '<S21>/Data Type Conversion'
     */
    lcdDisplay(rtb_Product_c < 0.0F ? -(int32_T)(uint32_T)-rtb_Product_c :
               (int32_T)(uint32_T)rtb_Product_c, VELOCIDAD_COMP_ConstP.LCD_p1_d,
               1U, 1U);

    /* Sum: '<S20>/Sum1' incorporates:
     *  Abs: '<S20>/Abs'
     *  Product: '<S20>/Product1'
     *  Sum: '<S4>/Sum1'
     *  UnitDelay: '<S20>/Unit Delay'
     */
    VELOCIDAD_COMP_B.Sum1_b = (real32_T)fabs((VELOCIDAD_COMP_B.Sum -
      VELOCIDAD_COMP_B.Media) * rtb_DataTypeConversion_a) +
      VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_p;

    /* Sum: '<S20>/Sum2' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S19>/Constant'
     *  DataTypeConversion: '<S4>/Data Type Conversion1'
     *  Logic: '<S4>/Logical Operator'
     *  RelationalOperator: '<S18>/Compare'
     *  RelationalOperator: '<S19>/Compare'
     *  UnitDelay: '<S20>/Unit Delay1'
     */
    VELOCIDAD_COMP_B.Sum2 = (real32_T)((VELOCIDAD_COMP_B.Saturation != 0.0F) &&
      (VELOCIDAD_COMP_B.Sum1 >= VELOCIDAD_COMP_P.CompareToConstant1_const) &&
      (VELOCIDAD_COMP_B.Sum1 < VELOCIDAD_COMP_P.CompareToConstant2_const)) +
      VELOCIDAD_COMP_DWork.UnitDelay1_DSTATE;

    /* Sum: '<S20>/Sum4' incorporates:
     *  Abs: '<S20>/Abs1'
     *  Product: '<S20>/Product2'
     *  UnitDelay: '<S20>/Unit Delay2'
     */
    VELOCIDAD_COMP_B.Sum4 = (real32_T)fabs(rtb_DataTypeConversion_a *
      VELOCIDAD_COMP_B.RateTransition) + VELOCIDAD_COMP_DWork.UnitDelay2_DSTATE;
  }
}

/* Model update function */
void VELOCIDAD_COMP_update(void)
{
  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S8>/Unit Delay' */
    VELOCIDAD_COMP_DWork.UnitDelay_DSTATE = VELOCIDAD_COMP_B.Saturation;
  }

  /* Update for Integrator: '<S9>/Integrator' */
  VELOCIDAD_COMP_DWork.Integrator_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S7>/Unit Delay' */
    VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_n = VELOCIDAD_COMP_B.Compare;

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_SYSTEM_E = 0U;
    VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_DSTATE =
      VELOCIDAD_COMP_B.DiscreteTimeIntegrator;
    VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_PrevRese = (int8_T)
      (VELOCIDAD_COMP_B.UnitDelay > 0);

    /* Update for DiscreteTransferFcn: '<S2>/Crd(z) ' */
    VELOCIDAD_COMP_DWork.Crdz_states[1] = VELOCIDAD_COMP_DWork.Crdz_states[0];
    VELOCIDAD_COMP_DWork.Crdz_states[0] = VELOCIDAD_COMP_DWork.Crdz_tmp;
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S17>/Unit Delay' */
    VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_h =
      VELOCIDAD_COMP_B.DataTypeConversion;

    /* Update for DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn' */
    VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states =
      VELOCIDAD_COMP_DWork.DiscreteTransferFcn_tmp;

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_e =
      VELOCIDAD_COMP_B.DataTypeConversion1;

    /* Update for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn' */
    VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states_h =
      VELOCIDAD_COMP_DWork.DiscreteTransferFcn_tmp_e;
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteTransferFcn: '<S2>/Cd(z)' */
    VELOCIDAD_COMP_DWork.Cdz_states[1] = VELOCIDAD_COMP_DWork.Cdz_states[0];
    VELOCIDAD_COMP_DWork.Cdz_states[0] = VELOCIDAD_COMP_DWork.Cdz_tmp;

    /* Update for UnitDelay: '<S3>/Unit Delay' */
    VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_d = VELOCIDAD_COMP_B.Sum1;

    /* Update for RateTransition: '<S1>/Rate Transition' */
    VELOCIDAD_COMP_DWork.RateTransition_Buffer0 = VELOCIDAD_COMP_B.Switch2;
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S20>/Unit Delay' */
    VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_p = VELOCIDAD_COMP_B.Sum1_b;

    /* Update for UnitDelay: '<S20>/Unit Delay1' */
    VELOCIDAD_COMP_DWork.UnitDelay1_DSTATE = VELOCIDAD_COMP_B.Sum2;

    /* Update for UnitDelay: '<S20>/Unit Delay2' */
    VELOCIDAD_COMP_DWork.UnitDelay2_DSTATE = VELOCIDAD_COMP_B.Sum4;
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(VELOCIDAD_COMP_M)!=-1) &&
        !((rtmGetTFinal(VELOCIDAD_COMP_M)-((VELOCIDAD_COMP_M->Timing.clockTick1)
           * 0.005)) > ((VELOCIDAD_COMP_M->Timing.clockTick1) * 0.005) *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(VELOCIDAD_COMP_M, "Simulation finished");
    }

    if (rtmGetStopRequested(VELOCIDAD_COMP_M)) {
      rtmSetErrorStatus(VELOCIDAD_COMP_M, "Simulation finished");
    }
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M)) {
    rt_ertODEUpdateContinuousStates(&VELOCIDAD_COMP_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++VELOCIDAD_COMP_M->Timing.clockTick0;
  VELOCIDAD_COMP_M->Timing.t[0] = rtsiGetSolverStopTime
    (&VELOCIDAD_COMP_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    VELOCIDAD_COMP_M->Timing.clockTick1++;
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.055s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.055, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    VELOCIDAD_COMP_M->Timing.clockTick2++;
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_COMP_M) &&
      VELOCIDAD_COMP_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick3" ensures timer will not overflow during the
     * application lifespan selected.
     */
    VELOCIDAD_COMP_M->Timing.clockTick3++;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void VELOCIDAD_COMP_derivatives(void)
{
  /* Derivatives for Integrator: '<S9>/Integrator' */
  {
    ((StateDerivatives_VELOCIDAD_COMP *) VELOCIDAD_COMP_M->ModelData.derivs)
      ->Integrator_CSTATE = VELOCIDAD_COMP_B.Gain1;
  }
}

/* Model initialize function */
void VELOCIDAD_COMP_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)VELOCIDAD_COMP_M, 0,
                sizeof(RT_MODEL_VELOCIDAD_COMP));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&VELOCIDAD_COMP_M->solverInfo,
                          &VELOCIDAD_COMP_M->Timing.simTimeStep);
    rtsiSetTPtr(&VELOCIDAD_COMP_M->solverInfo, &rtmGetTPtr(VELOCIDAD_COMP_M));
    rtsiSetStepSizePtr(&VELOCIDAD_COMP_M->solverInfo,
                       &VELOCIDAD_COMP_M->Timing.stepSize0);
    rtsiSetdXPtr(&VELOCIDAD_COMP_M->solverInfo,
                 &VELOCIDAD_COMP_M->ModelData.derivs);
    rtsiSetContStatesPtr(&VELOCIDAD_COMP_M->solverInfo, (real_T **)
                         &VELOCIDAD_COMP_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&VELOCIDAD_COMP_M->solverInfo,
      &VELOCIDAD_COMP_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&VELOCIDAD_COMP_M->solverInfo, (&rtmGetErrorStatus
      (VELOCIDAD_COMP_M)));
    rtsiSetRTModelPtr(&VELOCIDAD_COMP_M->solverInfo, VELOCIDAD_COMP_M);
  }

  rtsiSetSimTimeStep(&VELOCIDAD_COMP_M->solverInfo, MAJOR_TIME_STEP);
  VELOCIDAD_COMP_M->ModelData.intgData.y = VELOCIDAD_COMP_M->ModelData.odeY;
  VELOCIDAD_COMP_M->ModelData.intgData.f[0] = VELOCIDAD_COMP_M->ModelData.odeF[0];
  VELOCIDAD_COMP_M->ModelData.intgData.f[1] = VELOCIDAD_COMP_M->ModelData.odeF[1];
  VELOCIDAD_COMP_M->ModelData.intgData.f[2] = VELOCIDAD_COMP_M->ModelData.odeF[2];
  VELOCIDAD_COMP_M->ModelData.contStates = ((ContinuousStates_VELOCIDAD_COMP *)
    &VELOCIDAD_COMP_X);
  rtsiSetSolverData(&VELOCIDAD_COMP_M->solverInfo, (void *)
                    &VELOCIDAD_COMP_M->ModelData.intgData);
  rtsiSetSolverName(&VELOCIDAD_COMP_M->solverInfo,"ode3");
  rtmSetTPtr(VELOCIDAD_COMP_M, &VELOCIDAD_COMP_M->Timing.tArray[0]);
  rtmSetTFinal(VELOCIDAD_COMP_M, -1);
  VELOCIDAD_COMP_M->Timing.stepSize0 = 0.005;
  rtmSetFirstInitCond(VELOCIDAD_COMP_M, 1);

  /* External mode info */
  VELOCIDAD_COMP_M->Sizes.checksums[0] = (2632590607U);
  VELOCIDAD_COMP_M->Sizes.checksums[1] = (3999490651U);
  VELOCIDAD_COMP_M->Sizes.checksums[2] = (3896188434U);
  VELOCIDAD_COMP_M->Sizes.checksums[3] = (4034353658U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    VELOCIDAD_COMP_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(VELOCIDAD_COMP_M->extModeInfo,
      &VELOCIDAD_COMP_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(VELOCIDAD_COMP_M->extModeInfo,
                        VELOCIDAD_COMP_M->Sizes.checksums);
    rteiSetTPtr(VELOCIDAD_COMP_M->extModeInfo, rtmGetTPtr(VELOCIDAD_COMP_M));
  }

  /* block I/O */
  (void) memset(((void *) &VELOCIDAD_COMP_B), 0,
                sizeof(BlockIO_VELOCIDAD_COMP));

  /* states (continuous) */
  {
    (void) memset((void *)&VELOCIDAD_COMP_X, 0,
                  sizeof(ContinuousStates_VELOCIDAD_COMP));
  }

  /* states (dwork) */
  (void) memset((void *)&VELOCIDAD_COMP_DWork, 0,
                sizeof(D_Work_VELOCIDAD_COMP));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    VELOCIDAD_COMP_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (nxt_light_sensor): '<Root>/Light Sensor' */
  initLightSensor(4U);

  /* Start for RateTransition: '<S1>/Rate Transition' */
  VELOCIDAD_COMP_B.RateTransition = VELOCIDAD_COMP_P.RateTransition_X0;
  VELOCIDAD_COMP_PrevZCSigState.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  VELOCIDAD_COMP_DWork.UnitDelay_DSTATE =
    VELOCIDAD_COMP_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  if (rtmIsFirstInitCond(VELOCIDAD_COMP_M)) {
    VELOCIDAD_COMP_X.Integrator_CSTATE = 0.0;
  }

  VELOCIDAD_COMP_DWork.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_n =
    VELOCIDAD_COMP_P.UnitDelay_InitialCondition_a;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_DSTATE =
    VELOCIDAD_COMP_P.DiscreteTimeIntegrator_IC;
  VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/Crd(z) ' */
  VELOCIDAD_COMP_DWork.Crdz_states[0] = VELOCIDAD_COMP_P.Crdz_InitialStates;
  VELOCIDAD_COMP_DWork.Crdz_states[1] = VELOCIDAD_COMP_P.Crdz_InitialStates;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_h =
    VELOCIDAD_COMP_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn' */
  VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states =
    VELOCIDAD_COMP_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
  VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_e =
    VELOCIDAD_COMP_P.UnitDelay_InitialCondition_p;

  /* InitializeConditions for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn' */
  VELOCIDAD_COMP_DWork.DiscreteTransferFcn_states_h =
    VELOCIDAD_COMP_P.DiscreteTransferFcn_InitialSt_p;

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/Cd(z)' */
  VELOCIDAD_COMP_DWork.Cdz_states[0] = VELOCIDAD_COMP_P.Cdz_InitialStates;
  VELOCIDAD_COMP_DWork.Cdz_states[1] = VELOCIDAD_COMP_P.Cdz_InitialStates;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_d =
    VELOCIDAD_COMP_P.UnitDelay_InitialCondition_f2;

  /* InitializeConditions for RateTransition: '<S1>/Rate Transition' */
  VELOCIDAD_COMP_DWork.RateTransition_Buffer0 =
    VELOCIDAD_COMP_P.RateTransition_X0;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay' */
  VELOCIDAD_COMP_DWork.UnitDelay_DSTATE_p =
    VELOCIDAD_COMP_P.UnitDelay_InitialCondition_h;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
  VELOCIDAD_COMP_DWork.UnitDelay1_DSTATE =
    VELOCIDAD_COMP_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
  VELOCIDAD_COMP_DWork.UnitDelay2_DSTATE =
    VELOCIDAD_COMP_P.UnitDelay2_InitialCondition;

  /* Enable for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  VELOCIDAD_COMP_DWork.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(VELOCIDAD_COMP_M)) {
    rtmSetFirstInitCond(VELOCIDAD_COMP_M, 0);
  }
}

/* Model terminate function */
void VELOCIDAD_COMP_terminate(void)
{
  /* Terminate for S-Function (nxt_light_sensor): '<Root>/Light Sensor' */
  terminateLightSensor(4U);

  /* Terminate for S-Function (nxt_motor): '<S5>/Motor' */
  terminateMotor(3U, 2U);

  /* Terminate for S-Function (nxt_motor): '<S6>/Motor' */
  terminateMotor(2U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
