#include "communication.h"
#include "UART_Y.h"
#include "config.h"

#define PIN A0 //Interrupt pin

uint8_t box[] = {192, 168, 1, 7};
uint8_t console[] = {192, 168, 1, 9};

uint8_t udpReceiveFrame[UDP_REC_FRAME];
uint8_t udpSendFrame[UDP_SEND_FRAME] ;

CommunicationClient client(box, console);
UART_Y uart_y;

void setup() {
  Serial.begin(115200);
  client.Init();
  uart_y.begin();
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, HIGH);
}
void loop() {

 // udpReceiveFrame[0] = 5;
  
  if(client.receiveData(udpReceiveFrame)){
  uart_y.sendFrame(udpReceiveFrame);
  digitalWrite(PIN, LOW);
  uart_y.receiveFrame(udpSendFrame);
  digitalWrite(PIN, HIGH);
  }
  else{
  Serial.println("Nothing was received!");
  }
  client.sendData(udpSendFrame);
  delay(10);
}
