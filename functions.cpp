//non-class functions for output and other things
#include <iostream>
#include <cstdlib>
#include "classes.h"
#include "functions.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

#define _WIN32
void cleanStandardInputStream (void) {
    int leftover;
    do {
        leftover = cin.get();
    } while (leftover !='\n' && leftover != EOF);
}

void clearScreen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void pressEnter() {
    cout << "\n<<< Press Return to Continue>>>>\n";
    cin.get();
}

void displayHeader() {
    clearScreen();
    clearScreen();
    cout << "FMAS Version 1.0" << endl;
    cout << "Term Project - Flight Management Application System" << endl;
    cout << "Produced by Group#: 139" << endl;
    cout << "Names: Ryabinkin, Simon; ElSayed, Abdelrahman; Boucher, Maxime" << endl;
    pressEnter();
}

void printChoicePrompt() {
    cout<<"Please select one the following options:\n"<<endl;
    cout<<"1. Select a flight"<<endl;
    cout<<"2. Display Flight Seat Map."<<endl;
    cout<<"3. Display Passengers Information."<<endl;
    cout<<"4. Add a New Passenger."<<endl;
    cout<<"5. Remove an Existing Passenger"<<endl;
    cout<<"6. Save data"<<endl;
    cout<<"7. Quit."<<endl;
    cout<<"Enter your choice: (1, 2, 3, 4, 5, 6, or 7)"<<endl;
}

int menu() {
    int choice = -1;
    //clearScreen();
    printChoicePrompt();
    cin >> choice;
    cleanStandardInputStream();
    return choice;
}

Flight browseFlightList()
{
    ifstream flightFile("flights.txt");
    if (!flightFile) {
        cerr << "Error opening flights.txt file." << endl;
        exit(1);
    }
    int n = 0;
    string line;
    while (getline(flightFile, line)) {
        n++;
        cout << n << ". " << line << endl;
    }
    cout <<"successfully read "<< n <<" flights from file."<<endl;

    int selected_n;
    cout <<"select a flight number: ";
    cin >> selected_n;
    cout << selected_n<<endl;
    flightFile.clear(); 
    flightFile.seekg(0, std::ios::beg);
    n = 0;
    while (getline(flightFile, line)) {
        n++;
        if (n == selected_n) {
            break;
        }
    }
    //cout << "selected line:\n"<<line<<endl;
    
    flightFile.close();
    int number_of_rows, number_of_seats_per_row;
    string id, source, dest;
    stringstream iss(line);
    iss >>  id >>source>>dest >>number_of_rows >> number_of_seats_per_row;

    //create a route object
    Route* route = new Route(source, dest); 
    Flight returnFlight(number_of_rows, number_of_seats_per_row, route); 
    cout <<"You have selected "<<id <<" flight from "<< source <<" to "<< dest <<endl;
    return returnFlight;
}
void displaySeatMap(Flight);
void displayPassengerInformation(Flight);
void addNewPassenger(Flight);
void removeExistingPassenger(Flight);
void saveDataToFile(Flight);
