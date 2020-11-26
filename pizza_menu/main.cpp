#include <iostream>

#include "pizza.hpp"
#include "menu.hpp"

using namespace menu;
using namespace menu::dough;
using namespace menu::sauce;
using namespace menu::toppings;

int main(int argc, char const *argv[])
{
    Pizza *pizza = new Pizza("Hawaian Pizza");
    pizza = new ThinCrust(pizza);
    pizza = new Marinara(pizza);
    pizza = new Cheese(pizza);
    pizza = new Pepperoni(pizza);
    pizza = new Ham(pizza);
    pizza = new Pinapple(pizza);

    std::cout
        << pizza->description() << '\n';
    std::cout << '$' << pizza->cost() << '\n';

    return 0;
}
