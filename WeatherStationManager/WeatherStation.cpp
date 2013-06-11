///////////////////////////////////////
// Workfile    : WeatherStation.cpp
// Author      : Matthias Schett
// Date        : 12-04-2013
// Description : WeatherStation class
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include "WeatherStation.h"
using namespace std;

double const convertFactor = 1.8;
size_t const convertConstant = 32;

WeatherStation::WeatherStation(string const &name, double celsius, double humidity) : mName(name), mCelsius(celsius), mHumidity(humidity){
}

// Accessor methods
std::string const &WeatherStation::GetName() const{
    return mName;
}

void WeatherStation::SetName(std::string const &name){
    mName = name;
}

double WeatherStation::GetCelsius() const{
    return mCelsius;
}

void WeatherStation::SetCelsius(double c){
    mCelsius = c;
}

double WeatherStation::GetFahrenheit() const{
    // TF = TC * 1.8 + 32
    return (mCelsius * convertFactor + convertConstant);
}

void WeatherStation::SetFahrenheit(double f){
    // TC = (TF - 32) / 1.8
    mCelsius = (f - 32) / 1.8;
}

double WeatherStation::GetHumidity() const{
    return mHumidity;
}

void WeatherStation::SetHumidity(double h){
    mHumidity = h;
}


// Print the data of the weather station (Name, C,F, humidity)
void WeatherStation::Print(std::ostream &out) const{
    out << "Name: " << GetName() << " Temperatur: " << GetCelsius() << " Luftfeuchtigkeit: " << GetHumidity() << endl;
}