#include <iostream>

#include "cpp11/feature_modules/module03_raii/demonstrate_raii.h"
#include "cpp11/feature_modules/module03_raii/raii_string.h"

void demonstrate_raii_basic()
{
    const RAIIString m_str{"hello cpp"};
    const auto str = m_str.c_str();
    std::cout << str << std::endl;
    std::cout << "last char is " << str[m_str.size() - 1] << std::endl;
}