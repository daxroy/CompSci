#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "LogBook.h"
#include "Planet.h"
using namespace std;

logbook::logbook() {
    object = planet();
    pageNumber = 0;
    habitTraits.push_back("None");
    inhabitTraits.push_back("None");
    assess = "N/A";
}

planet logbook::getPlanet() {
    return object;
}

void logbook::setPlanet(planet p) {
    object = p;
}

int logbook::getPageNumber() {
    return pageNumber;
}

void logbook::setPageNumber(int p) {
    pageNumber = p;
}

void logbook::addHabitTrait(string t) {
    int size = habitTraits.size();
    for(int i = 0; i<size; i++) {
        if(habitTraits[i] == t) {
            return;
        }
    }
    if(habitTraits[0]== "None") {
        habitTraits.pop_back();
        habitTraits.push_back(t);
    } else {
        habitTraits.push_back(t);
    }
}

void logbook::addInhabitTrait(string t) {
    int size = inhabitTraits.size();
    for(int i = 0; i<size; i++) {
        if(inhabitTraits[i] == t) {
            return;
        }
    }
    if(inhabitTraits[0]== "None") {
        inhabitTraits.pop_back();
        inhabitTraits.push_back(t);
    } else {
        inhabitTraits.push_back(t);
    }
}

string logbook::getHabitTraits() {
    string traits = "";
    int size = habitTraits.size();
    for(int i = 0; i<size; i++) {
        if(i<habitTraits.size()-1) {
            traits += habitTraits[i] + ", ";
        } else {
            traits += habitTraits[i];
        }
    }
    return traits;
}

string logbook::getInhabitTraits() {
    string traits = "";
    for(int i = 0; i<inhabitTraits.size(); i++) {
        if(i<inhabitTraits.size()-1) {
            traits += inhabitTraits[i] + ", ";
        } else {
            traits += inhabitTraits[i];
        }
    }
    return traits;
}

string logbook::getAlienAssess() {
    return assess;  
}

void logbook::setAlienAssess(bool a) {
    if(a) {
        assess = "Habitable";
    } else {
        assess = "Inhabitable";
    }
}