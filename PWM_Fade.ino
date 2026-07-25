void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Increasing Fade
  for( int i=0; i <= 255; i++)
  {
    analogWrite(11,i);
    delay(05);
  } 

  //Decreasing Fade
  for( int j=255; j >= 0; j--)
  {
    analogWrite(11,j);
    delay(05);
  } 
  
}
