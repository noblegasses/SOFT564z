#ifndef LED_H
#define LED_H
#include <arduino.h>
extern void LEDSetup();
extern void BLUETOOTH_CONNECTED();
extern void BAD_DATA();
extern void WIFI_CONNECTED();
extern void WIFI_AP_CONNECTED();
extern void CLIENT_CONNECTED();
extern void BLUETOOTH_DISCONNECTED();
extern void DATA_CLEARED();
extern void WIFI_DISCONNECTED();
extern void WIFI_AP_DISCONNECTED();
extern void CLIENT_DISCONNECTED();
#endif
