#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Please provide one argument in Milliseconds.\n";
        return 0;
    }

    auto milli_value = atoi(argv[1]);
    std::cout << milli_value << '\n';
    std::chrono::duration<int, std::milli> timespan(milli_value);
    std::this_thread::sleep_for(timespan);
    std::cout << "Done!\n";
    return 0;
}
