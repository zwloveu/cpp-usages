#include <iostream>
#include "MyClass.h"

MyClass::MyClass(int x)
    : x{x}
{
    std::cout << "User-provided constructor invoked." << std::endl;
}

MyClass::MyClass(const MyClass &rhs)
    : x(rhs.x)
{
    std::cout << "User-provided copy constructor invoked." << std::endl;
}

MyClass &MyClass::operator=(const MyClass &rhs)
{
    std::cout << "User-provided copy assignment operator invoked." << std::endl;

    if (this != &rhs)
    {
        x = rhs.x;
    }

    return *this;
}

void MyClass::print_x() const
{
    std::cout << "The value of x is:" << x << std::endl;
}