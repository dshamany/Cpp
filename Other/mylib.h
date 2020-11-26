#include <iostream>

class MyObject
{
public:
    MyObject();
    ~MyObject();
    MyObject(const int &n);
    MyObject(const MyObject &obj);
    int value();
    friend std::ostream &operator<<(std::ostream &os, const MyObject &obj);

private:
    int _n;
};