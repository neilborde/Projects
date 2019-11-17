#include "ElectoralMap.hpp"
#include <tuple>
#include <vector>
#include <cmath>

int ElectoralMap::dist_counter_ = 0;

std::vector<Party> Vectorize2(){
  std::vector<Party> vec = {Party::Democrat, Party::Republican};
  return vec;
}
std::string Stringify3(Party p){
  switch(p){
    case Party::Republican:
      return "Republican";
    case Party::Democrat:
      return "Democrat";
    case Party::None:
      return "None";
  }
}

//display function
void District::disp(){
  for(auto elem : constituents_){
    std::cout << Stringify3(elem.first) << ": " << elem.second << "      ";
  }
  std::cout << std::endl;
}

//gets majority party in a district
Party District::Majority(){
  Party max = Party::None;
  int maxnum = 0;
  for(auto elem : constituents_){
    if(elem.second >= maxnum){
      max = elem.first;
    }
  }
  return max;
}
//gets majority party other than a candidates party, takes party of candidate
Party District::MajorityOther(Party p){
  Party max = Party::None;
  int maxnum = 0;
  std::string pstring = Stringify3(p);
  for(auto elem : constituents_){
    //std::cout << Stringify3(elem.first) << std::endl << Stringify3(p);
    if(elem.first!=p && elem.second >= maxnum){
      max = elem.first;
    }
  }
  return max;
}

//constructor
District::District(){
  int rand_area = (rand()%25)+5;
  area_ = rand_area;
  for(auto elem : Vectorize2()){
    int rand_const = (rand()%10);
    constituents_.insert({elem, rand_const});
  }
  int rand_const = (rand()%10);
  constituents_.insert({Party::None, rand_const});
}

//converts constituent from one party to another, takes two parties
void District::ConvertConstituent(Party p, Party p2){
  //check if parties are the same
  if(p!=p2){
    //increment and decrement parties accordingly
    std::map<Party,int>::iterator it = constituents_.find(p);
    if(it->second-1>=0){
      it->second-=1;
      it = constituents_.find(p2);
      it->second+=1;
        std::cout << "Constituent was converted from " << Stringify3(p) << " to " << Stringify3(p2) << std::endl;
    }
    else{
      std::cout << "Can't covert from this party because there are no remaining consituents." << std::endl;
    }
  }
  else{
    std::cout << "Cannot convert because candidate's party is already majority party" << std::endl;
  }
}

//constructor
ElectoralMap::ElectoralMap(){
  for(int i = 1; i <= districts_; ++i){
    District d;
    distmap_.insert({i,d});
    dist_counter_++;
  }
}

//returns a district, takes int id
District& ElectoralMap::get_district(int id){
  District & d = distmap_[id];
  return d;
}

//display function
void ElectoralMap::disp(){
  for(auto elem : distmap_){
    std::cout << "District " << elem.first << "       " << std::endl << "square miles: " << elem.second.get_area() << std::endl;
    elem.second.disp();
    std::cout << std::endl << std::endl;
  }
}

//calls election partycandidate takes election object and party
std::vector<Candidate> ElectoralMap::PartyCandidate(Election e, Party p){
  return e.PartyCandidate(p);
}

