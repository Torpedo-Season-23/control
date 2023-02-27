#include "Leakage.h"
#include "DHT.h"

DHT dht(DHTPIN, DHTTYPE);

LeakageSensor::LeakageSensor() {
  this->humidity = 0;
  this->temperature = 0;
}

void LeakageSensor::init() {
  dht.begin();
}

void LeakageSensor::update() {
  delay(2000);
  this->humidity = dht.readHumidity();
  this->temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Temperature:");
  Serial.print(temperature);
  Serial.print(" c");
  Serial.print(" //Humidity: ");
  Serial.print(humidity);
  Serial.print(" %/n");
}

void LeakageSensor::setSensor(int i) {
  this->sensor_num = (uint8_t)i;
}

uint8_t LeakageSensor::getHumidity() {
  this->update();
  return ((uint8_t)this->humidity);
}

uint8_t LeakageSensor::getTemperature() {
  this->update();
  return ((uint8_t)this->temperature);
}

uint8_t LeakageSensor::getSensorNum() {
  return this->sensor_num;
}