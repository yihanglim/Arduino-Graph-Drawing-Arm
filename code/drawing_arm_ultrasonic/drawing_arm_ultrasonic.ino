#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int servo1 = 8;       // first servo
const int servo2 = 9;       // second servo
const int servo3 = 10;       // third servo

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int pos1;      // angle of servo 1
int pos2;      // angle of servo2

int distance = 0;

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

 for (int i=0; i<40; i += 1) {
   
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  distance = map(uS / US_ROUNDTRIP_CM, 1, 30, 0, 30);
   if (i>30){
     pos1 = (61 - i + (distance));
     pos2 = i * 3;
    }
   else {
   pos1 = (i - (distance)); 
   pos2 = i * 3;
   }
   myservo1.write(pos1);
   myservo2.write(pos2); 
   delay(500);                           // waits for the servo to get there   
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
