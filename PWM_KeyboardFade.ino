void setup() {
  pinMode(9,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  if( Serial.available() > 0)
  {
    String incomingString = Serial.readString();
    incomingString .trim();
    keyboardinput(incomingString);
    int input= incomingString.toInt();
  int output_red=map(input,0,10,0,255);
  analogWrite(9,output_red);
}