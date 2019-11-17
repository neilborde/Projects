#include "Fort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

//ALL GETTERS AND SETTERS
Fort::Fort()
{
    fortname = "";
    mileage = 0;
}
void Fort::setMileage(int m)
{
    mileage = m;
}
void Fort::setFortname(string n)
{
    fortname = n;
}
int Fort::getMileage()
{
    return mileage;
}
string Fort::getFortname()
{
    return fortname;
}