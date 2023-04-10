#include <Wire.h>
#include <BH1750.h>

BH1750 bh1750;

void setup(){
  Serial.begin(9600);

  bool bh1750Status;
  bh1750Status = bh1750.begin();  
  if (!bh1750Status) {
    Serial.println("BME280 non è stato rilevato!");
  } else {
    Wire.begin();
    bh1750.begin();
    Serial.println(F("BH1750 rilevato"));
  }  
}

void loop() {
  float lux = bh1750.readLightLevel();
  if(lux <= 1) {
    Serial.println("Notte!");
  } else if(lux < 2500) {
    Serial.println("Nuvoloso!");
  } else {
    Serial.println("Sereno!");
  }
  delay(1000);
}
