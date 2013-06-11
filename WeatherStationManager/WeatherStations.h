///////////////////////////////////////
// Workfile    : WeatherStations.h
// Author      : Matthias Schett
// Date        : 12-04-2013
// Description : WeatherStation Manager class
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include "WeatherStation.h"
#include <iostream>
#include <exception>

class WeatherException : public std::exception
{
public:
    WeatherException(const char* errMessage):errMessage_(errMessage){}
    // overriden what() method from exception class
    const char* what() const throw() { return errMessage_; }

private:
    const char* errMessage_;
};

class WeatherStations {

private:

    // member variables
    WeatherStation *mStationArray;
    size_t mNumberOfStations;
    size_t mMaxNumber;

    // private helper methods
    // Search for the coldes station
    WeatherStation & searchForColdest() const throw(WeatherException&);
    // Search for the warnest station
    WeatherStation & searchForWarmest() const throw(WeatherException&);

public:
    // Constructor
    WeatherStations(size_t maxNr=10);

    // Copy constructor
    WeatherStations(WeatherStations const &ws);

    // Destructor
    ~WeatherStations();

    // Assignment operator
    WeatherStations &operator =(WeatherStations const &ws);

    // Adds a new weather station at the end (if possible)
    bool Add(WeatherStation const &ws);

    // Returns the number of weather stations
    size_t GetNrStations() const;

    // Prints all weather stations
    void PrintAll(std::ostream &out) const;

    // Prints coldest/warmest weather station
    void PrintColdest(std::ostream &out) const;
    void PrintWarmest(std::ostream &out) const;

};