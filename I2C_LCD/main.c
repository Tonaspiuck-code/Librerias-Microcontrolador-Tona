 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

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
#include "XLCD_I2C/xlcd.h"

void initLCD();
void textInit();
void sendLCD_I2C(uint16_t address, uint8_t *data, size_t dataLength);
void putsXLCD(char *buffer);
unsigned char sendLCD[] = {0x00,0x00,0x00,0x00,0x00,0x00};



int main(void)
{
    SYSTEM_Initialize();
    IO_RF3_SetHigh();
    initLCD();
    textInit();

    
    while(1)
    {
       
        
    }    
}

void initLCD(){
    WriteCmdXLCD(0x30,sendLCD);
    sendLCD_I2C(0x3F, sendLCD, 6);
    __delay_ms(5);
	WriteCmdXLCD(0x30,sendLCD);
    sendLCD_I2C(0x3F, sendLCD, 6);
    __delay_ms(5);
	WriteCmdXLCD(0x32,sendLCD);
    sendLCD_I2C(0x3F, sendLCD, 6);
    __delay_ms(5);
    WriteCmdXLCD(FOUR_BIT & LINES_5X7,sendLCD); 
    sendLCD_I2C(0x3F, sendLCD, 6);
    WriteCmdXLCD(CURSOR_ON & BLINK_ON,sendLCD);
    sendLCD_I2C(0x3F, sendLCD, 6);
    WriteCmdXLCD(RETURN_HOME,sendLCD);
    sendLCD_I2C(0x3F, sendLCD, 6);
    WriteCmdXLCD(RETURN_HOME,sendLCD);
    sendLCD_I2C(0x3F, sendLCD, 6);
    WriteCmdXLCD(0b00000110,sendLCD);           // Aseguramos incremento cursor & display fijo
    sendLCD_I2C(0x3F, sendLCD, 6);
}

void sendLCD_I2C(uint16_t address, uint8_t *data, size_t dataLength){
    uint8_t waitCounter = 100;
    //int i;
    //for(i = 0; i < dataLength; i++) {
    //    uint8_t d[] ={ data[i] };
        if(I2C1_Host.Write(address, data, dataLength)){
            waitCounter = 100; // This value depends on the system clock, I2C clock and data length.                                                                                          
            while ( I2C1_Host.IsBusy()){
                I2C1_Host.Tasks();
                waitCounter--;              
            }
            if (  I2C1_Host.ErrorGet() == I2C_ERROR_NONE){
                // Write operation is successful
            }
            else{
                // Error handling
            }
        }
        //__delay_ms(1);
    //}
}

void putsXLCD(char *buffer){
    
        while(*buffer)                  // Write data to LCD up to null
        {
            //while(BusyXLCD());      // Wait while LCD is busy
            //__delay_ms(5);
            WriteDataXLCD(*buffer,sendLCD); // Write character to LCD
            sendLCD_I2C(0x3F, sendLCD, 6);
            buffer++;               // Increment buffer
        }
        return;
}

void textInit(){
    SetDDRamAddr(0x00,sendLCD); 
    sendLCD_I2C(0x3F, sendLCD, 6);
    putsXLCD("** Mecatronizate **");

/*    SetDDRamAddr(SECOND_LINE,sendLCD);
    sendLCD_I2C(0x3F, sendLCD, 6);
*/    
    SetDDRamAddr(THIRD_LINE,sendLCD);
    sendLCD_I2C(0x3F, sendLCD, 6);
    putsXLCD(" LCD con i2c");

//    SetDDRamAddr(FOURTH_LINE,sendLCD);

}