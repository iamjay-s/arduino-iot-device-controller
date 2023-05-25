int terminal = 2;
int led = 4;
int prev,current;
int state;
void setup() {
  // put your setup code here, to run once:
  pinMode(terminal, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  state = 0;
  prev = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  current = digitalRead(terminal);
  if(prev==1 && current==0){
    if(state==0){
      digitalWrite(led, HIGH);
      state = 1;
    }
    else{
      digitalWrite(led, LOW);
      state = 0;
    }
  }
  prev = current;
  Serial.println(current);
  delay(100);
}
