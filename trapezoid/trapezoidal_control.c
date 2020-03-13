// Kyle Frisbee and Dominic Lauer
// basic Trapezoidal Control for BLDC motor

// data structure to hold Hall sensor data
typedef struct {

    uint8_t phaseU;
    uint8_t phaseV;
    uint8_t phaseW;

} HallData

// data structure to hold switching states
typedef enum {

    OFF;
    State1;
    State2;
    State3;
    State4;
    State5;
    State6;

} SwitchingState

typedef struct {

    uint8_t signalA_H;
    uint8_t signalA_L;
    uint8_t signalB_H;
    uint8_t signalB_L;
    uint8_t signalC_H;
    uint8_t signalC_L;

} PWMSignalOut

// function to read in the Hall sensor data
SwitchingState readHallData(HallData input) {

    if (input.phaseU == 1 && input.phaseV == 0 && input.phaseW == 1) return State1;

    else if (input.phaseU == 1 && input.phaseV == 0 && input.phaseW == 0) return State2;

    else if (input.phaseU == 1 && input.phaseV == 1 && input.phaseW == 0) return State3;

    else if (input.phaseU == 0 && input.phaseV == 1 && input.phaseW == 0) return State4;

    else if (input.phaseU == 0 && input.phaseV == 1 && input.phaseW == 1) return State5;

    else if (input.phaseU == 0 && input.phaseV == 0 && input.phaseW == 1) return State6;

    else return OFF;
}

// function to determine switching states based on output from readHalldata(), returns PWM signal to be sent out
PWMSignalOut setSwitchingStates(SwitchingState currentState) {

    PWMSignalOut output;

    switch(currentState) {

    case State1:

        output.signalA_H = 1;
        output.signalA_L = 0;
        output.signalB_H = 0;
        output.signalB_L = 0;
        output.signalC_H = 1;
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
        output.signalA_L = 1;
        output.signalB_H = 0;
        output.signalB_L = 0;
        output.signalC_H = 0;
        output.signalC_L = 1;
        return output;

    case State4:

        output.signalA_H = 0;
        output.signalA_L = 1;
        output.signalB_H = 0;
        output.signalB_L = 1;
        output.signalC_H = 0;
        output.signalC_L = 0;
        return output;

    case State5:

        output.signalA_H = 0;
        output.signalA_L = 0;
        output.signalB_H = 1;
        output.signalB_L = 1;
        output.signalC_H = 0;
        output.signalC_L = 0;
        return output;

    case State6:

        output.signalA_H = 0;
        output.signalA_L = 0;
        output.signalB_H = 1;
        output.signalB_L = 0;
        output.signalC_H = 1;
        output.signalC_L = 0;
        return output;

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

// function to send signals to microcontroller
void writePWM(PWMSignalOut output) {



}
// interrupt function
void interrupt() {



}
