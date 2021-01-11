#ifndef MOTOR_H
#define MOTOR_H
#include <Servo.h>
#include <Arduino.h>
// A function for the setup loop, configures pins
extern void motorSetup();
extern void Left();
extern void Right();
extern void Forwards();
extern void Backwards();
extern void Stop();
extern void Move_Servo(int pos);
#endif
