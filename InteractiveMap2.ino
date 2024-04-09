#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

#define LED_1 7 
#define LED_2 2
#define LED_3 3
#define LED_4 5
#define LED_5 4
#define LED_6 6

// #define audio_file "t50.wav"
#define audio_file "j3.wav"
// #define audio_file "m3.wav"
// #define audio_file "m3v2.wav"

TMRpcm tmrpcm;

int ledPins[] = {0,1,2,3,4,5,6,7};
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
  for(int i=0;i<9;i++)
  {
    pinMode(ledPins[i],OUTPUT);
  }
  // pinMode(A5,OUTPUT);
  pinMode(eyePins[0],OUTPUT);
  pinMode(eyePins[1],OUTPUT);
  tmrpcm.setVolume(5);
  tmrpcm.play(audio_file);

}

void loop() { 

  delay(1500);

  delay(6000);

  digitalWrite(LED_1,HIGH);
  delay(4000);
  digitalWrite(LED_1,LOW);

  digitalWrite(LED_2,HIGH);
  digitalWrite(LED_3,HIGH);
  delay(10000);
  digitalWrite(LED_2,LOW);
  digitalWrite(LED_3,LOW);

  digitalWrite(LED_3,HIGH);
  delay(3000);
  digitalWrite(LED_3,LOW);

  delay(2000);

  digitalWrite(LED_5,HIGH);
  delay(4000);
  digitalWrite(LED_5,LOW);

  digitalWrite(LED_4,HIGH);
  delay(9000);
  digitalWrite(LED_4,LOW);

  digitalWrite(LED_6,HIGH);
  delay(7000);
  digitalWrite(LED_6,LOW);


  digitalWrite(eyePins[0],HIGH);
  digitalWrite(eyePins[1],HIGH);
  delay(14000);

  tmrpcm.play(audio_file);

  for(int i=2;i<8;i++)
  {
    digitalWrite(ledPins[i],LOW);
  }
  digitalWrite(eyePins[0],LOW);
  digitalWrite(eyePins[1],LOW);

}
