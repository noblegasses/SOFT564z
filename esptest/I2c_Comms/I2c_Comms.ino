#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void receiveEvent();
void setup() {
  // put your setup code here, to run once:
 Wire.begin(5);
 Wire.onReceive(receiveEvent);
 lcd.init();
 lcd.init();
 lcd.backlight();
 lcd.clear();
 delay(100);
 Serial.begin(115200);
 Serial.print("setup");
}
void loop() {
  // put your main code here, to run repeatedly:
 //lcd.clear();
 //lcd.setCursor(0,0);
 //lcd.print("hello_world");
 //lcd.setCursor(0,1);
 //lcd.print("Arduino to LCD");
 delay(3000);
}
void receiveEvent(int howMany){
  while(0 < Wire.available()){
   char c = Wire.read();
   Serial.print(c); 
  }
}
