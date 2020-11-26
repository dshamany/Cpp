#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<int> replaceElements(vector<int> &arr)
{
    int max = 0;
    int count = 0;

    for (auto &n : arr)
    {
        max = 0;
        for (auto it = arr.rbegin(); it != arr.rend() - count - 1; it++)
        {
            if (*it > max)
                max = *it;
        }
        n = max;
        count++;
    }
    arr[arr.size() - 1] = -1;

    return arr;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {17, 18, 5, 4, 6, 1};

    for (auto &n : replaceElements(arr))
    {
        cout << n << ' ';
    }
    puts("");

    return 0;
}
