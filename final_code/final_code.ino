#include <Stepper.h>  // Include the stepper motor library

// Pin Definitions for Stepper Motor
const int stepsPerRevolution = 2048; // Number of steps per revolution
Stepper myStepper(stepsPerRevolution, 23, 22, 21, 19); // Initialize Stepper on pins 23, 22, 21, and 19

// Pin Definitions for Sensors
const int pHpin = 32; // GPIO pin to read analog value from pH sensor
const int turbidityPin = 34; // GPIO pin to read analog value from turbidity sensor

// Calibration values for pH sensor
float voltageOffset = 2.5; // Voltage at pH 7.0
float calibrationSlope = -5.70; // Calibration slope for pH calculation

// Calibration values for turbidity sensor
const float Vclear = 2.5; // Voltage for clear water
const float Vmax = 4.5; // Maximum sensor voltage for highly turbid water
const float Vmin = 0.5; // Minimum sensor voltage for very clear water

// NTU calculation coefficients (example, adjust based on sensor specs)
const float a = -1120.4;
const float b = 5742.3;
const float c = -4353.8;

// Manual position tracking for the stepper motor
int stepperPosition = 0; // Initial position

void setup() {
  Serial.begin(115200); // Initialize serial communication
  myStepper.setSpeed(10); // Set the speed of the stepper motor
}

void loop() {
  // Stepper Motor Rotation
  myStepper.step(stepsPerRevolution); // Rotate one full revolution
  stepperPosition += stepsPerRevolution; // Update position
  
  delay(15000); // Wait for 15 seconds before the next rotation

  // Read and Print pH Sensor Data
  int pHSensorValue = analogRead(pHpin); // Read pH sensor value
  float pHVoltage = pHSensorValue * (3.3 / 4095.0); // Convert to voltage
  float pHValue = 7 + ((pHVoltage - voltageOffset) * calibrationSlope); // Calculate pH value

  // Read and Print Turbidity Sensor Data
  int turbiditySensorValue = analogRead(turbidityPin); // Read turbidity sensor value
  float turbidityVoltage = turbiditySensorValue * (3.3 / 4095.0); // Convert to voltage
  float turbidityNTU;
  if (turbidityVoltage < Vclear) {
    turbidityNTU = a * (turbidityVoltage * turbidityVoltage) + b * turbidityVoltage + c;
  } else {
    turbidityNTU = 3000; // High turbidity, beyond sensor range
  }

  // Print pH and Turbidity Data
  Serial.print("Voltage (pH): ");
  Serial.print(pHVoltage, 2);  // Print pH voltage
  Serial.print(" V, pH: ");
  Serial.print(pHValue, 2);    // Print pH value
  Serial.print(" pH, ");

  Serial.print("Voltage (Turbidity): ");
  Serial.print(turbidityVoltage, 2);  // Print turbidity voltage
  Serial.print(" V, Turbidity: ");
  Serial.print(turbidityNTU, 2);      // Print NTU value
  Serial.print(" NTU, ");

  // Print Stepper Position
  Serial.print("StepperPos: ");
  Serial.println(stepperPosition);

  delay(2000); // Delay between sensor readings
}
