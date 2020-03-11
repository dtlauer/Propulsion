//
// Created by Dominic Kauer on 3/11/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "structs.h"
#include "trigTables.h"

#define MAG_RADIX_POINT 8

#define MAX_INT16  0x7FFF    //2^15 maximum signed 16 bit integer
#define MAX_UINT16 0xFFFF   //2^16 maximum unsigned 16 bit integer
#define MAX_ANGLE 0x3FFF   //From trigint_sin16.c line 32
#define EQUIVALENT_60deg  (MAX_ANGLE*60/360)   //60 deg equivalent in our angle system (14-bit angles)
#define EQUIVALENT_90deg  (MAX_ANGLE*90/360)    //60 deg equivalent in our angle system

#define SQRT_3 1.73205080757

#ifndef PROPULSION_TRANSISTORS_H
#define PROPULSION_TRANSISTORS_H

//Sets the transistors for state V0. T1 and T4 is LSB
void SVPWM_WriteV0(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(0);
    (*pm).setTran3(0);

    (*pm).setTran4(1);
    (*pm).setTran5(1);
    (*pm).setTran6(1);
}

//Sets the transistors for state V1
void SVPWM_WriteV1(SVPWM *pm) {
    (*pm).setTran1(1);
    (*pm).setTran2(0);
    (*pm).setTran3(0);

    (*pm).setTran4(0);
    (*pm).setTran5(1);
    (*pm).setTran6(1);
}

//Sets the transistors for state V2
void SVPWM_WriteV2(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(1);
    (*pm).setTran3(0);

    (*pm).setTran4(1);
    (*pm).setTran5(0);
    (*pm).setTran6(1);
}

//Sets the transistors for state V3
void SVPWM_WriteV3(SVPWM *pm) {
    (*pm).setTran1(1);
    (*pm).setTran2(1);
    (*pm).setTran3(0);

    (*pm).setTran4(0);
    (*pm).setTran5(0);
    (*pm).setTran6(1);
}

//Sets the transistors for state V4
void SVPWM_WriteV4(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(0);
    (*pm).setTran3(1);

    (*pm).setTran4(1);
    (*pm).setTran5(1);
    (*pm).setTran6(0);
}

//Sets the transistors for state V5
void SVPWM_WriteV5(SVPWM *pm) {
    (*pm).setTran1(1);
    (*pm).setTran2(0);
    (*pm).setTran3(1);

    (*pm).setTran4(0);
    (*pm).setTran5(1);
    (*pm).setTran6(0);
}

//Sets the transistors for state V6
void SVPWM_WriteV6(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(1);
    (*pm).setTran3(1);

    (*pm).setTran4(1);
    (*pm).setTran5(0);
    (*pm).setTran6(0);
}

//Sets the transistors for state V7
void SVPWM_WriteV7(SVPWM *pm) {
    (*pm).setTran1(1);
    (*pm).setTran2(1);
    (*pm).setTran3(1);

    (*pm).setTran4(0);
    (*pm).setTran5(0);
    (*pm).setTran6(0);
}

//Sets the transistors to off state
void SVPWM_WriteOFF(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(0);
    (*pm).setTran3(0);

    (*pm).setTran4(0);
    (*pm).setTran5(0);
    (*pm).setTran6(0);
}

#endif //PROPULSION_TRANSISTORS_H
