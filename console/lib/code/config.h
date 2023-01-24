#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Arduino.h>

// GLOBAL
#define BAUD_RATE 115200

// ETHERNET
#define DEBUG_ETHERNET 0
#define SHOW_MAC_AND_IP 0
#define MAC_COUNT 6
#define IP_COUNT 4
#define ETHERNET_BOX_MAC_0 0xDE
#define ETHERNET_BOX_MAC_1 0xAD
#define ETHERNET_BOX_MAC_2 0xBE
#define ETHERNET_BOX_MAC_3 0xEF
#define ETHERNET_BOX_MAC_4 0xFE
#define ETHERNET_BOX_MAC_5 0xED
#define IP_0 192
#define IP_1 168
#define IP_2 1
#define BOX_IP_3 7
#define CONSOLE_IP_3 9
#define BOX_PORT 8000
#define CONSOLE_PORT 7000
#define FRAME_RECIEVED_SIZE 10
#define FRAME_SENT_SIZE 34
#define CRITICAL_TIME 2000

#endif