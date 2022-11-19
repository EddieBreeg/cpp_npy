# C++ NPY

A tiny library that brings support for the NPY file format in C++.

## Building and linking

The library is built using CMake:
```
> cmake -B ./build
> cmake --build ./build
```

The static library is output to to lib folder, all you have to do is to link it into your own project.

## How is it used?

The [test.cpp](tests/test.cpp) file contains a simple example of how the API works.
Comments have also been added in the header files. 