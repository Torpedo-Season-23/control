#include "TorpedoMPU.h"
#include "Pressure.h"
#include "Communication.h"
#include "CurrentSensor.h"
#include"Output_signals.h"
#include "softStart.h"

//uint8_t thrustersFrame[24] = {0,1,1,1,0,1,1,0, 127 , 100 , 255 , 50 , 100 , 255 , 120, 255 ,33, 20,40,40,20,40,30,40};
//uint8_t Frame[8] = {0,255,0,255,255,255,255,255};
Thrusters thrusters;
TorpedoMPU tmpu;
CurrentSensor CurrentS;
CommunicationClient Client(53,18,19,IPAddress(198,168,1,7),IPAddress(198,168,1,7));
PressureSensor pressurS;
Tools tools;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  soft_start_initial_value();
  tools.init();
  thrusters.init();
  tmpu.start();
  tmpu.check();
  pressurS.pressureInit();

}

void loop() {
  tmpu.calculate();

  CurrentS.getCurrent();
//  pressurS.readData();

//   Serial.println("-------------------------");
  Client.receiveData(tools.tool_frame,thrusters.thrustersFrame);
  Client.sendData(tmpu.communication_data(),3,CurrentS.Return_current(),1,pressurS.pressureLoop(),1);
  Client.prep_to_send(tmpu.communication_data(),3,CurrentS.Return_current(),1,pressurS.pressureLoop(),1);
  tools.apply_signal();
  thrusters.prep_And_apply_signal();
}
