// Pin assignment
const int turbidityPin = 34; // Analog pin where OUT is connected

// Calibration values based on sensor and water quality standards
const float Vclear = 2.5;  // Voltage for clear water
const float Vmax = 4.5;    // Maximum sensor voltage for highly turbid water
const float Vmin = 0.5;    // Minimum sensor voltage for very clear water

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(turbidityPin); // Read analog value
  float voltage = sensorValue * (3.3 / 4095.0); // Convert analog reading to voltage (ESP32 is 12-bit ADC)
  
  // Calculate NTU from voltage
  float NTU;
  if (voltage < Vclear) {
    NTU = -1120.4 * (voltage * voltage) + 5742.3 * voltage - 4353.8;
  } else {
    NTU = 3000; // High turbidity, beyond sensor range
  }

  // Print voltage and NTU value
  Serial.print("Voltage: ");
  Serial.print(voltage, 2);  // Print voltage up to 2 decimal places
  Serial.print(" V, Turbidity: ");
  Serial.print(NTU, 2);      // Print NTU value up to 2 decimal places
  Serial.println(" NTU");

  delay(2000); // Delay 2 seconds between readings
}
