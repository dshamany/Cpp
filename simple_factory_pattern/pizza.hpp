#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <string>

class Pizza
{
public:
    Pizza() {}
    Pizza(const std::string &type)
        : _type(type) {}
    std::string description()
    {
        return _type;
    }

private:
    std::string _type;
};

#endif //PIZZA_HPP