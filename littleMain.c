#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SQRT_3 1.73205080757
//SPVC means Space Vector Control

tpydef struct {
    int16_t Phase_U;
    int16_t Phase_V;
    int16_t Phase_W;
} SPVC_Vector

typedef struct {
    SPVC_Vector REFERENCE;  //Input location
    SPVC_Vector OUTPUT;     //Output controlled vector



} SPVC_Module;

SPVC_Vector SVPC_ClarkeTrans(SPVC_Vector input) {

    SPVC_Vector output;

    output.alpha = (2 * (input.Phase_U - (input.Phase_V / 2) - (input.Phase_W / 2))) / 3;
    output.beta = (2 * ((SQRT_3 * input.Phase_V / 2) - (SQRT_3 * input.Phase_W / 2))) / 3;

    return output;
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
