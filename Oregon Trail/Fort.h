#ifndef FORT_H
#define FORT_H
#include <string>
#include <iostream>
using namespace std;

class Fort
{
    public:
        Fort();
        int getMileage();
        string getFortname();
        void setFortname(string);
        void setMileage(int);
    private:
        string fortname;//name of fort
        int mileage; // mileage of fort
};
#endif