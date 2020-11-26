#include "turkey.hpp"
#include "duck.hpp"
#include "chicken.hpp"

struct Turkey_Adapter : public Duck
{
public:
    Turkey_Adapter(Turkey *turkey)
        : _turkey(turkey) {}
    void set_turkey(Turkey *turkey)
    {
        _turkey = turkey;
    }
    std::string swim()
    {
        return "I don't swim...";
    }
    std::string performFly()
    {
        return _turkey->fly();
    }
    std::string performQuack()
    {
        return _turkey->gobble();
    }

private:
    Turkey *_turkey;
};

struct Chicken_Adapter : public Duck
{
public:
    Chicken_Adapter(Chicken *chicken)
        : _chicken(chicken) {}
    std::string swim()
    {
        return "Chickens don't swim...";
    }
    std::string performFly()
    {
        return "Chickens don't fly...";
    }
    std::string performQuack()
    {
        return _chicken->sound();
    }

private:
    Chicken *_chicken;
};