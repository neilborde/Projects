#include <string>
#include <iterator>
#include "Counter.hpp"
#include "TestTypes.hpp"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
/*Neil Borde
This is a template Counter class that is basically a map with interactive methods*/

TEST_CASE("Increment"){
  Counter<int> intcounter;
  intcounter.Increment(1,5);
  SECTION("Increment nonexistent"){
    intcounter.Increment(2,5);
    intcounter.Increment(3);
    REQUIRE(intcounter.getValueAt(2)==5);
    REQUIRE(intcounter.getValueAt(3)==1);
  }
  SECTION("Increment existent"){
    intcounter.Increment(1,5);
    intcounter.Increment(1);
    REQUIRE(intcounter.getValueAt(1)==11);
  }
}
TEST_CASE("Decrement"){
  Counter<std::string> stringcounter;
  stringcounter.Increment("dog",5);
  SECTION("Decrement nonexistent"){
    stringcounter.Decrement("cat",5);
    stringcounter.Decrement("cat");
    REQUIRE(stringcounter.getValueAt("cat")==-1);
  }
  SECTION("Decrement existent"){
    stringcounter.Decrement("dog",3);
    stringcounter.Decrement("dog");
    REQUIRE(stringcounter.getValueAt("dog")==1);
  }
  SECTION("Decrement too much"){
    stringcounter.Decrement("dog",6);
    REQUIRE(stringcounter.getValueAt("dog")==5);
  }
}
TEST_CASE("Most common, Least common"){
  Counter<double> doublecounter;
  doublecounter.Increment(1.1,1);
  doublecounter.Increment(2.2,2);
  doublecounter.Increment(3.3,2);
  doublecounter.Increment(4.4,4);
  doublecounter.Increment(5.5,5);
  doublecounter.Increment(6.6,6);
  SECTION("Normal conditions"){
    std::vector<double> keys = doublecounter.NMostCommon(3);
    std::vector<double> keys2 = doublecounter.NLeastCommon(3);
    REQUIRE((keys[0]==6.6 && keys[1]==5.5 && keys[2]==4.4));
    REQUIRE((keys2[0]==1.1 && keys2[1]==2.2 && keys2[2]==3.3));
  }
  SECTION("n too large"){
    //we should see "paramater n larger than map size" printed twice
    //not sure how to test this one correctly, but it prints "N too large" if you use an n greater than map size
    // std::vector<double> keys3 = doublecounter.NMostCommon(7);
    // std::vector<double> keys4 = doublecounter.NLeastCommon(7);
    // REQUIRE(keys3.size()==0);
    // REQUIRE(keys4.size()==0);
  }
}
TEST_CASE("NormalizedWeight"){
  Counter<char> charcounter;
  charcounter.Increment('a',2);
  charcounter.Increment('b',4);
  charcounter.Increment('c',4);
  SECTION("Normal conditions"){
    std::vector<std::tuple<char,double>> weights = charcounter.NormalizedWeight();
    double a = std::get<1>(weights[0]);
    double b = std::get<1>(weights[1]);
    double c = std::get<1>(weights[2]);
    REQUIRE((a==0.2 && b==0.4 && c==0.4));
  }
  SECTION("empty"){
    //we should see "empty map" printed
    //This has the same issue as the NMostcommon where I'm not sure how to unit test it, but it prints empty map;
    // Counter<char> charcounter2;
    // std::vector<std::tuple<char,double>> weights = charcounter2.NormalizedWeight();
  }
}
TEST_CASE("get_key_set, get_value_set"){
  SECTION("Normal conditions"){
    Counter<Book> bookcounter;
    Book a(10);
    Book b(20);
    Book c(30);
    bookcounter.Increment(a,5);
    bookcounter.Increment(b,10);
    bookcounter.Increment(c,15);
    std::vector<Book> keys = bookcounter.get_key_set();
    std::vector<int> values = bookcounter.get_value_set();
    //initialized each book with different number of pages, so this test will check if the correct books are
    //in the keys vector.
    REQUIRE((keys[0].getnumpages()==10 && keys[1].getnumpages()==20 && keys[2].getnumpages()==30));
    //check if correct values are added to values vector.
    REQUIRE((values[0]==5 && values[1]==10 && values[2]==15));
  }
  // SECTION("empty"){
  //   //should print "empty set" twice
  //   Counter<Book> bookcounter2;
  //   std::vector<Book> keys = bookcounter2.get_key_set();
  //   std::vector<int> values = bookcounter2.get_value_set();
  // }
}
TEST_CASE("get_map"){
  Counter<Movie> moviecounter;
  Movie a,b,c;
  a.movielength_ = 5;
  b.movielength_ = 10;
  c.movielength_ = 15;
  moviecounter.Increment(a);
  moviecounter.Increment(b,2);
  moviecounter.Increment(c,3);
  std::map<Movie,int> testmap = moviecounter.get_map();
  REQUIRE((testmap[a]==1 && testmap[b]==2 && testmap[c]==3));
}
TEST_CASE("gettotal"){
  SECTION("normal use"){
    Counter<SquareType> squarecounter;
    squarecounter.Increment(SquareType::Wall,5);
    squarecounter.Increment(SquareType::Human,15);
    int total = squarecounter.get_total();
    REQUIRE(total==20);
  }
  SECTION("empty"){
    Counter<SquareType> squarecounter2;
    int total2 = squarecounter2.get_total();
    REQUIRE(total2==0);
  }
}
TEST_CASE("get_total_range"){
  SECTION("normal use"){
    Counter<Book> bookcounter;
    Book a(10);
    Book b(15);
    Book c(20);
    Book d(25);
    bookcounter.Increment(a,5);
    bookcounter.Increment(b,5);
    bookcounter.Increment(c,5);
    bookcounter.Increment(d,5);
    //should increment for each book with pagelength between 15,20.
    int total = bookcounter.get_total_range(b,c);
    REQUIRE(total==10);
  }
  SECTION("empty"){
    Counter<Book> bookcounter;
    Book b(15);
    Book c(20);
    int total = bookcounter.get_total_range(b,c);
    REQUIRE(total==0);
  }
}
TEST_CASE("remove"){
  SECTION("normal use"){
    Counter<int> intcounter;
    intcounter.Increment(1,5);
    intcounter.Increment(2,5);
    intcounter.Remove(2);
    std::vector<int> keys = intcounter.get_key_set();
    //added two keys, removed 1, so the size of the keyset should be 1.
    REQUIRE(keys.size()==1);
  }
  SECTION("does not exist"){
    //should print element does not exist in map
    Counter<int> intcounter;
    intcounter.Remove(2);
  }
}
TEST_CASE("get_count_for_key"){
  SECTION("normal use"){
    Counter<std::string> stringcounter;
    stringcounter.Increment("dog",5);
    REQUIRE(stringcounter.get_count_for_key("dog")==5);
  }
  SECTION("element doesn't exist"){
    Counter<std::string> stringcounter;
    REQUIRE(stringcounter.get_count_for_key("dog")==0);
  }
}
TEST_CASE("parameterized constructor"){
  //this case tests that items are added to the map, that items that appear more than once are incremented
  //correctly and also that an empty vector yields an empty map
  std::vector<char> chars = {'a','b','c','c','d'};
  std::vector<char> chars2;
  Counter<char> charcounter(chars);
  Counter<char> charcounter2(chars2);
  REQUIRE(charcounter.get_total()==5);
  REQUIRE(charcounter.get_count_for_key('c')==2);
  REQUIRE(charcounter2.get_total()==0);
}
