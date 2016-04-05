#include "core.h"

//set stream pointer
FILE usart0_str = FDEV_SETUP_STREAM(USART0SendByte, NULL, _FDEV_SETUP_WRITE);

int main(void)
{
    //initialize ADC
    InitADC();
    //Initialize USART0
    USART0Init();
    //assign our stream to standart I/O streams
    stdout=&usart0_str;
}
