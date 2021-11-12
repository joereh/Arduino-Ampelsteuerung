#include <RCSwitch.h> // Library
RCSwitch receiver = RCSwitch(); //Definition

const int led_pin = 5; // LED ist an Pin D5
// Add comment
void setup() {
  pinMode(led_pin, OUTPUT); // D5 ist ein OUTPUT
  receiver.enableReceive(0); // Empfänger hängt an D2, was der Interrupt Pin 0 ist, nicht verwirren lassen
}

void loop() {
  if (receiver.available()){ //wenn daten empfangen werden, dann:
    int code = receiver.getReceivedValue(); //code ist das was empfangen wird
    if (code == 2345){ // wenn der empfangene Code "2345" lautet dann:
      digitalWrite(led_pin, HIGH); // LED pin gibt Strom aus
      delay(150); // arduino wartet 150ms, solange bleibt pin D5 auf HIGH
      digitalWrite(led_pin, LOW); // LED pin gibt keinen Strom aus
      receiver.resetAvailable(); // Receiver geht wieder auf Empfang
    }
  }
}
