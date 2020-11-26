#include <iostream>
#include <string>

void selection(const std::string arg){
    if (arg == "Test" || arg == "test") {
        std::cout << "Test Succeeded!" << std::endl;
        return;
    }
    else if (arg == "add") {
        system("touch /home/Journal/Today.txt");
        system("vim /home/Journal/Today.txt");
    }
    else if (arg == "ls" || arg == "list") {
        system("ls /home/Journal");
    }
    else
    {
        std::cout << "Not a valid entry";
    }
}

int main(int argc, char *argv[])
{
    if (argc > 0)
        selection(argv[1]);
    return 0;
}
