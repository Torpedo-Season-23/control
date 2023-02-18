#include "communication.h"
#include "UART_Z.h"
#include "UART_Y.h"
#define PIN 4

uint8_t box[] = {192, 168, 1, 7};
uint8_t console[] = {192, 168, 1, 9};

uint8_t udpReceiveFrame[13];
uint8_t udpSendFrame[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //10 bytes sensors, 4 converters, 1 leakage

CommunicationClient client(box, console);
UART_Z uart_z;
UART_Y uart_y;
struct maxTimes {
  long timeToReceiveUDP = 0;
  long timeToReceiveUART = 0;
  long timeToSendUDP = 0;
  long totalTime = 0;
} times;

void setup() {
  Serial.begin(115200);
  client.Init();
  uart_z.begin();
  uart_y.begin();
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, HIGH);
}
long lastTimeSinceSending = 0;
void loop() {

  client.receiveData(udpReceiveFrame);
  uart_y.sendFrame(udpReceiveFrame);
  uint8_t frame[UART_Z_FRAME_SIZE];
  digitalWrite(PIN, LOW);
  uart_y.receiveFrame(udpSendFrame);
  digitalWrite(PIN, HIGH);
  client.sendData(udpSendFrame);
  delay(10);

  //  maxTime= max(maxTime,millis()-totalTime);
  //  Serial.println(maxTime);
}
