#include<LiquidCrystal.h>
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); //order of display -> (column, row)
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.print("Hello LCD,@");
  lcd.setCursor(0, 1);  //Sets the cursor to row 1 and column 0
  lcd.print("Hello LCD X2");
  lcd.display();  //Optional for optimal display
  delay(1000);
}
