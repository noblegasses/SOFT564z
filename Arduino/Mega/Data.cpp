#include"Data.h"
float dataArray[9];
void sensorSetup(int addr){
 distanceSetup();
 IMU_Setup(addr);
 waterSetup();
}
void sensorRead(){
IMU_Read(dataArray);
dataArray[7]= distanceRead();
dataArray[8]= waterRead(); 
}
