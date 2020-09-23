/*
  Arduino Digital Output and "if" Statements
 Brandon Tsuge

 This is a simple example that demonstrates how to use Digital Output and "if" Statements
 The entire blog post can be found here:
 https://www.theboredrobot.com/post/arduino-digital-output-and-if-statements
 
 */


//assign variables names to what will be pins 2 and 3
//assign the pins for the two LED's
#define Button1 2
#define Button2 3
#define LED1 8
#define LED2 9

void setup() {
  Serial.begin(9600);
  pinMode(Button1, INPUT); //set button 1 as and input
  pinMode(Button2, INPUT_PULLUP); //set button 2 as an input with the pullup resistor
  pinMode(LED1, OUTPUT); //set LED1 as and output
  pinMode(LED2, OUTPUT); //set LED2 as and output
}

void loop() {
  int Button1State = digitalRead(Button1); //read pin 2
  int Button2State = digitalRead(Button2); //read pin 3

//turn LED1 on and off based on the first push button
  if (Button1State == HIGH){
    digitalWrite(LED1, HIGH);
  }
  else if (Button1State == LOW){
    digitalWrite(LED1, LOW);
  }

//turn LED2 on and off based on the second push button
  if (Button2State == HIGH){
    digitalWrite(LED2, HIGH);
  }
  else{
    digitalWrite(LED2, LOW);
  }

//Setup the LED's to alternate and flash if both buttons are pushed.
  if (Button1State == HIGH && Button2State == LOW){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(250);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(250);
  }

  //print values
  Serial.print("Button 1 State: ");
  Serial.print(Button1State);
  Serial.print("\t");
  Serial.print("Button 2 State: ");
  Serial.println(Button2State);

  

}
