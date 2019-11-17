#include "Player.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>
Player::Player(const std::string name, const bool is_h){
  name_ = name;
  points_ = 0;
  is_human_ = is_h;
  pos_.row = 0;
  pos_.col = 0;
  is_dead_ = false;
}  // constructor

// These are already implemented for you

//	// TODO: implement the following functions
//	// You MUST implement the following functions
//changes player points
void Player::ChangePoints(const int x){
  points_ += x;
}
//Sets is_dead_ member to true or false
void Player::SetDead(bool dead){
  is_dead_ = dead;
}
//
//	// set a new position for this player
void Player::SetPosition(Position pos){
  pos_ = pos;
}
//
//	// You may want to implement these functions as well
//	// ToRelativePosition is a function we used to translate positions
//	// into directions relative to the player (up, down, etc)
//didn't use this function
std::string Player::ToRelativePosition(Position other){
}
//
//	// Convert this player to a string representation of their name and points
std::string Player::Stringify(){
  std::string s = name_;
  std::string s2 = " points: ";
  std::string s3 = std::to_string(points_);
  s.append(s2);
  s.append(s3);
  return s;
}
//
//	// You may add other functions as needed/wanted
