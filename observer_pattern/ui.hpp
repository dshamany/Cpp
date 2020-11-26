#ifndef UI_HPP
#define UI_HPP

#include <iostream>

#include "observer.hpp"

class UI : public Observer
{
public:
    UI() {}
    void display(const int &temp, const int &press, const int &windSpeed)
    {
        std::cout << "Temperature:\t" << temp << '\n'
                  << "Pressure:\t" << press << '\n'
                  << "WindSpeed:\t" << windSpeed << '\n';
    }
    void update(const std::string &msg)
    {
        std::cout << msg << '\n';
    }
};

#endif // UI_HPP