
int i = 8;
int j = A0;
int k = 3;
void setup() {
  // put your setup code here, to run once:
pinMode(i,INPUT);
pinMode(j,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.print("Digital is ");
//Serial.println(digitalRead(i));
Serial.print ("Analog is ");
Serial.println(analogRead(j));
delay(1000);
/*delay(1000);
for (i=0;i<256;i++)
{
  analogWrite(k,i);
}
for (i=256;i<1;i--)
{
  analogWrite(k,i);
}
Serial.print ("Buzzer is ");
Serial.println(i);*/
}
