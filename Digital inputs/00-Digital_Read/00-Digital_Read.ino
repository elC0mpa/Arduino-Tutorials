#include <Arduino.h>

#define BAUDRATE 9600
#define SECONDS 5
#define INPUT_PIN 10

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT_PULLUP);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  delay(SECONDS*1000);
  if (digitalRead(INPUT_PIN) == LOW)
    Serial.println("Digital signal detected");
}
