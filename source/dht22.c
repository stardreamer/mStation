#include "dht22.h"

void readData(dht22Data* pData)
{
    
}

void dht_init(dht22Data* pData)
{
    DDR_DHT &= ~(_BV((*pData).pinNumber));
    PORT_DHT |= _BV((*pData).pinNumber);
}