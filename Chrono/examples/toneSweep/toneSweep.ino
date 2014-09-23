// INCLUDE CHRONO LIBRARY
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip
#include <Chrono.h>

// Brancher un haut-parleur piezo entre la broche 9 et le GND :
#define TONE_PIN 9

// Créer un objet Chrono :
Chrono updateTone; 

int hz = 30;

void setup() {
 
}

void loop() {
  
  if ( updateTone.metro(2) ) {
     hz = hz + 10;
     if ( hz > 5000) hz = 30;
     tone(TONE_PIN , hz);
  }
}
