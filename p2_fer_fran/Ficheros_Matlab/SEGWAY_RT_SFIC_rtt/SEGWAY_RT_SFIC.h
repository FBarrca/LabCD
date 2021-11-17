/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SEGWAY_RT_SFIC.h
 *
 * Code generated for Simulink model 'SEGWAY_RT_SFIC'.
 *
 * Model version                  : 1.450
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Nov 17 08:53:16 2021
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SEGWAY_RT_SFIC_h_
#define RTW_HEADER_SEGWAY_RT_SFIC_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef SEGWAY_RT_SFIC_COMMON_INCLUDES_
# define SEGWAY_RT_SFIC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_nxt.h"
#endif                                 /* SEGWAY_RT_SFIC_COMMON_INCLUDES_ */

#include "SEGWAY_RT_SFIC_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Gain6;                        /* '<S8>/Gain6' */
  real_T Gain1;                        /* '<S8>/Gain1' */
  real32_T Saturation;                 /* '<S7>/Saturation' */
  real32_T DataTypeConversion1;        /* '<S8>/Data Type Conversion1' */
  real32_T Switch2;                    /* '<S11>/Switch2' */
  real32_T Sum1;                       /* '<S2>/Sum1' */
  real32_T deg2rad1;                   /* '<Root>/deg2rad1' */
  real32_T deg2rad2;                   /* '<Root>/deg2rad2' */
  real32_T Sum;                        /* '<S31>/Sum' */
  real32_T Sum_d;                      /* '<S29>/Sum' */
  real32_T Gain3;                      /* '<S16>/Gain3' */
  real32_T Sum_n;                      /* '<S32>/Sum' */
  real32_T Gain3_j;                    /* '<S21>/Gain3' */
  real32_T deg2rad2_a;                 /* '<S16>/deg2rad2' */
  real32_T Sum1_m;                     /* '<S21>/Sum1' */
  real32_T Gain4;                      /* '<S21>/Gain4' */
  real32_T Sum_k;                      /* '<S18>/Sum' */
  boolean_T Compare;                   /* '<S15>/Compare' */
  boolean_T Compare_k;                 /* '<S14>/Compare' */
} BlockIO_SEGWAY_RT_SFIC;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Y_PWORK;                           /* '<S4>/Y' */

  real32_T UnitDelay_DSTATE;           /* '<S7>/Unit Delay' */
  real32_T UnitDelay_DSTATE_m;         /* '<S2>/Unit Delay' */
  real32_T Delay2_DSTATE[10];          /* '<Root>/Delay2' */
  real32_T UnitDelay_DSTATE_o;         /* '<S31>/Unit Delay' */
  real32_T DiscreteTransferFcn_states; /* '<S30>/Discrete Transfer Fcn' */
  real32_T UnitDelay_DSTATE_b;         /* '<S29>/Unit Delay' */
  real32_T DiscreteTransferFcn_states_n;/* '<S28>/Discrete Transfer Fcn' */
  real32_T UnitDelay_DSTATE_j;         /* '<S32>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S21>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_o1;        /* '<S21>/Unit Delay' */
  real32_T UnitDelay_DSTATE_f;         /* '<S18>/Unit Delay' */
  real32_T DiscreteTransferFcn_tmp;    /* '<S30>/Discrete Transfer Fcn' */
  real32_T DiscreteTransferFcn_tmp_c;  /* '<S28>/Discrete Transfer Fcn' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S8>/Integrator' */

  int8_T Medidasyestimaciondeestado_Subs;/* '<Root>/Medidas y estimacion de estado' */
  int8_T Audio_SubsysRanBC;            /* '<S3>/Audio' */
  int8_T Calculodelamediadelamedidadelgi;/* '<S3>/Calculo de la media de la medida del giroscopo' */
  int8_T Estimadordeestado_SubsysRanBC;/* '<S3>/Estimador de estado' */
} D_Work_SEGWAY_RT_SFIC;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
} ContinuousStates_SEGWAY_RT_SFIC;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
} StateDerivatives_SEGWAY_RT_SFIC;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S8>/Integrator' */
} StateDisabled_SEGWAY_RT_SFIC;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: lcdStr1
   * Referenced by: '<S22>/LCD'
   */
  uint8_T LCD_p1[3];

  /* Expression: lcdStr1
   * Referenced by: '<S23>/LCD'
   */
  uint8_T LCD_p1_i[5];

  /* Expression: lcdStr1
   * Referenced by: '<S24>/LCD'
   */
  uint8_T LCD_p1_n[5];

  /* Expression: lcdStr1
   * Referenced by: '<S25>/LCD'
   */
  uint8_T LCD_p1_h[4];

  /* Expression: lcdStr1
   * Referenced by: '<S26>/LCD'
   */
  uint8_T LCD_p1_p[7];

  /* Expression: lcdStr1
   * Referenced by: '<S27>/LCD'
   */
  uint8_T LCD_p1_j[7];
} ConstParam_SEGWAY_RT_SFIC;

