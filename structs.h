//
// Created by Dominic Kauer on 3/11/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef PROPULSION_STRUCTS_H
#define PROPULSION_STRUCTS_H

//Data type used for storing the state of the machine
typedef enum{
    SEC1,
    SEC2,
    SEC3,
    SEC4,
    SEC5,
    SEC6

} SVPWM_SEC;

//Stores the relative states for the FSM that controls the PWM switching
typedef enum{
    V0_REL,
    V1_REL,
    V2_REL,
    V7_REL,
    OFF_REL
}SVPWM_RELATIVE_VEC;

//Used for handeling absolute voltages
typedef enum{
    V0_ABS,
    V1_ABS,
    V2_ABS,
    V3_ABS,
    V4_ABS,
    V5_ABS,
    V6_ABS,
    V7_ABS,
    OFF_ABS
}SVPWM_ABS_VEC;

//SVPWM Struct datatype holds all relevant data for the PWM data
typedef struct {
    uint16_t halfZeroVector;
    uint16_t basicVec1;
    uint16_t basicVec2;
    uint16_t totalPeriod;
    uint16_t currentTime;
    uint8_t magnitude;  //A 0.8 fixed point number to control the length of the zero vector
} SPVWM_Time;

//Vector struct with three phases, magnitude, and angle
typedef struct {
    int16_t phase_U;
    int16_t phase_V;
    int16_t phase_W;
    uint16_t magnitude;
    uint16_t angle;
} Vector;
//Main Structure that ties everything together
typedef struct {

    //Functions used for setting transistor values.
    //These need to be defined and assigned in the main code with the device specific
    //A 0 will be pin off and a 1 will be pin on
    void (*setTran1)(uint8_t val);
    void (*setTran2)(uint8_t val);
    void (*setTran3)(uint8_t val);
    void (*setTran4)(uint8_t val);
    void (*setTran5)(uint8_t val);
    void (*setTran6)(uint8_t val);

    int16_t ControlAngle;
    int16_t RefAngle;


    SPVWM_Time Timer;  //Stores all the timing data for all states in the SVPWM state machine

    SVPWM_RELATIVE_VEC State;
    SVPWM_SEC CurrentSector;
    SVPWM_SEC PrevSector;

    Vector motorInput;
    Vector refVector;

} SVPWM;

#endif //PROPULSION_STRUCTS_H
