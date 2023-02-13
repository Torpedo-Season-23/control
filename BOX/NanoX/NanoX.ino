#include "communication.h"
#include "UART_Z.h"
#include "UART_Y.h"
#define PIN 4

uint8_t box[] = {192, 168, 1, 10};
uint8_t console[] = {192, 168, 1, 9};
CommunicationClient client(box, console);
UART_Z uart_z;
UART_Y uart_y;
struct maxTimes{
  long timeToReceiveUDP=0;
  long timeToReceiveUART=0;
  long timeToSendUDP=0;
  long totalTime= 0;
}times;

void setup() {
  Serial.begin(115200);
  client.Init();
  uart_z.begin();
  uart_y.begin();
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, HIGH);
}
long lastTimeSinceSending= 0;
void loop() {
  uint8_t udpReceiveFrame[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  uint8_t udpSendFrame[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//10 bytes sensors, 4 converters, 1 leakage
  
  long totalTime = millis();
  long currentTime= millis();
  client.receiveData(udpReceiveFrame);
  times.timeToReceiveUDP= max(times.timeToReceiveUDP,millis()-totalTime);
  uart_y.sendFrame(udpReceiveFrame+14);
  uint8_t frame[UART_Z_FRAME_SIZE];
  digitalWrite(PIN, LOW);
  uart_z.sendFrame(udpReceiveFrame);
  totalTime= millis();
  uart_y.receiveFrame(udpSendFrame);
  times.timeToReceiveUART= max(times.timeToReceiveUART,millis()-totalTime);
  digitalWrite(PIN, HIGH);
  totalTime= millis();
//  if(totalTime-lastTimeSinceSending > 600){/
    client.sendData(udpSendFrame);
    lastTimeSinceSending= totalTime;
//  }/
  
  times.timeToSendUDP= max(times.timeToSendUDP,millis()-totalTime);
  long now= millis()-currentTime;
  times.totalTime= max(times.totalTime,now);

  Serial.print("Time to Receive UDP : ");Serial.print(times.timeToReceiveUDP);
  Serial.print("\tTime to Receive UART : ");Serial.print(times.timeToReceiveUART);
  Serial.print("\tTime to Send UDP : ");Serial.println(times.timeToSendUDP);
  Serial.print("\t\tTotal Time : ");Serial.print(times.totalTime);Serial.print("\t");Serial.println(now); 

//  maxTime= max(maxTime,millis()-totalTime);
//  Serial.println(maxTime);
}
