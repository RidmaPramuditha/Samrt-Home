#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//pins
int ldrPin = 2;
int ledPin = 4;
int buzzerPin = 7;
int pirPin = 6;
int pirPinTwo = 5;
#define MQ2pin 0

//Variables
#define Threshold 90
int ldrValue = 0;
int val = 0;
int valTwo = 0;
float sensorValueMQ2;

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 64, &Wire);

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);       // declare LDR Sensor as input
  pinMode(ledPin, OUTPUT);         // declare LED as output
  pinMode(buzzerPin, OUTPUT);   // declare buzzer as output
  pinMode(pirPin, INPUT);       // declare PIR Sensor as input
  pinMode(pirPinTwo, INPUT);       // declare PIR Sensor as input
  Serial.println("MQ2 warming up!");
  Serial.begin(9600);
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
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
    oled.setTextSize(1);
    oled.setCursor(1, 0);
    oled.print("Light Turn On");
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
    oled.setTextSize(1);
    oled.setCursor(1, 0);
    oled.print("Motion Detected");
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
    oled.setTextSize(1);
    oled.setCursor(1, 0);
    oled.print("Gas Detected");
    oled.setTextSize(2);
    oled.display();
    oled.clearDisplay();
  }
  Serial.println("");
  delay(2000);  // wait 2s for next reading
}
