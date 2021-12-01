//Leistand
#include <RCSwitch.h>
#include <Bounce2.h>

RCSwitch mySwitch = RCSwitch();

#define STARTBTN 2
#define STOPBTN 3
#define F1BTN 4
#define F2BTN 5

Bounce startBouncer = Bounce(STARTBTN, 50);
Bounce stopBouncer = Bounce(STOPBTN, 50);
Bounce fuss1Bouncer = Bounce(F1BTN, 50);
Bounce fuss2Bouncer = Bounce(F2BTN, 50);

int LEDblue=6;

void setup() {
  mySwitch.enableTransmit(10);  // Der Sender wird an Pin 10 angeschlossen
  //pinMode(buttonApin, INPUT);
  pinMode(STARTBTN, INPUT);
  pinMode(STOPBTN, INPUT);
  pinMode(F1BTN, INPUT);
  pinMode(F2BTN, INPUT);

}
void loop() {
startBouncer.update();
stopBouncer.update();
fuss1Bouncer.update();
fuss2Bouncer.update();

// Start Ampelschaltung
if(startBouncer.fell())
  {
  mySwitch.send(1001, 16); // Dezimalzahl "1001“, 16 Bit
  digitalWrite(LEDblue, HIGH);
   delay(5000);
  digitalWrite(LEDblue, LOW);
  }


// Stop Ampelschaltung
  if(stopBouncer.fell())
  {
  mySwitch.send(2001, 16); // Dezimalzahl "2001“, 16 Bit
  digitalWrite(LEDblue, HIGH);
   delay(5000);
  digitalWrite(LEDblue, LOW);
  }

//   Fussgänger Spur 2
  if(fuss1Bouncer.fell())
  {
  mySwitch.send(3001, 16); // Dezimalzahl "3001“, 16 Bit
  digitalWrite(LEDblue, HIGH);
   delay(5000);
  digitalWrite(LEDblue, LOW);
  }
//  Fussgänger Spur 2
  if(fuss2Bouncer.fell())
  {
  mySwitch.send(4001, 16); // Dezimalzahl "4001“, 16 Bit
  digitalWrite(LEDblue, HIGH);
   delay(5000);
  digitalWrite(LEDblue, LOW);
  }



}
