#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

int main(int argc, char const *argv[])
{
    boost::system::error_code ec;

    // create context for asio to have memory to work with
    boost::asio::io_context context;

    // create resolver to convert address to ip address string
    std::string host = argc > 1 ? argv[1] : "www.duckduckgo.com";
    std::string port = "80";

    boost::asio::io_service service;

    boost::asio::ip::tcp::resolver::query resolver_query(host, port, boost::asio::ip::tcp::resolver::query::numeric_service);

    // create resolver
    boost::asio::ip::tcp::resolver resolver(service);

    // create iterator
    auto it = resolver.resolve(resolver_query, ec);

    // this stores the last ip address.
    std::stringstream ss;

    // print all endpoints if they exists
    if (ec)
    {
        puts("Failed to resolve DNS name");
        std::cout << "error code: " << ec.value() << "\nmsg: " << ec.message() << '\n';
        return -2;
    }
    else
    {
        for (auto &ep : it)
        {
            ss << ep.endpoint() << std::endl;
        }
    }

    // set host and port
    host = ss.str().substr(0, ss.str().rfind(':'));
    port = ss.str().substr(ss.str().rfind(':') + 1, ss.str().size() - 1);

    // remove the new line that follows the port number
    port.pop_back();

    std::cout << "Connecting to " << host << ':' << port << '\n';

    // get address of a desired connection (e.g. endpoint)
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address(host, ec), stoi(port));

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

    if (socket.is_open())
    {
        std::string hostname = argv[1] ? argv[1] : "www.duckduckgo.com";
        std::string endpoint_addition = argv[2] ? argv[2] : "index.html";
        // create string request
        std::string sReq = "GET /" + endpoint_addition + " HTTP/1.1\r\n"
                                                         "Host: " +
                           hostname.substr(3, hostname.size() - 1) + " \r\n"
                                                                     "Connection: close\r\n\r\n";

        // add request to socket
        socket.write_some(boost::asio::buffer(sReq.data(), sReq.size()), ec);

        // add delay to view content due to server proximity
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1000ms);

        // check if data is received
        size_t bytes = socket.available();
        std::cout << "bytes available: " << bytes << '\n';

        // handle data if available
        if (bytes > 0)
        {
            std::vector<char> vBuffer(bytes);
            socket.read_some(boost::asio::buffer(vBuffer.data(), vBuffer.size()), ec);

            // print content to console
            for (auto &c : vBuffer)
            {
                std::cout << c;
            }
        }
    }

    return 0;
}