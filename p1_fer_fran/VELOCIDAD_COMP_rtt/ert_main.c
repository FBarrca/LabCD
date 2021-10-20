/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include "ecrobot_private.h"
#include <ext_work.h>                  /* External mode header files */
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

int tick = 0;
double period = 0.005;
int sampleTime = 0;
int or_ext = 0;
int or_mdl = 0;
int timesup = 0;
DeclareEvent(TIMESUP);
DeclareTask(OSEK_Task_main);
DeclareTask(OSEK_Task_background);
void user_1ms_isr_type2(void)
{
  tick++;
  if (tick >= sampleTime) {
    tick = 0;
    or_ext++;
    or_mdl++;
    SetEvent(OSEK_Task_main, TIMESUP);
    timesup = 0;
  }
}

void ecrobot_device_initialize(void)
{
  int st;
  int last_act_time = 0;
  while (ecrobot_get_bt_status() != BT_STREAM) {
    st = systick_get_ms();
    if (st >= last_act_time + 10) {
      ecrobot_poll_nxtstate();
      last_act_time = st;
      ecrobot_init_bt_slave("fei");
      if (ecrobot_get_button_state() == (EXIT_PRESSED)) {
        ecrobot_device_terminate();
        display_clear(1);
        systick_wait_ms(10);
        nxt_lcd_power_down();          /* reset LCD hardware */
        systick_wait_ms(10);
        while (1) {
          nxt_avr_power_down();
        }
      }
    }
  }

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  VELOCIDAD_COMP_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(VELOCIDAD_COMP_M));
  rtExtModeCheckInit(4);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(VELOCIDAD_COMP_M->extModeInfo, 4, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(VELOCIDAD_COMP_M, true);
    }
  }

  rtERTExtModeStartMsg();
}

TASK(OSEK_Task_main)
{
  sampleTime = (int)(period/0.001);
  while (1) {
    WaitEvent(TIMESUP);
    ClearEvent(TIMESUP);
    VELOCIDAD_COMP_output();

    /* Get model outputs here */

    /* External mode */
    rtExtModeUploadCheckTrigger(4);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, VELOCIDAD_COMP_M->Timing.t[0]);
    }

    if (VELOCIDAD_COMP_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.005s, 0.0s] */
      rtExtModeUpload(1, ((VELOCIDAD_COMP_M->Timing.clockTick1) * 0.005));
    }

    if (VELOCIDAD_COMP_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.055s, 0.0s] */
      rtExtModeUpload(2, ((VELOCIDAD_COMP_M->Timing.clockTick2) * 0.055));
    }

    if (VELOCIDAD_COMP_M->Timing.TaskCounters.TID[3] == 0) {/* Sample time: [0.1s, 0.0s] */
      rtExtModeUpload(3, ((VELOCIDAD_COMP_M->Timing.clockTick3) * 0.1));
    }

    VELOCIDAD_COMP_update();
    rtExtModeCheckEndTrigger();
    or_mdl = 0;
  }

  TerminateTask();
}

TASK(OSEK_Task_background)
{
  int status;
  int link_status = 0;
  while ((rtmGetErrorStatus(VELOCIDAD_COMP_M) == (NULL)) && !rtmGetStopRequested
         (VELOCIDAD_COMP_M)) {
    status = ecrobot_get_bt_status();
    if (status != BT_NO_INIT && status != BT_STREAM) {
      ecrobot_term_bt_connection();
    }

    while (ecrobot_get_bt_status() != BT_STREAM) {
      if (link_status == 0) {
        display_clear(1);
      }

      ecrobot_init_bt_slave("fei");
      systick_wait_ms(1000);
      link_status = 0x55;
    }

    if (link_status == 0x55) {
      link_status = 0;
      display_clear(1);
    }

    if (timesup == 0) {
      timesup = 1;

      /* External mode */
      {
        boolean_T rtmStopReq = false;
        rtExtModePauseIfNeeded(VELOCIDAD_COMP_M->extModeInfo, 4, &rtmStopReq);
        if (rtmStopReq) {
          rtmSetStopRequested(VELOCIDAD_COMP_M, true);
        }

        if (rtmGetStopRequested(VELOCIDAD_COMP_M) == true) {
          rtmSetErrorStatus(VELOCIDAD_COMP_M, "Simulation finished");
          break;
        }
      }

      /* External mode */
      {
        boolean_T rtmStopReq = false;
        rtExtModeOneStep(VELOCIDAD_COMP_M->extModeInfo, 4, &rtmStopReq);
        if (rtmStopReq) {
          rtmSetStopRequested(VELOCIDAD_COMP_M, true);
        }
      }

      or_ext = 0;
    }
  }

  /* External mode */
  rtExtModeShutdown(4);
  VELOCIDAD_COMP_terminate();
  ecrobot_device_terminate();
  display_clear(1);
  systick_wait_ms(1000);
  nxt_lcd_power_down();
  systick_wait_ms(10);
  while (1) {
    nxt_avr_power_down();
  }

  TerminateTask();
}

void ecrobot_device_terminate(void)
{
  VELOCIDAD_COMP_terminate();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
