// https://learn.arm.com/learning-paths/embedded-systems/bare-metal/retarget/
// https://documentation-service.arm.com/static/5e8e36c2fd977155116a90b5

#ifndef __rtc_h
#define __rtc_h

#include "utils.h"

struct pl031_rtc {
        volatile unsigned int RTCDR;   // +0x00     Data register
        volatile unsigned int RTCMR;   // +0x04     Match register
        volatile unsigned int RTCLR;   // +0x08     Load register
        volatile unsigned int RTCCR;   // +0x0C     Control register         
        volatile unsigned int RTCIMSC; // +0x10     Interrupt mask Set/Clear 
        volatile unsigned int RTCRIS;  // +0x14     Raw interrupt status     
        volatile unsigned int RTCMIS;  // +0x18     Masked interrupt status
        volatile unsigned int RTCICR;  // +0x1C     Interrupt clear register
};

volatile struct pl031_rtc* my_rtc;

void rtcInit(volatile unsigned int *addr) {
    my_rtc = (struct pl031_rtc *)addr;
}



#endif