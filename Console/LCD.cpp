
#include "Lcd.h"

void Lcd::init () {
  this->lcd.init();
  this->lcd.clear();
  this->lcd.backlight();
  this->lcd.setCursor(0, 0);
  this->lcd.print("S:");
  this->lcd.setCursor(5,0);
  this->lcd.print("Comm:");
  this->lcd.setCursor(0,1);
  this->lcd.print("G1:");
  this->lcd.setCursor(4,1);
  this->lcd.print("G2:");
  this->lcd.setCursor(8,1);
  this->lcd.print("G3:");
  this->lcd.setCursor(12,1);
  this->lcd.print("G4:");
  // LCD.setCursor(5,1);
  // LCD.print("5G:");
  // LCD.setCursor(5,1);
  // LCD.print("6G:");
  // LCD.setCursor(5,1);
  // LCD.print("7G:");
  // LCD.setCursor(5,1);
  // LCD.print("8G:");

}

void Lcd::update(int speed, bool comm, int *acc){
    this->lcd.setCursor(3, 0);
    this->lcd.print(speed+1);
    this->lcd.setCursor(3, 1);
    this->lcd.print(acc[0]);
    this->lcd.setCursor(7, 1);
    this->lcd.print(acc[1]);
    this->lcd.setCursor(11, 1);
    this->lcd.print(acc[2]);
    this->lcd.setCursor(15, 1);
    this->lcd.print(acc[3]);
    this->lcd.setCursor(11, 0);
    this->lcd.print((comm==true)?"ON":"OFF");    

  //     this->lcd.setCursor(11, 0);
//     this->lcd.print(pid);
//     this->lcd.setCursor(19, 0);
//     this->lcd.print(accessories[7] ==255 ? 1 : 0);

//     this->lcd.setCursor(3,1);
//     this->lcd.print(accessories[0] ==255 ? 1 : 0);
//     this->lcd.setCursor(8,1);
//     this->lcd.print(accessories[1] ==255 ? 1 : 0);
//     this->lcd.setCursor(13,1);
//     this->lcd.print(accessories[2] ==255 ? 1 : 0);
//     this->lcd.setCursor(18,1);
//     this->lcd.print(accessories[3] ==255 ? 1 : 0);
//     this->lcd.setCursor(7,3);
// //    Serial.println(communication ? "ON /" : "OFF");
//     LCD.print(communication ? "ON " : "OFF");

//     LCD.setCursor(14,3);
//     LCD.print(followerMode ? 1 : 0);

//     LCD.setCursor (19, 3);
//     LCD.print (diagonalOn ? 1 : 0);
    
    

}
