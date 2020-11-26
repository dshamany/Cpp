#include <iostream>

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

int main(int argc, char const *argv[])
{
    boost::system::error_code ec;

    // create context for asio to have memory to work with
    boost::asio::io_context context;

    // get address of a desired connection (e.g. endpoint)
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("93.184.216.34", ec), 80);

    // create a socket for receiving implementation from context
    // this is an abstraction to use the platform networking tools
    boost::asio::ip::tcp::socket socket(context);

    // connect through socket to endpont parameter
    socket.connect(endpoint, ec);

    if (!ec)
    {
        puts("Connected");
    }
    else
    {
        std::cout << ec.message() << std::endl;
    }

    return 0;
}
