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
#include <cstdlib>
#include "User.h"
using namespace std;

User::User() {
    name = "";
    health = 100;
    money = 100000;
    fuel  = 200000;
    suitGrade =1;
    numPlanetsExplored = 0;
    numSaved = 0;
    numLost = 0;
    popLeft = 8000;
    
 
    weapon[0][0] = "Light Saber";
    weapon[0][1]  ="1";
    weapon[1][0] = "Blaster";
    weapon[1][1]  ="0";
    weapon[2][0] = "Beam gun";
    weapon[2][1]  ="0";



    for(int i =0; i < 2; i++){
        crew[i] = 0;
    }
    suitHealth =  100; // The suits condition
	healthKits = 0; // healing kit for health 
	translator = false;  // alien communicaiton
                         
}

string User::getName() {
    return name;
}
void User::setName(string uname) {
    name = uname;
}

int User::getHealth() {
    return health;
}
void User::setHealth(int hl) {
    if(hl>100) {
        health = 100;
    } else if (hl<0) {
        health = 0;
    } else {
    health = hl;
    }
}

int User::getHealthKits() {
    return healthKits;
}

void User::setHealthKits(int num) {
    healthKits = num;
}

int User::getSuitHealth() {
    return suitHealth;
}

void User::setSuitHealth(int h) {
    suitHealth = h;
}

int User::getMoney() {
    return money;
}

void User::setMoney(int mn) {
    money = mn;
}

int User::getFuel() {
    return fuel;
}

void User::setFuel(int fu) {
    fuel = fu;
}
int User::getSuitGrade() {
    return suitGrade;
}

void User::setSuitGrade(int grade) {
    suitGrade = grade+1;
}
int User::getWeapon(int type) {
    int values;
    if (type == 3){
        int saber = stoi(weapon[0][1]);
        int blaster = stoi(weapon[1][1]);
        int beam = stoi(weapon[2][1]);
        values = saber+blaster+beam; //weapon <2
    }
    else{
        values = stoi(weapon[type][1]); 
    }
    return values;
}

void User::setWeapon(int type, string amount) {
    int inventory = getWeapon(type);
    weapon[type][1] =  to_string((stoi(amount)+inventory));
}

int User::getCrew(int type) {
    int ph = crew[type];
    return ph;
}
void User::setCrew(int type, int amount){
    crew[type] = amount;
}

bool User::getTranslator() {
    return translator;
}

void User::setTranslator(bool n) {
    translator = n;
}

int User::getNumExplored() {
    return numPlanetsExplored;
}

void User::setNumExplored(int num) {
    numPlanetsExplored = num;
}

int User::getNumSaved() {
    return numSaved;
}

void User::setNumSaved(int num) {
    numSaved = num;
}

int User::getNumLost() {
    return numLost;
}

void User::setNumLost(int num) {
    numLost = num;
}

int User::getRepHabit() {
    return numRepHabit;
}

void User::setRepHabit(int num) {
    numRepHabit = num;
}

int User::getRepInhabit() {
    return numRepInhabit;
}

void User::setRepInhabit(int num) {
    numRepInhabit = num;
}

int User::getPopLeft() {
    return popLeft;
}

void User::setPopLeft(int num) {
    if(popLeft-num<0) {
        popLeft = 0;
    } else {
        popLeft -= num;
    }
}



