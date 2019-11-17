#ifndef COUNTER_HPP
#define COUNTER_HPP
#include <map>
#include <iterator>
#include <iostream>
#include <vector>
#include <tuple>
template <class T>
class Counter {
public:
  // any methods that interact with T as a parameter
  // or a return value will need to be explicitly marked
  // template <class T> when you implement them
  Counter();
  Counter(const std::vector<T> &vec);
  void Increment(const T &key);
  void display();
  void Increment(const T &key, const int &n);
  void Decrement(const T &key);
  void Decrement(const T &key, const int &n);
  int getValueAt(const T &key);
  std::vector<T> NMostCommon(const int &n);
  std::vector<T> NLeastCommon(const int &n);
  std::vector<std::tuple<T,double>> NormalizedWeight();
  std::vector<T> get_key_set();
  std::vector<int> get_value_set();
  std::map<T,int> get_map();
  const int get_total();
  const int get_total_range(const T &min, const T &max);
  void Remove(const T &key);
  const int get_count_for_key(const T &key);
  friend std::ostream &operator<< (std::ostream &out, const Counter<T> &c){
    for(auto elem : c.countmap_){
      std::cout << elem.first << ": " << elem.second << std::endl;
    }
  }
  //gettotalobjectcount90

private:
  std::map<T,int> countmap_;
};
//constructor
template <class T>
Counter<T>::Counter(){
}
//constructor: takes vector of type T to initialize values
template <class T>
Counter<T>::Counter(const std::vector<T> &vec){
  for(int i = 0; i < vec.size(); ++i){
    countmap_[vec[i]]++;
  }
}
//returns the count for a certain key, implemented this bebfore realizing there was another function doing the same thing
template <class T>
int Counter<T>::getValueAt(const T &key){
  typename std::map<T,int>::iterator it = countmap_.find(key);
  if(it == countmap_.end()){
    return -1;
  }
  return countmap_[key];
}
//increment key by 1, takes key
template <class T>
void Counter<T>::Increment(const T &key){
  countmap_[key]++;
}
//display function, didn't really use
template <class T>
void Counter<T>::display(){
  for(auto elem : countmap_)
  {
     std::cout << elem.first << " " << elem.second << "\n";
  }
}
//increment key by n, takes key and n
template <class T>
void Counter<T>::Increment(const T &key, const int &n){
  countmap_[key]+=n;
}
//decrement key by 1, takes key
template <class T>
void Counter<T>::Decrement(const T &key){
  typename std::map<T,int>::iterator it = countmap_.find(key);
  if (countmap_[key] == 1){
    countmap_.erase(key);
  }
  //if elem nonexistent
  else if(it == countmap_.end()){
    //std::cout << "Element does not exist in map. Cannot decrement" << std::endl;
    countmap_.erase(key);
  }
  else{
    countmap_[key]--;
  }
}
//decrement key by n, takes key and n
template <class T>
void Counter<T>::Decrement(const T &key, const int &n){
  typename std::map<T,int>::iterator it = countmap_.find(key);
  if (countmap_[key] == n){
    countmap_.erase(key);
  }
  else if (it != countmap_.end() && countmap_[key] < n){
    //std::cout << "Can't decrement by this much." << std::endl;
  }
  else if(it == countmap_.end()){
    //std::cout << "Element does not exist in map. Cannot decrement" << std::endl;
    countmap_.erase(key);
  }
  else{
    countmap_[key]-=n;
  }
}
//returns vector of keys of n most common elements, takes int n
template <class T>
std::vector<T> Counter<T>::NMostCommon(const int &n){
  if (n > countmap_.size()){
    std::cout << "n too large" << std::endl;
  }
  else{
    std::vector<std::tuple<int, T> > tuples;
    std::vector<int> values;
    //making a vector of tuples <int, T>
    for(auto elem : countmap_){
      tuples.push_back(std::make_tuple(elem.second,elem.first));
    }
    //sort in ascending order
    sort(tuples.begin(),tuples.end());
    //reverse for descending order
    reverse(tuples.begin(),tuples.end());
    std::vector<T> ret;
    //add n most common
    for(int i = 0; i < n; ++i){
      ret.push_back(std::get<1>(tuples[i]));
    }
    return ret;
  }
}
//returns vector of keys of n least common elements, takes int n
//same as previous function but without the reverse call.
template <class T>
std::vector<T> Counter<T>::NLeastCommon(const int &n){
  if (n > countmap_.size() || countmap_.empty()){
    //std::cout << "Parameter n larger than map size" << std::endl;
  }
  else{
    std::vector<std::tuple<int, T> > tuples;
    std::vector<int> values;
    for(auto elem : countmap_){
      tuples.push_back(std::make_tuple(elem.second,elem.first));
    }
    sort(tuples.begin(),tuples.end());
    std::vector<T> ret;
    for(int i = 0; i < n; ++i){
      ret.push_back(std::get<1>(tuples[i]));
    }
    return ret;
  }
}
//returns a vector of tuples <T,double> with the double being their normalized weight
template <class T>
std::vector<std::tuple<T,double>> Counter<T>::NormalizedWeight(){
  if(countmap_.empty()){
    std::cout << "empty map" << std::endl;
  }
  else{
    int counter = 0;
    //get total count
    for(auto elem : countmap_){
      counter+=elem.second;
    }
    std::vector<std::tuple<T,double>> ret;
    for(auto elem : countmap_){
      //get percentage weight
      double percent = (double(elem.second)/counter);
      //add tuple to return vector
      ret.push_back(std::make_tuple(elem.first,percent));
    }
    return ret;
  }
}
//gets vector of all keys in map
template <class T>
std::vector<T> Counter<T>::get_key_set(){
  if(countmap_.empty()){
    //std::cout << "empty map" << std::endl;
  }
  else{
    std::vector<T> keys;
    for(auto elem : countmap_){
      keys.push_back(elem.first);
    }
    return keys;
  }
}
//gets vector of all values in map
template <class T>
std::vector<int> Counter<T>::get_value_set(){
  if(countmap_.empty()){
    //std::cout << "empty map" << std::endl;
  }
  else{
    std::vector<int> values;
    for(auto elem : countmap_){
      values.push_back(elem.second);
    }
    return values;
  }
}
//returns underlying map
template <class T>
std::map<T,int> Counter<T>::get_map(){
  return countmap_;
}
//gets total count of all elements
template <class T>
const int Counter<T>::get_total(){
  int counter = 0;
  for(auto elem : countmap_){
    counter+=elem.second;
  }
  return counter;
}
//gets total count of all elements withing a certain range, takes min and max of range
template <class T>
const int Counter<T>::get_total_range(const T &min, const T &max){
  int counter = 0;
  for(auto elem : countmap_){
    if(elem.first >= min && elem.first <= max){
      counter+=elem.second;
    }
  }
  return counter;
}
//removes element from map
template <class T>
void Counter<T>::Remove(const T &key){
  if(countmap_.erase(key)){
    return;
  }
  else{
    //std::cout << "Element does not exist in map" << std::endl;
  }
}
//gets the count for a certain key, takes key
template <class T>
const int Counter<T>::get_count_for_key(const T &key){
  typename std::map<T,int>::iterator it = countmap_.find(key);
  if(it == countmap_.end()){
    return 0;
  }
  else{
    //iterate over map until we reach key
    for(auto elem : countmap_){
      if(elem.first == key){
        return elem.second;
      }
    }
  }
}
#endif
