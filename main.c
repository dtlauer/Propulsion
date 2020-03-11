#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAG_RADIX_POINT 8

#define MAX_INT16  0x7FFF    //2^15 maximum signed 16 bit integer
#define MAX_UINT16 0xFFFF   //2^16 maximum unsigned 16 bit integer
#define MAX_ANGLE 0x3FFF   //From trigint_sin16.c line 32
#define EQUIVALENT_60deg  (MAX_ANGLE*60/360)   //60 deg equivalent in our angle system (14-bit angles)
#define EQUIVALENT_90deg  (MAX_ANGLE*90/360)    //60 deg equivalent in our angle system

#define SQRT_3 1.73205080757
//lookup table for sine values
static const int16_t sineTable[360] = {
    0.0, 0.0174524064373, 0.0348994967025, 0.0523359562429, 0.0697564737441, 0.0871557427477, 0.104528463268, 0.121869343405, 0.13917310096, 0.15643446504, 0.173648177667, 0.190808995377, 0.207911690818, 0.224951054344, 0.2419218956, 0.258819045103, 0.275637355817, 0.292371704723, 0.309016994375,
0.325568154457, 0.342020143326, 0.358367949545, 0.374606593416, 0.390731128489, 0.406736643076, 0.422618261741, 0.438371146789, 0.45399049974, 0.469471562786, 0.484809620246, 0.5, 0.51503807491, 0.529919264233, 0.544639035015, 0.559192903471, 0.573576436351, 0.587785252292, 0.601815023152,
0.615661475326, 0.62932039105, 0.642787609687, 0.656059028991, 0.669130606359, 0.681998360062, 0.694658370459, 0.707106781187, 0.719339800339, 0.731353701619, 0.743144825477, 0.754709580223, 0.766044443119, 0.777145961457, 0.788010753607, 0.798635510047, 0.809016994375, 0.819152044289, 0.829037572555,
0.838670567945, 0.848048096156, 0.857167300702, 0.866025403784, 0.874619707139, 0.882947592859, 0.891006524188, 0.898794046299, 0.906307787037, 0.913545457643, 0.920504853452, 0.927183854567, 0.933580426497, 0.939692620786, 0.945518575599, 0.951056516295, 0.956304755963, 0.961261695938, 0.965925826289,
0.970295726276, 0.974370064785, 0.978147600734, 0.981627183448, 0.984807753012, 0.987688340595, 0.990268068742, 0.992546151641, 0.994521895368, 0.996194698092, 0.99756405026, 0.998629534755, 0.999390827019, 0.999847695156, 1.0, 0.999847695156, 0.999390827019, 0.998629534755, 0.99756405026,
0.996194698092, 0.994521895368, 0.992546151641, 0.990268068742, 0.987688340595, 0.984807753012, 0.981627183448, 0.978147600734, 0.974370064785, 0.970295726276, 0.965925826289, 0.961261695938, 0.956304755963, 0.951056516295, 0.945518575599, 0.939692620786, 0.933580426497, 0.927183854567, 0.920504853452,
0.913545457643, 0.906307787037, 0.898794046299, 0.891006524188, 0.882947592859, 0.874619707139, 0.866025403784, 0.857167300702, 0.848048096156, 0.838670567945, 0.829037572555, 0.819152044289, 0.809016994375, 0.798635510047, 0.788010753607, 0.777145961457, 0.766044443119, 0.754709580223, 0.743144825477,
0.731353701619, 0.719339800339, 0.707106781187, 0.694658370459, 0.681998360062, 0.669130606359, 0.656059028991, 0.642787609687, 0.62932039105, 0.615661475326, 0.601815023152, 0.587785252292, 0.573576436351, 0.559192903471, 0.544639035015, 0.529919264233, 0.51503807491, 0.5, 0.484809620246,
0.469471562786, 0.45399049974, 0.438371146789, 0.422618261741, 0.406736643076, 0.390731128489, 0.374606593416, 0.358367949545, 0.342020143326, 0.325568154457, 0.309016994375, 0.292371704723, 0.275637355817, 0.258819045103, 0.2419218956, 0.224951054344, 0.207911690818, 0.190808995377, 0.173648177667,
0.15643446504, 0.13917310096, 0.121869343405, 0.104528463268, 0.0871557427477, 0.0697564737441, 0.0523359562429, 0.0348994967025, 0.0174524064373, 1.22464679915e-16, -0.0174524064373, -0.0348994967025, -0.0523359562429, -0.0697564737441, -0.0871557427477, -0.104528463268, -0.121869343405, -0.13917310096, -0.15643446504,
-0.173648177667, -0.190808995377, -0.207911690818, -0.224951054344, -0.2419218956, -0.258819045103, -0.275637355817, -0.292371704723, -0.309016994375, -0.325568154457, -0.342020143326, -0.358367949545, -0.374606593416, -0.390731128489, -0.406736643076, -0.422618261741, -0.438371146789, -0.45399049974, -0.469471562786,
-0.484809620246, -0.5, -0.51503807491, -0.529919264233, -0.544639035015, -0.559192903471, -0.573576436351, -0.587785252292, -0.601815023152, -0.615661475326, -0.62932039105, -0.642787609687, -0.656059028991, -0.669130606359, -0.681998360062, -0.694658370459, -0.707106781187, -0.719339800339, -0.731353701619,
-0.743144825477, -0.754709580223, -0.766044443119, -0.777145961457, -0.788010753607, -0.798635510047, -0.809016994375, -0.819152044289, -0.829037572555, -0.838670567945, -0.848048096156, -0.857167300702, -0.866025403784, -0.874619707139, -0.882947592859, -0.891006524188, -0.898794046299, -0.906307787037, -0.913545457643,
-0.920504853452, -0.927183854567, -0.933580426497, -0.939692620786, -0.945518575599, -0.951056516295, -0.956304755963, -0.961261695938, -0.965925826289, -0.970295726276, -0.974370064785, -0.978147600734, -0.981627183448, -0.984807753012, -0.987688340595, -0.990268068742, -0.992546151641, -0.994521895368, -0.996194698092,
-0.99756405026, -0.998629534755, -0.999390827019, -0.999847695156, -1.0, -0.999847695156, -0.999390827019, -0.998629534755, -0.99756405026, -0.996194698092, -0.994521895368, -0.992546151641, -0.990268068742, -0.987688340595, -0.984807753012, -0.981627183448, -0.978147600734, -0.974370064785, -0.970295726276,
-0.965925826289, -0.961261695938, -0.956304755963, -0.951056516295, -0.945518575599, -0.939692620786, -0.933580426497, -0.927183854567, -0.920504853452, -0.913545457643, -0.906307787037, -0.898794046299, -0.891006524188, -0.882947592859, -0.874619707139, -0.866025403784, -0.857167300702, -0.848048096156, -0.838670567945,
-0.829037572555, -0.819152044289, -0.809016994375, -0.798635510047, -0.788010753607, -0.777145961457, -0.766044443119, -0.754709580223, -0.743144825477, -0.731353701619, -0.719339800339, -0.707106781187, -0.694658370459, -0.681998360062, -0.669130606359, -0.656059028991, -0.642787609687, -0.62932039105, -0.615661475326,
-0.601815023152, -0.587785252292, -0.573576436351, -0.559192903471, -0.544639035015, -0.529919264233, -0.51503807491, -0.5, -0.484809620246, -0.469471562786, -0.45399049974, -0.438371146789, -0.422618261741, -0.406736643076, -0.390731128489, -0.374606593416, -0.358367949545, -0.342020143326, -0.325568154457,
-0.309016994375, -0.292371704723, -0.275637355817, -0.258819045103, -0.2419218956, -0.224951054344, -0.207911690818, -0.190808995377, -0.173648177667, -0.15643446504, -0.13917310096, -0.121869343405, -0.104528463268, -0.0871557427477, -0.0697564737441, -0.0523359562429, -0.0348994967025, -0.0174524064373
};

