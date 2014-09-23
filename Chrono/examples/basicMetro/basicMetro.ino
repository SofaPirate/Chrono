// INCLUDE CHRONO LIBRARY
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip

// Instanciate a Chrono object.
Chrono myChrono; 

void setup() {
}

void loop() {
  // Use Chrono as a metronome with an interval of 1000 ms : 
  if (myChrono.metro(1000) ) { // metro(1000) returns 1 everytime an interval of 1000 is passed.
    // Do something here...
  }
}
