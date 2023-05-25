#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "Agarwal";
const char *password = "rsvagr@101";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/

String fin = "";
void handleRoot() {
  String str = "<h2>Hello</h2><form action='/' method='post'><button name='btn' formaction='/btn1'>Button 1</button><button name='btn' formaction='/btn2'>Button 2</button></form>";
  str = str + "<br><h1>" + fin + "</h1>";
  server.send(200, "text/html", str);
}

void myfunc1(){
  Serial.println("Button 1 pressed");
  fin = "Button 1 pressed";
  server.sendHeader("Location", "/");
  server.send(303);
}

void myfunc2(){
  Serial.println("Button 2 pressed");
  fin = "Button 2 pressed";
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
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
  server.on("/btn1", myfunc1);
  server.on("/btn2", myfunc2);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
