#include <iostream>

#include "key_value_read.hpp"

int main(int argc, const char *argv[])
{
    auto ins = PROCESS::ENV::instance(argv[1]);
    std::cout << ins.value("Keywords") << '\n';
    return 0;
}
