# Rc car

## About the project

### The creator
The creator of this project is me, an 18 years old student from sweden. I am currently studying at *Tullinge gymnasium* and this is my last year here. As a part of *Teknik 2* we have been working with arduinos in the last couple of months. Our mission was to do a project on our own, working with an arduino.

### The Project
This project was supposed to be an radio-controlled car, this isn't exactly the case. My car is controlled by a wire. The reason for this is because most of the bluetooth transmitters on the market is only capable with androids. I therefore choosed to controll my car with a wire leading to an old phone with buttons. I opened up the phone and linked the buttons to the arduino. When I for example press the 2 button on the phone, my car drives forward. I have five different commands on the phone, forward, reverse, left, right and a signal horn. The signal horn plays a melody when the button is pushed in on the phone, this is possible because the button is linked to a speaker on the car. To be able to turn left and right I have a servo motor. I destroyed an old rc car I hade laying around, I took out the servo motor and with hard work I managed to rebuild it to match with my own servo motor. The servo motor rotates between 90 to 0 and 90 to 180. You can steer left and right even when the car goes backwards. When you press the button going backwards, a red led diode also starts to shine at the back of the car. To stop the car, you press the forward and reverse button at the same time. I use a H-bridge, which is an electronic circuit that swtiches the polarity of a voltage applied to a load, to be able to make the motors going both forward and backward.

### The code
My code starts with including *Arduino.h* and *Servo.h* which is two libraries. Libraries provides extra funtionality for use in sketches. I then declare which pins in my arduino the motors and buttons should go into. Then I use pinMode() to configure the specified pin to behave either as an input or output. To be able to write a HIGH or LOW value to a digital pin I use digitalWrite(). Then I use *void* in function declarations, that indicates that the function is expected to return no information to the function from which it was called. This makes it possible for me to set different pins to either HIGH or LOW when the function is called at later. In the void loop I then make If statements that checks if the buttons are pushed down or not. If the button for forward is pushed down for example the pins to make the motor rotate forwards sets to HIGH. When another button then gets pushed down the forward part stops because the If statements clarify for it to just work when the forward button is pushed down. 

### The components you will need for this project
* Arduino Uno
* 2 Breadbords
* L293D Motor Driver IC
* 2x DC Motors
* Servo Motor
* 6 Resistors
* Red diode
* A bunch of wires

## Circuit diagram
![Image of Circuit diagram](https://github.com/Samuelsennero/Arduino-rc-car/blob/master/Images/kretsschema.jpg)

## 3D printed chassi
As a part of this project I also made a chassi to my car in *Fusion 360*. Unfortunately the 3D printer I was thinking to print it with didn't work. But the file got finished and you can see in the picture below what it looks like.

![Image of 3D printed chassi](https://github.com/Samuelsennero/Arduino-rc-car/blob/master/Images/CAD%20bil.JPG)

## Video of the car in action
[Youtube](https://youtu.be/RniXZ4N8NiE)
