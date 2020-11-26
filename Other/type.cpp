#include <iostream>
#include <ctime>
#include <chrono>

int main(int argc, char const *argv[]) {

    std::string text = "";
    std::string word = "";
    int word_count = 0;

    auto start  = time(0);
    auto end    = time(0);
    while (word != "-"){
        std::cin >> word;
        word_count++;
        text += " " + word;
        end = time(0);
    }
    double wpm = ((word_count)/(end - start) * 60);
    std::cout << "Words per Minute: " << wpm << std::endl;
    std::cout << text << std::endl;

    return 0;
}
