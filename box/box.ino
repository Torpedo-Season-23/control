#include "lib/code/rov.h"

Motion8 motion;

void setup() {
    Serial.begin(BAUD_RATE);
    motion.init()
}

void loop() {
    uint16_t speed = {
        1600,
        1600,
        1600,
        1600,
        1600,
        1600,
        1600,
        1600,
    };
    motion.setDirection(DIRECTION::GENERIC);
    motion.setSpeed(speed);
    motion.update();
    delay(2000);
    motion.setDirection(DIRECTION::STOP);
    motion.update();
    delay(2000);
    motion.setDirection(DIRECTION::FORWARD);
    motion.update();
    delay(2000);
}