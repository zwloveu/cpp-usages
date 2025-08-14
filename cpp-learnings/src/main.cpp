#include <iostream>
#include "MyClass.h"
#include "MyString.h"

int main()
{
    std::cout << "C++ standard version: " << __cplusplus << std::endl;

    MyClass o{12};
    o.print_x();
    std::cout << "Address of o is " << &o << std::endl;

    // error: use of deleted function 'MyClass::MyClass()
    // MyClass default_obj;

    MyClass o1 = o;
    o1.print_x();
    std::cout << "Address of o1 is " << &o1 << std::endl;

    MyClass o2{15};
    o2.print_x();
    std::cout << "Address of o2 is " << &o2 << std::endl;
    o2 = o1;
    o2.print_x();

    const MyString m_str{"hello cpp"};
    auto str = m_str.c_str();
    std::cout << str << std::endl;
    std::cout << "last char is " << str[m_str.size() - 1] << std::endl;

    return 0;
}
