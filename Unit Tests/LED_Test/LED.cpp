#include"LED.h"
int WIFI_pin = 13;
int AP_pin = 12;
int CLIENT_pin =14; 
int ERROR_pin = 27;
int BT_pin = 26;
void LEDSetup(){
  pinMode(WIFI_pin, OUTPUT);
  pinMode(AP_pin, OUTPUT);
  pinMode(CLIENT_pin, OUTPUT);
  pinMode(ERROR_pin, OUTPUT);
  pinMode(BT_pin, OUTPUT);
}
void BLUETOOTH_CONNECTED(){
   digitalWrite(BT_pin, HIGH);
  }
void BAD_DATA(){
  digitalWrite(ERROR_pin, HIGH);
  }
void WIFI_CONNECTED(){
  digitalWrite(WIFI_pin, HIGH);
  }
void WIFI_AP_CONNECTED(){
  digitalWrite(AP_pin, HIGH);
  }
void CLIENT_CONNECTED(){
  digitalWrite(CLIENT_pin, HIGH);
  }
void BLUETOOTH_DISCONNECTED(){
  digitalWrite(BT_pin, LOW);
  }
void DATA_CLEARED(){
  digitalWrite(ERROR_pin, LOW);
  }
void WIFI_DISCONNECTED(){
  digitalWrite(WIFI_pin, LOW);
  }
void WIFI_AP_DISCONNECTED(){
  digitalWrite(AP_pin, LOW);
  }
void CLIENT_DISCONNECTED(){
  digitalWrite(CLIENT_pin, LOW);
  }
