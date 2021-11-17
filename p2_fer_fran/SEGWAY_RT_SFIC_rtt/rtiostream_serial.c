/*
 * File: rtiostream_serial.cpp
 * Copyright 2001-2010 The MathWorks, Inc.
 */

#ifndef _rtiostream

#include "rtwtypes.h"
#include "rtiostream.h"
#define _rtiostream
#endif

#include "ecrobot_interface.h"

/***************** VISIBLE FUNCTIONS ******************************************/

/* Function: rtIOStreamOpen =================================================
 * Abstract:
 *  Open the connection with the target.
 */
int rtIOStreamOpen(int argc, void * argv[])
{
    /* ASCII character a is 65 */
    #define RTIOSTREAM_OPEN_COMPLETE 65
    
    int result = RTIOSTREAM_NO_ERROR;

    //init();

    return result;
}

/* Function: rtIOStreamSend =====================================================
 * Abstract:
 *  Sends the specified number of bytes on the serial line. Returns the number of
 *  bytes sent (if successful) or a negative value if an error occurred.
 */
int rtIOStreamSend(
        int          streamID,
        const void * src,
        size_t       size,
        size_t     * sizeSent)
{
    
    //Serial.write( (const uint8_T *)src, (int16_T)size);
    while(bt_pending() & 2 );
    bt_write( (uint8_T *)src, 0, (int16_T)size);
    
    *sizeSent = size;
    
    return RTIOSTREAM_NO_ERROR;
}

/* Function: rtIOStreamRecv ================================================
 * Abstract: receive data
 *
 */
int rtIOStreamRecv(
        int      streamID,
        void   * dst,
        size_t   size,
        size_t * sizeRecvd)
{
    uint8_T data;
    uint8_T * ptr = (uint8_T *)dst;
    
    *sizeRecvd = 0U;
    
    if (!(bt_pending()&1)) {
        return RTIOSTREAM_NO_ERROR;
    }
    
    while ((*sizeRecvd < size)) {
        if (bt_read(&data, 0, 1)== 1) {
            *ptr++ = (uint8_T) data;
            (*sizeRecvd)++;
        }
    }
    
    return RTIOSTREAM_NO_ERROR;
}

/* Function: rtIOStreamClose ================================================
 * Abstract: close the connection.
 *
 */
int rtIOStreamClose(int streamID)
{
    return RTIOSTREAM_NO_ERROR;
}
