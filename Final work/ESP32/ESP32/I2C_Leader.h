#ifndef I2C_Leader_H
#define I2C_Leader_H
#include <arduino.h>
#include "Data.h"
#include<Wire.h>
extern void I2CSetup();
extern void RequestSensors();
extern void SendMovement();

#endif
