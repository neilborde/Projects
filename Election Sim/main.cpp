#include "ElectoralMap.hpp"
#include "Election.hpp"
#include "TextUI.hpp"
#include <ctime>

/*Name: Neil Borde
This program simulates both normal elections and representative elections until stopped by pressing ctrl+c*/

int main(){
  srand(time(NULL));


  // Create a TextUI object, then continue prompting the user
  // for what they want to do until they leave the store
  while(1){
    std::cout << "Pick an election type." << std::endl;
    TextUI ui;
    std::string choice;
    choice = ui.PickElection();
    std::cout << std::endl;
    ui.RouteElection(choice);
  }

}
