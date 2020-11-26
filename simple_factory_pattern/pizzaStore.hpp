#ifndef PIZZASTORE_HPP
#define PIZZASTORE_HPP

#include <string>

class PizzaStore
{
public:
    explicit PizzaStore(const std::string &description)
        : _description(description) {}

private:
    std::string _description;
};

#endif //PIZZASTORE_HPP