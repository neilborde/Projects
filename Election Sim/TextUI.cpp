#include "TextUI.hpp"
#include "Election.hpp"
#include "ElectoralMap.hpp"
#include <string>


//returns a vector of parties from the enum
std::vector<Party> Vectorize(){
  std::vector<Party> vec = {Party::Democrat, Party::Republican};
  return vec;
}
std::string Stringify(Party p){
  switch(p){
    case Party::Republican:
      return "Republican";
    case Party::Democrat:
      return "Democrat";
  }
}

//constructor
TextUI::TextUI() {
  // set up the main menu
  main_menu_.push_back("Normal Election");
  main_menu_.push_back("Representative Election");
}

//takes user input and returns type of election
std::string TextUI::PickElection() {
  int choice = -1;
  while (choice < 0 || choice >= main_menu_.size()) {
    // display the main menu
    for (int i = 0; i < main_menu_.size(); i++) {
      std::cout << std::to_string(i) << ": " << main_menu_[i] << std::endl;
    }
    std::string str_choice;
    std::cin >> str_choice;
    try {
      choice = std::stoi(str_choice);
    } catch (const std::invalid_argument& ia) {
      std::cout << "Enter a number" << std::endl;
    }
  }
  return main_menu_[choice];
}

//executes correct election type, takes string of election type
void TextUI::RouteElection(std::string choice){
  ElectoralMap &map = ElectoralMap::GetInstance();
  Election * elec = nullptr;
  if(choice == "Representative Election"){
    elec = new RepresentativeElection();
  }
  else if (choice == "Normal Election"){
    elec = new Election();
  }
  std::string reg_choice;
  //registering candidates for election
  std::vector<Party> vec = Vectorize();
  for(auto elem : vec){
    std::cout << "Would you like to register a candidate for " << Stringify(elem) << "? (y or n)" << std::endl;
    std::cin >> reg_choice;
    while(reg_choice=="y"){
      std::string name_choice;
      std::cout << "What is their name" << std::endl;
      std::cin >> name_choice;
      elec->Register(elem, name_choice);
      std::cout << "Would you like to register a candidate for " << Stringify(elem) << "? (y or n)" << std::endl;
      std::cin >> reg_choice;
    }
  }
  //handles campaigning
  std::vector<Candidate> cands = elec->get_candidates();
  std::string campaign_choice;
  std::string district_choice = "0";
  map.disp();
  elec->DispCands();
  std::cout << "Which candidate is campaigning (id) (0 to stop) ?" << std::endl;
  std::cin >> campaign_choice;
  if(campaign_choice!="0"){
    std::cout << "Where is this candidate campaigning (id) (0 to stop) ?" <<std::endl;
    std::cin >> district_choice;
  }
  while(campaign_choice!="0" && district_choice!="0"){
    elec->Campaign(stoi(campaign_choice),stoi(district_choice));
    map.disp();
    elec->DispCands();
    std::cout << "Which candidate is campaigning (id) (0 to stop) ?" << std::endl;
    std::cin >> campaign_choice;
    if(campaign_choice!="0"){
      std::cout << "Where is this candidate campaigning (id) (0 to stop) ?" <<std::endl;
      std::cin >> district_choice;
    }
  }
  map.disp();
  elec->Vote();
}
