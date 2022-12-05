#include <Arduino.h>
#include <SPI.h>
#include "Pressure.h"
//#include <EtherCard.h>

void setup()
{
    Serial.begin(115200);
    pressureInit();
    
}
void loop()
{
  
   float pressure_reading = pressureLoop();
   Serial.print("Pressure: ");
   Serial.print(pressure_reading);
   Serial.println(" mbar");
  
//   Serial.print("Depth: ");
//   Serial.print(getDepth(pressure_reading));
//   Serial.println(" m");
//   Serial.println("");  
   //delay(2000);
  
    
}
