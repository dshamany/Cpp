#include <iostream>
#include <memory>

struct container
{
    container() : n(0) {}
    container(const int &_n) : n(_n) {}
    int n;
};

int main(int argc, char const *argv[])
{
    auto c_ptr = std::make_unique<container>(7);
    auto cpy_ptr = std::move(c_ptr);
    std::cout << cpy_ptr.get()->n << std::endl;

    return 0;
}
