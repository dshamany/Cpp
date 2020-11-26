#include <iostream>
#include <iomanip>

#include "beverage.hpp"
#include "beverageDecorator.hpp"
#include "decorator.hpp"
// #include "implementations.hpp"

int main(int argc, char const *argv[])
{
    Beverage *item = new Beverage("Coffee", 0.99);
    item = new Decorator("Soy", 0.11, item);
    item = new Decorator("Vanilla Blend", 0.05, item);
    item = new Decorator("Chocolate", 0.15, item);
    item = new Decorator("Light Ice", 0.01, item);
    item = new Decorator("Whip", 0.01, item);
    item = new Decorator("Chia Seeds", 0.25, item);

    // Beverage *item = new Coffee();
    // item = new CoconutMilk(item);
    // item = new Honey(item);

    std::cout << item->description() << '\n';
    std::cout << "$" << std::setprecision(3) << item->cost() << '\n';

    return 0;
}
