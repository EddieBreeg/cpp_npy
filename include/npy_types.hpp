#pragma once
#include <stddef.h>

enum PrimitiveType
{
    BOOL,
    INT,
    UINT,
    BYTE,
    UBYTE,
    STRING,
    FLOAT,
    VOID
};
struct FieldType
{
    PrimitiveType type;
    size_t size;
};
// basic types
struct BaseFieldType{
    constexpr static FieldType boolean = {PrimitiveType::BOOL, sizeof(bool)};
    constexpr static FieldType int8 = {PrimitiveType::BYTE, 1};
    constexpr static FieldType uint8 = {PrimitiveType::UBYTE, 1};
    constexpr static FieldType int16 = {PrimitiveType::INT, 2};
    constexpr static FieldType uint16 = {PrimitiveType::UINT, 2};
    constexpr static FieldType int32 = {PrimitiveType::INT, 4};
    constexpr static FieldType uint32 = {PrimitiveType::UINT, 4};
    constexpr static FieldType int64 =  {PrimitiveType::INT,  8};
    constexpr static FieldType uint64 = {PrimitiveType::UINT, 8};
};