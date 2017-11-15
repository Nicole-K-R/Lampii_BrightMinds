#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  char c;
  if(Serial.available()>0){
    Serial.println("Starting - in loop");
    c = Serial.read();
    Serial.println("read");
      if(c=='t'){
        Serial.println("it is t");
        readSensor();
      }
      else{
        Serial.println(c);
        digitalWrite(LED_BUILTIN, LOW);
      }
  }
}

void readSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
}
