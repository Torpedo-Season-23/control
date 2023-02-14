Sensor::Sensor() {
  this->working = false;
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