int input = 2;
int uv = 3;
int white = 4;
int ir = 5;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(input,INPUT);
  pinMode(uv,OUTPUT);
  pinMode(white,OUTPUT);
  pinMode(ir,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(input) == HIGH)
  {
    count++;
    if(count == 4)
    {
      count = 0;
    }
    
    if(count == 0)
    {
      digitalWrite(ir,LOW);
    }
    else if(count == 1)
    {
      digitalWrite(uv,HIGH);
    }
    else if(count == 2)
    {
      digitalWrite(white,HIGH);
      digitalWrite(uv,LOW);
    }
    else
    {
      digitalWrite(ir,HIGH);
      digitalWrite(white,LOW);
    }
    while(digitalRead(input) == HIGH);
    delay(250);
  }
 
}
