#include <iostream>

void hello_world(void(*callback)()){
    std::cout << "Hello, World!" << std::endl;
    callback();
}

int main(int argc, char const *argv[])
{
    hello_world([](){
        hello_world([](){
            puts("I am a lambda inside a lambda");
        });
    });
    return 0;
}
