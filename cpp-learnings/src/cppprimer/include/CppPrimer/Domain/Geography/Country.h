#pragma once

#include <string>
#include "CppPrimer/SharedKernel/Constants.h"

namespace Constants = CppPrimer::SharedKernel::Constants;

namespace CppPrimer::Domain::Geography
{
    class Country
    {
    public:
        Country() = default;

        Country(const std::string &name, int population, double area);

        void displayInfo() const;
        void setName(const std::string &newName);
        void setPopulation(int newPopulation);
        void setArea(double newArea);

        std::string getName() const;
        int getPopulation() const;
        double getArea() const;

    private:
        std::string name = Constants::DEFAULT_COUNTRY_NAME;
        int population = Constants::DEFAULT_POPULATION;
        double area = Constants::DEFAULT_AREA;
    };
}
