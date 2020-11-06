/*
  How to Read Analog Sensors with Arduino
 Brandon Tsuge

 This is an example that demonstrates how to read three different types of analog sensors.
 The entire blog post can be found here:
 https://www.theboredrobot.com/post/how-to-read-analog-sensors-with-arduino
 
 */


//define the analog input pins
const int PotPin = A0;
const int LightPin = A1;
const int TempPin = A2;

void setup() {
 Serial.begin(9600);

}

void loop() {
  // read the values from the three analog pins
  int PotVal = analogRead(PotPin);
  int LightVal = analogRead(LightPin);
  int TempVal = analogRead(TempPin);

  //convert to volts
  float PotVolts = (PotVal / 1024.0) * 5.0;
  float LightVolts = (LightVal / 1024.0) * 5.0;
  float TempVolts = (TempVal / 1024.0) * 5.0;

  //convert to temperature
  float Temperature = (TempVolts - 0.5) * 100;

//  Serial.println(PotVal);

  //print the values
  Serial.print(PotVolts);
  Serial.print("     ");
  Serial.print(LightVolts);
  Serial.print("     ");
  Serial.print(TempVolts);
  Serial.print("     ");

  Serial.print("Temperature: ");
  Serial.print(Temperature);
  Serial.println("°C");


  delay(100);

}
