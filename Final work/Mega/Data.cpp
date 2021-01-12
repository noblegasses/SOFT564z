#include"Data.h"
// functions for the setup and reading of all sensors
const int arlength = 2;//the length of the data array, if IMU is included, the length is 8, if not,the length is 2
volatile int dataArray[arlength];//initalize the array, volatile incase of intterupt
void sensorSetup(int addr){
 distanceSetup();//setup ultrasonic distance sensor
 //IMU_Setup(addr);//setup IMU(hardware currently unavailable so not included)
 waterSetup();//set up pins for the water sensor
}
void sensorRead(){
//IMU_Read(dataArray);//read data from IMU to the dataArray
dataArray[0]= distanceRead();// read the ultrasonic distance sensor data into the dataArray
dataArray[1]= waterRead(); // read the water level sensor data into the dataArray
}
