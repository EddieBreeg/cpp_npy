#include "npy.hpp"

void NPYWrite(std::string filename, Version v,const Descriptor& descr, const Shape& shape, const void* data)
{
    if(v.major>2 || !v.major) throw "unsupported NPY version";
    std::ofstream output(filename, std::ios_base::binary);
    if(!output.is_open()) throw (std::string("Couldn't open file") + filename);
    // magic string and version
    output << "\x93NUMPY" << v.major << v.minor;
    unsigned sizeFieldLen = v.major>1? 4:2;
    for(int i=0; i<sizeFieldLen; ++i)
        output << '\0';
    output << "{'descr':" << descr.toString() << ",'fortran_order':False,'shape':" << shape << '}';
    uint32_t headerSize = (uint32_t)output.tellp();
    while((headerSize++ & 63) < 63) output << ' ';
    output << '\n'; headerSize-=8+sizeFieldLen;
    output.seekp(8, std::ios_base::beg);
    for (unsigned i = 0; i < sizeFieldLen; i++)
    {
        output << (char)(headerSize&0xff);
        headerSize >>= 8;
    }
    output.seekp(0, std::ios_base::end);
    size_t dataSize = descr.size() * shape.nElements();
    output.write((const char*)data, dataSize);
    output.close();
}