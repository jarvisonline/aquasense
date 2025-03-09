// Pin Definitions
const int pHpin = 32;  // GPIO pin to read analog value from PO pin (changed to GPIO 32)

// Calibration values (adjust based on your calibration)
float voltageOffset = 2.5;  // Example voltage at pH 7.0 (adjust based on calibration)
float calibrationSlope = -5.7; // Example calibration slope (adjust based on calibration)

void setup() {
  Serial.begin(115200);  // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(pHpin);  // Read the analog value from the pH sensor
  float voltage = sensorValue * (3.3 / 4095.0);  // Convert analog value to voltage (12-bit ADC)

  // Calculate pH value from voltage (using calibration)
  float pHValue = 7 + ((voltage - voltageOffset) * calibrationSlope);

  // Print voltage and pH values
  Serial.print("Voltage: ");
  Serial.print(voltage, 2);  // Print voltage with 2 decimal places
  Serial.print(" V, pH: ");
  Serial.print(pHValue, 2);  // Print pH with 2 decimal places
  Serial.println();

  delay(2000);  // Wait for 2 seconds before the next reading
}
