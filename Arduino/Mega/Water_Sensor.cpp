#include"Water_Sensor.h"
const int Water_pin = A1;
void waterSetup(){
 pinMode(Water_pin, INPUT);
}
int waterRead(){
return analogRead(Water_pin);  
}
