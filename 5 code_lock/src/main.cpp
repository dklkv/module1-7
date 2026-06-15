#include <Arduino.h>
#include <Bounce2.h>

constexpr int RED = 16;
constexpr int GREEN = 18;
constexpr int BUTTON_A = 4;
constexpr int BUTTON_B = 13;
constexpr char CODE[4] = {'A', 'B', 'B', 'A'};
constexpr int INPUT_MAX = 4;

char input[INPUT_MAX];
int inputSize = 0;
Bounce buttonA;
Bounce buttonB;

void press(char letter);
bool check();
void blink(int pin);

void setup()
{
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUTTON_A, INPUT_PULLUP);
  buttonA.attach(BUTTON_A);
  buttonA.interval(20);

  pinMode(BUTTON_B, INPUT_PULLUP);
  buttonB.attach(BUTTON_B);
  buttonB.interval(20);
}

void loop()
{
    buttonA.update();
    buttonB.update();

    if (buttonA.fell()) {
      press('A');
    }

    if (buttonB.fell()) {
      press('B');
    }
}

void press(char letter) {
  input[inputSize] = letter;
  inputSize++;

  if (inputSize == INPUT_MAX) {
    blink(check() ? GREEN : RED);
  }
}

bool check() {
  return memcmp(CODE, input, INPUT_MAX) == 0;
}

void blink(int pin) {
  if (pin == RED) {
    Serial.println("Wrong code");
  }

  if (pin == GREEN) {
    Serial.println("Open");
  }

  for (int i = 0; i < 3; i++) {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
  }

  inputSize = 0;
}
