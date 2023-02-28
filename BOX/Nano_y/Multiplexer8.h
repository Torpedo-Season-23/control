#ifndef MUX_H
#define MUX_H

#include <Arduino.h>
#include "Leakage.h"

//Selector pins
#define S0 5
#define S1 6
#define S2 7

//Mux output pin
//#define LEAK 2

void init_mux()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);

  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
}


void select_mux(uint8_t sensor_num)
{
  LeakageSensor l;
  int selectPin[3] = {S0, S1, S2};
  for(int i=0 ; i<3 ; i++)
  {
    digitalWrite(selectPin[i], bitRead(sensor_num, i));
  }

 // uint8_t reading = analogRead(DHTPIN); //Q?
 // return reading;
}

#endif