/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VELOCIDAD.h
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

#ifndef RTW_HEADER_VELOCIDAD_h_
#define RTW_HEADER_VELOCIDAD_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef VELOCIDAD_COMMON_INCLUDES_
# define VELOCIDAD_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_nxt.h"
#endif                                 /* VELOCIDAD_COMMON_INCLUDES_ */

#include "VELOCIDAD_types.h"

/* Shared type includes */
#include "multiword_types.h"
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
  real_T Gain6;                        /* '<S10>/Gain6' */
  real_T Integrator;                   /* '<S10>/Integrator' */
  real_T Gain1;                        /* '<S10>/Gain1' */
  real32_T Saturation;                 /* '<S9>/Saturation' */
  real32_T DiscreteTimeIntegrator;     /* '<S7>/Discrete-Time Integrator' */
  real32_T Sum;                        /* '<S7>/Sum' */
  real32_T DataTypeConversion;         /* '<S13>/Data Type Conversion' */
  real32_T Radio;                      /* '<S15>/Radio' */
  real32_T DataTypeConversion1;        /* '<S13>/Data Type Conversion1' */
  real32_T Radio_l;                    /* '<S14>/Radio' */
  real32_T Media;                      /* '<S13>/Media' */
  real32_T Switch2;                    /* '<S12>/Switch2' */
  uint8_T UnitDelay;                   /* '<S7>/Unit Delay' */
  uint8_T Compare;                     /* '<S17>/Compare' */
} BlockIO_VELOCIDAD;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Velocidad_PWORK;                   /* '<S4>/Velocidad' */

  real32_T UnitDelay_DSTATE;           /* '<S9>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_h;         /* '<S15>/Unit Delay' */
  real32_T DiscreteTransferFcn_states; /* '<S15>/Discrete Transfer Fcn' */
  real32_T UnitDelay_DSTATE_e;         /* '<S14>/Unit Delay' */
  real32_T DiscreteTransferFcn_states_h;/* '<S14>/Discrete Transfer Fcn' */
  real32_T DiscreteTransferFcn_tmp;    /* '<S15>/Discrete Transfer Fcn' */
  real32_T DiscreteTransferFcn_tmp_e;  /* '<S14>/Discrete Transfer Fcn' */
  int32_T clockTickCounter;            /* '<S8>/Tension comun' */
  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S10>/Integrator' */

  uint8_T UnitDelay_DSTATE_c;          /* '<S7>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S7>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S7>/Discrete-Time Integrator' */
} D_Work_VELOCIDAD;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S10>/Integrator' */
} ContinuousStates_VELOCIDAD;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S10>/Integrator' */
} StateDerivatives_VELOCIDAD;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S10>/Integrator' */
} StateDisabled_VELOCIDAD;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct Parameters_VELOCIDAD_ {
  real_T ts;                           /* Variable: ts
                                        * Referenced by: '<S8>/Tension comun'
                                        */
  real32_T K;                          /* Variable: K
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real32_T R;                          /* Variable: R
                                        * Referenced by:
                                        *   '<S14>/Radio'
                                        *   '<S15>/Radio'
                                        */
  real_T Referenciavelocidad_Vmin;     /* Mask Parameter: Referenciavelocidad_Vmin
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real32_T Referenciavelocidad_T;      /* Mask Parameter: Referenciavelocidad_T
                                        * Referenced by: '<S17>/Constant'
                                        */
  real32_T Detecciondesector_const;    /* Mask Parameter: Detecciondesector_const
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Gain8_Gain;                   /* Expression: -1
                                        * Referenced by: '<S11>/Gain8'
                                        */
  real_T Gain6_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<S10>/Gain6'
                                        */
  real_T Tensioncomun_Amp;             /* Expression: 2
                                        * Referenced by: '<S8>/Tension comun'
                                        */
  real_T Tensioncomun_PhaseDelay;      /* Expression: 0
                                        * Referenced by: '<S8>/Tension comun'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: -0.08
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain1'
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
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real32_T UnitDelay_InitialCondition; /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S9>/Unit Delay'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S9>/Switch'
                                        */
  real32_T Saturation_UpperSat_b;      /* Computed Parameter: Saturation_UpperSat_b
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real32_T Saturation_LowerSat_i;      /* Computed Parameter: Saturation_LowerSat_i
                                        * Referenced by: '<S9>/Saturation'
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
  real32_T UnitDelay_InitialCondition_f;/* Computed Parameter: UnitDelay_InitialCondition_f
                                         * Referenced by: '<S15>/Unit Delay'
                                         */
  real32_T Radio1_Gain;                /* Computed Parameter: Radio1_Gain
                                        * Referenced by: '<S15>/Radio1'
                                        */
  real32_T Pasoarads_Gain;             /* Computed Parameter: Pasoarads_Gain
                                        * Referenced by: '<S15>/Paso a rad//s'
                                        */
  real32_T DiscreteTransferFcn_NumCoef[2];/* Computed Parameter: DiscreteTransferFcn_NumCoef
                                           * Referenced by: '<S15>/Discrete Transfer Fcn'
                                           */
  real32_T DiscreteTransferFcn_DenCoef[2];/* Computed Parameter: DiscreteTransferFcn_DenCoef
                                           * Referenced by: '<S15>/Discrete Transfer Fcn'
                                           */
  real32_T DiscreteTransferFcn_InitialStat;/* Computed Parameter: DiscreteTransferFcn_InitialStat
                                            * Referenced by: '<S15>/Discrete Transfer Fcn'
                                            */
  real32_T UnitDelay_InitialCondition_p;/* Computed Parameter: UnitDelay_InitialCondition_p
                                         * Referenced by: '<S14>/Unit Delay'
                                         */
  real32_T Radio1_Gain_d;              /* Computed Parameter: Radio1_Gain_d
                                        * Referenced by: '<S14>/Radio1'
                                        */
  real32_T Pasoarads_Gain_a;           /* Computed Parameter: Pasoarads_Gain_a
                                        * Referenced by: '<S14>/Paso a rad//s'
                                        */
  real32_T DiscreteTransferFcn_NumCoef_m[2];/* Computed Parameter: DiscreteTransferFcn_NumCoef_m
                                             * Referenced by: '<S14>/Discrete Transfer Fcn'
                                             */
  real32_T DiscreteTransferFcn_DenCoef_a[2];/* Computed Parameter: DiscreteTransferFcn_DenCoef_a
                                             * Referenced by: '<S14>/Discrete Transfer Fcn'
                                             */
  real32_T DiscreteTransferFcn_InitialSt_p;/* Computed Parameter: DiscreteTransferFcn_InitialSt_p
                                            * Referenced by: '<S14>/Discrete Transfer Fcn'
                                            */
  real32_T Media_Gain;                 /* Computed Parameter: Media_Gain
                                        * Referenced by: '<S13>/Media'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S13>/Gain2'
                                        */
  int32_T Gain1_Gain_f;                /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S13>/Gain1'
                                        */
  uint8_T UnitDelay_InitialCondition_a;/* Computed Parameter: UnitDelay_InitialCondition_a
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  int8_T Gain4_Gain;                   /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S1>/Gain4'
                                        */
  int8_T Gain2_Gain_h;                 /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S1>/Gain2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_VELOCIDAD {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    ContinuousStates_VELOCIDAD *contStates;
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
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_VELOCIDAD VELOCIDAD_P;

/* Block signals (auto storage) */
extern BlockIO_VELOCIDAD VELOCIDAD_B;

/* Continuous states (auto storage) */
extern ContinuousStates_VELOCIDAD VELOCIDAD_X;

/* Block states (auto storage) */
extern D_Work_VELOCIDAD VELOCIDAD_DWork;

/* Model entry point functions */
extern void VELOCIDAD_initialize(void);
extern void VELOCIDAD_output(void);
extern void VELOCIDAD_update(void);
extern void VELOCIDAD_terminate(void);

/* Real-time Model object */
extern RT_MODEL_VELOCIDAD *const VELOCIDAD_M;

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
 * '<Root>' : 'VELOCIDAD'
 * '<S1>'   : 'VELOCIDAD/Calcula mandos'
 * '<S2>'   : 'VELOCIDAD/Control PID velocidad'
 * '<S3>'   : 'VELOCIDAD/Medidas'
 * '<S4>'   : 'VELOCIDAD/Monitorizacion'
 * '<S5>'   : 'VELOCIDAD/Motor DERECHO'
 * '<S6>'   : 'VELOCIDAD/Motor IZQUIERDO'
 * '<S7>'   : 'VELOCIDAD/Referencia velocidad'
 * '<S8>'   : 'VELOCIDAD/Tension comun'
 * '<S9>'   : 'VELOCIDAD/Calcula mandos/Activacion control'
 * '<S10>'  : 'VELOCIDAD/Calcula mandos/Bateria'
 * '<S11>'  : 'VELOCIDAD/Calcula mandos/Saturacion de mandos'
 * '<S12>'  : 'VELOCIDAD/Calcula mandos/Saturacion de mandos/Saturation Dynamic'
 * '<S13>'  : 'VELOCIDAD/Medidas/Calculo velocidad'
 * '<S14>'  : 'VELOCIDAD/Medidas/Calculo velocidad/Derivada filtrada'
 * '<S15>'  : 'VELOCIDAD/Medidas/Calculo velocidad/Derivada filtrada '
 * '<S16>'  : 'VELOCIDAD/Referencia velocidad/Deteccion de sector'
 * '<S17>'  : 'VELOCIDAD/Referencia velocidad/Deteccion de sector1'
 */
#endif                                 /* RTW_HEADER_VELOCIDAD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
