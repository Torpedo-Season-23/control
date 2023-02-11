#include "lib/AltSoftSerial/AltSoftSerial.h"
#include "lib/SoftwareSerial/src/SoftwareSerial.h"
#include "lib/code/config.h"

AltSoftSerial motorsSerial(MOTORS_SOFTWARE_SERIAL_RX, MOTORS_SOFTWARE_SERIAL_TX);
uint8_t frame[12 - 4];

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
  motorsSerial.print(123);
}

void recieve() {
  Serial.println("Receiving...");
  if (!motorsSerial.available())
    return;
  byte x = motorsSerial.read();
  if (x != '(')
    return;

  while (!motorsSerial.available())
    ;
  x = motorsSerial.read();
  if (x != '(')
    return;
  for (uint8_t i = 0; i < 12 - 4; i++) {
    while (!motorsSerial.available())
      ;
    frame[i] = motorsSerial.read();
    Serial.println(frame[i]);
  }
  while (!motorsSerial.available())
    ;
  x = motorsSerial.read();
  if (x != ')')
    return;
  while (!motorsSerial.available())
    ;
  x = motorsSerial.read();
  if (x != ')')
    return;

  printRecieved();
}

void printRecieved() {
  Serial.print("Recieved: ");
  for (uint8_t i = 0; i < 12 - 4; i++) {
    Serial.print(frame[i]);
  }
  Serial.println();
}
