#include "System.h"

System s;

void setup() {
  Serial.begin(115200);
  s.init();
}

void loop() {
<<<<<<< HEAD
  // s.receiveData();
  s.activateUART();
  // s.sendData();
}
=======
  s.receiveData();
 // s.activateUART();
  //Read Here From Converters
  s.sendData();
}
>>>>>>> 4f7eed13799d6bb496f2889e5f9930832f45e2d8
