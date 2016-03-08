#ifndef DATATYPES_H
#define DATATYPES_h
typedef struct SensorsData sensorsData;

struct SensorsData
{
    int lm35Temp;
    double bmp280Pressure;
    double bmp280Temp;
    double bmp280Altitude;
    double dht22Temp;
    double dht22Humidity;
};
#endif