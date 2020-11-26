#include <iostream>
#include <vector>
#include <thread>

void print(const std::string &str)
{
    std::cout << "Printing string: " << str << std::endl;
}

void sequential(void f(const std::string &), std::vector<std::string> s)
{
    for (auto item : s)
    {
        f(item);
    }
}

void concurrent(void f(const std::string &), std::vector<std::string> s)
{
    for (auto item : s)
    {
        std::thread tmp(print, item);
        tmp.join();
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> s = {
        "Educative.blog",
        "Educative",
        "courses",
        "are great"};

    // std::vector<std::thread> threads;

    if (argc > 1)
    {
        std::string a = argv[1];
        if (a == "con")
            concurrent(print, s);
        else if (a == "seq")
            sequential(print, s);
    }
    else
    {
        std::cout << "provide con OR seq as an argument\n";
    }

    // for (auto &t : threads)
    // {
    //     t.join();
    // }
    return 0;
}
