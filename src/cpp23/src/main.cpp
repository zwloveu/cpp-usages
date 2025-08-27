#include <iostream>

import math;

int main()
{
    std::cout << "C++ version: " << __cplusplus << std::endl;

    std::cout << "add(1, 2) = " << math::add(1, 2) << std::endl;
    std::cout << "sub(1, 2) = " << math::sub(1, 2) << std::endl;

    return 0;
}