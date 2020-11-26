#include <iostream>
#include <thread>

void foo(int n){
    std::cout << "Foo " << n << std::endl;
}

int main(int argc, char const *argv[]) {
    auto f = [](int n){
        return n;
    };

    std::thread to(foo, f(15));
    to.join();
    return 0;
}
