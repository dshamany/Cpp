#ifndef VARIANT_HPP
#define VARIANT_HPP

#include <string>
#include <vector>
#include <map>

template <typename T>
class Variant
{
public:
    Variant() = delete;
    explicit Variant(const T &data) _data(data) {}
    void replaceValue(const T &data)
    {
        _data = data;
    }
    T value() { return _data; }

private:
    T _data;
};

#endif