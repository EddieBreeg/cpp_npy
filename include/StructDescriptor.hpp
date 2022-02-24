#pragma once
#include "fields.hpp"


class StructDescriptor
{
private:
    size_t _nFields;
    Field *_fields = nullptr;
    void computeOffsets();
public:
    template<typename... desc_t>
    StructDescriptor(size_t nFields, desc_t... fieldDescriptors): _nFields(nFields)
    {
        _fields = new Field[_nFields]{ {fieldDescriptors}... };
        computeOffsets();
    }
    const Field* begin() const;
    const Field* end() const;
    ~StructDescriptor();
};

