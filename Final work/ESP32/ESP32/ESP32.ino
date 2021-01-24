#include "WIFI_Socketing.h"
#include "I2C_Leader.h"
#include "LED.h"
#include "Bluetoothstuff.h"
//If I had a switch, it would use a switch, but instead this pin will be pulled low or High depending on mode
int ModePin =34;
void setup() {
 I2CSetup();
 LEDSetup();
 WiFiSetup();
 BTSetup("ESP32");
 pinMode(ModePin, INPUT);
 //Serial.begin (115200);
}

void loop() {
 if (analogRead(ModePin)){
  WiFiMode();
 }
 else{
  BTMode();
  }
}
