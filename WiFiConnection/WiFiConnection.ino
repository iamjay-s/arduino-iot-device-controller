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
void handleRoot() {
  String str = "<p id='clicked'></p><button name='btn' onclick='myFunc()'>Welcome</button><script>function myFunc(){document.getElementById('clicked').innerHTML='Welcome...';}</script>";
  server.send(200, "text/html", str);
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
}
