#include"I2C_Comms.h"
LiquidCrystal_I2C lcd(0x27,16,2);

void I2CSetup(int ardAddr, int IMUAddr){
//setup arduino as I2C device
 Wire.begin(ardAddr);
 sensorSetup(IMUAddr);
 motorSetup();
 Wire.onReceive(receiveData);
 Wire.onRequest(sendData);
 lcd.init();
 lcd.init();
 lcd.backlight();
 lcd.clear();
}


void sendData(){
sensorRead();
Wire.write((uint8_t*)dataArray,sizeof(dataArray));
}


void receiveData(int howMany){
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
