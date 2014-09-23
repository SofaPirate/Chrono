/*
 This code will blink an LED attached to pin 13 on and off. 
 */
 
#include <Chrono.h> //Include Chrono library
#define LED 13 // Define the led's pin

//Create a variable to hold theled's current state
int state = HIGH;

// Instanciate a Chrono object.
Chrono ledMetro = Chrono(); 

void setup()
{
  pinMode(LED,OUTPUT);
  digitalWrite(LED,state);
}

void loop()
{

  // Use Chrono as a metronome with an interval of 1000 ms : 
  if (ledMetro.metro(1000) ) { // .metro(1000) returns 1 everytime an interval of 1000 is passed.
    if (state==HIGH)  state=LOW;
    else state=HIGH;
    
    digitalWrite(LED,state);
  }
}