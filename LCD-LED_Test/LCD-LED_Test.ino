#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  {
    lcd.setCursor(0,1);
    lcd.write(1);
  }
  lcd.print("Hello Tracy :)");
}