/* Parameters (auto storage) */
struct Parameters_SEGWAY_RT_SFIC_ {
  real_T ts;                           /* Variable: ts
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real32_T Kcd[3];                     /* Variable: Kcd
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real32_T R;                          /* Variable: R
                                        * Referenced by: '<S16>/Gain3'
                                        */
  real32_T Wfc;                        /* Variable: Wfc
                                        * Referenced by: '<S21>/Gain'
                                        */
  real32_T alfa1;                      /* Variable: alfa1
                                        * Referenced by:
                                        *   '<S18>/Gain2'
                                        *   '<S29>/Gain2'
                                        *   '<S31>/Gain2'
                                        *   '<S32>/Gain2'
                                        */
  real32_T gyro0;                      /* Variable: gyro0
                                        * Referenced by: '<S18>/Unit Delay'
                                        */
  real32_T sound_freq;                 /* Variable: sound_freq
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real32_T time_start;                 /* Variable: time_start
                                        * Referenced by:
                                        *   '<S14>/Constant'
                                        *   '<S15>/Constant'
                                        */
  real32_T Calculodelavelocidadapartirdelc;/* Mask Parameter: Calculodelavelocidadapartirdelc
                                            * Referenced by: '<S20>/Paso a grados'
                                            */
  real32_T Calculodelavelocidadapartirde_j;/* Mask Parameter: Calculodelavelocidadapartirde_j
                                            * Referenced by: '<S19>/Paso a grados'
                                            */
  uint32_T Speaker_speakerVolume;      /* Mask Parameter: Speaker_speakerVolume
                                        * Referenced by: '<S17>/Speaker'
                                        */
  real_T Gain6_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<S8>/Gain6'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/5
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: 0.05
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 0.1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T deg2rad3_Gain;                /* Expression: 0.1
                                        * Referenced by: '<Root>/deg2rad3'
                                        */
  real32_T Gain8_Gain;                 /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<S9>/Gain8'
                                        */
  real32_T Gain1_Gain_a;               /* Computed Parameter: Gain1_Gain_a
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S18>/Gain3'
                                        */
  real32_T Pasoarads_Gain;             /* Computed Parameter: Pasoarads_Gain
                                        * Referenced by: '<S20>/Paso a rad//s'
                                        */
  real32_T Gain3_Gain_g;               /* Computed Parameter: Gain3_Gain_g
                                        * Referenced by: '<S31>/Gain3'
                                        */
  real32_T UnitDelay_InitialCondition; /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S31>/Unit Delay'
                                        */
  real32_T DiscreteTransferFcn_NumCoef[2];/* Computed Parameter: DiscreteTransferFcn_NumCoef
                                           * Referenced by: '<S30>/Discrete Transfer Fcn'
                                           */
  real32_T DiscreteTransferFcn_DenCoef[2];/* Computed Parameter: DiscreteTransferFcn_DenCoef
                                           * Referenced by: '<S30>/Discrete Transfer Fcn'
                                           */
  real32_T DiscreteTransferFcn_InitialStat;/* Computed Parameter: DiscreteTransferFcn_InitialStat
                                            * Referenced by: '<S30>/Discrete Transfer Fcn'
                                            */
  real32_T Pasoarads_Gain_j;           /* Computed Parameter: Pasoarads_Gain_j
                                        * Referenced by: '<S19>/Paso a rad//s'
                                        */
  real32_T Gain3_Gain_k;               /* Computed Parameter: Gain3_Gain_k
                                        * Referenced by: '<S29>/Gain3'
                                        */
  real32_T UnitDelay_InitialCondition_j;/* Computed Parameter: UnitDelay_InitialCondition_j
                                         * Referenced by: '<S29>/Unit Delay'
                                         */
  real32_T DiscreteTransferFcn_NumCoef_c[2];/* Computed Parameter: DiscreteTransferFcn_NumCoef_c
                                             * Referenced by: '<S28>/Discrete Transfer Fcn'
                                             */
  real32_T DiscreteTransferFcn_DenCoef_c[2];/* Computed Parameter: DiscreteTransferFcn_DenCoef_c
                                             * Referenced by: '<S28>/Discrete Transfer Fcn'
                                             */
  real32_T DiscreteTransferFcn_InitialSt_b;/* Computed Parameter: DiscreteTransferFcn_InitialSt_b
                                            * Referenced by: '<S28>/Discrete Transfer Fcn'
                                            */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S16>/Gain'
                                        */
  real32_T deg2rad4_Gain;              /* Computed Parameter: deg2rad4_Gain
                                        * Referenced by: '<S16>/deg2rad4'
                                        */
  real32_T Gain3_Gain_a;               /* Computed Parameter: Gain3_Gain_a
                                        * Referenced by: '<S32>/Gain3'
                                        */
  real32_T UnitDelay_InitialCondition_o;/* Computed Parameter: UnitDelay_InitialCondition_o
                                         * Referenced by: '<S32>/Unit Delay'
                                         */
  real32_T Gain3_Gain_f;               /* Computed Parameter: Gain3_Gain_f
                                        * Referenced by: '<S21>/Gain3'
                                        */
  real32_T deg2rad5_Gain;              /* Computed Parameter: deg2rad5_Gain
                                        * Referenced by: '<S16>/deg2rad5'
                                        */
  real32_T deg2rad2_Gain;              /* Computed Parameter: deg2rad2_Gain
                                        * Referenced by: '<S16>/deg2rad2'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real32_T UnitDelay1_InitialCondition;/* Computed Parameter: UnitDelay1_InitialCondition
                                        * Referenced by: '<S21>/Unit Delay1'
                                        */
  real32_T Gain1_Gain_i;               /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real32_T UnitDelay_InitialCondition_m;/* Computed Parameter: UnitDelay_InitialCondition_m
                                         * Referenced by: '<S21>/Unit Delay'
                                         */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S21>/Gain4'
                                        */
  real32_T deg2rad1_Gain;              /* Computed Parameter: deg2rad1_Gain
                                        * Referenced by: '<S16>/deg2rad1'
                                        */
  real32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S3>/Gain'
                                        */
  real32_T UnitDelay_InitialCondition_d;/* Computed Parameter: UnitDelay_InitialCondition_d
                                         * Referenced by: '<S7>/Unit Delay'
                                         */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S7>/Switch'
                                        */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real32_T UnitDelay_InitialCondition_dc;/* Computed Parameter: UnitDelay_InitialCondition_dc
                                          * Referenced by: '<S2>/Unit Delay'
                                          */
  real32_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S2>/Gain'
                                        */
  real32_T Saturation_UpperSat_j;      /* Computed Parameter: Saturation_UpperSat_j
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real32_T Saturation_LowerSat_c;      /* Computed Parameter: Saturation_LowerSat_c
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S1>/Gain'
                                        */
  real32_T Gain3_Gain_c;               /* Computed Parameter: Gain3_Gain_c
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real32_T Saturation_UpperSat_c;      /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real32_T Saturation_LowerSat_m;      /* Computed Parameter: Saturation_LowerSat_m
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real32_T Gain1_Gain_im;              /* Computed Parameter: Gain1_Gain_im
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real32_T Saturation1_UpperSat;       /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat;       /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real32_T Gain4_Gain_l;               /* Computed Parameter: Gain4_Gain_l
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real32_T Delay2_InitialCondition;    /* Computed Parameter: Delay2_InitialCondition
                                        * Referenced by: '<Root>/Delay2'
                                        */
  real32_T deg2rad1_Gain_d;            /* Computed Parameter: deg2rad1_Gain_d
                                        * Referenced by: '<Root>/deg2rad1'
                                        */
  real32_T deg2rad2_Gain_m;            /* Computed Parameter: deg2rad2_Gain_m
                                        * Referenced by: '<Root>/deg2rad2'
                                        */
  uint32_T Speaker_p2;                 /* Computed Parameter: Speaker_p2
                                        * Referenced by: '<S17>/Speaker'
                                        */
  uint32_T Speaker_p4;                 /* Computed Parameter: Speaker_p4
                                        * Referenced by: '<S17>/Speaker'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<Root>/Delay2'
                                        */
  uint8_T Speaker_p1;                  /* Computed Parameter: Speaker_p1
                                        * Referenced by: '<S17>/Speaker'
                                        */
  uint8_T AccelerationSensor_p1;       /* Computed Parameter: AccelerationSensor_p1
                                        * Referenced by: '<Root>/Acceleration Sensor'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SEGWAY_RT_SFIC {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    ContinuousStates_SEGWAY_RT_SFIC *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[1];
    real_T odeF[4][1];
    ODE4_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_SEGWAY_RT_SFIC SEGWAY_RT_SFIC_P;

/* Block signals (auto storage) */
extern BlockIO_SEGWAY_RT_SFIC SEGWAY_RT_SFIC_B;

/* Continuous states (auto storage) */
extern ContinuousStates_SEGWAY_RT_SFIC SEGWAY_RT_SFIC_X;

/* Block states (auto storage) */
extern D_Work_SEGWAY_RT_SFIC SEGWAY_RT_SFIC_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_SEGWAY_RT_SFIC SEGWAY_RT_SFIC_ConstP;

/* Model entry point functions */
extern void SEGWAY_RT_SFIC_initialize(void);
extern void SEGWAY_RT_SFIC_output(void);
extern void SEGWAY_RT_SFIC_update(void);
extern void SEGWAY_RT_SFIC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SEGWAY_RT_SFIC *const SEGWAY_RT_SFIC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SEGWAY_RT_SFIC'
 * '<S1>'   : 'SEGWAY_RT_SFIC/Calcula mandos'
 * '<S2>'   : 'SEGWAY_RT_SFIC/Control integral por realimentacion  de estado1'
 * '<S3>'   : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado'
 * '<S4>'   : 'SEGWAY_RT_SFIC/Monitorizacion'
 * '<S5>'   : 'SEGWAY_RT_SFIC/Motor A'
 * '<S6>'   : 'SEGWAY_RT_SFIC/Motor B'
 * '<S7>'   : 'SEGWAY_RT_SFIC/Calcula mandos/Activacion control'
 * '<S8>'   : 'SEGWAY_RT_SFIC/Calcula mandos/Bateria'
 * '<S9>'   : 'SEGWAY_RT_SFIC/Calcula mandos/Saturacion de mandos'
 * '<S10>'  : 'SEGWAY_RT_SFIC/Calcula mandos/Saturacion de mandos/Saturation Dynamic'
 * '<S11>'  : 'SEGWAY_RT_SFIC/Calcula mandos/Saturacion de mandos/Saturation Dynamic1'
 * '<S12>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Audio'
 * '<S13>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Calculo de la media de la medida del giroscopo'
 * '<S14>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Compare To Constant1'
 * '<S15>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Compare To Constant2'
 * '<S16>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado'
 * '<S17>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Audio/Speaker'
 * '<S18>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Calculo de la media de la medida del giroscopo/Filtro digital paso bajo'
 * '<S19>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/Calculo de la velocidad a partir del contador del encoder'
 * '<S20>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/Calculo de la velocidad a partir del contador del encoder '
 * '<S21>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/Filtro compementario'
 * '<S22>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/LCD1'
 * '<S23>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/LCD2'
 * '<S24>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/LCD3'
 * '<S25>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/LCD4'
 * '<S26>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/LCD5'
 * '<S27>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/LCD6'
 * '<S28>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/Calculo de la velocidad a partir del contador del encoder/Derivada discreta'
 * '<S29>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/Calculo de la velocidad a partir del contador del encoder/Filtro digital paso bajo'
 * '<S30>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/Calculo de la velocidad a partir del contador del encoder /Derivada discreta'
 * '<S31>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/Calculo de la velocidad a partir del contador del encoder /Filtro digital paso bajo'
 * '<S32>'  : 'SEGWAY_RT_SFIC/Medidas y estimacion de estado/Estimador de estado/Filtro compementario/Filtro digital paso bajo'
 */
#endif                                 /* RTW_HEADER_SEGWAY_RT_SFIC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
