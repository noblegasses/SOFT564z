#include "TCP.hpp"
WiFiServer NetworkConnect(char ssid[], char pswd[], uint port, int ipaddr[4]){
 IPAddress ip = (ip[0],ip[1],ip[2],ip[3]);
 int Status = WL_IDLE_STATUS;
 boolean alreadyConnected = false;
 WiFiServer Server(port);
 if (!WiFi.config(ip, gateway, subnet)) {
    Serial.println("STA Failed to configure" );
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
 return Server;
}
