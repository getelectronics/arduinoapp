#include <Arduino_FreeRTOS.h>

// define three tasks for Blink & LDR & VR
void TaskBlink( void *pvParameters );
void TaskLDR( void *pvParameters );
void TaskVR( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() 
{
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Now set up two tasks to run independently.
  xTaskCreate(
    TaskBlink
    ,  (const portCHAR *)"Blink"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  3
    ,  NULL );


  xTaskCreate(
    TaskVR
    ,  (const portCHAR *) "VR"
    ,  128  // Stack size
    ,  NULL
    ,  2  // Priority
    ,  NULL );
    
  xTaskCreate(
    TaskLDR
    ,  (const portCHAR *) "LDR"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*---------------------- Tasks ---------------------*/

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;


  // initialize digital LED_BUILTIN on pin 13 as an output.
  pinMode(12, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(12, LOW);   // turn the LED on
    Serial.println("LED 12 on");
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
    digitalWrite(12, HIGH);    // turn the LED off
    Serial.println("LED 12 off");
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
  }
}

void TaskLDR(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  

  for (;;)
  {
    // read the input on analog pin 1:
    int sensorValue = analogRead(A1);
    // print out the value you read:
    Serial.print("LDR value = ");
    Serial.println(sensorValue);
    vTaskDelay(20);  // one tick delay (300ms) in between reads for stability
  }
}

void TaskVR(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  

  for (;;)
  {
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
    // print out the value you read:
    Serial.print("VR value = ");
    Serial.println(sensorValue);
    vTaskDelay(20);  // one tick delay (300ms) in between reads for stability
  }
}

