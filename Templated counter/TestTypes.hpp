#ifndef _TESTTYPES_H_
#define _TESTTYPES_H_
class Book{

public:
  Book(int n){
    numpages_=n;
  }
  friend bool operator<(const Book &b, const Book &b2) {
    return(b.numpages_ < b2.numpages_);
  }
  friend bool operator>(const Book &b, const Book &b2) {
    return(b.numpages_ > b2.numpages_);
  }
  friend bool operator<=(const Book &b, const Book &b2) {
    return(b.numpages_ <= b2.numpages_);
  }
  friend bool operator>=(const Book &b, const Book &b2) {
    return(b.numpages_ >= b2.numpages_);
  }
  int getnumpages(){
    return numpages_;
  }
  friend std::ostream &operator<< (std::ostream &out, const Book &b){
    std::cout << b.numpages_;
  }

private:
  int numpages_;
};
struct Movie{
  int movielength_;
  friend bool operator<(const Movie &m, const Movie &m2){
    return(m.movielength_ < m2.movielength_);
  }
  friend bool operator>(const Movie &m, const Movie &m2){
    return(m.movielength_ > m2.movielength_);
  }
  friend bool operator<=(const Movie &m, const Movie &m2){
    return(m.movielength_ <= m2.movielength_);
  }
  friend bool operator>=(const Movie &m, const Movie &m2){
    return(m.movielength_ >= m2.movielength_);
  }
  friend std::ostream &operator<< (std::ostream &out, const Movie &m){
    std::cout << m.movielength_;
  }
};
enum class SquareType { Wall, Exit, Empty, Human, Enemy, Treasure };

#endif
