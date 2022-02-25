#include "../include/npy.hpp"
#include <iostream>

// test on a simple int32 array
void f0(){
    FieldDescriptor desc{BaseFieldType::int32, 4};
    int32_t X[] = {1,2,3,4};
    NPYWrite("A.npy", {1,0}, desc, Shape(2,2,2), X);
}
// test on a simple 2-field structure
void f1(){
    struct {int32_t x,y;} v = {1,2};
    StructDescriptor desc(2, 4, 
        FieldDescriptor{BaseFieldType::int32, 4},
        FieldDescriptor{BaseFieldType::int32, 4}
    );
    NPYWrite("B.npy", {1,0}, desc, Shape::noShape(), &v);
}
// test on a null terminated ASCII string
void f2(){
    struct str {char s[4];};
    str X[] = {"foo", "bar"};
    FieldDescriptor desc = {{PrimitiveType::STRING, 4}, 1};
    NPYWrite("C.npy", {1,0}, desc, Shape(1,2), X);
}
// test on a more complex structure, with V2.0
void f3(){
    struct Foo{
        int16_t x;
        char y[5];
        int32_t z;
    };
    Foo X[] = {{1,"foo\0", 2}, {3, "bar\0", 4}};
    StructDescriptor desc(3, 4, 
        FieldDescriptor{BaseFieldType::int16, 2},
        FieldDescriptor{{PrimitiveType::STRING, 5}, 1},
        FieldDescriptor{BaseFieldType::int32, 4}
    );
    NPYWrite("D.npy", {2,0}, desc, Shape(2,2,1), X);
}

int main(int argc, char const *argv[])
{
    f0();
    f1();
    f2();
    f3();
    return 0;
}
