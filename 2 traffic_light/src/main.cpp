#include <Arduino.h>

const int RED = 15;
const int YELLOW = 16;
const int GREEN = 17;
const int BUTTON = 18;
bool pedestrianRequest = false;

// put function declarations here:
void buttonPressed();
void trafficMode();
void pedestrianMode();

void setup()
{
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  
  attachInterrupt(
    digitalPinToInterrupt(BUTTON),
    buttonPressed,
    FALLING
  );
}

void loop()
{
  if (pedestrianRequest)
  {
      pedestrianMode();
      pedestrianRequest = false;
      Serial.println("Traffic mode");
  }
  else {
  	trafficMode();
  }
}

void buttonPressed()
{
    pedestrianRequest = true;
}

void trafficMode()
{
  digitalWrite(GREEN, HIGH);
}

void pedestrianMode()
{
  Serial.println("Pedestrian mode");
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
  delay(5000);
  digitalWrite(RED, LOW);
}