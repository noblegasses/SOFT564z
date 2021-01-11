#include <Wire.h>
int board = 0x5;
void setup() {
  Wire.begin();
Serial.begin(115200);

}
char message1[5]={'F','0','9','0','\0'};
char message2[5]={'S','0','0','0','\0'};
char message3[5]={'B','1','8','0','\0'};
void loop() {
 Serial.println(message1);
 Wire.beginTransmission(board);
 Wire.write(message1);
 Wire.endTransmission();
 delay(3000);

 Serial.println(message2);
 Wire.beginTransmission(board);
 Wire.write(message2);
 Wire.endTransmission();
 delay(3000);

 Serial.println(message3);
 Wire.beginTransmission(board);
 Wire.write(message3);
 Wire.endTransmission();
 delay(3000);

 Serial.println(message2);
 Wire.beginTransmission(board);
 Wire.write(message2);
 Wire.endTransmission();
 delay(3000);
}
