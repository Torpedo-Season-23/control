#include "Thrusters.h"
#include "Tools.h"
#include "UARTTerminal.h"

Thrusters thrusters;
Tools tools;
Uart_z uartz;

// uint8_t frame[] = {0, 1, 1, 1, 0, 1, 1, 0, 127 , 100 , 255 , 50 , 100 , 255 , 120, 255 , 33, 20, 40, 40, 20, 40, 30, 40};
// uint8_t tool[] = {0, 255, 0, 255, 255, 255, 255, 255};
 
void setup() {
  Serial.begin(115200);
  uartz.startUART();
  tools.init();
  thrusters.init();
}

void loop() {
  Serial.print("Waiting to receive...");
   uartz.receiveFrame(thrusters.thrustersFrame , tools.tool_frame);
   thrusters.prep_And_apply_signal();
   tools.apply_signal();
}