//tallies votes for one district in normal election and returns map with candidate as key and votes as data, takes district and election.
std::map<Candidate,int> ElectoralMap::voteNormalDist(District d, Election e){
  std::map<Candidate,int> votes;
  std::vector<Candidate> cands = e.get_candidates();
  for(auto elem : e.get_candidates()){
    votes.insert({elem,0});
  }
  Party majority = d.Majority();
  for(auto elem : d.get_constituents()){
    std::vector<Candidate> c = PartyCandidate(e,elem.first);
    //PARTY NONE  OR NO CANDIDATES
    if(elem.first == Party::None || c.empty()){
      for(int i = 1; i <= elem.second; ++i){
        int rand_pct = (rand()%10)+1;
        //70%
        if(rand_pct>3){
          std::vector<Candidate> vec = PartyCandidate(e,majority);
          if(vec.size()>1){
            int rand_choice = (rand()%vec.size());
            std::map<Candidate,int>::iterator it = votes.find(vec[rand_choice]);
            it->second++;
          }
          else{
            std::map<Candidate,int>::iterator it = votes.find(vec[0]);
            it->second++;
          }
        }
        //30%
        else{
          std::vector<Candidate> cands2 = cands;
          for(int i = 0; i < cands2.size(); ++i){
            if(cands2[i].party_==majority){
              cands2.erase(cands2.begin()+i);
            }
          }
          int rand_choice = (rand()%cands2.size());
          std::map<Candidate,int>::iterator it = votes.find(cands2[rand_choice]);
          it->second++;
        }
      }
    }
    //NOT PARTY NONE
    else{
      for(int i = 1; i <= elem.second; ++i){
        int rand_pct = (rand()%10)+1;
        //90%
        if(rand_pct>1){
          std::vector<Candidate> cands3 = PartyCandidate(e,elem.first);
          int rand_choice = (rand()%cands3.size());
          std::map<Candidate,int>::iterator it = votes.find(cands3[rand_choice]);
          it->second++;
        }
        //10%
        else{
          std::vector<Candidate> cands4 = cands;
          for(int i = 0; i < cands4.size(); ++i){
            if(cands4[i].party_==elem.first){
              cands4.erase(cands4.begin()+i);
            }
          }
          int rand_choice = (rand()%cands4.size());
          std::map<Candidate,int>::iterator it = votes.find(cands4[rand_choice]);
          it->second++;
        }
      }
    }
  }
  return votes;
}
//aggregates district votes for normal election and prints winner, takes election object
void ElectoralMap::voteNormalTotal(Election e){
  std::cout << "VOTES BY DISTRICT:" << std::endl << std::endl;
  std::map<Candidate,int> total;
  std::vector<Candidate> cands = e.get_candidates();
  for(auto elem : cands){
    total.insert({elem,0});
  }
  for(auto elem : distmap_){
    std::cout << "District " << elem.first << std::endl;
    std::map<Candidate,int> map = voteNormalDist(elem.second, e);
    for(auto element : map){
      std::cout << element.first.name_ << ": " << element.second << "       ";
      std::map<Candidate,int>::iterator it = total.find(element.first);
      it->second+=element.second;
    }
    std::cout << std::endl;
  }
  //aggregates final results
  std::cout << std::endl << std::endl;
  int max = 0;
  std::string name;
  std::cout << "Full Results:" << std::endl;
  for(auto elem : total){
    if(elem.second >= max){
      max = elem.second;
      name = elem.first.name_;
    }
    std::cout << elem.first.name_ << ": " << elem.second << std::endl;
  }
  std::cout << std::endl << "Congratulation " << name << ". You win with " << max << " votes!" << std::endl << std::endl;

}

//per district vote for representative election, takes district and election
std::tuple<Candidate,int> ElectoralMap::voteRepDist(District d, Election e){
  std::map<Candidate,int> map = voteNormalDist(d,e);
  std::vector<Candidate> cands;
  int max = 0;
  Candidate c;
  for(auto elem : map){
    if(elem.second>=max){
      max = elem.second;
    }
  }
  for(auto elem : map){
    if(elem.second==max){
      cands.push_back(elem.first);
    }
  }
  int rand_choice = (rand()%cands.size());
  c = cands[rand_choice];
  int total_constituents = 0;
  for(auto elem : distmap_){
    total_constituents+=(elem.second.get_constituents2());
    //std::cout << total_constituents << std::endl;
  }
  int district_constituents = d.get_constituents2();
  int num_votes = 5 * districts_;
  int votes = floor((double(district_constituents)/total_constituents)*num_votes);
  std::tuple<Candidate,int> dist_winner = std::make_tuple(c,votes);
  return dist_winner;
}

//aggregates representative votes for all districts and declares winner
void ElectoralMap::voteRepTotal(Election e){
  std::map<Candidate,int> results;
  std::vector<Candidate> cands = e.get_candidates();
  for(auto elem : cands){
    results.insert({elem,0});
  }
  std::cout << "DISTRICT VOTES" << std::endl << std::endl;
  for(auto elem : distmap_){
    std::tuple<Candidate, int> dist_winner = voteRepDist(elem.second,e);
    std::map<Candidate,int>::iterator it = results.find(std::get<0>(dist_winner));
    it->second+=std::get<1>(dist_winner);
    std::cout << "District: " << elem.first << std::endl;
    std::cout << std::get<0>(dist_winner).name_ << ": " << std::get<1>(dist_winner) << std::endl;
  }
  std::cout << std::endl << "FINAL RESULTS" << std::endl << std::endl;
  int max = 0;
  for(auto elem : results){
    if(elem.second >= max){
      max = elem.second;
    }
    std::cout << elem.first.name_ << ": " << elem.second << std::endl;
  }
  std::vector<Candidate> cands2;
  for(auto elem : results){
    if(elem.second == max){
      cands2.push_back(elem.first);
    }
  }
  if(cands2.size()>1){
    int rand_choice = (rand()%cands2.size());
    std::cout << "Congratulations " << cands2[rand_choice].name_ << " you won!" << std::endl << std::endl;
  }
  else{
    std::cout << "Congratulations " << cands2[0].name_ << " you won!" << std::endl << std::endl;
  }
}
