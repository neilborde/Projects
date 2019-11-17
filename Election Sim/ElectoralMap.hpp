#ifndef _ELECTORALMAP_H_
#define _ELECTORALMAP_H_
#include "Election.hpp"
#include <map>
#include <iostream>
#include <iterator>


class District{
public:
  District();
  friend std::ostream &operator<< (std::ostream &out, const District &d){
    std::cout << d.area_;
  }
  void disp();
  std::map<Party,int> get_constituents(){
    return constituents_;
  }
  Party Majority();
  int get_area(){
    return area_;
  }
  int get_constituents2(){
    int num = 0;
    for(auto elem : constituents_){
      num+=elem.second;
    }
    return num;
  }
  int get_party_constituents(Party p){
    for(auto elem : constituents_){
      if(elem.first==p){
        return elem.second;
      }
    }
  }
  int get_non_party_constituents(Party p){
    int num = 0;
    for(auto elem : constituents_){
      if(elem.first != p && elem.first != Party::None){
        num+=elem.second;
      }
    }
    return num;
  }
  bool AreNone(){
    for(auto elem : constituents_){
      if(elem.first==Party::None){
        return(elem.second>0);
      }
    }
  }
  void ConvertConstituent(Party p, Party p2);
  Party MajorityOther(Party p);
private:
  int area_;
  std::map<Party,int> constituents_;
};


class ElectoralMap{
private:
  ElectoralMap();
  std::map<int,District> distmap_;
public:
  static ElectoralMap& GetInstance() {
		// gets instantiated the first time
		static ElectoralMap instance; // guaranteed to be destroyed

		return instance;
	}
  District& get_district(int id);
  friend std::ostream &operator<< (std::ostream &out, const ElectoralMap &em){
    for (auto elem : em.distmap_){
      std::cout << "District " << elem.first << ": " << elem.second << std::endl;
    }
  }
  static const int districts_ = 4;
  static int dist_counter_;
  ElectoralMap(ElectoralMap const&) = delete; // copy constructor
	void operator=(ElectoralMap const&) = delete;
  void disp();
  std::map<Candidate,int> voteNormalDist(District d, Election e);
  std::vector<Candidate> PartyCandidate(Election e, Party p);
  void voteNormalTotal(Election e);
  std::tuple<Candidate,int> voteRepDist(District d, Election e);
  void voteRepTotal(Election e);

};

#endif
