#include "lib/SoftwareSerial/src/SoftwareSerial.h"
#include "lib/code/config.h"

SoftwareSerial sensorsSerial(SENSORS_SOFTWARE_SERIAL_RX, SENSORS_SOFTWARE_SERIAL_TX);
SoftwareSerial motorsSerial(MOTORS_SOFTWARE_SERIAL_RX, MOTORS_SOFTWARE_SERIAL_TX);
uint8_t frame[12];

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(LED_BUILTIN, OUTPUT);
  sensorsSerial.begin(BAUD_RATE);
  motorsSerial.begin(BAUD_RATE);
}

void loop() {
  blinkLED();
  send();
  // receive();
}

void blinkLED() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void send() {
  Serial.println("Sending...");
  frame[0] = '(';
  frame[1] = '(';
  for (uint8_t i = 2; i < 10; i++) {
    frame[i] = i + 1;
  }

  frame[12 - 2] = ')';
  frame[12 - 1] = ')';

  sensorsSerial.write(frame, 12);
  motorsSerial.write(frame, 12);
}

void receive() {
  Serial.print("Receiving...");
  Serial.print(sensorsSerial.available());
  while (sensorsSerial.available() == 0) {
  }
  if (sensorsSerial.available()) {
    Serial.print("Sensors: ");
    Serial.println(sensorsSerial.readString());
  }
}
