//I downloaded and imported the following library - https://github.com/bluemurder/DS1624 This is the example so some of the hard graft has already been done for you 

#include <DS1624.h>

// Sensor presents all address pins connected to ground
DS1624 ds1624(0x00);

void setup()
{ 
// Begin serial connection at 9600 baud
Serial.begin(9600);
}

void loop()
{
float temperature;
bool valid;

// Get current temperature
ds1624.GetTemperature(temperature, valid);

// Print it
Serial.println(temperature);

// Wait a while
delay(1000);
}


