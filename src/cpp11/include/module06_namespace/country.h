#pragma once

#include <string>

#include "module06_namespace/constants.h"

namespace module06_namespace
{
    namespace Constants = module06_namespace::SharedKernel::Constants;

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