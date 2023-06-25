//BERMAS LESTER LANCE J.
//BSIT-NS-3A
//PROF. DARWIN VARGAS

const int redLed = 7;
const int yellowLed = 6;
const int greenLed = 5;
const int buzzPin = 10;
const int trigPin = 11;
const int echoPin = 12;

float distance = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);        //set up a serial connection with the computer
  
  // set RGB Led pins to output
  pinMode(redLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  
  // Set buzzer-pin as output
  pinMode(buzzPin,OUTPUT);

  // Set trigPin and echoPin as output
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);     //print the distance that was measured
  Serial.println(" inches");      //print units after the distance

  if(distance >= 10 and distance <= 20){
    // green led will turn on
    digitalWrite(greenLed, HIGH);   // Turn on the LED
    digitalWrite(yellowLed, LOW);    // Turn off the LED
    digitalWrite(redLed, LOW);    // Turn off the LED

    digitalWrite(buzzPin, HIGH); // Tone ON
    digitalWrite(buzzPin, HIGH);  // Tone OFF
  }
  else if (distance >= 5 and distance <= 9){
    // yellow led will turn on
    digitalWrite(greenLed, LOW);   // Turn on the LED
    digitalWrite(yellowLed, HIGH);    // Turn off the LED
    digitalWrite(redLed, LOW);    // Turn off the LED

    digitalWrite(buzzPin, HIGH); // Tone ON
    digitalWrite(buzzPin, HIGH);  // Tone OFF
  }
  else if (distance >= 1 and distance <= 5){
    // red led will turn on and buzzer turn on in 2 seconds
    digitalWrite(greenLed, LOW);   // Turn on the LED
    digitalWrite(yellowLed, LOW);    // Turn off the LED
    digitalWrite(redLed, HIGH);    // Turn off the LED

    digitalWrite(buzzPin, LOW); // Tone ON
    delay(2000);                // Wait for two seconds
    digitalWrite(buzzPin, HIGH);  // Tone OFF
  }
  else{
    digitalWrite(greenLed, LOW);   // Turn on the LED
    digitalWrite(yellowLed, LOW);    // Turn off the LED
    digitalWrite(redLed, LOW);    // Turn off the LED
  }

  delay(50);  
}

float getDistance(){
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calculatedDistance;         //variable to store the distance calculated from the echo time
  
  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //use the pulsein command to see how long it takes for the
  //pulse to bounce back to the sensor
  echoTime = pulseIn(echoPin, HIGH);      
 
  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)
  return calculatedDistance;              //send back the distance that was calculated}
}
