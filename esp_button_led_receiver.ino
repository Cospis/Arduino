#include<ESP8266WiFi.h>
#include "user_interface.h"
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
// WiFi Definitions
const char *ssid      = "Switch";
const char *password  = "123456789";
int val;
String lastReq;

int ledPin = D5; // GPIO 2
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // turn on

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password, 1, false);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  //************Check if client has connected***************************

  WiFiClient client = server.available();

  if (client) {
    // Read the request line
    String msg = client.readStringUntil('\r');
    Serial.println(msg);
    client.flush();
    delay(100);
    //********************************************************************

    int val;
    if (msg.indexOf("/off") != -1)
      val = 0;
    if (msg.indexOf("/on") != -1)
      val = 1;

    client.stop();
    delay(100);

    digitalWrite(ledPin, val);
    client.flush();
  }
  //********************************************************************

}
