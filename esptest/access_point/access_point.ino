#include <WiFi.h>
const char* ssid = "espWiFi";
const char* pswd = "Printing";
void setup() {
  // put your setup code here, to run once:
 WiFi.softAP(ssid, pswd);
}

void loop() {
}
