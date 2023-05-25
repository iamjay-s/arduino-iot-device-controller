#define low HIGH
#define high LOW
int out = 2;
int terminal = 6;
int state;
int prev, curr;
void setup() {
  // put your setup code here, to run once:
  pinMode(out, OUTPUT);
  pinMode(terminal, INPUT);
  Serial.begin(9600);
  digitalWrite(out, low);
  state = 0;
  prev = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  curr = digitalRead(terminal);
  Serial.println(curr);
  if(prev == 0 && curr == 1){
    if(state == 0){
      digitalWrite(out, high);
      state = 1;

      Serial.println("Turned On");
    }
    else if(state == 1){
      digitalWrite(out, low);
      state = 0;

      Serial.println("Turned Off");
    }
  }
  prev = curr;
}
