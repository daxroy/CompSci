//CSCI1300 Spring 2022
//Author: Martin Dax Roy & Noah Mamo
//Recitation: 103 - Rahul Kumar
//Project 3

#ifndef USER_H
#define USER_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;


class User {
    string name;
    int health;  // Players body health 
    int money;  // current amount of cash on player 
    int fuel;   // fuel on the spaceship of player
    int suitGrade;  // what grade suit player has  
    string weapon[3][2]; // the weapons player has     
    int crew[2]; //crews player chose 2 only 
    int suitHealth; // The suits condition
	int healthKits; // healing kit for health 
	bool translator;  // alien communicaiton
    int numPlanetsExplored;
    int numSaved;
    int numLost;
    int numRepHabit;
    int numRepInhabit;
    int popLeft;
    

    
    public:
    User();
    string getName();
    void setName(string);
    int getHealth();
    void setHealth(int); 
    int getSuitHealth();
    void setSuitHealth(int);
    int getHealthKits();
    void setHealthKits(int);
    int getMoney(); 
    void setMoney(int);
    int getFuel();
    void setFuel(int);
    int getSuitGrade();
    void setSuitGrade(int);
    int getWeapon(int);
    void setWeapon(int, string);
    int getCrew(int);
    void setCrew(int, int);
    bool getTranslator();
    void setTranslator(bool);
    int getNumExplored();
    void setNumExplored(int);
    int getNumSaved();
    void setNumSaved(int);
    int getNumLost();
    void setNumLost(int);
    int getRepHabit();
    void setRepHabit(int);
    int getRepInhabit();
    void setRepInhabit(int);
    int getPopLeft();
    void setPopLeft(int);
};
#endif

