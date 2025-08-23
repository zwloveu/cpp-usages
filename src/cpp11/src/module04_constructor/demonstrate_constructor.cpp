#include <iostream>

#include "module04_constructor/demonstrate_constructor.h"
#include "module04_constructor/my_class.h"

void demonstrate_constructor_basic()
{
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
}