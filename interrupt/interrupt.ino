#include "definitions.h"
#include "command.h"
#include "changeCommand.h"
#include "readCommand.h"
#include "setupTimer2.h"


struct Command command =
{
        PREAMBLE,           // preamble part 2
        SEPARATOR,          // -- Separating bit --
        BLANK_BYTE_ONE,     // Engine Number
        SEPARATOR,          // -- Separating bit --
        BLANK_BYTE_TWO,     // byteTwo
        SEPARATOR,          // -- Separating bit --
        command.byteOne ^ command.byteTwo,  // Checksum
        END_OF_MESSAGE        // --- End of message bit ---
};


unsigned char byteOne;
unsigned char byteTwo;

//  - TODO -  Ask Asger about this -

struct Command *commandPointer = &command;
unsigned char *byteOnePointer = &byteOne;
unsigned char *byteTwoPointer = &byteTwo;


void setup()
{
    Serial.begin(9600);
    pinMode(DCC_PIN,OUTPUT);              // pin 4 this is for the DCC Signal
    pinMode(LED_BUILTIN,OUTPUT);               // pin 13 the onboard LED
    //setupTimer2();
    delay(100);
}

void loop()
{

    byteOne = 50; 
    byteTwo = SPEED1;
    
    // TODO -- Ask Asger --
    readCommand(&command, "PRE");

    
    // readCommand(commandPointer, "PRE");
    // changeCommand(commandPointer, byteOne, byteTwo);
    changeCommand(&command, byteOne, byteTwo);
    delay(500);
    
    byteOne = 60; 
    byteTwo = SPEED6;

    readCommand(&command, "POST");
    changeCommand(&command, byteOne, byteTwo);

    
    delay(500);

    Serial.print("timer is: ");
    Serial.print(TCNT2);
    Serial.println();

    delay(500);
}
