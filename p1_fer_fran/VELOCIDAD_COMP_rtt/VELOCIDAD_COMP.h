/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VELOCIDAD_COMP.h
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

#ifndef RTW_HEADER_VELOCIDAD_COMP_h_
#define RTW_HEADER_VELOCIDAD_COMP_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef VELOCIDAD_COMP_COMMON_INCLUDES_
# define VELOCIDAD_COMP_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_nxt.h"
#endif                                 /* VELOCIDAD_COMP_COMMON_INCLUDES_ */

#include "VELOCIDAD_COMP_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T Gain6;                        /* '<S9>/Gain6' */
  real_T Integrator;                   /* '<S9>/Integrator' */
  real_T DataTypeConversion4;          /* '<S3>/Data Type Conversion4' */
  real_T Gain1;                        /* '<S9>/Gain1' */
  real32_T Saturation;                 /* '<S8>/Saturation' */
  real32_T DiscreteTimeIntegrator;     /* '<S7>/Discrete-Time Integrator' */
  real32_T Sum;                        /* '<S7>/Sum' */
  real32_T Multiply1;                  /* '<S2>/Multiply1' */
  real32_T DataTypeConversion;         /* '<S13>/Data Type Conversion' */
  real32_T Radio;                      /* '<S17>/Radio' */
  real32_T DataTypeConversion1;        /* '<S13>/Data Type Conversion1' */
  real32_T Radio_l;                    /* '<S16>/Radio' */
  real32_T Media;                      /* '<S13>/Media' */
  real32_T Multiply;                   /* '<S2>/Multiply' */
  real32_T Switch2;                    /* '<S12>/Switch2' */
  real32_T Sum1;                       /* '<S3>/Sum1' */
  real32_T RateTransition;             /* '<S1>/Rate Transition' */
  real32_T DataTypeConversion1_d;      /* '<S3>/Data Type Conversion1' */
  real32_T Gain2;                      /* '<S20>/Gain2' */
  real32_T Gain3;                      /* '<S20>/Gain3' */
  real32_T Sum3;                       /* '<S20>/Sum3' */
  real32_T Sum1_b;                     /* '<S20>/Sum1' */
  real32_T Sum2;                       /* '<S20>/Sum2' */
  real32_T Sum4;                       /* '<S20>/Sum4' */
  uint8_T UnitDelay;                   /* '<S7>/Unit Delay' */
  uint8_T Compare;                     /* '<S23>/Compare' */
  boolean_T HitCrossing;               /* '<S3>/Hit  Crossing' */
} BlockIO_VELOCIDAD_COMP;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Velocidad_PWORK;                   /* '<S4>/Velocidad' */

  struct {
    void *LoggedData;
  } estado_PWORK;                      /* '<S4>/estado' */

  real32_T UnitDelay_DSTATE;           /* '<S8>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real32_T Crdz_states[2];             /* '<S2>/Crd(z) ' */
  real32_T UnitDelay_DSTATE_h;         /* '<S17>/Unit Delay' */
  real32_T DiscreteTransferFcn_states; /* '<S17>/Discrete Transfer Fcn' */
  real32_T UnitDelay_DSTATE_e;         /* '<S16>/Unit Delay' */
  real32_T DiscreteTransferFcn_states_h;/* '<S16>/Discrete Transfer Fcn' */
  real32_T Cdz_states[2];              /* '<S2>/Cd(z)' */
  real32_T UnitDelay_DSTATE_d;         /* '<S3>/Unit Delay' */
  real32_T UnitDelay_DSTATE_p;         /* '<S20>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S20>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S20>/Unit Delay2' */
  real32_T Crdz_tmp;                   /* '<S2>/Crd(z) ' */
  real32_T DiscreteTransferFcn_tmp;    /* '<S17>/Discrete Transfer Fcn' */
  real32_T DiscreteTransferFcn_tmp_e;  /* '<S16>/Discrete Transfer Fcn' */
  real32_T Cdz_tmp;                    /* '<S2>/Cd(z)' */
  real32_T RateTransition_Buffer0;     /* '<S1>/Rate Transition' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S9>/Integrator' */

  int_T HitCrossing_MODE;              /* '<S3>/Hit  Crossing' */
  uint8_T UnitDelay_DSTATE_n;          /* '<S7>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S7>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S7>/Discrete-Time Integrator' */
} D_Work_VELOCIDAD_COMP;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S9>/Integrator' */
} ContinuousStates_VELOCIDAD_COMP;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S9>/Integrator' */
} StateDerivatives_VELOCIDAD_COMP;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S9>/Integrator' */
} StateDisabled_VELOCIDAD_COMP;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<S3>/Hit  Crossing' */
} PrevZCSigStates_VELOCIDAD_COMP;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: lcdStr1
   * Referenced by: '<S14>/LCD'
   */
  uint8_T LCD_p1[7];

  /* Expression: lcdStr1
   * Referenced by: '<S15>/LCD'
   */
  uint8_T LCD_p1_e[7];

  /* Expression: lcdStr1
   * Referenced by: '<S21>/LCD'
   */
  uint8_T LCD_p1_d[4];
} ConstParam_VELOCIDAD_COMP;

