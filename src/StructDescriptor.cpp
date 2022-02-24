#include "StructDescriptor.hpp"


void StructDescriptor::computeOffsets()
{
    size_t maxSize = _fields[0]._descr.type.size;
    _fields[0]._offset = 0;
    _fields[0]._size = maxSize * _fields[0]._descr.shape.nElements();
    
    for (size_t i = 1; i < _nFields; i++)
    {
        Field* f = _fields+i;
        Field* prev = _fields+i-1;
        maxSize = maxSize>f->_descr.type.size? maxSize:f->_descr.type.size;
        // compute field total size
        f->_size = f->_descr.type.size * f->_descr.shape.nElements();
        // compute offset
        f->_offset = prev->_offset + prev->_size;
        f->_offset += (f->_descr.type.size - (f->_offset % f->_descr.type.size)) % f->_descr.type.size; // align
        prev->_padding = f->_offset - (prev->_offset + prev->_size);
    }
    Field& last = _fields[_nFields-1];
    last._padding = (maxSize-((last._offset+last._size)%maxSize)) % maxSize;
}
const Field* StructDescriptor::begin() const { return _fields;};
const Field* StructDescriptor::end() const { return _fields+_nFields; };

StructDescriptor::~StructDescriptor()
{
    delete[] _fields;
}