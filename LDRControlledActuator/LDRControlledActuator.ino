int volt = A5;
int actuator = 7;
int prev; //0->Night, 1->Day
int current;
float val;
void setup() {
  // put your setup code here, to run once:
  pinMode(volt, INPUT);
  pinMode(actuator, OUTPUT);
  Serial.begin(9600);
  val = analogRead(volt);
  val = (5/1023.) * val;
  if(val>=0.5){
    current = 1;
  }
  else{
    current = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  prev = current;
  val = analogRead(volt);
  val = (5/1023.) * val;   // converting value of val into the range 0-5V from 0-1023
  
  if(val>=0.5){           //value of val to be decided a/c to environmental cond.
    current = 1;
  }
  else{
    current = 0;
  }

  if(prev == 0 && current == 1){
    digitalWrite(actuator, HIGH);
    delay(5000);
    digitalWrite(actuator, LOW);
  }
  
  Serial.println(val);
  delay(1000);
}
