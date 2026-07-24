void setup() {
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);

}
int pulse;
void loop() {
  if (Serial.available() > 0) 
  {
    String input = Serial.readString();
    input.trim();
    int value = input.toInt(); // Converting to Integer
    Serial.print("You Entered : ");
    Serial.print(value);
    Serial.println();
    attachInterrupt(digitalPinToInterrupt(2),changepulse,FALLING); // Run changepulse fncion on Falling edge of switch 2
    //delay(1000);
    
  
    for (int i=0;i<value;i++)
    {
      RED(pulse); // Run RED function for loop
    }

  }

}

void changepulse() {
  int pot_in = analogRead(A0); //Read value from Potentiometer
  pulse = map(pot_in,0,1023,100,1000); //Scale value to 100-1000
  
  Serial.print("New Pulse Length : ");
  Serial.print(pulse);
  Serial.println();
}


void RED(int pulse) {
  digitalWrite(13,OUTPUT);
  delay(pulse);
  digitalWrite(13,LOW);
  delay(pulse);
}