#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
public:
    virtual const std::string description() const;
    virtual void description(const std::string &);
    virtual float cost() const;
    virtual void cost(const float &cost);

private:
    std::string _desc;
    float _cost;
};

const std::string Item::description() const
{
    return _desc;
}

void Item::description(const std::string &description)
{
    _desc = description;
}

float Item::cost() const
{
    return _cost;
}

void Item::cost(const float &cost)
{
    _cost = cost;
}

#endif