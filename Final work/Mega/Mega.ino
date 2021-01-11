//a library for wired communication, in this case I2C
#include "I2C_comms.h"
void setup() {
Serial.begin(115200);
motorSetup();
I2CSetup(0x5,0x68);
//Wire.begin(0x5);
//Wire.onReceive(receiveData);
}

void loop() {
  delay(100);
}
