#include <Arduino.h>
#include <Wire.h>
#include <math.h>
#ifndef _Converter_H_
#define _Converter_H_
#define TEST_CONVERTER 

const byte address_1 = 0x78;
const byte address_2 = 0x76;
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
  bool converter = HIGH ;
  void init();
  double linear11(twobytes tbval);
  twobytes CommandExec2(byte DeviceAddr, byte Command);
  double directf(twobytes tbval);
  void data_conv();

public:
  double converterArray[2];
  double Conv_data[6];
  int Converter_PINs[3]  = {A1,A2,A3};
  int controlPins[2] = {2 , 4 };
  int check_conv[2]={1,1};

  Converter() {
    this->converterArray[0] = 0;
    this->converterArray[1] = 0;
  
    this->VOUT_MODE = -9;
    this->Conv_data[0]=0;
    this->Conv_data[1]=0;
    this->Conv_data[2]=0;
    this->Conv_data[3]=0;
    this->Conv_data[4]=0;
    this->Conv_data[5]=0;

  }
  void print_data();
  void switchPin();
  uint8_t *getData(bool converter);
  // int *checkConverter(uint8_t *frame);
};
#endif
