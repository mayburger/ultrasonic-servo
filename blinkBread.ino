
#include <Servo.h>

const int trigPin = 3;
const int echoPin = 7;

long duration;
int distance;

Servo servo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//  pinMode(LED, OUTPUT);
  
  servo.attach(11);
  
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  if(distance < 20){
    servo.write(0);
    } else{
      servo.write(180);
      }

  Serial.print("Distance: ");
  Serial.println(distance);
  
}
