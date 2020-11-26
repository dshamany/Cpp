#include <iostream>

<<<<<<< HEAD
// Base Case
template <typename T>
double sum(T t){
    return t;
}

// Recursive Case
template <typename T, typename... Rest>
double sum(T t, Rest... rest){
    return t + sum(rest...);
}

int main(int argc, char const *argv[]) {
    auto x = sum(1.2, 2.3, 3.4, 5.5, 0.5, 0.1);
    std::cout << x << std::endl;
=======
// null case
void println() {}

// base case
template <typename T>
void println(T param)
{
    std::cout << param << '\n';
}

template <typename P1, typename... Args>
void println(P1 param, Args... args)
{
    println(param);
    println(args...);
}

int main(int argc, char const *argv[])
{
    println("Daniel", 4.3, 55.76898765f, 84, true, 'D');
>>>>>>> a09602e... First commit in a while
    return 0;
}
