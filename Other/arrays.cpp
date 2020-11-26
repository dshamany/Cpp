#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    for (auto &n : vec)
    {
        cout << n << ' ';
    }
    puts("");

    // INSERT
    vec.resize(11);

    int pos = 0;

    while (vec[pos] <= 5 && pos < vec.size())
    {
        pos++;
    }

    int end = vec.size() - 1;
    while (end > pos && end > 0)
    {
        vec[end] = vec[end - 1];
        end--;
    }

    vec[end] = 100;

    for (auto &n : vec)
    {
        cout << n << ' ';
    }
    puts("");

    // DELETE
    int del_pos = 5;

    while (del_pos != vec.size())
    {
        vec[del_pos] = vec[del_pos + 1];
        del_pos++;
    }

    vec.resize(10);

    for (auto &n : vec)
    {
        cout << n << ' ';
    }
    puts("");

    return 0;
}
