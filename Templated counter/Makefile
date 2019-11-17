CXX = g++  # the compiler
CXXFLAGS = -std=c++11 -Wall  # flags for the compiler (use c++11 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for "make all"
all: test
clean:
	rm Counter.o TestTypes.o test
test: Counter.hpp TestTypes.o test.o
	$(CXX) $(CXXFLAGS) Counter.hpp TestTypes.o test.o -o test
TestTypes.o: TestTypes.cpp
	$(CXX) $(CXXFLAGS) -c TestTypes.cpp TestTypes.hpp
test.o: test.cpp TestTypes.cpp Counter.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp
