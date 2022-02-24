cmake_minimum_required(VERSION 3.2.0)
project(npy VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
add_library(npy STATIC)
target_sources(npy 
    PRIVATE src/npy.cpp
    PRIVATE src/fields.cpp
    PRIVATE src/StructDescriptor.cpp
)
