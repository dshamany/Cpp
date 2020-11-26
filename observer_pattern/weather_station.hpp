#ifndef WEATHER_STATION_HPP
#define WEATHER_STATION_HPP

#include "subject.hpp"

class WeatherStation : public Subject
{
public:
    WeatherStation() : temperature(0), pressure(0), windSpeed(0) {}
    void setTemperature(const int &);
    int getTemperature();
    void setPressure(const int &);
    int getPressure();
    void setWindSpeed(const int &);
    int getWindSpeed();

private:
    int temperature;
    int pressure;
    int windSpeed;
};

void WeatherStation::setTemperature(const int &temp)
{
    temperature = temp;
    notifyObservers("Temperature Changed.");
}

int WeatherStation::getTemperature()
{
    return temperature;
}

void WeatherStation::setPressure(const int &press)
{
    pressure = press;
    notifyObservers("Pressure Changed.");
}

int WeatherStation::getPressure()
{
    return pressure;
}

void WeatherStation::setWindSpeed(const int &speed)
{
    windSpeed = speed;
    notifyObservers("Wind Speed Changed.");
}

int WeatherStation::getWindSpeed()
{
    return windSpeed;
}

#endif // WEATHER_STATION_HPP