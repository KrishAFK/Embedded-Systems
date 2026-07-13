
  unsigned long time;
  unsigned long pushbutton;
  unsigned long lastpulse;
  unsigned long reaction;
  #define timebetweenpulses 3000
  #define pulseduration 1000

void setup() {
  pinMode(2,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),reactionISR,FALLING);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  lastpulse = millis();
}

void loop() {
  time=millis();
  if (time >= lastpulse + timebetweenpulses)
  {
  pulseLED(12);
  lastpulse = time;
  }

  if (pushbutton > 0){
    reaction = pushbutton - lastpulse;
    pushbutton=0;
    Serial.println(reaction + String(" Milliseconds"));
  }

}

void reactionISR(){
  pushbutton = millis();
}

void pulseLED(int pin){
  digitalWrite(pin,HIGH);
  delayMicroseconds(pulseduration);
  digitalWrite(pin,LOW);

}
