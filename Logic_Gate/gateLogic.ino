const int inputYellow = 4;
const int inputGreen = 3;
const int ledYellow = 7;
const int ledGreen = 10;
const int ledRgb = 6;
bool onYellow = false;
bool onGreen = false;
char bitwiseOp = '\0';
bool bitwise = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputYellow, INPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(inputGreen, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRgb, OUTPUT);
  Serial.begin(9600);
  Serial.println("Select a logic gate(&, |, or ^): ");
}

void loop() {
  // put your main code here, to run repeatedly:   
   while (Serial.available() > 0 && bitwise == false) {
                // read the incoming byte:
                 bitwiseOp = Serial.read();

                // say what you got:
                Serial.print("received: ");
                Serial.println(bitwiseOp);
                if ( bitwiseOp == '&' || bitwiseOp == '^' || bitwiseOp == '|')
                {
                  bitwise = true;
                }
                else
                {
                  bitwise = false;
                }
        }
        
  if(digitalRead(inputYellow) == HIGH && onYellow == false)
  {
      digitalWrite(ledYellow, HIGH);
      onYellow = true;
      delay(250);
  }
  else if (digitalRead(inputYellow) == HIGH && onYellow == true)
  {
      digitalWrite(ledYellow, LOW);
      onYellow = false;
      delay(250);
  }
 
  if (digitalRead(inputGreen) == HIGH && onGreen == false)
  {
      digitalWrite(ledGreen, HIGH);
      onGreen = true;
      delay(250);
  }
  else if (digitalRead(inputGreen) == HIGH && onGreen == true)
  {
      digitalWrite(ledGreen, LOW);
      onGreen = false;
      delay(250);
  }
  
  switch (bitwiseOp)
  {
    case '^':
         if (onGreen^onYellow)
         {
          
            digitalWrite(ledRgb, HIGH);
         }
         else
        {
            digitalWrite(ledRgb, LOW);
        }
        break;
    case '&':
        if (onGreen & onYellow)
         {
            digitalWrite(ledRgb, HIGH);
         }
         else
        {
            digitalWrite(ledRgb, LOW);
        }
        break;
    case '|':
      if (onGreen | onYellow)
         {
            digitalWrite(ledRgb, HIGH);
         }
         else
        {
            digitalWrite(ledRgb, LOW);
        }
  }
  
}
