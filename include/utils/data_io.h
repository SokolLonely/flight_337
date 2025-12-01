// include/utils/data_io.h
#ifndef DATA_IO_H
#define DATA_IO_H

#include <vector>
#include "../classes/Airline.h"
#include "../classes/Flight.h"
using std::vector;

Airline* createAirline(const string& airline_name);
// PROMISES:
// Creates a new Airline instance with the provided name
// Populates Airline with Flights, Routes, Passengers and Seats information by reading data files
// Prints error messages if input files can't be opened
// Returns a pointer to the created airline instance 

void saveData(vector<Flight> flights);
// PROMISES:
// Prompts user on if they would like to save the passengers data to a file
// Reprompts on invalid input
// Prints error message if output file can't be opened
// Stores all passengers information in a file "passengers.txt"

#endif // DATA_IO_H

