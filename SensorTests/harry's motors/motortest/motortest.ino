#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
int button = 0;
const int DIRECTIONA = 12;
const int DIRECTIONB = 13;
const int BRAKEA = 9;
const int BRAKEB = 8;
const int PWMA = 3;
const int PWMB = 11;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(DIRECTIONA, OUTPUT);
  pinMode(DIRECTIONB, OUTPUT);
  pinMode(BRAKEA, OUTPUT);
  pinMode(BRAKEB, OUTPUT);
//  pinMode(PWMA, OUTPUT);
//  pinMode(PWMB, OUTPUT);
  digitalWrite(BRAKEA, HIGH);
  digitalWrite(BRAKEB, HIGH);
  analogWrite(PWMA, 255);
  analogWrite(PWMB, 255);
}

void buttonAction(int button) {
  switch(button) {
    case 0:
      Serial.println("Error- Out of range or inteference");
    break;
    case 1:
      Serial.println("1");
    break;
    case 2:
      Serial.println("2");
    break;
    case 3:
      Serial.println("3");
    break;
    case 4:
      Serial.println("4");
    break;
    case 5:
      Serial.println("5");
    break;
    case 6:
      Serial.println("6");
    break;
    case 7:
      Serial.println("7");
    break;
    case 8:
      Serial.println("8");
    break;
    case 9:
      Serial.println("9");
    break;
    case 10:
      Serial.println("0");
    break;
    case 11:
      Serial.println("*");
    break;
    case 12:
      Serial.println("#");
    break;
    case 13:
      Serial.println("^");
      digitalWrite(DIRECTIONA, LOW);
      digitalWrite(DIRECTIONB, LOW);
      digitalWrite(BRAKEB, LOW);
      digitalWrite(BRAKEA, LOW);
      delay(100);
    break;
    case 14:
      Serial.println(">");
      digitalWrite(DIRECTIONA, HIGH);
      digitalWrite(DIRECTIONB, HIGH);
      digitalWrite(BRAKEB, LOW);
      digitalWrite(BRAKEA, LOW);
      delay(100);
    break;
    case 15:
      Serial.println("<");
      digitalWrite(DIRECTIONA, LOW);
      digitalWrite(DIRECTIONB, LOW);
      digitalWrite(BRAKEB, LOW);
      digitalWrite(BRAKEA, LOW);
      delay(100);
    break;
    case 16:
      Serial.println("v");
      digitalWrite(DIRECTIONA, HIGH);
      digitalWrite(DIRECTIONB, LOW);
      digitalWrite(BRAKEB, LOW);
      digitalWrite(BRAKEA, LOW);
      delay(100);
    break;
    case 17:
      Serial.println("OK");
      digitalWrite(BRAKEB, HIGH);
      digitalWrite(BRAKEA, HIGH);
    break;
  }
}

void loop() {
  if (irrecv.decode(&results)){
      if (results.value == 16753245) {
        button = 1;
      }
      else if (results.value == 16736925) {
        button = 2;
      }
      else if (results.value == 16769565) {
        button = 3;
      }
      else if (results.value == 16720605) {
        button = 4;
      }
      else if (results.value == 16712445) {
        button = 5;
      }
      else if (results.value == 16761405) {
        button = 6;
      }
      else if (results.value == 16769055) {
        button = 7;
      }
      else if (results.value == 16754775) {
        button = 8;
      }
      else if (results.value == 16748655) {
        button = 9;
      }
      else if (results.value == 16750695) {
        button = 10;
      }
      else if (results.value == 16738455) {
        button = 11;
      }
      else if (results.value == 16756815) {
        button = 12;
      }
      else if (results.value == 16718055) {
        button = 13;
      }
      else if (results.value == 16734885) {
        button = 14;
      }
      else if (results.value == 16716015) {
        button = 15;
      }
      else if (results.value == 16730805) {
        button = 16;
      }
      else if (results.value == 16726215) {
        button = 17;
      }
      else if (results.value == 4294967295) {
        button = button;
      }
      else {
        button = 0;
      }
//      Serial.println(results.value, HEX);
      buttonAction(button);
      irrecv.resume();
  }
  if(button == 0) {
    digitalWrite(BRAKEB, HIGH);
    digitalWrite(BRAKEA, HIGH);
  }
}
