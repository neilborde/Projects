/*
Neil Borde
Homework 1 Maze Game
This game allows the player to control their own character and two enemies. They must try to reach the exit.
Running program does not require any parameters
*/

#include <iostream>
#include "Player.h"
#include "Maze.h"
#include <ctime>
using namespace std;

int main(){
  srand(time(NULL));
  Player p("Player",true);
  Maze m;
  m.NewGame(&p,2);
  while(!m.IsGameOver()){
    m.TakeTurn(m.GetNextPlayer());
  }
  m.GenerateReport();
}
