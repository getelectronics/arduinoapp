//This uses a library - https://github.com/arduinolearning/Arduino-Libraries/tree/master/GA1A12S202

#include <Wire.h>
#include <LiquidCrystal.h>
#include "GA1A12S202.h"

//setup for the LCD keypad shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

GA1A12S202 luxValue(A1);

void setup() 
{
  //init serial for some debug
  Serial.begin(9600);
  Serial.println("Light Sensor Test"); 

  //init LCD
  lcd.begin(16,2);
  //line 1 - temperature
  lcd.setCursor(0,0);
  lcd.print("Raw: ");
  lcd.setCursor(0,1);
  lcd.print("Lux: ");
}

void loop() 
{
  // put your main code here, to run repeatedly:

  lcd.setCursor(6,0);
  /* Display the results (light is measured in lux) */
  lcd.print(luxValue.getRaw());
  lcd.setCursor(6,1);
  lcd.print(luxValue.getLux());
  delay(500);
}


