#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
int X=0;

void setup() {
  
  lcd.begin(16, 2);
  lcd.print("GAS CONC.:");
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(7, LOW);
  X = analogRead(A0);
  lcd.setCursor(11, 0);
  lcd.print(X);
  Serial.println(X);
  lcd.setCursor(0, 1);
  if (X<530){
    lcd.print("NORMAL");}
  else if (X>545 and X<680){
    lcd.print("MEDIUM");}
  else{
    lcd.print("HIGHER");
    digitalWrite(7, HIGH);}
  delay(100);
}
