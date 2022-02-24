#pragma once

#include <stddef.h>
#include <concepts>

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

class Shape
{
private:
    size_t _size;
    unsigned *_dims = nullptr;
public:
    template<typename... arg_t>
    Shape(size_t nDims, arg_t... dims): _size(nDims)
    {
        _dims = new unsigned[_size]{(unsigned)dims...};
    }
    Shape();
    Shape(const Shape&);
    Shape(Shape&&);
    Shape& operator=(const Shape&);
    Shape& operator=(Shape&&);
    
    ~Shape();
    const unsigned& operator[](size_t index) const;
    const unsigned* begin() const;
    const unsigned* end() const;
    size_t dimensions() const;
    size_t nElements() const;

    static Shape noShape();
};
struct FieldDescriptor
{
    FieldType type;
    Shape shape = Shape();
};
struct Field
{
    FieldDescriptor _descr;
    size_t _offset, _padding, _size;
};