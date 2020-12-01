#include<WiFi.h>
IPAddress ip(192,168,0,85);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);
//char ssid[] = "NaoNetwork";
//char pswd[] ="j0hnc01r0";
char ssid[]="CityLets WiFi";
char pswd[]="CityLetsProp!!"; 
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
 Serial.println(WiFi.macAddress());
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
    client.print("Hello world, and all that\n\r");
    alreadyConnected=true;
    }
   if(client.available()>0){
    char clientinput = client.read();
    Server.write(clientinput);
    client.print(clientinput);
    Serial.print(clientinput);
    if (client.available()<0){
      Serial.print("\r\n");
      client.print("\r\n");
      }
    }
  }
 alreadyConnected = false;
}
