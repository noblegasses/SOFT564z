//the following code is tested yet unimplmenented, it is adapted from https://playground.arduino.cc/Main/MPU-6050/#short
#ifndef MPU_H
#define MPU_H
#include <Wire.h>
#include <Arduino.h>
//a small function to disable the sleep and start the IMU measuring
extern void IMU_Setup(int addr);
//get the information from the IMU
extern void IMU_Read(float *dataout);
#endif
