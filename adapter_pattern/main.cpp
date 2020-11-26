#include <iostream>

#include "tests.hpp"
#include "duck.hpp"
#include "turkey.hpp"
#include "adapter.hpp"

int main(int argc, char const *argv[])
{
    test(new Duck());
    puts("");

    auto turkey = new Turkey_Adapter(new Turkey());
    auto chicken = new Chicken_Adapter(new Chicken());

    test(turkey);
    puts("");

    test(chicken);
    puts("");

    return 0;
}
