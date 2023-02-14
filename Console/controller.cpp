#include "Arduino.h"
#include "controller.h"
#include "config.h"

USB Usb;
PS3USB PS3(&Usb);

uint8_t speeds[] = {LOW_SPEED_VALUE, NORMAL_SPEED_VALUE, HIGH_SPEED_VALUE};
void Controller::init() {

#if !defined(__MIPSEL__)
  while (!Serial)
    ;
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1)
      ;  //halt
  }
  Serial.print(F("\r\nPS3 USB Library Started"));
}
int* Controller::get_hframe() {
  return this->Td_array;
}
int Controller::getspeed() {
  return this->speed;
}
int* Controller::get_vframe() {
  return this->vertical_frame;
}
uint8_t* Controller::get_accframe() {
  return this->acc_array;
}

void Controller::Update() {
  Usb.Task();
  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
    this->manageHorizontalMotion();
    this->manageVerticalMotion();



    //acc frame
    if (PS3.getButtonClick(TRIANGLE)) {
      if (this->flags[0] == 0) {
        this->acc_array[0] = 1;
        this->flags[0] = 1;
      }
      else {
        this->acc_array[0] = 0;
        this->flags[0] = 0;
      }
    }
    if (PS3.getButtonClick(CIRCLE)) {
      if (this->flags[1] == 0) {
        this->acc_array[1] = 1;
        this->flags[1] = 1;
      } else {
        this->acc_array[1] = 0;
        this->flags[1] = 0;
      }
    }
    if (PS3.getButtonClick(CROSS)) {
      if (this->flags[2] == 0) {
        this->acc_array[2] = 1;
        this->flags[2] = 1;
      } else {
        this->acc_array[2] = 0;
        this->flags[2] = 0;
      }
    }
    if (PS3.getButtonClick(SQUARE)) {
      if (this->flags[3] == 0) {
        this->acc_array[3] = 1;
        this->flags[3] = 1;
      } else {
        this->acc_array[3] = 0;
        this->flags[3] = 0;
      }
    }
    //set led
    PS3.setLedOn(LED1);

    //set speed
    if (PS3.getButtonClick(L1)) 
      this->speed= max(this->speed-1,0); 
    if (PS3.getButtonClick(R1)) 
      this->speed= min(this->speed,SPEEDS_NUMBER-1);
  }
  delay(50);
}

void Controller::manageHorizontalMotion() {
  //hizontal frame
  float Tx, Ty, Tm;
  float fx, fy, fm, temp;
  Tx = PS3.getAnalogHat(LeftHatX);
  Ty = 255 - PS3.getAnalogHat(LeftHatY);
  Tm = PS3.getAnalogHat(RightHatX);

  Tx = map(Tx, 0, 255, -speeds[this->speed], speeds[this->speed]);
  Ty = map(Ty, 0, 255, -speeds[this->speed], speeds[this->speed]);
  Tm = map(Tm, 0, 255, -speeds[this->speed], speeds[this->speed]);
  if (Ty == -1) Ty = 0;
  fx = Tx / speeds[this->speed];
  fy = Ty / speeds[this->speed];
  fm = Tm / speeds[this->speed];
  temp = 42 / (abs(fx) + abs(fy) + abs(fm));
  Tx = fx * temp;
  Ty = fy * temp;
  Tm = fm * temp;
  this->Td_array[0] = Tx;
  this->Td_array[1] = Ty;
  this->Td_array[2] = Tm;
}

void Controller::manageVerticalMotion() {
  uint8_t direction = 0;
  if (PS3.getButtonPress(L2)) direction = -1; //Down
  else if (PS3.getButtonPress(R2)) direction = 1;
  this->vertical_frame[1] = 1500 + direction * speeds[this->speed];
  this->vertical_frame[0] = 1500 + direction * speeds[this->speed];
}
