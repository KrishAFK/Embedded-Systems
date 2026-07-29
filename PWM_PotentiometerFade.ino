void setup() {
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);

}

void loop() {
  int pot_in = analogRead(A0);
  int output=map(pot_in,0,1023,0,100);
  analogWrite(10,output);
}
