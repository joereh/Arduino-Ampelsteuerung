#include <RCSwitch.h> //Library
RCSwitch sender = RCSwitch(); //Definition

const int code = 2345; //Der Code den wir übermitteln wollen
const int senderpin = 10; //Der Pin an dem wir den DataPin des Transmitters angeschlossen haben

void setup() {
  sender.enableTransmit(senderpin); //Wir sagen dem Arduino wo wir senden, hier unser DataPin
}

void loop() {
  sender.send(code, 16); //Wir senden den Code mit 16 Bit
  delay(1000); //Arduino wartet nach dem Senden 1000ms
}
