#include <LiquidCrystal.h>

const int trig = 10;
const int echo = 9;
const int rs = 51, e = 50, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
float timing = 0.00;
float duration = 0.00;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  timing = pulseIn(echo, HIGH);
  duration = (timing * 0.034) / 2;

  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(duration);
  delay(2000);
  lcd.clear();
}
