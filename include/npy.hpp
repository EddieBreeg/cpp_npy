#pragma once
#include <string>
#include "fields.hpp"
#include "StructDescriptor.hpp"
#include <fstream>

struct Version
{
    char major, minor;
};

/**
 * Writes an array to a file
 * @param filename: The name of the file to write the data into
 * @param v: The NPY file format version to use. Valid values are 1.0, 2.0 and 3.0
 * @param descr: A descriptor for the elements of the array
 * @param shape: The shape descriptor of the array
 * @param data: A pointer to the data to write
*/
void NPYWrite(std::string filename, Version v,const Descriptor& descr, const Shape& shape, const void* data);