/* Parameters (auto storage) */
struct Parameters_VELOCIDAD_COMP_ {
  real32_T R;                          /* Variable: R
                                        * Referenced by:
                                        *   '<S16>/Radio'
                                        *   '<S17>/Radio'
                                        */
  real_T Referenciavelocidad1_Vmin;    /* Mask Parameter: Referenciavelocidad1_Vmin
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real32_T Referenciavelocidad1_T;     /* Mask Parameter: Referenciavelocidad1_T
                                        * Referenced by: '<S23>/Constant'
                                        */
  real32_T Detecciondesector_const;    /* Mask Parameter: Detecciondesector_const
                                        * Referenced by: '<S22>/Constant'
                                        */
  real32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S18>/Constant'
                                        */
  real32_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Gain8_Gain;                   /* Expression: -1
                                        * Referenced by: '<S11>/Gain8'
                                        */
  real_T Gain6_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<S9>/Gain6'
                                        */
  real_T OFFSET_Value;                 /* Expression: -0.08
                                        * Referenced by: '<Root>/OFFSET'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T HitCrossing_Offset;           /* Expression: 44.5
                                        * Referenced by: '<S3>/Hit  Crossing'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 100
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -100
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -100
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 1/5
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real32_T UnitDelay_InitialCondition; /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S8>/Switch'
                                        */
  real32_T Saturation_UpperSat_b;      /* Computed Parameter: Saturation_UpperSat_b
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real32_T Saturation_LowerSat_i;      /* Computed Parameter: Saturation_LowerSat_i
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S7>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  real32_T ang_refmaximo4_Value;       /* Computed Parameter: ang_refmaximo4_Value
                                        * Referenced by: '<S7>/ang_ref maximo4'
                                        */
  real32_T Crdz_NumCoef[3];            /* Computed Parameter: Crdz_NumCoef
                                        * Referenced by: '<S2>/Crd(z) '
                                        */
  real32_T Crdz_DenCoef[3];            /* Computed Parameter: Crdz_DenCoef
                                        * Referenced by: '<S2>/Crd(z) '
                                        */
  real32_T Crdz_InitialStates;         /* Computed Parameter: Crdz_InitialStates
                                        * Referenced by: '<S2>/Crd(z) '
                                        */
  real32_T UnitDelay_InitialCondition_f;/* Computed Parameter: UnitDelay_InitialCondition_f
                                         * Referenced by: '<S17>/Unit Delay'
                                         */
  real32_T Radio1_Gain;                /* Computed Parameter: Radio1_Gain
                                        * Referenced by: '<S17>/Radio1'
                                        */
  real32_T Pasoarads_Gain;             /* Computed Parameter: Pasoarads_Gain
                                        * Referenced by: '<S17>/Paso a rad//s'
                                        */
  real32_T DiscreteTransferFcn_NumCoef[2];/* Computed Parameter: DiscreteTransferFcn_NumCoef
                                           * Referenced by: '<S17>/Discrete Transfer Fcn'
                                           */
  real32_T DiscreteTransferFcn_DenCoef[2];/* Computed Parameter: DiscreteTransferFcn_DenCoef
                                           * Referenced by: '<S17>/Discrete Transfer Fcn'
                                           */
  real32_T DiscreteTransferFcn_InitialStat;/* Computed Parameter: DiscreteTransferFcn_InitialStat
                                            * Referenced by: '<S17>/Discrete Transfer Fcn'
                                            */
  real32_T UnitDelay_InitialCondition_p;/* Computed Parameter: UnitDelay_InitialCondition_p
                                         * Referenced by: '<S16>/Unit Delay'
                                         */
  real32_T Radio1_Gain_d;              /* Computed Parameter: Radio1_Gain_d
                                        * Referenced by: '<S16>/Radio1'
                                        */
  real32_T Pasoarads_Gain_a;           /* Computed Parameter: Pasoarads_Gain_a
                                        * Referenced by: '<S16>/Paso a rad//s'
                                        */
  real32_T DiscreteTransferFcn_NumCoef_m[2];/* Computed Parameter: DiscreteTransferFcn_NumCoef_m
                                             * Referenced by: '<S16>/Discrete Transfer Fcn'
                                             */
  real32_T DiscreteTransferFcn_DenCoef_a[2];/* Computed Parameter: DiscreteTransferFcn_DenCoef_a
                                             * Referenced by: '<S16>/Discrete Transfer Fcn'
                                             */
  real32_T DiscreteTransferFcn_InitialSt_p;/* Computed Parameter: DiscreteTransferFcn_InitialSt_p
                                            * Referenced by: '<S16>/Discrete Transfer Fcn'
                                            */
  real32_T Media_Gain;                 /* Computed Parameter: Media_Gain
                                        * Referenced by: '<S13>/Media'
                                        */
  real32_T Cdz_NumCoef[3];             /* Computed Parameter: Cdz_NumCoef
                                        * Referenced by: '<S2>/Cd(z)'
                                        */
  real32_T Cdz_DenCoef[3];             /* Computed Parameter: Cdz_DenCoef
                                        * Referenced by: '<S2>/Cd(z)'
                                        */
  real32_T Cdz_InitialStates;          /* Computed Parameter: Cdz_InitialStates
                                        * Referenced by: '<S2>/Cd(z)'
                                        */
  real32_T UnitDelay_InitialCondition_f2;/* Computed Parameter: UnitDelay_InitialCondition_f2
                                          * Referenced by: '<S3>/Unit Delay'
                                          */
  real32_T RateTransition_X0;          /* Computed Parameter: RateTransition_X0
                                        * Referenced by: '<S1>/Rate Transition'
                                        */
  real32_T UnitDelay_InitialCondition_h;/* Computed Parameter: UnitDelay_InitialCondition_h
                                         * Referenced by: '<S20>/Unit Delay'
                                         */
  real32_T UnitDelay1_InitialCondition;/* Computed Parameter: UnitDelay1_InitialCondition
                                        * Referenced by: '<S20>/Unit Delay1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S20>/Gain2'
                                        */
  real32_T UnitDelay2_InitialCondition;/* Computed Parameter: UnitDelay2_InitialCondition
                                        * Referenced by: '<S20>/Unit Delay2'
                                        */
  real32_T Gain1_Gain_n;               /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S20>/Gain1'
                                        */
  real32_T Gain3_Gain_p;               /* Computed Parameter: Gain3_Gain_p
                                        * Referenced by: '<S20>/Gain3'
                                        */
  uint8_T UnitDelay_InitialCondition_a;/* Computed Parameter: UnitDelay_InitialCondition_a
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_VELOCIDAD_COMP {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    ContinuousStates_VELOCIDAD_COMP *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[1];
    real_T odeF[3][1];
    ODE3_IntgData intgData;
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
    uint32_T clockTick2;
    uint32_T clockTick3;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[4];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_VELOCIDAD_COMP VELOCIDAD_COMP_P;

/* Block signals (auto storage) */
extern BlockIO_VELOCIDAD_COMP VELOCIDAD_COMP_B;

/* Continuous states (auto storage) */
extern ContinuousStates_VELOCIDAD_COMP VELOCIDAD_COMP_X;

/* Block states (auto storage) */
extern D_Work_VELOCIDAD_COMP VELOCIDAD_COMP_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_VELOCIDAD_COMP VELOCIDAD_COMP_ConstP;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_VELOCIDAD_COMP VELOCIDAD_COMP_PrevZCSigState;

/* Model entry point functions */
extern void VELOCIDAD_COMP_initialize(void);
extern void VELOCIDAD_COMP_output(void);
extern void VELOCIDAD_COMP_update(void);
extern void VELOCIDAD_COMP_terminate(void);

/* Real-time Model object */
extern RT_MODEL_VELOCIDAD_COMP *const VELOCIDAD_COMP_M;

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
 * '<Root>' : 'VELOCIDAD_COMP'
 * '<S1>'   : 'VELOCIDAD_COMP/Calcula mandos'
 * '<S2>'   : 'VELOCIDAD_COMP/Control PID velocidad'
 * '<S3>'   : 'VELOCIDAD_COMP/Medidas'
 * '<S4>'   : 'VELOCIDAD_COMP/Monitorizacion'
 * '<S5>'   : 'VELOCIDAD_COMP/Motor DERECHO'
 * '<S6>'   : 'VELOCIDAD_COMP/Motor IZQUIERDO'
 * '<S7>'   : 'VELOCIDAD_COMP/Referencia velocidad1'
 * '<S8>'   : 'VELOCIDAD_COMP/Calcula mandos/Activacion control'
 * '<S9>'   : 'VELOCIDAD_COMP/Calcula mandos/Bateria'
 * '<S10>'  : 'VELOCIDAD_COMP/Calcula mandos/Compare To Constant'
 * '<S11>'  : 'VELOCIDAD_COMP/Calcula mandos/Saturacion de mandos'
 * '<S12>'  : 'VELOCIDAD_COMP/Calcula mandos/Saturacion de mandos/Saturation Dynamic'
 * '<S13>'  : 'VELOCIDAD_COMP/Medidas/Calculo velocidad'
 * '<S14>'  : 'VELOCIDAD_COMP/Medidas/LCD5'
 * '<S15>'  : 'VELOCIDAD_COMP/Medidas/LCD7'
 * '<S16>'  : 'VELOCIDAD_COMP/Medidas/Calculo velocidad/Derivada filtrada'
 * '<S17>'  : 'VELOCIDAD_COMP/Medidas/Calculo velocidad/Derivada filtrada '
 * '<S18>'  : 'VELOCIDAD_COMP/Monitorizacion/Compare To Constant1'
 * '<S19>'  : 'VELOCIDAD_COMP/Monitorizacion/Compare To Constant2'
 * '<S20>'  : 'VELOCIDAD_COMP/Monitorizacion/IAE_COMP'
 * '<S21>'  : 'VELOCIDAD_COMP/Monitorizacion/IAE_COMP/LCD1'
 * '<S22>'  : 'VELOCIDAD_COMP/Referencia velocidad1/Deteccion de sector'
 * '<S23>'  : 'VELOCIDAD_COMP/Referencia velocidad1/Deteccion de sector1'
 */
#endif                                 /* RTW_HEADER_VELOCIDAD_COMP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
