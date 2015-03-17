// INCLUDE CHRONO LIBRARY
#include <Chrono.h>
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip


// Instanciate a Chrono object.
Chrono myChrono; 

void setup() {
}

void loop() {
  // Use Chrono as a metronome with an interval of 1000 ms : 
  if (myChrono.passed(1000) ) { // elapsed(1000) returns 1 if 1000ms have passed.
    myChrono.restart();  // restart the Chrono 
    // Do something here...
  }
}
