#include"Wifi_Socketing.h"
char SSIDinternal[]="espWiFi";
char PSWDinternal[]="ShortRange";
char SSIDexternal[]="NickNetwork";
char PSWDexternal[]="R0b0t1c5";
const uint port= 1001;
int Status = WL_IDLE_STATUS;
boolean alreadyConnected = false;
IPAddress ip(192,168,1,85);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
WiFiServer Server(port);
void WiFiSetup() {
  if (!WiFi.config(ip, gateway, subnet)) {
    Serial.println("STA Failed to configure");
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
 while (client){
    if (!alreadyConnected){
    CLIENT_CONNECTED();
    client.flush();
    }
   bool dataInteg = true; 
   for(int i =0; client.available()>0&&i<4; i++){
    char clientinput = client.read();
    if (i<sizeof(moveArray)){
      if (checkValid(clientinput)){
       moveArray[i] = clientinput;
      }
      }
    else{
      dataInteg=false;
      BAD_DATA();
    }
    }
  for (int i =0; i<4; i++){
    Serial.print (moveArray[i]);
    }
  Serial.print("\n\r");
  RequestSensors();
  for (int i=0; i<sizeof(dataArray)/2; i++){
    client.print(dataArray[i]);
  if (dataInteg){
    SendMovement();
  }
  }
}
alreadyConnected = false;
CLIENT_DISCONNECTED();
delay(500); 
}
