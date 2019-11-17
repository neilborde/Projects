#ifndef _TEXTUI_H_
#define _TEXTUI_H_
#include <iostream>
#include <vector>

class TextUI {
public:
  TextUI();

  std::string PickElection();

  void RouteElection(std::string choice);

  //int ItemMenu(Store s, std::map<int, std::string> items);


private:
  std::vector<std::string> main_menu_;
};

#endif
