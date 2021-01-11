int pin = 13;
bool value = 0;
bool oldvalue = 0;

void setup() {
pinMode(pin, INPUT);
Serial.begin(115200);
}

void loop() {
value = digitalRead(pin);
if (value != oldvalue){
  oldvalue=value;
  Serial.print("value is:");
  Serial.println(value);
}
}
