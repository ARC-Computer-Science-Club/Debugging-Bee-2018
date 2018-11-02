int black = 2;
int white = 3;
int green = 4;
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
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(black) == HIGH)
  {
    state1 = !(state1);
  }
  if(digitalRead(white) == HIGH)
  {
    state2 = !(state2);
  }
  if(digitalRead(green) == HIGH)
  {
    state3 = !(state3);
  }

  if(state1 && state2 && state3)
  {
    digitalWrite(lock, HIGH);  
  }
  else
  {
    digitalWrite(lock, LOW);
  }
}
