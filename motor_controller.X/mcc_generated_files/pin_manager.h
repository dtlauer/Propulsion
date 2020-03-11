/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F44K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set HALLA aliases
#define HALLA_TRIS                 TRISAbits.TRISA0
#define HALLA_LAT                  LATAbits.LATA0
#define HALLA_PORT                 PORTAbits.RA0
#define HALLA_ANS                  ANSELAbits.ANSA0
#define HALLA_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define HALLA_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define HALLA_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define HALLA_GetValue()           PORTAbits.RA0
#define HALLA_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define HALLA_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define HALLA_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define HALLA_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set HALLB aliases
#define HALLB_TRIS                 TRISAbits.TRISA1
#define HALLB_LAT                  LATAbits.LATA1
#define HALLB_PORT                 PORTAbits.RA1
#define HALLB_ANS                  ANSELAbits.ANSA1
#define HALLB_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define HALLB_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define HALLB_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define HALLB_GetValue()           PORTAbits.RA1
#define HALLB_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define HALLB_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define HALLB_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define HALLB_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set HALLC aliases
#define HALLC_TRIS                 TRISAbits.TRISA2
#define HALLC_LAT                  LATAbits.LATA2
#define HALLC_PORT                 PORTAbits.RA2
#define HALLC_ANS                  ANSELAbits.ANSA2
#define HALLC_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define HALLC_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define HALLC_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define HALLC_GetValue()           PORTAbits.RA2
#define HALLC_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define HALLC_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define HALLC_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define HALLC_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set BUTTON aliases
#define BUTTON_TRIS                 TRISAbits.TRISA3
#define BUTTON_LAT                  LATAbits.LATA3
#define BUTTON_PORT                 PORTAbits.RA3
#define BUTTON_ANS                  ANSELAbits.ANSA3
#define BUTTON_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define BUTTON_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define BUTTON_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define BUTTON_GetValue()           PORTAbits.RA3
#define BUTTON_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set KILLSWITCH aliases
#define KILLSWITCH_TRIS                 TRISAbits.TRISA4
#define KILLSWITCH_LAT                  LATAbits.LATA4
#define KILLSWITCH_PORT                 PORTAbits.RA4
#define KILLSWITCH_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define KILLSWITCH_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define KILLSWITCH_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define KILLSWITCH_GetValue()           PORTAbits.RA4
#define KILLSWITCH_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define KILLSWITCH_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set SCS aliases
#define SCS_TRIS                 TRISAbits.TRISA5
#define SCS_LAT                  LATAbits.LATA5
#define SCS_PORT                 PORTAbits.RA5
#define SCS_ANS                  ANSELAbits.ANSA5
#define SCS_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SCS_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SCS_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SCS_GetValue()           PORTAbits.RA5
#define SCS_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SCS_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SCS_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SCS_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set A_L aliases
#define A_L_TRIS                 TRISBbits.TRISB0
#define A_L_LAT                  LATBbits.LATB0
#define A_L_PORT                 PORTBbits.RB0
#define A_L_WPU                  WPUBbits.WPUB0
#define A_L_ANS                  ANSELBbits.ANSB0
#define A_L_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define A_L_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define A_L_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define A_L_GetValue()           PORTBbits.RB0
#define A_L_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define A_L_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define A_L_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define A_L_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define A_L_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define A_L_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set A_H aliases
#define A_H_TRIS                 TRISBbits.TRISB1
#define A_H_LAT                  LATBbits.LATB1
#define A_H_PORT                 PORTBbits.RB1
#define A_H_WPU                  WPUBbits.WPUB1
#define A_H_ANS                  ANSELBbits.ANSB1
#define A_H_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define A_H_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define A_H_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define A_H_GetValue()           PORTBbits.RB1
#define A_H_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define A_H_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define A_H_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define A_H_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define A_H_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define A_H_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS                 TRISBbits.TRISB2
#define EN_LAT                  LATBbits.LATB2
#define EN_PORT                 PORTBbits.RB2
#define EN_WPU                  WPUBbits.WPUB2
#define EN_ANS                  ANSELBbits.ANSB2
#define EN_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define EN_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define EN_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define EN_GetValue()           PORTBbits.RB2
#define EN_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define EN_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define EN_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define EN_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define EN_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set CAL aliases
#define CAL_TRIS                 TRISBbits.TRISB3
#define CAL_LAT                  LATBbits.LATB3
#define CAL_PORT                 PORTBbits.RB3
#define CAL_WPU                  WPUBbits.WPUB3
#define CAL_ANS                  ANSELBbits.ANSB3
#define CAL_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define CAL_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define CAL_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define CAL_GetValue()           PORTBbits.RB3
#define CAL_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define CAL_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define CAL_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define CAL_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define CAL_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define CAL_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set FAULT aliases
#define FAULT_TRIS                 TRISBbits.TRISB4
#define FAULT_LAT                  LATBbits.LATB4
#define FAULT_PORT                 PORTBbits.RB4
#define FAULT_WPU                  WPUBbits.WPUB4
#define FAULT_ANS                  ANSELBbits.ANSB4
#define FAULT_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define FAULT_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define FAULT_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define FAULT_GetValue()           PORTBbits.RB4
#define FAULT_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define FAULT_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define FAULT_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define FAULT_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define FAULT_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define FAULT_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set OCTW aliases
#define OCTW_TRIS                 TRISBbits.TRISB5
#define OCTW_LAT                  LATBbits.LATB5
#define OCTW_PORT                 PORTBbits.RB5
#define OCTW_WPU                  WPUBbits.WPUB5
#define OCTW_ANS                  ANSELBbits.ANSB5
#define OCTW_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define OCTW_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define OCTW_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define OCTW_GetValue()           PORTBbits.RB5
#define OCTW_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define OCTW_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define OCTW_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define OCTW_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define OCTW_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define OCTW_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set CLK aliases
#define CLK_TRIS                 TRISCbits.TRISC3
#define CLK_LAT                  LATCbits.LATC3
#define CLK_PORT                 PORTCbits.RC3
#define CLK_ANS                  ANSELCbits.ANSC3
#define CLK_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define CLK_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define CLK_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define CLK_GetValue()           PORTCbits.RC3
#define CLK_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define CLK_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define CLK_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define CLK_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SDI aliases
#define SDI_TRIS                 TRISCbits.TRISC4
#define SDI_LAT                  LATCbits.LATC4
#define SDI_PORT                 PORTCbits.RC4
#define SDI_ANS                  ANSELCbits.ANSC4
#define SDI_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDI_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDI_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDI_GetValue()           PORTCbits.RC4
#define SDI_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDI_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SDI_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SDO aliases
#define SDO_TRIS                 TRISCbits.TRISC5
#define SDO_LAT                  LATCbits.LATC5
#define SDO_PORT                 PORTCbits.RC5
#define SDO_ANS                  ANSELCbits.ANSC5
#define SDO_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SDO_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SDO_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SDO_GetValue()           PORTCbits.RC5
#define SDO_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SDO_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SDO_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set REF aliases
#define REF_TRIS                 TRISCbits.TRISC7
#define REF_LAT                  LATCbits.LATC7
#define REF_PORT                 PORTCbits.RC7
#define REF_ANS                  ANSELCbits.ANSC7
#define REF_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define REF_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define REF_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define REF_GetValue()           PORTCbits.RC7
#define REF_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define REF_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define REF_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define REF_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set LCD0 aliases
#define LCD0_TRIS                 TRISDbits.TRISD0
#define LCD0_LAT                  LATDbits.LATD0
#define LCD0_PORT                 PORTDbits.RD0
#define LCD0_ANS                  ANSELDbits.ANSD0
#define LCD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LCD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LCD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LCD0_GetValue()           PORTDbits.RD0
#define LCD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LCD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LCD0_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define LCD0_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set LCD1 aliases
#define LCD1_TRIS                 TRISDbits.TRISD1
#define LCD1_LAT                  LATDbits.LATD1
#define LCD1_PORT                 PORTDbits.RD1
#define LCD1_ANS                  ANSELDbits.ANSD1
#define LCD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LCD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LCD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LCD1_GetValue()           PORTDbits.RD1
#define LCD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LCD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LCD1_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define LCD1_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set SO2 aliases
#define SO2_TRIS                 TRISDbits.TRISD2
#define SO2_LAT                  LATDbits.LATD2
#define SO2_PORT                 PORTDbits.RD2
#define SO2_ANS                  ANSELDbits.ANSD2
#define SO2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define SO2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define SO2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define SO2_GetValue()           PORTDbits.RD2
#define SO2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define SO2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define SO2_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define SO2_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set SO1 aliases
#define SO1_TRIS                 TRISDbits.TRISD3
#define SO1_LAT                  LATDbits.LATD3
#define SO1_PORT                 PORTDbits.RD3
#define SO1_ANS                  ANSELDbits.ANSD3
#define SO1_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define SO1_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define SO1_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define SO1_GetValue()           PORTDbits.RD3
#define SO1_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define SO1_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define SO1_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define SO1_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set C_L aliases
#define C_L_TRIS                 TRISDbits.TRISD4
#define C_L_LAT                  LATDbits.LATD4
#define C_L_PORT                 PORTDbits.RD4
#define C_L_ANS                  ANSELDbits.ANSD4
#define C_L_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define C_L_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define C_L_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define C_L_GetValue()           PORTDbits.RD4
#define C_L_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define C_L_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define C_L_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define C_L_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set C_H aliases
#define C_H_TRIS                 TRISDbits.TRISD5
#define C_H_LAT                  LATDbits.LATD5
#define C_H_PORT                 PORTDbits.RD5
#define C_H_ANS                  ANSELDbits.ANSD5
#define C_H_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define C_H_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define C_H_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define C_H_GetValue()           PORTDbits.RD5
#define C_H_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define C_H_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define C_H_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define C_H_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set B_L aliases
#define B_L_TRIS                 TRISDbits.TRISD6
#define B_L_LAT                  LATDbits.LATD6
#define B_L_PORT                 PORTDbits.RD6
#define B_L_ANS                  ANSELDbits.ANSD6
#define B_L_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define B_L_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define B_L_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define B_L_GetValue()           PORTDbits.RD6
#define B_L_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define B_L_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define B_L_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define B_L_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set B_H aliases
#define B_H_TRIS                 TRISDbits.TRISD7
#define B_H_LAT                  LATDbits.LATD7
#define B_H_PORT                 PORTDbits.RD7
#define B_H_ANS                  ANSELDbits.ANSD7
#define B_H_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define B_H_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define B_H_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define B_H_GetValue()           PORTDbits.RD7
#define B_H_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define B_H_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define B_H_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define B_H_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/