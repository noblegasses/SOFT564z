#include "Distance_Sensor.h"
const int echo = 0;//set the echo pin of the sensor to be PWM pin digital 0
const int trigger = 1;//set the trigger pin of the sensor to be pin digital 1 
void distanceSetup(){//set up the control and data pins of the distance sensor
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
}
int distanceRead(){
  int duration;
  //clear pin condition
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  //trigger the distance sensor to start measurement
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  //wait  for response
  //read the duration for pulse return
  duration = pulseIn(echo, HIGH);
  //calcuate distance in mm by dividing by the speed of sound in mm
  float distance = duration * 0.034 / 2;
  return distance;
}
