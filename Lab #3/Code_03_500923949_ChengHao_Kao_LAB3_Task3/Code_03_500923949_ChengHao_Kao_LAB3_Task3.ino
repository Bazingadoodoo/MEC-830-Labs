#include<Stepper.h>
#include<Servo.h>
#include<Mouse.h>

#define STEPS 2048 
Stepper mystepper(STEPS,8,10,9,11);
Servo myservo;

const int xAxis = A0; 
const int yAxis = A1;

int step = 0;
int pos = 0;
int range = 12; 
int threshold = range / 4;
int center = range / 2;
int rpm = 0;

void setup()
{
  mystepper.setSpeed(15);
  myservo.attach(7);
  myservo.write(90);
}

void loop()
{
  int xReading = readAxis(A0);
  int yReading = readAxis(A1);
  
  if (xReading > 0)
  {
    pos = pos+45;
    delay(100);
    myservo.write(pos);
  }
  
  else if (xReading < 0)
  {
    pos = pos-45;
    delay(100);
    myservo.write(pos);
  }

  while(yReading > 0)
  {
    rpm = map(yReading, 0, 6, 0, 17);
    mystepper.setSpeed(rpm);
    mystepper.step(30);
    yReading = readAxis(A1);
  }

  while(yReading < 0)
  {
    rpm = map(yReading, 0, -6, 0, 17);
    mystepper.setSpeed(rpm);
    mystepper.step(-30);
    yReading = readAxis(A1);
  }
}

int readAxis(int thisAxis) 
{
  int reading = analogRead(thisAxis);
  reading = map(reading, 0, 1023, 0, range);
  int distance = reading - center;

  if (abs(distance) < threshold) 
  {
    distance = 0;
  }
  return distance;
}
