#include "Pressure.h"

// SPI mySPI(MOSI_PIN, MISO_PIN, SCLK_PIN);
void PressureSensor::init() {
    SPI.begin();
    pinMode(MCLK_PIN, OUTPUT);
    delay(100);

#ifdef __AVR__
    TCCR1B = (TCCR1B & 0xF8) | 1; // generates the MCLK signal
#else
    analogWriteFreq(32000);
    analogWriteRange(256);
#endif
    analogWrite(MCLK_PIN, 128);
}

PressureSensor::PressureSensor() {
    this->pressure = 0;
    this->depth = 0;
    this->temperature = 0;
}

uint16_t PressureSensor::readData(const uint16_t command, const unsigned long recvDelay) {
    // SPI.beginTransaction(SPISettings(COMM_FREQUENCY, MSBFIRST, SPI_MODE0));
    // transfer 3 byte reset sequence
    SPI.transfer((RESET_SEQUENCE >> 16) & 0xFF);
    SPI.transfer((RESET_SEQUENCE >> 8) & 0xFF);
    SPI.transfer(RESET_SEQUENCE & 0xFF);

    SPI.transfer16(command); // transfer 2 byte command
    SPI.endTransaction();

    if (recvDelay > 0)
        delay(recvDelay); // wait for conversion end

    SPI.beginTransaction(SPISettings(COMM_FREQUENCY, MSBFIRST, SPI_MODE1));
    uint16_t data = SPI.transfer16(0);
    SPI.endTransaction();

    // Serial.print("Data received (cmd: 0x");
    // Serial.print(command, HEX);
    // Serial.print("): ");
    // Serial.println(data);

    return data;
}

void PressureSensor::update() {

    const uint16_t word1 = this->readData(0x1D50, 0);
    const uint16_t word2 = this->readData(0x1D60, 0);
    const uint16_t word3 = this->readData(0x1D90, 0);
    const uint16_t word4 = this->readData(0x1DA0, 0);
    /* Serial.print("Calibration word 1: ");
      Serial.println(word1);
      Serial.print("Calibration word 2: ");
      Serial.println(word2);
      Serial.print("Calibration word 3: ");
      Serial.println(word3);
      Serial.print("Calibration word 4: "); 
      Serial.println(word4);*/

    const uint16_t c1 = word1 >> 1;
    const uint16_t c2 = ((word3 & 0x3F) << 6) | (word4 & 0x3F);
    const uint16_t c3 = word4 >> 6;
    const uint16_t c4 = word3 >> 6;
    const uint16_t c5 = ((word1 & 0x01) << 10) | (word2 >> 6);
    const uint16_t c6 = word2 & 0x3F;

    // Read digital pressure value from MS5540C
    const uint16_t d1 = this->readData(D1_SEQUENCE, CONVERSION_DELAY_MS);
    // Serial.print("D1: ");
    // Serial.println(d1);

    // Read digital temperature value from MS5540C
    const uint16_t d2 = this->readData(D2_SEQUENCE, CONVERSION_DELAY_MS);
    // Serial.print("D2: ");
    // Serial.println(d2);

    // Calculate calibration temperature
    const long ut1 = (8 * c5) + 20224;

    // Calculate actual temperature
    const long dT = d2 - ut1;                   // Difference between actual temperature and reference temperature
    long temp = 200 + ((dT * (c6 + 50)) >> 10); // Actual temperature (0.1°C resolution)

    // Calculate temperature compensated pressure
    const long off = (c2 * 4) + (((c4 - 512) * dT) >> 12); // Offset at actual temperature
    const long sens = c1 + ((c3 * dT) >> 10) + 24576;      // Sensitivity at actual temperature
    const long x = ((sens * (d1 - 7168)) >> 14) - off;     //
    long p = ((x * 10) >> 5) + 250 * 10;                   // Temperature compensated pressure

    // SECOND-ORDER TEMPERATURE COMPENSATION
    long t2 = 0;
    long p2 = 0;
    if (temp < 200) // Low Temperatures
    {
        t2 = (11 * (c6 + 24) * (200 - temp) * (200 - temp)) >> 20;
        p2 = (3 * t2 * (p - 3500)) >> 14;
    } else if (temp > 400) // High Temperatures
    {
        t2 = (3 * (c6 + 24) * (450 - temp) * (450 - temp)) >> 20;
        p2 = (t2 * (p - 10000)) >> 13;
    }

    // Calculate pressure and temperature
    temp = temp - t2;
    p = p - p2;

    this->temperature = (float)temp / 10;
    this->pressure = (float)p / 10;
    this->depth = (this->pressure * 100) / (1000 * 9.81);
   /* Serial.println("temperature");
    Serial.println(temperature);*/

    //
    //    Serial.print("Temperature: ");
    //    Serial.print(temperature);
    //    Serial.println(" °C");

    /*
        //Serial.print("temp: ");
        //Serial.print(temp);
        //Serial.println(" °C");
*/
         Serial.print("Pressure: ");
         Serial.print(pressure);
         Serial.println(" mbar");
  
}
uint16_t PressureSensor::getPressure(){
  this->update();
  return (uint16_t)this->pressure;

}
