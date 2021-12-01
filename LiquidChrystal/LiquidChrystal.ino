#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{

  lcd.init();
  lcd.init();

  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Hackster");
  lcd.setCursor(4,0);
}

void loop()
{
  lcd.setCursor(4,0);
  lcd.print("Hackster");
}
