#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
}
/*int in = A0;
void setup() {
 // put your setup code here, to run once:
 pinMode(in,INPUT); 
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(in);
    if (data != 33){
  Serial.print(data);
  Serial.print("\r\n");
  }
}*/ 
