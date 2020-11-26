#ifndef TOPPING_HPP
#define TOPPING_HPP

#include "pizza.hpp"

class Topping : public Pizza
{
public:
    Topping(){};
    Topping(Pizza *pizza, const std::string &desc = "unknown", const float &cost = 0.00)
        : _pizza(pizza)
    {
        this->set(desc, cost);
    }
    virtual const std::string description()
    {
        return _pizza->description();
    }

private:
    Pizza *_pizza;
};

#endif //TOPPING_HPP