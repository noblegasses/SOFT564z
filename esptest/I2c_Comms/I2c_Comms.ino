#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
 Wire.begin();
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
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("hello_world");
 lcd.setCursor(0,1);
 lcd.print("ESP32 to LCD");
 Serial.print("Transmitting... \r\n");
 Wire.beginTransmission(5);
 Wire.write("ESP32 to Arduino");
 Wire.endTransmission();
 delay(3000);
}
