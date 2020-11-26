#ifndef TYPES_HPP
#define TYPES_HPP

#include "variant.hpp"

class Number : public Variant<void>
{
public:
    Number(const double &number = 0.0)
        : _number(new Variant<double>(number)) {}
    Number *operator=(const Number &other)
    {
        _number = other._number;
    }

private:
    Variant<double> *_number;
};

#endif // TYPES_HPP