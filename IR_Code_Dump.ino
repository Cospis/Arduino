#include <IRremote.h> //Include IR library

const int sig = 9; // Attach IR signal to pin 9
IRrecv irrecv(sig); //Receive Signal from "sig"
decode_results results; //Accept codes

void setup(){
  Serial.begin(9600);  //Start Serial Monitor
  irrecv.enableIRIn(); // Start Receiver
//  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)) 
  {
      int val = (results.value); //Save results imside "val"
      Serial.println(val); //Print val
        irrecv.resume();
  }
}
