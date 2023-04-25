#include "Leakage.h"
#include "DHT.h"
#include "config.h"

DHT* dht[8];  //needs to be tested

LeakageSensor::LeakageSensor() {
  for (int i = 0; i < SENSORS_NUM; i++) {
    this->humidity[i] = 0;
    this->temperature[i] = 0;
  }
}

void LeakageSensor::init() {
  int sensorsPin[8] = { A0, A1, A2, A3, 7, 6, 4, 2 };
  for (int i = 0; i < SENSORS_NUM; i++) {
    dht[i] = new DHT(sensorsPin[i], DHTTYPE);
    dht[i]->begin();
  }
}

void LeakageSensor::update() {
  // delay(2000);
  int i;
  for (i = 0; i < SENSORS_NUM; i++) {
    this->humidity[i] = dht[i]->readHumidity();//
    this->temperature[i] = dht[i]->readTemperature();


    // if (isnan(this->humidity[i]) || isnan(this->temperature[i])) {
    //   Serial.print(F("Failed to read from DHT sensor! SENSOR NUMBER:"));
    //   Serial.println(i);
    //   continue;
   // }
    // Serial.println();
    // Serial.print("Leakage ");
    // Serial.print(i);
    // Serial.print(" ");
    // Serial.print(humidity[i]);
    //Serial.print(" | ");

    // Serial.print("Temperature:");
    // Serial.print(this->temperature[i]);
    // Serial.print(" c");
    // Serial.print(" //Humidity: ");
    // Serial.print(this->humidity[i]);
    // Serial.print("\n");



    // Check if any reads failed and exit early (to try again).
    if (isnan(this->humidity[i]) || isnan(this->temperature[i])) {
      Serial.print(F("Failed to read from DHT sensor! SENSOR NUMBER:"));
      Serial.print(i);
      Serial.println();
      continue;
    }

    // Serial.print("Temperature:");
    // Serial.print(this->temperature[i]);
    // Serial.println();
    // Serial.println(i);
    // Serial.print(" c");
    // Serial.print(" //Humidity: ");
    // Serial.print(this->humidity[i]);
    // Serial.println(i);
    // Serial.println("\n");

    // Serial.print(" %\n");
  }
  Serial.println();
}

uint8_t* LeakageSensor::getHumidity() {
  this->update();
  return (this->humidity);//(uint8_t*)
}

uint8_t* LeakageSensor::getTemperature() {
  this->update();
  return ((uint8_t)this->temperature);
}
