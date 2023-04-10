#include "PMS.h"
#include <HardwareSerial.h>
#include <Wire.h>
 
PMS pms(Serial2);
PMS::DATA data;
 
float val1;
float val2;
float val3;

void setup() {
  if(pms.begin()) {
    Serial.begin(9600);
    Serial2.begin(9600);
    delay(2000);
  } else {
    Serial.println("PMS5003 non rilevato!");
  }
}

void loop() {
  if (pms.read(data)) {
    val1 = data.PM_AE_UG_1_0;
    val2 = data.PM_AE_UG_2_5;
    val3 = data.PM_AE_UG_10_0;
 
    Serial.println("Air Quality Monitor");
 
    Serial.println("PM1.0 :"); Serial.println(val1); Serial.println("(ug/m3)");
 
    Serial.println("PM2.5 :"); Serial.println(val2); Serial.println("(ug/m3)");
 
    Serial.println("PM10 :"); Serial.println(val3); Serial.println("(ug/m3)");
 
    Serial.println("");
  }
}
