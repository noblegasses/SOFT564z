#include <Motor.h>
void Left(){
 digitalWrite(AMot,HIGH);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,255);
 digitalWrite(BMot,HIGH);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,255);
}
void Right(){
 digitalWrite(AMot,LOW);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,255);
 digitalWrite(BMot,HIGH);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,255);
}
void Forward(){
 digitalWrite(AMot,HIGH);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,255);
 digitalWrite(BMot,LOW);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,255);
}
void Backwards(){
 digitalWrite(AMot,LOW);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,255);
 digitalWrite(BMot,HIGH);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,255);
}
void Stop(){
 digitalWrite(AMot,LOW);
 digitalWrite(ABra,HIGH);
 analogWrite(AThrot,0);
 digitalWrite(BMot,LOW);
 digitalWrite(BBra,HIGH);
 analogWrite(BThrot,0);  
}
