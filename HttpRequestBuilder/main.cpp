#include <iostream>
#include "HttpRequestBuilder.hpp"
#include "example.hpp"

void printRequest(HttpRequestBuilder *builder)
{
    std::string add_to_path = "/";
    if (builder->params().size())
    {
        int n = 0;
        for (auto p = builder->params().begin(); p != builder->params().end(); ++p, ++n)
        {
            add_to_path += p->first + "=" + p->second + "&";
        }
        builder->path(add_to_path);
    }
    std::cout << builder->method() << ' ' << builder->path() << ' ' << builder->httpVersion() << '\n';
    for (auto &h : builder->headers())
    {
        std::cout << h.first << ": " << h.second << '\n';
    }
    std::cout << "Host: " << builder->host() << '\n';
    builder->method() != "GET" && std::cout << "Body:" << builder->body() << '\n';
}

int main(int argc, char const *argv[])
{
    // auto builder = new HttpRequestBuilder();
    // builder->method("POST");
    // builder->host("www.duck.com");
    // builder->httpVersion("HTTP/2");
    // builder->query("Test");

    // builder->headers({{"Content-Type", "application/json"},
    //                   {"Accept", "application/json"}});
    // builder->body("{\"Success\":\"OK\"}");
    // builder->params({{"q", "test"}});

    // printRequest(builder);

    Image *img = new Image();
    std::cout << img->get_alignment() << '\n';

    return 0;
}
