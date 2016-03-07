#include "usartCommunication.h"
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

//set stream pointer
FILE usart0_str = FDEV_SETUP_STREAM(USART0SendByte, NULL, _FDEV_SETUP_WRITE);

void InitADC()
{
 // Select Vref=AVcc
 ADMUX |= (1<<REFS0);
 //set prescaller to 128 and enable ADC 
 ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);    
}

uint16_t ReadADC(uint8_t ADCchannel)
{
 //select ADC channel with safety mask
 ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);
 //single conversion mode
 ADCSRA |= (1<<ADSC);
 // wait until ADC conversion is complete
 while( ADCSRA & (1<<ADSC) );
 return ADC;
}


int main(void)
{
    double value = 0.0;
    //initialize ADC
    InitADC();
    //Initialize USART0
    USART0Init();
    //assign our stream to standart I/O streams
    stdout=&usart0_str;
    
    while(1)
    {
        value =(double)0.5*ReadADC(PORTC0); 
        
        printf("%u\n", (uint16_t)value);
    }
}