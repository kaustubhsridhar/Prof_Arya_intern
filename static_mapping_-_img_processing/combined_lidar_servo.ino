#include <Wire.h>
#include "LIDARLite.h"
#include<Servo.h>
Servo myservo;
LIDARLite myLidarLite;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);  // attaches the servo on pin 9 to the servo object
Serial.begin(115200); // Initialize serial connection to display distance readings
myLidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
myLidarLite.configure(0); // Change this number to try out alternate configurations

}
int pos = 0; 
void loop() {
myservo.write(0);
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
myservo.write(pos);  // tell servo to go to position in variable 'pos'
// Take a measurement with receiver bias correction and print to serial terminal


Serial.println(myLidarLite.distance());

// Take 19 measurements without receiver bias correction and print to serial terminal
for(int i = 0; i < 19; i++)
  {
    
  Serial.println(myLidarLite.distance(false));

  }

delay(10);                       // waits 100ms for the servo to reach the position
}
  while(1){}
}
