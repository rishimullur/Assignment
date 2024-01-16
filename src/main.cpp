#include <Arduino.h>

const int analogInPin = 35;  // D7 is mapped to pin 35 on ESP32
float calibrationFactor = 1.0; 

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(analogInPin);

  // Apply calibration factor
  float calibratedValue = sensorValue * calibrationFactor;

  // Convert ADC value to voltage
  float voltage = (calibratedValue / 4095.0) * 3.3;

  Serial.print("ADC Value: ");
  Serial.print(sensorValue);
  Serial.print(", Calibrated Value: ");
  Serial.print(calibratedValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);

  delay(1000);  // Delay for 1 second before reading again
}
