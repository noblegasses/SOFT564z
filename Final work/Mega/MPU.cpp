#include"MPU.h"
int IMUaddr;
void IMU_Setup(int addr){
  IMUaddr = addr;
  //write to the MPU to disable sleep mode
  Wire.beginTransmission(addr);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
}
void IMU_Read(float *dataout){
  //read data from IMU 
  Wire.beginTransmission(IMUaddr);
  //request from written address on
  Wire.write(0x3B);  
  Wire.endTransmission(false);//do not restart connection
  //request a 7 registers from the sensors
  Wire.requestFrom(IMUaddr,7*2,true);  
  //accelerometer data
  dataout[0]=Wire.read()<<8|Wire.read();    
  dataout[1]=Wire.read()<<8|Wire.read();  
  dataout[2]=Wire.read()<<8|Wire.read(); 
  //temperature data
  dataout[3]=Wire.read()<<8 | Wire.read();
  //gyrodata  
  dataout[4]=Wire.read()<<8|Wire.read();  
  dataout[5]=Wire.read()<<8|Wire.read();  
  dataout[6]=Wire.read()<<8|Wire.read();  
}
