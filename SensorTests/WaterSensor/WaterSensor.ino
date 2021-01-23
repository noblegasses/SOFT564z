int sensor=A1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(sensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(sensor);
  if (data>=200){
   data= map(data,200,360,0,40);
  }
  else{
    data=0;
   }
  Serial.println(data);
  /*
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
 */
}
