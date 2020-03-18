/* 
 * File:   methods.h
 * Author: Kyle Frisbee
 *
 * Created on March 18, 2020, 11:32 AM
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "dataStructures.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/pin_manager.h"

#ifndef METHODS_H
#define	METHODS_H

#ifdef	__cplusplus
extern "C" {
#endif

void initialize() {
    
    INTCONbits.GIE = 1;         // Enable global interrupts
    
    SYSTEM_Initialize();    //in MCC.h inits CLK, pins, TMR
     
}

HallData readHallData() {
    
    HallData input;
    
    input.phaseU = HALLA_PORT;
    input.phaseV = HALLB_PORT;
    input.phaseW = HALLC_PORT;
    return input;
    
}

// function to read in the Hall sensor data
SwitchingState interpretHallData(HallData input) {

    if (BUTTON_PORT == 1 || KILLSWITCH_PORT == 1) return OFF; 
    // if the button is not pressed, the motor should be OFF
    // OR if the dead man switch is released, turn the motor OFF
    
    else if (input.phaseU == 1 && input.phaseV == 0 && input.phaseW == 1) return State1;

    else if (input.phaseU == 1 && input.phaseV == 0 && input.phaseW == 0) return State2;

    else if (input.phaseU == 1 && input.phaseV == 1 && input.phaseW == 0) return State3;

    else if (input.phaseU == 0 && input.phaseV == 1 && input.phaseW == 0) return State4;

    else if (input.phaseU == 0 && input.phaseV == 1 && input.phaseW == 1) return State5;

    else if (input.phaseU == 0 && input.phaseV == 0 && input.phaseW == 1) return State6;

    else return OFF;
}

// function to determine CW switching based on output from readHalldata(), returns PWM signal to be sent out
PWMSignalOut setCWSwitching(SwitchingState currentState) {

    PWMSignalOut output;

    switch(currentState) {

    case State1:

        output.signalA_H = 1;
        output.signalA_L = 0;
        output.signalB_H = 0;
        output.signalB_L = 1;
        output.signalC_H = 0;
        output.signalC_L = 0;
        return output;

    case State2:

        output.signalA_H = 1;
        output.signalA_L = 0;
        output.signalB_H = 0;
        output.signalB_L = 0;
        output.signalC_H = 0;
        output.signalC_L = 1;
        return output;

    case State3:

        output.signalA_H = 0;
        output.signalA_L = 0;
        output.signalB_H = 1;
        output.signalB_L = 0;
        output.signalC_H = 0;
        output.signalC_L = 1;
        return output;

    case State4:

        output.signalA_H = 0;
        output.signalA_L = 1;
        output.signalB_H = 1;
        output.signalB_L = 0;
        output.signalC_H = 0;
        output.signalC_L = 0;
        return output;

    case State5:

        output.signalA_H = 0;
        output.signalA_L = 1;
        output.signalB_H = 0;
        output.signalB_L = 0;
        output.signalC_H = 1;
        output.signalC_L = 0;
        return output;

    case State6:

        output.signalA_H = 0;
        output.signalA_L = 0;
        output.signalB_H = 0;
        output.signalB_L = 1;
        output.signalC_H = 1;
        output.signalC_L = 0;
        return output;

    // default case - turn the motor off (all 0 or all 1)
    default:
        output.signalA_H = 0;
        output.signalA_L = 0;
        output.signalB_H = 0;
        output.signalB_L = 0;
        output.signalC_H = 0;
        output.signalC_L = 0;
        return output;
    }

}

// switching to turn motor CCW
PWMSignalOut setCCWSwitching(SwitchingState currentState) {

    PWMSignalOut output;

    switch(currentState) {

    case State1:

        output.signalA_H = 0;
        output.signalA_L = 1;
        output.signalB_H = 1;
        output.signalB_L = 0;
        output.signalC_H = 0;
        output.signalC_L = 0;
        return output;

    case State2:

        output.signalA_H = 0;
        output.signalA_L = 1;
        output.signalB_H = 0;
        output.signalB_L = 0;
        output.signalC_H = 1;
        output.signalC_L = 0;
        return output;

    case State3:

        output.signalA_H = 0;
        output.signalA_L = 0;
        output.signalB_H = 0;
        output.signalB_L = 1;
        output.signalC_H = 1;
        output.signalC_L = 0;
        return output;

    case State4:

        output.signalA_H = 1;
        output.signalA_L = 0;
        output.signalB_H = 0;
        output.signalB_L = 1;
        output.signalC_H = 0;
        output.signalC_L = 0;
        return output;

    case State5:

        output.signalA_H = 1;
        output.signalA_L = 0;
        output.signalB_H = 0;
        output.signalB_L = 0;
        output.signalC_H = 0;
        output.signalC_L = 1;
        return output;

    case State6:

        output.signalA_H = 0;
        output.signalA_L = 0;
        output.signalB_H = 1;
        output.signalB_L = 0;
        output.signalC_H = 0;
        output.signalC_L = 1;
        return output;

    // default case - turn the motor off (all 0 or all 1)
    default:
        output.signalA_H = 0;
        output.signalA_L = 0;
        output.signalB_H = 0;
        output.signalB_L = 0;
        output.signalC_H = 0;
        output.signalC_L = 0;
        return output;
    }

}

// function to send signals to motor-controller
void writePWM(PWMSignalOut output) {

    A_H_LAT = output.signalA_H;
    A_L_LAT = output.signalA_L;
    B_H_LAT = output.signalB_H;
    B_L_LAT = output.signalB_L;
    C_H_LAT = output.signalC_H;
    C_L_LAT = output.signalC_L;
    
}

// interrupt function
void high_priority_interrupt_tmr0_isr(void) {

    INTCONbits.TMR0IF = 0; //clear TMR0 interrupt flag
        
    // first read the latest Hall data
    HallData input = readHallData();
    // use hall data to determine state of the motor
    SwitchingState state = interpretHallData(input);
    // use state of the motor to set PWM output
    PWMSignalOut output = setCWSwitching(state);
    // send PWM output to the motor
    writePWM(output);
}

#ifdef	__cplusplus
}
#endif

#endif	/* METHODS_H */

