#include <iostream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

int main(int argc, char const *argv[])
{
    auto uuid = boost::uuids::random_generator()();
    std::cout << uuid << '\n';
    return 0;
}
