#ifndef BEVERAGE_DECORATOR_HPP
#define BEVERAGE_DECORATOR_HPP

#include "item.hpp"

class BeverageDecorator : public Item
{
public:
    BeverageDecorator();
    BeverageDecorator(Item *);
    Item *beverage();
    Item operator*(BeverageDecorator *beverageDecorator)
    {
        return *beverageDecorator->beverage();
    }
    const std::string description() const;

private:
    Item *_beverage;
};

BeverageDecorator::BeverageDecorator() {}

BeverageDecorator::BeverageDecorator(Item *beverage)
{
    _beverage = new Beverage(
        beverage->description() + ", " + _beverage->description(),
        beverage->cost() + _beverage->cost());
}

Item *BeverageDecorator::beverage()
{
    return _beverage;
}

const std::string BeverageDecorator::description() const
{
    return _beverage->description();
}

#endif // BEVERAGE_DECORATOR_HPP