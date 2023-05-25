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
  String newStr = "<h2>Hello.....</h2><br><form action='/' method='get'><button type='submit' name='btn' value='One' formaction='/btn1'>Button 1</button><br><button type='submit' name='btn' value='Two' formaction='/btn2'>Button 2</button></form>";
  server.send(200, "text/html", newStr);
}

void handleButton1(){
  String out1 = "<h3>Hello B1 </h3>";
  String out2 = "<a href='/'>Home</a>";
  String f = out1 + out2;
  server.send(200, "text/html", f);
}
void handleButton2(){
  String out1 = "<h3>Hello B2 </h3>";
  String out2 = "<a href='/'>Home</a>";
  String f = out1 + out2;
  server.send(200, "text/html", f);
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
  server.on("/btn1", handleButton1);
  server.on("/btn2", handleButton2);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
