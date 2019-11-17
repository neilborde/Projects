#ifndef TRIP_H
#define TRIP_H
#include "River.h"
#include "Fort.h"
#include <string>
#include <iostream>
using namespace std;

class Trip
{
    public:
        void setFortnameAt(int, string);
        string getFortnameAt(int);
        string getRivernameAt(int);
        void setFortMileageAt(int, int);
        void setRivernameAt(int, string);
        void setRiverMileageAt(int, int);
        void setRiverDepthAt(int, int);
        int getMonth();
        void setMonth(int);
        int getDay();
        void setDay(int);
        int getMileage();
        void setMileage(int);
        int getClosestRiver();
        int getClosestFort();
        int getOxen();
        void setOxen(int);
        int getFood();
        void setFood(int);
        int getBullets();
        void setBullets(int);
        int getParts();
        void setParts(int);
        int getMedkits();
        void setMedkits(int);
        double getMoney();
        void setMoney(double);
        int getFortIndex();
        int getRiverIndex();
        int getRiverDepthAt(int);
        int getFortMileageAt(int);
    private:
        Fort fortarray[6];//array of fort objects
        River riverarray[4];//array of river objects
        int month = 0;//motn
        int day = 0;//day
        int mileage = 0;//total mileage
        double money = 0.0;//total money
        int oxen = 0;//oxen
        int food = 0;//food
        int bullets = 0;//bullets
        int parts = 0;//wagon parts
        int medkits = 0;//medkits
        const int numRivers = 4;//number of river
        const int numForts = 6;//number of forts
};
#endif