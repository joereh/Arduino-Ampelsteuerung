#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int buttonApin = 7;
int buttonBpin = 8;

int LEDblue=6;

void setup() {
  mySwitch.enableTransmit(10);  // Der Sender wird an Pin 10 angeschlossen
  pinMode(buttonApin, INPUT);
  pinMode(buttonBpin, INPUT);
}
void loop() {

//  Button A
  if (digitalRead(buttonApin) == HIGH)
  {
  mySwitch.send(1001, 16); // Dezimalzahl "1001“, 16 Bit
  digitalWrite(LEDblue, HIGH);
   delay(5000);  
  digitalWrite(LEDblue, LOW); 
  } 
  

//  Button B
  if (digitalRead(buttonBpin) == HIGH)
  {
  mySwitch.send(2001, 16); // Dezimalzahl "2001“, 16 Bit
  digitalWrite(LEDblue, HIGH);
   delay(5000);  
  digitalWrite(LEDblue, LOW); 
  } 

  
}  
