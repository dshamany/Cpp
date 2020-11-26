#include <iostream>

struct Entity {
    static int x, y;
};

namespace Ent {
    static int x, y;
}

int Entity::x;
int Entity::y;

int main(int argc, char const *argv[])
{
    Ent::x = 2;
    Ent::y = 3;

    std::cout << Ent::x << ", " << Ent::y << std::endl;

    return 0;
}
