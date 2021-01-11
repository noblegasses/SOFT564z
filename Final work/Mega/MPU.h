#ifndef MPU_H
#define MPU_H
#include <Wire.h>
#include <Arduino.h>
/*The following  code is adapted from the arduino MPU6050 example code
seen here: */
//a small function to disable the sleep and start the IMU measuring
extern void IMU_Setup(int addr);
//get the information from the IMU
extern void IMU_Read(float *dataout);
#endif
