#include "Converter.h"

void Converter::init() {
  Wire.begin();
  // Wire.setClock(10000l);
}

double Converter::linear11(twobytes tbval) {
  linear11_val_t t;
  t.tbdata = tbval;
  return t.linear.base * (double)pow(2, t.linear.mantissa);
}

twobytes Converter::CommandExec2(byte DeviceAddr, byte Command) {
  int wen = 0;
  twobytes res;
  Wire.beginTransmission(DeviceAddr);
  Wire.write(Command);
  wen = Wire.endTransmission((uint8_t) false);
  if (wen != 0) {
    Serial.print("endTransmission error ");
    Serial.println(wen);
    res.lsb = 0xFF;
    res.msb = 0xFF;
  }
  Wire.requestFrom((uint8_t)DeviceAddr, (uint8_t)2, (uint8_t) true);
  if (Wire.available()) {
    res.lsb = Wire.read();
    res.msb = Wire.read();
  } else {
    Serial.println("No data on bus\r\n");
  }

  return res;
}
double Converter::directf(twobytes tbval) {
  linear11_val_t t;
  t.tbdata = tbval;
  int16_t X = t.raw;
  double valu = (X)*pow(2, VOUT_MODE);
  return valu;
}

void Converter::data_conv() {
  init();
  tbval = CommandExec2(address_1, VIN);
  double Vin = linear11(tbval);

  Serial.print("Vin = ");
  Serial.print(Vin);
  Serial.print(" V");
  Serial.print("\t");

  tbval = CommandExec2(address_1, VOUT);
  double Vout = directf(tbval);
  Serial.print("Vout = ");
  Serial.print(Vout);
  Serial.print(" V");
  Serial.print("\t");

  tbval = CommandExec2(address_1, IOUT);
  converterArray[0] = linear11(tbval);  //* 100;

  tbval = CommandExec2(address_1, TEMP_1);
  converterArray[1] = linear11(tbval);

}
// int *Converter::checkConverter(uint8_t *frame) {  //will be put in converters file
//   for (int i = 6; i < 8; i++) {
//     this->check_conv[i-6] = bitRead(frame[1], i);  //(frame[1] >> (i)) & 0x01
//   }
//   digitalWrite(controlPins[0], check_conv[0]);
//   digitalWrite(controlPins[1] , check_conv[1]);
// }

void Converter::switchPin(){
  
  digitalWrite(controlPins[0] , check_conv[0]);
  digitalWrite(controlPins[1] , check_conv[1]);
  converter = !converter;
  digitalWrite(Converter_PINs[0] , HIGH);
  digitalWrite(Converter_PINs[1] ,converter);
  digitalWrite(Converter_PINs[2] ,HIGH);

  if(converter){
    //getData(converter);
    #ifdef TEST_CONVERTER
    Serial.println("Converter 1 ");
    Serial.println();
    print_data();
    #endif

  }else{
    //getData(converter);
    #ifdef TEST_CONVERTER
    Serial.println("Converter 2 ");
    Serial.println();
    print_data();
    #endif
  }
}

//
uint8_t *Converter::getData(bool converter) {
  uint8_t Conv_data[6];
      data_conv();
      int i = (converter)? 0 : 3;
      Conv_data[i + 0] = highByte((uint8_t)converterArray[0]);
      Conv_data[i + 1] = lowByte((uint8_t)converterArray[0]);
      Conv_data[i + 2] = converterArray[1];
  return Conv_data;
}

void Converter::print_data() {
  data_conv();
  Serial.print("Iout = ");
  Serial.print(converterArray[0]);
  Serial.print(" A");

  Serial.print("\t");
  Serial.print("temp = ");
  Serial.print(converterArray[1]);
  Serial.println("c");
}