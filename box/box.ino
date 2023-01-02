#include "lib/code/rov.h"

ROV rov;

void setup() {
    Serial.begin(BAUD_RATE);
    rov.init();
}

void loop() {
    rov.update();
}