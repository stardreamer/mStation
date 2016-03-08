#include "core.h"

//set stream pointer
FILE usart0_str = FDEV_SETUP_STREAM(USART0SendByte, NULL, _FDEV_SETUP_WRITE);

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
        value =((double)500/1023)*ReadADC(PORTC0); 
        
        printf("%u\n", (uint16_t)value);
    }
}
