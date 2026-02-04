/* 
 * File:   keypad4x4.h
 * Author: mecatronizate
 *
 * ESTE SOFTWARE SE PROPORCIONA "AS IS" ("TAL CUAL"), SIN NINGUNA GARANT�A...
 * ...
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND...
 * 
 * 
 */


#ifndef KEYPAD4X4_H
#define	KEYPAD4X4_H


// Libreria que contiene las definiciones de LATCH y PORT
#include <xc.h>

// *********************************************************************
//       No olvide cambiar los valores por los que usted utiliza
// *********************************************************************
//
// Pines utilizados para las columnas:
// PORT es para ENTRADAS
#define Col_1 PORTBbits.RB7
#define Col_2 PORTBbits.RB6
#define Col_3 PORTBbits.RB5
#define Col_4 PORTBbits.RB4
// Pines utilizados para los renglones:
// LAT es para SALIDAS
#define Row_1 LATBbits.LATB3 
#define Row_2 LATBbits.LATB2 
#define Row_3 LATBbits.LATB1 
#define Row_4 LATBbits.LATB0 


unsigned char getKey();
        
#endif	/* KEYPAD4X4_H */

