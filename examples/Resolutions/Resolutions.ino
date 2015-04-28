#include <SuperChrono.h>

// Custom time function (just returns the number of times loop() was called).
unsigned long _loopCount = 0;
unsigned long loopTime() {
  return _loopCount;
}

SuperChrono millisChrono;
SuperChrono microsChrono(SuperChrono::MICROS);
SuperChrono secondsChrono(SuperChrono::SECONDS);
SuperChrono loopChrono(loopTime);

void setup() {
  Serial.begin(57600);
}

void loop() {
  // Output every second.
  if (secondsChrono.passed(1)) {
    Serial.println("PING!");
    Serial.print("Millis chrono: "); Serial.println(millisChrono.elapsed());
    Serial.print("Micros chrono: "); Serial.println(microsChrono.elapsed());
    Serial.print("Loop chrono: ");   Serial.println(loopChrono.elapsed());
    secondsChrono.restart();
  }
  _loopCount++;
}
