void setup() {
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(A0,INPUT);

}

void loop() {
  if( digitalRead(2) == LOW)
  {
    int pot_in_red = analogRead(A0);
    int output_red=map(pot_in_red,0,1023,0,100);
    analogWrite(9,output_red);
  }

  if( digitalRead(2) == HIGH)
  {
    analogWrite(9,0);
  }

  if( digitalRead(3) == LOW)
  {
    int pot_in_green = analogRead(A0);
    int output_green=map(pot_in_green,0,1023,0,100);
    analogWrite(10,output_green);
  }

  if( digitalRead(3) == HIGH)
  {
    analogWrite(10,0);
  }

}

