#ifndef DHT22_H
#define DHT22_H
#define DHT_ERROR 1
#include<stdint.h>

typedef struct Dht22Data dht22Data;

struct Dht22Data
{
    uint8_t integralTemp;
    uint8_t fracTemp;
    uint8_t integralHumidity;
    uint8_t fracHumidity;
    char errorCode;
};

void readData(dht22Data* pData);

void dht_init(uint8_t pinNumber);
#endif