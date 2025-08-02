#include "CppPrimer/Domain/Geography/Country.h"
#include <iostream>

namespace CppPrimer::Domain::Geography
{
    Country::Country(const std::string &name, int population, double area)
        : name(name), population(population > 0 ? population : 0),
          area(area > 0 ? area : 0.0) {}

    void Country::displayInfo() const
    {
        std::cout << "Country: " << name << "\n"
                  << "Population: " << population << "\n"
                  << "Area: " << area << " km²\n";
    }

    void Country::setName(const std::string &newName)
    {
        name = newName.empty() ? "Unnamed" : newName;
    }

    void Country::setPopulation(int newPopulation)
    {
        population = (newPopulation > 0) ? newPopulation : population;
    }

    void Country::setArea(double newArea)
    {
        area = (newArea > 0) ? newArea : area;
    }

    std::string Country::getName() const { return name; }
    int Country::getPopulation() const { return population; }
    double Country::getArea() const { return area; }
}
