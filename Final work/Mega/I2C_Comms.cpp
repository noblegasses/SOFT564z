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
}


void receiveData(int howMany){
  byte idx = 0;
  while(Wire.available()&&idx<4){
     MotorMove[idx++] = Wire.read(); // receive byte as a character
  }
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
