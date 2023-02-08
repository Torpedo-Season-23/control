#include "communication.h"
#include "UART_Z.h"
#include "UART_Y.h"

uint8_t box[] = {192, 168, 1, 7};
uint8_t console[] = {192, 168, 1, 9};
uint8_t uart_z_frame[UART_Z_FRAME_SIZE];
CommunicationClient client(18, 10, box, console);
struct sensorsData sensors;
UART_Z uart_z;
UART_Y uart_y;


void setup(){
  Serial.begin(115200);
  client.Init();
  uart_z.begin();
  uart_y.begin();


}
void loop(){
    client.receiveData(uart_z_frame+2,uart_z_frame);
    uart_z.sendFrame(uart_z_frame);
    uart_y.receiveFrame(&sensors);
    
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
