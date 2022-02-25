#pragma once

#include <iostream>
#include <string>

struct Descriptor
{
    virtual std::string toString() const = 0;
    virtual size_t size() const = 0;
};