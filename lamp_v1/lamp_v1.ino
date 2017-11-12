int trigPin = 6;    //Trig - Blue
int echoPin = 7;    //Echo - Green
long duration, cm;
int whiteL = 8; //Yellow
int whiteM = 9; //Orange
int whiteH = 10; //Purple
int yellowL = 11; //White
int yellowM = 12; //Grey
int yellowH = 13; //Brown/Grey
int lightIn = A0; //Purple - Male_to_Female
int currentLev = 2;
int newLev = 2;
String currentCol = "w";
String newCol = "w";

void setup() {
  turnOnWhite(2);
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(whiteL, OUTPUT);
  pinMode(whiteM, OUTPUT);
  pinMode(whiteH, OUTPUT);
  pinMode(yellowL, OUTPUT);
  pinMode(yellowM, OUTPUT);
  pinMode(yellowH, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(lightIn, INPUT);
}

void loop() {
  if (analogRead(lightIn) < 300){
    newCol = "y";
  }
  else if (analogRead(lightIn) > 300){
    newCol = "w";
  }
  //turn off
  int distanceCm = getDistance();
  newLev = getLevel(distanceCm);
  if (currentLev == newLev && currentCol == newCol){
    Serial.println("Same");
  }
  else{
    if (currentLev != newLev){
      Serial.println("Different Level");
      Serial.println(String(distanceCm) + " cm");
      Serial.println(String(currentLev) + " - " + String(newLev));
    }
    if (currentCol != newCol){
      Serial.println("Different Colour");
      Serial.println(currentCol + " -" + newCol+"");
    }
    
    turnOff();
    if (newCol=="w"){
      turnOnWhite(newLev);
    }
    else if (newCol=="y"){
      turnOnYellow(newLev);
    }
    else if (newCol=="OFF"){
      turnOff();
    }
  }
  currentLev = newLev;
  currentCol = newCol;
}

int getLevel(int dist){
  if (dist < 16){
    newLev = 1;
  }
  else if (dist <20){
    newLev = 2;
  }
  else{
    newLev = 3;
  }
  return newLev;
}

void turnOff(){
  Serial.println("Turn Off");
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

float getDistance(){
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  Serial.print("cm: ");
  Serial.print(cm);
  Serial.println();
  delay(100);
  return cm;
}

