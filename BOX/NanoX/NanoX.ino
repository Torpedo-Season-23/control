#include "System.h"
#include "config.h"
#include "Converter.h"

System s;

void setup() {
  Serial.begin(115200);
  s.init();
  pinMode(INTERRUPT_PIN, OUTPUT);
  digitalWrite(INTERRUPT_PIN, HIGH);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4,HIGH);
  digitalWrite(2,HIGH);

}

void loop() {
  Serial.println("Loop");
  s.receiveData();
  s.activateUART();
  //s.updateConverters();
  s.sendData();
}
