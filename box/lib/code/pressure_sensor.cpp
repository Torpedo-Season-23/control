
PressureSensor::PressureSensor() {
    this->mclk = PRESSURE_MCLK;
    this->miso = PRESSURE_MISO;
    this->mosi = PRESSURE_MOSI;
    this->sclk = PRESSURE_SCLK;
    this->spi = new SoftSPI(this->mosi, this->miso, this->sclk);
    this->pressure = 0;
    this->temperature = 0;
    this->depth = 0;
}

void PressureSensor::init() {
    this->spi->begin();
    pinMode(this->mclk, OUTPUT);
#ifdef __AVR__
    TCCR1B = (TCCR1B & 0xF8) | 1;  // generates the MCLK signal
#else
    analogWriteFreq(32000);
    analogWriteRange(256);
#endif
    analogWrite(this->mclk, 128);
}

uint16_t PressureSensor::readData(const uint16_t command, const unsigned long recvDelay) {
    this->spi->beginTransaction(SPISettings(COMM_FREQUENCY, MSBFIRST, SPI_MODE0));
    this->spi->transfer((RESET_SEQUENCE >> 16) & 0xFF);
    this->spi->transfer((RESET_SEQUENCE >> 8) & 0xFF);
    this->spi->transfer(RESET_SEQUENCE & 0xFF);

    this->spi->transfer16(command);  // transfer 2 byte command
    this->spi->endTransaction();

    if (recvDelay > 0)
        delay(recvDelay);  // wait for conversion end

    this->spi->beginTransaction(SPISettings(COMM_FREQUENCY, MSBFIRST, SPI_MODE1));
    uint16_t data = this->spi->transfer16(0);
    this->spi->endTransaction();

    return data;
}

void PressureSensor::update() {
    if (!this->working) return;
    const uint16_t word1 = this->readData(0x1D50, 0);
    const uint16_t word2 = this->readData(0x1D60, 0);
    const uint16_t word3 = this->readData(0x1D90, 0);
    const uint16_t word4 = this->readData(0x1DA0, 0);

    const uint16_t c1 = word1 >> 1;
    const uint16_t c2 = ((word3 & 0x3F) << 6) | (word4 & 0x3F);
    const uint16_t c3 = word4 >> 6;
    const uint16_t c4 = word3 >> 6;
    const uint16_t c5 = ((word1 & 0x01) << 10) | (word2 >> 6);
    const uint16_t c6 = word2 & 0x3F;

    const uint16_t d1 = this->readData(D1_SEQUENCE, CONVERSION_DELAY_MS);
    const uint16_t d2 = this->readData(D2_SEQUENCE, CONVERSION_DELAY_MS);

    const long ut1 = (8 * c5) + 20224;
    const long dT = d2 - ut1;
    long temp = 200 + ((dT * (c6 + 50)) >> 10);

    const long off = (c2 * 4) + (((c4 - 512) * dT) >> 12);
    const long sens = c1 + ((c3 * dT) >> 10) + 24576;
    const long x = ((sens * (d1 - 7168)) >> 14) - off;
    long p = ((x * 10) >> 5) + 250 * 10;

    long t2 = 0;
    long p2 = 0;
    if (temp < 200) {
        t2 = (11 * (c6 + 24) * (200 - temp) * (200 - temp)) >> 20;
        p2 = (3 * t2 * (p - 3500)) >> 14;
    } else if (temp > 400) {
        t2 = (3 * (c6 + 24) * (450 - temp) * (450 - temp)) >> 20;
        p2 = (t2 * (p - 10000)) >> 13;
    }
    temp = temp - t2;
    p = p - p2;

    this->temperature = (float)temp / 10;
    this->pressure = (float)p / 10;
    this->depth = (this->pressure * 100) / (1000 * 9.81);

    if (DEBUG_SENSORS)
        this->display();
}

void PressureSensor::reset() {
    this->spi->beginTransaction(SPISettings(COMM_FREQUENCY, MSBFIRST, SPI_MODE0));
    this->spi->transfer((RESET_SEQUENCE >> 16) & 0xFF);
    this->spi->transfer((RESET_SEQUENCE >> 8) & 0xFF);
    this->spi->transfer(RESET_SEQUENCE & 0xFF);
    this->spi->endTransaction();

    this->pressure = 0;
    this->temperature = 0;
    this->depth = 0;
}

void PressureSensor::display() {
    Serial.print("Pressure: ");
    Serial.print(this->pressure);
    Serial.print(" mbar | Temperature: ");
    Serial.print(this->temperature);
    Serial.print(" °C | Depth: ");
    Serial.print(this->depth);
    Serial.println(" m");
}

float PressureSensor::getDepth() {
    return this->depth;
}

float PressureSensor::getPressure() {
    return this->pressure;
}
