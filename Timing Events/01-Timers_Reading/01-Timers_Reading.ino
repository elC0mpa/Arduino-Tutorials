#include <Arduino.h>

#define BAUDRATE 9600
#define SECONDS 3

unsigned long lastMillisValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  lastMillisValue = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long difference = millis() - lastMillisValue;
  if (difference >= SECONDS*1000)
  {
    Serial.println(String(difference) + " milliseconds ellapsed");
    lastMillisValue = millis();
  }
  while (Serial.available())
  {
    auto str = Serial.readString();
    Serial.println(str);
  }
}
