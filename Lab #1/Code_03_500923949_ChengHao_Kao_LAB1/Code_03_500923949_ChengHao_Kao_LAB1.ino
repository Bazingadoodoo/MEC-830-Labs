int x;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();
  Serial.print(x);
  if (x == 954)
  {
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    delay(1000);
    digitalWrite(6,LOW);
    delay(1000);
  }
  else if (x == 963)
  {
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(7,LOW); 
    delay(1000);
  }
}
