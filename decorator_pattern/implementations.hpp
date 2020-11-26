#ifndef IMPLEMENTATIONS_HPP
#define IMPLEMENTATIONS_HPP

#include "beverage.hpp"
#include "decorator.hpp"

// BEVERAGES
struct Coffee : public Beverage
{
public:
    Coffee()
    {
        description("Coffee");
        cost(0.99);
    }
    explicit Coffee(Beverage *beverage, const float &price = 0.99)
    {
        const std::string &type = ", Coffee";
        description(beverage->description() + type);
        cost(beverage->cost() + price);
    }
};

// DECORATORS
struct Soy : public Decorator
{
    Soy();
    explicit Soy(Beverage *beverage, const float &price = 0.19)
    {
        this->description(", Soy");
        this->cost(price);
        Soy(this);
    }
};

struct CoconutMilk : public Decorator
{
    CoconutMilk();
    explicit CoconutMilk(Beverage *beverage, const float &price = 0.49)
    {
        this->description(", Coconut Milk");
        this->cost(price);
        CoconutMilk(this);
    }
};

struct Honey : public Decorator
{
    Honey();
    explicit Honey(Beverage *beverage, const float &price = 0.05)
    {
        this->description(", Honey");
        this->cost(price);
        Honey(this);
    }
};

#endif //IMPLEMENTATIONS_HPP