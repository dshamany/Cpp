#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <string>

class Pizza
{
public:
    Pizza() : _desc("New Pizza"), _cost(0.00f) {}
    Pizza(const std::string &desc, const float &cost = 0.00f)
        : _desc(desc), _cost(cost) {}
    const std::string description() const { return _desc; }
    const float cost() const { return _cost; }
    void set(const std::string &desc, const float &cost)
    {
        _desc = desc;
        _cost = cost;
    }

private:
    std::string _desc;
    float _cost;
};

#endif