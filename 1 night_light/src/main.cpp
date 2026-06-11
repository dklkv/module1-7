#include <Arduino.h>

int LED = 18;
int LDR = 4;
int THRESHOLD = 800;


void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  int light = analogRead(LDR);
  Serial.println(light);
  
  if (light < THRESHOLD) {
  	digitalWrite(LED, HIGH);
  }
  else {
   	digitalWrite(LED, LOW); 
  }

  delay(100);
}
