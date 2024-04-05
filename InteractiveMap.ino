#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"


TMRpcm tmrpcm;

int ledPins[] = {1,2,3,4,5,6,7,8};
int eyePins[] = {A0,A1};

unsigned long previousMillis = 0;
const long interval = 2000; 
int state = 0;
int maxState = 10;

void setup() {

  tmrpcm.speakerPin=9;
  Serial.begin(9600);
  Serial.println("Starting");
  if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
  for(int i=0;i<8;i++)
  {
    pinMode(ledPins[i],OUTPUT);
  }
  pinMode(eyePins[0],OUTPUT);
  pinMode(eyePins[1],OUTPUT);
  tmrpcm.setVolume(5);
  tmrpcm.play("t50.wav");
}

void loop() {
  unsigned long currentMillis = millis();
  Serial.print("\nCurrent state ");
  Serial.print(state);
  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;
    state++;
    if(state == maxState)
    {
      Reset();
      return;
    }
    if(state < 8){
      digitalWrite(ledPins[state],HIGH);
      if(state != 1){
        digitalWrite(ledPins[state-1],LOW);
      }
    }else{
      digitalWrite(eyePins[state-8],HIGH);
    }

  }

}


void Reset()
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(ledPins[i],LOW);
  }
  digitalWrite(eyePins[0],LOW);
  digitalWrite(eyePins[1],LOW);
  state = 0;
  tmrpcm.play("t50.wav");
}
