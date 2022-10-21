#include<Servo.h>
#include<PID_v1.h>

#define echoPin 11
#define trigPin 12

const int button1 = 2;
const int button2 = 3;

int bv1 = 0;
int bv2 = 0;
int pos = 0;
int angle;

double Setpoint = 8.14;
double Input;
double Output = 0;
double Kp=0.01, Ki=30, Kd=0.03;

long duration;

Servo myservo;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  digitalWrite(trigPin, LOW);
  myservo.attach(9);
  myservo.write(42);
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd);
}

void loop()
{
  bv1 = digitalRead(button1);
  bv2 = digitalRead(button2);
  
  if (bv1 == LOW)           //CCW
  {
    Setpoint = Setpoint + 0.1;
    delay(20);
  }
  else if (bv2 == LOW)      //CW
  {
    Setpoint = Setpoint - 0.1;
    delay(20);
  }
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Input = duration * 0.0385 / 2;
 
  myPID.Compute();
  angle = round(Output);
  myservo.write(angle);
  
  Serial.print(Input);
  Serial.print(",");
  Serial.println(Setpoint);
  
}
