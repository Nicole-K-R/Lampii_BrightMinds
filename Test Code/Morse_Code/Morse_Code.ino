#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);
int pinOut = 7;
bool enterWord = true;
String sentence = "";

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(pinOut, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  {
    lcd.setCursor(0,1);
    lcd.write(1);
  }
  int counter = 0;
  while(enterWord == true){
    Serial.println("Enter a word");
    sentence = Serial.readString();
    while(sentence == ""){//Wait for a word to be entered
      sentence = Serial.readString();
      delay(500);
    }
    lcd.clear();
    lcd.print(sentence);//Print word to LCD
    do{//Do morse code
      for (int i = 0; i < sentence.length(); i ++){
        morseCode(String(sentence.charAt(i)));
      }
      Serial.println("Would you like to enter a new word?");
      String redo = Serial.readString();
      while(redo == "" && true){//add timeout to replace true (2s)
        redo = Serial.readString();
      }
      if (redo == "F"){
        enterWord = false;
      }
      else if (redo == "T"){
        enterWord = true;
        sentence = "";
      }
    }while(sentence != "");//Wait for a response (go through at least once)
  }
}

void morseCode(String chara){
    Serial.println(chara);
    Serial.println(chara);
    if(chara == "A" || chara == "a"){
      morseA();
    }
    else if(chara == "B" || chara == "b"){
      morseB();
    }
    else if(chara == "C" || chara == "c"){
      morseB();
    }
    else if(chara == "D" || chara == "d"){
      morseD();
    }
    else if(chara == "E" || chara == "e"){
      morseE();
    }
    else if(chara == "F" || chara == "f"){
      morseF();
    }
    else if(chara == "G" || chara == "g"){
      morseG();
    }
    else if(chara == "H" || chara == "h"){
      morseH();
    }
    else if(chara == "I" || chara == "i"){
      morseI();
    }
    else if(chara == "J" || chara == "j"){
      morseJ();
    }
    else if(chara == "K" || chara == "k"){
      morseK();
    }
    else if(chara == "L" || chara == "l"){
      morseL();
    }
    else if(chara == "M" || chara == "m"){
      morseM();
    }
    else if(chara == "N" || chara == "n"){
      morseN();
    }
    else if(chara == "O" || chara == "o"){
      morseO();
    }
    else if(chara == "P" || chara == "p"){
      morseP();
    }
    else if(chara == "Q" || chara == "q"){
      morseQ();
    }
    else if(chara == "R" || chara == "r"){
      morseR();
    }
    else if(chara == "S" || chara == "s"){
      morseS();
    }
    else if(chara == "T" || chara == "t"){
      morseT();
    }
    else if(chara == "U" || chara == "u"){
      morseU();
    }
    else if(chara == "V" || chara == "v"){
      morseV();
    }
    else if(chara == "W" || chara == "w"){
      morseW();
    }
    else if(chara == "X" || chara == "x"){
      morseX();
    }
    else if(chara == "Y" || chara == "y"){
      morseY();
    }
    else if(chara == "Z" || chara == "z"){
      morseZ();
    }
    else if(chara == "0"){
      morseS();
    }
    else if(chara == "1"){
      morse1();
    }
    else if(chara == "2"){
      morse2();
    }
    else if(chara == "3"){
      morse3();
    }
    else if(chara == "4"){
      morse4();
    }
    else if(chara == "5"){
      morse5();
    }
    else if(chara == "6"){
      morse6();
    }
    else if(chara == "7"){
      morse7();
    }
    else if(chara == "8"){
      morse8();
    }
    else if(chara == "9"){
      morse9();
    }
}



void morseA(){//.-
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseB(){//-...
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseC(){//-.-.
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseD(){//-..
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseE(){//.
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseF(){//..-.
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseG(){//--.
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseH(){//....
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseI(){//..
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseJ(){//.---
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseK(){//-.-
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseL(){//.-..
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseM(){//--
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseN(){//-.
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseO(){//---
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseP(){//.--.
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseQ(){//--.-
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseR(){//.-.
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseS(){//...
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseT(){//-
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseU(){//..-
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseV(){//...-
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseW(){//.--
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseX(){//-..-
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseY(){//-.--
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morseZ(){//--..
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse1(){//.----
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse2(){//..---
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse3(){//...--
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse4(){//....-
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse5(){//.....
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse6(){//-....
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse7(){//--...
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse8(){//---..
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse9(){//----.
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(500);
  digitalWrite(pinOut, LOW);
  delay(500);
}

void morse0(){//-----
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(200);
  digitalWrite(pinOut, HIGH);
  delay(1500);
  digitalWrite(pinOut, LOW);
  delay(500);
}
