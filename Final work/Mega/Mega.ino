//include headder files
#include "I2C_comms.h"
void setup() {
Serial.begin(115200);//begin serial terminal for debugging purposes
Serial.println("startup");
I2CSetup(0x5,0x68);//set up peripherals,0x5 is the arduino's I2c address
}

void loop() {
  sensorRead();//read the sensors, incase of I2C data request
  Serial.print("Distance is ");
  Serial.print(dataArray[0]);
  Serial.println("mm");
  Serial.print("Water level is ");
  Serial.print(dataArray[1]);
  Serial.println("mm");
  Move_motors();
}
