#include <Arduino.h>

int const LED_1 = 15;
int const LED_2 = 16;
int const LED_3 = 18;
int const LDR = 4;
int const THRESHOLD1 = 2000;
int const THRESHOLD2 = 800;


void setup() {
  Serial.begin(115200);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop() {
  int light = analogRead(LDR);
  Serial.println(light);

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, light > THRESHOLD2 ? HIGH : LOW);
  digitalWrite(LED_3, light > THRESHOLD1 ? HIGH : LOW);

  delay(100);
}
