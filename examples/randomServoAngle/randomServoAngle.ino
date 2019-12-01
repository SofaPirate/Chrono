// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

// Instanciate a Chrono object.
Chrono myChrono; 

// INCLUDE SERVO LIBRARY.
#include <Servo.h> 

// INSTANTION A SERVO OBJECT.
Servo myServo; 

void setup() {
   // ATTACH THE SERVO TO PIN 9
  myServo.attach(9);
}

void loop() {
  // Use Chrono as a metronome with an interval of 1000 ms : 
  if (myChrono.hasPassed(1000) ) { // elapsed(1000) returns 1 (true) if 1000 ms have passed.
    myChrono.restart();  // restart the Chrono 

    int randomAngle = random(0,180);
    myServo.write(randomAngle);

    // ALTERNATIVE: USE MICROSECONDS FOR MORE PRECISION.
    // int randomUs = random(1500,2500);
    // myServo.writeMicroseconds(randomUs);
  }
}
