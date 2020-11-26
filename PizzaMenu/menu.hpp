#ifndef MENU_HPP
#define MENU_HPP

#include "pizza.hpp"
#include "topingDecorator.hpp"

namespace PizzaType
{
    struct ThinCrust : public Pizza
    {
        ThinCrust()
        {
            this->description("Thin Crust");
            this->cost(4.99);
        }
    };

    struct ThickCrust : public Pizza
    {
        ThickCrust()
        {
            this->description("Thick Crust");
            this->cost(5.99);
        }
    };
} // namespace PizzaType

namespace Sauce
{

    struct Marinara : public Topping
    {
        Marinara() = delete;
        Marinara(Pizza *pizza)
        {
            this->description(pizza->description() + ", Marinara Sauce");
            this->cost(pizza->cost() + 0.49);
        }
    };

    struct Alfredo : public Topping
    {
        Alfredo() = delete;
        Alfredo(Pizza *pizza)
        {
            this->description(pizza->description() + ", Alfredo Sauce");
            this->cost(pizza->cost() + 0.49);
        }
    };

    struct Pesto : public Topping
    {
        Pesto() = delete;
        Pesto(Pizza *&pizza)
        {
            this->description(pizza->description() + ", Pesto Sauce");
            this->cost(pizza->cost() + 0.49);
        }
    };
} // namespace Sauce

namespace Toppings
{

    struct Pepperoni : public Topping
    {
        Pepperoni() = delete;
        Pepperoni(Pizza *&pizza)
        {
            this->description(pizza->description() + ", Pepperoni");
            this->cost(pizza->cost() + 0.25);
        }
    };

    struct Cheese : public Topping
    {
        Cheese() = delete;
        Cheese(Pizza *pizza)
        {
            this->description(pizza->description() + ", Cheese");
            this->cost(pizza->cost() + 0.25);
        }
    };

    struct Olives : public Topping
    {
        Olives() = delete;
        Olives(Pizza *pizza)
        {
            this->description(pizza->description() + ", Olives");
            this->cost(pizza->cost() + 0.25);
        }
    };

    struct Pepper : public Topping
    {
        Pepper() = delete;
        Pepper(Pizza *pizza)
        {
            this->description(pizza->description() + ", Pepper");
            this->cost(pizza->cost() + 0.25);
        }
    };

    struct Onions : public Topping
    {
        Onions() = delete;
        Onions(Pizza *pizza)
        {
            this->description(pizza->description() + ", Onions");
            this->cost(pizza->cost() + 0.25);
        }
    };

} // namespace Toppings

#endif // MENU_HPP