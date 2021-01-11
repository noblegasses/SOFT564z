#include"I2C_Comms.h"
LiquidCrystal_I2C lcd(0x27,16,2);

void I2CSetup(int ardAddr, int IMUAddr){
//setup arduino as I2C device
 Wire.begin(ardAddr);
 Wire.onReceive(receiveData);
 Wire.onRequest(sendData);
 lcd.init();
 lcd.init();
 lcd.backlight();
 lcd.clear();
 sensorSetup(IMUAddr);
 motorSetup();
}


void sendData(){
sensorRead();
Wire.write((uint8_t*)dataArray,sizeof(dataArray));
}


void receiveData(){
int pointer;
int pos = 0;
while(1<Wire.available()){
 char input = Wire.read();
 if (pointer== 0) {
  switch  (input){
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
     DisplayError(message);
  }
 }
 if (pointer >= 1){
   pos = pos + (input-'0')*pow(10,3-pointer);
 }
}
 Move_Servo(pos);
}


void UpdateLCD(char *line1, char *line2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
}

void DisplayError(char *error){
 lcd.clear();
 lcd.setCursor(0,0); 
 lcd.print("Error");
 lcd.setCursor(0,1);
 lcd.print(error);
}
