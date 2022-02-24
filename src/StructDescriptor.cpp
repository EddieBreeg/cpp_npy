#include "StructDescriptor.hpp"

#include <bit>
static const char endianPrefix = std::endian::native==std::endian::little? '<':'>';

void StructDescriptor::computeOffsets()
{
    for (size_t i = 1; i < _nFields; i++)
    {
        Field& f = _fields[i];
        Field& prev = _fields[i-1];
        // size of the previous field
        size_t prevSize = prev._descr.shape.nElements()*prev._descr.type.size;
        // initial offset without aligning
        f._offset = prev._offset+prevSize;
        // padding
        f._padding = (f._descr.align - (f._offset % f._descr.align)) % f._descr.align;
        // aligned offset
        f._offset += f._padding;
    }
}
const Field* StructDescriptor::begin() const { return _fields;};
const Field* StructDescriptor::end() const { return _fields+_nFields; };
const Field& StructDescriptor::operator[](size_t index) const { return _fields[index]; }

StructDescriptor::~StructDescriptor()
{
    delete[] _fields;
}