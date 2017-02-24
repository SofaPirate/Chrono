#include <Chrono.h>

Chrono chrono;
boolean passedFirstPost = false;

void setup() {
  Serial.begin(57600);
  Serial.println("Restart with offset");
  chrono.restart(1000);
  printChrono();
}

void loop() {
  if (!passedFirstPost && chrono.passed(5000)) {
    Serial.println("Stop 5 sec");
    chrono.stop();
    printChrono();
    Serial.println("Add 2000 ms");
    chrono.add(2000);
    printChrono();
    Serial.println("Resume + wait 1000 ms");
    chrono.resume();
    chrono.delay(1000);
    printChrono();
    passedFirstPost = true;
  }
  else if (chrono.passed(10000)) {
    Serial.println("Stop 10 sec");
    chrono.stop();
    printChrono();
    Serial.println("Restart");
    chrono.restart();
    passedFirstPost = false;
  }
}

void printChrono() {
 Serial.print("Elapsed: "); Serial.print(chrono.elapsed()); Serial.print(" ms ("); Serial.print(chrono.isRunning() ? "RUNNING" : "STOPPED"); Serial.println(")");
}
