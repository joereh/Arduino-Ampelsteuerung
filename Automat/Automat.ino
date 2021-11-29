const int buttonA = 2;
const int buttonB = 4;
const int ledPin = 13;

enum AutomatenZustand {START,WaitForA,WaitForB,ACTIVE};
AutomatenZustand zustand = START;

int ledState = LOW;
int aktiverZustand = 0;
unsigned long previousMillis = 0;
const long interval = 2000;


void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonA , INPUT);
  pinMode(buttonB, INPUT);
  

}

void loop() {
    automat();
}

void automat() {
   int buttonStateA = digitalRead(buttonA);
   int buttonStateB = digitalRead(buttonB);
   
   unsigned long currentMillis = millis();

   switch(zustand){
           case START:
                       ledState = LOW;
                       digitalWrite(ledPin,ledState);
                       if(buttonStateA == LOW && buttonStateB == LOW){
                        zustand = WaitForA;
                       }
                       
                       break;
            case WaitForA:
                       if(buttonStateA == HIGH){  
                        zustand = WaitForB;
                        }
                       break;
                   
             case WaitForB:
                       if(buttonStateB == HIGH){
                         ledState = HIGH;
                         digitalWrite(ledPin,ledState);
                         zustand = ACTIVE;
                         }
                         break;
                         
            case ACTIVE:
                        if(buttonStateB == LOW){
                         if(currentMillis - previousMillis >= interval){
                           previousMillis = currentMillis;
                           zustand = START;  
                           }
                         }
                         break;
                      
     
     }
  }
