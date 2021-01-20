#include <Arduino.h>
#include <Servo.h>

// Motor 1
int motorPin1  = 5; // Pin 14 of H-bridge
int motorPin2  = 6; // Pin 10 of H-bridge

// Motor 2
int motorPin3  = 10; // Pin  7 of H-bridge
int motorPin4  = 9;  // Pin  2 of H-bridge

// Servo motor
int servoPin = 3;
Servo Servo1;

// Signal horn
int signalHornPin = 13;

// Backlight
int ledPin = 12;

// Button
int signalHornButtonPin = 4;

int forwardButtonPin = 2;

int reverseButtonPin = 11;

int leftButtonPin = 7;

int rightButtonPin = 8;




void setup(){
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(ledPin, OUTPUT); 
    pinMode(signalHornPin,OUTPUT);
    pinMode(signalHornButtonPin,INPUT);
    pinMode(forwardButtonPin, INPUT);
    pinMode(reverseButtonPin, INPUT);
    pinMode(leftButtonPin, INPUT);
    pinMode(rightButtonPin, INPUT);
    Serial.begin(9600);
    Servo1.attach(servoPin);
}

// Right Motor 
void rightMotorForward() {
   digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void rightMotorReverse() {
   digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}

// Left Motor
void leftMotorForward() {
   digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void leftMotorReverse() {
   digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

// Backlight: when the reverse button is pressed down, the warning light for reverse is lit.
void turnBackLightOn() {
  digitalWrite(ledPin, HIGH);
}

void turnBackLightOff() {
  digitalWrite(ledPin, LOW);
}


// Movement
void forward() {
  leftMotorForward();
  rightMotorForward();
  Servo1.write(90); 
}

void reverse() {
  leftMotorReverse();
  rightMotorReverse();
  Servo1.write(90);
}

// Rotate power steering 90 degrees
void right() {
  Servo1.write(0);
}

// Rotate power steering 90 degrees
void left() {
  Servo1.write(180);
}

void stop() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  Servo1.write(90);
  turnBackLightOff();
}


// loop
void loop(){

  // Check forward button. If pressed, call forward()
  if(digitalRead(forwardButtonPin) == HIGH) {
   turnBackLightOff();
   forward();
   }

  // To stop both motors, a combination off pressing down two buttons (forward and reverse) is used
  if(digitalRead(forwardButtonPin) == HIGH && digitalRead(reverseButtonPin) == HIGH){
   stop();
   delay(2000);
   }
  
  // Check signal horn button. If pressed, set pin for signal horn to HIGH. If not pressed, set pin for signal horn to LOW
  if(digitalRead(signalHornButtonPin) == HIGH) {
   digitalWrite(signalHornPin, HIGH);
   }
   else {
   digitalWrite(signalHornPin, LOW);
   }

  // Check reverse button. If pressed, call turnBackLightOn() and reverse()
  if(digitalRead(reverseButtonPin) == HIGH) {
   turnBackLightOn();
   reverse();
   }
   
  // Check left button. If pressed, call left()
  if(digitalRead(leftButtonPin) == HIGH) {
   left();
   }

  // Check right button. If pressed, call right()
  if(digitalRead(rightButtonPin) == HIGH) {
   right();
   }
  
}

