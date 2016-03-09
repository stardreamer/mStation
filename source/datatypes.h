#ifndef DATATYPES_H
#define DATATYPES_h
typedef struct SensorsData sensorsData;
typedef struct Lm35Data lm35Data;

struct Lm35Data
{
    char Temp;
    char errorCode;
};

struct SensorsData
{
    lm35Data lm35;
};
#endif