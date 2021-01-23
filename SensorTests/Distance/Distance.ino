const int echo = 5;
const int trigger = 6;
void setup() {
 Serial.begin(115200);
 pinMode(trigger, OUTPUT);
 pinMode(echo, INPUT);
}

void loop() {
  int duration=0;
  //clear pin condition
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  //trigger the distance sensor to start measurement
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  //wait  for response
  //read the duration for pulse return
  duration = pulseIn(echo, HIGH);
  //calcuate distance in mm by multiplying by the speed of sound in mm/uS
  float distance = (duration*0.343) / 2;
  Serial.print("Duration is ");
  Serial.print(duration);
  Serial.println("ms");
  Serial.print("Distance is ");
  Serial.print(distance);
  Serial.println("mm");
  delay(1000);
}
