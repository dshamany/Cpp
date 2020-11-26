#include "Timer.h"

Timer::Timer()
    : _hour(0), _minute(0), _second(0) {}

Timer::Timer(const int &hour = 0, const int &minute = 0, const int &second = 0)
    : _hour(hour), _minute(minute), _second(second) {}

// Public Functions

void Timer::increment()
{
    increment_seconds();
}

void Timer::decrement()
{
    decrement_seconds();
}

// Getters

int Timer::hour()
{
    return _hour;
}

int Timer::minute()
{
    return _minute;
}

int Timer::second()
{
    return _second;
}

// Setters

void Timer::hour(const int &hour)
{
    _hour = hour;
}

void Timer::minute(const int &minute)
{
    _minute = minute;
}

void Timer::second(const int &second)
{
    _second = second;
}

// Private Functions for internal use

void Timer::increment_hours()
{
    if (_hour == 23)
    {
        _hour == 0;
    }
    else
    {
        _hour++;
    }
}

void Timer::increment_minutes()
{
    if (_minute == 59)
    {
        increment_hours();
        _minute = 0;
    }
    else
    {
        _minute++;
    }
}

void Timer::increment_seconds()
{
    if (_second == 59)
    {
        increment_minutes();
        _second = 0;
    }
    else
    {
        _second++;
    }
}

void Timer::decrement_hours()
{
    if (_hour == 0)
    {
        _hour = 23;
    }
    else
    {
        _hour--;
    }
}

void Timer::decrement_minutes()
{
    if (_minute == 0)
    {
        decrement_hours();
        _minute = 59;
    }
    else
    {
        _minute--;
    }
}

void Timer::decrement_seconds()
{
    if (_second == 0)
    {
        decrement_minutes();
        _second = 59;
    }
    else
    {
        _second--;
    }
}