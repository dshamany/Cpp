#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include <string>

class Chicken
{
public:
    Chicken() {}
    std::string sound()
    {
        return "Baak baak";
    }
};

#endif // CHICKEN_HPP