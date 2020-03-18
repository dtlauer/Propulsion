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
    
    for (;;) {   // interrupt is enabled, so just let it run
        
        /*
         * Handling of the switch bounce for the external accelerator button. 
         * When car is currently accelerating (button is pushed) this block will
         * not be entered.
         * 50ms delay allows time for button to settle. Without this, ISR would
         * continue running and motor would rapidly turn on/off with the bounce.
         */
        if (BUTTON_PORT == 1 && KILLSWITCH_PORT == 0) {
            while (BUTTON_PORT);    //waits for button to be pushed
            INTCONbits.TMR0IE = 0; //disable TMR0 interrupt
            __delay_ms(50);
            INTCONbits.TMR0IE = 1; //enable TMR0 interrupt   
        }
/*        INTCONbits.TMR0IE = 0; //disable TMR0 interrupt
        
        while(BUTTON_PORT == 1); 
        //while button is not pressed, wait
        //BUTTON_PORT will equal 0 when button is pressed
*/              
    }

    
    
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
