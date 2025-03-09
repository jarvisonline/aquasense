#include <Stepper.h>  // Include the stepper motor library

const int stepsPerRevolution = 2048;  // From your motor data sheet, number of steps per revolution

// Initialize the stepper library on pins 23, 22, 21, and 19
Stepper myStepper(stepsPerRevolution, 23, 22, 21, 19);

void setup() {
  myStepper.setSpeed(10);  // Set the speed at 10 rpm
}

void loop() {
  myStepper.step(stepsPerRevolution);  // 146 steps is 1/14th of a full rotation. Since we have 14 wells, this will index the feeder one space.

  // Turn the motor off when not in use to preserve energy and prevent it from heating up
  digitalWrite(23, LOW);
  digitalWrite(22, LOW);
  digitalWrite(21, LOW);
  digitalWrite(19, LOW);

  delay(15000);  // Pause for 15 seconds before the next rotation
}
