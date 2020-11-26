#include <iostream>

void increment(int& value) {
    value++;
}

int main(int argc, char const *argv[])
{
    int a = 256;
    increment(a);

    std::cout << std::dec << &a << std::endl;
    std::cout << std::hex << a << std::endl;
    std::cout << std::oct << a << std::endl;

    printf("%d\n", &a);

    return 0;
}
