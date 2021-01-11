#ifndef Data_H
#define Data_H
#include <Arduino.h>
#include "Distance_Sensor.h"
#include "MPU.h"
#include "Water_Sensor.h"
extern float dataArray[9];
extern void sensorSetup(int addr);
extern void sensorRead();
#endif
