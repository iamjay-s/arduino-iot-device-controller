#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

String cmd = "";
/* Set these to your desired credentials. */
const char *ssid = "Agarwal";
const char *password = "rsvagr@101";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
void handleRoot() {
  String newStr = "<h2>Hello.....</h2><br><form action='' method='GET'><button type='submit' name='btn' value='One'>Button 1</button><br><button type='submit' name='btn' value='Two'>Button 2</button></form>";
  server.send(200, "text/html", newStr);
}

void display(String str){
  String out1 = "<h3>Hello </h3>";
  String out2 = "<a href='http://192.168.1.83/'>Home</a>";
  String f = out1 + str + out2;
  server.send(200, "text/html", f);
  server.handleClient();
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
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  cmd = server.arg("btn");
  if(cmd!=""){
    //Serial.println(cmd);
    display(cmd);
  }
  
}
