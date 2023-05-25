//Light up LED inversely with voltage
int volt = A5;
int aout = 3; //recommended pin 3,9,10,11 pwm digital-analog pin with ~ (avoid pin 5,6 for analog output due to long duty cycle)
float val;
int fval;
int check = A2;
float checkval;
void setup() {
  // put your setup code here, to run once:
  pinMode(volt, INPUT);
  pinMode(aout, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(volt);
  val = (5/1023.) * val;
  val = 5.0 - val;       // inverting o/p with variation in voltage
  val = (1023/5.) * val;
  fval = val/4.;
  Serial.println(fval);
  analogWrite(aout, fval);
  delay(200);
}
