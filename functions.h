#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "classes.h"
void cleanStandardInputStream(void);
void clearScreen(void);
void pressEnter();
void displayHeader();
void printChoicePrompt();
int menu();
Flight* browseFlightList();
void displaySeatMap(Flight* flight);
void displayPassengerInformation(Flight& flight);
void addNewPassenger(Flight& flight);
void removeExistingPassenger(Flight& flight);
void saveDataToFile(Flight& flight);
#endif