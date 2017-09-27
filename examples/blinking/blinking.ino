/*
 This code will toggle pin 13 on and off every second (1000 ms).
 This should be the debug LED's pin. So the debug LED should
 blink every second.
 */

// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

// Set the led's pin
int ledPin =  13; 

//Create a variable to hold the led's state
int ledState = HIGH;

// Instanciate a Chrono object.
Chrono ledChrono; 

void setup()
{
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,ledState);
}

void loop()
{

  if (ledChrono.hasPassed(1000) ) { // returns true if it passed 1000 ms since it was started
    ledChrono.restart();  // restart the crono so that it triggers again later
    
    // toggle the stored state
    if (ledState==HIGH)  ledState=LOW;
    else ledState=HIGH;
    
    // write the state to the pin
    digitalWrite(ledPin,ledState);
  }
}

