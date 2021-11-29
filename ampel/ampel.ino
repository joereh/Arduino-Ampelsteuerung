// ----------------------------------------------------------------------------------
// Ampel 1.0 ... für Arduino UNO      
// Mit Bibliothek "MobaTools.h", eigens für dieses Projekt erstellt

#include <MobaTools.h>   

// Parameter "Taster"
const byte tMod     =   2;        //  Taste "Modus"   (Tag-/Nacht)
const byte tPoli    =   3;        //  Taste "Polizei" (Kurzfristiger Blinker)
const byte tUeber   =   4;        //  Taste "Überweg" (Anforderung Fußgänger)

// Parameter "Ampel"
const byte aRot     =   5;        //  LED-Pin 
const byte aGelb    =   6;        //  "
const byte aGruen   =   7;        //  "
const byte aModus   =   8;        //  " (Signal Anforderung Tag-/Nacht-Modus)

const byte fFuss    =   9;        //  LED-Pins (Signal Anforderung f. Fussgänger)
const byte fWeiss   =  10;        //  " (Signal "Warten")
const byte fRot     =  11;        //  "
const byte fGruen   =  12;        //  "

const word zRot     =  30;        //  Sekunden
const word zRotgelb =   2;        //  "
const word zGruen   =  20;        //  "
const word zGelb    =   3;        //  "

// Parameter "Blaulicht"
const byte bPin     =  13;        //  Blaue LED
const word mEin     =  15;        //  Millis EIN
const word mAus     = 150;        //  Millis AUS

const byte wHol     =   2;        //  Wiederholungen
const word mZyk     = 555;        //  Millis Gesamt-Zyklus (Ein + Aus) * Wiederholung inkl. Warten
const word gAnz     =  25;        //  Anzahl kompletter Gesamt-Zyklen

// Instanzen
Taster          Modus(tMod);      //  "Nachtmodus" (Down-Aktiv)
Taster          Polizei(tPoli);   //  "Blaulicht"  (Down-Aktiv)
Taster          Ueberweg(tUeber); //  "Überweg"    (Down-Aktiv)

Warnblinker     Blaulicht( bPin, mEin, mAus, wHol, mZyk, gAnz );

Ampelschaltung  Ampel( aRot,   aGelb,        aGruen, aModus,  \
                       zRot,   zRotgelb,     zGruen, zGelb,   \
                       fWeiss, fRot, fGruen, fFuss            );  

void setup()
{
  Modus.begin();                  //  Buttons / Taster
  Polizei.begin();                //  "
  Ueberweg.begin();               //  "
  
  Ampel.begin();                  //  Ampelschaltung  
  Blaulicht.begin();              //  Blaulicht  
}

void loop()
{
  // --- Permanente Überwachung, Status-Updates etc. ---------------------
  //
  Blaulicht.Run();                //  Abarbeitung Blaulicht, nur bei Anforderung
  Ampel.Run();                    //  Abarbeitung Ampelschaltung, permanent
  
  // --- Aktionen auf Anforderung ----------------------------------------
  //
  if( Modus.KeyDown() )           //  Anforderung Tag-/Nachtmodus
    Ampel.Nachtmodus();           //  Bleibt dann bis neue Anforderung 

  if( Ueberweg.KeyDown() )        //  Anforderung Überweg 
    Ampel.Fussgaenger();          //  Wird in der Rotphase freigegeben
      
  if( Polizei.KeyDown() )         //  Anforderung Polizeieinsatz
    Blaulicht.Start();            //  Blinkt eine Weile, stoppt selbstständig       
}
