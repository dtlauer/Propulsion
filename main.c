#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "structs.h"
#include "trigTables.h"
#include "functions.h"
#include "transistors.h"

#define MAG_RADIX_POINT 8

#define MAX_INT16  0x7FFF    //2^15 maximum signed 16 bit integer
#define MAX_UINT16 0xFFFF   //2^16 maximum unsigned 16 bit integer
#define MAX_ANGLE 0x3FFF   //From trigint_sin16.c line 32
#define EQUIVALENT_60deg  (MAX_ANGLE*60/360)   //60 deg equivalent in our angle system (14-bit angles)
#define EQUIVALENT_90deg  (MAX_ANGLE*90/360)    //60 deg equivalent in our angle system

#define SQRT_3 1.73205080757

SVPWM pwmBoi;

void fakeISR() {
    SVPWM_STDISR(&pwmBoi);
    Test_setTimer(0xFFFF - pwmBoi.Timer.currentTime);
}

int main() {
    //Setup function pointers
    pwmBoi.setTran1 = TEST_V1;
    pwmBoi.setTran2 = TEST_V2;
    pwmBoi.setTran3 = TEST_V3;
    pwmBoi.setTran4 = TEST_V4;
    pwmBoi.setTran5 = TEST_V5;
    pwmBoi.setTran6 = TEST_V6;

    //Calculate Switching Times
    pwmBoi.Timer.totalPeriod = 30000;
    pwmBoi.Timer.magnitude = 0x7F;

    pwmBoi.refVector.magnitude = 1000;

    uint16_t TEST_Angles [19] = {12, 45, 59, 60, 105, 119, 120, 155, 179, 180, 203, 239, 240, 258, 299, 300, 315, 359, 360};

    for(int i = 0; i < 19; i ++){
        printf("--------------------------------------------------\n\r");
        SVPWM_SetControlAngle(&pwmBoi, (MAX_ANGLE * TEST_Angles[i] / 360));
        printf("MAX_ANGLE: %d\n\r", MAX_ANGLE);
        printf("Angle: %d\n\r", TEST_Angles[i]);
        printf("Control Angle: %d\n\r", pwmBoi.ControlAngle);
        printf("Ref Angle: %d\n\r", pwmBoi.RefAngle);
        fakeISR();
        printf("Sector: %d\n\r", (pwmBoi.CurrentSector));
        printf("Current State: %d\n\r", pwmBoi.State);
        printf("Total Period: %u\n\r", pwmBoi.Timer.totalPeriod);
        printf("Half Vec Time: %u\n\r", pwmBoi.Timer.halfZeroVector);
        printf("Vec 1 Time: %u\n\r", pwmBoi.Timer.basicVec1);
        printf("Vec 2 Time: %u\n\r", pwmBoi.Timer.basicVec2);

    }

    return 0;
}
