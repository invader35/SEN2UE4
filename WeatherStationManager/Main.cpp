///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 12-04-2013
// Description : WeatherStation Manager class
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <vld.h>
#include <iostream>
#include "WeatherStations.h"

using namespace std;

int main(){

    WeatherStation ws1 ("WS1", 18.3, 99);
    WeatherStation ws2 ("WS2", 6.3, 12);
    WeatherStation ws3 ("WS3", -17, 14);

    WeatherStations wsManager (3);

    cout << "Test Add" << endl;

    wsManager.Add(ws1) ? cout << "Neuanlage erfolgreich" << endl : cout << "Wetterstation nicht hinzugefuegt" << endl;
    wsManager.Add(ws2) ? cout << "Neuanlage erfolgreich" << endl : cout << "Wetterstation nicht hinzugefuegt" << endl;
    wsManager.Add(ws3) ? cout << "Neuanlage erfolgreich" << endl : cout << "Wetterstation nicht hinzugefuegt" << endl;
    wsManager.Add(ws1) ? cout << "Neuanlage erfolgreich" << endl : cout << "Wetterstation nicht hinzugefuegt" << endl;

    cout << "Test PrintAll" << endl;

    wsManager.PrintAll(cout);

    cout << "Test Getter" << endl;

    cout << "Should return 3: " << wsManager.GetNrStations() << endl;

    cout << "Test copy constr" << endl;

    WeatherStations wsManager1 (wsManager);

    cout << "Coldest of original: ";
    wsManager.PrintColdest(cout);

    cout << endl << "Coldest of copy: ";
    wsManager1.PrintColdest(cout);
    
    cout << endl << "Test Assignment operator" << endl;

    WeatherStations wsManager2 = wsManager;

    cout << "Warmest of original: ";
    wsManager.PrintWarmest(cout);

    cout << endl << "Warmest of copy: ";
    wsManager2.PrintWarmest(cout);

    cin.get();
    return 0;
}