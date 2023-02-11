Sensor::Sensor() {
  this->working = false;
  this->data = 0;
}

void Sensor::startWorking() {
  this->working = true;
}

void Sensor::stopWorking() {
  this->working = false;
}

void Sensor::toggleWorking() {
  this->working = !this->working;
}

float Sensor::getData() {
  return this->data;
}