#include <Wire.h>
void receiveEvent();
void setup() {
  // put your setup code here, to run once:
 Wire.begin(1);
 Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
Wire.beginTransmission(0x5);
Wire.write("ESP to Arduino");
Wire.endTransmission(); 
Serial.print("transmitting.../r/n");
delay(1000);
}
