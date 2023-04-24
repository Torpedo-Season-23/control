#ifndef SETTINGS_H
#define SETTINGS_H
#include <Arduino.h>


class IndexConverter {
public:
  void init(uint16_t *originalFrame) {

    this->thrusterPointers[FRONT_LEFT] = &originalFrame[0];
    this->thrusterPointers[FRONT_RIGHT] = &originalFrame[1];
    this->thrusterPointers[UPPER_FRONT] = &originalFrame[2];
    this->thrusterPointers[BACKWARD_LEFT] = &originalFrame[3];
    this->thrusterPointers[BACKWARD_RIGHT] = &originalFrame[4];
    this->thrusterPointers[UPPER_BACK] = &originalFrame[5];
  }
  uint16_t *updateArray(float* factorsFrame) {
   
  String s = "Factors : " + String(factorsFrame[0]) + "=" + String(factorsFrame[1]) + "=" + String(factorsFrame[2]) + "=" + String(factorsFrame[3]);
  Serial.println(s);
    for (int i = 0; i < MOTORS_NUMBER; i++)
      newFrame[i] = (uint16_t)(*this->thrusterPointers[i] * factorsFrame[i]);
    return newFrame;
  }

private:
  uint16_t *thrusterPointers[MOTORS_NUMBER];
  uint16_t newFrame[MOTORS_NUMBER];
};

class FactorsController {
public:
  void setFactors() {
    if (Serial.available()) {
      String in = Serial.readString();
      String current = "";
      int count = 0;
      for (int i = 0; i < in.length(); i++) {
        if (in[i] == '-' || in[i] == '\n') {
          this->factors[count] = (float)current.toInt() / 100;
          //Serial.println(factors[count]);
          current = "";
          count++;
        } else {
          current += in[i];
        }
      }
    }

  }
  float *getFactors() {
    return this->factors;
  }

private:
  float factors[6] = { 1, 1, 1, 1, 1, 1 };//Factors based on latest conversion of indexes
};

#endif
