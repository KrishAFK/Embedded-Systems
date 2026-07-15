
String incomingString;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  
  if (Serial.available() > 0)
  {
    incomingString = Serial.readString();
    incomingString .trim();
    if (incomingString == "b")
    {
      digitalWrite(13,HIGH);
      delay(1000);
      digitalWrite(13,LOW);
    }
    if (incomingString == "B")
    {
      digitalWrite(12,HIGH);
      delay(1000);
      digitalWrite(12,LOW);
    }
  }

}
