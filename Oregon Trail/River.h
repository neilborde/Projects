#ifndef RIVER_H
#define RIVER_H
#include <string>
#include <iostream>
using namespace std;

class River
{
    public:
        River();
        void setRivername(string);
        void setMileage(int);
        int getMileage();
        string getName();
        int getDepth();
        void setDepth(int);
    private:
        int mileage;//mileage
        string rivername;//name of river
        int depth;//depth of river
};
#endif