#include "communication.h"
#include "UART_Y.h"
#include "config.h"
#include "Converter.h"
#define PIN 4

uint8_t box[] = { 192, 168, 1, 7 };
uint8_t console[] = { 192, 168, 1, 9 };

uint8_t udpReceiveFrame[UDP_REC_FRAME];
uint8_t udpSendFrame[UDP_SEND_FRAME];

CommunicationClient client(box, console);
UART_Y uart_y;
Converter converter;

void setup() {
  Serial.begin(115200);
  client.Init();
  uart_y.begin();
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, HIGH);
}
void loop() {

  if (client.receiveData(udpReceiveFrame)) {
    uart_y.sendFrame(udpReceiveFrame);
    digitalWrite(PIN, LOW);
    uart_y.receiveFrame(udpSendFrame);
    digitalWrite(PIN, HIGH);

  } else {
    Serial.println("Nothing was received!");
  }
  client.sendData(udpSendFrame);
  // client.sendData(converter.get_data());
  delay(10);
}
