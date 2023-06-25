//BERMAS, LESTER LANCE J.
//BSIT-NS-3AB-M
//IT371LAB-M
//PROF. DARWIN VARGAS


#include <Servo.h>

Servo myservo;

const int BUTTON_PIN = 8;
int lastButtonState = 0;
int buttonState = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  
  if(buttonState == 0){
    if (count == 0){
      myservo.write(90);
      delay(250);
      count++;
    }
    else{
      myservo.write(0);
      delay(250);
      count = 0;
    }
  }

  Serial.print("BUTTON STATE: ");
  Serial.println(buttonState);
  Serial.print("COUNT STATE: ");
  Serial.println(count);
}
