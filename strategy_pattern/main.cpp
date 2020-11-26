#include <iostream>

#include "duck.hpp"

using std::cout;

int main(int argc, char const *argv[])
{
    auto mallard = new Duck("Mallard", true, 'Q');

    cout << " ...I'm "
         << mallard->performFly() << " and "
         << mallard->swim() << " ...so " << mallard->performQuack() << '\n';
    return 0;
}
