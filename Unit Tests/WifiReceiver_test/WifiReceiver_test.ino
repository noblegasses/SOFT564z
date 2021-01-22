#include<WiFi.h>
IPAddress ip(192,168,1,85);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
char inputData[4];
char ssid[]= "NickNetwork";
char pswd[]= "R0b0t1c5";
const uint port= 1001;
int Status = WL_IDLE_STATUS;
boolean alreadyConnected = false;
WiFiServer Server(port);
void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
  if (!WiFi.config(ip, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
 while(Status != WL_CONNECTED){
 Serial.print("trying to connect to network ");
 Serial.print(ssid);
 Serial.print("...\r\n");
 //Serial.println(ip);
 Status = WiFi.begin(ssid,pswd);
 WiFi.setHostname("Nick32");
 //WiFi.config(ip);
 delay(5000);
 }
 Server.begin();
 Serial.print("ayy, I'm connected, My IP is:");
 IPAddress myAddress = WiFi.localIP();
 Serial.println(myAddress);
 
}

void loop() {
  // put your main code here, to run repeatedly:
 WiFiClient client = Server.available();
 while (client){
  if(!alreadyConnected){
    client.flush();
    Serial.println("new client");
    //client.print("Hello world, and all that\n\r");
    alreadyConnected=true;
    }
   if(client.available()>4){
    char clientinput = client.read();
    if (clientinput == 'F' ||
        clientinput == 'B' || 
        clientinput == 'L' ||  
        clientinput == 'R' || 
        clientinput == 'S' ){
     inputData[0] = clientinput;
     for (int i = 1; i<4; i++){
      inputData[i] = client.read();
     }
    for (int i=0; i<sizeof(inputData);i++){
     Serial.print(inputData[i]);      
    }
    Serial.println();
    }
   }
  int dummyData[] = {10,400};
  client.print('S');//start character to sync data stream
  for (int i=0; i<2;i++) {
    client.print(dummyData[i]);
    client.print('E');//stop character to differentiate letters
   }
 }
 alreadyConnected = false;
}
