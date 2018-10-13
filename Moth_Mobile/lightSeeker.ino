#include <Servo.h>
Servo rightWheel;
Servo leftWheel;
int photoLeft = A0;
int photoRight = A1;
int photoFront = A2;
int photoTop = A3;
int left,right,front,top;
char dir = 'S';

void setup()
{
  Serial.begin(9600);
  rightWheel.attach(5);
  leftWheel.attach(6);
  rightWheel.write(90);
  leftWheel.write(90); 
}

void loop()
{
  left = analogRead(photoLeft);
  right = analogRead(photoRight);
  front = analogRead(photoFront);
  top = analogRead(photoTop);

  if(left > right && left > front && left > top && dir != 'L')
  {
    turnLeft();
    dir = 'L';
  }
  else if(right > left && right > front && right > top && dir != 'R')
  {
    turnRight();
    dir = 'R';
  }
  else if(front > left && front > right && front > top && dir != 'F')
  {
    forward();
    dir = 'F';
  }
  else if(top > left && top > right && front < top && dir != 'S')
  {
    halt();
    dir = 'S';
  }
  Serial.println(dir);
  Serial.println(left);
  Serial.println(right);
  Serial.println(front);
  Serial.println(top);
  delay(250);
}

void forward()
{
  rightWheel.write(100);
  leftWheel.write(80);
}

void turnRight()
{
  rightWheel.write(80);
  leftWheel.write(80);
}

void turnLeft()
{
  rightWheel.write(100);
  leftWheel.write(100);
}

void halt()
{
  rightWheel.write(90);
  leftWheel.write(90);
}
