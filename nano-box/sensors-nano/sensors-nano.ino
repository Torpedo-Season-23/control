#include "lib/SoftwareSerial/src/SoftwareSerial.h"
#include "lib/code/config.h"

SoftwareSerial sensorsSerial(SENSORS_SOFTWARE_SERIAL_RX, SENSORS_SOFTWARE_SERIAL_TX);
uint8_t frame[12 - 4];

void setup() {
  Serial.begin(BAUD_RATE);
  sensorsSerial.begin(BAUD_RATE);
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
  sensorsSerial.stopListening();
  Serial.println("Sending...");
  sensorsSerial.print(123);
}

void recieve() {
  Serial.println("Receiving...");
  if (!sensorsSerial.available())
    return;
  byte x = sensorsSerial.read();
  if (x != '(')
    return;

  while (!sensorsSerial.available())
    ;
  x = sensorsSerial.read();
  Serial.println(x);
  if (x != '(')
    return;
  for (uint8_t i = 0; i < 12 - 4; i++) {
    while (!sensorsSerial.available())
      ;
    frame[i] = sensorsSerial.read();
    Serial.println(frame[i]);
  }
  while (!sensorsSerial.available())
    ;
  x = sensorsSerial.read();
  Serial.println(x);
  if (x != ')')
    return;
  while (!sensorsSerial.available())
    ;
  x = sensorsSerial.read();
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
