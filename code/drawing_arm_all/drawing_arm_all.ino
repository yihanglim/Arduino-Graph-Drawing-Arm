#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int servo1 = 8;       // first servo
const int servo2 = 9;       // second servo
const int LDR = A0;
const int button = 5;
const int mic = A1;

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int pos1;      // angle of servo 1
int pos2;      // angle of servo2
int lightning;
int intensity;
int buttonstate;
int value;
int sound;
int loudness;
int i;
int distance = 0;
void setup() {

  // Servo  
 
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo
  myservo1.write(0);
  delay(500);
  myservo2.write(0);
  delay(500);
  pinMode(LDR, INPUT);
  pinMode(button, INPUT);
  pinMode(mic, INPUT);
  // Inizialize Serial
  Serial.begin(9600);

}

void loop(){

     // Scene 1: 
 for (int i=0; i<40; i += 1) {
 delay(50)
if (digitalRead(button) == 1){
  buttonpress();}
if (analogRead(LDR) > 200){
 lightSensor(); }
if (analogRead(mic) > 400){
  microphone(); }
if (unsigned int uS = sonar.ping() > 50) {
  ultrasonic(); }
   myservo1.write(pos1);
   myservo2.write(pos2); 
   delay(400);                        
 }
}
 
void buttonpress() {
 buttonstate = digitalRead(button);
 Serial.println(value);
 value = buttonstate * 10;
 if (i > 30){
    pos1 = 61 - (i+ value);
    pos2 = i*3;
  }
  else{
   pos1 = i + value;                   // servo1 from 0 to 180 degrees
   pos2 = i*3;
  }
 }

void lightSensor() {
  
 lightning = analogRead(LDR);
 intensity = map(lightning, 10,800, 0,30);
 Serial.println(lightning);
  if (i > 30){
    pos1 = 61 - (i+ intensity);
    pos2 = i*3;
  }
  else{
   pos1 = i+ intensity;                   // servo1 from 0 to 180 degrees
   pos2 = i*3;}
}

void microphone() {
  sound = analogRead(mic);
 loudness = map(sound, 100,800, 0,30);
 Serial.println(sound);
  if (i > 30){
    pos1 = 61 - (i+ loudness);
    pos2 = i*3;
  }
  else{
   pos1 = i+ loudness;                   // servo1 from 0 to 180 degrees
   pos2 = i*3;}
}

void ultrasonic(){
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  distance = map(uS / US_ROUNDTRIP_CM, 1, 200, 0, 30);
   if (i>30){
     pos1 = (61 - i + (distance));
     pos2 = i * 3;
    }
   else {
   pos1 = (i + (distance)); 
   pos2 = i * 3;
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
