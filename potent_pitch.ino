/*Created By Qozim Idris to vary brightness of LED 
or Loudness of a Buzzer.....
For any questions or corrections, 
please contact me @qozimidris@gmail.com
*/
float (val);
int n = A2; //Pin for potentiometer
int i =9; // Pin for led/buzzer
float v; //Inverse of the potentiometer value
int p; //Loudness/Brightness (0-255)
void setup() {
  // put your setup code here, to run once:
pinMode(n,INPUT);
pinMode(i,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(n);
Serial.println(val);
v = 1023-val;
p= v/1023*255;
analogWrite(i,p);
}