//lookup table for cosine values
static const int16_t cosineTable[360] = {
    1.0, 0.999847695156, 0.999390827019, 0.998629534755, 0.99756405026, 0.996194698092, 0.994521895368, 0.992546151641, 0.990268068742, 0.987688340595, 0.984807753012, 0.981627183448, 0.978147600734, 0.974370064785, 0.970295726276, 0.965925826289, 0.961261695938, 0.956304755963, 0.951056516295, 0.945518575599, 0.939692620786, 0.933580426497, 0.927183854567, 0.920504853452, 0.913545457643, 0.906307787037, 0.898794046299, 0.891006524188, 0.882947592859, 0.874619707139, 0.866025403784, 0.857167300702, 0.848048096156, 0.838670567945, 0.829037572555, 0.819152044289, 0.809016994375, 0.798635510047, 0.788010753607, 0.777145961457, 0.766044443119, 0.754709580223, 0.743144825477, 0.731353701619, 0.719339800339, 0.707106781187, 0.694658370459, 0.681998360062, 0.669130606359, 0.656059028991, 0.642787609687, 0.62932039105, 0.615661475326, 0.601815023152, 0.587785252292, 0.573576436351, 0.559192903471, 0.544639035015, 0.529919264233, 0.51503807491, 0.5, 0.484809620246, 0.469471562786, 0.45399049974, 0.438371146789, 0.422618261741, 0.406736643076, 0.390731128489, 0.374606593416, 0.358367949545, 0.342020143326, 0.325568154457, 0.309016994375, 0.292371704723, 0.275637355817, 0.258819045103, 0.2419218956, 0.224951054344, 0.207911690818, 0.190808995377, 0.173648177667, 0.15643446504, 0.13917310096, 0.121869343405, 0.104528463268, 0.0871557427477, 0.0697564737441, 0.0523359562429, 0.0348994967025, 0.0174524064373, 6.12323399574e-17, -0.0174524064373, -0.0348994967025, -0.0523359562429, -0.0697564737441, -0.0871557427477, -0.104528463268, -0.121869343405, -0.13917310096, -0.15643446504, -0.173648177667, -0.190808995377, -0.207911690818, -0.224951054344, -0.2419218956, -0.258819045103, -0.275637355817, -0.292371704723, -0.309016994375, -0.325568154457, -0.342020143326, -0.358367949545, -0.374606593416, -0.390731128489, -0.406736643076, -0.422618261741, -0.438371146789, -0.45399049974, -0.469471562786, -0.484809620246, -0.5, -0.51503807491, -0.529919264233, -0.544639035015, -0.559192903471, -0.573576436351, -0.587785252292, -0.601815023152, -0.615661475326, -0.62932039105, -0.642787609687, -0.656059028991, -0.669130606359, -0.681998360062, -0.694658370459, -0.707106781187, -0.719339800339, -0.731353701619, -0.743144825477, -0.754709580223, -0.766044443119, -0.777145961457, -0.788010753607, -0.798635510047, -0.809016994375, -0.819152044289, -0.829037572555, -0.838670567945, -0.848048096156, -0.857167300702, -0.866025403784, -0.874619707139, -0.882947592859, -0.891006524188, -0.898794046299, -0.906307787037, -0.913545457643, -0.920504853452, -0.927183854567, -0.933580426497, -0.939692620786, -0.945518575599, -0.951056516295, -0.956304755963, -0.961261695938, -0.965925826289, -0.970295726276, -0.974370064785, -0.978147600734, -0.981627183448, -0.984807753012, -0.987688340595, -0.990268068742, -0.992546151641, -0.994521895368, -0.996194698092, -0.99756405026, -0.998629534755, -0.999390827019, -0.999847695156, -1.0, -0.999847695156, -0.999390827019, -0.998629534755, -0.99756405026, -0.996194698092, -0.994521895368, -0.992546151641, -0.990268068742, -0.987688340595, -0.984807753012, -0.981627183448, -0.978147600734, -0.974370064785, -0.970295726276, -0.965925826289, -0.961261695938, -0.956304755963, -0.951056516295, -0.945518575599, -0.939692620786, -0.933580426497, -0.927183854567, -0.920504853452, -0.913545457643, -0.906307787037, -0.898794046299, -0.891006524188, -0.882947592859, -0.874619707139, -0.866025403784, -0.857167300702, -0.848048096156, -0.838670567945, -0.829037572555, -0.819152044289, -0.809016994375, -0.798635510047, -0.788010753607, -0.777145961457, -0.766044443119, -0.754709580223, -0.743144825477, -0.731353701619, -0.719339800339, -0.707106781187, -0.694658370459, -0.681998360062, -0.669130606359, -0.656059028991, -0.642787609687, -0.62932039105, -0.615661475326, -0.601815023152, -0.587785252292, -0.573576436351, -0.559192903471, -0.544639035015, -0.529919264233, -0.51503807491, -0.5, -0.484809620246, -0.469471562786, -0.45399049974, -0.438371146789, -0.422618261741, -0.406736643076, -0.390731128489, -0.374606593416, -0.358367949545, -0.342020143326, -0.325568154457, -0.309016994375, -0.292371704723, -0.275637355817, -0.258819045103, -0.2419218956, -0.224951054344, -0.207911690818, -0.190808995377, -0.173648177667, -0.15643446504, -0.13917310096, -0.121869343405, -0.104528463268, -0.0871557427477, -0.0697564737441, -0.0523359562429, -0.0348994967025, -0.0174524064373, -1.83697019872e-16, 0.0174524064373, 0.0348994967025, 0.0523359562429, 0.0697564737441, 0.0871557427477, 0.104528463268, 0.121869343405, 0.13917310096, 0.15643446504, 0.173648177667, 0.190808995377, 0.207911690818, 0.224951054344, 0.2419218956, 0.258819045103, 0.275637355817, 0.292371704723, 0.309016994375, 0.325568154457, 0.342020143326, 0.358367949545, 0.374606593416, 0.390731128489, 0.406736643076, 0.422618261741, 0.438371146789, 0.45399049974, 0.469471562786, 0.484809620246, 0.5, 0.51503807491, 0.529919264233, 0.544639035015, 0.559192903471, 0.573576436351, 0.587785252292, 0.601815023152, 0.615661475326, 0.62932039105, 0.642787609687, 0.656059028991, 0.669130606359, 0.681998360062, 0.694658370459, 0.707106781187, 0.719339800339, 0.731353701619, 0.743144825477, 0.754709580223, 0.766044443119, 0.777145961457, 0.788010753607, 0.798635510047, 0.809016994375, 0.819152044289, 0.829037572555, 0.838670567945, 0.848048096156, 0.857167300702, 0.866025403784, 0.874619707139, 0.882947592859, 0.891006524188, 0.898794046299, 0.906307787037, 0.913545457643, 0.920504853452, 0.927183854567, 0.933580426497, 0.939692620786, 0.945518575599, 0.951056516295, 0.956304755963, 0.961261695938, 0.965925826289, 0.970295726276, 0.974370064785, 0.978147600734, 0.981627183448, 0.984807753012, 0.987688340595, 0.990268068742, 0.992546151641, 0.994521895368, 0.996194698092, 0.99756405026, 0.998629534755, 0.999390827019, 0.999847695156
};
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

}SVPWM;

