//#include <p18cxxx.h>
#include "xlcd.h"

/********************************************************************
*       Function Name:  WriteCmdXLCD                                *
*       Return Value:   void                                        *
*       Parameters:     cmd: command to send to LCD                 *
*       Description:    This routine writes a command to the Hitachi*
*                       HD44780 LCD controller. The user must check *
*                       to see if the LCD controller is busy before *
*                       calling this routine.                       *
********************************************************************/
void WriteCmdXLCD(unsigned char cmd,unsigned char * bfrCmd)
{
    bfrCmd[0] = (cmd & 0xF0) | 0x08;
    bfrCmd[1] = bfrCmd[0] |0x0C; // D7 D6 D5 D4 -- E RW RS 
    bfrCmd[2] = bfrCmd[0];
    bfrCmd[3] = ((cmd<<4)& 0xF0) | 0x08;
    bfrCmd[4] = bfrCmd[3] | 0b00001100; // D7 D6 D5 D4 -- E RW RS
    bfrCmd[5] = bfrCmd[3];
    //unsigned char cmdLCD[]  = {cmdLCD_U,cmdLCD_UE,cmdLCD_L,cmdLCD_LE,0x00};
    
    //bool r = I2C1_Write(LCD_ADDR, bfrCmd, 6);

    return;
}

