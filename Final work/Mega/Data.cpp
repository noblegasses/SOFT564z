#include"Data.h"
const int arlength = 2;
float dataArray[arlength];
void sensorSetup(int addr){
 distanceSetup();
 //IMU_Setup(addr);
 waterSetup();
}
void sensorRead(){
//IMU_Read(dataArray);
dataArray[0]= distanceRead();
dataArray[1]= waterRead(); 
}
