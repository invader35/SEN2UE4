///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 12-04-2013
// Description : WeatherStation class
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <iostream>
#include "WeatherStation.h"

using namespace std;

int main(){

    WeatherStation ws1 ("Erste Wetterstation", 32.3, 28.3);

    ws1.Print(cout);

    cout << "Getter und Setter Test" << endl;
    cout << "Setting Name to Hans" << endl;
    ws1.SetName("Hans");
    cout << "GetName = " << ws1.GetName();
    cout << "Setting Temperature to 18.3C" << endl;
    ws1.SetCelsius(18.3);
    cout << "GetTemp = " << ws1.GetCelsius() << endl; 
    cout << "Setting Humidity to 78" << endl;
    ws1.SetCelsius(78);
    cout << "GetHumid = " << ws1.GetCelsius() << endl;

    cout << "Setting Temperature to 18.3F" << endl;
    ws1.SetFahrenheit(18.3);
    cout << "GetTemp in F = " << ws1.GetFahrenheit() << endl; 
    cout << "GetTemp in C = " << ws1.GetCelsius() << endl; 

    cin.get();
    return 0;
}