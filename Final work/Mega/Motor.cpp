#include "Motor.h"
//Set the motor's speed by PWM value
int Speed=200; 
//initalize channel A motor, brake, and throttle pins 
const int AMot = 12;
const int ABra = 9;
const int AThrot =3;
//initalize channel B motor, brake, and throttle pins
const int BMot =13;
const int BBra =8;
const int BThrot = 11;
//initalize servo control
char MotorMove[4]={'S','2','5','5'};
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
 digitalWrite(AMot,LOW);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,Speed);
 digitalWrite(BMot,LOW);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,Speed);
}
void Right(){
 digitalWrite(AMot,HIGH);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,Speed);
 digitalWrite(BMot,HIGH);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,Speed);
}
void Backwards(){
 digitalWrite(AMot,HIGH);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,Speed);
 digitalWrite(BMot,LOW);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,Speed);
}
void Forwards(){
 digitalWrite(AMot,LOW);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,Speed);
 digitalWrite(BMot,HIGH);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,Speed);
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
void Move_motors(){
 int pos =0;
 for(int i=0;i<sizeof(MotorMove);i++){
  if (i== 0) {
   switch(MotorMove[i]){
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
   pos = pos + (MotorMove[i]-'0')*pow(10,3-i);
  }
 }
 Move_Servo(pos);
 //Serial.print('\n');
}
