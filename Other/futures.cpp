#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;
typedef long int ull;

void findOdd(std::promise<ull> &&oddSumPromise, ull start, ull end)
{
    ull oddSum = 0;
    for (ull i = start; i <= end; ++i)
    {
        if (i % 2)
        {
            oddSum += 1;
        }
    }

    oddSumPromise.set_value(oddSum);
}

int main(int argc, char const *argv[])
{
    auto start_time = std::chrono::high_resolution_clock::now();
    ull start = 0, end = 1'900'000'000;
    std::promise<ull> oddSum;
    std::future<ull> oddFuture = oddSum.get_future();

    puts("Thread Created!");
    std::thread t1(findOdd, std::move(oddSum), start, end);

    puts("Waiting for result...");

    cout << "oddSum: " << oddFuture.get() << endl;

    puts("Completed!");
    t1.join();

    auto end_time = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count()
              << " seconds to complete.\n";
    return 0;
}
