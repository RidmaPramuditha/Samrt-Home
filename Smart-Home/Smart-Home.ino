//pins
int ldrPin = 2;
int ledPin = 4;
int buzzerPin = 7;
int pirPin = 6;
int pirPinTwo = 5;

//Variables
//int pirState = LOW;
//int pirStateTwo = LOW;
int ldrValue = 0;
int val = 0;
int valTwo = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);       // declare LDR Sensor as input
  pinMode(ledPin, OUTPUT);         // declare LED as output
  pinMode(buzzerPin, OUTPUT);   // declare buzzer as output
  pinMode(pirPin, INPUT);       // declare PIR Sensor as input
  pinMode(pirPinTwo, INPUT);       // declare PIR Sensor as input
  Serial.begin(9600);
}

void  loop() {
  ldrSensor();
  pirSensor();
  //pirSensorTwo();
}

void ldrSensor() {
  ldrValue = digitalRead(ldrPin);

  Serial.print("LDR Sensor Value=");
  Serial.println(ldrValue);
  delay(300);

  if (ldrValue == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
}


void pirSensor() {
  //PIR Sensor One
  val = digitalRead(pirPin);
  Serial.print("PIR Sensor Value=");
  Serial.println(val);
  //PIR Senosor Two
  valTwo = digitalRead(pirPinTwo);
  Serial.print("PIR Sensor Value Two=");
  Serial.println(valTwo);
  
  if (val == HIGH || valTwo == HIGH)
  {
    digitalWrite(buzzerPin, HIGH);

    /*if (pirState == LOW || pirStateTwo == LOW)
    {
      Serial.println("Motion detected!");
      pirState = HIGH;
      Serial.println("Motion detected - PIR Two!");
      pirStateTwo = HIGH;
    }*/
  }
  else
  {
    digitalWrite(buzzerPin, LOW);

    /*if (pirState == HIGH || pirStateTwo == HIGH) 
    {
      Serial.println("Motion ended!");
      pirState = LOW;
      Serial.println("Motion ended!");
      pirStateTwo = LOW;
    }*/
    delay(1000);
  }
}


/*void pirSensorTwo() {
  valTwo = digitalRead(pirPinTwo);
  Serial.print("PIR Sensor Value Two=");
  Serial.println(valTwo);
  if (valTwo == HIGH)
  {
    digitalWrite(buzzerPin, HIGH);

    if (pirStateTwo == LOW)
    {
      Serial.println("Motion detected - PIR Two!");
      pirStateTwo = HIGH;
    }
  }
  else
  {
    digitalWrite(buzzerPin, LOW);

    if (pirStateTwo == HIGH)
    {
      Serial.println("Motion ended!");
      pirStateTwo = LOW;
    }
    delay(5000);
  }
}*/
