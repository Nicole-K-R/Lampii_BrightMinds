int whiteL = 8;
int whiteM = 9;
int whiteH = 10;
int yellowL = 11;
int yellowM = 12;
int yellowH = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(whiteL, OUTPUT);
  pinMode(whiteM, OUTPUT);
  pinMode(whiteH, OUTPUT);
  pinMode(yellowL, OUTPUT);
  pinMode(yellowM, OUTPUT);
  pinMode(yellowH, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello");
}

void loop() {
  Serial.println("White Low - ON");
  turnOnWhite(1);
  delay(1000);
  Serial.println("White Low - OFF");
  turnOff();
  delay(1000);
  
  Serial.println("White Medium - ON");
  turnOnWhite(2);
  delay(1000);
  Serial.println("White Low - OFF");
  turnOff();
  delay(1000);

  Serial.println("White High - ON");
  turnOnWhite(3);
  delay(1000);
  Serial.println("White High - OFF");
  turnOff();
  delay(5000);
  
  Serial.println("Yellow Low - ON");
  turnOnYellow(1);
  delay(1000);
  Serial.println("Yellow Low - OFF");
  turnOff();
  delay(1000);
  
  Serial.println("Yellow Medium - ON");
  turnOnYellow(2);
  delay(1000);
  Serial.println("Yellow Low - OFF");
  turnOff();
  delay(1000);

  Serial.println("Yellow High - ON");
  turnOnYellow(3);
  delay(1000);
  Serial.println("Yellow High - OFF");
  turnOff();
  delay(1000);
}

void turnOff(){
  digitalWrite(whiteL, LOW);
  digitalWrite(whiteM, LOW);
  digitalWrite(whiteH, LOW);
  digitalWrite(yellowL, LOW);
  digitalWrite(yellowM, LOW);
  digitalWrite(yellowH, LOW);
}

void turnOnWhite(int level){
  //3 = High, 1 = Low
  if(level > 0){
    digitalWrite(whiteL, HIGH);
  }
  if(level > 1){
    digitalWrite(whiteM, HIGH);
  }
  if(level > 2){
    digitalWrite(whiteH, HIGH);
  }
}

void turnOnYellow(int level){
  //3 = High, 1 = Low
  if(level > 0){
    digitalWrite(yellowL, HIGH);
  }
  if(level > 1){
    digitalWrite(yellowM, HIGH);
  }
  if(level > 2){
    digitalWrite(yellowH, HIGH);
  }
}
