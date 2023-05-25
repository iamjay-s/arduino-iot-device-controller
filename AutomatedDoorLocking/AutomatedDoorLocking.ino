#include<Servo.h>
int echo = 9;
int trig = 2;
int servo = 5;
float dur;
float dist;
int pos;
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  myServo.attach(servo);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo, HIGH);
  dur = dur/2.;
  dist = 0.034 * dur;
  Serial.println(dist);
  if(dist<=25 && dist>0){
    myServo.write(120);
    delay(5000);
  }
  myServo.write(0);
}
