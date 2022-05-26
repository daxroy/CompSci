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