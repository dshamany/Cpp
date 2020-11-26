#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <vector>
#include <map>
#include <string>
#include <iostream>

class Document
{
public:
    explicit Document() : _links({}), _info({}) {}
    explicit Document(const std::string &key, const std::string &value)
    {
        _info[key] = value;
    }
    void setInfo(const std::string &key, const std::string &value)
    {
        _info[key] = value;
    }
    std::string getInfo(const std::string &key)
    {
        return _info[key];
    }
    std::map<std::string, std::string> getAllInfo()
    {
        return _info;
    }
    void setLink(const std::string &title, Document *document)
    {
        _links[title] = document;
    }
    Document *getLink(const std::string &title)
    {
        return _links[title];
    }
    std::map<std::string, Document *> getAllLinks()
    {
        return _links;
    }

private:
    std::map<std::string, Document *> _links;
    std::map<std::string, std::string> _info;
};

#endif //DOCUMENT_HPP