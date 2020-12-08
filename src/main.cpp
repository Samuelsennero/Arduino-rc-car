#include <Arduino.h>
 // Motor 1
 int motorPin1  = 5; // Pin 14 of H-bridge
 int motorPin2  = 6; // Pin 10 of H-bridge
 // Motor 2
 int motorPin3  = 10; // Pin  7 of H-bridge
 int motorPin4  = 9;  // Pin  2 of H-bridge

void setup(){
  
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    Serial.begin(9600);
}

// Motor 1
void Motor1Clockwise() {
   digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void Motor1CounterClockwise() {
   digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}


// Motor 2
void Motor2Clockwise() {
   digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void Motor2CounterClockwise() {
   digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void stopMotors() {
   digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}

// loop.

void loop(){
  Motor1Clockwise();
  Motor2Clockwise();
  delay(3000);
  Motor1CounterClockwise();
  Motor2CounterClockwise();
  delay(3000);

  
}

