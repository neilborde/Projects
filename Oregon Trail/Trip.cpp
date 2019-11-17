#include "Trip.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;


void Trip::setFortnameAt(int index, string n)
{
    //sets name of fort at certain index
    fortarray[index].setFortname(n);
}
void Trip::setFortMileageAt(int index, int m)
{
    //sets mileage at certain index
    fortarray[index].setMileage(m);
}
void Trip::setRivernameAt(int index, string n)
{
    //sets name at certain index
    riverarray[index].setRivername(n);
}
void Trip::setRiverMileageAt(int index, int m)
{
    //sets mileage at certain index
    riverarray[index].setMileage(m);
}
void Trip::setRiverDepthAt(int index, int depth)
{
    //sets depth at certain indx
    riverarray[index].setDepth(depth);
}
string Trip::getFortnameAt(int index)
{
    //gets name at certain index
    string s = fortarray[index].getFortname();
    return s;
}
string Trip::getRivernameAt(int index)
{
    //gets name at certain index
    string s = riverarray[index].getName();
    return s;
}
int Trip::getRiverDepthAt(int index)
{
    //gets depth at certain index
    int s = riverarray[index].getDepth();
    return s;
}
int Trip::getFortMileageAt(int index)
{
    //gets mileage at certain index
    int c = fortarray[index].getMileage();
    return c;
}
//GETTERS AND SETTERS
int Trip::getMonth()
{
    return month;
}
void Trip::setMonth(int m)
{
    month = m;
}
int Trip::getDay()
{
    return day;
}
void Trip::setDay(int d)
{
    day = d;
}
int Trip::getMileage()
{
    return mileage;
}
void Trip::setMileage(int miles)
{
    mileage += miles;
}

int Trip::getClosestRiver()
{
    //arbitrary max value
    int max = 100000;
    //runs through all rivers
    for (int i = 0; i < numRivers; i++)
    {
        //checks if river is closer than total mileage and previous river
        if (riverarray[i].getMileage() > mileage and riverarray[i].getMileage() < max)
        {
            //sets new max
            max = riverarray[i].getMileage();
        }
    }
    return max;
}
int Trip::getClosestFort()
{
    //SAME AS RIVER FUNCTION
    int max = 100000;
    for (int i = 0; i < numForts; i++)
    {
        if (fortarray[i].getMileage() > mileage and fortarray[i].getMileage() < max)
        {
            max = fortarray[i].getMileage();
        }
    }
    return max;
}

int Trip::getFortIndex()
{
    //return index of fort if mileage is equal to fort mileage
    for (int i = 0; i < numForts; i++)
    {
        if (getMileage() == fortarray[i].getMileage())
        {
            return i;
        }
    }
    return 0;
}
int Trip::getRiverIndex()
{
    //SAME AS FORT FUNCTION ABOVE
    for (int i = 0; i < numRivers; i++)
    {
        if (getMileage() == riverarray[i].getMileage())
        {
            return i;
        }
    }
}
//GETTERS AND SETTERS
int Trip::getOxen()
{
    return oxen;
}
void Trip::setOxen(int o)
{
    oxen += o;
}
int Trip::getFood()
{
    return food;
}
void Trip::setFood(int f)
{
    food += f;
}
int Trip::getBullets()
{
    return bullets;
}
void Trip::setBullets(int b)
{
    bullets += b;
}
int Trip::getParts()
{
    return parts;
}
void Trip::setParts(int w)
{
    parts+=w;
}
int Trip::getMedkits()
{
    return medkits;
}
void Trip::setMedkits(int m)
{
    medkits += m;
}
double Trip::getMoney()
{
    return money;
}
void Trip::setMoney(double m)
{
    money += m;
}