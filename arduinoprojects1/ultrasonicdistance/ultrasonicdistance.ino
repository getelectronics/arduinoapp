#include <Wire.h>
#include <LiquidCrystal.h>

//setup for the LCD keypad shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const int TRIG_PIN = 2;
const int ECHO_PIN = 3;

void setup()
{
 pinMode(TRIG_PIN,OUTPUT);
 pinMode(ECHO_PIN,INPUT);
 //init LCD
 lcd.begin(16,2);
 //line 1 - Distance
 lcd.setCursor(0,0);
 lcd.print("Distance");
}

void loop()
{
   long duration, distanceCm, distanceIn;
   digitalWrite(TRIG_PIN, LOW);
   delayMicroseconds(2);
   digitalWrite(TRIG_PIN, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG_PIN, LOW);
   duration = pulseIn(ECHO_PIN,HIGH);
   // convert the time into a distance
   distanceCm = duration / 29.1 / 2 ;
   distanceIn = duration / 74 / 2;
   lcd.setCursor(0,0);
   //display message if readings are less than 0
   if (distanceCm <= 0)
   {
     lcd.print(distanceCm);
     lcd.print("???");
   }
   else
   {
   //display readings on lcd
     lcd.clear();
     lcd.print("Distance: ");
     lcd.print(distanceCm);
     lcd.print("cm");
   }
   lcd.print("");
   delay(500);
}
