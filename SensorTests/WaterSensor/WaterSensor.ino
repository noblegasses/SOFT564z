int sensor=A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(sensor);
  if (data > 350){
   Serial.print("Wow");
  }
  else if (data > 300){
    Serial.print("Very Drink");
  }
  else if (data > 250){
    Serial.print("Such Water");
   }
  else if (data > 200){
    Serial.print("Smol Wet");
  }
  else{
    Serial.print("THORSTY");
  }
 Serial.print("\n\r");
}
