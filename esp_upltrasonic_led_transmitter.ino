#include <ESP8266WiFi.h>
#define buttonPin D3

const char *ssid      = "Switch";
const char *password  = "123456789";

int sensorValue = 0;       //sensor value, I'm usingg 0/1 button state
//int buttonState;             // the current reading from the input pin
//int lastButtonState = LOW;   // the previous reading from the input pin
//unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
//unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
const int pingPin = D7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = D6; // Echo Pin of Ultrasonic Sensor
int Signal = 0, lastSignalState = 0;

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(buttonPin, INPUT);

  // set the ESP8266 to be a WiFi-client
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {

//  int reading = digitalRead(buttonPin);
//  if (reading != lastButtonState) {
//    lastDebounceTime = millis();
//  }
//  if ((millis() - lastDebounceTime) > debounceDelay) {
//    if (reading != buttonState) {
//      buttonState = reading;
//      if (buttonState == HIGH) {
//        sensorValue = ! sensorValue;
//      }
//    }
//  }
//  lastButtonState = reading;

  // Use WiFiClient class to create TCP connections
    long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  //  Serial.print(inches);
  //  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);

  if (cm <= 40) {
    Signal = 0;
  }
  else if (cm >= 160 ) {
    Signal = 1;
  }
  else {
    Signal = lastSignalState;
  }

  lastSignalState = Signal;
  Serial.println("The signal is: " + String(Signal));
  WiFiClient client;
  const char * host = "192.168.4.1";            //default IP address
  const int httpPort = 80;

  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
sensorValue = Signal;
  String url;
  if (sensorValue == 1) {
    url = "/on/";
  }

  if (sensorValue == 0) {
    url = "/off/";
  }
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  client.stop();
}
long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
