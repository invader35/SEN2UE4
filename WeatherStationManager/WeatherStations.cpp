///////////////////////////////////////
// Workfile    : WeatherStations.cpp
// Author      : Matthias Schett
// Date        : 12-04-2013
// Description : WeatherStation Manager class
// Remarks     : -
// Revision    : 0
///////////////////////////////////////
#include "WeatherStations.h"


// Constructor
WeatherStations::WeatherStations(size_t maxNr) : mMaxNumber(maxNr), mNumberOfStations(0), mStationArray(new WeatherStation[maxNr]){
}

// Copy constructor
WeatherStations::WeatherStations(WeatherStations const &ws){
    mNumberOfStations = ws.GetNrStations();
    mMaxNumber = ws.mMaxNumber;
    mStationArray = new WeatherStation[mMaxNumber];
    for(size_t i = 0; i < mNumberOfStations; i++){
        mStationArray[i] = ws.mStationArray[i];
    }
}

// Destructor
WeatherStations::~WeatherStations(){
    delete [] mStationArray;
    mStationArray = 0;
}

// Assignment operator
WeatherStations &WeatherStations::operator =(WeatherStations const &ws){
    mStationArray = ws.mStationArray;
    mMaxNumber = ws.mMaxNumber;
    mNumberOfStations = ws.GetNrStations();

    return *this;
}

// Adds a new weather station at the end (if possible)
bool WeatherStations::Add(WeatherStation const &ws){
    if(mNumberOfStations < mMaxNumber){
        mStationArray[mNumberOfStations] = ws;
        ++mNumberOfStations;
        return true;
    }
    return false;
}

// Returns the number of weather stations
size_t WeatherStations::GetNrStations() const{
    return mNumberOfStations;
}

// Prints all weather stations
void WeatherStations::PrintAll(std::ostream &out) const{
    for(size_t i = 0; i < mNumberOfStations; i++){
        mStationArray[i].Print(out);
    }
}

// Prints coldest/warmest weather station
void WeatherStations::PrintColdest(std::ostream &out) const{
    try{
        searchForColdest().Print(out);
    } catch(WeatherException& e){
        std::cout << e.what() << std::endl;
    }
}
void WeatherStations::PrintWarmest(std::ostream &out) const{
    try{
        searchForWarmest().Print(out);
    } catch(WeatherException& e){
        std::cout << e.what() << std::endl;
    }
}

WeatherStation & WeatherStations::searchForColdest() const{
    double temperature;
    size_t pos = 0;

    if(mNumberOfStations > 0){
        temperature = mStationArray[0].GetCelsius();
        for(size_t i = 1; i < mNumberOfStations; i++){
            if(temperature > mStationArray[i].GetCelsius()){
                temperature = mStationArray[i].GetCelsius();
                pos = i;
            }
        }
        return mStationArray[pos];
    } else {
        throw WeatherException("No station are defined");
    }
}

WeatherStation & WeatherStations::searchForWarmest() const{
    double temperature;
    size_t pos = 0;
    
    if(mNumberOfStations > 0){
        temperature = mStationArray[0].GetCelsius();
        for(size_t i = 1; i < mNumberOfStations; i++){
            if(temperature < mStationArray[i].GetCelsius()){
                temperature = mStationArray[i].GetCelsius();
                pos = i;
            }
        }
        return mStationArray[pos];
    } else {
        throw WeatherException("No station are defined");
    }
}