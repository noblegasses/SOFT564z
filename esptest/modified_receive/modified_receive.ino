#include "Motor.h"
#include <Wire.h>

void setup()
{
  Wire.begin(0x5);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  motorSetup();
  Serial.begin(115200);           // start serial for output
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  int pos =0;
  char buff[4];
  byte idx = 0;
  while(Wire.available()&&idx<4){
     buff[idx++] = Wire.read(); // receive byte as a character
  }
  for(int i=0;i<sizeof(buff);i++){
   Serial.print(buff[i]);
   if (i== 0) {
  switch  (buff[i]){
    case ('F'):
     Forwards();
    break;
    case ('B'):
     Backwards();
    break;
    case('L'):
     Left();
    break;
    case('S'):
     Stop();
    break;
    //if unexpected value then error on LCD
    default:
     Stop();
     char message[]="Invalid Direction Character";
   }
  }
 if (i >= 1){
   pos = pos + (buff[i]-'0')*pow(10,3-i);
  }
 }
 Move_Servo(pos);
  Serial.print('\n');
}
