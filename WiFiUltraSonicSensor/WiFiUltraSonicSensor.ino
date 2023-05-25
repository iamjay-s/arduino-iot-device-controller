#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

int trig = D8;
int echo = D15;
float dist;
int dur;
String str = "";
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
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo, HIGH);
  dur = dur/2.;
  dist = 0.034 * dur;
  str = "<br><h2>Distance is </h2>";
  str = str + dist;
  String f = newStr + "<br>" + str;
  server.send(200, "text/html", f);
  
}


void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
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

}
