#include"Water_Sensor.h"
const int Water_pin = A1;
void waterSetup(){
 pinMode(Water_pin, INPUT);
}
int waterRead(){
 int level = analogRead(Water_pin);
 if (level>=200){
  level= map(level,200,360,0,40);
 }
 else{
   level=0;
 }
return level;  
}
