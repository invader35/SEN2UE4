///////////////////////////////////////
// Workfile    : WeatherStation.h
// Author      : Matthias Schett
// Date        : 12-04-2013
// Description : WeatherStation class
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <string>
#include <iostream>

class WeatherStation{

private:
    std::string mName; // Name of the weather station
    double mCelsius; // Temperature in degree Celsius
    double mHumidity; // Humidity in percent

public:
    // Constructor
    WeatherStation(std::string const &name="", double celsius=0, double humidity=0);

    // Accessor methods
    std::string const &GetName() const;
    void SetName(std::string const &name);
    double GetCelsius() const;
    void SetCelsius(double c);
    double GetFahrenheit() const;
    void SetFahrenheit(double f);
    double GetHumidity() const;
    void SetHumidity(double h);
    // Print the data of the weather station (Name, C,F, humidity)
    void Print(std::ostream &out) const;
};

inline std::ostream &operator << (std::ostream &out, WeatherStation & ws){
    ws.Print(out);
    return out;
}