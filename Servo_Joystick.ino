#include <Servo.h> //Include Servo library
int x=A0; // Joystick pin
//int y = A1;
int servo = 2; // Connect Servo here
int xval;
int axis;
Servo Cospis; // Create Servo Cospis
void setup() {
  // put your setup code here, to run once:
Cospis.attach(servo);
pinMode(x,INPUT);
//pinMode(y,INPUT);
Cospis.write(0);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
xval = analogRead(x);
axis= map(xval, 0, 1023, 0, 180); //Map Joystick value to 180 degrees.
Cospis.write(axis); // Turn servo to the angle 
Serial.println(axis);
}
