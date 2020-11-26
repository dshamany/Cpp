#include <iostream>
#include <future>
#include <string>

void test(const std::string &str)
{
    std::cout << str << std::endl;
}

int main(int argc, char const *argv[])
{
    std::async(std::launch::async, test, "Test 1");
    std::async(std::launch::async, test, "Test 2");

    return 0;
}
