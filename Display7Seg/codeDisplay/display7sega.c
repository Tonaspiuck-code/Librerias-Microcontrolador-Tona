#include "display7sega.h"


unsigned char getValue(unsigned char n){
    switch(n){
        case 0: case '0':            return 0b00000011;
        case 1: case '1':            return 0b10011111;
        case 2: case '2':            return 0b00100101;
        case 3: case '3':            return 0b00001101;
        case 4: case '4':            return 0b10011001;
        case 5: case '5':            return 0b01001001;
        case 6: case '6':            return 0b01000001;
        case 7: case '7':            return 0b00011111;
        case 8: case '8':            return 0b00000001;
        case 9: case '9':            return 0b00001001;
        case 10: case 'A': case 'a': return 0x11;
        case 11: case 'B': case 'b': return 0xC1;
        case 12: case 'C': case 'c': return 0x63;
        case 13: case 'D': case 'd': return 0x85;
        case 14: case 'E': case 'e': return 0x61;
        case 15: case 'F': case 'f': return 0x71;
        case 'G':                    return 0x41;
        case 'g':                    return 0x09;
        case 'H': case 'h':          return 0x91;
        case 'I':                    return 0xF3;
        case 'i':                    return 0xF7;
        case 'J': case 'j':          return 0x87;
        case 'L': case 'l':          return 0xE3;
        case 'N':                    return 0x13;
        case 'n':                    return 0xD5;
        case 'O':                    return 0x03;
        case 'o':                    return 0xC5;
        case 'P': case 'p':          return 0x31;
        case 'Q': case 'q':          return 0x19;
        case 'R':                    return 0x33;
        case 'r':                    return 0x33;
        case 'S': case 's':          return 0x49;
        case 'T': case 't':          return 0xE1;
        case 'U':                    return 0x83;
        case 'u':                    return 0xC7;
        case 'Y': case 'y':          return 0x89;
        case 'Z': case 'z':          return 0x25;
      
        default: return 0xFF;
    }
}