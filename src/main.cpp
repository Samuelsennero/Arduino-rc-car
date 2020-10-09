#include <Arduino.h>

 int motorPin3  = 10; // Pin  7 of L293
 int motorPin4  = 9;  // Pin  2 of L293

void setup(){
  
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    Serial.begin(9600);
}


void clockwise() {
   digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);

}

void counter_clockwise() {
   digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);

}

void stop() {
   digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);

}

void loop(){
  clockwise();
  delay(4000);
  counter_clockwise();
  delay(4000);

}

