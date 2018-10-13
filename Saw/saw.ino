#include <Servo.h>

int pot = A1;
Servo myServo;

void setup() {
  // put your setup code here, to run once
  myServo.attach(A0);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int speed = analogRead(pot);
  if(speed  < 250)
  {
    speed = 91;
  }
  else if(speed < 500)
  {
    speed = 94;
  }
  else if(speed < 750)
  {
    speed = 96;
  }
  else
  {
    speed = 120;
  }
  myServo.write(speed);
}
