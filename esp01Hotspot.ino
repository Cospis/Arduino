#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid="Cospis";
const char* key="12345678";
ESP8266WebServer server(80);
int led=D0;
int state = HIGH;
String ON = "<!DOCTYPE html> <html><head><title>Cospis</title></head><body><h1><center>LED Switch</br></center></hi><p1><center><a href='/off'>Turn ON</a></center></p1></body></html>";
String OFF = "<!DOCTYPE html> <html><head><title>Cospis</title></head><body><h1><center>LED Switch</br></center></hi><p1><center><a href='/on'>Turn OFF</a></center></p1></body></html>";
void setup()
{
Serial.begin(115200);
WiFi.softAP(ssid,key);
pinMode(led,OUTPUT);
//IPAddress myIP = WiFi.softAPIP();
delay(100);
//Serial.println(myIP);
server.on("/", handle_OnConnect);
server.on("/on", handle_ledon);
server.on("/off", handle_ledoff);
 server.begin();
}
  void loop()
  {
  server.handleClient(); 
  }
  void handle_OnConnect() {
  Serial.println("Visited");
  server.send(200, "text/html", ON); 
}
  void handle_ledon() {
  Serial.println("SWITCHED");
  digitalWrite(led,HIGH);
  server.send(200, "text/html", ON); 
}
void handle_ledoff() {
  Serial.println("SWITCHED");
  digitalWrite(led,LOW);
  server.send(200, "text/html", OFF); 
}
