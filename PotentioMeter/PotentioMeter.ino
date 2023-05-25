int volt = A5;
float val;
void setup() {
  // put your setup code here, to run once:
  pinMode(volt, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(volt);
  val = (5/1023.) * val;
  Serial.println(val);
  delay(2000);
}
