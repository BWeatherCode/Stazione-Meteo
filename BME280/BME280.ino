#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme; // I2C

unsigned long delayTime;

void setup() {
  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  bool bme280Status;
  bme280Status = bme.begin(0x76);  
  if (!bme280Status) {
    Serial.println("BME280 non è stato rilevato!");
  } else {
    Serial.println("-- BME280 Rilevato! --");
    delayTime = 1000;

    Serial.println();
  }
}


void loop() { 
  bme280Values();
  delay(delayTime);
}

void bme280Values() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}
