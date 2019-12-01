// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

// Brancher un haut-parleur piezo entre la broche 9 et le GND :
#define TONE_PIN 9

// Créer un objet Chrono :
Chrono updateTone; 

int hz = 30;

void setup() {
 
}

void loop() {
  
  if ( updateTone.hasPassed(2) ) {
     updateTone.restart();
     hz = hz + 10;
     if ( hz > 5000) hz = 30;
     tone(TONE_PIN , hz);
  }
}
