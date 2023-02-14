SensorsMapper::SensorsMapper() {
}

void SensorsMapper::setSensorsFrame(uint8_t mpuFrame[MPU_FRAME_SIZE], uint8_t pressureFrame[PRESSURE_FRAME_SIZE]) {
  memcpy(this->sensorsFrame, mpuFrame, MPU_FRAME_SIZE);
  memcpy(this->sensorsFrame + MPU_FRAME_SIZE, pressureFrame, PRESSURE_FRAME_SIZE);
}

uint8_t* SensorsMapper::getSensorsFrame() {
  return this->sensorsFrame;
}