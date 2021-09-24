const int pingPin = D7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = D6; // Echo Pin of Ultrasonic Sensor
int Signal = 0, lastSignalState = 0;


void setup() {
  Serial.begin(115200); // Starting Serial Terminal
}

void loop() {
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
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
