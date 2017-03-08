// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

// Brancher un haut-parleur piezo entre la broche 9 et le GND :
#define TONE_PIN 13

// Créer un objet Chrono :
Chrono updateTone; 

void setup() {
  
  // Essayer de créer un random seed :
  randomSeed( analogRead(0) + analogRead(1) + analogRead(2) + analogRead(3) + analogRead(4) + analogRead(5) );
  
}

void loop() {
  
  if ( updateTone.hasPassed(100) ) {
	updateTone.restart();
	
     int hz = random(30,11000);
     tone(TONE_PIN , hz);
  }
}
