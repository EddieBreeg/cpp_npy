#pragma once

#include <string>
#include <sstream>
#include "npy_types.hpp"
#include "Descriptor.hpp"

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

    friend std::ostream& operator<<(std::ostream& s, const Shape& shape);
    static Shape noShape();
};
struct FieldDescriptor: public Descriptor
{
    FieldType type;
    size_t align;
    Shape shape=Shape();
    FieldDescriptor(){};
    FieldDescriptor(FieldType t, size_t a, Shape&& s=Shape::noShape());
    std::string toString() const;
    size_t size() const { return shape.nElements()*type.size; };
};

struct Field
{
    FieldDescriptor _descr;
    size_t _size, _padding=0, _offset=0;
    Field(){}
    Field(const FieldDescriptor& d): _descr(d){}
};