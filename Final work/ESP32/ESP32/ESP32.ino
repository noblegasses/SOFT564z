#include "WIFI_Socketing.h"
#include "I2C_Leader.h"
#include "LED.h"
void setup() {
 I2CSetup();
 LEDSetup();
 WiFiSetup();
 //Serial.begin (115200);
}

void loop() {
 WiFiMode();
}
