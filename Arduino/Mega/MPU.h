#ifndef MPU_H
#define MPU_H
#include <Wire.h>
/*The following  code is adapted from the arduino MPU6050 example code
seen here:*/
float IMUData[7]={0.0,0.0,0.0,0.0,0.0,0.0,0.0]
//a small function to disable the sleep and start the IMU measuring
void IMU_Setup(int addr);
//get the information from the IMU
void IMU_Read(float *dataout);
#endif
