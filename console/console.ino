#include "lib/nRF/RF24.h"

RF24 radio(9, 10);  // CE, CSN

void setup() {
  Serial.begin(9600);
  Serial.println("Hello World");
  radio.begin();
}

void loop() {
  radio.stopListening();
  char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  Serial.println("Sent");
  radio.startListening();
  delay(1000);
}