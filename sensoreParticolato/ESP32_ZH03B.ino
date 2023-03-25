#include <HardwareSerial.h>

// Create a serial object for communicating with the sensor
HardwareSerial sensorSerial(2); // Use Serial2 (pins 16 and 17)


// Set up the sensor
void setup() {
  // Start the serial communication with the sensor
  sensorSerial.begin(9600);
  sensorSerial.begin(9600, SERIAL_8N1, 16, 17); // begin communication at 9600 baud using pins 16 and 17
  
  // Send the sensor initialization command
  sensorSerial.write(0x42);
  sensorSerial.write(0x4D);
  sensorSerial.write(0xE1);
  sensorSerial.write(0x00);
}

// Read the sensor data
void loop() {
  // Wait for data to be available
  while (sensorSerial.available() < 8) {
    delay(10);
  }

  // Read the data
  byte data[8];
  for (int i = 0; i < 8; i++) {
    data[i] = sensorSerial.read();
  }

  // Calculate the PM2.5 and PM10 concentrations
  float pm25 = (data[3] * 256 + data[2]) / 10.0;
  float pm10 = (data[7] * 256 + data[6]) / 10.0;
  float pm100 = (data[5] * 256 + data[4]) / 10.0;

  // Print the concentrations to the serial monitor
  Serial.print("PM2.5: ");
  Serial.print(pm25);
  Serial.print(" ug/m3");
  Serial.print("   PM1: ");
  Serial.print(pm10);
  Serial.println(" ug/m3");
  Serial.print("   PM10   ");
  Serial.print(pm100);
  Serial.println(" ug/m3");

  // Wait for 1 second before reading again
  delay(10000);
}
