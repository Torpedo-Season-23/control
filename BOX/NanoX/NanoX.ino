#include "communication.h"
#include "UART_Z.h"
#include "UART_Y.h"
#define PIN 4

uint8_t box[] = {192, 168, 1, 10};
uint8_t console[] = {192, 168, 1, 9};
uint8_t uart_z_frame[UART_Z_FRAME_SIZE];
CommunicationClient client(18, 10, box, console);
struct sensorsData sensors;
UART_Z uart_z;
UART_Y uart_y;

long currentTime= millis();

void setup() {
  Serial.begin(115200);
  client.Init();
  uart_z.begin();
  uart_y.begin();
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, HIGH);
}
void loop() {
  //digitalWrite(13,HIGH);

  client.receiveData(uart_z_frame+2,uart_z_frame);
  //delay(30);
  uart_y.sendFrame(uart_z_frame);
  uint8_t frame[UART_Z_FRAME_SIZE];


  //digitalWrite(PIN, LOW);
  //uart_z.sendFrame(uart_z_frame);/*
  //if(current-currentTime < 2000)
  //  return;
  //uart_y.receiveFrame(&sensors);

  digitalWrite(PIN, HIGH);

  /*Serial.print("IMU angles: ");
  for(int i= 0;i<3;i++){
    Serial.print(sensors.angles[i]);
    Serial.print(" ");
  }
  Serial.print("\tPressure: ");
  Serial.println(sensors.pressure);*/
  //delay(50);
  long current= millis();
  if(current - currentTime>50){
    current= currentTime;
    client.sendData();
      return;

  }
      

  //Switch Converters
  /*
    //Receive Communication
    //Switch Converters
    //Send to Z
    //Send to Y
  */
  /*
    Read from y
    Read from converters
    Send UDP
  */
}
