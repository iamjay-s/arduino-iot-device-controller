#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager

ESP8266WebServer server(80);

String fin = "";
void handleRoot() {
  String str = "<h2>Hello</h2><form action='/' method='get'><input type='text' name='inputData'></input><br><button name='btn' formaction='/btn1'>Button 1</button><button name='btn' formaction='/btn2'>Button 2</button></form>";
  str = str + "<br><h1>" + fin + "</h1>";
  server.send(200, "text/html", str);
}

void myfunc1(){
  String temp = server.arg("inputData");
  Serial.println(temp);
  fin = temp;
  server.sendHeader("Location", "/");
  server.send(303);
}

void myfunc2(){
  String temp = server.arg("inputData");
  Serial.println(temp);
  String btn = "<h2>" + temp + "</h2><br><a href='/'><button>Home</button></a>";
  server.send(200, "text/html", btn);
}


void setup() {

  Serial.begin(115200);
  WiFiManager wm;

  wm.resetSettings();
  bool res;
  res = wm.autoConnect("AutoConnectAP", "password");  
  if (!res) {
    Serial.println("Failed to connect");
  } else {
    Serial.println("connected...yeey :)");
  }

  server.on("/", handleRoot);
  server.on("/btn1", myfunc1);
  server.on("/btn2", myfunc2);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();

}
