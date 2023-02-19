#include "Arduino.h"
#include "psgamepad.h"

void PSGamepad::Update() {
  this->Usb.Task();
  if (this->PS3.PS3Connected || this->PS3.PS3NavigationConnected) {
    this->update_hmotion();
    this->update_vmotion();
    //acc frame
    if (this->PS3.getButtonClick(TRIANGLE)) {
      if (this->flags[0] == 0) {
        this->acc_array[0] = 1;
        this->flags[0] = 1;
      } else {
        this->acc_array[0] = 0;
        this->flags[0] = 0;
      }
    }
    if (this->PS3.getButtonClick(CIRCLE)) {
      if (this->flags[1] == 0) {
        this->acc_array[1] = 1;
        this->flags[1] = 1;
      } else {
        this->acc_array[1] = 0;
        this->flags[1] = 0;
      }
    }
    if (this->PS3.getButtonClick(CROSS)) {
      if (this->flags[2] == 0) {
        this->acc_array[2] = 1;
        this->flags[2] = 1;
      } else {
        this->acc_array[2] = 0;
        this->flags[2] = 0;
      }
    }
    if (this->PS3.getButtonClick(SQUARE)) {
      if (this->flags[3] == 0) {
        this->acc_array[3] = 1;
        this->flags[3] = 1;
      } else {
        this->acc_array[3] = 0;
        this->flags[3] = 0;
      }
    }
    //set led
    this->PS3.setLedOn(LED1);

    //set speed
    if (this->PS3.getButtonClick(L1)) {
      if (this->speed > 0)
        this->speed--;
    }
    if (this->PS3.getButtonClick(R1)) {
      if (this->speed < 2) this->speed++;
    }
  }
  delay(50);
}
void PSGamepad::update_vmotion() {
  int8_t direction = 0;
  if (this->PS3.getButtonPress(L2)) direction = -1;  //Down
  else if (this->PS3.getButtonPress(R2)) direction = 1;
  this->vertical_frame[0] = 1500 + direction * map(this->speeds[this->speed], 0, 128, 0, 400);
  this->vertical_frame[1] = this->vertical_frame[0];
}
void PSGamepad::update_hmotion() {
  //hizontal frame
  float Tx, Ty, Tm;
  float factor, sum;
  Tx = PS3.getAnalogHat(LeftHatX);
  Ty = 255 - PS3.getAnalogHat(LeftHatY);
  Tm = PS3.getAnalogHat(RightHatX);

  Tx = map(Tx, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  Ty = map(Ty, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  Tm = map(Tm, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  if (Ty == -1) Ty = 0;
  sum =abs (Tx) +abs (Ty) +abs (Tm);
  factor = this->speeds[this->speed] / sum;
  Tx *= factor;
  Ty *= factor;
  Tm *= factor;  
  this->Td_array[0] = Tx;
  this->Td_array[1] = Ty;
  this->Td_array[2] = Tm;
}