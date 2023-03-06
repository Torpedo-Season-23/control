#include "communication.h"
#include "UART_Y.h"
#include "config.h"

uint8_t box[] = {192, 168, 1, 7};
uint8_t console[] = {192, 168, 1, 9};
uint8_t udpReceiveFrame[UDP_REC_FRAME];
uint8_t udpSendFrame[UDP_SEND_FRAME];

CommunicationClient client(box, console);
UART_Y uart_y;

void setup()
{
  Serial.begin(115200);
  client.Init();
  uart_y.begin();
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, HIGH);
}
void loop()
{

  // udpReceiveFrame[0] = 5;
  bool i = client.receiveData(udpReceiveFrame);
  if (!i)
  {
    client.defaultFrame(udpReceiveFrame);
    client.Init();
    Serial.println("Not connected");
    delay(5);
  }
  uart_y.sendFrame(udpReceiveFrame);
  digitalWrite(PIN, LOW);
  uart_y.receiveFrame(udpSendFrame);
  digitalWrite(PIN, HIGH);
  client.sendData(udpSendFrame);
  delay(10);
}
