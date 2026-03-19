

#define DO_PIN 12  // ESP32's pin GPIO14 connected to DO pin of the MQ2 sensor
#define AO_PIN 13

void setup() {
  // initialize serial communication
  Serial.begin(112500);
  // initialize the ESP32's pin as an input
  pinMode(DO_PIN, INPUT);
  pinMode(AO_PIN, INPUT);

  Serial.println("Warming up the MQ2 sensor");
  delay(20000);  // wait for the MQ2 to warm up
}

void loop() {
  int gasState = digitalRead(DO_PIN);

  if (gasState == HIGH)
    Serial.println("The gas is NOT present");
  else
    Serial.println("The gas is present");
    delay(1000);

     int gasValue = analogRead(AO_PIN);

  Serial.print("MQ2 sensor AO value: ");
  Serial.println(gasValue);
  delay(1000);
}
