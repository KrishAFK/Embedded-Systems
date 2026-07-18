void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(2,INPUT);
  pinMode(A0,INPUT);
  
}

void emergency_ON() {
  analogWrite(9,255);
  analogWrite(10,255);
  analogWrite(11,255);
}

void emergency_OFF() {
  analogWrite(9,0);
  analogWrite(10,0);
  analogWrite(11,0);
}

void loop() {
  int pot_in = analogRead(A0);
  int rgb_input = map(pot_in,0,1023,0,255);
  analogWrite(11,rgb_input);
  attachInterrupt(digitalPinToInterrupt(2),emergency_ON,LOW);
  attachInterrupt(digitalPinToInterrupt(2),emergency_OFF,HIGH);
}
