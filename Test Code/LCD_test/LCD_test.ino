#include <LiquidCrystal.h>

// inicia el lcd con los correspondientes pines
LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

byte customchar[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,     
};

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(1, customchar);
  lcd.print("Custom!");
}

void loop() {
  {
    lcd.setCursor(0,1);
    lcd.write(1);
  }
  lcd.print("Hello Tracy :)");
//  
//  lcd.print("printing text");
//
//  delay(3000);
//
//  lcd.clear();
//  lcd.setCursor(0,1);
//  lcd.print("Setting Cursor");
//
//  delay(3000);
//
//  lcd.clear();
//  lcd.print("Blank Cursor");
//  lcd.blink();
//
//  delay(3000);
//
//  lcd.clear();
//  lcd.noBlink();
//  lcd.print("Uline Cursor");
//  lcd.cursor();
//
//  delay(3000);
//
//  lcd.clear();
//  lcd.print("No Cursor");
//  lcd.noCursor();
//
//  delay(3000);
//
//  lcd.clear();
//  lcd.print("no display");
//
//  delay(1000);
//
//  lcd.noDisplay();
//
//  lcd.clear();
//  lcd.print("display on");
//
//  delay(3000);
//  
//  lcd.display();
}


