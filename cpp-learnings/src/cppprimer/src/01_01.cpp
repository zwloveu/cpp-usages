#include "CppPrimer/Domain/Geography/Country.h"

#include <iostream>

namespace Geography = CppPrimer::Domain::Geography;

int main()
{
    std::cout << "Hello Cpp Primer" << std::endl;

    Geography::Country china("China", 1412000000, 9596961.0);
    china.displayInfo();

    Geography::Country unknown;
    unknown.setName("New Country");
    unknown.setPopulation(1000000);
    unknown.setArea(500000.5);
    unknown.displayInfo();

    return 0;
}