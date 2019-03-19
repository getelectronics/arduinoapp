int pinArray[] = {2, 3, 4, 5, 6, 7,8,9};
int count = 0;
int timer = 100;

void setup()
{
  for (count=0;count&lt;8;count++)
  {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop()
{
  for (count=0;count&lt;8;count++)
  {
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }

  for (count=7;count&gt;=0;count--)
  {
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
}
