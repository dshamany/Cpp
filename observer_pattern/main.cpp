#include <iostream>

#include "weather_station.hpp"
#include "ui.hpp"
#include "logger.hpp"

int main(int argc, char const *argv[])
{
    WeatherStation *ws = new WeatherStation();

    auto logger = new Logger();
    ws->registerObserver(logger);
    puts("");

    ws->setPressure(1);
    ws->setTemperature(72);
    ws->setWindSpeed(5);
    puts("");

    logger->update();
    puts("");

    auto ui = new UI();
    ws->registerObserver(ui);
    puts("");

    ws->setTemperature(112);

    logger->update();

    ws->removeObserver(logger);

    ws->setPressure(12);

    logger->update();

    for (int i = 0; i < logger->log_count(); i++)
    {
        std::cout << logger->getLog(i).second << '\n';
    }

    return 0;
}
