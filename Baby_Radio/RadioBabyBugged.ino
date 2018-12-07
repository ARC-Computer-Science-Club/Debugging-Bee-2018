#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int sdPinRX = 0;
const int sdPinTX = 1;

const int startButtonPin = 5;
const int stopButtonPin  = 6;
const int whiteOutPin =  7;
const int whiteInPin  =  8;
const int blueOutPin =  9;
const int blueInPin  = 10;
const int yellowOutPin = 11;
const int yellowInPin  = 12;

bool started = false;
int startButtonState;
int stopButtonState;
int white;
int blue;
int yellow;

SoftwareSerial mySoftwareSerial(sdPinRX, sdPinTX);
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  pinMode(startButtonPin, INPUT);
  pinMode(stopButtonPin, INPUT);
  pinMode(whiteOutPin, OUTPUT);
  pinMode(blueOutPin, OUTPUT);
  pinMode(yellowOutPin, OUTPUT);
  pinMode(whiteInPin, INPUT);
  pinMode(blueInPin, INPUT);
  pinMode(yellowInPin, INPUT);

  pinMode(sdPinRX, INPUT);
  pinMode(sdPinTX, OUTPUT);
   
  digitalWrite(whiteOutPin, LOW);
  digitalWrite(blueOutPin, HIGH);
  digitalWrite(yellowOutPin, HIGH);

  mySoftwareSerial.begin(9600);
  
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(30);
  myDFPlayer.EQ(4);
}

void loop() {
  int startButtonState = digitalRead(startButtonPin);
  int stopButtonState = digitalRead(stopButtonPin);
  int white = digitalRead(whiteInPin);
  int blue = digitalRead(blueInPin);
  int yellow = digitalRead(yellowInPin);

  if( startButtonState && !stopButtonState && !started )
  {
    started = true;
    myDFPlayer.play(1);
  }
  else if(stopButtonState && !(!stopButtonState || startButtonState || white) && !(blue || !yellow))
  {
    myDFPlayer.stop();
    started = false;
  }
}
