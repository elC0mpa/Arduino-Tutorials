#include <Arduino.h>
#include <TimerOne.h>

#define BAUDRATE 9600
#define SECONDS 3

void timeEllapsed()
{
  Serial.println("Time ellapsed");
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  Timer1.initialize(SECONDS*1000000);
  Timer1.attachInterrupt(timeEllapsed);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available())
  {
    auto str = Serial.readString();
    Serial.println(str);
  }
}
