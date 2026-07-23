void setup() {
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if( Serial.available() > 0)
  {
    String incomingstring = Serial.readString();
    incomingstring.trim();
    int input = incomingstring.toInt(); //Covert to Integer
    if( input>0 && input<6) //Check if value between 1 and 5
    {
      for (int i=0;i<input;i++) //For loop for running red led x number of times
      {
        digitalWrite(12,HIGH);
        delay(400);
        digitalWrite(12,LOW);
        delay(400);
      }
    }

    else //If value not in range
    {
      digitalWrite(13,HIGH);
      delay(400);
      digitalWrite(13,LOW);
    }
    
  }

}
