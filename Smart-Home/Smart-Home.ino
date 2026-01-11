int ldrValue;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
}

void  loop() {
  ldrSensor();
}

void ldrSensor() {
  ldrValue = digitalRead(2);

  Serial.print("LDR Sensor Value=");
  Serial.println(ldrValue);
  delay(300);

  if (ldrValue == 1) {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
  delay(1000);
}
