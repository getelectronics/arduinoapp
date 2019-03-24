//You need to add the adafruit sht31 library, this is available in the library manager

#include <Wire.h>
#include <LiquidCrystal.h>
#include "Adafruit_SHT31.h"

//setup for the LCD keypad shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() 
{
  //init serial for some debug
  Serial.begin(9600);
  Serial.println("Light Sensor Test"); 
  //init sht31
  if (! sht31.begin(0x44)) 
  {
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }
  //init LCD
  lcd.begin(16,2);
  //line 1 - temperature
  lcd.setCursor(0,0);
  lcd.print("Temp = ");
  //line 2 - humidity
  lcd.setCursor(0,1);
  lcd.print("Hum = ");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();
  //display temperature on lcd
  if (! isnan(t)) 
  {
    lcd.setCursor(0,0);
    lcd.print("Temp = "); 
    lcd.print(t);
  } 
  else 
  { 
    Serial.println("Failed to read temperature");
  }
  //display humidity on lcd  
  if (! isnan(h)) 
  {
    lcd.setCursor(0,1);
    lcd.print("Hum = ");
    lcd.print(h);
  } 
  else 
  { 
    Serial.println("Failed to read humidity");
  }
  Serial.println();
  delay(500);
}


