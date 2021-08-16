/*
Controlling a DC Brushed Motor with the L298N Motor Controller
 Brandon Tsuge

In this example, I demonstrate how to control a fairly common 6V gear motor with the L298N Motor Controller.
https://www.theboredrobot.com/post/controlling-a-dc-brushed-motor-with-the-l298n-motor-controller
 
 */

//Define the Pins of the potentiometer and the motor controller pins
#define PotPin A0
#define ENA1Pin 3
#define IN1Pin 4
#define IN2Pin 5

//Create variables for the pot and the speed of the motor
int PotVal;
int MotorSpeed;

void setup() {
  pinMode(ENA1Pin, OUTPUT);
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //read the value of the pot
  PotVal = analogRead(PotPin);

  //forward if statement
  if (PotVal >= 512){
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    MotorSpeed = map(PotVal, 512, 1023, 0, 118);
    analogWrite(ENA1Pin, MotorSpeed);

    Serial.print("Pot Value: ");
    Serial.print(PotVal);
    Serial.print("    ");
    Serial.print("Forward Motor Speed: ");
    Serial.println(MotorSpeed);
  }

  //motor in reverse statement
  else{
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    MotorSpeed = map(PotVal, 0, 512, 118, 0);
    analogWrite(ENA1Pin, MotorSpeed);

    Serial.print("Pot Value: ");
    Serial.print(PotVal);
    Serial.print("    ");
    Serial.print("Reverse Motor Speed: ");
    Serial.println(MotorSpeed);
  }
}
