int pin = A0;
float val = 0.0;
float volts;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pin);
  volts = (5/1023.) * val;
  Serial.println(volts);
  delay(1000);
}
