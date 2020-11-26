#include <iostream>
#include <chrono>
#include <thread>

class Timer
{
public:
    explicit Timer();
    explicit Timer(const int &, const int &, const int &);

    // Public Functions

    void increment();
    void decrement();

    // Getters
    int hour();
    int minute();
    int second();

    // Setters
    void hour(const int &);
    void minute(const int &);
    void second(const int &);

private:
    void increment_hours();
    void increment_minutes();
    void increment_seconds();

    void decrement_hours();
    void decrement_minutes();
    void decrement_seconds();

    int _hour;
    int _minute;
    int _second;
};