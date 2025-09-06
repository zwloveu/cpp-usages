#include <iostream>

#include "cpp11/feature_modules/module06_namespace/demonstrate_namespace.h"
#include "cpp11/feature_modules/module06_namespace/country.h"

namespace module06_namespace
{
    void demonstrate_namespace_basic()
    {
        Country china("China", 1412000000, 9596961.0);
        china.displayInfo();

        Country unknown;
        unknown.setName("New Country");
        unknown.setPopulation(1000000);
        unknown.setArea(500000.5);
        unknown.displayInfo();

        const Country china2("China", 1412000000, 9596961.0);
        // china2.setPopulation(1000000); const object can only access const-qualifying member function
        china2.displayInfo();
    }
}