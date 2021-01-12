const int echo = 0;
const int trigger = 1;
void setup() {
 Serial.begin(115200);
 pinMode(trigger, OUTPUT);
 pinMode(echo, INPUT);
}

void loop() {
  int duration;
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
  //calcuate distance in mm by dividing by the speed of sound in mm
  float distance = duration * 0.0034 / 2;
  Serial.println(duration);
  Serial.println(distance);
}
