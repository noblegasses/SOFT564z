#ifndef I2C_COMMS_H
#define I2C_COMMS_H
#include "Data.h"
#include "Motor.h"
#include <Arduino.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
extern volatile int dataArray[2];
extern void I2CSetup(int ardAddr,int IMUAddr);
extern void sendData();
extern void receiveData(int howMany);
extern void UpdateLCD(char *line1, char *line2);
extern void DisplayError(char *error);
#endif
