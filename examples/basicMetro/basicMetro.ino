// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

// Instanciate a Chrono object.
Chrono myChrono; 

void setup() {
}

void loop() {
  // Use Chrono as a metronome with an interval of 1000 ms : 
  if (myChrono.hasPassed(1000) ) { // elapsed(1000) returns 1 if 1000ms have passed.
    myChrono.restart();  // restart the Chrono 
    // Do something here...
  }
}
