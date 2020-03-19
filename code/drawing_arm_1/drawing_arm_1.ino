#include <Servo.h>

const int servo1 = 8;       // first servo
const int servo2 = 9;       // second servo

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo


int pos1;      // angle of servo 1
int pos2;      // angle of servo2

void setup() {

  // Servo  
 
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo
  myservo1.write(0);
  delay(500);
  myservo2.write(0);
  delay(500);

  // Inizialize Serial
  Serial.begin(9600);

}

void loop(){

     // Scene 1: 
 for (int i=0; i<40; i += 1) {
 
  if (i > 30){
    pos1 = 61 - (i);
    pos2 = i*3;
  }
  else{
   pos1 = i;                   // servo1 from 0 to 180 degrees
   pos2 = i*3;
  }   // servo2 turns slower
   myservo1.write(pos1);
   myservo2.write(pos2); 
   delay(400);                           // waits for the servo to get there   
 }
}



/*
    // Scene 2 
 for (int i=0; i<60; i += 1) {
   pos1 = 45;                  // servo1 doesn't move
   pos2 = 90 + i;              // servo2 from 90 to 150 degrees
   servo1.write(pos1);
   servo2.write(pos2); 
   delay(15);                           // waits for the servo to get there 
 }
} 
*/
