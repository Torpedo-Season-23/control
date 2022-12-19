#include "imu_sensor.h"

IMUSensor::IMUSensor() {
    this->scl = IMU_SCL;
    this->sda = IMU_SDA;
    this->accel_x = 0;
    this->accel_y = 0;
    this->accel_z = 0;
    this->gyro_x = 0;
    this->gyro_y = 0;
    this->gyro_z = 0;
    this->mag_x = 0;
    this->mag_y = 0;
    this->mag_z = 0;
    this->temp = 0;
}