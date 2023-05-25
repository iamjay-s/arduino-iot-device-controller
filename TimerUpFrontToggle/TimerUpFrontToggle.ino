//Using UpFront Connection for Toggle Switch
int inp = 8;
int val;
int prev=1, curr=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inp, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  curr = digitalRead(inp);
  if(curr == 0){
    val += 1;
  }
  if(prev==0 && curr == 1){
    Serial.println(val);
    val = 0;
  }
  prev = curr;
  delay(1000);
}