SVPWM pwmBoi;

//Returns the current sector of the SVPWM system
SVPWM_SEC SVPWM_GetControlAngleSEC(SVPWM *pm){

    //Because this is integer math, the remnants are automatically discarded and we're left with how many times 60 degrees goes into the current angle
    //This is allowed because enums always start at 0 and go to #elements -1. SO each sector gets a subsequent assignment
    return ((*pm).ControlAngle / EQUIVALENT_60deg) % 6; //CONVRET TO multiples of 60 deg
    /*
    int8_t inter = ((*pm).ControlAngle / EQUIVALENT_60deg) % 6; //CONVRET TO multiples of 60 deg

        switch(inter){
    case 0:
        return SEC1;
        break;
    case 1:
        return SEC2;
        break;
    case 2:
        return SEC3;
        break;
    case 3:
        return SEC4;
        break;
    case 4:
        return SEC5;
        break;
    case 5:
        return SEC6;
        break;
    default:
        return SEC1;
    }*/
}

//Updates the sector of the control signal
void SVPWM_SetCurrentSEC(SVPWM *pm){
    (*pm).CurrentSector = SVPWM_GetControlAngleSEC(pm);
}

//Sets the transistors for state V0. T1 and T4 is LSB
void SVPWM_WriteV0(SVPWM *pm){
    (*pm).setTran1(0);
    (*pm).setTran2(0);
    (*pm).setTran3(0);

    (*pm).setTran4(1);
    (*pm).setTran5(1);
    (*pm).setTran6(1);
}

