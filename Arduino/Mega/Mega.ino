//a library for wired communication, in this case I2C
#include "I2C_comms.h"
int read_ultrasonic();
int read_encoder();
void setup() {
I2CSetup(0x5,0x68);
}

void loop() {
}
