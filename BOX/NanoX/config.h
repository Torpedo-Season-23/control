#ifndef CONFIG_H
#define CONFIG_H

#define UDP_REC_FRAME 1+1+6 //(bytes): 1 Accessories, 1 directions + converters on/off, 6 thrusters speeds 
#define UDP_SEND_FRAME 6+2+8+6 //(bytes): 6 IMU angles, 2 pressure, 8 leakage, 3*2 converters

#endif
