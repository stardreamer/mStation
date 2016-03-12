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
    
    dht22Data mydata = {
        .integralTemp = 0,
        .fracTemp = 0,
        .integralHumidity = 0,
        .fracHumidity = 0,
        .pinNumber = 1,
        .errorCode = DHT_NOT_INIT};
        
    dht_init(&mydata);
    
    while(1)
    {
        printf("%i %i %i\n", mydata.integralTemp, mydata.pinNumber, mydata.errorCode);
    }
}
