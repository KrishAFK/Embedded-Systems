#define RED_LED 12            // RED LED PIN
#define BLUE_LED 13           // BLUE LED PIN
#define POTENTIOMETER A0      // POTENTIOMETER INPUT
#define RGB_BLUE 11           // BLUE RGB/PWM PIN
bool warning = false;         // WARNING FLAG FOR TASK 3 TO STOP INFINITE OUTPUTS
bool flag2 = false;           // FLAG FOR TASK 4 TO STOP LOOP OF PWM 
int last_pot_in = -1;         // TO NOTICE CHANGE IN POTENTIOMETER VALUE FOR TASK 3
int count = 0;                // TO COUNT NUMBER OF PRESSES IN TASK 4

void setup() {
  pinMode(RED_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  pinMode(POTENTIOMETER,INPUT);
  Serial.begin(9600);
}

// Task 1 - Function to Read the character
void ReadingChar() {
  Serial.println("Please enter a character:");

  while (Serial.available() == 0) {
  }

  char incomingChar = Serial.read();
  Serial.print("You entered: ");
  Serial.println(incomingChar);

  while (Serial.available() > 0)
  {
    Serial.read();
    delay(2);
  }
  delay(1000);
}

// Task 1 - Function to Read the string
void ReadingString() {
  
  Serial.println("Please enter a word:");

  while (Serial.available() > 0) {

    String incomingstr = Serial.readString();
    incomingstr.trim();
    Serial.print("You entered: ");
    Serial.println(incomingstr);
    Serial.println();
  }
  delay(3000);
}

// Task 4 - Function to track the number of counts and update flag
void Adaptive_Lighting() {
  count += 1;
  flag2=false;
  if (count>6) {
    count = 1;
    
  }
}



void loop() {

  // ---------------------TASK 1 - Re-establish serial communication---------------------
  //ReadingChar();        // Function to read a single character as input
  //ReadingString();      // Function to read a string -- PS: Enter input immediately :)
  //---------------------END OF TASK 1---------------------


  //---------------------TASK 2 - Emergency Lighting System---------------------
  // while (Serial.available() > 0) {
  //   String input = Serial.readString();
  //   input.trim();
  //   if (input == "Y") {
  //     digitalWrite(BLUE_LED,HIGH);
  //   }

  //   if (input == "y") {
  //     digitalWrite(BLUE_LED,LOW);
  //   }

  //   if (input == "N") {
  //     digitalWrite(RED_LED,HIGH);
  //   }

  //   if (input == "n") {
  //     digitalWrite(RED_LED,LOW);
  //   }

  //   if (input == "YN" || input == "NY") {
  //     digitalWrite(RED_LED,HIGH);
  //     digitalWrite(BLUE_LED,HIGH);
  //   }

  //   if (input == "yn" || input == "ny") {
  //     digitalWrite(RED_LED,LOW);
  //     digitalWrite(BLUE_LED,LOW);
  //   }

  //---------------------END OF TASK 2---------------------


  //---------------------TASK 3 - Advanced Sensor Monitoring System---------------------

  // int pot_in = analogRead(POTENTIOMETER);
  // float voltage = pot_in * 0.0048875;    // Scalin Factor (5/1023 = 0.0048875...)
  
  

  // if (voltage > 4.3) {
  //   if (abs(pot_in - last_pot_in) > 10) 
  //   {
  //     Serial.print("Analog input : ");
  //     Serial.println(pot_in);
  //     Serial.print("Voltage : ");
  //     Serial.println(voltage);
  //     Serial.println("CAUTION: Voltage level is high!");
  //     warning=true;
  //   }

  //     last_pot_in = pot_in;
    
  // }  
  

  // if (voltage < 1.2) {
  //   if (abs(pot_in - last_pot_in) > 10) 
  //   {
  //     Serial.print("Analog input : ");
  //     Serial.println(pot_in);
  //     Serial.print("Voltage : ");
  //     Serial.println(voltage);
  //     Serial.println("WARNING: Voltage level is critically low!");
  //     warning=true;
  //   }

  //     last_pot_in = pot_in;
    
  // }
  // if (voltage > 1.2 && voltage <4.33) {
  //   if (abs(pot_in - last_pot_in) > 10) 
  //   {
  //     Serial.print("Analog input : ");
  //     Serial.println(pot_in);
  //     Serial.print("Voltage : ");
  //     Serial.println(voltage);
  //     Serial.println("MESSAGE: Voltage level is normal!");
  //     warning=true;
  //   }

  //     last_pot_in = pot_in;
    
  // }
  // last_pot_in = pot_in;
  // delay(50);


  //---------------------TASK 4 - Adaptive Cabin Illumination System---------------------


  attachInterrupt(digitalPinToInterrupt(3),Adaptive_Lighting,FALLING);
  if (count == 1) {
    if(flag2==false) {
      for( int i=0; i <=51 ; i++)
      {
        analogWrite(11,i);
        delay(50);
      }
      flag2=true;
    }
    analogWrite(11,51); 
  }

  if (count == 2) {
    if (flag2==false) {
      for( int j=51; j <=102 ; j++)
      {
        analogWrite(11,j);
        delay(50);
      }
      flag2=true;
    }
    analogWrite(11,102) ;
  }

  if (count == 3) {
    if(flag2==false) {
      for( int k=102; k <=153 ; k++)
      {
        analogWrite(11,k);
        delay(50);
      }
      flag2=true;
    }
    analogWrite(11,153);
  }

  if (count == 4) {
    if(flag2==false) {
      for( int l=153; l <=204 ; l++)
      {
        analogWrite(11,l);
        delay(50);
      }
      flag2=true;
    }
    analogWrite(11,204);
  }

  if (count == 5) {
    if(flag2==false) {
      for( int m=204; m <=255 ; m++)
      {
        analogWrite(11,m);
        delay(50);
      }
      flag2=true;
    }
    analogWrite(11,255);
  }

  if (count == 6) {
    if(flag2==false) {
      for( int j=255; j >= 0; j--)
      {
        analogWrite(11,j);
        delay(5);
      }
      flag2=true;
    }
    analogWrite(11,0);
  }

  //---------------------END OF TASK 4------------------------------

}
