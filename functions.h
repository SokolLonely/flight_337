#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "classes.h"
void cleanStandardInputStream(void);
void clearScreen(void);
void pressEnter();
void displayHeader();
void printChoicePrompt();
int menu();
Airline* createAirline();
int browseFlightList(vector<Flight> flights);
void displaySeatMap(Flight& flight);
void displayPassengerInfo(Flight& flight);
void addNewPassenger(Flight& flight);
void removeExistingPassenger(Flight& flight);
void saveDataToFile(Flight& flight);
#endif