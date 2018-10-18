int bits[4] = {5,4,3,2};
const int NUMBER_OF_BITS = 4;
int input = 0;
int mask;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < NUMBER_OF_BITS; i++)
  {
    pinMode(bits[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) 
  {
    input = Serial.parseInt();
    // say what you got:
    Serial.print("I received: ");
    Serial.println(input);
    mask = 1;
    for(int i = 0; i < NUMBER_OF_BITS; i++)
    {
      if(input & mask)
      {
        digitalWrite(bits[i], HIGH);
      }
      else
      {
        digitalWrite(bits[i], LOW);
      }
      mask <<= 1;
    }
  }
}
