PS3GamePad::PS3GamePad() {
  this->ps3 = new PS3USB(&this->usb);
}

void PS3GamePad::update() {
  this->usb.Task();
  if (this->ps3->PS3Connected || this->ps3->PS3NavigationConnected) {
    this->updateHorizontalMotion();
    this->updateVerticalMotion();
    if (this->ps3->getButtonClick(TRIANGLE)) {
      if (this->flags[0] == 0) {
        this->accArray[0] = 1;
        this->flags[0] = 1;
      } else {
        this->accArray[0] = 0;
        this->flags[0] = 0;
      }
    }
    if (this->ps3->getButtonClick(CIRCLE)) {
      if (this->flags[1] == 0) {
        this->accArray[1] = 1;
        this->flags[1] = 1;
      } else {
        this->accArray[1] = 0;
        this->flags[1] = 0;
      }
    }
    if (this->ps3->getButtonClick(CROSS)) {
      if (this->flags[2] == 0) {
        this->accArray[2] = 1;
        this->flags[2] = 1;
      } else {
        this->accArray[2] = 0;
        this->flags[2] = 0;
      }
    }
    if (this->ps3->getButtonClick(SQUARE)) {
      if (this->flags[3] == 0) {
        this->accArray[3] = 1;
        this->flags[3] = 1;
      } else {
        this->accArray[3] = 0;
        this->flags[3] = 0;
      }
    }
    this->ps3->setLedOn(LED1);

    if (this->ps3->getButtonClick(L1)) {
      if (this->speed > 0)
        this->speed--;
    }
    if (this->ps3->getButtonClick(R1)) {
      if (this->speed < 2) this->speed++;
    }
  }
  Serial.print("Speed: ");
  Serial.println(this->speed);
  delay(50);
}

void PS3GamePad::updateVerticalMotion() {
  int8_t direction = 0;
  if (this->ps3->getButtonPress(L2))
    direction = -1;  // Down
  else if (this->ps3->getButtonPress(R2))
    direction = 1;
  this->verticalFrame[0] = 1500 + direction * map(this->speeds[this->speed], 0, 128, 0, 400);
  this->verticalFrame[1] = this->verticalFrame[0];
}

void PS3GamePad::updateHorizontalMotion() {
  float Tx, Ty, Tm;
  float factor, sum;
  Tx = this->ps3->getAnalogHat(LeftHatX);
  Ty = 255 - this->ps3->getAnalogHat(LeftHatY);
  Tm = this->ps3->getAnalogHat(RightHatX);

  Tx = map(Tx, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  Ty = map(Ty, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  Tm = map(Tm, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  if (Ty == -1) Ty = 0;
  sum = abs(Tx) + abs(Ty) + abs(Tm);
  factor = this->speeds[this->speed] / sum;
  Tx *= factor;
  Ty *= factor;
  Tm *= factor;
  this->tdArray[0] = Tx;
  this->tdArray[1] = Ty;
  this->tdArray[2] = Tm;
}