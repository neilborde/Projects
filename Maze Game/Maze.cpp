
#include "Maze.h"
#include <vector>
#include "Player.h"
#include <string>
#include <cstdlib>


// you may change this enum as you need
// TODO: implement
// converts a squaretype into the correct ascii character
std::string SquareTypeStringify(SquareType sq){
  switch(sq){
    case SquareType::Wall:
      return "~";
    case SquareType::Exit:
      return "[]";
    case SquareType::Empty:
      return "O";
    case SquareType::Human:
      return "x";
    case SquareType::Enemy:
      return "M";
    case SquareType::Treasure:
      return "T";
    // default:
    //   return "";
  }

}

	// TODO: implement
  //board constructor
  //set all squares to empty
Board::Board(){
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j){
      arr_[i][j]=SquareType::Empty;
    }
  }
  //set human and exit corners
  arr_[0][0] = SquareType::Human;
  arr_[3][3] = SquareType::Exit;
  //set walls with 20% probability
  int random;
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j){
      //check if starting or exit square
      if((i+j != 0) && (i+j != 6)){
        random = (rand()%100)+1;
        if(random<=20){
          arr_[i][j] = SquareType::Wall;
        }
      }
    }
  }
  //set treasure with 10% probability
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j){
      if((i+j != 0) && (i+j != 6) && arr_[i][j]!=SquareType::Wall){
        random = (rand()%100)+1;
        if(random<=10){
          arr_[i][j] = SquareType::Treasure;
        }
      }
    }
  }
  //set enemy locations
  arr_[2][1] = SquareType::Enemy;
  arr_[3][0] = SquareType::Enemy;
}
//displays the board
void Board::display(){
  for (int i = 0; i < 4; ++i)
  {
      for (int j = 0; j < 4; ++j)
      {
          std::cout << SquareTypeStringify(arr_[i][j]) << ' ';
      }
      std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "If either you or the enemy cannot move, you must restart the game using ctrl+c!" << std::endl;
}


//	// TODO: you MUST implement the following functions
//gets squaretype at specific index
SquareType Board::get_square_value(Position pos) const{
  int i = pos.row;
  int j = pos.col;
  return arr_[i][j];
}
//
//	// set the value of a square to the given SquareType
void Board::SetSquareValue(Position pos, SquareType value){
  arr_[pos.row][pos.col] = value;
}
//
//	// get the possible Positions that a Player could move to
//	// (not off the board or into a wall)
// I changed this function to return a vector of strings instead of positions to better fit my implementation of the game
std::vector<std::string> Board::GetMoves(Player *p){
  Position pos = p->get_position();
  Position temp = pos;
  std::vector<std::string> moves;
  //check if the player can move in each direction, then push the string corresponding to that direction into the vector.
  //check if there is wall or if going outside bounds of array
  if (arr_[pos.row+1][pos.col] != SquareType::Wall && pos.row+1 != 4){
    moves.push_back("DOWN");
  }
  if (arr_[pos.row-1][pos.col] != SquareType::Wall && pos.row-1 != -1){
    moves.push_back("UP");
  }
  if (arr_[pos.row][pos.col+1] != SquareType::Wall && pos.col+1 != 4){
    moves.push_back("RIGHT");
  }
  if (arr_[pos.row][pos.col-1] != SquareType::Wall && pos.col-1 != -1){
    moves.push_back("LEFT");
  }
  return moves;

}
//
// //	// Move a player to a new position on the board. Return
// //	// true if they moved successfully, false otherwise.
//didn't use this function
bool Board::MovePlayer(Player *p, Position pos){
  p->SetPosition(pos);
  return true;

}
// //
// //	// Get the square type of the exit square
SquareType Board::GetExitOccupant(){
  return arr_[3][3];
}
// //
// //	// You probably want to implement this
// friend std::ostream& operator<<(std::ostream& os, const Board &b);



//	// TODO: implement these functions
//maze constructor
Maze::Maze(){
  // Board b;
  board_=new Board();
  turn_count_=0;
  std::vector<Player *> p;
  players_=p;
} // constructor
// //
// //	// initialize a new game, given one human player and
// //	// a number of enemies to generate
//Initialize 2 enemies
void Maze::NewGame(Player *human, const int enemies){
  players_.push_back(human);
  Player * enemy1 = new Player("enemy1",false);
  Player * enemy2 = new Player("enemy2",false);
  enemy1->SetPosition({2,1});
  enemy2->SetPosition({3,0});
  players_.push_back(enemy1);
  players_.push_back(enemy2);
  std::cout << "Welcome to the maze game!" << std::endl;
  std::cout << "Key:" << std::endl << "~ = WALL" << std::endl << "[] = EXIT" << std::endl << "O = EMPTY" << std::endl << "x = PLAYER" << std::endl << "M = ENEMY" << std::endl << "T = TREASURE" << std::endl << "~~~~" << std::endl;
  std::cout << "BOARD" << std::endl;

}
//helper function to check if a selected move is within the set of valid moves
bool isValid(std::vector<std::string> moves, std::string choice){
  for (int i = 0;i<moves.size();i++){
    if (choice == moves[i]){
      return true;
    }
  }
  return false;
}
// //
// //	// have the given Player take their turn
void Maze::TakeTurn(Player *p){
  //display board
  board_->display();
  //get set of valid moves
  std::vector<std::string> moves = board_->GetMoves(p);
  //position structs for all possible moves
  Position pos = p->get_position();
  Position pdown = pos;
  Position pup = pos;
  Position pleft = pos;
  Position pright = pos;
  pdown.row++;
  pup.row--;
  pleft.col--;
  pright.col++;
  std::string choice;
  //printing possible moves
  std::cout <<  p->get_name() << "'s choices are: ";
  for(int i = 0; i < moves.size();i++){
    std::cout << moves[i] << " ";
  }
  //obtain user input and convert to uppercase
  getline(std::cin,choice);
  for(int i = 0; i < choice.length(); i++){
    choice[i]=toupper(choice[i]);
  }
  //checking if valild choice or not
  while(!isValid(moves,choice)){
    std::cout << "invalid choice pick again" << std::endl;
    getline(std::cin,choice);
    for(int i = 0; i < choice.length(); i++){
      choice[i]=toupper(choice[i]);
    }
  }
  //conditional for if player is human
  if(p->is_human()==true){
    //set position correctly if choice is down, check for treasure update points, check for enemy set isdead to ture, check for exit points
    //This is repeated for all directions
    if (choice == "DOWN"){
      p->SetPosition(pdown);
      if (board_->get_square_value(pdown)==SquareType::Treasure){
        p->ChangePoints(100);
      }
      if (board_->get_square_value(pdown)==SquareType::Enemy && p->is_human()==true){
        p->SetDead(true);
      }
      if (pdown.row == 3 && pdown.col == 3){
        p->ChangePoints(1);
      }
      board_->SetSquareValue(pdown,SquareType::Human);
      board_->SetSquareValue(pos,SquareType::Empty);
    }
    else if (choice == "UP"){
      if (board_->get_square_value(pup)==SquareType::Treasure){
        p->ChangePoints(100);
      }
      if (board_->get_square_value(pup)==SquareType::Enemy && p->is_human()==true){
        p->SetDead(true);
      }
      if (pup.row == 3 && pup.col == 3){
        p->ChangePoints(1);
      }
      p->SetPosition(pup);
      board_->SetSquareValue(pup,SquareType::Human);
      board_->SetSquareValue(pos,SquareType::Empty);
    }
    else if (choice == "LEFT"){
      if (board_->get_square_value(pleft)==SquareType::Treasure){
        p->ChangePoints(100);
      }
      if (board_->get_square_value(pleft)==SquareType::Enemy && p->is_human()==true){
        p->SetDead(true);
      }
      if (pleft.row == 3 && pleft.col == 3){
        p->ChangePoints(1);
      }
      p->SetPosition(pleft);
      board_->SetSquareValue(pleft,SquareType::Human);
      board_->SetSquareValue(pos,SquareType::Empty);
    }
    else if (choice == "RIGHT"){
      if (board_->get_square_value(pright)==SquareType::Treasure){
        p->ChangePoints(100);
      }
      if (board_->get_square_value(pright)==SquareType::Enemy && p->is_human()==true){
        p->SetDead(true);
      }
      if (pright.row == 3 && pright.col == 3){
        p->ChangePoints(1);
      }
      p->SetPosition(pright);
      board_->SetSquareValue(pright,SquareType::Human);
      board_->SetSquareValue(pos,SquareType::Empty);
     }
   }
   //if player is enemy
 else{
   //mostly same as above with some different interactions with enemy moving onto enemy, or enemy moving onto human
   //Also repeated for all directions
   if (choice == "DOWN"){
     if (board_->get_square_value(pdown)!=SquareType::Enemy){
       p->SetPosition(pdown);
       if (board_->get_square_value(pdown)==SquareType::Treasure){
         p->ChangePoints(100);
       }
       if (board_->get_square_value(pdown)==SquareType::Human && p->is_human()==false){
         players_[0]->SetDead(true);
       }
       if (pdown.row == 3 && pdown.col == 3){
         p->ChangePoints(1);
       }
       board_->SetSquareValue(pdown,SquareType::Enemy);
       board_->SetSquareValue(pos,SquareType::Empty);
   }
 }
   else if (choice == "UP"){
     if (board_->get_square_value(pup)!=SquareType::Enemy){
       if (board_->get_square_value(pup)==SquareType::Treasure){
         p->ChangePoints(100);
       }
       if (board_->get_square_value(pup)==SquareType::Human && p->is_human()==false){
         players_[0]->SetDead(true);
       }
       if (pup.row == 3 && pup.col == 3){
         p->ChangePoints(1);
       }
       p->SetPosition(pup);
       board_->SetSquareValue(pup,SquareType::Enemy);
       board_->SetSquareValue(pos,SquareType::Empty);
     }
   }
   else if (choice == "LEFT"){
     if (board_->get_square_value(pleft)!=SquareType::Enemy){
       if (board_->get_square_value(pleft)==SquareType::Treasure){
         p->ChangePoints(100);
       }
       if (board_->get_square_value(pleft)==SquareType::Human && p->is_human()==false){
         players_[0]->SetDead(true);
       }
       if (pleft.row == 3 && pleft.col == 3){
         p->ChangePoints(1);
       }
       p->SetPosition(pleft);
       board_->SetSquareValue(pleft,SquareType::Enemy);
       board_->SetSquareValue(pos,SquareType::Empty);
     }
   }
   else if (choice == "RIGHT"){
     if (board_->get_square_value(pright)!=SquareType::Enemy){
       if (board_->get_square_value(pright)==SquareType::Treasure){
         p->ChangePoints(100);
       }
       if (board_->get_square_value(pright)==SquareType::Human && p->is_human()==false){
         players_[0]->SetDead(true);
       }
       if (pright.row == 3 && pright.col == 3){
         p->ChangePoints(1);
       }
       p->SetPosition(pright);
       board_->SetSquareValue(pright,SquareType::Enemy);
       board_->SetSquareValue(pos,SquareType::Empty);
      }
    }
 }
 //increment turn counter
   turn_count_++;
}
// //
// //	// Get the next player in turn order
Player * Maze::GetNextPlayer(){
  int player = turn_count_%3;
  return players_[player];
}
// //
// //	// return true iff the human made it to the exit
// //	// or the enemies ate all the humans
bool Maze::IsGameOver(){
  bool yesno = false;
  if (players_[0]->get_dead()==true || board_->get_square_value({3,3}) == SquareType::Human){
    yesno = true;
  }
  return yesno;
}
// //
// //	// You probably want to implement these functions as well
// //	// string info about the game's conditions after it is over
std::string Maze::GenerateReport(){
  for (int i =0; i < players_.size(); i++){
    std::cout << players_[i]->get_name() << " has " << players_[i]->get_points() << " points. ";
  }
}
// friend std::ostream& operator<<(std::ostream& os, const Maze &m);
//
