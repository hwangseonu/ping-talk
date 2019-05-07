#ifndef protocols_h
#define protocols_h

#include <stdint.h>

typedef struct _ETHERNET {
    uint8_t dst [6];
    uint8_t src[6];
    uint16_t type;
} Ethernet;


typedef struct _ICMP {    
    int8_t vhl;
    int8_t tos;
    int16_t totalLength;
    int16_t identifier;
    int16_t flagsAndFragmentOffset;
    int8_t ttl;
    int8_t protocol;
    int16_t headerChecksum;
    int8_t src[4];
    int8_t dst[4];
    int8_t type;
    int8_t code;
    int16_t icmpChecksum;
    int64_t data;
} ICMP;

#endif
