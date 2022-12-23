#include "lib/code/rov.h"

#define DEBUG_IMU 0
#define DEBUG_PRESSURE 0
#define DEBUG_CURRENT 0
#define DEBUG_SENSOR_MANAGER 0

#define DEBUG_MOTOR_T100 0
#define DEBUG_MOTOR_T200 0
#define DEBUG_MOTION 0

#define DEBUG_ACCESSORIES 0

#define DEBUG_COMMUNICATION 0

#define DEBUG_WHOLE_ROV 0

MPU6050Sensor mpu;
PressureSensor pressure;
CurrentSensor current(CURRENT_SENSOR_BACK_LEFT_PIN, CURRENT_SENSOR_BACK_LEFT);
SensorsManager sensorsManager;

T100Motor t100motor(VERTICAL_FRONT_PIN, VERTICAL_FRONT);
T200Motor t200motor(HORIZONTAL_BACK_LEFT_PIN, HORIZONTAL_BACK_LEFT);
Motion8 motion;

Accessories accessories;

BoxEthernet ethernet;

ROV rov;

void setup() {
    Serial.begin(BAUD_RATE);
    if (DEBUG_IMU) mpu.init();
    if (DEBUG_PRESSURE) pressure.init();
    if (DEBUG_CURRENT) current.init();
    if (DEBUG_SENSOR_MANAGER) sensorsManager.init();

    if (DEBUG_MOTOR_T100) t100motor.init();
    if (DEBUG_MOTOR_T200) t200motor.init();
    if (DEBUG_MOTION) motion.init();

    if (DEBUG_ACCESSORIES) accessories.init();

    if (DEBUG_COMMUNICATION) ethernet.init();

    if (DEBUG_WHOLE_ROV) rov.init();
}

void loop() {
    if (DEBUG_IMU) mpu.update();
    if (DEBUG_PRESSURE) pressure.update();
    if (DEBUG_CURRENT) current.update();
    if (DEBUG_SENSOR_MANAGER) sensorsManager.update();

    if (DEBUG_MOTOR_T100) t100motor.update();
    if (DEBUG_MOTOR_T200) t200motor.update();
    if (DEBUG_MOTION) motion.update();

    if (DEBUG_ACCESSORIES) accessories.update();

    if (DEBUG_COMMUNICATION) ethernet.update();

    if (DEBUG_WHOLE_ROV) rov.update();
}
