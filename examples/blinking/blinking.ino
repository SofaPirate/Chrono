/*
 This code will blink an LED attached to pin 13 on and off. 
 */

// INCLUDE CHRONO LIBRARY : http://github.com/thomasfredericks/Chrono
#include <Chrono.h> 

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


  if (ledMetro.hasPassed(20) ) { // returns true if 20 ms have passed.
    ledMetro.restart();  // restart the Chrono 
    
    if (state==HIGH)  state=LOW;
    else state=HIGH;

    digitalWrite(LED,state);
  }
}

