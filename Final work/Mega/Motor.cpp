#include "Motor.h"
//initalize channel A motor, brake, and throttle pins 
const int AMot = 12;
const int ABra = 9;
const int AThrot =3;
//initalize channel B motor, brake, and throttle pins
const int BMot =13;
const int BBra =8;
const int BThrot = 11;
//initalize servo control
Servo sensorArm;
int servoPin = 10;
void motorSetup(){
 pinMode(AMot, OUTPUT);
 pinMode(ABra, OUTPUT); 
 pinMode(BMot, OUTPUT);
 pinMode(BBra, OUTPUT); 
 sensorArm.attach(servoPin);
}
void Left(){
 digitalWrite(AMot,HIGH);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,255);
 digitalWrite(BMot,HIGH);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,255);
}
void Right(){
 digitalWrite(AMot,LOW);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,255);
 digitalWrite(BMot,HIGH);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,255);
}
void Forwards(){
 digitalWrite(AMot,HIGH);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,255);
 digitalWrite(BMot,LOW);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,255);
}
void Backwards(){
 digitalWrite(AMot,LOW);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,255);
 digitalWrite(BMot,HIGH);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,255);
}
void Stop(){
 digitalWrite(AMot,LOW);
 digitalWrite(ABra,HIGH);
 analogWrite(AThrot,0);
 digitalWrite(BMot,LOW);
 digitalWrite(BBra,HIGH);
 analogWrite(BThrot,0);  
}
void Move_Servo(int pos){
 sensorArm.write(pos); 
}
