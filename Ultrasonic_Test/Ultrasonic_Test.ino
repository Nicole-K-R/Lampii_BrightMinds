int pinIn = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinIn, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(pinIn);
  Serial.println(value);
  delay(1000);
}
