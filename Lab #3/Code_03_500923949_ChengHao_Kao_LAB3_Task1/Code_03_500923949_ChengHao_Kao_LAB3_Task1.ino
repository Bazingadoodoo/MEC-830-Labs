#include<Servo.h>

Servo myservo;

const int button1 = 2;
const int button2 = 3;

int bv1 = 0;
int bv2 = 0;
int pos = 0;

void setup()
{
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  myservo.attach(9);
  myservo.write(45);
}

void loop()
{
  bv1 = digitalRead(button1);
  bv2 = digitalRead(button2);
  
  if (bv1 == LOW)
  {
    pos = pos+22;
    delay(100);
    myservo.write(pos);
  }
  else if (bv2 == LOW)
  {
    pos = pos-22;
    delay(100);
    myservo.write(pos);
  }
  else
  {
  }
}
