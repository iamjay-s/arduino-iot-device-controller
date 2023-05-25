#include<LiquidCrystal.h>
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int led = 7;
String msg;
int pwd;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); //order of display -> (column, row)
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();    
  lcd.setCursor(0, 0);
  while(Serial.available() == 0){}
  msg = Serial.readString();

  while(Serial.available() == 0){}
  pwd = Serial.parseInt();

  if(pwd==9001){
    lcd.print("Hello");
    lcd.setCursor(0,1);
    lcd.print(msg);
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(led, LOW);
  }
  else{
    lcd.print("Incorrect Password!");
  }
  lcd.display();

  delay(1000);
}
