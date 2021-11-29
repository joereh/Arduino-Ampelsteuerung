#define PIN_TEST A0

#define REF_VOLTAGE    5.0
#define PIN_STEPS   1024.0

void setup()
{
    Serial.begin(9600);
}

float volt;

void loop()
{

    volt = (analogRead(PIN_TEST)*REF_VOLTAGE/PIN_STEPS);      
    Serial.print("U = ");
    //Serial.print(analogRead(PIN_TEST)*REF_VOLTAGE/PIN_STEPS);
    Serial.print(volt);
    Serial.println(" V");
    delay(2000);
}
