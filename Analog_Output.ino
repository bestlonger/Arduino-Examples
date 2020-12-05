/*
 How to Create an Analog Signal with Arduino
 Brandon Tsuge

 This is an example that demonstrates how to read three potentiometers, and map those inputs to be used as analog outputs for an RGB LED.
 https://www.theboredrobot.com/post/how-to-create-an-analog-signal-with-arduino
 
 */

//define analog pins for potentiometers.
#define RedPotPin A0
#define BluePotPin A1
#define GreenPotPin A2

void setup() {
  Serial.begin(9600);

  //set pins 9-11 as outputs.
  for (int i = 9; i <= 11; i++){
    pinMode(i, OUTPUT);
  }

    //redundant code to demonstrate how a "while" loop can be used instead of a "for" loop.
//  int i = 9;
//  while (i <= 11){
//    pinMode(i, OUTPUT);
//    i++;
//  }


}

void loop() {
  //read potentiometer values.
  int RedVal = analogRead(RedPotPin);
  int BlueVal = analogRead(BluePotPin);
  int GreenVal = analogRead(GreenPotPin);

  //map potentiometers values to that they can be used with the "analogWrite" command
  int RedOut = map(RedVal, 0, 1024, 0, 255);
  int BlueOut = map(BlueVal, 0, 1024, 0, 255);
  int GreenOut = map(GreenVal, 0, 1024, 0, 255);

  //write the values to pins 9-11.
  analogWrite(11, RedOut);
  analogWrite(10, BlueOut);
  analogWrite(9, GreenOut);

  //print statements.
  Serial.print(RedVal);
  Serial.print("    ");
  Serial.print(BlueVal);
  Serial.print("    ");
  Serial.println(GreenVal);
  delay(100);


}
