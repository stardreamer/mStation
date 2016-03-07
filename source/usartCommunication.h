#ifndef USARTCOMMUNICATION_H
#define USARTCOMMUNICATION_H
#define F_CPU 16000000UL
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define USART_BAUDRATE 9600
#include <avr/io.h>
#include <stdio.h>

void USART0Init(void);
int USART0SendByte(char u8Data, FILE *stream);
#endif