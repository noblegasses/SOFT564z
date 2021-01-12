#include"I2C_Comms.h"
LiquidCrystal_I2C lcd(0x27,16,2);//set up the LCD as a 16 char,2 line device at I2C address 0x27

void I2CSetup(int ardAddr, int IMUAddr){
//setup arduino as I2C device
 Wire.begin(ardAddr);//set up arduino as I2C device with input address
 sensorSetup(IMUAddr);//set up sensors with IMU at input address
 motorSetup();//set up motor pins
 Wire.onReceive(receiveData);//attach receiveData handler to the receive data I2C event
 Wire.onRequest(sendData);//attach sendData handler to the data request I2C event
 //initialize LCD
 lcd.init();
 lcd.init();
 lcd.backlight();
 lcd.clear();
}


void sendData(){
 for (int i=0;i<sizeof(dataArray)/2;i++){
 int  tempval = dataArray[i];
 byte msb = tempval>>8;
 byte lsb = tempval & 0x00FF;
 Wire.write(msb);
 Wire.write(lsb);
 }
 
 //Wire.write((uint8_t*)dataArray,sizeof(dataArray));
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
    case('R'):
     Right();
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
