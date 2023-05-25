#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

int trig = D8;
int echo = D15;
float dist;
int dur;
String str = "";
int led = D2;
int status = 0;
/* Set these to your desired credentials. */
const char *ssid = "Agarwal";
const char *password = "rsvagr@101";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
void handleRoot() {
  String newStr = "<h2>Ultrasonic Sensor</h2><br><form action='/' method='post'><button type='submit' name='sensor' value='on'>Check</button><br></form>";
  //server.send(200, "text/html", newStr);
  float distance = checkDist();
  str = "<br><h2>Distance is </h2>";
  str = str + distance;
  String f = newStr + "<br>" + str;

  if(status == 1){
    f = f + "<br>LED is turned ON";
  }
  else{
    f = f + "<br>LED is turned OFF";
  }

  server.send(200, "text/html", f);
}

float checkDist(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo, HIGH);
  dur = dur/2.;
  dist = 0.034 * dur;
  Serial.println(dist);
  return dist;
}


void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);

  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  //server.on("/active", handleButton);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  float temp = checkDist();
  if(temp <= 20.0 && temp > 0){
    digitalWrite(led, HIGH);
    status = 1;
  }
  else if(temp>20.0){
    digitalWrite(led, LOW);
    status = 0;
  }
}
