int volt = A5;
int led = 7;
float val;
void setup() {
  // put your setup code here, to run once:
  pinMode(volt, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(volt);
  val = val * (5/1023.);
  Serial.println(val);
  if(val<=0.5){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }  
  delay(200);
}
