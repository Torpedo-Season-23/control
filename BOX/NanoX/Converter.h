#include <Arduino.h>
#include <Wire.h>
#include <math.h>
#ifndef _Converter_H_
#define _Converter_H_

const byte address = 0x78;
const byte VIN = 0x88;
const byte VOUT = 0x8B;
const byte IOUT = 0x8c;
const byte POUT = 0x96;
const byte TEMP_1 = 0x8D;

typedef struct
{
  byte lsb;
  byte msb;
} twobytes;

typedef struct
{
  int16_t base : 11;
  int16_t mantissa : 5;
} linear11_t;

typedef union {
  linear11_t linear;
  uint16_t raw;
  twobytes tbdata;
} linear11_val_t;

class Converter {
private:
  twobytes tbval;
  int VOUT_MODE;
  void init();
  double linear11(twobytes tbval);
  twobytes CommandExec2(byte DeviceAddr, byte Command);
  double directf(twobytes tbval);
  void data();


public:
  double Converter_array[2];
  uint8_t Converter_PINs[2] ={6,7};

  Converter() {
    this->Converter_array[0] = 0;
    this->Converter_array[1] = 0;
    this->VOUT_MODE = -9;
  }
 uint8_t*get_data();
 void print_data();
};
#endif
