#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <vector>

#include "observer.hpp"

class Subject
{
public:
    Subject() {}
    void registerObserver(Observer *);
    void removeObserver(Observer *);
    void notifyObservers(const std::string &);

private:
    std::vector<Observer *> observers;
};

void Subject::registerObserver(Observer *observer)
{
    observer->setId(observers.size());
    observers.push_back(observer);
    observer->update("Observer Registered.");
}

void Subject::removeObserver(Observer *observer)
{
    auto begin = observers.begin() + (observer->getId());
    observers.erase(begin, begin + 1);
    observer->update("Observer Removed.");
}

void Subject::notifyObservers(const std::string &msg = "")
{
    if (observers.size())
    {
        for (auto &obs : observers)
        {
            obs->update(msg);
        }
    }
}

#endif // SUBJECT_HPP