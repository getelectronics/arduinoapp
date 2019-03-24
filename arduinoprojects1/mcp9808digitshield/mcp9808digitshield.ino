//https://github.com/arduinolearning/Arduino-Libraries/blob/master/digitshieldlibrary.zip 

#include <Wire.h>
#include "Adafruit_MCP9808.h"
#include <DigitShield.h>

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

void setup()
{ 
  // initiliase the DigitShield
  DigitShield.begin();
  // Begin serial connection at 9600 baud for debug
  Serial.begin(9600);
  
  if (!tempsensor.begin()) 
  {
    Serial.println("Couldn't find MCP9808!");
    while (1);
  }
}

void loop()
{
  float c = tempsensor.readTempC();
  DigitShield.setPrecision(2);
  DigitShield.setValue(c);
  delay(250);
  // Wait a while
  tempsensor.shutdown_wake(1);
  delay(1000);
  tempsensor.shutdown_wake(0);
}


