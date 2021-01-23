#include "Distance_Sensor.h"
const int echo = 5;//set the echo pin of the sensor to be PWM pin digital 5
const int trigger = 6;//set the trigger pin of the sensor to be pin digital 6 
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
  int distance = (duration * 0.343) / 2;
  return distance;
}
