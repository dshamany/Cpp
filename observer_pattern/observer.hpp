#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

class Observer
{
public:
    Observer() : _id(-1), _msg("") {}
    Observer(const int &id) : _id(id), _msg("") {}
    void setId(const int &id)
    {
        _id = id;
    }
    int getId()
    {
        return _id;
    }
    const std::string getMsg()
    {
        return _msg;
    }
    virtual void update(const std::string &msg = "")
    {
        _msg = msg;
    }

private:
    int _id;
    std::string _msg;
};

#endif // OBSERVER_HPP