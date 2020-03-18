/* 
 * File:   dataStructures.h
 * Author: Kyle Frisbee
 *
 * Created on March 18, 2020, 11:30 AM
 */

#ifndef DATASTRUCTURES_H
#define	DATASTRUCTURES_H

#ifdef	__cplusplus
extern "C" {
#endif

// data structure to hold Hall sensor data
typedef struct {

    uint8_t phaseU;
    uint8_t phaseV;
    uint8_t phaseW;

} HallData;

// data structure to hold switching states
typedef enum {

    OFF,
    State1,
    State2,
    State3,
    State4,
    State5,
    State6,

} SwitchingState;

typedef struct {

    uint8_t signalA_H;
    uint8_t signalA_L;
    uint8_t signalB_H;
    uint8_t signalB_L;
    uint8_t signalC_H;
    uint8_t signalC_L;

} PWMSignalOut;

typedef struct {
    
    HallData input;
    SwitchingState state;
    PWMSignalOut ouput;
    
} ControlData;

#ifdef	__cplusplus
}
#endif

#endif	/* DATASTRUCTURES_H */

