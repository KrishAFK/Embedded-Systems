void setup() {
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  Serial.println("Please enter a character:");

  while (Serial.available() == 0) {
  }

  char incomingChar = Serial.read();
  Serial.print("You entered: ");
  Serial.println(incomingChar);
  Serial.println();

  while (Serial.available() > 0)
  {
    Serial.read();
    delay(2);
  }

  delay(1000);
  Serial.println("Please enter a word:");

  while (Serial.available() == 0) {
  }

  String incomingstr = Serial.readString();
  incomingstr.trim();
  Serial.print("You entered: ");
  Serial.println(incomingstr);
  Serial.println();
 
 delay(2000);
}
