#include <Arduino.h>

#include <Chrono.h>

void setup() {
  
  Serial.begin(115200);
 
  // Following code loops for 5 seconds
  CHRONO_LOOP_FOR(5000) {
    Serial.println("Looping for 5 seconds...");
    delay(500);
  }

}

void loop() {
  
  CHRONO_ONCE_EVERY(2000) {
    Serial.println("This is printed every 2 seconds.");
  }
}

