#include <string>

#include "flyBehavior.hpp"
#include "quackBehavior.hpp"

class Duck
{
public:
    Duck(const std::string &type, const bool &doesFly = true, const char &sound = 'Q')
        : type(type)
    {
        setFly(doesFly);
        setQuack(sound);
        isFlying = false;
        isSwimming = false;
    }
    std::string swim()
    {
        if (isFlying)
        {
            return "...not swimming";
        }
        isSwimming = true;
        isFlying = false;
        return "Swimming...";
    }
    void setFly(const bool &doesFly = true)
    {
        if (doesFly)
        {
            fly = new FlyWithWings();
        }
        else
        {
            isFlying = false;
            fly = new FlyWithoutWings();
        }
    }
    void setQuack(const char &sound = 'Q')
    {
        if (sound == 'Q' || sound == 'q')
        {
            quack = new Quack();
        }
        else if (sound == 'M' || sound == 'm')
        {
            quack = new Muted();
        }
        else if (sound == 'S' || sound == 's')
        {
            quack = new Squeek();
        }
    }
    std::string performFly()
    {
        isFlying = true;
        isSwimming = false;
        return fly->fly();
    }
    std::string performQuack()
    {
        return quack->quack();
    }

private:
    FlyBehavior *fly = nullptr;
    QuackBehavior *quack = nullptr;
    bool isFlying;
    bool isSwimming;
    std::string type;
};