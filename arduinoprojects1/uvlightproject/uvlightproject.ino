#include <Wire.h>
#include <LiquidCrystal.h>
#include "Adafruit_SI1145.h"
Adafruit_SI1145 uv = Adafruit_SI1145();
//setup for the LCD keypad shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{
 Serial.begin(9600);
 Serial.println("Adafruit SI1145 test");
 if (! uv.begin()) {
 Serial.println("Didn't find Si1145");
 while (1);
 }
 Serial.println("OK!");
 //init LCD
 lcd.begin(16,2);
 //line 1 - temperature
 lcd.setCursor(0,0);
 lcd.print("SI1145 test");
}

void loop()
{
 lcd.clear();
 lcd.setCursor(0,0);
 //display readings on lcd
 lcd.print("Vis: ");
 lcd.print(uv.readVisible());
 float UVindex = uv.readUV();
 UVindex /= 100.0;
 lcd.setCursor(0,1);
 lcd.print("UV: ");
 lcd.print(UVindex);
 delay(500);
}