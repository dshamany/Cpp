#include <iostream>

#include "pizza.hpp"
#include "menu.hpp"

using namespace PizzaType;
using namespace Sauce;
using namespace Toppings;

int main(int argc, char const *argv[])
{
    Pizza *thin = new ThinCrust();
    thin = new Marinara(thin);
    thin = new Cheese(thin);
    thin = new Onions(thin);
    thin = new Olives(thin);

    std::cout << thin->description() << '\n';
    std::cout << thin->cost() << '\n';
    return 0;
}
