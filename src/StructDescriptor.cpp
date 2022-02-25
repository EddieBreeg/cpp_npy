#include "StructDescriptor.hpp"

StructDescriptor::StructDescriptor(size_t nFields, size_t align, const FieldDescriptor *fieldDescriptors):
    _nFields(nFields)
{
    _fields = new Field[_nFields];
    for(size_t i=0; i<_nFields; ++i)
        _fields[i] = Field(fieldDescriptors[i]);
    computeOffsets(align);
}
void StructDescriptor::computeOffsets(size_t align)
{
    _fields[0]._size = _fields[0]._descr.size();
    _size=_fields[0]._size;
    for (size_t i = 1; i < _nFields; i++)
    {
        Field& f = _fields[i];
        Field& prev = _fields[i-1];
        f._size = f._descr.size();
        // size of the previous field
        // initial offset without aligning
        f._offset = prev._offset+prev._size;
        // padding
        f._padding = (f._descr.align - (f._offset % f._descr.align)) % f._descr.align;
        // aligned offset
        f._offset += f._padding;
        _size += f._padding + f._size;
    }
    _padding = (align - (_size%align)) % align;
    _size += _padding;
}
const Field* StructDescriptor::begin() const { return _fields;};
const Field* StructDescriptor::end() const { return _fields+_nFields; };
const Field& StructDescriptor::operator[](size_t index) const { return _fields[index]; }

std::string StructDescriptor::toString() const{
    std::stringstream s;
    s << '[';
    for(size_t i=0; i<_nFields-1; ++i){
        const Field& f = _fields[i];
        if(f._padding) s << "('','|V" << f._padding << "'),";
        s << "('" << i << "'," << f._descr.toString() << "),";
    }
    const Field& last = _fields[_nFields-1];
    if(last._padding) s << "('','|V" << last._padding << "'),";
    s << "('" << _nFields-1 << "'," << last._descr.toString() << ')';
    if(_padding) s << ",('','|V" << _padding << "')";
    s << ']';
    return s.str();
}


StructDescriptor::~StructDescriptor()
{
    delete[] _fields;
}