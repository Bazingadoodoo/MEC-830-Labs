#include<Stepper.h>

Stepper mystepper(2048,8,10,9,11);

const int button1 = 2;
const int button2 = 3;

int bv1 = 0;
int bv2 = 0;
int step = 0;

void setup()
{
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  mystepper.setSpeed(15);
}

void loop()
{
  bv1 = digitalRead(button1);
  bv2 = digitalRead(button2);
  
  if (bv1 == LOW)
  {
    mystepper.step(256);
    delay(100);
  }
  else if (bv2 == LOW)
  {
    mystepper.step(-256);
    delay(100);
  }
  else
  {
  }
}
