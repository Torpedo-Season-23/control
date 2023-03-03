#include "Converter.h"

void Converter::init() {
  Wire.begin();
  Wire.setClock(10000l);
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

uint8_t* Converter::data() {
  init();
  tbval = CommandExec2(address, VIN);
  double Vin = linear11(tbval);
  // Serial.print("Vin = ");
  // Serial.print(Vin);
  // Serial.print(" V");
  // Serial.print("\t");

  tbval = CommandExec2(address, VOUT);
  double Vout = directf(tbval);
  // Serial.print("Vout = ");
  // Serial.print(Vout);
  // Serial.print(" V");
  // Serial.print("\t");

  tbval = CommandExec2(address, IOUT);
  Converter_array[0] = linear11(tbval) * 100;

  tbval = CommandExec2(address, TEMP_1);
  Converter_array[1] = linear11(tbval);

  return (uint8_t)Converter_array;
}

uint8_t* Converter::Set_data() {
  uint8_t Conv_data[6];
  for (int i = 0; i < 2; i++) {
    digitalWrite(Converter_PINs[i], HIGH);
    data();
    int INDEX = (i == 0) ? 0 : 3;
    Conv_data[INDEX] = highByte((uint8_t)Converter_array[0]);
    Conv_data[INDEX + 1] = lowByte((uint8_t)Converter_array[0]);
    Conv_data[INDEX + 2] = Converter_array[1];
    digitalWrite(Converter_PINs[i], LOW);
  }
  return Conv_data;
}
uint8_t *Converter::Debug() {
  uint8_t Conv_data[6];
  for (int i = 0; i < 2; i++) {
    if (digitalRead(ON_OFF_PINS[i])) {
      Serial.print("converter 1 is ON.");
      digitalWrite(Converter_array[i], HIGH);
      data();
      Conv_data[i] = highByte((uint8_t)Converter_array[0]);
      Conv_data[i + 1] = lowByte((uint8_t)Converter_array[0]);
      Conv_data[i + 2] = Converter_array[1];
      print_data();
      digitalWrite(Converter_PINs[i], LOW);
    } else if (digitalRead(ON_OFF_PINS[i + 1])) {
      Serial.print("converter 2 is ON.");
      digitalWrite(Converter_array[i + 1], HIGH);
      data();
      Conv_data[i+ 3 ] = highByte((uint8_t)Converter_array[0]);
      Conv_data[i + 4] = lowByte((uint8_t)Converter_array[0]);
      Conv_data[i + 5] = Converter_array[1];
      print_data();
      digitalWrite(Converter_PINs[i+ 1], LOW);
    }
  }
  return Conv_data;
}

void Converter::print_data() {
  data();

  Serial.print("Iout = ");
  Serial.print(Converter_array[0]);
  Serial.print(" A");

  Serial.print("\t");
  Serial.print("temp = ");
  Serial.print(Converter_array[1]);
  Serial.println("c");
}