#include "Vector.h"
#include <iostream>
// Vector and Seperation.cpp share the same Vector interface information 
// These two files are otherwise independent and can be compiled seperately 
Vector::Vector(int s)
    :elem{new double[s]}, sz{s}
{
}

double& Vector::operator[](int i) { 
    return elem[i];
}

int Vector::size() const { 
    return sz;
}

int main(){ 
    Vector a(5);
    const Vector * b = &a;
}