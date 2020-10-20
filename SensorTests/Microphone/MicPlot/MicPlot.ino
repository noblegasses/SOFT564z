int analog = A0;
int digital = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(analog, INPUT);
  pinMode(digital, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogData = analogRead(analog);
  int digitalData= digitalRead(digital);
  Serial.print(digitalData);
  Serial.print(" , ");
  Serial.println(analogData);
  delay(20);
}
