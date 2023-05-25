#define low HIGH
#define high LOW
int out = 2;
int terminal1 = 6;
int terminal2 = 8;
int state;
int prev, curr;
int prev2, curr2;
void setup() {
  // put your setup code here, to run once:
  pinMode(out, OUTPUT);
  pinMode(terminal1, INPUT);
  pinMode(terminal2, INPUT);
  Serial.begin(9600);
  digitalWrite(out, low);
  state = 0;
  prev = 1;
  prev2 = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  curr = digitalRead(terminal1);
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


  curr2 = digitalRead(terminal2);
  Serial.println(curr2);
  if(prev2 == 0 && curr2 == 1){
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
  prev2 = curr2;
}
