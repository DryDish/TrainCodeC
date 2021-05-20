#ifndef TRAIN_CODE_C_DEFINITIONS
#define TRAIN_CODE_C_DEFINITIONS

// These externs fix the missing declaration errors
// It essentially promises the compiler that they are/will be filled soon
// WIP do not use yet

/*
unsigned char TIMSK2;
unsigned char TCCR2A;
unsigned char TCCR2B;
unsigned char TOIE2;
unsigned char TCNT2;

*/

// For the interrupts
#define TIMER_SHORT 0x8D               // 58usec pulse length 141 255-141=114
#define TIMER_LONG  0x1B               // 116usec pulse length 27 255-27 =228

// Static variables
#define DCC_PIN 4


#define BLANK_PREAMBLE 0x0000
#define BLANK_BYTE_ONE 0
#define BLANK_BYTE_TWO 0
#define PREAMBLE 0xFFFF
#define SEPARATOR 0
#define END_OF_MESSAGE 1

// Speed
#define SPEED0 0x60
#define HARDSTOP 0x61
#define SPEED1 0x62
#define SPEED2 0x63
#define SPEED3 0x64
#define SPEED4 0x65
#define SPEED5 0x66
#define SPEED6 0x67
#define SPEED7 0x68
#define SPEED8 0x69
#define SPEED9 0x6A
#define SPEED10 0x6B
#define SPEED11 0x6C
#define SPEED12 0x6D
#define SPEED13 0x6E
#define SPEED14 0x6F


#endif // TRAIN_CODE_C_DEFINITIONS




