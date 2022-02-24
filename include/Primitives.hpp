#pragma once

#include <stddef.h>

enum PrimitiveType
{
    INT8,
    INT16,
    INT32,
    INT64,
    UINT8,
    UINT16,
    UINT32,
    UINT64,
    FLOAT,
    DOUBLE,
    LONG_DOUBLE
};
struct PrimitiveSize
{
    const static size_t INT8_SIZE =     1;
    const static size_t INT16_SIZE =    2;
    const static size_t INT32_SIZE =    4;
    const static size_t INT64_SIZE =    8;
    const static size_t FLOAT_SIZE =    sizeof(float);
    const static size_t DOUBLE_SIZE =   sizeof(double);
    const static size_t LONG_DOUBLE_SIZE =   sizeof(long double);
};
