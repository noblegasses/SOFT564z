#include "LED.h"
void setup() {
 LEDSetup();
}

void loop() {
  WIFI_CONNECTED();
  delay(500);
  WIFI_DISCONNECTED();
  WIFI_AP_CONNECTED();
  delay(500);
  WIFI_AP_DISCONNECTED();
  CLIENT_CONNECTED();
  delay(500);
  CLIENT_DISCONNECTED();
  BAD_DATA();
  delay(500);
  DATA_CLEARED();
  BLUETOOTH_CONNECTED();
  delay(500);
  BLUETOOTH_DISCONNECTED();
}
