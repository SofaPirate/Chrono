
// INCLUDE CHRONO LIBRARY
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip
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
            
            unsigned long elapsed = myChrono.get();
               
               if ( newButtonState == LOW && elapsed > 10 ) {
                  Serial.print("ms "); 
                  Serial.print( elapsed ); 
                  Serial.println(); 
                  
                  
               }
                 
                
            myChrono.restart();
        }
}

