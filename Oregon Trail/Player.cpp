#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

//GETTER AND SETTER
Player::Player(string n)
{
    name = n;
}
string Player::getName()
{
    return name;
}
