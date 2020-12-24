int brownpin = 7;
int yellowpin= 8;
int readB =0;
int readY =0;
int AMot = 12;
int ABra = 9;
int AThrot = 3;
int BMot = 13;
int BBra = 8;
int BThrot=11;
void moveForward();
void moveBackward();
void stopMotors();
void setup() {
 //Setup Channel A
 pinMode(AMot, OUTPUT); //Initiates Motor Channel A pin
 pinMode(ABra, OUTPUT); //Initiates Brake Channel A pin
 //Setup Channel B
 pinMode(BMot, OUTPUT); //Initiates Motor Channel B pin
 pinMode(BBra, OUTPUT);  //Initiates Brake Channel B pin
 pinMode(brownpin, INPUT);
 pinMode(yellowpin, INPUT);
 Serial.begin(115200);
}

void loop() {
 switch(Serial.read()){
  case 'w':
   moveForward();
   break;
  case 's':
   moveBackward();
   break;
  case '.':
   stopMotors();
   break;
  default:
   break;
  }
 readB=digitalRead(brownpin);
 readY=digitalRead(yellowpin);
 Serial.print("brown is : ");
 Serial.print(readB);
 Serial.print(" yellow is: ");
 Serial.print(readY);
 Serial.print("\r\n");
}
void moveForward(){
 digitalWrite(AMot,HIGH);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,0);
 digitalWrite(BMot,LOW);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,60);
}
void moveBackward(){
 digitalWrite(AMot,LOW);
 digitalWrite(ABra,LOW);
 analogWrite(AThrot,50);
 digitalWrite(BMot,HIGH);
 digitalWrite(BBra,LOW);
 analogWrite(BThrot,50);
}
void stopMotors(){
   digitalWrite(AMot,LOW);
 digitalWrite(ABra,HIGH);
 analogWrite(AThrot,0);
 digitalWrite(BMot,LOW);
 digitalWrite(BBra,HIGH);
 analogWrite(BThrot,0);
}
