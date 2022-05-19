//CSCI1300 Spring 2022
//Author: Martin Dax Roy & Noah Mamo
//Recitation: 103 - Rahul Kumar
//Project 3



#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "Crew.h"
using namespace std;

crew::crew() {
    for(int i = 0; i<4; i++) {
        crews[i][0] = "";
        crews[i][1] = "";
    }
}

string crew::getName(int index) {
    return crews[index][0];
}

string crew::getPerk(int index) {
    return crews[index][1];
}

void crew::setName(int index, string name) {
    crews[index][0] = name;
}

void crew::setPerk(int index, string perk) {
    crews[index][1] = perk;
}
