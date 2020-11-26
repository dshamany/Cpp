#include <iostream>
#include <cassert>
using namespace std;

int gcd(int a, int b){
    while(true){
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int generalizedGCD(int num, int* arr)
{
    int result = arr[0];
    for (int i = 1; i < num; ++i)
        result = gcd(arr[i], result);

    return result;
}

int main(int argc, char const *argv[]) {
    unsigned int num = 5;
    int arr[num] = {24, 48, 64, 96};

    cout << generalizedGCD(num, arr) << endl;

    return 0;
}
