//You will need to install the Adafruit GXX and PCD8544 libraries and https://github.com/EngDial/AM2320 for the sensor

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Wire.h>
#include <AM2320.h>


// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(2, 3, 4, 5, 6); //dfrobot lcd4884 shield

#define XPOS 0
#define YPOS 1
#define DELTAY 2

AM2320 th;

void setup()   
{
  Serial.begin(9600);
  Wire.begin();             // join i2c bus (address optional for master) 
  display.begin();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);
  display.clearDisplay();   // clears the screen and buffer
  // text display tests
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.println("AM2302 TEST");
  display.display();
  delay(1000);

}

 
void loop() 
{

    // Display temperature
    display.setTextColor(BLACK, WHITE); // 'inverted' text
    Serial.println("Chip = AM2320");
    display.setCursor(0,0);
    switch(th.Read()) 
    {
      case 2:
        display.println(" CRC failed");
        break;
      case 1:
        display.println(" Sensor offline");
        break;
      case 0:
        display.setCursor(0,15);
        display.print("Humi = ");
        display.print(th.Humidity);
        display.println("%");
        display.setCursor(0,30);
        display.print("Temp = ");
        display.print(th.cTemp);
        display.println("C");
        display.println();
        break;
    }
    display.display();
    delay(1000);
}


