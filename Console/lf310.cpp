/////////////////////////////////////////////////////////////////////////
///  \file lf310.cpp
/// \brief This is the USB HID driver for the Logitech F310 game pad
///
/// \author Alan Ford
/////////////////////////////////////////////////////////////////////////
#include "lf310.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse a HID data report from the Logitech F310
///////////////////////////////////////////////////////////////////////////////
void LF310::ParseHIDData(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {
  if (HIDUniversal::VID != LF310_VID || HIDUniversal::PID != LF310_PID)  // Make sure the right device is actually connected
    return;
  memcpy(&lf310Data, buf, min(len, MFK_CASTUINT8T sizeof(lf310Data)));
  static LF310DataButtons oldButtonState;
  if (lf310Data.btn.val != oldButtonState.val) {                     // Check if anything has changed
    buttonClickState.val = lf310Data.btn.val & ~oldButtonState.val;  // Update click state variable
    oldButtonState.val = lf310Data.btn.val;
  }
}

void Xbox::Update() {
  this->Usb.Task();
  this->update_hmotion();
  this->update_vmotion();
  //speed
  if (this->lf310.buttonClickState.LBbutton) {
    if (this->speed > 0) this->speed--;
    this->lf310.buttonClickState.LBbutton = 0;
  }
  if (this->lf310.buttonClickState.RBbutton) {
    if (this->speed < 2) this->speed++;
    this->lf310.buttonClickState.RBbutton = 0;
  }
  //acc frame
  if (this->lf310.buttonClickState.Ybutton) {
    if (this->flags[0] == 0) {
     this->acc_array[0] = 1;
      this->flags[0] = 1;
    } else {
      this->acc_array[0] = 0;
      this->flags[0] = 0;
    }
    this->lf310.buttonClickState.Ybutton = 0;
  }
  if (this->lf310.buttonClickState.Bbutton) {
    if (this->flags[1] == 0) {
      this->acc_array[1] = 1;
      this->flags[1] = 1;
    } else {
      this->acc_array[1] = 0;
      this->flags[1] = 0;
    }
    this->lf310.buttonClickState.Bbutton = 0;
  }
  if (this->lf310.buttonClickState.Abutton) {
    if (this->flags[2] == 0) {
      this->acc_array[2] = 1;
      this->flags[2] = 1;
    } else {
      this->acc_array[2] = 0;
      this->flags[2] = 0;
    }
    this->lf310.buttonClickState.Abutton = 0;
  }
  if (this->lf310.buttonClickState.Xbutton) {
    if (this->flags[3] == 0) {
      this->acc_array[3] = 1;
      this->flags[3] = 1;
    } else {
      this->acc_array[3] = 0;
      this->flags[3] = 0;
    }
    this->lf310.buttonClickState.Xbutton = 0;
  }
  delay(50);
}
void Xbox::update_vmotion() {
  int8_t direction = 0;
  if (this->lf310.buttonClickState.LTbutton) direction = -1;  //Down
  else if (this->lf310.buttonClickState.RTbutton) direction = 1;
  this->vertical_frame[0] = 1500 + direction * map(speeds[this->speed], 0, 128, 0, 400);
  this->vertical_frame[1] = this->vertical_frame[0];
}
void Xbox::update_hmotion() {
  float Tx, Ty, Tm;
  float factor, sum;
  Tx = map(this->lf310.lf310Data.X, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  Ty = map(255 - this->lf310.lf310Data.Y, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  Tm = map(this->lf310.lf310Data.Z, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  if (Tx < 30 && Tx > -30) Tx = 0;
  if (Ty < 30 && Ty > -30) Ty = 0;
  if (Tm < 30 && Tm > -30) Tm = 0;
  sum =abs (Tx) +abs (Ty) +abs (Tm);
  factor = this->speeds[this->speed] / sum;
  Tx *= factor;
  Ty *= factor;
  Tm *= factor;
  this->Td_array[0] = Tx;
  this->Td_array[1] = Ty;
  this->Td_array[2] = Tm;
}
