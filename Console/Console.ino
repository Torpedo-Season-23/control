#include "System.h"
#include "RF24/RF24.h"

RF24 radio(17, 18);
const byte writingAddress[6] = "00001";
const byte readingAddress[6] = "00002";
bool listenedBefore = false;
long int prev_time;
String grand_str = "";

struct msg {
  byte message = 0;
};

struct msg s_msg;

Xbox controller;
System s(&controller);

bool rtc=false;
long timeRTC;
long prevRTC;

void startListening() {
  if (!listenedBefore) {
    radio.begin();
    radio.openReadingPipe(1, readingAddress);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();
    listenedBefore = true;
  }
}


void setup() {
  Serial.begin(115200);
  s.Init();

  radio.begin();
  radio.openWritingPipe(writingAddress);
  radio.openReadingPipe(1, readingAddress);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  prev_time = millis();
  timeRTC=millis();
  prevRTC=millis();
}

void loop() {
  timeRTC=millis();
  s.Update();

  if (controller.nrf()) { // the start signal's button is pressed
    //for (int i = 0; i < 5; i++)
      radio.write("AAAAAA", 5);
    Serial.print("Sent the float\'s start signal...");
//    s.clearLCD();
  }
  if(controller.timer()){
    s.updateRTC();
    rtc=true;
    prevRTC=timeRTC;
  }
  
  if(timeRTC-prevRTC>5000){
    s.clearLCD();
  }

}
