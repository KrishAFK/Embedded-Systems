int counter = 0;
void setup() {
  pinMode(13,OUTPUT);// put your setup code here, to run once:
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  Serial.println(counter);
  if (digitalRead(2) == HIGH)
  {
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    delay(100);
    digitalWrite(9,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    delay(100);
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
  }
 
}