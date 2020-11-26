#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char const *argv[])
{
    try
    {
        boost::asio::io_service;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
