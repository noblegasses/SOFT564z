//a library for wired communication, in this case I2C
#include "I2C_comms.h"
void setup() {
Serial.begin(115200);
I2CSetup(0x5,0x68);
Wire.onReceive(receiveData);
Wire.begin(0x5);


}

void loop() {
  delay(100);
}
