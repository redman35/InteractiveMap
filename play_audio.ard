#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

unsigned long previousMillis = 0;  // Variable to store the last time the action was triggered
const long interval = 60000 * 6;       // Interval in milliseconds (1 minute)

TMRpcm tmrpcm;

void setup()
{
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(5);
tmrpcm.play("t50.wav");

}

void loop(){

   unsigned long currentMillis = millis();  // Get the current time

  // Check if it's time to trigger the action
  if (currentMillis - previousMillis >= interval) {
    // Save the last time the action was triggered
    previousMillis = currentMillis;
    tmrpcm.play("t50.wav");
  }

}
