int ledPins[] = {1,2,3,4,5,6,7,8};
int eyePins[] = {A0,A1};

unsigned long previousMillis = 0;
const long interval = 1000; 
int state = 0;
int maxState = 10;

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++)
  {
    pinMode(ledPins[i],OUTPUT);
  }
  pinMode(eyePins[0],OUTPUT);
  pinMode(eyePins[1],OUTPUT);

}

void loop() {
  unsigned long currentMillis = millis();

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
      digitalWrite(ledPins[state],LOW);
    }else{
      digitalWrite(eyePins[state-8],LOW);
    }

  }

}


void Reset()
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(ledPins[i],HIGH);
  }
  digitalWrite(eyePins[0],HIGH);
  digitalWrite(eyePins[1],HIGH);
  state = 0;
}
