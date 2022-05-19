//CSCI1300 Spring 2022
//Author: Martin Dax Roy & Noah Mamo
//Recitation: 103 - Rahul Kumar
//Project 3 

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Planet.h"
#include "Map.h"
using namespace std;

planet::planet() {
    srand(time(NULL));
    size = (1+rand()%16)/2;
    cap = size*.5*1000+rand()%1000;
    fuelNeeded = 50000;
    string name1 = "";
    string line;
    string arr[3125];
    ifstream fin("four_letter_words.txt");
    if(fin.fail()) {
        cout << "Planet name file not found" << endl;
    }
    int j = 0;
    while(getline(fin, line)) {
        arr[j] = line;
        j++;
    }
    for(int i = 0; i<6; i++) {
        int r = rand()%2+1;
        if(r == 1) {
            name1 += char(rand()%26+65);
        } else {
            name1 += to_string(rand()%10);
        }
    }
    name = name1 + "-" +arr[rand()%3125];
}

int planet::getSize() {
    return size;
}

string planet::getName() {
    return name;
}

int planet::getCap() {
    return cap;
}

int planet::getFuelForPlanet() {
    return fuelNeeded;
}

void planet::setFuelForPlanet(int fuel) {
    fuelNeeded = fuel*fuel/1000000+fuel;
}
