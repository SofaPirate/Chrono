
// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

#define BUTTON_PIN 2

Chrono myChrono;
int previousButtonState;

void setup() {

        // Demarrer la communication serie a  57600 baud.
        Serial.begin(57600);
        
        // Configurer la broche BUTTON_PIN en tant qu'entree
        // avec pull-up interne :
        pinMode(BUTTON_PIN,INPUT_PULLUP);
        
        previousButtonState = digitalRead(BUTTON_PIN);
}

void loop() {

        int newButtonState = digitalRead(BUTTON_PIN);
        if ( previousButtonState != newButtonState ) {
            previousButtonState = newButtonState;
                           
               if ( newButtonState == LOW && myChrono.hasPassed(10) ) {
                  Serial.print("ms "); 
                  Serial.print( myChrono.elapsed() ); 
                  Serial.println(); 
                  
               }
                 
                
            myChrono.restart();
        }
}

