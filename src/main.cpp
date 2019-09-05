#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial800l(10,11);

void setup() {
  pinMode(3,OUTPUT);

  Serial800l.begin(9600);
  while (!Serial800l);
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  if (Serial800l.available())
  {
    String dado = Serial800l.readString();
    Serial.println(dado);
  }
  else if(Serial.available())
  {
    String dado = Serial.readString();
    Serial800l.println(dado);
  }
}