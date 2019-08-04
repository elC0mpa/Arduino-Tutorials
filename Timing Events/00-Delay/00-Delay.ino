#include <Arduino.h>

#define BAUDRATE 9600
#define SECONDS 1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(SECONDS*1000);
  Serial.println("Do Something");
}
