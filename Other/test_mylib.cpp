#include <iostream>
#include "mylib.h"

int main(int argc, char const *argv[])
{
    auto o = MyObject(7);
    std::cout << o.value() << '\n';
    return 0;
}
