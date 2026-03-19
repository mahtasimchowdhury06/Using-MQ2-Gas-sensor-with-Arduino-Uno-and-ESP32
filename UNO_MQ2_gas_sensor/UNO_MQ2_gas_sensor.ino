/* Change the threshold value with your own reading */
#define Threshold 400

#define MQ2pin 0
#define MQ2pin1 8

int sensorValue1;  //variable to store sensor value

float sensorValue;  //variable to store sensor value

void setup() {
	Serial.begin(9600); // sets the serial port to 9600
	Serial.println("MQ2 warming up!");
	delay(20000); // allow the MQ2 to warm up
}

void loop() {
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  sensorValue1 = digitalRead(MQ2pin1); // read digital output pin
	Serial.print("Digital Output: ");
	Serial.print(sensorValue1);

  if(sensorValue > Threshold)
  {
    Serial.print(" | Smoke detected!");
  }
  else{
    Serial.println("  |  Smoke: -");
  }
  
  Serial.println("");
  delay(2000); // wait 2s for next reading
}