#include "Converter.h"

void Converter::init() {
  Wire.begin();
}
//get (vin , Iout , temp) true value
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

//get vout true value
double Converter::directf(twobytes tbval) {
  linear11_val_t t;
  t.tbdata = tbval;
  int16_t X = t.raw;
  double valu = (X)*pow(2, VOUT_MODE);
  return valu;
}

void Converter::data_conv() {
  init();

//get (vin , vout) only for debug
#ifdef TEST_CONVERTER
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
#endif

//get Iout
  tbval = CommandExec2(address_1, IOUT);
  converterArray[0] = linear11(tbval) *100;
//get temp
  tbval = CommandExec2(address_1, TEMP_1);
  converterArray[1] = linear11(tbval);
}


void Converter::checkConverter(uint8_t *recFrame) {
  byte neededByte= recFrame[1] & 0b11;
  Serial.print("Switching: ");
  Serial.print(neededByte&1);
  Serial.print(",\t");
  Serial.print(neededByte&0b01);
  
  digitalWrite(controlPins[0], neededByte&1);
  digitalWrite(controlPins[1], neededByte&0b10);
}

void Converter::switchPin(uint8_t *sendFrame) {
  
  converter = converter==HIGH ? LOW:HIGH;
  //control which converter to send (swap converter every loop) (101 , 111)
  digitalWrite(Converter_PINs[1], converter);
  //get data
  getData(converter, sendFrame);

//debug
#ifdef TEST_CONVERTER
  if (converter) {
    Serial.println("Converter 1 ");
    Serial.println();
    print_data();
  } else {
    Serial.println("Converter 2 ");
    Serial.println();
    print_data();
  }
#endif
}

//get converters data 
void Converter::getData(bool converter, uint8_t *sendFrame) {
  data_conv();
  int i = (converter) ? UDP_CONVERTER_1_INDEX : UDP_CONVERTER_2_INDEX;
  sendFrame[i + 0] = highByte((uint8_t)converterArray[0]);
  sendFrame[i + 1] = lowByte((uint8_t)converterArray[0]);
  sendFrame[i + 2] = converterArray[1];
}

//for debugging
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
