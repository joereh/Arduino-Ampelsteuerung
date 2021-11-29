#define LED_ROT   2    // Pin PD2
#define LED_GELB  3    // Pin PD3
#define LED_GRUEN 4    // Pin PD4

void setup() 
{
  pinMode(LED_ROT,   OUTPUT);
  pinMode(LED_GELB,  OUTPUT);
  pinMode(LED_GRUEN, OUTPUT);
}

void thread_rot()
{
    static enum {AUS, EIN} zustand = AUS;
    static unsigned long int warteSeit = 0;

    switch (zustand)
    {
        case AUS:
            if (millis() - warteSeit >= 100)     // Bedingung: 100 ms später
            {
                digitalWrite(LED_ROT, HIGH);     // Reaktion: LED ein schalten
                warteSeit = millis();  
                zustand = EIN;                   // Neuer Zustand: LED ist EIN
            }          
            break;

        case EIN: 
            if (millis() - warteSeit >= 100)     // Bedingung: 100 ms später 
            {
                digitalWrite(LED_ROT, LOW);      // Reaktion: LED aus schalten 
                warteSeit = millis();  
                zustand = AUS;                   // Neuer Zustand: LED ist AUS
            }          
            break;
    }
}

void thread_gelb()
{
    static enum {AUS, EIN} zustand = AUS;
    static unsigned long int warteSeit = 0;

    switch (zustand)
    {
        case AUS:   
            if (millis() - warteSeit >= 253) 
            {
                digitalWrite(LED_GELB, HIGH); 
                warteSeit = millis();  
                zustand = EIN; 
            }          
            break;

        case EIN: 
            if (millis() - warteSeit >= 253) 
            {
                digitalWrite(LED_GELB, LOW); 
                warteSeit = millis();  
                zustand = AUS; 
            }          
            break;
    }
}

void thread_gruen()
{
    static enum {AUS, EIN} zustand = AUS;
    static unsigned long int warteSeit = 0;

    switch (zustand)
    {
        case AUS:   
            if (millis() - warteSeit >= 378) 
            {
                digitalWrite(LED_GRUEN, HIGH); 
                warteSeit = millis();  
                zustand = EIN; 
            }          
            break;

        case EIN: 
            if (millis() - warteSeit >= 378) 
            {
                digitalWrite(LED_GRUEN, LOW); 
                warteSeit = millis();  
                zustand = AUS; 
            }          
            break;
    }
}

void loop() 
{
    thread_rot();
    thread_gelb();
    thread_gruen();
} 
