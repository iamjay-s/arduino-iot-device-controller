#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

int led = D2;
/* Set these to your desired credentials. */
const char *ssid = "Agarwal";
const char *password = "rsvagr@101";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
void handleRoot() {
  String newStr = "<h2>LED Test</h2><br><form action='/' method='post'><button type='submit' name='led' value='on' formaction='/on'>Turn On</button><br><button type='submit' name='led' value='off' formaction='/off'>Turn Off</button></form>";
  server.send(200, "text/html", newStr);
}

void handleButton1(){
  digitalWrite(led, HIGH);
  server.sendHeader("Location", "/");
  server.send(303); //ensure safety and trust while redirecting

}
void handleButton2(){
  digitalWrite(led, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
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
  server.on("/on", handleButton1);
  server.on("/off", handleButton2);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
