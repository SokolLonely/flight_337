#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "classes.h"
void cleanStandardInputStream(void);
void clearScreen(void);
void pressEnter();
void displayHeader();
void printChoicePrompt();
int menu();
Flight browseFlightList();
void displaySeatMap(Flight);
void displayPassengerInformation(Flight);
void addNewPassenger(Flight);
void removeExistingPassenger(Flight);
void saveDataToFile(Flight);
#endif