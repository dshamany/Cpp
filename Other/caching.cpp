#include <iostream>
#include <vector>

std::vector<int> vec;
std::vector<int> cache = {-1, -1, -1, -1, -1};

void insert(const int &num)
{
    vec.push_back(num);

    for (auto &e : cache)
    {
        if (e < 0)
        {
            e = num;
        }
    }
}

int get(const int &num)
{
    for (auto &e : cache)
    {
        if (e == num)
        {
            puts("returned from cache");
            std::swap(cache[0], e);
            return cache[0];
        }
    }

    for (auto &e : vec)
    {
        if (e == num)
        {
            cache[4] = e;
            return e;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    insert(5);
    insert(12);
    insert(34);
    insert(43);
    insert(17);
    insert(36);
    insert(45);
    insert(11);

    int n;

    while (true)
    {
        cout << "choose number: ";
        cin >> n;
        std::cout << get(n) << '\n';
    }

    return 0;
}
