/*
Cet exemple mesure le temps entre deux pressions sur un unterrupteur.
*/

// INCLUDE CHRONO LIBRARY
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip
#include <Chrono.h> 

// L'interrupteur est branché à la broche 3 avec un pull-up externe :
#define BUTTON_PIN 3

Chrono myChrono;
int previousButtonState;

void setup() {

        // Demarrer la communication serie a  57600 baud.
        Serial.begin(57600);
        
        // Configurer la broche BUTTON_PIN en tant qu'entree
        pinMode(BUTTON_PIN,INPUT);
        
        previousButtonState = digitalRead(BUTTON_PIN);
}

void loop() {

        int newButtonState = digitalRead(BUTTON_PIN);
        
        if ( previousButtonState != newButtonState ) {
            previousButtonState = newButtonState;
            
            unsigned long elapsed = myChrono.get();
               
               if ( newButtonState == LOW && elapsed > 10 ) {
                  Serial.print("ms "); 
                  Serial.print( elapsed ); 
                  Serial.println(); 
                  
                  
               }
                 
            myChrono.restart();
        }
}

