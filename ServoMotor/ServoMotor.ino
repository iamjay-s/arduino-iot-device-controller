#include<Servo.h>
int rotate =  3;
int pos;
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(rotate); //Attach pin no 3 (rotate pin) with servo motor
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() == 0){}
  pos = Serial.parseInt();
  myServo.write(pos);
  delay(1000);
}
