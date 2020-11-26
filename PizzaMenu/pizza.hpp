#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <string>

class Pizza
{
public:
    explicit Pizza(const std::string &, const float &);
    void description(const std::string &);
    void cost(const float &);
    const std::string description() const;
    const float cost() const;
    void set(const std::string &, const float &);

private:
    std::string _desc;
    float _cost;
};

Pizza::Pizza(const std::string &desc = "unknown pizza", const float &cost = 0.00f)
    : _desc(desc), _cost(cost) {}

void Pizza::description(const std::string &desc)
{
    this->_desc = desc;
}

void Pizza::cost(const float &price)
{
    this->_cost = price;
}

const std::string Pizza::description() const
{
    return this->_desc;
}

const float Pizza::cost() const
{
    return this->_cost;
}

void Pizza::set(const std::string &desc, cons float &cost)
{
    _desc = desc;
    _cost = cost;
}

#endif //PIZZA_HPP