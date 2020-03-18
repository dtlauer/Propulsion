// Kyle Frisbee and Dominic Lauer
// basic Trapezoidal Control for BLDC motor\

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "dataStructures.h"
#include "methods.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/pin_manager.h"

void main() {
    
    initialize();
    
    for(;;) {   // interrupt is enabled, so just let it run
        
/*        INTCONbits.TMR0IE = 0; //disable TMR0 interrupt
        
        while(BUTTON_PORT == 1); 
        //while button is not pressed, wait
        //BUTTON_PORT will equal 0 when button is pressed
*/              
    }
    //turn off interrupts
    //look for button press while button == 0;
    //turn on interrupts
    
    
    
/*    HallData input;
    input.phaseU = 0;
    input.phaseV = 0;
    input.phaseW = 0;

    SwitchingState currentState = interpretHallData(input);
    printf("State: %d\n", currentState);

    PWMSignalOut output = setSwitchingStates(currentState);
    printf("A_H: %d\n", output.signalA_H);
    printf("A_L: %d\n", output.signalA_L);
    printf("B_H: %d\n", output.signalB_H);
    printf("B_L: %d\n", output.signalB_L);
    printf("C_H: %d\n", output.signalC_H);
    printf("C_L: %d\n", output.signalC_L);
*/
}
