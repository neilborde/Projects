#ifndef _ELECTION_H_
#define _ELECTION_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>


enum class Party { None, Democrat, Republican};
//   friend bool operator==(const Party & p, const Part & p2){
//     return(Stringify4(p)==Stringify4(p2))
//   }
// };

struct Candidate{
  std::string name_;
  Party party_;
  int id_;
  static int num_;
  friend bool operator<(const Candidate &c, const Candidate &c2) {
    return(c.id_ < c2.id_);
  }
};

class Election{
public:
  Election();
  void Register(Party p, std::string n);
  void disp();
  void DispCands();
  std::vector<Candidate> get_candidates(){
    return candidates_;
  }
  std::vector<Candidate> PartyCandidate(Party p);
  virtual void Vote();
  void Campaign(int cand_id, int dist_id);
private:
  std::vector<Candidate> candidates_;
};

class RepresentativeElection : public Election{
public:
  RepresentativeElection() : Election(){}
  void Vote();
private:
};

#endif
