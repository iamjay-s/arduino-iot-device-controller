#define low HIGH
#define high LOW
int out = 2;
int current;
void setup() {
  // put your setup code here, to run once:
  pinMode(out, OUTPUT);
  Serial.begin(9600);
  digitalWrite(out, low);
  current = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()==0){}
  current = Serial.parseInt();
  if(current == 1){
    digitalWrite(out, low);
    Serial.println("Turned Off");
  }
  else if(current == 2){
    digitalWrite(out, high);
    Serial.println("Turned On");
  }
}
