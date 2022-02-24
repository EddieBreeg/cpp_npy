#pragma once
#include <stdio.h>
#include <string>
#include "fields.hpp"
#include "StructDescriptor.hpp"

class NPYFileWriter
{
private:
    /* data */
public:
    NPYFileWriter(std::string fileName);
    ~NPYFileWriter();
};