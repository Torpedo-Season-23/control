IController::IController() {
  for (uint8_t i = 0; i < 6; i++) {
    this->accArray[i] = 0;
  }
  for (uint8_t i = 0; i < 3; i++) {
    this->tdArray[i] = 0;
  }
  for (uint8_t i = 0; i < 2; i++) {
    this->verticalFrame[i] = 1500;
  }
  for (uint8_t i = 0; i < 8; i++) {
    this->flags[i] = false;
  }
  this->speeds[0] = LOW_SPEED;
  this->speeds[1] = NORMAL_SPEED;
  this->speeds[2] = HIGH_SPEED;
  this->speed = 1;
}

void IController::init() {
#if !defined(__MIPSEL__)
  while (!Serial)
    ;  // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (this->usb.Init() == -1)
    Serial.println("OSC did not start.");
  else
    Serial.print("Start");
}

int* IController::getHorizontalFrame() {
  return this->tdArray;
}
int* IController::getVerticalFrame() {
  return this->verticalFrame;
}
int* IController::getAccFrame() {
  return this->accArray;
}
int IController::getSpeed() {
  return this->speed;
}