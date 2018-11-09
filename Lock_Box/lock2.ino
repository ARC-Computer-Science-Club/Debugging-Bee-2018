int green = 2;
int black = 3;
int white = 4;
int lock = 5;
bool state1 = false;
bool state2 = false;
bool state3 = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(black, INPUT);
  pinMode(white, INPUT);
  pinMode(green, INPUT);
  pinMode(lock, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  do
  {
      state1 = digitalRead(black);
      state2 = digitalRead(white);
      state3 = digitalRead(green);
  }while(!state1 && !state2 && !state3);
  digitalWrite(lock, HIGH);
  
  int arr[3] = {black,white,green};
  if(combo(arr, 3))
  {
    digitalWrite(lock, LOW);
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
    do
    {
      state1 = digitalRead(black);
      state2 = digitalRead(white);
      state3 = digitalRead(green);
    }while(!state1 && !state2 && !state3);
    delay(400);
    Serial.println(*myCombo);
    int count = 0;
    bool valid = false;
    if(state1)
    {
      count++;
      if(*myCombo == black)
      {
        valid = true;
      }
    }
    if(state2)
    {
      count++;
      if(*myCombo == white)
      {
        valid = true;
      }
    }
    if(state3)
    {
      count++;
      if(*myCombo == green)
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
