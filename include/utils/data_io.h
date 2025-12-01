// include/utils/data_io.h
#ifndef DATA_IO_H
#define DATA_IO_H

#include <vector>
#include "../classes/Airline.h"
#include "../classes/Flight.h"
using std::vector;

Airline* createAirline(const string& airline_name);
void saveData(vector<Flight> flights);

#endif // DATA_IO_H

