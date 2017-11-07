/*
  Controlling a servo position using a potentiometer (variable resistor).
  The Chrono library is used to wait till the servo gets to its position.
*/

// INCLUDE SERVO.
#include <Servo.h>

// INSTANTION A SERVO OBJECT.
Servo myServo;

// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h>

// Instanciate a Chrono object.
Chrono myChrono;

// Analog pin used to connect the potentiometer.
int potpin = A0;


void setup() {
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // THIS BLOCK OF CODE WILL RUN EVERY 15 MS. 
  if (myChrono.hasPassed(15) ) { // elapsed(15) returns 1 (true) if 15 ms have passed.
    myChrono.restart();  // restart the Chrono
    
    int val = analogRead(potpin);        // reads the value of the potentiometer (value between 0 and 1023)
    val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myServo.write(val);                  // sets the servo position according to the scaled value
  }

}
