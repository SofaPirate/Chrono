/*
 This code will blink an LED attached to pin 13 on and off. 
 */

// INCLUDE CHRONO LIBRARY
#include <Chrono.h>
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip


#define LED 13 // Define the led's pin

//Create a variable to hold theled's current state
int state = HIGH;

// Instanciate a Chrono object.
Chrono ledMetro; 

void setup()
{
  pinMode(LED,OUTPUT);
  digitalWrite(LED,state);
}

void loop()
{


  if (ledMetro.passed(20) ) { // elapsed(20) returns true if 20 ms have passed.
    ledMetro.restart();  // restart the Chrono 
    
    if (state==HIGH)  state=LOW;
    else state=HIGH;

    digitalWrite(LED,state);
  }
}

