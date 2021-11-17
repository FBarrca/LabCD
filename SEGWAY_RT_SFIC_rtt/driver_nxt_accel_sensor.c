/* Copyright 2011 The MathWorks, Inc. */

/**************************************
 *   LEGO NXT Accel Sensor Driver     *
 **************************************/

#include "driver_nxt.h"

void getAccelSensorValue(uint8_T portNumber, int16_T* xData, int16_T* yData, int16_T* zData)
{
    int16_T temp[3];
    ecrobot_get_accel_sensor(portNumber-1, temp);
    *xData = temp[0];
    *yData = temp[1];
    *zData = temp[2];
}

void initAccelSensor(uint8_T portNumber)
{
    ecrobot_init_accel_sensor(portNumber-1);
}

void terminateAccelSensor(uint8_T portNumber)
{
    ecrobot_term_accel_sensor(portNumber-1);
}


