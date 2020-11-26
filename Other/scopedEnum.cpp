#include <iostream>

enum class Object {
    square, oval=4, rectangle
};

enum class Faces {
    Good, Bad, oval
};

int main(int argc, char const *argv[]) {
    // std::cout << static_cast<int>(Object::oval) << "\n"
    //           << static_cast<int>(Faces::oval)  << std::endl;

    // This is how we can use them for switch statements
    auto s = Faces::oval; // use auto when possible
    switch (s) {
        case Faces::oval:
            std::cout << "Correct" << std::endl;
            break;
        default:
            std::cout << "Default" << std::endl;
    }

    return 0;
}
