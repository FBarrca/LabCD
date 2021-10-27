/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SEGWAY_RT_SFR.c
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
#include "SEGWAY_RT_SFR_dt.h"
#include "nxt_util.h"

/* Block signals (auto storage) */
BlockIO_SEGWAY_RT_SFR SEGWAY_RT_SFR_B;

/* Continuous states */
ContinuousStates_SEGWAY_RT_SFR SEGWAY_RT_SFR_X;

/* Block states (auto storage) */
D_Work_SEGWAY_RT_SFR SEGWAY_RT_SFR_DWork;

/* Real-time model */
RT_MODEL_SEGWAY_RT_SFR SEGWAY_RT_SFR_M_;
RT_MODEL_SEGWAY_RT_SFR *const SEGWAY_RT_SFR_M = &SEGWAY_RT_SFR_M_;
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
  (SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[2])++;
  if ((SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.1s, 0.0s] */
    SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[2] = 0;
  }

  (SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[3])++;
  if ((SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[3]) > 39) {/* Sample time: [0.2s, 0.0s] */
    SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  SEGWAY_RT_SFR_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  SEGWAY_RT_SFR_output();
  SEGWAY_RT_SFR_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  SEGWAY_RT_SFR_output();
  SEGWAY_RT_SFR_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  SEGWAY_RT_SFR_output();
  SEGWAY_RT_SFR_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void SEGWAY_RT_SFR_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator;
  int8_T rtb_Button_0;
  uint16_T rtb_Battery_0;
  int8_T tmp;
  int8_T tmp_0;
  uint32_T rtb_Timer_0;
  real32_T rtb_DataTypeConversion_n;
  int16_T rtb_GyroSensor;
  int16_T rtb_AccelerationSensor_o1;
  int16_T rtb_AccelerationSensor_o2;
  int16_T rtb_AccelerationSensor_o3;
  int32_T rtb_EncoderL;
  int32_T rtb_EncoderR;
  real32_T rtb_Gain_f;
  real32_T rtb_Add1;
  real32_T rtb_Sum7;
  int32_T rtb_DataTypeConversion2_idx_0;
  int32_T rtb_DataTypeConversion2_idx_1;
  real32_T tmp_1;
  if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&SEGWAY_RT_SFR_M->solverInfo,
                          ((SEGWAY_RT_SFR_M->Timing.clockTick0+1)*
      SEGWAY_RT_SFR_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SEGWAY_RT_SFR_M)) {
    SEGWAY_RT_SFR_M->Timing.t[0] = rtsiGetT(&SEGWAY_RT_SFR_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(SEGWAY_RT_SFR_DWork.Audio_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(SEGWAY_RT_SFR_DWork.Calculodelamediadelamedidadelgi);

  /* Reset subsysRan breadcrumbs */
  srClearBC(SEGWAY_RT_SFR_DWork.Estimadordeestado_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_Subs);
  if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
      SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (nxt_button): '<S7>/Button' */
    rtb_Button_0 = pressButton(1U);

    /* Switch: '<S7>/Switch' incorporates:
     *  DataTypeConversion: '<S7>/Data Type Conversion'
     *  S-Function (nxt_button): '<S7>/Button'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    if (rtb_Button_0 >= SEGWAY_RT_SFR_P.Switch_Threshold) {
      rtb_Sum7 = rtb_Button_0;
    } else {
      rtb_Sum7 = SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE;
    }

    /* End of Switch: '<S7>/Switch' */

    /* Saturate: '<S7>/Saturation' */
    if (rtb_Sum7 > SEGWAY_RT_SFR_P.Saturation_UpperSat) {
      SEGWAY_RT_SFR_B.Saturation = SEGWAY_RT_SFR_P.Saturation_UpperSat;
    } else if (rtb_Sum7 < SEGWAY_RT_SFR_P.Saturation_LowerSat) {
      SEGWAY_RT_SFR_B.Saturation = SEGWAY_RT_SFR_P.Saturation_LowerSat;
    } else {
      SEGWAY_RT_SFR_B.Saturation = rtb_Sum7;
    }

    /* End of Saturate: '<S7>/Saturation' */

    /* S-Function (nxt_battery): '<S8>/Battery' */
    rtb_Battery_0 = getBattery();

    /* Gain: '<S8>/Gain6' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     *  S-Function (nxt_battery): '<S8>/Battery'
     */
    SEGWAY_RT_SFR_B.Gain6 = SEGWAY_RT_SFR_P.Gain6_Gain * (real_T)rtb_Battery_0;
  }

  /* Integrator: '<S8>/Integrator' */
  if (SEGWAY_RT_SFR_DWork.Integrator_IWORK.IcNeedsLoading) {
    SEGWAY_RT_SFR_X.Integrator_CSTATE = SEGWAY_RT_SFR_B.Gain6;
  }

  rtb_Integrator = SEGWAY_RT_SFR_X.Integrator_CSTATE;

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  SEGWAY_RT_SFR_B.DataTypeConversion1 = (real32_T)rtb_Integrator;
  if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
      SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    rtb_DataTypeConversion_n = SEGWAY_RT_SFR_B.DataTypeConversion1;

    /* S-Function (nxt_gyro_sensor): '<Root>/Gyro Sensor' */
    rtb_GyroSensor = getGyroSensorValue(3U, 2U, 600);

    /* S-Function (nxt_accel_sensor): '<Root>/Acceleration Sensor' */
    getAccelSensorValue(SEGWAY_RT_SFR_P.AccelerationSensor_p1,
                        &rtb_AccelerationSensor_o1, &rtb_AccelerationSensor_o2,
                        &rtb_AccelerationSensor_o3);

    /* S-Function (nxt_encoder): '<Root>/Encoder L' */
    rtb_EncoderL = getEncoderValueNoReset(2U);

    /* S-Function (nxt_encoder): '<Root>/Encoder R' */
    rtb_EncoderR = getEncoderValueNoReset(3U);
  }

  /* Outputs for Enabled SubSystem: '<Root>/Medidas y estimacion de estado' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if ((rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
       SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[2] == 0) && rtmIsMajorTimeStep
      (SEGWAY_RT_SFR_M)) {
    if (SEGWAY_RT_SFR_B.Saturation > 0.0F) {
      if (!SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_MODE) {
        SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_MODE = true;
      }
    } else {
      if (SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_MODE) {
        /* Disable for Enabled SubSystem: '<S2>/Audio' */
        if (SEGWAY_RT_SFR_DWork.Audio_MODE) {
          SEGWAY_RT_SFR_DWork.Audio_MODE = false;
        }

        /* End of Disable for SubSystem: '<S2>/Audio' */
        SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_MODE = false;
      }
    }
  }

  if (SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_MODE) {
    if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
        SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function (nxt_timer): '<S2>/Timer' */
      rtb_Timer_0 = getTime();

      /* Gain: '<S2>/Gain' incorporates:
       *  DataTypeConversion: '<S2>/Data Type Conversion1'
       *  S-Function (nxt_timer): '<S2>/Timer'
       */
      rtb_Gain_f = SEGWAY_RT_SFR_P.Gain_Gain_l * (real32_T)rtb_Timer_0;

      /* RelationalOperator: '<S15>/Compare' incorporates:
       *  Constant: '<S15>/Constant'
       */
      SEGWAY_RT_SFR_B.Compare = (rtb_Gain_f < SEGWAY_RT_SFR_P.time_start);

      /* Outputs for Enabled SubSystem: '<S2>/Audio' incorporates:
       *  EnablePort: '<S12>/Enable'
       */
      if (SEGWAY_RT_SFR_B.Compare) {
        if (!SEGWAY_RT_SFR_DWork.Audio_MODE) {
          SEGWAY_RT_SFR_DWork.Audio_MODE = true;
        }

        if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
            SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[3] == 0) {
          /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
           *  Constant: '<S12>/Constant2'
           */
          if (SEGWAY_RT_SFR_P.sound_freq < 4.2949673E+9F) {
            if (SEGWAY_RT_SFR_P.sound_freq >= 0.0F) {
              rtb_Timer_0 = (uint32_T)SEGWAY_RT_SFR_P.sound_freq;
            } else {
              rtb_Timer_0 = 0U;
            }
          } else {
            rtb_Timer_0 = MAX_uint32_T;
          }

          /* End of DataTypeConversion: '<S17>/Data Type Conversion' */

          /* S-Function (nxt_speaker): '<S17>/Speaker' */
          playSoundFreqOnly(rtb_Timer_0, SEGWAY_RT_SFR_P.Speaker_speakerVolume,
                            SEGWAY_RT_SFR_P.Speaker_p4);
        }

        srUpdateBC(SEGWAY_RT_SFR_DWork.Audio_SubsysRanBC);
      } else {
        if (SEGWAY_RT_SFR_DWork.Audio_MODE) {
          SEGWAY_RT_SFR_DWork.Audio_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S2>/Audio' */

      /* Outputs for Enabled SubSystem: '<S2>/Calculo de la media de la medida del giroscopo' incorporates:
       *  EnablePort: '<S13>/Enable'
       */
      if (SEGWAY_RT_SFR_B.Compare) {
        /* Sum: '<S18>/Sum' incorporates:
         *  DataTypeConversion: '<S2>/Data Type Conversion4'
         *  Gain: '<S18>/Gain2'
         *  Gain: '<S18>/Gain3'
         *  UnitDelay: '<S18>/Unit Delay'
         */
        SEGWAY_RT_SFR_B.Sum_k = SEGWAY_RT_SFR_P.Gain3_Gain * (real32_T)
          rtb_GyroSensor + SEGWAY_RT_SFR_P.alfa1 *
          SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_f;
        srUpdateBC(SEGWAY_RT_SFR_DWork.Calculodelamediadelamedidadelgi);
      }

      /* End of Outputs for SubSystem: '<S2>/Calculo de la media de la medida del giroscopo' */

      /* Sum: '<S2>/Add1' incorporates:
       *  DataTypeConversion: '<S2>/Data Type Conversion4'
       */
      rtb_Add1 = (real32_T)rtb_GyroSensor - SEGWAY_RT_SFR_B.Sum_k;

      /* RelationalOperator: '<S14>/Compare' incorporates:
       *  Constant: '<S14>/Constant'
       */
      SEGWAY_RT_SFR_B.Compare_k = (rtb_Gain_f >= SEGWAY_RT_SFR_P.time_start);

      /* DataTypeConversion: '<S2>/Data Type Conversion2' */
      rtb_DataTypeConversion2_idx_0 = rtb_AccelerationSensor_o1;
      rtb_DataTypeConversion2_idx_1 = rtb_AccelerationSensor_o2;

      /* Outputs for Enabled SubSystem: '<S2>/Estimador de estado' incorporates:
       *  EnablePort: '<S16>/Enable'
       */
      if (SEGWAY_RT_SFR_B.Compare_k) {
        /* Sum: '<S31>/Sum' incorporates:
         *  DataTypeConversion: '<S2>/Data Type Conversion5'
         *  Gain: '<S20>/Paso a grados'
         *  Gain: '<S20>/Paso a rad//s'
         *  Gain: '<S31>/Gain2'
         *  Gain: '<S31>/Gain3'
         *  UnitDelay: '<S31>/Unit Delay'
         */
        SEGWAY_RT_SFR_B.Sum = SEGWAY_RT_SFR_P.Calculodelavelocidadapartirdelc *
          (real32_T)rtb_EncoderR * SEGWAY_RT_SFR_P.Pasoarads_Gain *
          SEGWAY_RT_SFR_P.Gain3_Gain_g + SEGWAY_RT_SFR_P.alfa1 *
          SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_o;

        /* DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn' */
        SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_tmp = (SEGWAY_RT_SFR_B.Sum -
          SEGWAY_RT_SFR_P.DiscreteTransferFcn_DenCoef[1] *
          SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_states) /
          SEGWAY_RT_SFR_P.DiscreteTransferFcn_DenCoef[0];

        /* Sum: '<S32>/Sum' incorporates:
         *  Gain: '<S32>/Gain2'
         *  Gain: '<S32>/Gain3'
         *  UnitDelay: '<S32>/Unit Delay'
         */
        SEGWAY_RT_SFR_B.Sum_n = SEGWAY_RT_SFR_P.Gain3_Gain_a * rtb_Add1 +
          SEGWAY_RT_SFR_P.alfa1 * SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_j;

        /* Gain: '<S21>/Gain3' */
        SEGWAY_RT_SFR_B.Gain3 = SEGWAY_RT_SFR_P.Gain3_Gain_f *
          SEGWAY_RT_SFR_B.Sum_n;

        /* Sum: '<S16>/Sum7' incorporates:
         *  DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn'
         */
        rtb_Sum7 = (SEGWAY_RT_SFR_P.DiscreteTransferFcn_NumCoef[0] *
                    SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_tmp +
                    SEGWAY_RT_SFR_P.DiscreteTransferFcn_NumCoef[1] *
                    SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_states) +
          SEGWAY_RT_SFR_B.Gain3;

        /* Sum: '<S29>/Sum' incorporates:
         *  DataTypeConversion: '<S2>/Data Type Conversion3'
         *  Gain: '<S19>/Paso a grados'
         *  Gain: '<S19>/Paso a rad//s'
         *  Gain: '<S29>/Gain2'
         *  Gain: '<S29>/Gain3'
         *  UnitDelay: '<S29>/Unit Delay'
         */
        SEGWAY_RT_SFR_B.Sum_d = SEGWAY_RT_SFR_P.Calculodelavelocidadapartirde_j *
          (real32_T)rtb_EncoderL * SEGWAY_RT_SFR_P.Pasoarads_Gain_j *
          SEGWAY_RT_SFR_P.Gain3_Gain_k + SEGWAY_RT_SFR_P.alfa1 *
          SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_b;

        /* DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
        SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_tmp_c = (SEGWAY_RT_SFR_B.Sum_d -
          SEGWAY_RT_SFR_P.DiscreteTransferFcn_DenCoef_c[1] *
          SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_states_n) /
          SEGWAY_RT_SFR_P.DiscreteTransferFcn_DenCoef_c[0];

        /* Sum: '<S16>/Sum2' incorporates:
         *  DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn'
         */
        rtb_Gain_f = (SEGWAY_RT_SFR_P.DiscreteTransferFcn_NumCoef_c[0] *
                      SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_tmp_c +
                      SEGWAY_RT_SFR_P.DiscreteTransferFcn_NumCoef_c[1] *
                      SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_states_n) +
          SEGWAY_RT_SFR_B.Gain3;

        /* Gain: '<S16>/Gain3' incorporates:
         *  Gain: '<S16>/Gain'
         *  Sum: '<S16>/Sum1'
         */
        SEGWAY_RT_SFR_B.Gain3_l = (rtb_Sum7 + rtb_Gain_f) *
          SEGWAY_RT_SFR_P.Gain_Gain * SEGWAY_RT_SFR_P.R;

        /* DataTypeConversion: '<S22>/Data Type Conversion' */
        tmp_1 = (real32_T)floor(SEGWAY_RT_SFR_B.Gain3_l);
        if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
          tmp_1 = 0.0F;
        } else {
          tmp_1 = (real32_T)fmod(tmp_1, 4.2949673E+9F);
        }

        /* S-Function (nxt_lcd): '<S22>/LCD' incorporates:
         *  DataTypeConversion: '<S22>/Data Type Conversion'
         */
        lcdDisplay(tmp_1 < 0.0F ? -(int32_T)(uint32_T)-tmp_1 : (int32_T)
                   (uint32_T)tmp_1, SEGWAY_RT_SFR_ConstP.LCD_p1, 1U, 1U);

        /* Gain: '<S16>/deg2rad4' incorporates:
         *  Sum: '<S16>/Sum3'
         */
        rtb_Gain_f = (rtb_Sum7 - rtb_Gain_f) * SEGWAY_RT_SFR_P.deg2rad4_Gain;

        /* DataTypeConversion: '<S23>/Data Type Conversion' */
        tmp_1 = (real32_T)floor(rtb_Gain_f);
        if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
          tmp_1 = 0.0F;
        } else {
          tmp_1 = (real32_T)fmod(tmp_1, 4.2949673E+9F);
        }

        /* S-Function (nxt_lcd): '<S23>/LCD' incorporates:
         *  DataTypeConversion: '<S23>/Data Type Conversion'
         */
        lcdDisplay(tmp_1 < 0.0F ? -(int32_T)(uint32_T)-tmp_1 : (int32_T)
                   (uint32_T)tmp_1, SEGWAY_RT_SFR_ConstP.LCD_p1_i, 2U, 1U);

        /* DataTypeConversion: '<S24>/Data Type Conversion' */
        tmp_1 = (real32_T)floor(rtb_Add1);
        if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
          tmp_1 = 0.0F;
        } else {
          tmp_1 = (real32_T)fmod(tmp_1, 4.2949673E+9F);
        }

        /* S-Function (nxt_lcd): '<S24>/LCD' incorporates:
         *  DataTypeConversion: '<S24>/Data Type Conversion'
         */
        lcdDisplay(tmp_1 < 0.0F ? -(int32_T)(uint32_T)-tmp_1 : (int32_T)
                   (uint32_T)tmp_1, SEGWAY_RT_SFR_ConstP.LCD_p1_n, 3U, 1U);

        /* DataTypeConversion: '<S25>/Data Type Conversion' */
        tmp_1 = (real32_T)floor(SEGWAY_RT_SFR_B.Gain3);
        if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
          tmp_1 = 0.0F;
        } else {
          tmp_1 = (real32_T)fmod(tmp_1, 4.2949673E+9F);
        }

        /* S-Function (nxt_lcd): '<S25>/LCD' incorporates:
         *  DataTypeConversion: '<S25>/Data Type Conversion'
         */
        lcdDisplay(tmp_1 < 0.0F ? -(int32_T)(uint32_T)-tmp_1 : (int32_T)
                   (uint32_T)tmp_1, SEGWAY_RT_SFR_ConstP.LCD_p1_h, 4U, 1U);

        /* Sum: '<S16>/Sum4' incorporates:
         *  Math: '<S16>/Math Function'
         *  Math: '<S16>/Math Function1'
         */
        rtb_Gain_f = (real32_T)(rtb_DataTypeConversion2_idx_0 *
          rtb_DataTypeConversion2_idx_0) + (real32_T)
          (rtb_DataTypeConversion2_idx_1 * rtb_DataTypeConversion2_idx_1);

        /* Sqrt: '<S16>/Reciprocal Sqrt' */
        if (rtb_Gain_f > 0.0F) {
          rtb_Gain_f = 1.0F / (real32_T)sqrt(rtb_Gain_f);
        } else if (rtb_Gain_f == 0.0F) {
          rtb_Gain_f = (rtInfF);
        } else {
          rtb_Gain_f = (rtNaNF);
        }

        /* End of Sqrt: '<S16>/Reciprocal Sqrt' */

        /* Product: '<S16>/Product' incorporates:
         *  Gain: '<S16>/deg2rad5'
         */
        rtb_Sum7 = SEGWAY_RT_SFR_P.deg2rad5_Gain * (real32_T)
          rtb_DataTypeConversion2_idx_1 * rtb_Gain_f;

        /* Trigonometry: '<S16>/Trigonometric Function' */
        if (rtb_Sum7 > 1.0F) {
          rtb_Sum7 = 1.0F;
        } else {
          if (rtb_Sum7 < -1.0F) {
            rtb_Sum7 = -1.0F;
          }
        }

        /* Gain: '<S16>/deg2rad2' incorporates:
         *  Trigonometry: '<S16>/Trigonometric Function'
         */
        SEGWAY_RT_SFR_B.deg2rad2_a = SEGWAY_RT_SFR_P.deg2rad2_Gain * (real32_T)
          asin(rtb_Sum7);

        /* Sum: '<S21>/Sum1' incorporates:
         *  Gain: '<S21>/Gain'
         *  Gain: '<S21>/Gain1'
         *  Gain: '<S21>/Gain2'
         *  Sum: '<S21>/Sum'
         *  UnitDelay: '<S21>/Unit Delay'
         */
        SEGWAY_RT_SFR_B.Sum1 = (SEGWAY_RT_SFR_P.ts * SEGWAY_RT_SFR_B.Sum_n +
          SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_o1) * SEGWAY_RT_SFR_P.Gain_Gain_b
          + SEGWAY_RT_SFR_P.Gain2_Gain * SEGWAY_RT_SFR_B.deg2rad2_a;

        /* Gain: '<S21>/Gain4' */
        SEGWAY_RT_SFR_B.Gain4 = SEGWAY_RT_SFR_P.Gain4_Gain *
          SEGWAY_RT_SFR_B.Sum1;

        /* DataTypeConversion: '<S26>/Data Type Conversion' incorporates:
         *  Gain: '<S16>/deg2rad1'
         */
        tmp_1 = (real32_T)floor(SEGWAY_RT_SFR_P.deg2rad1_Gain *
          SEGWAY_RT_SFR_B.Gain4);
        if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
          tmp_1 = 0.0F;
        } else {
          tmp_1 = (real32_T)fmod(tmp_1, 4.2949673E+9F);
        }

        /* S-Function (nxt_lcd): '<S26>/LCD' incorporates:
         *  DataTypeConversion: '<S26>/Data Type Conversion'
         */
        lcdDisplay(tmp_1 < 0.0F ? -(int32_T)(uint32_T)-tmp_1 : (int32_T)
                   (uint32_T)tmp_1, SEGWAY_RT_SFR_ConstP.LCD_p1_p, 5U, 1U);

        /* DataTypeConversion: '<S27>/Data Type Conversion' */
        tmp_1 = (real32_T)floor(SEGWAY_RT_SFR_B.deg2rad2_a);
        if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
          tmp_1 = 0.0F;
        } else {
          tmp_1 = (real32_T)fmod(tmp_1, 4.2949673E+9F);
        }

        /* S-Function (nxt_lcd): '<S27>/LCD' incorporates:
         *  DataTypeConversion: '<S27>/Data Type Conversion'
         */
        lcdDisplay(tmp_1 < 0.0F ? -(int32_T)(uint32_T)-tmp_1 : (int32_T)
                   (uint32_T)tmp_1, SEGWAY_RT_SFR_ConstP.LCD_p1_j, 6U, 1U);
        srUpdateBC(SEGWAY_RT_SFR_DWork.Estimadordeestado_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S2>/Estimador de estado' */
    }

    if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M)) {
      srUpdateBC(SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_Subs);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Medidas y estimacion de estado' */
  if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
      SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S6>/Gain3' incorporates:
     *  SignalConversion: '<S6>/TmpSignal ConversionAtGain3Inport1'
     */
    rtb_Gain_f = (SEGWAY_RT_SFR_P.Gain3_Gain_gu[0] * SEGWAY_RT_SFR_B.Gain3_l +
                  SEGWAY_RT_SFR_P.Gain3_Gain_gu[1] * SEGWAY_RT_SFR_B.Gain3) +
      SEGWAY_RT_SFR_P.Gain3_Gain_gu[2] * SEGWAY_RT_SFR_B.Gain4;

    /* Switch: '<S11>/Switch2' incorporates:
     *  Gain: '<S6>/Gain3'
     *  RelationalOperator: '<S11>/LowerRelop1'
     */
    if (rtb_Gain_f > SEGWAY_RT_SFR_B.DataTypeConversion1) {
      SEGWAY_RT_SFR_B.Switch2 = SEGWAY_RT_SFR_B.DataTypeConversion1;
    } else {
      /* Gain: '<S9>/Gain1' */
      rtb_Sum7 = SEGWAY_RT_SFR_P.Gain1_Gain_a *
        SEGWAY_RT_SFR_B.DataTypeConversion1;

      /* Switch: '<S11>/Switch' incorporates:
       *  RelationalOperator: '<S11>/UpperRelop'
       */
      if (rtb_Gain_f < rtb_Sum7) {
        SEGWAY_RT_SFR_B.Switch2 = rtb_Sum7;
      } else {
        SEGWAY_RT_SFR_B.Switch2 = rtb_Gain_f;
      }

      /* End of Switch: '<S11>/Switch' */
    }

    /* End of Switch: '<S11>/Switch2' */

    /* Switch: '<S10>/Switch2' incorporates:
     *  Constant: '<Root>/Constant1'
     *  RelationalOperator: '<S10>/LowerRelop1'
     */
    if (SEGWAY_RT_SFR_P.Constant1_Value > SEGWAY_RT_SFR_B.DataTypeConversion1) {
      rtb_Gain_f = SEGWAY_RT_SFR_B.DataTypeConversion1;
    } else {
      /* Gain: '<S9>/Gain8' */
      rtb_Gain_f = SEGWAY_RT_SFR_P.Gain8_Gain *
        SEGWAY_RT_SFR_B.DataTypeConversion1;

      /* Switch: '<S10>/Switch' incorporates:
       *  RelationalOperator: '<S10>/UpperRelop'
       */
      if (!(SEGWAY_RT_SFR_P.Constant1_Value < rtb_Gain_f)) {
        rtb_Gain_f = SEGWAY_RT_SFR_P.Constant1_Value;
      }

      /* End of Switch: '<S10>/Switch' */
    }

    /* End of Switch: '<S10>/Switch2' */

    /* Gain: '<S1>/Gain' */
    rtb_Gain_f *= SEGWAY_RT_SFR_P.Gain_Gain_a;

    /* Product: '<S1>/Divide2' incorporates:
     *  Gain: '<S1>/Gain3'
     *  Product: '<S1>/Divide'
     *  Sum: '<S1>/Sum4'
     */
    rtb_Sum7 = 1.0F / rtb_DataTypeConversion_n * (SEGWAY_RT_SFR_B.Switch2 -
      rtb_Gain_f) * SEGWAY_RT_SFR_P.Gain3_Gain_c * SEGWAY_RT_SFR_B.Saturation;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Sum7 > SEGWAY_RT_SFR_P.Saturation_UpperSat_c) {
      rtb_Sum7 = SEGWAY_RT_SFR_P.Saturation_UpperSat_c;
    } else {
      if (rtb_Sum7 < SEGWAY_RT_SFR_P.Saturation_LowerSat_m) {
        rtb_Sum7 = SEGWAY_RT_SFR_P.Saturation_LowerSat_m;
      }
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
     *  Gain: '<S1>/Gain2'
     *  Saturate: '<S1>/Saturation'
     */
    tmp_1 = (real32_T)floor(SEGWAY_RT_SFR_P.Gain2_Gain_p * rtb_Sum7);
    if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
      tmp_1 = 0.0F;
    } else {
      tmp_1 = (real32_T)fmod(tmp_1, 256.0F);
    }

    /* S-Function (nxt_motor): '<S4>/Motor' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     */
    tmp = (int8_T)(tmp_1 < 0.0F ? (int32_T)(int8_T)-(int8_T)(uint8_T)-tmp_1 :
                   (int32_T)(int8_T)(uint8_T)tmp_1);
    setMotor(&tmp, 2U, 2U);

    /* Product: '<S1>/Divide3' incorporates:
     *  Gain: '<S1>/Gain1'
     *  Product: '<S1>/Divide1'
     *  Sum: '<S1>/Sum5'
     */
    rtb_Sum7 = 1.0F / rtb_DataTypeConversion_n * (SEGWAY_RT_SFR_B.Switch2 +
      rtb_Gain_f) * SEGWAY_RT_SFR_P.Gain1_Gain_i * SEGWAY_RT_SFR_B.Saturation;

    /* Saturate: '<S1>/Saturation1' */
    if (rtb_Sum7 > SEGWAY_RT_SFR_P.Saturation1_UpperSat) {
      rtb_Sum7 = SEGWAY_RT_SFR_P.Saturation1_UpperSat;
    } else {
      if (rtb_Sum7 < SEGWAY_RT_SFR_P.Saturation1_LowerSat) {
        rtb_Sum7 = SEGWAY_RT_SFR_P.Saturation1_LowerSat;
      }
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
     *  Gain: '<S1>/Gain4'
     *  Saturate: '<S1>/Saturation1'
     */
    tmp_1 = (real32_T)floor(SEGWAY_RT_SFR_P.Gain4_Gain_l * rtb_Sum7);
    if (rtIsNaNF(tmp_1) || rtIsInfF(tmp_1)) {
      tmp_1 = 0.0F;
    } else {
      tmp_1 = (real32_T)fmod(tmp_1, 256.0F);
    }

    /* S-Function (nxt_motor): '<S5>/Motor' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion2'
     */
    tmp_0 = (int8_T)(tmp_1 < 0.0F ? (int32_T)(int8_T)-(int8_T)(uint8_T)-tmp_1 :
                     (int32_T)(int8_T)(uint8_T)tmp_1);
    setMotor(&tmp_0, 3U, 2U);
  }

  /* Gain: '<S8>/Gain1' incorporates:
   *  Sum: '<S8>/Sum1'
   */
  SEGWAY_RT_SFR_B.Gain1 = (SEGWAY_RT_SFR_B.Gain6 - rtb_Integrator) *
    SEGWAY_RT_SFR_P.Gain1_Gain;
  if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
      SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S6>/deg2rad1' */
    SEGWAY_RT_SFR_B.deg2rad1 = SEGWAY_RT_SFR_P.deg2rad1_Gain_f *
      SEGWAY_RT_SFR_B.Gain4;

    /* Gain: '<S6>/deg2rad2' */
    SEGWAY_RT_SFR_B.deg2rad2 = SEGWAY_RT_SFR_P.deg2rad2_Gain_h *
      SEGWAY_RT_SFR_B.Gain3;
  }
}

