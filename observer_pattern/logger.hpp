#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <vector>
#include <string>

#include "observer.hpp"

class Logger : public Observer
{
public:
    Logger() : log({}) {}
    void append(const int &id, const std::string &info);
    const std::pair<int, std::string> getLog(const int &from_id);
    int autoId();
    int log_count();
    void update(const std::string &msg);

private:
    std::vector<std::pair<int, std::string>> log;
};

void Logger::append(const int &id, const std::string &info)
{
    std::pair<int, std::string> tmp({id, info});
    log.push_back(tmp);
}

const std::pair<int, std::string> Logger::getLog(const int &from_id)
{
    for (auto &l : log)
    {
        if (l.first == from_id)
        {
            std::pair<int, std::string> tmp = {l.first, l.second};
            return tmp;
        }
    }
    return {};
}

int Logger::autoId()
{
    return log.size();
}

void Logger::update(const std::string &msg = "")
{
    append(autoId(), msg);
}

int Logger::log_count()
{
    return log.size();
}

#endif // LOGGER_HPP