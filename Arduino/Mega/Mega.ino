//a library for wired communication, in this case I2C
#include <Wire.h>
void setup() {
 //give a hex address to the arduino to communicate
 Wire.begin(0x8);
 //attach functions for incoming communcations
 Wire.onReceive()
 Wire.onRequest()
}

void loop() {

}
