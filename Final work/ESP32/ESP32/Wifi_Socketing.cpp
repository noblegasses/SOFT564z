#include"Wifi_Socketing.h"
char SSIDinternal[]="espWiFi";
char PSWDinternal[]="ShortRange";
char SSIDexternal[]="NickNetwork";
char PSWDexternal[]="R0b0t1c5";
const uint port= 49153;
int Status = WL_IDLE_STATUS;
boolean alreadyConnected = false;
IPAddress ip(192,168,1,85);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
WiFiServer Server(port);
void WiFiSetup() {
  if (!WiFi.config(ip, gateway, subnet)) {
    WIFI_DISCONNECTED();
    WIFI_AP_DISCONNECTED();
    BAD_DATA();
    //Serial.println("STA Failed to configure");
  }
 //if the board device cannot connect to WiFi, open device as it's own access point
 for (int i=0; i<=5 && Status!=WL_CONNECTED; i++){
  Status = WiFi.begin(SSIDexternal,PSWDexternal);
  WiFi.setHostname("Nick32");
  WiFi.config(ip, gateway, subnet);
 delay(5000);
 }
 if (Status != WL_CONNECTED){
  WIFI_AP_CONNECTED();
  WiFi.softAP(SSIDinternal, PSWDinternal);
  }
 else{
  WIFI_CONNECTED();
  }
 Server.begin();
}


void WiFiMode(){
 WiFiClient client = Server.available();
 unsigned long start = millis();
 while (client){
    if (!alreadyConnected){
    alreadyConnected=true;
    CLIENT_CONNECTED();
    //Serial.println("new client");
    client.flush();
    }
   bool dataInteg = true; 
   bool updateMove= false;
   while (client.available()>0){
    updateMove=true;
    char clientinput = client.read();
    if (clientinput == 'F' ||
        clientinput == 'B' || 
        clientinput == 'L' ||  
        clientinput == 'R' || 
        clientinput == 'S' ){
     moveArray[0] = clientinput;
     for (int i = 1; i<4; i++){
      moveArray[i] = client.read();
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
  //if (millis()-start>50){
  //start = millis();
  //Serial.print("sending");
  RequestSensors();
  client.print('S');//start character to sync data stream
  for (int i=0; i<2;i++) {
    client.print(dataArray[i]);
    client.print('E');//stop character to differentiate letters
    Serial.print(dataArray[i]);
    Serial.print(" ");
   }
   Serial.println();
  //Serial.println("sending Data");
  if (dataInteg&&updateMove){
    SendMovement();
  }
  //}
}
alreadyConnected = false;
CLIENT_DISCONNECTED();
if (moveArray[0] != 'S'){
 moveArray[0]='S';//emergency brake
 SendMovement();
WIFI_DISCONNECTED();
WIFI_AP_DISCONNECTED();
delay(50); 
}
}
