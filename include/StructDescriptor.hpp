#pragma once
#include "fields.hpp"

class StructDescriptor: public Descriptor
{
private:
    size_t _nFields;
    Field *_fields = nullptr;
    size_t _size=0, _padding=0;
    void computeOffsets(size_t align);
public:
    /**
     * Constructs a structure descriptor from a list of field descriptors
     * @param nFields: The total number of fields
     * @param align: How the structure is aligned in memory
     * @param fieldDescriptors: The field descriptors
    */
    StructDescriptor(size_t nFields, size_t align, const FieldDescriptor *fieldDescriptors);
    template<typename... desc_t>
    /**
     * Constructs a structure descriptor from a list of field descriptors
     * @param nFields: The total number of fields
     * @param align: How the structure is aligned in memory
     * @param fieldDescriptors: The field descriptors
    */
    StructDescriptor(size_t nFields, size_t align, desc_t&&... fieldDescriptors): _nFields(nFields)
    {
        _fields = new Field[_nFields]{Field(fieldDescriptors)...};
        computeOffsets(align);
    }
    const Field* begin() const;
    const Field* end() const;
    const Field& operator[](size_t index) const;
    size_t size() const { return _size; }
    std::string toString() const;
    ~StructDescriptor();
};

