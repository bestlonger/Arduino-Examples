/*
 Reading Encoder values from a Brushed DC Motor
 Brandon Tsuge

This is sample code to run a single brushed DC motor with a built in rotary encoder.
I use an RC transmitter and receiver to control the speed of the motor.
I then read the encoder output values and print them to the serial montor.
You can find an explanation here: 
https://www.theboredrobot.com/post/using-a-dc-brushed-motor-with-rotary-encoder
 */

//define pin for reading RC Receiver
#define Ch3ReadPin 10

//define motor driver pins for motor
#define ENA1Pin 11 //PWM input
#define IN1Pin 9 //Direction logic pin
#define IN2Pin 8 //Direction logic pin

//define motor encoder pins
#define M1EncPin1 2
#define M1EncPin2 3

//define motor encoder counter variables
volatile long Counter1 = 0;
volatile long Counter2 = 0;

//RC PWM variables
unsigned long Ch3PWM = 0;
int tempCh3 = 0;
int Ch3Min = 9999;
int Ch3Max = 0;

//Motor output values
unsigned int M1Out = 0;

void setup() {
  Serial.begin(9600);
    
  //set RC pins to input
  pinMode(Ch3ReadPin, INPUT);

  //set motor driver pins to output
  pinMode(ENA1Pin, OUTPUT);
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);

  //setup to read encoder pins
  pinMode(M1EncPin1, INPUT_PULLUP);
  pinMode(M1EncPin2, INPUT_PULLUP);

  //Command to count as the motors rotate
  attachInterrupt(digitalPinToInterrupt(M1EncPin1),CountEncoder1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(M1EncPin2),CountEncoder2,CHANGE);
}

void loop() {
  //read the RC values
  Ch3PWM = pulseIn(Ch3ReadPin,HIGH);

  //Assign forward/reverse logic for motor controller.
  digitalWrite(IN1Pin,HIGH);
  digitalWrite(IN2Pin,LOW);

  //Calculate Min's and Max's for the RC Channel
  tempCh3 = pulseIn(Ch3ReadPin,HIGH);
  if (tempCh3 < Ch3Min){
    Ch3Min = tempCh3;
  }
  if (tempCh3 > Ch3Max){
    Ch3Max = tempCh3;
  }

  //write values to motor controller
  M1Out = map(Ch3PWM, Ch3Min, Ch3Max, 0, 255);
  analogWrite(ENA1Pin,M1Out); 

  //Print Statements
  Serial.print("Encoder 1 Count: ");
  Serial.print(Counter1);
  Serial.print("    ");
  Serial.print("Encoder 2 Count: ");
  Serial.print(Counter2);
  Serial.print("    ");
  Serial.print("Combined Encoder Count: ");
  Serial.println(Counter1 + Counter2);
}

//counting functions
void CountEncoder1(){
  Counter1 ++;
}

void CountEncoder2(){
  Counter2 ++;
}
