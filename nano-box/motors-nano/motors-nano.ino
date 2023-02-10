#include "lib/AltSoftSerial/AltSoftSerial.h"
#include "lib/SoftwareSerial/src/SoftwareSerial.h"
#include "lib/code/config.h"

AltSoftSerial motorsSerial(MOTORS_SOFTWARE_SERIAL_RX, MOTORS_SOFTWARE_SERIAL_TX);

void setup() {
  Serial.begin(BAUD_RATE);
  motorsSerial.begin(BAUD_RATE);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  blinkLED();
  // send();
  recieve();
}

void blinkLED() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void send() {
  Serial.println("Sending...");
  motorsSerial.print("Hello From Motors");
}

void recieve() {
  Serial.print("Receiving...");
  Serial.println(motorsSerial.available());
  while (motorsSerial.available() == 0) {
  }

  if (motorsSerial.available()) {
    Serial.print("Recieved: ");
    Serial.println(motorsSerial.readString());
  }
}
