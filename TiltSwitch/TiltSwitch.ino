int tilt = 2;
int led = 3;
int val;
void setup() {
  // put your setup code here, to run once:
  pinMode(tilt, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  // Tilt switch has to be initiated with HIGH
  digitalWrite(tilt, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(tilt);
  Serial.println(val);
  if(val==0){
    digitalWrite(led, LOW);
  }
  else{
    digitalWrite(led, HIGH);
  }
  delay(200);

}
