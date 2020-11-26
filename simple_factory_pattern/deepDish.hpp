#ifndef DEEPDISH_HPP
#define DEEPDISH_HPP

#include "pizzaStore.hpp"
#include <string>

class DeepDish
{
public:
    explicit DeepDish()
        : _store(new PizzaStore("Deep Dish")) {}

private:
    PizzaStore *_store;
};

#endif //DEEPDISH