#include <iostream>
#include <iterator>
#include <vector>
#include <boost/filesystem.hpp>
#include <fstream>

using fs = boost::filesystem;

void read_dir(int argc, char* argv[]){
    fs::path p(argc > 1 ? argv[1] : ".");
    std::vector<fs::directory_entry> v;

    if (is_directory(p)){
        copy(directory_iterator(p), directory_iterator(), back_inserter(v));
        std::cout << p << " contains:\n";
        for (const auto& t : v){
            std::cout << t.path().string() << std::endl;
        }
    }
}

void create_dir(){
    const auto dir_name = "Test_Directory";
    fs::path pp(dir_name);
    try {
        if (create_directory(pp)){
            rename(pp, dir_name);
        }
    } catch (fs::filesystem_error& e){
        std::__1::cerr << e.what() << "\n";
    }
}

void write_file(){
    fs::path fpath{"test.txt"};
    fs::ofstream ofs{fpath};
    ofs << "Hello, There!\n";
}

int main(int argc, char *argv[]) {
    read_dir(argc, argv);
    create_dir();
    write_file();
    return 0;
}
