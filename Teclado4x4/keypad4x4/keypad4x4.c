#include "keypad4x4.h"


unsigned char getKey(){
    unsigned char tecla = 1;
    unsigned char value = 0xFF; 
    while(tecla){
        Row_4 = 1;
        if (Col_4 == 1) {
            value = 13; // D
            tecla = 0;
        } // D 
        else if (Col_3 == 1){
            value = 14; 
            tecla = 0;
        } // E
        else if (Col_2 == 1){
            value = 0; 
            tecla = 0;
        } // 0 
        else if (Col_1 == 1)  {
            value = 15; 
            tecla = 0;
        }// F 
        Row_4 = 0;
        Row_3 = 1;
        if (Col_4 == 1)  {
            value = 12; 
            tecla = 0;
        }// C
        else if (Col_3 == 1) {
            value = 9; 
            tecla = 0;
        } // 9 
        else if (Col_2 == 1) {
            value = 8; 
            tecla = 0;
        }// 8
        else if (Col_1 == 1) {
            value = 7; 
            tecla = 0;
        } // 7 
        Row_3 = 0;
        Row_2 = 1;
        if (Col_4 == 1) {
            value = 11; 
            tecla = 0;
        } // B
        else if (Col_3 == 1) {
            value = 6;
            tecla = 0;
        } // 6 
        else if (Col_2 == 1) {
            value = 5; 
            tecla = 0;
        } // 5
        else if (Col_1 == 1) {
            value = 4; 
            tecla = 0;
        }// 4 
        Row_2 = 0;
        Row_1= 1;
        if (Col_4 == 1)  {
            value = 10;
            tecla = 0;
        }// A
        else if (Col_3 == 1) {
            value = 3; 
            tecla = 0;
        }// 3
        else if (Col_2 == 1) {
            value = 2; 
            tecla = 0;
        }// 2
        else if (Col_1 == 1)  {
            value = 1; 
            tecla = 0;
        } // 1
        Row_1 = 0;
    }
    return value;
}
