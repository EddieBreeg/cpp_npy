#pragma once
#include <string>
#include "fields.hpp"
#include "StructDescriptor.hpp"
#include <fstream>

struct Version
{
    char major, minor;
};


void NPYWrite(std::string filename, Version v,const Descriptor& descr, const Shape& shape, const void* data);