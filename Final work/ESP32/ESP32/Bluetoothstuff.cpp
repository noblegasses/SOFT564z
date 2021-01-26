//This code is unimplemented
#include "Bluetoothstuff.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
void BTSetup(char *DeviceName){
SerialBT.begin(DeviceName);
}
void BTMode(){
 BLUETOOTH_CONNECTED();
 bool dataInteg = true; 
 bool updateMove= false;
 if (SerialBT.available()){
  while(SerialBT.available()){
    updateMove=true;
    char clientinput = SerialBT.read();
    if (clientinput == 'F' ||
        clientinput == 'B' || 
        clientinput == 'L' ||  
        clientinput == 'R' || 
        clientinput == 'S' ){
     moveArray[0] = clientinput;
     for (int i = 1; i<4; i++){
      moveArray[i] = SerialBT.read();
     }
     //validate the rest of the bus
     for(int i = 1;i<4; i++){
      if (moveArray[i]-48 <0 || moveArray[i]-48>9){
       dataInteg=false;
       BAD_DATA();//raise error light
      }
      else{//if data is good
      DATA_CLEARED(); 
     }
    }
   }
 }
 RequestSensors();
 SerialBT.print('S');//start character to sync data stream
 for (int i=0; i<2;i++) {
  SerialBT.print(dataArray[i]);
  SerialBT.print('E');//stop character to differentiate letters
 }
 //Serial.println("sending Data");
 if (dataInteg&&updateMove){
   SendMovement();
 }
}
BLUETOOTH_DISCONNECTED();
}
