#include "IController.h"

int* IController::get_hframe() {
  return this->Td_array;
}
int* IController::get_vframe() {
  return this->vertical_frame;
}
// void IController::set_hframe(int array){this->Td_array=array}
// void IController::set_vframe(int *array){this->vertical_frame=array}
int* IController::get_accframe() {
  return this->acc_array;
}
int IController::getspeed() {
  if (this->speed == 0)
    return 100;
  if (this->speed == 1)
    return 250;
  if (this->speed == 2)
    return 400;
  // return this->speed;
}
void IController::init() {
#if !defined(__MIPSEL__)
  while (!Serial)
    ;  // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (this->Usb.Init() == -1) Serial.println("OSC did not start.");
  else Serial.print("Start");
}