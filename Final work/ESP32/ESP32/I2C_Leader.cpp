#include "I2C_Leader.h"
int boardAddr = 0x5;//the address of the follower device
void I2CSetup(){
  Wire.begin();
  }
void RequestSensors(){
  byte idx =0;
  Wire.requestFrom(0x5,4,true);
  while(Wire.available()&&idx<sizeof(dataArray)){
   dataArray[idx++] = Wire.read()<<8|Wire.read();;
  }
}
void SendMovement(){
 Wire.beginTransmission(boardAddr);
 for (int i = 0; i<4; i++){
  Wire.write(moveArray[i]);
 }
 Wire.endTransmission();
 Serial.print("sending movement: ");
 //for (int i = 0; i<sizeof(moveArray); i++){
 Serial.println(moveArray);
 //}
 //Serial.println();
}
