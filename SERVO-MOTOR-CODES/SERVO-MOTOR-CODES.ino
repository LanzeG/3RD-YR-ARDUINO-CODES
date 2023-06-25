//SERVO-MOTOR
//LESTER LANCE J. BERMAS
//BSIT-NS-3AB-M
//PROF. DARWIN VARGAS


#include <Servo.h>          
int potPosition; 
int servoPosition;                   
Servo myservo; 
void setup() {
  myservo.attach(9);       
void loop() {
  potPosition = analogRead(A0);                    
  servoPosition = map(potPosition, 0, 1023, 20, 160); 
  myservo.write(servoPosition);                     
