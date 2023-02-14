#include "Arduino.h"
#include "controller.h"
#include "config.h"

USB Usb;
PS3USB PS3(&Usb);
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

  //hizontal frame
    float Tx, Ty, Tm;
    float fx,fy,fm,temp;
    Tx = PS3.getAnalogHat(LeftHatX);
    Ty = 255 - PS3.getAnalogHat(LeftHatY);
    Tm = PS3.getAnalogHat(RightHatX);
    switch (this->speed){
      case 1:
        Tx = map(Tx, 0, 255, -42, 42);
        Ty = map(Ty, 0, 255, -42, 42);
        Tm = map(Tm, 0, 255, -42, 42);
        if (Ty == -1) Ty = 0;
        fx=Tx/42;
        fy=Ty/42;
        fm=Tm/42;
        temp=42/(abs(fx)+abs(fy)+abs(fm));
        Tx=fx*temp;
        Ty=fy*temp;
        Tm=fm*temp;
        this->Td_array[0] = Tx;
        this->Td_array[1] = Ty;
        this->Td_array[2] = Tm;
        break;
      case 2:
        Tx = map(Tx, 0, 255, -85, 85);
        Ty = map(Ty, 0, 255, -85, 85);
        Tm = map(Tm, 0, 255, -85, 85);
        if (Ty == -1) Ty = 0;
        fx=Tx/85;
        fy=Ty/85;
        fm=Tm/85;
        temp=85/(abs(fx)+abs(fy)+abs(fm));
        Tx=fx*temp;
        Ty=fy*temp;
        Tm=fm*temp;
        this->Td_array[0] = Tx;
        this->Td_array[1] = Ty;
        this->Td_array[2] = Tm;
        break;
      case 3:
        Tx = map(Tx, 0, 255, -128, 128);
        Ty = map(Ty, 0, 255, -128, 128);
        Tm = map(Tm, 0, 255, -128, 128);
        if (Ty == -1) Ty = 0;
        fx=Tx/128;
        fy=Ty/128;
        fm=Tm/128;
        temp=128/(abs(fx)+abs(fy)+abs(fm));
        Tx=fx*temp;
        Ty=fy*temp;
        Tm=fm*temp;
        this->Td_array[0] = Tx;
        this->Td_array[1] = Ty;
        this->Td_array[2] = Tm;
        break;
      default:
        this->Td_array[0] = 0;
        this->Td_array[1] = 0;
        this->Td_array[2] = 0;
        break;
    }
  
  //vertical frame
  switch(this->speed){
    case 1:
    if (PS3.getButtonPress(L2)) {
        this->vertical_frame[1] = 1633;
        this->vertical_frame[0] = 1367;
        } 
    else {
        this->vertical_frame[1] = 1500;
        this->vertical_frame[0] = 1500;}
    if (PS3.getButtonPress(R2)||PS3.getButtonPress(L2)) {
        this->vertical_frame[0] = 1633;
        this->vertical_frame[1] = 1367;
        if (PS3.getButtonPress(L2)) {
          this->vertical_frame[1] = 1633;
          this->vertical_frame[0] = 1367;} 
      } 
    else {
        this->vertical_frame[1] = 1500;
        this->vertical_frame[0] = 1500;}

    break;
    case 2:
    if (PS3.getButtonPress(L2)) {
        this->vertical_frame[1] = 1766;
        this->vertical_frame[0] = 1234;} 
    else {
        this->vertical_frame[1] = 1500;
        this->vertical_frame[0] = 1500;}
    if (PS3.getButtonPress(R2)||PS3.getButtonPress(L2)) {
        this->vertical_frame[0] = 1766;
        this->vertical_frame[1] = 1234;
        if (PS3.getButtonPress(L2)) {
          this->vertical_frame[1] = 1766;
          this->vertical_frame[0] = 1234;} 
        } 
    else {
        this->vertical_frame[1] = 1500;
        this->vertical_frame[0] = 1500;}
    break;
    case 3:
    if (PS3.getButtonPress(L2)) {
        this->vertical_frame[1] = 1900;
        this->vertical_frame[0] = 1100;} 
    else {
        this->vertical_frame[1] = 1500;
        this->vertical_frame[0] = 1500;}
    if (PS3.getButtonPress(R2)||PS3.getButtonPress(L2)) {
        this->vertical_frame[0] = 1900;
        this->vertical_frame[1] = 1100;
        if (PS3.getButtonPress(L2)) {
          this->vertical_frame[1] = 1900;
          this->vertical_frame[0] = 1100;} 
        } 
    else {
        this->vertical_frame[1] = 1500;
        this->vertical_frame[0] = 1500;}
    break;
    default:
    this->vertical_frame[1] = 1500;
    this->vertical_frame[0] = 1500;
    break;
  }

  //acc frame
    if (PS3.getButtonClick(TRIANGLE)) {
        if (this->flags[0] == 0) {
            this->acc_array[0] = 1;
            this->flags[0] = 1; } 
        else {
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
    if (PS3.getButtonClick(L1)) {
      if (this->speed > 0)
        this->speed--;
    }
    if (PS3.getButtonClick(R1)) {
      if (this->speed < 3) this->speed++;
    }
  }
  delay(50);
}
