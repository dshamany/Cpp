#ifndef PIZZAS_HPP
#define PIZZAS_HPP

#include "pizza.hpp"

struct Veggie : public Pizza
{
public:
    Veggie()
        : _pizza(new Pizza("Veggie")) {}

private:
    Pizza *_pizza;
};

struct Hawaiian : public Pizza
{
public:
    Hawaiian()
        : _pizza(new Pizza("Hawaiian")) {}

private:
    Pizza *_pizza;
};

struct Pepperoni : public Pizza
{
public:
    Pepperoni()
        : _pizza(new Pizza("Pepperoni")) {}

private:
    Pizza *_pizza;
};

struct BBQ_Chicken : public Pizza
{
public:
    BBQ_Chicken()
        : _pizza(new Pizza("BBQ Chicken")) {}

private:
    Pizza *_pizza;
};

struct Kabob : public Pizza
{
public:
    Kabob()
        : _pizza(new Pizza("Kabob")) {}

private:
    Pizza *_pizza;
};

#endif // PIZZAS_HPP