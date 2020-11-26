#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

void print(const boost::system::error_code &ec,
           boost::asio::steady_timer *t, int *count)
{
    if (count < 5)
    {
        std::cout << *count << ' ';
        ++(*count);
    }
    else if (!ec)
        std::cout << "Hello, world!" << std::endl;
    else
        std::cerr << "Error Code: " << ec << std::endl;
}

int main(int argc, char const *argv[])
{
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
    t.

        io.run();
    return 0;
}
