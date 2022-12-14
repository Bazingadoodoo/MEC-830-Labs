int ledPin = 13;
int sensorPin = 2;
int sensorValue;
int lastTiltState = HIGH; 

long lastDebounceTime = 0; 
long debounceDelay = 50; 

void setup()
{
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  sensorValue = digitalRead(sensorPin);

  if (sensorValue == lastTiltState)    
  {
    lastDebounceTime = millis(); 
  }
  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
    lastTiltState = sensorValue;     
  }
  
  digitalWrite(ledPin, lastTiltState);
  delay(500);
}
