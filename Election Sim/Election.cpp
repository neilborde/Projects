#include "Election.hpp"
#include "ElectoralMap.hpp"

int Candidate::num_ = 0;

//convert party to string takes party
std::string Stringify2(Party p){
  switch(p){
    case Party::Republican:
      return "Republican";
    case Party::Democrat:
      return "Democrat";
    default:
      return "ERROR";
  }
}

//displays candidates
void Election::disp(){
  for(auto elem : candidates_){
    std::cout << elem.name_ << std::endl;
    std::cout << Stringify2(elem.party_) << std::endl << elem.id_ << std::endl;
  }
}

//constructor
Election::Election(){
  Candidate::num_=0;
}
//registers candidates for election takes a party and string name
void Election::Register(Party p, std::string n){
  Candidate::num_++;
  Candidate c;
  c.party_ = p;
  c.name_ = n;
  c.id_ = Candidate::num_;
  candidates_.push_back(c);
}

//returns all the candidates belonging to a party, takes party
std::vector<Candidate> Election::PartyCandidate(Party p){
  std::vector<Candidate> vec;
  for(auto elem : candidates_){
    if(elem.party_==p){
      vec.push_back(elem);
    }
  }
  return vec;
}
//calls a vote for normal election
void Election::Vote(){
  ElectoralMap &map = ElectoralMap::GetInstance();
  map.voteNormalTotal(*this);
}

//allows a candidate to campaign in a district, takes two ints for candidate and district id
void Election::Campaign(int cand_id, int dist_id){
  std::vector<Candidate> cands = get_candidates();
  std::string name;
  ElectoralMap& map = ElectoralMap::GetInstance();
  Party p;
  //determines candidate information
  for(auto elem : cands){
    if(elem.id_==cand_id){
      name = elem.name_;
      p = elem.party_;
    }
  }
  std::cout << name << " is campaigning in district " << dist_id << std::endl;
  Party majority = map.get_district(dist_id).MajorityOther(p);
  //check if there are no more consituents in the majority other district to convert
  if(map.get_district(dist_id).get_party_constituents(majority)>0){
    //calculation of psuccess and pextrasuccess
    int party_constituents = map.get_district(dist_id).get_party_constituents(p);
    int non_party_constituents = map.get_district(dist_id).get_non_party_constituents(p);
    int majority_consituents = map.get_district(dist_id).get_party_constituents(map.get_district(dist_id).Majority());
    Party majority = map.get_district(dist_id).MajorityOther(p);
    double numerator = (party_constituents+1)*2;
    double value1 = numerator/double(non_party_constituents);
    double value2 = numerator/double(map.get_district(dist_id).get_area());
    double p_success = value1*value2;
    double p_extra_success = p_success*0.1;
    p_success*=100;
    p_extra_success*=100;
    std::cout << "Chances to convert: " << p_success << std::endl;
    std::cout << "Chances to convert from another party: " << p_extra_success << std::endl;
    //getting random number to determine who to convert
    int rand_num = (rand()%100)+1;
    //checking for edge cases and rand number not in conversion interval
    if(rand_num > p_success || (majority_consituents == 0 && !map.get_district(dist_id).AreNone()) || (rand_num > p_extra_success && rand_num <= p_success && !map.get_district(dist_id).AreNone())){
      std::cout << "No one was converted." << std::endl;
    }
    //psuccess but not pextrasuccess
    else if(rand_num <= p_success && rand_num > p_extra_success && map.get_district(dist_id).AreNone()){
      map.get_district(dist_id).ConvertConstituent(Party::None,p);
    }
    //psuccess and pextrasuccess
    else if(rand_num <=p_extra_success && map.get_district(dist_id).AreNone()){
      map.get_district(dist_id).ConvertConstituent(Party::None,p);
      map.get_district(dist_id).ConvertConstituent(majority,p);
    }
    //psuccess and pextrasuccess but no one in party none
    else if(rand_num <= p_extra_success && !map.get_district(dist_id).AreNone()){
      map.get_district(dist_id).ConvertConstituent(majority,p);
    }
  }
  else{
    std::cout << "No one left in party to convert." << std::endl;
  }

}

//displays candidates
void Election::DispCands(){
  for(auto elem : candidates_){
    std::cout << elem.id_ << ": " << elem.name_ << std::endl;
  }
}

//calls vote for representative election
void RepresentativeElection::Vote(){
  ElectoralMap &map = ElectoralMap::GetInstance();
  map.voteRepTotal(*this);
}
