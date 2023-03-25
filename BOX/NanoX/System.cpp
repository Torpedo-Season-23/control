#include "System.h"



void System::init() {

  this->client.init();
  uart_y.begin();
  pinMode(INTERRUPT_PIN, OUTPUT);
  digitalWrite(INTERRUPT_PIN, HIGH);
}

void System::sendData()
{
    client.sendData(udpSendFrame);
    delay(10);

    for(int i = 0 ; i < 16 ; i ++){
      Serial.print(udpSendFrame[i]);
      Serial.print(" ");
 
    }
      Serial.println();


}

void System::receiveData()
{
      bool i = client.receiveData(udpReceiveFrame);

 
  if (!i)
  {
    client.defaultFrame(udpReceiveFrame);
    client.init();
    //Serial.println("Not connected");
   // delay(5);
  }
}

void System::activateUART()
{
  uart_y.sendFrame(udpReceiveFrame);
  Serial.print("aaaaa");
 
//  digitalWrite(INTERRUPT_PIN, LOW);
  
 uart_y.receiveFrame(udpSendFrame);
 Serial.print("jjjj");
   
  // digitalWrite(INTERRUPT_PIN, HIGH);

}
