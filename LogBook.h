//CSCI1300 Spring 2022
//Author: Martin Dax Roy, Noah Mamo
//Recitation: 103 - Rahul Kumar
//Project 3 

#ifndef LOGBOOK_H
#define LOGBOOK_H


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "Planet.h"
using namespace std;

class logbook {
    private:
    planet object;
    int pageNumber;
    vector<string> habitTraits;
    vector<string> inhabitTraits;
    string assess;
    public:
    logbook();
    planet getPlanet();
    void setPlanet(planet);
    int getPageNumber();
    void setPageNumber(int);
    void addHabitTrait(string);
    void addInhabitTrait(string);
    string getHabitTraits();
    string getInhabitTraits();
    string getAlienAssess();
    void setAlienAssess(bool);
};


#endif