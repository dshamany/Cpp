#include "duck.hpp"
#include <iostream>

bool test(Duck *duck)
{
    std::cout << duck->swim() << '\n';
    std::cout << duck->performFly() << '\n';
    std::cout << duck->performQuack() << '\n';
    return true;
}