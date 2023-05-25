void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()==0){}
  String command = Serial.readStringUntil('\r');
  // Serial.println(command);
  if(command=="switch on") digitalWrite(2, HIGH);
  else digitalWrite(2, LOW);
}
