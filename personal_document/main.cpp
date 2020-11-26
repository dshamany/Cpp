#include <iostream>

#include "document.hpp"

int main(int argc, char const *argv[])
{
    Document *doc = new Document();
    doc->setInfo("FullName", "Daniel Latrell George Shamany");
    doc->setInfo("BirthDay", "02-10-1989");

    Document *health = new Document();
    health->setInfo("Liver", "Great");
    health->setInfo("Kidney", "Fucked!");

    doc->setLink("Health", health);

    Document *academics = new Document();
    academics->setInfo("CSUN", "B.S. Business Management");
    academics->setInfo("SMC", "A.A. Business Management");

    doc->setLink("Academics", academics);

    puts("DETAILS:");
    for (auto &i : doc->getAllInfo())
    {
        std::cout << i.first << ":\t" << i.second << '\n';
    }
    puts("\nLINKS:");
    for (auto &l : doc->getAllLinks())
    {
        std::cout << "- " << l.first << '\n';

        for (auto &li : l.second->getAllInfo())
        {
            std::cout << "\t\t" << li.first << " -> " << li.second << '\n';
        }
    }
    return 0;
}
