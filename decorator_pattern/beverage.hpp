#ifndef BEVERAGE_HPP
#define BEVERAGE_HPP

#include <string>

#include "item.hpp"

class Beverage : public Item
{
public:
    explicit Beverage() {}
    explicit Beverage(const std::string &desc, const float &price)
    {
        description(desc);
        cost(price);
    }
};

#endif //BEVERAGE_HPP