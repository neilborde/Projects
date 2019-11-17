#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

class Player
{
    public:
        string getName();
        Player(string);
    private:
        string name;//name of players
};
#endif