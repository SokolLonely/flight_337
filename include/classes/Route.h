// include/classes/Route.h
#ifndef ROUTE_H
#define ROUTE_H

#include <string>
using std::string;

class Route {
private:
    string source;
    string destination;
public:
    Route(string source, string destination);
    string get_source() const;
    string get_destination() const;
};

#endif // ROUTE_H

