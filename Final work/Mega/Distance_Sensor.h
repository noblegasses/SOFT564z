#ifndef Distance_H
#define Distance_H
#include <Arduino.h>
// a function to set up the nessisary pins for distance measurement 
extern void distanceSetup();
//a function to read data from the distance sensor and translate it into mm
extern int distanceRead();
#endif
