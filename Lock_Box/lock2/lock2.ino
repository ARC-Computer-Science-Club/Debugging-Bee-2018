int blue = 2;
int white = 3;
int yellow = 4;
int lock = 5;
bool state1 = false;
bool state2 = false;
bool state3 = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(white, INPUT);
  pinMode(yellow, INPUT);
  pinMode(blue, INPUT);
  pinMode(lock, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  do
  {
      state1 = digitalRead(white);
      state2 = digitalRead(yellow);
      state3 = digitalRead(blue);
  }while(!state1 && !state2 && !state3);
  digitalWrite(lock, LOW);
  
  int arr[3] = {white,yellow,blue};
  if(combo(arr, 3))
  {
    digitalWrite(lock, HIGH);
  }
}

bool combo(int *myCombo, int comboLength)
{
  bool prevInput = true;
  if(comboLength > 1)
  {
    prevInput = combo(myCombo+1, comboLength-1);
  }

  if(prevInput)
  {
    Serial.println(*myCombo);
    do
    {
      state1 = digitalRead(white);
      state2 = digitalRead(yellow);
      state3 = digitalRead(blue);
    }while(!state1 && !state2 && !state3);
    delay(400);
    int count = 0;
    bool valid = false;
    if(state1)
    {
      count++;
      if(*myCombo == white)
      {
        valid = true;
      }
    }
    if(state2)
    {
      count++;
      if(*myCombo == yellow)
      {
        valid = true;
      }
    }
    if(state3)
    {
      count++;
      if(*myCombo == blue)
      {
        valid = true;
      }
    }
    if(count == 1 && valid)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}
