//header file for classes.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Airline{
    private:
        string name;
        //vector<Flight> flights;

    public:
        Airline();
        Airline(string name): name(name){}
        
        //addFlight(Flight& flight);
};

class Route{
    private:
        string source;
        string dest;
    public:
        Route();
        Route(string src, string dest): source(src), dest(dest){}
};