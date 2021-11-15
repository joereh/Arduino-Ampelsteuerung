// define pins
#define RED 3
#define YELLOW 4
#define GREEN 5
//starte Ampelschaltung
int buttonBpin = 12;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(buttonBpin, INPUT_PULLUP);

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
}
// define variables
int redValue;
int greenValue;
int blueValue;

// main loop
void loop()
{
#define delayTime 4000 // fading time between colors

// starte Ampelschaltung 
if (digitalRead(buttonBpin) == LOW)
  {
  
  for (int i = 0; i < 10000000; i += 1) // 
  {
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  delay(delayTime);
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(1750);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(delayTime);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(1750);
  }
     
  }
  
}
