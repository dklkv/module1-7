#include <Arduino.h>
#include <vector>

int const LDR = 4;
float const EMA_COEFFICIENT = 0.2;

std::vector <int> ma;
float ema = NAN;

float average();
float exponentialAverage(int noisy);

void setup() {
  Serial.begin(115200);
  randomSeed(micros());
}

void loop() {
  int light = analogRead(LDR);
  int noisy = constrain(light + random(-200, 201), 0, 4095);

  ma.push_back(noisy);
  if (ma.size() > 5) {
    ma.erase(ma.begin());
  }

  if (isnan(ema)) {
    ema = noisy;
  }

  ema = exponentialAverage(noisy);

  Serial.print(light);
  Serial.print(" ");
  Serial.print(noisy);
  Serial.print(" ");
  Serial.print(average());
  Serial.print(" ");
  Serial.println(ema);

  delay(100);
}

float average() {
  int sum = 0;

  for (int v : ma) {
    sum += v;
  }

  return (float) sum / ma.size();
}

float exponentialAverage(int noisy)
{
  return EMA_COEFFICIENT * noisy + (1 - EMA_COEFFICIENT) * ema;
}
