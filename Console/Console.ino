#include "System.h"
#include "RF24/RF24.h"

RF24 radio(17, 18);
const byte address[6] = "00001";
long int prev_time;

struct msg {
  byte message = 0;
};

struct msg start_signal;

PSGamepad controller;
System s(&controller);

void setup() {
  Serial.begin(115200);
  s.Init();

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  prev_time = millis();  
}

void loop() {
  s.Update();

  if (false) { // the start signal's button is pressed
    for (int i = 0; i < 5; i++) 
      radio.write('A', sizeof('A'));
    
    Serial.print("Sent the float\'s start signal...");
  }
}