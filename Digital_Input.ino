/*
 How to USE INPUT and INPUT_PULLUP on Arduino
 Brandon Tsuge

 This is a simple example that demonstrates how to use INPUT_PULLUP.
 The entire blog post can be found here:
 https://www.theboredrobot.com/post/how-to-use-input-and-input_pullup-on-arduino
 
 */

//assign variables names to what will be pins 2 and 3
#define Button1 2
#define Button2 3

void setup() {
  Serial.begin(9600);
  pinMode(Button1, INPUT); //set button 1 as and input
  pinMode(Button2, INPUT_PULLUP); //set button 2 as an input with the pullup resistor
  

}

void loop() {
  int Button1State = digitalRead(Button1); //read pin 2
  int Button2State = digitalRead(Button2); //read pin 3

  //print values
  Serial.print("Button 1 State: ");
  Serial.print(Button1State);
  Serial.print("\t");
  Serial.print("Button 2 State: ");
  Serial.println(Button2State);

  

}
