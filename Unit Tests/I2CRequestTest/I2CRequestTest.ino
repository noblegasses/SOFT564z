#include <Wire.h>
void setup() {
 Wire.begin();
 Serial.begin(115200);
 }

void loop() {
  //request 2 floats(4 bits each) from follower
  Wire.requestFrom(0x5,4*2, true);
  float sensors[2];
  byte idx =0;
  while(Wire.available()&&idx<sizeof(sensors)){
   sensors[idx++] = Wire.read();
 }
 Serial.print ("Distance is:");
 Serial.print(sensors[0]);
 Serial.print(" | Water level is: ");
 Serial.println(sensors[1]);
 delay(500);
}
