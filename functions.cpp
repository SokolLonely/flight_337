//non-class functions for output and other things
#include <iostream>
using namespace std;
#include <iostream>
#include "classes.h"
void printWelcomeMessage() {
    cout << "FMAS Version 1.0" << endl;
    cout << "Term Project — Flight Management Application System" << endl;
    cout << "Produced by Group# 139" << endl;
    cout << "Members: Ryabinkin, Simon; ElSayed, Abdelrahman; Boucher, Maxime" << endl;
    cout << endl;
    cout << "<<< PRESS RETURN TO CONTINUE >>>" << endl;
}
void printChoicePrompt() {
    cout<<"Please select one the following options:"<<endl;

cout<<"1. Select a flight"<<endl;

cout<<"2. Display Flight Seat Map."<<endl;

cout<<"3. Display Passengers Information."<<endl;

cout<<"4. Add a New Passenger."<<endl;

cout<<"5. Remove an Existing Passenger"<<endl;

cout<<"6. Save data"<<endl;

cout<<"7. Quit."<<endl;

cout<<"Enter your choice: (1, 2, 3, 4, 5, 6, or 7)";
}
Flight browseFlightList();
void displaySeatMap(Flight);
void displayPassengerInformation(Flight);
void addNewPassenger(Flight);
void removeExistingPassenger(Flight);
void saveDataToFile(Flight);
