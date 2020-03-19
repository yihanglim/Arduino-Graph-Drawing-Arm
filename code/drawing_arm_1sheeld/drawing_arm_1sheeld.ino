/* Include 1Sheeld library. */
#include <OneSheeld.h>

#include <Servo.h>

const int servo1 = 8;       // first servo
const int servo2 = 9;       // second servo

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

int pos1;      // angle of servo 1
int pos2;      // angle of servo2
int buttonstate = 0;

void setup() {

  // Servo  
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo
  myservo1.write(0);
  delay(500);
  myservo2.write(0);
  delay(500);

  // Inizialize Serial
  Serial.begin(115200);

}

void loop(){

   myservo1.write(map(abs(OrientationSensor.getX()),200,300,100,30));
   myservo2.write(map(abs(OrientationSensor.getY()),0,50,100,30));
   delay(500);                           // waits for the servo to get there 

 }

