#include <Arduino.h>

#define BAUDRATE 9600
#define SECONDS 5
#define INTERRUPT_PIN 2

volatile bool isDetected;

void signalDetected()
{
  isDetected = true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  if (digitalPinToInterrupt(INTERRUPT_PIN) == NOT_AN_INTERRUPT)
  {
    Serial.println("This pin is not asociated to an external interrupt");
    while (true);    
  }
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), signalDetected, FALLING);
  isDetected = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000*SECONDS);
  if (isDetected)
  {
    Serial.println("Digital signal detected");
    isDetected = false;
  }
}
