#ifndef DATA_IO_H
#define DATA_IO_H

#include <vector>
#include "../classes/Airline.h"
#include "../classes/Flight.h"
using namespace std;

Airline* createAirline();
void saveData(vector<Flight> flights);

#endif // DATA_IO_H

