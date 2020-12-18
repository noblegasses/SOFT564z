#ifndef TCP_H
#define TCP_H
#include<WiFi.h>
//#include"tinyxml121.h"
WiFiServer NetworkConnect(char ssid[], char pswd[], uint port, int ipaddr[4] ={0});
#endif
