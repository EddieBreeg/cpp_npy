#include "fields.hpp"
#include <algorithm>

Shape::Shape(): _size(0){}
Shape::~Shape(){ delete[] _dims; }

const unsigned& Shape::operator[](size_t index) const { return _dims[index]; }
const unsigned* Shape::begin() const { return _dims; }
const unsigned* Shape::end() const { return _dims+_size; }

size_t Shape::dimensions() const { return _size; }
size_t Shape::nElements() const{
    size_t r=1;
    for(size_t i=0; i<_size; ++i) r*=_dims[i];
    return r;
}

Shape::Shape(const Shape& other): _size(other._size){
    _dims = new unsigned[_size];
    for(size_t i=0; i<_size; ++i)
        _dims[i] = other._dims[i];
}
Shape::Shape(Shape&& other): _size(other._size), _dims(other._dims){
    other._dims = nullptr;
}
Shape& Shape::operator=(const Shape& other){
    _size = other._size;
    delete[] _dims;
    _dims = new unsigned[_size];
    for(size_t i=0; i<_size; ++i)
        _dims[i] = other._dims[i];
    return *this;
}
Shape& Shape::operator=(Shape&& other){
    std::swap(this->_size, other._size);
    std::swap(this->_dims, other._dims);
    return *this;
}
Shape Shape::noShape() { return Shape(); }

std::ostream& operator<<(std::ostream& s, const Shape& shape){
    s << '(';
    for(unsigned d: shape)
        s << d << ',';
    s << ')';
    return s;
}