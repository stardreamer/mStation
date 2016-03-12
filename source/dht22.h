#ifndef DHT22_H
#define DHT22_H
#define DDR_DHT DDRB
#define PORT_DHT PORTB
#define PIN_DHT PINB
#define F_CPU 16000000UL
#define DHT_ERROR 1
#define DHT_NOT_INIT 2
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

typedef struct Dht22Data dht22Data;

struct Dht22Data
{
    uint8_t integralTemp;
    uint8_t fracTemp;
    uint8_t integralHumidity;
    uint8_t fracHumidity;
    unsigned char pinNumber;
    char errorCode;
};

void readData(dht22Data* pData);

void dht_init(dht22Data* pData);
#endif