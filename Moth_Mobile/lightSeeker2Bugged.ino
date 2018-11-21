class Moth_Mobile
{
  Servo _rightWheel;
  Servo _leftWheel;
  char _direction;
  int _antennae[4];
  int _lightLevel[4];
  void init()
  {
    _rightWheel.attach(5);
    _leftWheel.attach(6);
    _rightWheel.write(90);
    _leftWheel.write(90);
    _direction = 'S';
    _antennae[0] = A0;
    _antennae[1] = A1;
    _antennae[2] = A2;
    _antennae[3] = A3;
  }

  void followLight()
  {
    int currentMax = 0;
    for(int i = 0; i < 4; i++)
    {
      _lightLevel[i] = analogRead(_antennae[i]);
      if(_lightLevel[i] < _lightLevel[currentMax])
      {
        currentMax = i;
      }
    }
    Serial.print(currentMax);
    switch(currentMax)
    {
      case 0:
      turnLeft();
      break;
      case 1:
      turnRight();
      break;
      case 2:
      forward();
      break;
      case 3:
      halt();
    }
  }
  
  void forward()
  {
    _rightWheel.write(100);
    _leftWheel.write(80);
    _direction = 'F';
  }
  
  void turnRight()
  {
    _rightWheel.write(80);
    _leftWheel.write(80);
    _direction = 'R';
  }
  
  void turnLeft()
  {
    _rightWheel.write(100);
    _leftWheel.write(100);
    _direction = 'L';
  }
  
  void halt()
  {
    _rightWheel.write(90);
    _leftWheel.write(90);
    _direction = 'S';
  }

  char getDirection()
  {
    return _direction;
  }
};

void setup()
{
  Moth_Mobile mothy;
  mothy.init();
  Serial.begin(9600);
}

void loop()
{
  mothy.followLight();
  Serial.print("current _direction: ");
  Serial.println(mothy.getDirection());
  delay(250);
}
