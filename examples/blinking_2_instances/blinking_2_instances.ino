// This code will blink output 13 every 250 ms
// abd will blink output 9 every 125 ms


// INCLUDE CHRONO LIBRARY : http://github.com/thomasfredericks/Chrono
#include <Chrono.h> 

#define LED_A 13 // Define a LED pin
#define LED_B 9 // Define another LED pin

// Create variables to hold the LED states
int stateA = HIGH;
int stateB = HIGH;

// Instantiate a Chrono object.
Chrono chronoA; 

// Instantiate another metro object and set the interval to 125 milliseconds (0.125 seconds).
Chrono chronoB = Chrono(); 

void setup()
{
  pinMode(LED_A,OUTPUT);
  digitalWrite(LED_A,stateA);
  
   pinMode(LED_B,OUTPUT);
  digitalWrite(LED_B,stateB);
  
}

void loop()
{
  // Use Chrono as a metronome with an interval of 250 ms : 
  if ( chronoA.hasPassed(250) ) {
    chronoA.restart();
    if (stateA==HIGH)  { 
      stateA=LOW;
    } else {
      stateA=HIGH;
    }
    digitalWrite(LED_A,stateA);
  }
  
  // Use Chrono as a metronome with an interval of 125 ms : 
   if ( chronoB.hasPassed(125) ) { 
    chronoB.restart();
    if (stateB==HIGH)  { 
      stateB=LOW;
    } else {
      stateB=HIGH;
    }
    digitalWrite(LED_B,stateB);
  }
  
  
}
