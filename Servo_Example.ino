/*
 How to Create Control a Servo with Arduino
 Brandon Tsuge

 This is an example that demonstrates how to read values from a potentiometer, or sensor and map them to a servo output. This sketch also prints out the PWM pulse width and Duty Cycle
https://www.theboredrobot.com/post/how-to-control-a-servo-with-arduino
 
 */

//include the servo library
#include <Servo.h>

//define the pins for the sensor input, servo output, and the sensor reading the pulse from the servo output
#define SensorPin A0
#define ServoPin 3
#define PulsePin 4

//create a servo object
Servo Servo1;

//initialize variables
int pos = 0;
int SensorVal = 0;
float PulseLength = 0.0;
const float Period = 0.02; // 1/50Hz = 0.02 seconds

void setup() {
  Servo1.attach(ServoPin); //attach the servo to the pin
  pinMode(PulsePin, INPUT); //set pin 4 to and input
  Serial.begin(9600);
}

void loop() {
  //read the potentiometer, map to 0-180, write it to the servo
  SensorVal = analogRead(SensorPin);
  pos = map(SensorVal, 0, 1023, 0, 180);
  Servo1.write(pos);

  PulseLength = pulseIn(PulsePin, HIGH); //measure the time that the PWM signal is in the HIGH position in microseconds
  DutyCycle = ((PulseLength / pow(10,6)) / Period) * 100; //convert pulse length to a duty cycle in percent

  //print statements
  Serial.print("Servo Angle (°): ");
  Serial.print(pos);
  Serial.print("    ");
  Serial.print("Pulse Length (µs): ");
  Serial.print(PulseLength);
  Serial.print("    ");
  Serial.print("Duty Cycle (%): ");
  Serial.println(DutyCycle);
  

}
