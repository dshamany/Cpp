#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "Timer.h"

using namespace std::chrono_literals;

void printTime(void(cb)())
{

    Timer *t = new Timer(0, 0, 0);

    while (true)
    {
        auto sHr = (t->hour() < 10) ? "0" + std::to_string(t->hour()) : std::to_string(t->hour());
        auto sMn = (t->minute() < 10) ? "0" + std::to_string(t->minute()) : std::to_string(t->minute());
        auto sSc = (t->second() < 10) ? "0" + std::to_string(t->second()) : std::to_string(t->second());

        system("clear");
        std::cout << sHr << ':' << sMn << ':' << sSc << "\n";
        cb();

        std::this_thread::sleep_for(1s);
        t->increment();
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1{printTime, []() {
                       std::cout << "newLine\n";
                   }};

    t1.join();

    puts("");
    return 0;
}
