#include "lib/code/rov.h"

ROV rov;

void setup() {
    rov.init();
}

void loop() {
    rov.update();
}
