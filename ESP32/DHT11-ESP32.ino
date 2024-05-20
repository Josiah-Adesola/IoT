#include "DHT.h"

#define DHTPIN 4

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT11 TEST!"));

  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);

  float h = dht.readHumidity();

  //Read temperature as celsius (the default)

  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)){
    Serial.println(F("Failed to read from HT Sensor!"));
    return;
  }

  // Compute heat index in Celsius
  float hic = dht.computeHeatIndex(t,h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(F("% Heat Index: "));
  Serial.print(hic);
  Serial.println(F("°C "));
}
