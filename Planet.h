#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

class planet {
    int size;
    string name;
    int cap;
    bool inhabited;
    int fuelNeeded;
    string habitTraits[3];
    string inhabitTraits[3];
    public:
    planet();
    int getSize();
    string getName();
    int getCap();
    int getFuelForPlanet();
    void setFuelForPlanet(int);
};
#endif