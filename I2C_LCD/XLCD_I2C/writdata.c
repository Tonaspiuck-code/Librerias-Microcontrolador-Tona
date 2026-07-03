//#include <p18cxxx.h>
//#include <xlcd.h>
//#include <xc.h>
#include "xlcd.h"
/********************************************************************
*       Function Name:  WriteDataXLCD                               *
*       Return Value:   void                                        *
*       Parameters:     data: data byte to be written to LCD        *
*       Description:    This routine writes a data byte to the      *
*                       Hitachi HD44780 LCD controller. The user    *
*                       must check to see if the LCD controller is  *
*                       busy before calling this routine. The data  *
*                       is written to the character generator RAM or*
*                       the display data RAM depending on what the  *
*                       previous SetxxRamAddr routine was called.   *
********************************************************************/
void WriteDataXLCD(char data, unsigned char * bfrCmd)
{
    bfrCmd[0] = (data & 0xF0)|0x09;
    bfrCmd[1] = bfrCmd[0] |0x0D; // D7 D6 D5 D4 -- E RW RS 
    bfrCmd[2] = bfrCmd[0];
    bfrCmd[3] = ((data<<4)&0xF0)|0x09;
    bfrCmd[4] = bfrCmd[3] | 0b00001101; // D7 D6 D5 D4 -- E RW RS
    bfrCmd[5] = bfrCmd[3];
    //bfrCmd[] = {dataLCD_U,dataLCD_UE,dataLCD_L,dataLCD_LE,0x00};
    
    //bool r = I2C1_Write(LCD_ADDR, bfrCmd, 6);
 
    return;
}

