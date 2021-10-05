/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VELOCIDAD.c
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
#include "VELOCIDAD_dt.h"
#include "nxt_util.h"

/* Block signals (auto storage) */
BlockIO_VELOCIDAD VELOCIDAD_B;

/* Continuous states */
ContinuousStates_VELOCIDAD VELOCIDAD_X;

/* Block states (auto storage) */
D_Work_VELOCIDAD VELOCIDAD_DWork;

/* Real-time model */
RT_MODEL_VELOCIDAD VELOCIDAD_M_;
RT_MODEL_VELOCIDAD *const VELOCIDAD_M = &VELOCIDAD_M_;
static void rate_scheduler(void);
real32_T sMultiWord2Single(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real32_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0F;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= (real32_T)ldexp((real32_T)cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += (real32_T)ldexp((real32_T)u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

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
  (VELOCIDAD_M->Timing.TaskCounters.TID[2])++;
  if ((VELOCIDAD_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.1s, 0.0s] */
    VELOCIDAD_M->Timing.TaskCounters.TID[2] = 0;
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
  VELOCIDAD_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  VELOCIDAD_output();
  VELOCIDAD_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  VELOCIDAD_output();
  VELOCIDAD_derivatives();

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

/* Model output function */
void VELOCIDAD_output(void)
{
  int8_T rtb_DataTypeConversion_d_0;
  uint16_T rtb_Battery_0;
  int32_T rtb_EncoderDERECHO_0;
  int8_T tmp;
  int8_T tmp_0;
  real_T rtb_Gain3;
  real32_T rtb_DiscreteTransferFcn;
  int16_T tmp_1;
  int64m_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_4;
  int64m_T tmp_5;
  if (rtmIsMajorTimeStep(VELOCIDAD_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&VELOCIDAD_M->solverInfo,
                          ((VELOCIDAD_M->Timing.clockTick0+1)*
      VELOCIDAD_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(VELOCIDAD_M)) {
    VELOCIDAD_M->Timing.t[0] = rtsiGetT(&VELOCIDAD_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_M) &&
      VELOCIDAD_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (nxt_button): '<S9>/Button' */
    rtb_DataTypeConversion_d_0 = pressButton(1U);

    /* Switch: '<S9>/Switch' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion'
     *  S-Function (nxt_button): '<S9>/Button'
     *  UnitDelay: '<S9>/Unit Delay'
     */
    if (rtb_DataTypeConversion_d_0 >= VELOCIDAD_P.Switch_Threshold) {
      rtb_DiscreteTransferFcn = rtb_DataTypeConversion_d_0;
    } else {
      rtb_DiscreteTransferFcn = VELOCIDAD_DWork.UnitDelay_DSTATE;
    }

    /* End of Switch: '<S9>/Switch' */

    /* Saturate: '<S9>/Saturation' */
    if (rtb_DiscreteTransferFcn > VELOCIDAD_P.Saturation_UpperSat_b) {
      VELOCIDAD_B.Saturation = VELOCIDAD_P.Saturation_UpperSat_b;
    } else if (rtb_DiscreteTransferFcn < VELOCIDAD_P.Saturation_LowerSat_i) {
      VELOCIDAD_B.Saturation = VELOCIDAD_P.Saturation_LowerSat_i;
    } else {
      VELOCIDAD_B.Saturation = rtb_DiscreteTransferFcn;
    }

    /* End of Saturate: '<S9>/Saturation' */
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_M) &&
      VELOCIDAD_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (nxt_battery): '<S10>/Battery' */
    rtb_Battery_0 = getBattery();

    /* Gain: '<S10>/Gain6' incorporates:
     *  DataTypeConversion: '<S10>/Data Type Conversion'
     *  S-Function (nxt_battery): '<S10>/Battery'
     */
    VELOCIDAD_B.Gain6 = VELOCIDAD_P.Gain6_Gain * (real_T)rtb_Battery_0;
  }

  /* Integrator: '<S10>/Integrator' */
  if (VELOCIDAD_DWork.Integrator_IWORK.IcNeedsLoading) {
    VELOCIDAD_X.Integrator_CSTATE = VELOCIDAD_B.Gain6;
  }

  VELOCIDAD_B.Integrator = VELOCIDAD_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(VELOCIDAD_M) &&
      VELOCIDAD_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscretePulseGenerator: '<S8>/Tension comun' */
    rtb_Gain3 = (VELOCIDAD_DWork.clockTickCounter < floor(0.5 / VELOCIDAD_P.ts))
      && (VELOCIDAD_DWork.clockTickCounter >= 0) ? VELOCIDAD_P.Tensioncomun_Amp :
      0.0;
    if (VELOCIDAD_DWork.clockTickCounter >= floor(1.0 / VELOCIDAD_P.ts) - 1.0) {
      VELOCIDAD_DWork.clockTickCounter = 0;
    } else {
      VELOCIDAD_DWork.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S8>/Tension comun' */

    /* Sum: '<S8>/Sum' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Gain3 += VELOCIDAD_P.Constant_Value;

    /* UnitDelay: '<S7>/Unit Delay' */
    VELOCIDAD_B.UnitDelay = VELOCIDAD_DWork.UnitDelay_DSTATE_c;

    /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    if (VELOCIDAD_DWork.DiscreteTimeIntegrator_SYSTEM_E != 0) {
      VELOCIDAD_B.DiscreteTimeIntegrator =
        VELOCIDAD_DWork.DiscreteTimeIntegrator_DSTATE;
    } else if ((VELOCIDAD_B.UnitDelay > 0) &&
               (VELOCIDAD_DWork.DiscreteTimeIntegrator_PrevRese <= 0)) {
      VELOCIDAD_DWork.DiscreteTimeIntegrator_DSTATE =
        VELOCIDAD_P.DiscreteTimeIntegrator_IC;
      VELOCIDAD_B.DiscreteTimeIntegrator =
        VELOCIDAD_DWork.DiscreteTimeIntegrator_DSTATE;
    } else {
      VELOCIDAD_B.DiscreteTimeIntegrator =
        VELOCIDAD_P.DiscreteTimeIntegrator_gainval * VELOCIDAD_B.Saturation +
        VELOCIDAD_DWork.DiscreteTimeIntegrator_DSTATE;
    }

    /* End of DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */

    /* Sum: '<S7>/Sum' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S7>/ang_ref maximo4'
     *  Gain: '<S7>/Gain1'
     *  RelationalOperator: '<S16>/Compare'
     */
    VELOCIDAD_B.Sum = (real32_T)((real_T)(VELOCIDAD_B.DiscreteTimeIntegrator >=
      VELOCIDAD_P.Detecciondesector_const) *
      VELOCIDAD_P.Referenciavelocidad_Vmin) + VELOCIDAD_P.ang_refmaximo4_Value;

    /* S-Function (nxt_encoder): '<Root>/Encoder IZQUIERDO' */
    rtb_EncoderDERECHO_0 = getEncoderValueNoReset(2U);

    /* Gain: '<S13>/Gain2' incorporates:
     *  S-Function (nxt_encoder): '<Root>/Encoder IZQUIERDO'
     */
    tmp_3 = (uint32_T)VELOCIDAD_P.Gain2_Gain;
    tmp_4 = (uint32_T)rtb_EncoderDERECHO_0;
    sMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_2.chunks[0U], 2);

    /* DataTypeConversion: '<S13>/Data Type Conversion' */
    VELOCIDAD_B.DataTypeConversion = sMultiWord2Single(&tmp_2.chunks[0U], 2, 0) *
      9.31322575E-10F;

    /* Gain: '<S15>/Radio' incorporates:
     *  Gain: '<S15>/Paso a rad//s'
     *  Gain: '<S15>/Radio1'
     *  Sum: '<S15>/Sum'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    VELOCIDAD_B.Radio = (VELOCIDAD_B.DataTypeConversion -
                         VELOCIDAD_DWork.UnitDelay_DSTATE_h) *
      VELOCIDAD_P.Radio1_Gain * VELOCIDAD_P.Pasoarads_Gain * VELOCIDAD_P.R;

    /* DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn' */
    VELOCIDAD_DWork.DiscreteTransferFcn_tmp = (VELOCIDAD_B.Radio -
      VELOCIDAD_P.DiscreteTransferFcn_DenCoef[1] *
      VELOCIDAD_DWork.DiscreteTransferFcn_states) /
      VELOCIDAD_P.DiscreteTransferFcn_DenCoef[0];

    /* S-Function (nxt_encoder): '<Root>/Encoder DERECHO' */
    rtb_EncoderDERECHO_0 = getEncoderValueNoReset(3U);

    /* Gain: '<S13>/Gain1' incorporates:
     *  S-Function (nxt_encoder): '<Root>/Encoder DERECHO'
     */
    tmp_3 = (uint32_T)VELOCIDAD_P.Gain1_Gain_f;
    tmp_4 = (uint32_T)rtb_EncoderDERECHO_0;
    sMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_5.chunks[0U], 2);

    /* DataTypeConversion: '<S13>/Data Type Conversion1' */
    VELOCIDAD_B.DataTypeConversion1 = sMultiWord2Single(&tmp_5.chunks[0U], 2, 0)
      * 9.31322575E-10F;

    /* Gain: '<S14>/Radio' incorporates:
     *  Gain: '<S14>/Paso a rad//s'
     *  Gain: '<S14>/Radio1'
     *  Sum: '<S14>/Sum'
     *  UnitDelay: '<S14>/Unit Delay'
     */
    VELOCIDAD_B.Radio_l = (VELOCIDAD_B.DataTypeConversion1 -
      VELOCIDAD_DWork.UnitDelay_DSTATE_e) * VELOCIDAD_P.Radio1_Gain_d *
      VELOCIDAD_P.Pasoarads_Gain_a * VELOCIDAD_P.R;

    /* DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' */
    VELOCIDAD_DWork.DiscreteTransferFcn_tmp_e = (VELOCIDAD_B.Radio_l -
      VELOCIDAD_P.DiscreteTransferFcn_DenCoef_a[1] *
      VELOCIDAD_DWork.DiscreteTransferFcn_states_h) /
      VELOCIDAD_P.DiscreteTransferFcn_DenCoef_a[0];

    /* Gain: '<S13>/Media' incorporates:
     *  DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn'
     *  DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn'
     *  Sum: '<S13>/Sum7'
     */
    VELOCIDAD_B.Media = ((VELOCIDAD_P.DiscreteTransferFcn_NumCoef[0] *
                          VELOCIDAD_DWork.DiscreteTransferFcn_tmp +
                          VELOCIDAD_P.DiscreteTransferFcn_NumCoef[1] *
                          VELOCIDAD_DWork.DiscreteTransferFcn_states) +
                         (VELOCIDAD_P.DiscreteTransferFcn_NumCoef_m[0] *
                          VELOCIDAD_DWork.DiscreteTransferFcn_tmp_e +
                          VELOCIDAD_P.DiscreteTransferFcn_NumCoef_m[1] *
                          VELOCIDAD_DWork.DiscreteTransferFcn_states_h)) *
      VELOCIDAD_P.Media_Gain;

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     *  Gain: '<S2>/Gain2'
     *  Product: '<S8>/Divide2'
     *  Sum: '<S2>/Sum1'
     */
    if (VELOCIDAD_P.ManualSwitch_CurrentSetting == 1) {
      rtb_DiscreteTransferFcn = (real32_T)rtb_Gain3 * VELOCIDAD_B.Saturation;
    } else {
      rtb_DiscreteTransferFcn = (VELOCIDAD_B.Sum - VELOCIDAD_B.Media) *
        VELOCIDAD_P.K;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* Switch: '<S12>/Switch2' incorporates:
     *  RelationalOperator: '<S12>/LowerRelop1'
     */
    if (rtb_DiscreteTransferFcn > VELOCIDAD_B.Integrator) {
      VELOCIDAD_B.Switch2 = (real32_T)VELOCIDAD_B.Integrator;
    } else {
      /* Gain: '<S11>/Gain8' */
      rtb_Gain3 = VELOCIDAD_P.Gain8_Gain * VELOCIDAD_B.Integrator;

      /* Switch: '<S12>/Switch' incorporates:
       *  RelationalOperator: '<S12>/UpperRelop'
       */
      if (rtb_DiscreteTransferFcn < rtb_Gain3) {
        VELOCIDAD_B.Switch2 = (real32_T)rtb_Gain3;
      } else {
        VELOCIDAD_B.Switch2 = rtb_DiscreteTransferFcn;
      }

      /* End of Switch: '<S12>/Switch' */
    }

    /* End of Switch: '<S12>/Switch2' */

    /* Product: '<S1>/Divide3' incorporates:
     *  Constant: '<Root>/Constant'
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  Gain: '<S1>/Gain1'
     *  Product: '<S1>/Divide1'
     *  Sum: '<S1>/Sum5'
     */
    rtb_Gain3 = (VELOCIDAD_B.Switch2 + VELOCIDAD_P.Constant_Value_m) / (real32_T)
      VELOCIDAD_B.Integrator * VELOCIDAD_P.Gain1_Gain * VELOCIDAD_B.Saturation;

    /* Saturate: '<S1>/Saturation1' */
    if (rtb_Gain3 > VELOCIDAD_P.Saturation1_UpperSat) {
      rtb_Gain3 = VELOCIDAD_P.Saturation1_UpperSat;
    } else {
      if (rtb_Gain3 < VELOCIDAD_P.Saturation1_LowerSat) {
        rtb_Gain3 = VELOCIDAD_P.Saturation1_LowerSat;
      }
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
     *  Saturate: '<S1>/Saturation1'
     */
    rtb_Gain3 = floor(rtb_Gain3);
    if (rtIsNaN(rtb_Gain3) || rtIsInf(rtb_Gain3)) {
      rtb_Gain3 = 0.0;
    } else {
      rtb_Gain3 = fmod(rtb_Gain3, 256.0);
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion2'
     *  Gain: '<S1>/Gain4'
     */
    tmp_1 = (int16_T)((rtb_Gain3 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                       -rtb_Gain3 : (int32_T)(int8_T)(uint8_T)rtb_Gain3) *
                      VELOCIDAD_P.Gain4_Gain >> 6);
    if (tmp_1 > 127) {
      tmp_1 = 127;
    } else {
      if (tmp_1 < -128) {
        tmp_1 = -128;
      }
    }

    /* S-Function (nxt_motor): '<S5>/Motor' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion'
     */
    tmp = (int8_T)tmp_1;
    setMotor(&tmp, 3U, 2U);

    /* Product: '<S1>/Divide2' incorporates:
     *  Constant: '<Root>/Constant'
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  Gain: '<S1>/Gain3'
     *  Product: '<S1>/Divide'
     *  Sum: '<S1>/Sum4'
     */
    rtb_Gain3 = (VELOCIDAD_B.Switch2 - VELOCIDAD_P.Constant_Value_m) / (real32_T)
      VELOCIDAD_B.Integrator * VELOCIDAD_P.Gain3_Gain * VELOCIDAD_B.Saturation;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Gain3 > VELOCIDAD_P.Saturation_UpperSat) {
      rtb_Gain3 = VELOCIDAD_P.Saturation_UpperSat;
    } else {
      if (rtb_Gain3 < VELOCIDAD_P.Saturation_LowerSat) {
        rtb_Gain3 = VELOCIDAD_P.Saturation_LowerSat;
      }
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
     *  Saturate: '<S1>/Saturation'
     */
    rtb_Gain3 = floor(rtb_Gain3);
    if (rtIsNaN(rtb_Gain3) || rtIsInf(rtb_Gain3)) {
      rtb_Gain3 = 0.0;
    } else {
      rtb_Gain3 = fmod(rtb_Gain3, 256.0);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     *  Gain: '<S1>/Gain2'
     */
    tmp_1 = (int16_T)((rtb_Gain3 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                       -rtb_Gain3 : (int32_T)(int8_T)(uint8_T)rtb_Gain3) *
                      VELOCIDAD_P.Gain2_Gain_h >> 6);
    if (tmp_1 > 127) {
      tmp_1 = 127;
    } else {
      if (tmp_1 < -128) {
        tmp_1 = -128;
      }
    }

    /* S-Function (nxt_motor): '<S6>/Motor' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     */
    tmp_0 = (int8_T)tmp_1;
    setMotor(&tmp_0, 2U, 2U);
  }

  /* Gain: '<S10>/Gain1' incorporates:
   *  Sum: '<S10>/Sum1'
   */
  VELOCIDAD_B.Gain1 = (VELOCIDAD_B.Gain6 - VELOCIDAD_B.Integrator) *
    VELOCIDAD_P.Gain1_Gain_l;
  if (rtmIsMajorTimeStep(VELOCIDAD_M) &&
      VELOCIDAD_M->Timing.TaskCounters.TID[1] == 0) {
    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     */
    VELOCIDAD_B.Compare = (uint8_T)(VELOCIDAD_B.DiscreteTimeIntegrator >=
      VELOCIDAD_P.Referenciavelocidad_T);
  }
}

/* Model update function */
void VELOCIDAD_update(void)
{
  if (rtmIsMajorTimeStep(VELOCIDAD_M) &&
      VELOCIDAD_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S9>/Unit Delay' */
    VELOCIDAD_DWork.UnitDelay_DSTATE = VELOCIDAD_B.Saturation;
  }

  /* Update for Integrator: '<S10>/Integrator' */
  VELOCIDAD_DWork.Integrator_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(VELOCIDAD_M) &&
      VELOCIDAD_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S7>/Unit Delay' */
    VELOCIDAD_DWork.UnitDelay_DSTATE_c = VELOCIDAD_B.Compare;

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    VELOCIDAD_DWork.DiscreteTimeIntegrator_SYSTEM_E = 0U;
    VELOCIDAD_DWork.DiscreteTimeIntegrator_DSTATE =
      VELOCIDAD_B.DiscreteTimeIntegrator;
    VELOCIDAD_DWork.DiscreteTimeIntegrator_PrevRese = (int8_T)
      (VELOCIDAD_B.UnitDelay > 0);

    /* Update for UnitDelay: '<S15>/Unit Delay' */
    VELOCIDAD_DWork.UnitDelay_DSTATE_h = VELOCIDAD_B.DataTypeConversion;

    /* Update for DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn' */
    VELOCIDAD_DWork.DiscreteTransferFcn_states =
      VELOCIDAD_DWork.DiscreteTransferFcn_tmp;

    /* Update for UnitDelay: '<S14>/Unit Delay' */
    VELOCIDAD_DWork.UnitDelay_DSTATE_e = VELOCIDAD_B.DataTypeConversion1;

    /* Update for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' */
    VELOCIDAD_DWork.DiscreteTransferFcn_states_h =
      VELOCIDAD_DWork.DiscreteTransferFcn_tmp_e;
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(VELOCIDAD_M)!=-1) &&
        !((rtmGetTFinal(VELOCIDAD_M)-((VELOCIDAD_M->Timing.clockTick1) * 0.005))
          > ((VELOCIDAD_M->Timing.clockTick1) * 0.005) * (DBL_EPSILON))) {
      rtmSetErrorStatus(VELOCIDAD_M, "Simulation finished");
    }

    if (rtmGetStopRequested(VELOCIDAD_M)) {
      rtmSetErrorStatus(VELOCIDAD_M, "Simulation finished");
    }
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_M)) {
    rt_ertODEUpdateContinuousStates(&VELOCIDAD_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++VELOCIDAD_M->Timing.clockTick0;
  VELOCIDAD_M->Timing.t[0] = rtsiGetSolverStopTime(&VELOCIDAD_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    VELOCIDAD_M->Timing.clockTick1++;
  }

  if (rtmIsMajorTimeStep(VELOCIDAD_M) &&
      VELOCIDAD_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    VELOCIDAD_M->Timing.clockTick2++;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void VELOCIDAD_derivatives(void)
{
  /* Derivatives for Integrator: '<S10>/Integrator' */
  {
    ((StateDerivatives_VELOCIDAD *) VELOCIDAD_M->ModelData.derivs)
      ->Integrator_CSTATE = VELOCIDAD_B.Gain1;
  }
}

/* Model initialize function */
void VELOCIDAD_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)VELOCIDAD_M, 0,
                sizeof(RT_MODEL_VELOCIDAD));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&VELOCIDAD_M->solverInfo,
                          &VELOCIDAD_M->Timing.simTimeStep);
    rtsiSetTPtr(&VELOCIDAD_M->solverInfo, &rtmGetTPtr(VELOCIDAD_M));
    rtsiSetStepSizePtr(&VELOCIDAD_M->solverInfo, &VELOCIDAD_M->Timing.stepSize0);
    rtsiSetdXPtr(&VELOCIDAD_M->solverInfo, &VELOCIDAD_M->ModelData.derivs);
    rtsiSetContStatesPtr(&VELOCIDAD_M->solverInfo, (real_T **)
                         &VELOCIDAD_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&VELOCIDAD_M->solverInfo,
      &VELOCIDAD_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&VELOCIDAD_M->solverInfo, (&rtmGetErrorStatus
      (VELOCIDAD_M)));
    rtsiSetRTModelPtr(&VELOCIDAD_M->solverInfo, VELOCIDAD_M);
  }

  rtsiSetSimTimeStep(&VELOCIDAD_M->solverInfo, MAJOR_TIME_STEP);
  VELOCIDAD_M->ModelData.intgData.y = VELOCIDAD_M->ModelData.odeY;
  VELOCIDAD_M->ModelData.intgData.f[0] = VELOCIDAD_M->ModelData.odeF[0];
  VELOCIDAD_M->ModelData.intgData.f[1] = VELOCIDAD_M->ModelData.odeF[1];
  VELOCIDAD_M->ModelData.intgData.f[2] = VELOCIDAD_M->ModelData.odeF[2];
  VELOCIDAD_M->ModelData.contStates = ((ContinuousStates_VELOCIDAD *)
    &VELOCIDAD_X);
  rtsiSetSolverData(&VELOCIDAD_M->solverInfo, (void *)
                    &VELOCIDAD_M->ModelData.intgData);
  rtsiSetSolverName(&VELOCIDAD_M->solverInfo,"ode3");
  rtmSetTPtr(VELOCIDAD_M, &VELOCIDAD_M->Timing.tArray[0]);
  rtmSetTFinal(VELOCIDAD_M, -1);
  VELOCIDAD_M->Timing.stepSize0 = 0.005;
  rtmSetFirstInitCond(VELOCIDAD_M, 1);

  /* External mode info */
  VELOCIDAD_M->Sizes.checksums[0] = (4077541861U);
  VELOCIDAD_M->Sizes.checksums[1] = (2857516295U);
  VELOCIDAD_M->Sizes.checksums[2] = (1847277076U);
  VELOCIDAD_M->Sizes.checksums[3] = (86470824U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    VELOCIDAD_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(VELOCIDAD_M->extModeInfo,
      &VELOCIDAD_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(VELOCIDAD_M->extModeInfo, VELOCIDAD_M->Sizes.checksums);
    rteiSetTPtr(VELOCIDAD_M->extModeInfo, rtmGetTPtr(VELOCIDAD_M));
  }

  /* block I/O */
  (void) memset(((void *) &VELOCIDAD_B), 0,
                sizeof(BlockIO_VELOCIDAD));

  /* states (continuous) */
  {
    (void) memset((void *)&VELOCIDAD_X, 0,
                  sizeof(ContinuousStates_VELOCIDAD));
  }

  /* states (dwork) */
  (void) memset((void *)&VELOCIDAD_DWork, 0,
                sizeof(D_Work_VELOCIDAD));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    VELOCIDAD_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 32;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  VELOCIDAD_DWork.UnitDelay_DSTATE = VELOCIDAD_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  if (rtmIsFirstInitCond(VELOCIDAD_M)) {
    VELOCIDAD_X.Integrator_CSTATE = 0.0;
  }

  VELOCIDAD_DWork.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for DiscretePulseGenerator: '<S8>/Tension comun' */
  VELOCIDAD_DWork.clockTickCounter = 0;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  VELOCIDAD_DWork.UnitDelay_DSTATE_c = VELOCIDAD_P.UnitDelay_InitialCondition_a;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  VELOCIDAD_DWork.DiscreteTimeIntegrator_DSTATE =
    VELOCIDAD_P.DiscreteTimeIntegrator_IC;
  VELOCIDAD_DWork.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
  VELOCIDAD_DWork.UnitDelay_DSTATE_h = VELOCIDAD_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn' */
  VELOCIDAD_DWork.DiscreteTransferFcn_states =
    VELOCIDAD_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
  VELOCIDAD_DWork.UnitDelay_DSTATE_e = VELOCIDAD_P.UnitDelay_InitialCondition_p;

  /* InitializeConditions for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' */
  VELOCIDAD_DWork.DiscreteTransferFcn_states_h =
    VELOCIDAD_P.DiscreteTransferFcn_InitialSt_p;

  /* Enable for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  VELOCIDAD_DWork.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(VELOCIDAD_M)) {
    rtmSetFirstInitCond(VELOCIDAD_M, 0);
  }
}

/* Model terminate function */
void VELOCIDAD_terminate(void)
{
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
