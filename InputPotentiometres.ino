#include <Arduino.h>

const int potPin1 = 2;    
const int potPin2 = 4;
const int butPin7 = 7;
const int ledPin = 13;

int val1 = 0;       
int val2 = 0;
int val3 = 0;
float analogRange = 1023.0;


void setup() {
  pinMode(ledPin, OUTPUT);  
  pinMode(butPin7, INPUT);
  Serial.begin(9600);
}

void loop() {
  val1 = analogRead(potPin1);
  val2 = analogRead(potPin2);
  Serial.print(val1);
  Serial.print(",");
  Serial.print(val2);
  Serial.print(",");

  val3 = digitalRead(butPin7);
  if (val3 == LOW) {
    Serial.println(1);
  } else {
    Serial.println(2);
  }
  delay(50);
}