
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int LEDred=6;
int LEDgreen=7;
int LEDyellow=8;
void setup() 
{ 
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Empfänger ist an Interrupt-Pin "0" - Das ist am UNO der Pin2
  Serial.println("Ausgabe serieller Monitor" );
}
int switchA;
int switchB;

void loop() {
  
  if (mySwitch.available()) // Wenn ein Code Empfangen wird...
  {
    int value = mySwitch.getReceivedValue(); // Empfangene Daten werden unter der Variable "value" gespeichert.
    switchA=0; 
    
    if (value == 0) 
    {
      Serial.println("Unbekannter Code");
    }   
    ///////////////////////////
    // Button A 1001/1002 
    if (value == 1001) 
    {
      switchA=1001;
    } 
    if (value == 1002) 
    {
      switchA=1002;
    } 
   /////////////////////////// 
   // Button B 2001/2002 
    if (value == 2001) 
    {
      switchB=2001;
    } 
    if (value == 2002) 
    {
      switchB=2002;
    } 
   
    mySwitch.resetAvailable(); // Hier wird der Empfänger "resettet"
  }
 /////////////////////////// 
 //Button A 1001/1002 red
  if (switchA == 1001)
  {
    digitalWrite(LEDred, HIGH); 
    digitalWrite(LEDyellow, LOW);
    digitalWrite(LEDgreen, LOW); 
  } 

  if (switchA == 1002)
  {
    digitalWrite(LEDred, LOW); 
    digitalWrite(LEDyellow, LOW);
    digitalWrite(LEDgreen, LOW);
  } 
 /////////////////////////// 

/////////////////////////// 
 //Button B 2001/2002 yellow
  if (switchB == 2001)
  {
    digitalWrite(LEDred, LOW); 
    digitalWrite(LEDyellow, HIGH);
    digitalWrite(LEDgreen, LOW); 
  } 

  if (switchB == 2002)
  {
    digitalWrite(LEDred, LOW); 
    digitalWrite(LEDyellow, LOW);
    digitalWrite(LEDgreen, LOW); 
  } 
 /////////////////////////// 

/*digitalWrite(LEDred, HIGH); 
delay(2000); 
digitalWrite(LEDyellow, HIGH); 
delay(1000); 
digitalWrite(LEDred, LOW); 
digitalWrite(LEDyellow, LOW);
digitalWrite(LEDgreen, HIGH); 
  */
}
