//OLED Display libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//pins
int ldrPin = 2;
int ledPin = 4;
int buzzerPin = 7;
int pirPin = 6;
int pirPinTwo = 5;
#define MQ2pin 0 //Analog A0
Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 64, &Wire);

//Variables
#define Threshold 90
int ldrValue = 0;
int val = 0;
int valTwo = 0;
float sensorValueMQ2;


void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);       // declare LDR Sensor as input
  pinMode(ledPin, OUTPUT);         // declare LED as output
  pinMode(buzzerPin, OUTPUT);   // declare buzzer as output
  pinMode(pirPin, INPUT);       // declare PIR Sensor as input
  pinMode(pirPinTwo, INPUT);       // declare PIR Sensor as input
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); //OLED Display
  Serial.println("MQ2 warming up!");
}

void  loop() {
  ldrSensor();
  pirSensor();
  gasdetector();

}

void ldrSensor() {
  ldrValue = digitalRead(ldrPin);
  
  Serial.print("LDR Sensor Value=");
  Serial.println(ldrValue);
  delay(300);

  if (ldrValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    oled.clearDisplay();
    oled.setTextColor(WHITE);
    oled.setTextSize(2);
    oled.setCursor(1, 0);
    oled.print("Light");
    oled.setTextSize(2);
    oled.setCursor(0, 25);
    oled.print("Turn On");
    oled.setTextSize(2);
    oled.display();
    oled.clearDisplay();
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
    delay(500);
    oled.clearDisplay();
    oled.setTextColor(WHITE);
    oled.setTextSize(2);
    oled.setCursor(1, 0);
    oled.print("Motion");
    oled.setTextSize(2);
    oled.setCursor(0, 25);
    oled.print("Detected");
    oled.setTextSize(2);
    oled.display();
    oled.clearDisplay();
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }
}


void gasdetector() {
  sensorValueMQ2 = analogRead(MQ2pin);  // read analog input pin 0
  Serial.print("Sensor Value: ");
  Serial.print(sensorValueMQ2);

  if (sensorValueMQ2 > Threshold) {
    Serial.print(" | Gas detected!");
    digitalWrite(buzzerPin, HIGH);
    oled.clearDisplay();
    oled.setTextColor(WHITE);
    oled.setTextSize(2);
    oled.setCursor(1, 0);
    oled.print("Gas");
    oled.setTextSize(2);
    oled.setCursor(0, 25);
    oled.print("Detected");
    oled.setTextSize(2);
    oled.display();
    oled.clearDisplay();
  }
  Serial.println("");
  delay(2000);  // wait 2s for next reading
}
