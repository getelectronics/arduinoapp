const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int PWMOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup()
{
}

void loop()
{
// read the analog in value:
sensorValue = analogRead(analogInPin);
// map it to the range of the analog out:
outputValue = map(sensorValue, 0, 1023, 0, 255);
// change the analog out value:
analogWrite(PWMOutPin, outputValue);
// wait 2 milliseconds for the a/d converter to settle
delay(2);
}