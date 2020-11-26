#include <string>

struct QuackBehavior
{
    virtual std::string quack() = 0;
};

struct Quack : QuackBehavior
{
    std::string quack()
    {
        return "Quack quack...";
    }
};

struct Muted : QuackBehavior
{
    std::string quack()
    {
        return "[muted]";
    }
};

struct Squeek : QuackBehavior
{
    std::string quack()
    {
        return "Squeek squeek...";
    }
};