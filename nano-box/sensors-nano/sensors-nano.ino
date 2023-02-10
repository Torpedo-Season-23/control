#include "lib/SoftwareSerial/src/SoftwareSerial.h"
#include "lib/code/config.h"

SoftwareSerial sensorsSerial(SENSORS_SOFTWARE_SERIAL_RX, SENSORS_SOFTWARE_SERIAL_TX);

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
  Serial.println("Sending...");
  sensorsSerial.print("Hello From Sensors");
}

void recieve() {
  Serial.print("Receiving...");
  Serial.println(sensorsSerial.available());
  while (sensorsSerial.available() == 0) {
  }

  if (sensorsSerial.available()) {
    Serial.print("Recieved: ");
    Serial.println(sensorsSerial.readString());
  }
}
