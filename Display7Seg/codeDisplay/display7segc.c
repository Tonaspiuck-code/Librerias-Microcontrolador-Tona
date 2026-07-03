#include "display7segc.h"


unsigned char getValue(unsigned char n){
    switch(n){
        case 0: case '0':            return 0b11111100;
        case 1: case '1':            return 0b01100000;
        case 2: case '2':            return 0b11011010;
        case 3: case '3':            return 0b11110010;
        case 4: case '4':            return 0b01100110;
        case 5: case '5':            return 0b10110110;
        case 6: case '6':            return 0b10111110;
        case 7: case '7':            return 0b11100000;
        case 8: case '8':            return 0b11111110;
        case 9: case '9':            return 0b11110110;
        case 10: case 'A': case 'a': return 0xEE;
        case 11: case 'B': case 'b': return 0x3E;
        case 12: case 'C': case 'c': return 0x9C;
        case 13: case 'D': case 'd': return 0x7A;
        case 14: case 'E': case 'e': return 0x9E;
        case 15: case 'F': case 'f': return 0x8E;
        case 'G':                    return 0xBE;
        case 'g':                    return 0xF6;
        case 'H': case 'h':          return 0x6E;
        case 'I':                    return 0x0C;
        case 'i':                    return 0x08;
        case 'J': case 'j':          return 0x78;
        case 'L': case 'l':          return 0x1C;
        case 'N':                    return 0xEC;
        case 'n':                    return 0x2A;
        case 'O':                    return 0xFC;
        case 'o':                    return 0x3A;
        case 'P': case 'p':          return 0xCE;
        case 'Q': case 'q':          return 0xE6;
        case 'R':                    return 0xCC;
        case 'r':                    return 0xCC;
        case 'S': case 's':          return 0xB6;
        case 'T': case 't':          return 0x1E;
        case 'U':                    return 0x7C;
        case 'u':                    return 0x38;
        case 'Y': case 'y':          return 0x76;
        case 'Z': case 'z':          return 0xDA;
      
        default: return 0x00;
    }
}