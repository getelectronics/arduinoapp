int ledPin = 2; // we will use this variable later

// The setup() method runs once at startup
void setup()
{
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
}

// the loop() method repeats indefinitely
void loop()
{
  digitalWrite(ledPin, HIGH); //switch LED on - high
  delay(1000); //delay for 100 ms
  digitalWrite(ledPin, LOW); //switch LED off - low
  delay(1000); //delay for 100 ms
}