//Sets the transistors for state V1
void SVPWM_WriteV1(SVPWM *pm){
    (*pm).setTran1(1);
    (*pm).setTran2(0);
    (*pm).setTran3(0);

    (*pm).setTran4(0);
    (*pm).setTran5(1);
    (*pm).setTran6(1);
}

//Sets the transistors for state V2
void SVPWM_WriteV2(SVPWM *pm){
    (*pm).setTran1(0);
    (*pm).setTran2(1);
    (*pm).setTran3(0);

    (*pm).setTran4(1);
    (*pm).setTran5(0);
    (*pm).setTran6(1);
}

//Sets the transistors for state V3
void SVPWM_WriteV3(SVPWM *pm){
    (*pm).setTran1(1);
    (*pm).setTran2(1);
    (*pm).setTran3(0);

    (*pm).setTran4(0);
    (*pm).setTran5(0);
    (*pm).setTran6(1);
}

//Sets the transistors for state V4
void SVPWM_WriteV4(SVPWM *pm){
    (*pm).setTran1(0);
    (*pm).setTran2(0);
    (*pm).setTran3(1);

    (*pm).setTran4(1);
    (*pm).setTran5(1);
    (*pm).setTran6(0);
}

//Sets the transistors for state V5
void SVPWM_WriteV5(SVPWM *pm){
    (*pm).setTran1(1);
    (*pm).setTran2(0);
    (*pm).setTran3(1);

    (*pm).setTran4(0);
    (*pm).setTran5(1);
    (*pm).setTran6(0);
}

