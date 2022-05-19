//CSCI1300 Spring 2022
//Author: Martin Dax Roy & Noah Mamo
//Recitation: 103 - Rahul Kumar
//Project 3
#ifndef CREW_H
#define CREW_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

class crew {
    private:
    string crews[4][2];
    public:
    crew();
    string getName(int);
    string getPerk(int);
    void setName(int, string);
    void setPerk(int, string);
};
#endif