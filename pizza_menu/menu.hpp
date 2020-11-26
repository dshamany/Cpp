#ifndef MENU_HPP
#define MENU_HPP

#include "pizza.hpp"
#include "topping.hpp"

namespace menu
{
    namespace dough
    {
        struct ThinCrust : public Pizza
        {
            ThinCrust() = delete;
            ThinCrust(Pizza *pizza = new Pizza("unknown pizza", 0.00f))
            {
                auto name = "Thin Crust";
                auto cost = 5.99f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };

        struct ThickCrust : public Pizza
        {
            ThickCrust() = delete;
            ThickCrust(Pizza *pizza = new Pizza("unknown pizza", 0.00f))
            {
                auto name = "Thick Crust";
                auto cost = 6.99f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };
    } // namespace dough

    namespace sauce
    {
        struct Marinara : public Topping
        {
            Marinara() = delete;
            Marinara(Pizza *pizza)
            {
                auto name = "Marinara Sauce";
                auto cost = 0.00f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };

        struct Pesto : public Topping
        {
            Pesto() = delete;
            Pesto(Pizza *pizza)
            {
                auto name = "Pesto Sauce";
                auto cost = 0.10f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };
    } // namespace sauce

    namespace toppings
    {
        struct Olives : public Topping
        {
            Olives() = delete;
            Olives(Pizza *pizza)
            {
                auto name = "Olives";
                auto cost = 0.25f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };

        struct Onions : public Topping
        {
            Onions() = delete;
            Onions(Pizza *pizza)
            {
                auto name = "Onions";
                auto cost = 0.25f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };

        struct Pepperoni : public Topping
        {
            Pepperoni() = delete;
            Pepperoni(Pizza *pizza)
            {
                auto name = "Pepperoni";
                auto cost = 0.49f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };

        struct Ham : public Topping
        {
            Ham() = delete;
            Ham(Pizza *pizza)
            {
                auto name = "Ham";
                auto cost = 0.49f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };

        struct Cheese : public Topping
        {
            Cheese() = delete;
            Cheese(Pizza *pizza)
            {
                auto name = "Cheese";
                auto cost = 0.25f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };

        struct Pinapple : public Topping
        {
            Pinapple() = delete;
            Pinapple(Pizza *pizza)
            {
                auto name = "Pinapple";
                auto cost = 0.25f;
                this->set(pizza->description() + ", " + name, pizza->cost() + cost);
            }
        };

    } // namespace toppings
} // namespace menu

#endif