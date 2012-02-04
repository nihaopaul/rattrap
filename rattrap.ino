int infra = A0;
int servo = 7;
int led = 13;
boolean caught_rat = false;

#include <Servo.h> 
Servo myservo;

void setup() {
   pinMode(infra, INPUT);
   pinMode(led, OUTPUT);
   myservo.attach(servo);
   myservo.write(0);
   digitalWrite(led, HIGH);
   delay(2000);
   myservo.write(60);
   digitalWrite(led, LOW);
   Serial.begin(9600);
}

void loop() {
  
  Serial.println(analogRead(infra));
  
  if (!caught_rat) {
    if (analogRead(infra) > 100) {
      droptrap();
    }
  } else {
    delay(1000);
    digitalWrite(led, HIGH);
     delay(1000);
    digitalWrite(led, LOW);   
  }
}

void droptrap() {
  caught_rat = true;
  myservo.write(0);
  delay(500);
  myservo.write(80);
 
}

