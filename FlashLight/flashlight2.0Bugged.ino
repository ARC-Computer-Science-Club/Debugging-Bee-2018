const int BUTTON = 2;
const int UV_LED = 3;
const int WHITE_LED = 4;
const int IR_LED = 5;
const int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON,INPUT);
  pinMode(UV_LED,OUTPUT);
  pinMode(WHITE_LED,OUTPUT);
  pinMode(IR_LED,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON) = HIGH)
  {
    count = (count++)%4;

    switch(count)
    {
      case 0:
        digitalWrite(IR_LED,LOW);
      break;
      case 1:
        digitalWrite(UV_LED,HIGH);
      break;
      case 2:
        digitalWrite(WHITE_LED,HIGH);
        digitalWrite(UV_LED,LOW);
      break;
      default:
        digitalWrite(IR_LED,HIGH);
        digitalWrite(WHITE_LED,LOW);
    }
    
    while(digitalRead(BUTTON) == HIGH);
    delay(250);
  }
 
}
