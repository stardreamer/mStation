#ifndef CORE_H
#define CORE_H
#define F_CPU 16000000UL
#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "datatypes.h"
#include "dht22.h"

void USART0Init(void);
int USART0SendByte(char u8Data, FILE *stream);
void InitADC();
uint16_t ReadADC(uint8_t ADCchannel);
#endif