#ifndef __XLCD_H
#define __XLCD_H
#include <xc.h>
// addres for the MCC created header files
#include "../mcc_generated_files/system/system.h"

/*
 * 
 * This is just a small modification to be used in other PICs, 
 * all the code is based on the PLIB xc8 original files.
 *  
 * Since there is no PortX control no modification about the 
 * UPPER/LOWER bits
 * 
 * 
 */

/* PIC18 XLCD peripheral routines.
 *
 *   Notes:
 *      - These libraries routines are written to support the
 *        Hitachi HD44780 LCD controller.
 

 * That is how is connected the data pin for the PC8574AT 
 * 
 * P0 P1 P2 P3 P4 P5 P6 P7
 * RS RW E  -- D4 D5 D6 D7
 * 
 */


#define LCD_ADDR    0x3F        /* PCF8574T */

/* Display ON/OFF Control defines */
#define DON         0b00001111  /* Display on      */
#define DOFF        0b00001011  /* Display off     */
#define CURSOR_ON   0b00001111  /* Cursor on       */
#define CURSOR_OFF  0b00001101  /* Cursor off      */
#define BLINK_ON    0b00001111  /* Cursor Blink    */
#define BLINK_OFF   0b00001110  /* Cursor No Blink */

#define CLEAR_SCREEN 0b00000001  /* Clear display  */
#define RETURN_HOME  0b00000010  /* Return home */
#define FIRST_LINE   0b00000000  /* First line First position */
#define SECOND_LINE  0b01000000  /* Second line First position */
#define THIRD_LINE   0b10010100//0b00010100  /* Third line First position */
#define FOURTH_LINE  0b11010100//0b01010100  /* Fourth line First position */

/*           Entry mode  Set       */
/* Cursor or Display Shift defines */
#define SHIFT_CUR_LEFT    0b00000100  /* Cursor shifts to the left   */
#define SHIFT_CUR_RIGHT   0b00000101  /* Cursor shifts to the right  */
#define SHIFT_DISP_LEFT   0b00000110  /* Display shifts to the left  */
#define SHIFT_DISP_RIGHT  0b00000111  /* Display shifts to the right */

/* Function Set defines */
#define FOUR_BIT   0b00101100  /* 4-bit Interface               */
#define EIGHT_BIT  0b00111100  /* 8-bit Interface               */
#define LINE_5X7   0b00110000  /* 5x7 characters, single line   */
#define LINE_5X10  0b00110100  /* 5x10 characters               */
#define LINES_5X7  0b00111000  /* 5x7 characters, multiple line */

#ifdef _OMNI_CODE_
#define PARAM_SCLASS
#else
#define PARAM_SCLASS auto
#endif

#ifndef MEM_MODEL
#ifdef _OMNI_CODE_
#define MEM_MODEL
#else
#define MEM_MODEL far  /* Change this to near for small memory model */
#endif
#endif

/* OpenXLCD
 * Configures I/O pins for external LCD
 */
//void OpenXLCD(PARAM_SCLASS unsigned char);

/* SetCGRamAddr
 * Sets the character generator address
 */
//void SetCGRamAddr(PARAM_SCLASS unsigned char);

/* SetDDRamAddr
 * Sets the display data address
 */
void SetDDRamAddr(PARAM_SCLASS unsigned char, unsigned char * bfrCmd);

/* BusyXLCD
 * Returns the busy status of the LCD
 */
//unsigned char BusyXLCD(void);

/* ReadAddrXLCD
 * Reads the current address
 */
//unsigned char ReadAddrXLCD(void);

/* ReadDataXLCD
 * Reads a byte of data
 */
//char ReadDataXLCD(void);

/* WriteCmdXLCD
 * Writes a command to the LCD
 */
void WriteCmdXLCD(PARAM_SCLASS unsigned char, unsigned char * bfrCmd);

/* WriteDataXLCD
 * Writes a data byte to the LCD
 */
void WriteDataXLCD(PARAM_SCLASS char, unsigned char * bfrCmd);

/* putcXLCD
 * A putc is a write
 */
//#define putcXLCD WriteDataXLCD

/* putsXLCD
 * Writes a string of characters to the LCD
 */
//void putsXLCD(PARAM_SCLASS char *);
/* putrsXLCD
 * Writes a string of characters in ROM to the LCD
 */
//void putrsXLCD(const char *);

/* User defines these routines according to the oscillator frequency */
//extern void DelayFor18TCY(void);
//extern void DelayPORXLCD(void);
//extern void DelayXLCD(void);

#endif
