
//Ampelanlage
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int buttonState;

// Ampel Belegung der Ausgaenge
//Ampelspur 1
const byte RotA1 = 3;
const byte GelbA1 = 4;
const byte GruenA1 = 5;
//Fussgängerspur 1
const byte RotF1 = 6;
const byte GruenF1 = 7;
////Fussgängerspur 2
const byte RotF2 = 8;
const byte GruenF2 = 9;
//Ampelspur 2
const byte RotA2 = 10;
const byte GelbA2 = 11;
const byte GruenA2 = 12;

//
const int ZEITROTPHASE = 5000;
const int ZEITGELBPHASE = 1500;
const int FUSSGAENGERPHASE = 15000;
unsigned long ampelMillis;
unsigned long ampelIntervall;
//
enum ZUSTAENDE {ASTART,ROT, ROTGELB, GRUEN, GELB,FSTOP,ASTOP};
byte zustand = ASTART;


void setup() {
  // Definiert die Pins als Ausgang
  pinMode(RotA1, OUTPUT);
  pinMode(GelbA1, OUTPUT);
  pinMode(GruenA1, OUTPUT);
  pinMode(RotF1, OUTPUT);
  pinMode(GruenF1, OUTPUT);
  pinMode(RotF2, OUTPUT);
  pinMode(GruenF2, OUTPUT);
  pinMode(RotA2, OUTPUT);
  pinMode(GelbA2, OUTPUT);
  pinMode(GruenA2, OUTPUT);
  // Empfänger ist an Interrupt-Pin "0" - Das ist am UNO der Pin2
  mySwitch.enableReceive(0);
  //Debug
  Serial.begin(9600);
  Serial.println("Ampelsteuerung setup");
 }

void loop() {

if (mySwitch.available()) // Wenn ein Code Empfangen wird...
  {
    buttonState = mySwitch.getReceivedValue();
    mySwitch.resetAvailable(); // Hier wird der Empfänger "resettet"
  }

  // Ampelschaltung
  if ((millis() - ampelMillis >= ampelIntervall)) {
    switch (zustand) {
      case ASTART:
        if(buttonState == 1001)
           {
           zustand = ASTOP;
           }
         break;
      case ROT:
        //Spur1
        digitalWrite(RotA1, HIGH);
        digitalWrite(GelbA1, LOW);
        digitalWrite(GruenA1, LOW);
        digitalWrite(RotF1, HIGH);
        digitalWrite(GruenF1, LOW);
       //Spur2 Gruen
        digitalWrite(RotA2, LOW);
        digitalWrite(GelbA2, LOW);
        digitalWrite(GruenA2, HIGH);
        digitalWrite(RotF2, HIGH);
        digitalWrite(GruenF2, LOW);
        zustand = ROTGELB;
        ampelMillis = millis();
        if(buttonState == 3001)
           {
             digitalWrite(RotF1, LOW);
             digitalWrite(GruenF1, HIGH);
             digitalWrite(RotF2, HIGH);
             digitalWrite(GruenF2, LOW);
             ampelIntervall = FUSSGAENGERPHASE;
             buttonState=0;
           }
           else {
                 ampelIntervall = ZEITROTPHASE;
           }
        break;
      case ROTGELB:
        //SPUR1
        digitalWrite(RotA1, HIGH);
        digitalWrite(GelbA1, HIGH);
        digitalWrite(GruenA1, LOW);
        digitalWrite(RotF1, HIGH);
        digitalWrite(GruenF1, LOW);
        //Spur2 Gelb
        digitalWrite(RotA2, LOW);
        digitalWrite(GelbA2, HIGH);
        digitalWrite(GruenA2, LOW);
        digitalWrite(RotF2, HIGH);
        digitalWrite(GruenF2, LOW);


        zustand = GRUEN;
        ampelMillis = millis();
        ampelIntervall = ZEITGELBPHASE;
        break;
      case GRUEN:
        digitalWrite(RotA1, LOW);
        digitalWrite(GelbA1, LOW);
        digitalWrite(GruenA1, HIGH);
        //Spur2 ROT
        digitalWrite(RotA2, HIGH);
        digitalWrite(GelbA2, LOW);
        digitalWrite(GruenA2, LOW);
        zustand = GELB;
        ampelMillis = millis();

        if(buttonState == 4001)
           {
             digitalWrite(RotF2, LOW);
             digitalWrite(GruenF2, HIGH);
             digitalWrite(RotF1, HIGH);
             digitalWrite(GruenF1, LOW);
             ampelIntervall = FUSSGAENGERPHASE;
             buttonState=0;
           }
           else {
                 ampelIntervall = ZEITROTPHASE;
           }
        break;
      case GELB:
        digitalWrite(RotA1, LOW);
        digitalWrite(GelbA1, HIGH);
        digitalWrite(GruenA1, LOW);
        // Spur2 ROT-Gelb
        digitalWrite(RotA2, HIGH);
        digitalWrite(GelbA2, HIGH);
        digitalWrite(GruenA2, LOW);
        zustand = ASTOP;
        ampelMillis = millis();
        ampelIntervall = ZEITGELBPHASE;
        break;
      case ASTOP:
        if(buttonState == 2001)
           {
           zustand = ASTART;
           digitalWrite(RotA1, LOW);
           digitalWrite(RotA2, LOW);
           digitalWrite(GelbA1, LOW);
           digitalWrite(GelbA2, LOW);
           digitalWrite(RotF1, LOW);
           digitalWrite(RotF2, LOW);
           digitalWrite(GruenF1, LOW);
           digitalWrite(GruenF2, LOW);
           }
         else {
          zustand = ROT;
          }
        break;

    } //case
  }//if
}//loop
