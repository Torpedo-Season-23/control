#include "TorpedoMPU.h"
#include "Pressure.h"
#include "Communication.h"
#include "CurrentSensor.h"
#include "Output_signals.h"
#include "softStart.h"

Thrusters thrusters;
TorpedoMPU tmpu;
CurrentSensor CurrentS;
uint8_t box[] = { 192, 168, 1, 7 };
uint8_t console[] = { 192, 168, 1, 9 };
uint16_t imu[3] = { 1666, 898, 255 };
uint8_t current = 9;
uint16_t pressure = 1024;
CommunicationClient client(18, 10, box, console);
PressureSensor pressurS;
Tools tools;


//thrustersFrame = {0,1,1,1,0,1,1,0, 127 , 100 , 255 , 50 , 100 , 255 , 120, 255 ,33, 20,40,40,20,40,30,40};
//Frame = {0,255,0,255,255,255,255,255};
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  // client.Init();
  soft_start_initial_value();
  tools.init();

  thrusters.init();
  tmpu.start();
  tmpu.check();

  pressurS.pressureInit();
}

void loop() {

  // client.receiveData(tools.tool_frame, thrusters.thrustersFrame);
  // client.sendData(imu, 3, current, 1, pressure);
  //tmpu.calculate();
  // // tools.apply_signal();
  // // thrusters.prep_And_apply_signal();
  //  Serial.print("current:");
  //  Serial.println(CurrentS.getCurrent());

  // Serial.print("roll:");
  // Serial.print(tmpu.angles[0]);
  // Serial.print("  pitch:");
  // Serial.print(tmpu.angles[1]);
  // Serial.print("  yaw:");
  // Serial.println(tmpu.angles[2]);
  // Serial.print("preassure: ");
  // Serial.print(pressurS.pressureLoop());
  // Serial.println("-------------------------");
  // delay(2000);
}
