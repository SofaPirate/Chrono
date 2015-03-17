/*
Cet exemple mesure le temps entre deux pressions sur un interrupteur.
*/

// INCLUDE CHRONO LIBRARY
#include <Chrono.h>
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip


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
                           
               if ( newButtonState == LOW && myChrono.passed(10) ) {
                  Serial.print("ms "); 
                  Serial.print( myChrono.elapsed() ); 
                  Serial.println(); 
                  
                  
               }
                 
            myChrono.restart();
        }
}

