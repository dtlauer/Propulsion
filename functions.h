//
// Created by Dominic Kauer on 3/11/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "structs.h"
#include "trigTables.h"
#include "transistors.h"

#ifndef PROPULSION_FUNCTIONS_H
#define PROPULSION_FUNCTIONS_H

#define MAG_RADIX_POINT 8

#define MAX_INT16  0x7FFF    //2^15 maximum signed 16 bit integer
#define MAX_UINT16 0xFFFF   //2^16 maximum unsigned 16 bit integer
#define MAX_ANGLE 0x3FFF   //From trigint_sin16.c line 32
#define EQUIVALENT_60deg  (MAX_ANGLE*60/360)   //60 deg equivalent in our angle system (14-bit angles)
#define EQUIVALENT_90deg  (MAX_ANGLE*90/360)    //60 deg equivalent in our angle system

#define SQRT_3 1.73205080757

//Returns the current sector of the SVPWM system
SVPWM_SEC SVPWM_GetControlAngleSEC(SVPWM *pm) {

    //Because this is integer math, the remnants are automatically discarded and we're left with how many times 60 degrees goes into the current angle
    //This is allowed because enums always start at 0 and go to #elements -1. SO each sector gets a subsequent assignment
    return ((*pm).ControlAngle / EQUIVALENT_60deg) % 6; //CONVRET TO multiples of 60 deg
}

//Updates the sector of the control signal
void SVPWM_SetCurrentSEC(SVPWM *pm) {
    (*pm).CurrentSector = SVPWM_GetControlAngleSEC(pm);
}

//Updates the current timer to get the next wait time
void SVPWM_UpdateCurrentTimer(SVPWM *pm) {
    switch((*pm).State){
        case V0_ABS:
            (*pm).Timer.currentTime = (*pm).Timer.halfZeroVector;
            break;
        case V1_ABS:
            (*pm).Timer.currentTime = (*pm).Timer.basicVec1;
            break;
        case V2_ABS:
            (*pm).Timer.currentTime = (*pm).Timer.basicVec2;
            break;
        case V7_REL:
            (*pm).Timer.currentTime = (*pm).Timer.halfZeroVector;
            break;
        default:
            return;
    }
}

//Gets the absolute voltage vector from the relative voltage vector and the sector number
SVPWM_ABS_VEC SVPWM_GetAbsoluteVoltageVector(SVPWM *pm) {
    //Two zero vectors are independent of the state
    if((*pm).State == V0_REL)
        return V0_ABS;
    if((*pm).State == V7_REL)
        return V7_ABS;

    switch((*pm).CurrentSector) {
        case SEC1:
            if((*pm).State == V1_REL)
                return V1_ABS;
            if((*pm).State == V2_REL)
                return V3_ABS;
            break;
        case SEC2:
            if((*pm).State == V1_REL)
                return V3_ABS;
            if((*pm).State == V2_REL)
                return V2_ABS;
            break;
        case SEC3:
            if((*pm).State == V1_REL)
                return V2_ABS;
            if((*pm).State == V2_REL)
                return V6_ABS;
            break;
        case SEC4:
            if((*pm).State == V1_REL)
                return V6_ABS;
            if((*pm).State == V2_REL)
                return V4_ABS;
            break;
        case SEC5:
            if((*pm).State == V1_REL)
                return V4_ABS;
            if((*pm).State == V2_REL)
                return V5_ABS;
            break;
        case SEC6:
            if((*pm).State == V1_REL)
                return V5_ABS;
            if((*pm).State == V2_REL)
                return V1_ABS;
            break;
        default:
            return OFF_ABS;
    }
}

//Progresses the current voltage state to the next voltage state
void SVPWM_SetNextRelativeState(SVPWM *pm) {
    switch((*pm).State) {
        case V0_REL:
            (*pm).State = V1_REL;
            break;
        case V1_REL:
            (*pm).State = V2_REL;
            break;
        case V2_REL:
            (*pm).State = V7_REL;
            break;
        case V7_REL:
            (*pm).State = V0_REL;
            break;
        default:
            return;
    }
}

