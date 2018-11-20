#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int sdPinRX = 0;
const int sdPinTX = 1;

const int startButtonPin = 5;
const int stopButtonPin  = 6;
const int link1OutPin =  7;
const int link1InPin  =  8;
const int link2OutPin =  9;
const int link2InPin  = 10;
const int link3OutPin = 11;
const int link3InPin  = 12;
const int ledPin = LED_BUILTIN;

bool started = false;
int ledState = LOW;
int startButtonState;
int stopButtonState;
int link1State;
int link2State;
int link3State;

SoftwareSerial mySoftwareSerial(sdPinRX, sdPinTX);
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  pinMode(startButtonPin, INPUT);
  pinMode(stopButtonPin, INPUT);
  pinMode(link1OutPin, OUTPUT);
  pinMode(link2OutPin, OUTPUT);
  pinMode(link3OutPin, OUTPUT);
  pinMode(link1InPin, INPUT);
  pinMode(link2InPin, INPUT);
  pinMode(link3InPin, INPUT);

  pinMode(sdPinRX, INPUT);
  pinMode(sdPinTX, OUTPUT);
   
  digitalWrite(ledPin, ledState);
  digitalWrite(link1OutPin, LOW);
  digitalWrite(link2OutPin, HIGH);
  digitalWrite(link3OutPin, HIGH);

  mySoftwareSerial.begin(9600);
  
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(30);
  myDFPlayer.EQ(4);
}

void loop() {
  int startButtonState = digitalRead(startButtonPin);
  int stopButtonState = digitalRead(stopButtonPin);
  int link1State = digitalRead(link1InPin);
  int link2State = digitalRead(link2InPin);
  int link3State = digitalRead(link3InPin);

  if( startButtonState && !stopButtonState && !started )
  {
    ledState = HIGH;
    started = true;
    myDFPlayer.play(1);
  }
  else if(!(!(stopButtonState && !startButtonState) || !stopButtonState || !link1State || !(!link2State || link3State)))
  {
    myDFPlayer.stop();
    started = false;
    ledState = LOW;
  }

  digitalWrite(ledPin, ledState);
}
