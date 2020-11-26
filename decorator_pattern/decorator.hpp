#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <string>

#include "beverage.hpp"

class Decorator : public Beverage
{
public:
    Decorator() {}
    Decorator(const std::string &desc, const float &price, Beverage *beverage = nullptr)
    {
        if (beverage)
        {
            description(beverage->description() + ", " + desc);
            cost(beverage->cost() + price);
        }
        else
        {
            description(desc);
            cost(price);
        }
    }
};

#endif //DECORATOR_HPP