/* Model update function */
void SEGWAY_RT_SFR_update(void)
{
  if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
      SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S7>/Unit Delay' */
    SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE = SEGWAY_RT_SFR_B.Saturation;
  }

  /* Update for Integrator: '<S8>/Integrator' */
  SEGWAY_RT_SFR_DWork.Integrator_IWORK.IcNeedsLoading = 0;

  /* Update for Enabled SubSystem: '<Root>/Medidas y estimacion de estado' incorporates:
   *  Update for EnablePort: '<S2>/Enable'
   */
  if (SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_MODE && (rtmIsMajorTimeStep
       (SEGWAY_RT_SFR_M) &&
       SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[1] == 0)) {
    /* Update for Enabled SubSystem: '<S2>/Calculo de la media de la medida del giroscopo' incorporates:
     *  Update for EnablePort: '<S13>/Enable'
     */
    if (SEGWAY_RT_SFR_B.Compare) {
      /* Update for UnitDelay: '<S18>/Unit Delay' */
      SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_f = SEGWAY_RT_SFR_B.Sum_k;
    }

    /* End of Update for SubSystem: '<S2>/Calculo de la media de la medida del giroscopo' */

    /* Update for Enabled SubSystem: '<S2>/Estimador de estado' incorporates:
     *  Update for EnablePort: '<S16>/Enable'
     */
    if (SEGWAY_RT_SFR_B.Compare_k) {
      /* Update for UnitDelay: '<S31>/Unit Delay' */
      SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_o = SEGWAY_RT_SFR_B.Sum;

      /* Update for DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn' */
      SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_states =
        SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_tmp;

      /* Update for UnitDelay: '<S32>/Unit Delay' */
      SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_j = SEGWAY_RT_SFR_B.Sum_n;

      /* Update for UnitDelay: '<S29>/Unit Delay' */
      SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_b = SEGWAY_RT_SFR_B.Sum_d;

      /* Update for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
      SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_states_n =
        SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_tmp_c;

      /* Update for UnitDelay: '<S21>/Unit Delay' */
      SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_o1 = SEGWAY_RT_SFR_B.Sum1;
    }

    /* End of Update for SubSystem: '<S2>/Estimador de estado' */
  }

  /* End of Update for SubSystem: '<Root>/Medidas y estimacion de estado' */

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(SEGWAY_RT_SFR_M)!=-1) &&
        !((rtmGetTFinal(SEGWAY_RT_SFR_M)-((SEGWAY_RT_SFR_M->Timing.clockTick1) *
           0.005)) > ((SEGWAY_RT_SFR_M->Timing.clockTick1) * 0.005) *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(SEGWAY_RT_SFR_M, "Simulation finished");
    }

    if (rtmGetStopRequested(SEGWAY_RT_SFR_M)) {
      rtmSetErrorStatus(SEGWAY_RT_SFR_M, "Simulation finished");
    }
  }

  if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M)) {
    rt_ertODEUpdateContinuousStates(&SEGWAY_RT_SFR_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++SEGWAY_RT_SFR_M->Timing.clockTick0;
  SEGWAY_RT_SFR_M->Timing.t[0] = rtsiGetSolverStopTime
    (&SEGWAY_RT_SFR_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    SEGWAY_RT_SFR_M->Timing.clockTick1++;
  }

  if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
      SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    SEGWAY_RT_SFR_M->Timing.clockTick2++;
  }

  if (rtmIsMajorTimeStep(SEGWAY_RT_SFR_M) &&
      SEGWAY_RT_SFR_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick3" ensures timer will not overflow during the
     * application lifespan selected.
     */
    SEGWAY_RT_SFR_M->Timing.clockTick3++;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void SEGWAY_RT_SFR_derivatives(void)
{
  /* Derivatives for Integrator: '<S8>/Integrator' */
  {
    ((StateDerivatives_SEGWAY_RT_SFR *) SEGWAY_RT_SFR_M->ModelData.derivs)
      ->Integrator_CSTATE = SEGWAY_RT_SFR_B.Gain1;
  }
}

/* Model initialize function */
void SEGWAY_RT_SFR_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SEGWAY_RT_SFR_M, 0,
                sizeof(RT_MODEL_SEGWAY_RT_SFR));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SEGWAY_RT_SFR_M->solverInfo,
                          &SEGWAY_RT_SFR_M->Timing.simTimeStep);
    rtsiSetTPtr(&SEGWAY_RT_SFR_M->solverInfo, &rtmGetTPtr(SEGWAY_RT_SFR_M));
    rtsiSetStepSizePtr(&SEGWAY_RT_SFR_M->solverInfo,
                       &SEGWAY_RT_SFR_M->Timing.stepSize0);
    rtsiSetdXPtr(&SEGWAY_RT_SFR_M->solverInfo,
                 &SEGWAY_RT_SFR_M->ModelData.derivs);
    rtsiSetContStatesPtr(&SEGWAY_RT_SFR_M->solverInfo, (real_T **)
                         &SEGWAY_RT_SFR_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&SEGWAY_RT_SFR_M->solverInfo,
      &SEGWAY_RT_SFR_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&SEGWAY_RT_SFR_M->solverInfo, (&rtmGetErrorStatus
      (SEGWAY_RT_SFR_M)));
    rtsiSetRTModelPtr(&SEGWAY_RT_SFR_M->solverInfo, SEGWAY_RT_SFR_M);
  }

  rtsiSetSimTimeStep(&SEGWAY_RT_SFR_M->solverInfo, MAJOR_TIME_STEP);
  SEGWAY_RT_SFR_M->ModelData.intgData.y = SEGWAY_RT_SFR_M->ModelData.odeY;
  SEGWAY_RT_SFR_M->ModelData.intgData.f[0] = SEGWAY_RT_SFR_M->ModelData.odeF[0];
  SEGWAY_RT_SFR_M->ModelData.intgData.f[1] = SEGWAY_RT_SFR_M->ModelData.odeF[1];
  SEGWAY_RT_SFR_M->ModelData.intgData.f[2] = SEGWAY_RT_SFR_M->ModelData.odeF[2];
  SEGWAY_RT_SFR_M->ModelData.intgData.f[3] = SEGWAY_RT_SFR_M->ModelData.odeF[3];
  SEGWAY_RT_SFR_M->ModelData.contStates = ((ContinuousStates_SEGWAY_RT_SFR *)
    &SEGWAY_RT_SFR_X);
  rtsiSetSolverData(&SEGWAY_RT_SFR_M->solverInfo, (void *)
                    &SEGWAY_RT_SFR_M->ModelData.intgData);
  rtsiSetSolverName(&SEGWAY_RT_SFR_M->solverInfo,"ode4");
  rtmSetTPtr(SEGWAY_RT_SFR_M, &SEGWAY_RT_SFR_M->Timing.tArray[0]);
  rtmSetTFinal(SEGWAY_RT_SFR_M, -1);
  SEGWAY_RT_SFR_M->Timing.stepSize0 = 0.005;
  rtmSetFirstInitCond(SEGWAY_RT_SFR_M, 1);

  /* External mode info */
  SEGWAY_RT_SFR_M->Sizes.checksums[0] = (4215976138U);
  SEGWAY_RT_SFR_M->Sizes.checksums[1] = (3580249616U);
  SEGWAY_RT_SFR_M->Sizes.checksums[2] = (3721286669U);
  SEGWAY_RT_SFR_M->Sizes.checksums[3] = (2351659707U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    SEGWAY_RT_SFR_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&SEGWAY_RT_SFR_DWork.Audio_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &SEGWAY_RT_SFR_DWork.Calculodelamediadelamedidadelgi;
    systemRan[5] = (sysRanDType *)
      &SEGWAY_RT_SFR_DWork.Estimadordeestado_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &SEGWAY_RT_SFR_DWork.Medidasyestimaciondeestado_Subs;
    rteiSetModelMappingInfoPtr(SEGWAY_RT_SFR_M->extModeInfo,
      &SEGWAY_RT_SFR_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SEGWAY_RT_SFR_M->extModeInfo,
                        SEGWAY_RT_SFR_M->Sizes.checksums);
    rteiSetTPtr(SEGWAY_RT_SFR_M->extModeInfo, rtmGetTPtr(SEGWAY_RT_SFR_M));
  }

  /* block I/O */
  (void) memset(((void *) &SEGWAY_RT_SFR_B), 0,
                sizeof(BlockIO_SEGWAY_RT_SFR));

  /* states (continuous) */
  {
    (void) memset((void *)&SEGWAY_RT_SFR_X, 0,
                  sizeof(ContinuousStates_SEGWAY_RT_SFR));
  }

  /* states (dwork) */
  (void) memset((void *)&SEGWAY_RT_SFR_DWork, 0,
                sizeof(D_Work_SEGWAY_RT_SFR));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    SEGWAY_RT_SFR_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for Enabled SubSystem: '<Root>/Medidas y estimacion de estado' */
  /* InitializeConditions for Enabled SubSystem: '<S2>/Calculo de la media de la medida del giroscopo' */
  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
  SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_f = SEGWAY_RT_SFR_P.gyro0;

  /* End of InitializeConditions for SubSystem: '<S2>/Calculo de la media de la medida del giroscopo' */

  /* InitializeConditions for Enabled SubSystem: '<S2>/Estimador de estado' */
  /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
  SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_o =
    SEGWAY_RT_SFR_P.UnitDelay_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn' */
  SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_states =
    SEGWAY_RT_SFR_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for UnitDelay: '<S32>/Unit Delay' */
  SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_j =
    SEGWAY_RT_SFR_P.UnitDelay_InitialCondition_o;

  /* InitializeConditions for UnitDelay: '<S29>/Unit Delay' */
  SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_b =
    SEGWAY_RT_SFR_P.UnitDelay_InitialCondition_j;

  /* InitializeConditions for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
  SEGWAY_RT_SFR_DWork.DiscreteTransferFcn_states_n =
    SEGWAY_RT_SFR_P.DiscreteTransferFcn_InitialSt_b;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
  SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE_o1 =
    SEGWAY_RT_SFR_P.UnitDelay_InitialCondition_m;

  /* End of InitializeConditions for SubSystem: '<S2>/Estimador de estado' */
  /* End of Start for SubSystem: '<Root>/Medidas y estimacion de estado' */
  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  SEGWAY_RT_SFR_DWork.UnitDelay_DSTATE =
    SEGWAY_RT_SFR_P.UnitDelay_InitialCondition_d;

  /* InitializeConditions for Integrator: '<S8>/Integrator' */
  if (rtmIsFirstInitCond(SEGWAY_RT_SFR_M)) {
    SEGWAY_RT_SFR_X.Integrator_CSTATE = 0.0;
  }

  SEGWAY_RT_SFR_DWork.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for S-Function (nxt_accel_sensor): '<Root>/Acceleration Sensor' */
  initAccelSensor(SEGWAY_RT_SFR_P.AccelerationSensor_p1);

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(SEGWAY_RT_SFR_M)) {
    rtmSetFirstInitCond(SEGWAY_RT_SFR_M, 0);
  }
}

/* Model terminate function */
void SEGWAY_RT_SFR_terminate(void)
{
  /* Terminate for S-Function (nxt_accel_sensor): '<Root>/Acceleration Sensor' */
  terminateAccelSensor(SEGWAY_RT_SFR_P.AccelerationSensor_p1);

  /* Terminate for S-Function (nxt_motor): '<S4>/Motor' */
  terminateMotor(2U, 2U);

  /* Terminate for S-Function (nxt_motor): '<S5>/Motor' */
  terminateMotor(3U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
