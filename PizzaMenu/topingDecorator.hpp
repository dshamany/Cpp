#ifndef TOPING_DECORATOR_HPP
#define TOPING_DECORATOR_HPP

#include "pizza.hpp"

class Topping : public Pizza
{
public:
    Topping(Pizza *);
    Topping(const std::string &, const float &);
    const std::string getDescription() const;
    const float getCost() const;
    void setPizza(Pizza *);

private:
    Pizza *_pizza;
};

Topping::Topping(Pizza *pizza)
{
    _pizza = pizza;
}

Topping::Topping(const std::string &desc = "Unknown Topping", const float &cost = 0.00)
{
    this->description(desc);
    this->cost(cost);
}

const std::string Topping::getDescription() const
{
    return _pizza->description() + ", " + this->description();
}

const float Topping::getCost() const
{
    return _pizza->cost() + this->cost();
}

void Topping::setPizza(Pizza *pizza)
{
    _pizza = pizza;
}

#endif //TOPPING_DECORATOR_HPP