//Takes a unsigned 14 bit angle input and updates the reference angle
void SVPWM_SetControlAngle(SVPWM *pm, uint16_t inputAngle) {
    (*pm).ControlAngle = inputAngle;
    (*pm).RefAngle =  inputAngle % EQUIVALENT_60deg; //Find how many points past the nearest 60 we are
}

//Calculates the appropriate amount of time to spend in each sector
void SVPWM_SetVectorTimes(SVPWM *pm) {
    uint8_t sector;
    uint16_t sectorIndex, angleIndex;
    sector = (*pm).CurrentSector + 1;
    printf("Sector + 1 %d\r\n", sector);
    sectorIndex = sector * 60 - 1;
    printf("Sector index %d\r\n", sectorIndex);
    angleIndex = (*pm).RefAngle * 60 / MAX_ANGLE;
    printf("Angle Index %d\r\n", angleIndex);

    (*pm).Timer.basicVec1 = (SQRT_3 * (*pm).Timer.totalPeriod * (sineTable[sectorIndex] * cosineTable[angleIndex] - sineTable[angleIndex] * cosineTable[sectorIndex]));

    sectorIndex = (sector - 1) * 60;
    (*pm).Timer.basicVec2 = (SQRT_3 * (*pm).Timer.totalPeriod * (- sineTable[sectorIndex] * cosineTable[angleIndex] + sineTable[angleIndex] * cosineTable[sectorIndex]));

    (*pm).Timer.halfZeroVector = ((*pm).Timer.totalPeriod - (*pm).Timer.basicVec1 - (*pm).Timer.basicVec2) >> 1;

}

//Calls the write function to the input vector
void SVPWM_WriteABSVector(SVPWM *pm) {
    switch(SVPWM_GetAbsoluteVoltageVector(pm)){
        case V0_ABS:
            SVPWM_WriteV0(pm);
            break;
        case V1_ABS:
            SVPWM_WriteV1(pm);
            break;
        case V2_ABS:
            SVPWM_WriteV2(pm);
            break;
        case V3_ABS:
            SVPWM_WriteV3(pm);
            break;
        case V4_ABS:
            SVPWM_WriteV4(pm);
            break;
        case V5_ABS:
            SVPWM_WriteV5(pm);
            break;
        case V6_ABS:
            SVPWM_WriteV6(pm);
            break;
        case V7_ABS:
            SVPWM_WriteV7(pm);
            break;
        default:
            //We don't know whats happening if we get here.
            SVPWM_WriteOFF(pm);
    }
}


void SVPWM_STDISR(SVPWM *pm) {
    SVPWM_SetCurrentSEC(pm);
    SVPWM_SetNextRelativeState(pm);
    SVPWM_WriteABSVector(pm);
    SVPWM_SetVectorTimes(pm);
    SVPWM_UpdateCurrentTimer(pm);
}

uint16_t Test_setTimer(uint16_t time) {
    printf("Time: %d\n\r", time);
}

//Basic Debugging functions
uint8_t TEST_V0(uint8_t input) {
    if(input == 0)
        printf("T0: OFF\n\r");
    if(input == 1)
        printf("T0: ON\n\r");
}

uint8_t TEST_V1(uint8_t input) {
    if(input == 0)
        printf("T1: OFF\n\r");
    if(input == 1)
        printf("T1: ON\n\r");
}

uint8_t TEST_V2(uint8_t input) {
    if(input == 0)
        printf("T2: OFF\n\r");
    if(input == 1)
        printf("T2: ON\n\r");
}

uint8_t TEST_V3(uint8_t input) {
    if(input == 0)
        printf("T3: OFF\n\r");
    if(input == 1)
        printf("T3: ON\n\r");
}

uint8_t TEST_V4(uint8_t input) {
    if(input == 0)
        printf("T4: OFF\n\r");
    if(input == 1)
        printf("T4: ON\n\r");
}

uint8_t TEST_V5(uint8_t input) {
    if(input == 0)
        printf("T5: OFF\n\r");
    if(input == 1)
        printf("T5: ON\n\r");
}

uint8_t TEST_V6(uint8_t input) {
    if(input == 0)
        printf("T6: OFF\n\r");
    if(input == 1)
        printf("T6: ON\n\r");
}

#endif //PROPULSION_FUNCTIONS_H
