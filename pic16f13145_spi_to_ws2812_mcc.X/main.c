 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "image.h"

/*
    Main application
*/

#define NUMBER_OF_ROWS        8
#define NUMBER_OF_COLUMNS     32
#define NUMBER_OF_LEDS        ( NUMBER_OF_ROWS*NUMBER_OF_COLUMNS )
#define RGB_IMAGE_SIZE        ( NUMBER_OF_LEDS * 3 )

typedef struct
{
    uint8_t greenChannel;
    uint8_t redChannel;
    uint8_t blueChannel;
} color_t; 


static void WriteLEDsString(color_t const * const frame) 
{
    SPI1_Open(Custom_SPI); 
    SPI1_BufferExchange(frame, RGB_IMAGE_SIZE);
    SPI1_Close(); 
}

int main(void)
{

    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 
    
    while(1)
    {
        CLBSWINLbits.CLBSWIN0 = 0; // DEMUX out0, SPI routed to PPSOUT pins
        __delay_ms(100);
        
        WriteLEDsString(imageR);
        __delay_ms(100);
        
        WriteLEDsString(imageG);
        __delay_ms(100);
        

        CLBSWINLbits.CLBSWIN0 = 1; // DEMUX out1, SPI routed to SPI_to_WS2812 CLB circuit
        __delay_ms(100);
        
        WriteLEDsString(imageR);
        __delay_ms(1000);
        
        WriteLEDsString(imageG);
        __delay_ms(1000);

    }    
}
