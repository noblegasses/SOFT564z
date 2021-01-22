#include <Wire.h>
int outData[]={40,300};
char buff[4]={'S','0','0','0'};
void sendData(){
 for (int i=0;i<sizeof(outData)/2;i++){
 int  tempval = outData[i];
 byte msb = tempval>>8;
 byte lsb = tempval & 0x00FF;
 Wire.write(msb);
 Wire.write(lsb);
 }
 /*Serial.print("Sending: ");
 for (int i=0;i<sizeof(outData)/2;i++){
  Serial.print(outData[i]);
 }
 Serial.println();*/
}


void receiveData(int howMany){
  int pos =0;
  int idx = 0;
  while(Wire.available()&&idx<4){
     buff[idx++] = Wire.read(); // receive byte as a character
  }
}
void setup() {
 Serial.begin(115200);
 Wire.begin(0x5);
 Wire.onReceive(receiveData);
 Wire.onRequest(sendData);
}

void loop() {

Serial.print("Receiving: ");
Serial.print(buff);
Serial.print('\n');
delay(100);
}
