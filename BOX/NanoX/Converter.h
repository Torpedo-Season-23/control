#ifndef _Converter_H_
#define _Converter_H_
#include <Arduino.h>
#include <Wire.h>
#include <math.h>
#include "config.h"

//converters address
const byte address_1 = 0x78;

//PMbus commands 
const byte VIN = 0x88;
const byte VOUT = 0x8B;
const byte IOUT = 0x8c;
const byte POUT = 0x96;
const byte TEMP_1 = 0x8D;

//to split value into two bytes
typedef struct
{
  byte lsb;
  byte msb;
} twobytes;

// to split vlue into base and power 
typedef struct
{
  int16_t base : 11;
  int16_t mantissa : 5;
} linear11_t;

//to convert between types
typedef union {
  linear11_t linear;
  uint16_t raw;
  twobytes tbdata;
} linear11_val_t;


class Converter {
private:
  twobytes tbval;
  int VOUT_MODE; //needed to calculate vout true value
  int converter = HIGH; //to swap between convertes
  void init(); 
  double linear11(twobytes tbval); //(vin , iout , temp) data type 
  twobytes CommandExec2(byte DeviceAddr, byte Command); //get data from i2c
  double directf(twobytes tbval); // (vout) data type  
  void data_conv(); 

public:
  float converterArray[2]; //contains data after conversion
  float Conv_data[6]; //contains data to be send 
  uint8_t Converter_PINs[3] = { A1, A2, A3 }; //pins to swap convertse (101) or (111)
  //uint8_t controlPins[2] = { 2, 4 }; //pins to control power(on/off) on converters 
  uint8_t check_conv[2] = { 1, 1 }; // power value on two converters 

  Converter() {
    //set initial values
    this->converterArray[0] = 0;
    this->converterArray[1] = 0;
    this->VOUT_MODE = -9;
    this->Conv_data[0] = 0;
    this->Conv_data[1] = 0;
    this->Conv_data[2] = 0;
    this->Conv_data[3] = 0;
    this->Conv_data[4] = 0;
    this->Conv_data[5] = 0;
  }
  void print_data();
  void switchPin(uint8_t *sendFrame);
  void getData(bool converter, uint8_t *sendFrame);
  void checkConverter(uint8_t *recFrame);
};
#endif
