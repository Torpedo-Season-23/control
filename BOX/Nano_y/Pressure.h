// #include "SOFTSPI.h"
#include <SPI.h>
#ifndef _PRESSURE_H_
#define _PRESSURE_H_
#include <Arduino.h>
// #include "lib/SoftSPI/SoftSPI.cpp"

#define D1_SEQUENCE 0x0F40      // pressure measurement sequence
#define D2_SEQUENCE 0x0F20      // temperature measurement sequence
#define WORD1_SEQUENCE 0x1D50   // word1 sequence
#define WORD2_SEQUENCE 0x1D60   // word2 sequence
#define WORD3_SEQUENCE 0x1D90   // word3 sequence
#define WORD4_SEQUENCE 0x1DA0   // word4 sequence
#define RESET_SEQUENCE 0x155540 // reset sequence

#define CONVERSION_DELAY_MS 35
#define COMM_FREQUENCY 500000

#define MCLK_PIN 10
#define MISO_PIN 12
#define MOSI_PIN 11
#define SCLK_PIN 13
class PressureSensor {
  private:
    float pressure;
    float depth;
    float temperature;

  public:
    PressureSensor();
    void init();
    void update();
    uint16_t readData(const uint16_t command, const unsigned long recvDelay = 0);
    uint16_t getPressure();
};
#endif
