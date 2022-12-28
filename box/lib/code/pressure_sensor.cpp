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
    this->working = true;
    this->spi->begin();
    pinMode(this->mclk, OUTPUT);
}

void PressureSensor::update() {
    if (!this->working) return;
    digitalWrite(this->mclk, HIGH);
    this->spi->transfer(0xAA);
    digitalWrite(this->mclk, LOW);
    delay(10);

    digitalWrite(this->mclk, LOW);
    byte p1 = this->spi->transfer(0x00);
    byte p2 = this->spi->transfer(0x00);
    byte p3 = this->spi->transfer(0x00);
    byte t1 = this->spi->transfer(0x00);
    byte t2 = this->spi->transfer(0x00);
    byte t3 = this->spi->transfer(0x00);
    digitalWrite(this->mclk, HIGH);

    this->pressure = ((p1 << 16) | (p2 << 8) | p3) / 64.0;
    this->temperature = ((t1 << 16) | (t2 << 8) | t3) / 64.0;
    this->depth = (this->pressure - 1013.25) / (9.80665 * 0.000295);

    this->data = this->depth;

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
    Serial.print(" m");
}

float PressureSensor::getDepth() {
    return this->depth;
}

float PressureSensor::getPressure() {
    return this->pressure;
}