//Sets the transistors for state V6
void SVPWM_WriteV6(SVPWM *pm){
    (*pm).setTran1(0);
    (*pm).setTran2(1);
    (*pm).setTran3(1);

    (*pm).setTran4(1);
    (*pm).setTran5(0);
    (*pm).setTran6(0);
}

//Sets the transistors for state V7
void SVPWM_WriteV7(SVPWM *pm){
    (*pm).setTran1(1);
    (*pm).setTran2(1);
    (*pm).setTran3(1);

    (*pm).setTran4(0);
    (*pm).setTran5(0);
    (*pm).setTran6(0);
}

//Sets the transistors to off state
void SVPWM_WriteOFF(SVPWM *pm){
    (*pm).setTran1(0);
    (*pm).setTran2(0);
    (*pm).setTran3(0);

    (*pm).setTran4(0);
    (*pm).setTran5(0);
    (*pm).setTran6(0);
}

//Updates the current timer to get the next wait time
void SVPWM_UpdateCurrentTimer(SVPWM *pm){
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
SVPWM_ABS_VEC SVPWM_GetAbsoluteVoltageVector(SVPWM *pm){
    //Two zero vectors are independent of the state
    if((*pm).State == V0_REL)
        return V0_ABS;
    if((*pm).State == V7_REL)
        return V7_ABS;

    switch((*pm).CurrentSector){
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
void SVPWM_SetNextRelativeState(SVPWM *pm){
    switch((*pm).State){
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
void SVPWM_SetControlAngle(SVPWM *pm, uint16_t inputAngle){
        (*pm).ControlAngle = inputAngle;
        (*pm).RefAngle =  inputAngle % EQUIVALENT_60deg; //Find how many points past the nearest 60 we are
}

//Calculates the appropriate amount of time to spend in each sector
void SVPWM_SetVectorTimes(SVPWM *pm){
    uint8_t sector;
    uint16_t sectorIndex, angleIndex;
    sector = (*pm).CurrentSector + 1;
    printf("Sector + 1 %d\r\n", sector);
    sectorIndex = sector * 60 - 1;
    printf("Sector index %d\r\n", sectorIndex);
    angleIndex = (*pm).RefAngle * 60 / MAX_ANGLE;
    printf("Angle Index %d\r\n", angleIndex);

    (*pm).Timer.basicVec1 = (SQRT_3 * (*pm).Timer.totalPeriod * (*pm).refVector.magnitude * (sineTable[sectorIndex] * cosineTable[angleIndex] - sineTable[angleIndex] * cosineTable[sectorIndex]));

    sectorIndex = (sector - 1) * 60;
    (*pm).Timer.basicVec2 = (SQRT_3 * (*pm).Timer.totalPeriod * (*pm).refVector.magnitude * (- sineTable[sectorIndex] * cosineTable[angleIndex] + sineTable[angleIndex] * cosineTable[sectorIndex]));

    (*pm).Timer.halfZeroVector = ((*pm).Timer.totalPeriod - (*pm).Timer.basicVec1 - (*pm).Timer.basicVec2) >> 1;

}

//Calls the write function to the input vector
void SVPWM_WriteABSVector(SVPWM *pm){
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


void SVPWM_STDISR(SVPWM *pm){
    SVPWM_SetCurrentSEC(pm);
    SVPWM_SetNextRelativeState(pm);
    SVPWM_WriteABSVector(pm);
    SVPWM_SetVectorTimes(pm);
    SVPWM_UpdateCurrentTimer(pm);
}

uint16_t Test_setTimer(uint16_t time){
    printf("Time: %d\n\r", time);
}

void fakeISR(){
    SVPWM_STDISR(&pwmBoi);
    Test_setTimer(0xFFFF - pwmBoi.Timer.currentTime);
}

//Basic Debugging functions
uint8_t TEST_V0(uint8_t input){
    if(input == 0)
        printf("T0: OFF\n\r");
    if(input == 1)
        printf("T0: ON\n\r");
}
uint8_t TEST_V1(uint8_t input){
    if(input == 0)
        printf("T1: OFF\n\r");
    if(input == 1)
        printf("T1: ON\n\r");
}
uint8_t TEST_V2(uint8_t input){
    if(input == 0)
        printf("T2: OFF\n\r");
    if(input == 1)
        printf("T2: ON\n\r");
}
uint8_t TEST_V3(uint8_t input){
    if(input == 0)
        printf("T3: OFF\n\r");
    if(input == 1)
        printf("T3: ON\n\r");
}
uint8_t TEST_V4(uint8_t input){
    if(input == 0)
        printf("T4: OFF\n\r");
    if(input == 1)
        printf("T4: ON\n\r");
}
uint8_t TEST_V5(uint8_t input){
    if(input == 0)
        printf("T5: OFF\n\r");
    if(input == 1)
        printf("T5: ON\n\r");
}
uint8_t TEST_V6(uint8_t input){
    if(input == 0)
        printf("T6: OFF\n\r");
    if(input == 1)
        printf("T6: ON\n\r");
}

int main()
{

    //Setup function pointers
    pwmBoi.setTran1 = TEST_V1;
    pwmBoi.setTran2 = TEST_V2;
    pwmBoi.setTran3 = TEST_V3;
    pwmBoi.setTran4 = TEST_V4;
    pwmBoi.setTran5 = TEST_V5;
    pwmBoi.setTran6 = TEST_V6;

    //Set angle & find the sine
    SVPWM_SetControlAngle(&pwmBoi, (MAX_ANGLE*75/360));

    //Find the sector
    SVPWM_SetCurrentSEC(&pwmBoi);
    printf("Sector: %u\n\r", pwmBoi.CurrentSector);

    //Calculate Switching Times

    pwmBoi.Timer.totalPeriod = 30000;
    pwmBoi.Timer.magnitude = 0x7F;
    SVPWM_SetVectorTimes(&pwmBoi);
    
    pwmBoi.refVector.magnitude = 1000;
/*
    printf("Magnitude: %u\n\r", pwmBoi.Timer.Magnitude);
    printf("Total Period: %u\n\r", pwmBoi.Timer.totalPeriod);
    printf("Half Vec Time: %u\n\r", pwmBoi.Timer.halfZeroVector);
    printf("Vec 1 Time: %u\n\r", pwmBoi.Timer.basicVec1);
    printf("Vec 2 Time: %u\n\r", pwmBoi.Timer.basicVec2);
    printf("Sector: %d\n\r", (pwmBoi.CurrentSector));
    printf("Current State: %d\n\r", pwmBoi.State);

    pwmBoi.State = V0_REL;
    printf("Current State: %d\n\r", pwmBoi.State);
    printf("ABS Voltage: %d\n\r", SVPWM_GetAbsoluteVoltageVector(&pwmBoi));

    pwmBoi.State = V1_REL;
    printf("Current State: %d\n\r", pwmBoi.State);
    printf("ABS Voltage: %d\n\r", SVPWM_GetAbsoluteVoltageVector(&pwmBoi));

    pwmBoi.State = V2_REL;
    printf("Current State: %d\n\r", pwmBoi.State);
    printf("ABS Voltage: %d\n\r", SVPWM_GetAbsoluteVoltageVector(&pwmBoi));

    pwmBoi.State = V7_REL;
    printf("Current State: %d\n\r", pwmBoi.State);
    printf("ABS Voltage: %d\n\r", SVPWM_GetAbsoluteVoltageVector(&pwmBoi));
*/
    uint16_t TEST_Angles [19] = {12, 45, 59, 60, 105, 119, 120, 155, 179, 180, 203, 239, 240, 258, 299, 300, 315, 359, 360};

    for(int i = 0; i < 19; i ++){
        printf("--------------------------------------------------\n\r");
        printf("Angle: %d\n\r", TEST_Angles[i]);
        printf("Angle: %d\n\r", pwmBoi.RefAngle * 60 / MAX_ANGLE);
        SVPWM_SetControlAngle(&pwmBoi, (MAX_ANGLE*TEST_Angles[i]/360));
        printf("Control Angle: %d\n\r", pwmBoi.ControlAngle);
        printf("Ref Angle: %d\n\r", pwmBoi.RefAngle);
        for(int j = 0; j < 4; j++){
            printf("***************************\n\r");
            fakeISR();
            printf("ABS Voltage: %d\n\r", SVPWM_GetAbsoluteVoltageVector(&pwmBoi));
            printf("Sector: %d\n\r", (pwmBoi.CurrentSector));
            printf("Current State: %d\n\r", pwmBoi.State);
            printf("Total Period: %u\n\r", pwmBoi.Timer.totalPeriod);
            printf("Half Vec Time: %u\n\r", pwmBoi.Timer.halfZeroVector);
            printf("Vec 1 Time: %u\n\r", pwmBoi.Timer.basicVec1);
            printf("Vec 2 Time: %u\n\r", pwmBoi.Timer.basicVec2);
        }
    }

    return 0;
}
