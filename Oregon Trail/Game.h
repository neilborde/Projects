#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include "Player.h"
#include "Trip.h"
using namespace std;

#include <vector>

class Game
{
    public:
        int split(string, char, string array[], int);
        bool huntChecker(string);
        bool gameEnd();
        bool gameEnd2();
        void finalStatus();
        bool menuChecker(string);
        void dayTracker(int);
        void statusUpdate();
        bool amountChecker(string);
        bool storeChecker(string);
        bool storeChecker2(string);
        void currentBill();
        void start();
        void storeInitial();
        bool daychecker(int, string);
        bool monthchecker(string);
        void initialize();
        void displayMenu();
        bool puzzle();
        bool menu();
        void store();
        void rest();
        void hunt();
        void trail();
        void misfortune();
        void raiders();
    private:
        vector<Player> players;
        Trip trip;
        const int numPlayers = 5;
};
#endif