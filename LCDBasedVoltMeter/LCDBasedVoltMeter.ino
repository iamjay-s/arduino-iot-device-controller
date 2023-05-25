#include<LiquidCrystal.h>
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int volt = 8;
float val;
void setup() {
  // put your setup code here, to run once:
  pinMode(volt, INPUT);
  lcd.begin(16,2); //order of display -> (column, row)
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(volt);
  val = (5/1023.) * val;
  lcd.clear();
  lcd.print(val);
  lcd.display();  //Optional for optimal display
  Serial.println(val);
  delay(100);
}
