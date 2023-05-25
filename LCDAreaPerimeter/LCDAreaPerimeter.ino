#include <LiquidCrystal.h>
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float l;
float b;
float temp;
float area;
float perimeter;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);  //order of display -> (column, row)
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);

  while (Serial.available() == 0) {}
  temp = Serial.parseFloat();
  if(temp != 0.0){
    l = temp;
  }
  else{
    while(Serial.available() == 0){}
    l = Serial.parseFloat();
  }
  Serial.println(l);

  
  while (Serial.available() == 0) {}
  temp = Serial.parseFloat();
  if(temp != 0.0){
    b = temp;
  }
  else{
    while(Serial.available() == 0){}
    b = Serial.parseFloat();
  }
  Serial.println(b);

  area = l * b;
  perimeter = 2 * (l + b);
  lcd.print("Area = ");
  lcd.setCursor(7,0);
  lcd.print(area);
  lcd.setCursor(0, 1);
  lcd.print("Perimeter = ");
  lcd.setCursor(12,1);
  lcd.print(perimeter);
  lcd.display();

  delay(10000);
}
