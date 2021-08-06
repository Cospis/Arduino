int i = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(i,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int j = analogRead(i);
Serial.println(j);
}
