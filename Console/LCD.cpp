#include "LCD.h"

void LCD::init(){
  lcd.init();
  lcd.backlight();
}


void LCD::update(int16_t *sensors , int* acc, int speed , int8_t dir){

lcd.setCursor(0, 0);
/*lcd.print("P:"); 
lcd.print(sensors[3]); 
lcd.print(" "); 
if(dir == FORWARD){
lcd.print("FORWARD "); 
}
if(dir == BACKWARD){
lcd.print("BACKWARD"); 
}
if(dir == RIGHT){
lcd.print("RIGHT   "); 
}
if(dir == LEFT){
lcd.print("LEFT    "); 
}
if(dir == STOP){
lcd.print("STOP    "); 
}
if(dir == M_LEFT){
lcd.print("M-LEFT  "); 
}
if(dir == M_RIGHT){
lcd.print("M-RIGHT "); 
}
if(dir == UP){
lcd.print("UP      "); 
}
if(dir == DOWN){
lcd.print("DOWN    "); 
}*/

//Show ACCESSORIES
for (int i = ACCESSORIES - 1; i >= 0; i--) {
  lcd.setCursor(i, 1);
  lcd.print(acc[i]);  
}

//Show speed
lcd.setCursor(ACCESSORIES+1, 1); 
if(speed > 250){
  lcd.print("H");  
}else if (speed > 100){
  lcd.print("M");  
}else{
  lcd.print("L");  
}



}

  void LCD::updateRTC(){
    lcd.setCursor(0,0);
    lcd.print("Received :)");
  }
void LCD::clear(){
  lcd.setCursor(0,0);
  lcd.print("               ");
}
