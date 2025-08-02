#include "CppPrimer/Domain/Geography/Country.h"

#include <iostream>

namespace Geography = CppPrimer::Domain::Geography;

int main()
{
    Geography::Country china("China", 1412000000, 9596961.0);
    china.displayInfo();

    Geography::Country unknown;
    unknown.setName("New Country");
    unknown.setPopulation(1000000);
    unknown.setArea(500000.5);
    unknown.displayInfo();

    const Geography::Country china2("China", 1412000000, 9596961.0);
    // china2.setPopulation(1000000); const object can only access const-qualifying member function
    china2.displayInfo();

    return 0;
}