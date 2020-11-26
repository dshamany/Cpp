#include <iostream>

class Singleton
{
public:
    Singleton(Singleton &s) = delete;
    static Singleton &Get()
    {
        return s_instance;
    }
    friend std::ostream &operator<<(std::ostream &os, const Singleton &s)
    {
        os << s.Get().fn;
        return os;
    }

private:
    Singleton(){};
    static Singleton s_instance;
    float fn = 0.1234f;
};

Singleton Singleton::s_instance;

int main(int argc, char const *argv[])
{
    Singleton::Get();

    std::cout << Singleton::Get() << '\n';
    std::cin.ignore();
    return 0;
}
