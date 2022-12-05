 #define VIN A0
#define vcc 5.0
void setup() {

Serial.begin(9600);
}

void loop() {
  double voltage =   (5.0 / 1023.0) * analogRead(VIN); // Read the voltage from sensor
  voltage =  voltage - (vcc * 0.5) + 0.007 ;// 0.007 is a value to make voltage zero when there is no current
  int current = round(voltage / 0.04);//Factor differs from a model to another
  Serial.print("Current= ");
  Serial.println(round(current));
}
