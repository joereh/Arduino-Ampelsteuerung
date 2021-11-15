//www.elegoo.com
//2016.12.8

// define pins
#define RED 3
#define YELLOW 4
#define GREEN 5
int buttonApin = 9;
int buttonBpin = 8;
int buttonCpin = 10;
int buttonDpin = 11;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);
  pinMode(buttonCpin, INPUT_PULLUP); 
  pinMode(buttonDpin, INPUT_PULLUP); 
  
  digitalWrite(RED, HIGH);
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

if (digitalRead(buttonApin) == LOW)
  {
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
}

 if (digitalRead(buttonBpin) == LOW)
  {
   digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  }

 if (digitalRead(buttonCpin) == LOW)
  {
   digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  }
if (digitalRead(buttonDpin) == LOW)
  {

  for (int i = 0; i < 100; i += 1) // 
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
  digitalWrite(GREEN, HIGH);
  delay(1750);
  }
    
  
  }
  
}
