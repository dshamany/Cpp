#include <string>

struct FlyBehavior
{
    virtual std::string fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
    std::string fly()
    {
        return "Flying...";
    }
};

class FlyWithoutWings : public FlyBehavior
{
    std::string fly()
    {
        return "Can't fly...I have no wings";
    }
};