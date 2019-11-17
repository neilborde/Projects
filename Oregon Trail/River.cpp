#include "River.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

//ALL GETTERS AND SETTERS
River::River()
{
    rivername = "";
    mileage = 0;
}
void River::setRivername(string n)
{
    rivername = n;
}
void River::setMileage(int m)
{
    mileage = m;
}
void River::setDepth(int d)
{
    depth = d;
}
int River::getMileage()
{
    return mileage;
}
string River::getName()
{
    return rivername;
}
int River::getDepth()
{
    return depth;
}